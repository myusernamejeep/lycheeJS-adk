
#include "fs.h"

#include <fstream>
#include <string.h>


namespace lib {

	v8::Handle<v8::ObjectTemplate> FS::generate() {

		v8::Handle<v8::ObjectTemplate> tpl = v8::ObjectTemplate::New();

		tpl->Set(v8::String::NewSymbol("read"),  v8::FunctionTemplate::New(FS::handleRead),  v8::ReadOnly);
		tpl->Set(v8::String::NewSymbol("write"), v8::FunctionTemplate::New(FS::handleWrite), v8::ReadOnly);

		return tpl;

	}

	v8::Handle<v8::Value> FS::handleRead(const v8::Arguments& args) {

		v8::HandleScope scope;
		v8::Handle<v8::Value> result = v8::Null();

		if (args.Length() == 1) {

			v8::String::Utf8Value path(args[0]->ToString());

			char* buffer = FS::readVM(*path);
			if (buffer != NULL) {
				result = v8::String::New(buffer);
			}

			delete buffer;

		}


		return scope.Close(result);

	}

	v8::Handle<v8::Value> FS::handleWrite(const v8::Arguments& args) {

		v8::HandleScope scope;
		v8::Handle<v8::Value> result = v8::False();

		if (args.Length() == 2) {

			v8::String::Utf8Value path(args[0]->ToString());
			v8::String::Utf8Value data(args[1]->ToString());

			bool fsresult = FS::writeVM(*path, *data, data.length());
			if (fsresult == true) {
				result = v8::True();
			}

		}


		return scope.Close(result);

	}


	bool FS::writeVM(char* path, char* data, size_t length) {

		char* realpath = FS::getReal(path);
		bool result = FS::write(realpath, data, length);

		delete realpath;

		return result;

	}

	bool FS::write(char* path, char* data, size_t length) {

		FILE *fp = fopen(path, "wb");
		if (fp != NULL) {

			fwrite(data, 1, length, fp);
			fclose(fp);

			return true;

		}

		return false;

	}

	char* FS::readVM(char* path) {

		char* realpath = FS::getReal(path);
		char* buffer = FS::read(realpath);

		delete realpath;

		return buffer;

	}

	char* FS::read(char* path) {

		FILE* fp = fopen(path, "rb");
		if (fp != NULL) {

			fseek(fp, 0, SEEK_END);
			int size = ftell(fp);
			rewind(fp);

			char* buffer = new char[size + 1];
			buffer[size] = '\0';


			for (int i = 0; i < size; ) {
				int read = static_cast<int>(fread(&buffer[i], 1, size - i, fp));
				i += read;
			}

			fclose(fp);

			return buffer;

		}

		return NULL;

	}



	/*
	 * VM abstraction layer of sandboxed paths
	 */

	char _folder_separator = '/';
	const char* _folder_this = "./";
	char* _root;

	char* FS::getReal(char* path) {

		char* buf = NULL;

		if (path[0] != _folder_separator) {

			buf = new char[strlen(_root) + strlen(path) + 1];
			strcpy(buf, _root);
			strcat(buf, path);

		} else {

			buf = new char[strlen(path) + 1];
			strcpy(buf, path);

		}

		return buf;

	}

	void FS::setVMRoot(char* program_path, char* file_path) {

		// Take the path from the executable
		char* pch = strrchr(program_path, _folder_separator);
		int index = pch ? (pch - program_path + 1) : 2;

		char* buf = new char[index + 1];
		strncpy(buf, pch ? program_path : _folder_this, index);
		buf[index] = '\0';


		// Take the path from the JavaScript file
		char* pch1 = strrchr(file_path, _folder_separator);
		int index1 = pch1 ? (pch1 - file_path + 1) : 2;

		char* buf1 = new char[index1 + 1];
		strncpy(buf1, pch1 ? file_path : _folder_this, index1);
		buf1[index1] = '\0';

		delete[] _root;

		_root = new char[index + index1 + 1];
		strcpy(_root, buf);
		strcpy(_root, buf1);

		delete[] buf;
		delete[] buf1;

	}

	char *FS::pushVMRoot(char *new_path) {

		char *old_path = _root;

		char *pch = strrchr(new_path, _folder_separator);
		int index = pch ? (pch - new_path + 1) : 2;

		delete[] _root;
		_root = new char[index + 1];

		strncpy(_root, pch ? new_path : _folder_this, index);
		_root[index] = '\0';

		return old_path;

	}

	void FS::popVMRoot(char *old_path) {
		delete[] _root;
		_root = old_path;
	}

	char* FS::getVMRoot(void) {
		return _root;
	}

}

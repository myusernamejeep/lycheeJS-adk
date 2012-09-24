
#include "arraybuffer.h"


namespace api {

	v8::Persistent<v8::FunctionTemplate> _arraybuffer_template;

	ArrayBuffer::ArrayBuffer(const ArrayBuffer &cpy) {
	}



	v8::Handle<v8::FunctionTemplate> ArrayBuffer::generate() {

		_arraybuffer_template = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(handleNew));
		_arraybuffer_template->InstanceTemplate()->SetInternalFieldCount(2);
		_arraybuffer_template->SetClassName(v8::String::New("ArrayBuffer"));

		return _arraybuffer_template;

	}

	void ArrayBuffer::makeWeak(v8::Persistent<v8::Value> object, void* data) {

		free(data);
		object.Dispose();

	}

	v8::Handle<v8::Value> ArrayBuffer::handleNew(const v8::Arguments& args) {

		v8::HandleScope scope;

		if (!args.IsConstructCall()) {
			return scope.Close(v8::ThrowException(v8::Exception::TypeError(v8::String::New("V8GL object constructor cannot be called as a function."))));
		}

		if (args.Length() != 1 || !args[0]->IsNumber()) {
			return scope.Close(v8::ThrowException(v8::Exception::SyntaxError(v8::String::New("Usage: new ArrayBuffer(length)"))));
		}


		v8::Local<v8::Object> thisObj = args.This();

		unsigned long length = args[0]->Uint32Value();

		void* data = malloc(length);
		memset(data, 0, length);

		v8::Persistent<v8::Object> handle = v8::Persistent<v8::Object>::New(thisObj);
		handle.makeWeak(data, ArrayBuffer::makeWeak);


		thisObj->SetPointerInInternalField(0, data);
		thisObj->SetPointerInInternalField(1, (void*) length);
		thisObj->Set(v8::String::NewSymbol("byteLength"), v8::Int32::New(length), v8::ReadOnly);


		return scope.Close(thisObj);

	}

	v8::Handle<v8::Value> Text::handleToString(const v8::Arguments& args) {
		return v8::String::New("[object Text]");
	}

	v8::Handle<v8::Value> Text::handleLoad(const v8::Arguments& args) {

		v8::HandleScope scope;
		v8::Local<v8::Object> thisObj = args.This();

		if (thisObj.IsEmpty()) {
			return scope.Close(v8::Null());
		}


		v8::Local<v8::String> property = v8::String::New("data");
		if (thisObj->Has(property)) {

			v8::String::Utf8Value value(thisObj->Get(v8::String::New("url")));
			char* url = v8gl::Path::getReal((char*) *value);

			char* data = api::Text::load(url);
			if (data == NULL) {

				thisObj->Set(property, v8::Null(), v8::ReadOnly);
				v8::ThrowException(v8::Exception::Error(v8::String::New("Could not read file.")));

			} else {

				thisObj->Set(v8::String::New("url"), v8::String::New(url), v8::ReadOnly);
				thisObj->Set(property, v8::String::New(data), v8::ReadOnly);

			}

			v8::Local<v8::Function> callback = v8::Function::Cast(*thisObj->Get(v8::String::New("onload")));
			if (!callback.IsEmpty()) {
				callback->Call(thisObj, 0, NULL);
			}

		}


		return scope.Close(v8::Null());

	}

	char* Text::load(char* filename) {

		FILE* file = fopen(filename, "rb");
		if (file == NULL) {
			return NULL;
		}


		fseek(file, 0, SEEK_END);
		int size = ftell(file);
		rewind(file);


		char* chars = new char[size + 1];
		chars[size] = '\0';

		for (int i = 0; i < size; ) {
			int read = static_cast<int>(fread(&chars[i], 1, size - i, file));
			i += read;
		}

		fclose(file);


		return chars;

	}

}


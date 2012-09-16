
#include "path.h"


namespace v8gl {

	char Path::seperator_ = '/';
	char* Path::root_;

	void Path::setRoot(char* program_path, char* file_path) {

		// Take the path from the executable
		char* pch = strrchr(program_path, seperator_);
		int index = pch ? (pch - program_path + 1) : 2;

		char* buf = new char[index + 1];
		strncpy(buf, pch ? program_path : "./", index);
		buf[index] = '\0';


		// Take the path from the JavaScript file
		char* pch1 = strrchr(file_path, seperator_);
		int index1 = pch1 ? (pch1 - file_path + 1) : 2;

		char* buf1 = new char[index1 + 1];
		strncpy(buf1, pch1 ? file_path : "./", index1);
		buf1[index1] = '\0';

		root_ = new char[index + index1 + 1];
		strcpy(root_, buf);
		strcpy(root_, buf1);

		delete[] buf;
		delete[] buf1;

	}

	char *Path::pushRoot(char *new_path) {

		char *old_path = root_;

		char *pch = strrchr(new_path, seperator_);
		int index = pch ? (pch - new_path + 1) : 2;

		root_ = new char[index + 1];
		strncpy(root_, pch ? new_path : "./", index);
		root_[index] = '\0';

		return old_path;

	}

	void Path::popRoot(char *old_path) {
		delete[] root_;
		root_ = old_path;
	}

	char* Path::getRoot(void) {
		return root_;
	}

	char* Path::getReal(char* filepath) {

		char* buf = NULL;

		if (filepath[0] != seperator_) {

			buf = new char[strlen(root_) + strlen(filepath) + 1];
			strcpy(buf, root_);
			strcat(buf, filepath);

		} else {

			buf = new char[strlen(filepath) + 1];
			strcpy(buf, filepath);

		}

		return buf;

	}

}

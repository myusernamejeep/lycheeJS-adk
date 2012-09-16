
#ifndef V8GL_PATH_H_
#define V8GL_PATH_H_

#include <string.h>

#include <v8.h>


namespace v8gl {

	class Path {

		private:

		public:

			static char seperator_;
			static char* root_;

			static char* getRoot(void);
			static void setRoot(char* program_path, char* file_path);

			static char *pushRoot(char* new_path);
			static void popRoot(char *old_path);

			static char* getReal(char* filepath);

	};

}


#endif
 

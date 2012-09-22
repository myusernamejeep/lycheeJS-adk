
#ifndef V8GL_H_
#define V8GL_H_

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


	class V8GL {

		private:

		public:

			static bool _v8gl_targeted;

			static v8::Persistent<v8::Context> initialize(int* pargc, char** argv);
			static bool dispatch(v8::Handle<v8::Context>, char* what);

			static v8::Handle<v8::Value> execute(v8::Handle<v8::Context> context, v8::Handle<v8::String> source, v8::Handle<v8::String> filename);

			static char* read(char* filename);
			static void logException(v8::TryCatch* try_catch);

	};

}


#endif


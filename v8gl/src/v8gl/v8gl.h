
#ifndef V8GL_V8GL_H_
#define V8GL_V8GL_H_

#include <v8.h>


namespace v8gl {

	class V8GL {

		private:

		public:

			static bool _v8gl_targeted;

			static v8::Persistent<v8::Context> initialize(int* pargc, char** argv);
			static bool dispatch(v8::Handle<v8::Context>, char* what);

			static v8::Handle<v8::Value> execute(v8::Handle<v8::Context> context, v8::Handle<v8::String> source, v8::Handle<v8::String> filename);
			static v8::Handle<v8::Value> executeVM(v8::Handle<v8::Context> context, v8::Handle<v8::String> source, v8::Handle<v8::String> filename);

			static void logException(v8::TryCatch* try_catch);

	};

}


#endif


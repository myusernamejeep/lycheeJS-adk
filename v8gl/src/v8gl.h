
#ifndef V8GL_V8GL_H_
#define V8GL_V8GL_H_

#include <v8.h>


namespace v8gl {

	class V8GL {

		private:

		public:

			static v8::Persistent<v8::Context> initialize(int argc, char* argv[]);
			static bool dispatch(v8::Handle<v8::Context>);

			static v8::Handle<v8::Value> execute(v8::Handle<v8::Context> context, v8::Handle<v8::String> source, v8::Handle<v8::String> filename);
			static v8::Handle<v8::Value> executeVM(v8::Handle<v8::Context> context, v8::Handle<v8::String> source, v8::Handle<v8::String> filename);

			static void logException(v8::TryCatch* try_catch);

	};

}


#endif


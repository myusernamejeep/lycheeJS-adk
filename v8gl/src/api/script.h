
#ifndef API_SCRIPT_H_
#define API_SCRIPT_H_

#include <v8.h>


namespace api {

	class Script {

		private:

		public:

			// Disallowing copy constructor
			Script(const api::Script &cpy);

			static v8::Handle<v8::Value> handleNew(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleLoad(const v8::Arguments& args);
			static char* load(char* filename);
			static v8::Handle<v8::Value> handleExecute(const v8::Arguments& args);

			static v8::Handle<v8::Value> handleToString(const v8::Arguments& args);

			static v8::Handle<v8::FunctionTemplate> generate(void);

	};

};

#endif


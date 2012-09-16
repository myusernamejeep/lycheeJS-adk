
#ifndef API_TEXT_H_
#define API_TEXT_H_

#include <v8.h>


namespace api {

	class Text {

		private:

		public:

			// Disallowing copy constructor
			Text(const api::Text &cpy);

			static v8::Handle<v8::Value> handleNew(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleLoad(const v8::Arguments& args);
			static char* load(char* filename);

			static v8::Handle<v8::Value> handleToString(const v8::Arguments& args);

			static v8::Handle<v8::FunctionTemplate> generate(void);

	};

};

#endif


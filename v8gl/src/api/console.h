
#ifndef API_CONSOLE_H_
#define API_CONSOLE_H_

#include <v8.h>

namespace api {

	class Console {

		public:
			static v8::Handle<v8::Value> debug(v8::Handle<v8::Context> context, v8::Handle<v8::Value> data);

			static v8::Handle<v8::Value> handleDebug(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleLog(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleWarn(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleError(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleGroup(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleGroupEnd(const v8::Arguments& args);

			static v8::Handle<v8::ObjectTemplate> generate(void);

	};

};

#endif


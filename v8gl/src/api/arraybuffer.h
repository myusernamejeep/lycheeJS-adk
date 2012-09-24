
#ifndef API_ARRAYBUFFER_H_
#define API_ARRAYBUFFER_H_

#include <v8.h>


namespace api {

	class ArrayBuffer {

		private:

		public:

			// Disallowing copy constructor
			ArrayBuffer(const api::ArrayBuffer &cpy);

			static void makeWeak(v8::Persistent<v8::Value> object, void* data);
			static v8::Handle<v8::Value> handleNew(const v8::Arguments& args);

			static v8::Handle<v8::FunctionTemplate> generate(void);

	};

};

#endif


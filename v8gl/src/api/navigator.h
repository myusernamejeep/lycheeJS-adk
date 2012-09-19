
#ifndef API_NAVIGATOR_H_
#define API_NAVIGATOR_H_

#include <v8.h>

namespace api {

	class Navigator {

		public:

			static v8::Handle<v8::ObjectTemplate> generate(void);

	};

};

#endif


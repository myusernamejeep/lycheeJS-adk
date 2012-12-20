
#ifndef BINDING_GLES_H
#define BINDING_GLES_H

#include <v8.h>


namespace binding {

	class GLES {

		private:

			static v8::Handle<v8::Value> handleEnable(const v8::Arguments& args);

		public:

			static v8::Handle<v8::ObjectTemplate> generate(void);

	};

}

#endif
 

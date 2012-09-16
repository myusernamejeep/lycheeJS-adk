
#ifndef BINDING_GLU_H
#define BINDING_GLU_H

#include <v8.h>


namespace binding {

	class GLU {

		private:

			static v8::Handle<v8::Value> handleCheckExtension(const v8::Arguments& args);

			static v8::Handle<v8::Value> handleOrtho2D(const v8::Arguments& args);
			static v8::Handle<v8::Value> handlePerspective(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleLookAt(const v8::Arguments& args);
			static v8::Handle<v8::Value> handlePickMatrix(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleProject(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleUnProject(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleUnProject4(const v8::Arguments& args);

		public:

			static v8::Handle<v8::ObjectTemplate> generate(void);

	};

}

#endif
 

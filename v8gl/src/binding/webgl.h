
#ifndef BINDING_WEBGL_H
#define BINDING_WEBGL_H

#include <v8.h>


namespace binding {

	class WEBGL {

		private:
		public:

			static v8::Handle<v8::Value> handleCreateBuffer(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleCreateFramebuffer(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleCreateRenderbuffer(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleCreateTexture(const v8::Arguments& args);

			static v8::Handle<v8::Value> handleDeleteBuffer(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleDeleteFramebuffer(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleDeleteRenderbuffer(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleDeleteTexture(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleDrawElements(const v8::Arguments& args);

			static v8::Handle<v8::Value> handleFramebufferRenderbuffer(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleFramebufferTexture2D(const v8::Arguments& args);

			static v8::Handle<v8::Value> handleGenerateMipmap(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleGetActiveAttrib(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleGetActiveUniform(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleGetAttachedShaders(const v8::Arguments& args);

			static v8::Handle<v8::Value> handleShaderSource(const v8::Arguments& args);

	};

}

#endif
 

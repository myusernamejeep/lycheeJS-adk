
#ifndef BINDING_GL_H
#define BINDING_GL_H

#include <v8.h>


namespace binding {

	class GL {

		private:

			static v8::Handle<v8::Value> handleAccum(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleActiveTexture(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleAlphaFunc(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleAreTexturesResident(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleArrayElement(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleAttachShader(const v8::Arguments& args);

			static v8::Handle<v8::Value> handleBegin(const v8::Arguments& args);


			static v8::Handle<v8::Value> handleBeginQuery(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleBindBuffer(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleBindTexture(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleBitmap(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleBlendColor(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleBlendEquation(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleBlendEquationSeparate(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleBlendFunc(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleBlendFuncSeparate(const v8::Arguments& args);

			static v8::Handle<v8::Value> handleCallList(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleClear(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleClearAccum(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleClearColor(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleClearDepth(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleClearIndex(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleClearStencil(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleClientActiveTexture(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleClipPlane(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleColor3i(const v8::Arguments& args);

			static v8::Handle<v8::Value> handleMatrixMode(const v8::Arguments& args);

		public:

			static v8::Handle<v8::ObjectTemplate> generate();

	};

}

#endif
 

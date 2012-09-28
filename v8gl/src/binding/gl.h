
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
			static v8::Handle<v8::Value> handleColor3f(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleColor3fv(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleColor3i(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleColor3iv(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleColor4f(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleColor4fv(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleColor4i(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleColor4iv(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleColorMask(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleColorMaterial(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleCompileShader(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleCopyPixels(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleCreateBuffer(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleCreateProgram(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleCreateShader(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleCullFace(const v8::Arguments& args);

			static v8::Handle<v8::Value> handleDeleteBuffers(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleDeleteLists(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleDeleteProgram(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleDeleteQueries(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleDeleteShader(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleDisable(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleDisableClientState(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleDisableVertexAttribArray(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleDepthFunc(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleDepthMask(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleDepthRange(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleDetachShader(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleDrawArrays(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleDrawBuffer(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleDrawBuffers(const v8::Arguments& args);

			static v8::Handle<v8::Value> handleEdgeFlag(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleEnable(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleEnableClientState(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleEnableVertexAttribArray(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleEnd(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleEndList(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleEndQuery(const v8::Arguments& args);

			static v8::Handle<v8::Value> handleFlush(const v8::Arguments& args);

			static v8::Handle<v8::Value> handleLinkProgram(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleLoadIdentity(const v8::Arguments& args);

			static v8::Handle<v8::Value> handleMatrixMode(const v8::Arguments& args);

			static v8::Handle<v8::Value> handleOrtho(const v8::Arguments& args);

			static v8::Handle<v8::Value> handleTexCoord2f(const v8::Arguments& args);

			static v8::Handle<v8::Value> handleUseProgram(const v8::Arguments& args);

			static v8::Handle<v8::Value> handleVertex2f(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleVertex2i(const v8::Arguments& args);

		public:

			static v8::Handle<v8::ObjectTemplate> generate();

	};

}

#endif
 

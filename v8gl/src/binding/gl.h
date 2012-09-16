
#ifndef BINDING_GL_H
#define BINDING_GL_H

#include <v8.h>


namespace binding {

	class GL {

		private:

			static v8::Handle<v8::Value> handleAccum(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleActiveTexture(const v8::Arguments& args);
			static v8::Handle<v8::Value> getNEVER(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getLESS(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getEQUAL(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getLEQUAL(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getGREATER(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getNOTEQUAL(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getGEQUAL(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getALWAYS(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> handleAlphaFunc(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleAreTexturesResident(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleArrayElement(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleAttachShader(const v8::Arguments& args);

			static v8::Handle<v8::Value> getPOINTS(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getLINES(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getLINE_STRIP(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getLINE_LOOP(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getTRIANGLES(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getTRIANGLE_STRIP(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getTRIANGLE_FAN(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getQUADS(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getQUAD_STRIP(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getPOLYGON(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> handleBegin(const v8::Arguments& args);


			static v8::Handle<v8::Value> handleBeginQuery(const v8::Arguments& args);
			static v8::Handle<v8::Value> getARRAY_BUFFER(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getELEMENT_ARRAY_BUFFER(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getPIXEL_PACK_BUFFER(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getPIXEL_UNPACK_BUFFER(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> handleBindBuffer(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleBindTexture(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleBitmap(const v8::Arguments& args);
			static v8::Handle<v8::Value> getBLEND_COLOR(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> handleBlendColor(const v8::Arguments& args);
			static v8::Handle<v8::Value> getFUNC_ADD(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getFUNC_SUBTRACT(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getFUNC_REVERSE_SUBTRACT(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getMIN(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getMAX(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> handleBlendEquation(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleBlendEquationSeparate(const v8::Arguments& args);
			static v8::Handle<v8::Value> getZERO(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getONE(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getSRC_COLOR(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getONE_MINUS_SRC_COLOR(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getDST_COLOR(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getONE_MINUS_DST_COLOR(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getSRC_ALPHA(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getONE_MINUS_SRC_ALPHA(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getDST_ALPHA(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getONE_MINUS_DST_ALPHA(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getCONSTANT_COLOR(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getONE_MINUS_CONSTANT_COLOR(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getCONSTANT_ALPHA(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getONE_MINUS_CONSTANT_ALPHA(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getSRC_ALPHA_SATURATE(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> handleBlendFunc(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleBlendFuncSeparate(const v8::Arguments& args);

			static v8::Handle<v8::Value> handleCallList(const v8::Arguments& args);
			static v8::Handle<v8::Value> getCOLOR_BUFFER_BIT(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getDEPTH_BUFFER_BIT(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getACCUM_BUFFER_BIT(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getSTENCIL_BUFFER_BIT(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> handleClear(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleClearAccum(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleClearColor(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleClearDepth(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleClearIndex(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleClearStencil(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleClientActiveTexture(const v8::Arguments& args);


			static v8::Handle<v8::Value> getMATRIX_MODE(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> handleMatrixMode(const v8::Arguments& args);

		public:

			static v8::Handle<v8::ObjectTemplate> generate();

	};

}

#endif
 

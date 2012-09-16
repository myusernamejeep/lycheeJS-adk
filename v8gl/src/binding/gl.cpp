
#include "gl.h"

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
#else
	#define GL_GLEXT_PROTOTYPES
	#include <GL/gl.h>
#endif


/*
 * OpenGL Software Development Kit 2.1
 *
 * The GL bindings were implemented following the spec document available here:
 * http://www.opengl.org/sdk/docs/man/
 *
 *
 * Missing Bindings:
 *
 * - gl.bindBuffer() needs evaluation if it is usable on Android.
 * - gl.bufferData()
 * - gl.bufferSubData()
 *
 * - gl.callLists()
 *
 *
 * Incomplete Bindings (TODO)
 *
 * - gl.bindAttribLocation()
 *
 */



namespace binding {

	/*
	 * Section A
	 */
	v8::Handle<v8::Value> GL::handleAccum(const v8::Arguments& args) {

		if (args.Length() == 2) {

			int op = args[0]->IntegerValue();
			double value = args[1]->NumberValue();

			glAccum((GLenum) op, (GLfloat) value);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::handleActiveTexture(const v8::Arguments& args) {

		if (args.Length() == 1) {

			int texture = args[0]->IntegerValue();

			glActiveTexture((GLenum) texture);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::getNEVER(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_NEVER);
	}

	v8::Handle<v8::Value> GL::getLESS(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_LESS);
	}

	v8::Handle<v8::Value> GL::getEQUAL(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_EQUAL);
	}

	v8::Handle<v8::Value> GL::getLEQUAL(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_LEQUAL);
	}

	v8::Handle<v8::Value> GL::getGREATER(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_GREATER);
	}

	v8::Handle<v8::Value> GL::getNOTEQUAL(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_NOTEQUAL);
	}

	v8::Handle<v8::Value> GL::getGEQUAL(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_GEQUAL);
	}

	v8::Handle<v8::Value> GL::getALWAYS(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_ALWAYS);
	}

	v8::Handle<v8::Value> GL::handleAlphaFunc(const v8::Arguments& args) {

		if (args.Length() == 2) {

			int func = args[0]->IntegerValue();
			double ref = args[1]->NumberValue();

			glAlphaFunc((GLenum) func, (GLclampf) ref);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::handleAreTexturesResident(const v8::Arguments& args) {

		v8::Handle<v8::Value> result = v8::False();

		if (args.Length() == 3) {

			int n = args[0]->IntegerValue();

			v8::Handle<v8::Array> textures_arr = v8::Handle<v8::Array>::Cast(args[1]);
			GLuint* textures = new GLuint[textures_arr->Length()];

			v8::Handle<v8::Array> residences_arr = v8::Handle<v8::Array>::Cast(args[2]);
			GLboolean* residences = new GLboolean[residences_arr->Length()];


			for (unsigned i = 0; i < textures_arr->Length(); i++) {
				v8::Handle<v8::Value> value(textures_arr->Get(v8::Integer::New(i)));
				textures[i] = (GLuint) value->Uint32Value();
			}

			for (unsigned j = 0; j < residences_arr->Length(); j++) {
				v8::Handle<v8::Value> value(residences_arr->Get(v8::Integer::New(j)));
				textures[j] = (GLboolean) value->BooleanValue();
			}


			bool _result = glAreTexturesResident((GLsizei) n, (GLuint*) textures, (GLboolean*) residences);

			if (_result == true) {
				result = v8::True();
			}

		}

		return result;

	}

	v8::Handle<v8::Value> GL::handleArrayElement(const v8::Arguments& args) {

		if (args.Length() == 1) {

			int i = args[0]->IntegerValue();

			glArrayElement((GLint) i);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::handleAttachShader(const v8::Arguments& args) {

		if (args.Length() == 2) {

			unsigned int program = args[0]->Uint32Value();
			unsigned int shader = args[1]->Uint32Value();

			glAttachShader((GLuint) program, (GLuint) shader);

		}

		return v8::Undefined();

	}



	/*
	 * Section B
	 */

	v8::Handle<v8::Value> GL::getPOINTS(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_POINTS);
	}

	v8::Handle<v8::Value> GL::getLINES(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_LINES);
	}

	v8::Handle<v8::Value> GL::getLINE_STRIP(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_LINE_STRIP);
	}

	v8::Handle<v8::Value> GL::getLINE_LOOP(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_LINE_LOOP);
	}

	v8::Handle<v8::Value> GL::getTRIANGLES(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_TRIANGLES);
	}

	v8::Handle<v8::Value> GL::getTRIANGLE_STRIP(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_TRIANGLE_STRIP);
	}

	v8::Handle<v8::Value> GL::getTRIANGLE_FAN(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_TRIANGLE_FAN);
	}

	v8::Handle<v8::Value> GL::getQUADS(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_QUADS);
	}

	v8::Handle<v8::Value> GL::getQUAD_STRIP(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_QUAD_STRIP);
	}

	v8::Handle<v8::Value> GL::getPOLYGON(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_POLYGON);
	}

	v8::Handle<v8::Value> GL::handleBegin(const v8::Arguments& args) {

		if (args.Length() == 1) {

			int mode = args[0]->IntegerValue();

			glBegin((GLenum) mode);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::handleBeginQuery(const v8::Arguments& args) {

		if (args.Length() == 2) {

			int target = args[0]->IntegerValue();
			unsigned int id = args[1]->Uint32Value();

			glBeginQuery((GLenum) target, (GLuint) id);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::getARRAY_BUFFER(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_ARRAY_BUFFER);
	}

	v8::Handle<v8::Value> GL::getELEMENT_ARRAY_BUFFER(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_ELEMENT_ARRAY_BUFFER);
	}

	v8::Handle<v8::Value> GL::getPIXEL_PACK_BUFFER(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_PIXEL_PACK_BUFFER);
	}

	v8::Handle<v8::Value> GL::getPIXEL_UNPACK_BUFFER(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_PIXEL_UNPACK_BUFFER);
	}

	v8::Handle<v8::Value> GL::handleBindBuffer(const v8::Arguments& args) {

		if (args.Length() == 2) {

			int target = args[0]->IntegerValue();
			unsigned int buffer = args[1]->Uint32Value();

			glBindBuffer((GLenum) target, (GLuint) buffer);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::handleBindTexture(const v8::Arguments& args) {

		if (args.Length() == 2) {

			int target = args[0]->IntegerValue();
			unsigned int texture = args[1]->Uint32Value();

			glBindTexture((GLenum) target, (GLuint) texture);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::handleBitmap(const v8::Arguments& args) {

		if (args.Length() == 7) {

			int width    = args[0]->IntegerValue();
			int height   = args[1]->IntegerValue();
			double xorig = args[2]->NumberValue();
			double yorig = args[3]->NumberValue();
			double xmove = args[4]->NumberValue();
			double ymove = args[5]->NumberValue();


			v8::Handle<v8::Array> bitmap_arr = v8::Handle<v8::Array>::Cast(args[6]);
			GLubyte* bitmap = new GLubyte(bitmap_arr->Length());


			for (unsigned i = 0; i < bitmap_arr->Length(); i++) {
				v8::Handle<v8::Value> value(bitmap_arr->Get(v8::Integer::New(i)));
				bitmap[i] = (GLubyte) value->Uint32Value();
			}


			glBitmap(
				(GLsizei) width, (GLsizei) height,
				(GLfloat) xorig, (GLfloat) yorig,
				(GLfloat) xmove, (GLfloat) ymove,
				(GLubyte*) bitmap
			);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::getBLEND_COLOR(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_BLEND_COLOR);
	}

	v8::Handle<v8::Value> GL::handleBlendColor(const v8::Arguments& args) {

		if (args.Length() == 4) {

			double red   = args[0]->NumberValue();
			double green = args[1]->NumberValue();
			double blue  = args[2]->NumberValue();
			double alpha = args[3]->NumberValue();

			glBlendColor((GLclampf) red, (GLclampf) green, (GLclampf) blue, (GLclampf) alpha);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::getFUNC_ADD(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_FUNC_ADD);
	}

	v8::Handle<v8::Value> GL::getFUNC_SUBTRACT(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_FUNC_SUBTRACT);
	}

	v8::Handle<v8::Value> GL::getFUNC_REVERSE_SUBTRACT(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_FUNC_REVERSE_SUBTRACT);
	}

	v8::Handle<v8::Value> GL::getMIN(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_MIN);
	}

	v8::Handle<v8::Value> GL::getMAX(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_MAX);
	}

	v8::Handle<v8::Value> GL::handleBlendEquation(const v8::Arguments& args) {

		if (args.Length() == 1) {

			int mode = args[0]->IntegerValue();

			glBlendEquation((GLenum) mode);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::handleBlendEquationSeparate(const v8::Arguments& args) {

		if (args.Length() == 2) {

			int modeRGB   = args[0]->IntegerValue();
			int modeAlpha = args[1]->IntegerValue();

			glBlendEquationSeparate((GLenum) modeRGB, (GLenum) modeAlpha);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::getZERO(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_ZERO);
	}

	v8::Handle<v8::Value> GL::getONE(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_ONE);
	}

	v8::Handle<v8::Value> GL::getSRC_COLOR(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_SRC_COLOR);
	}

	v8::Handle<v8::Value> GL::getONE_MINUS_SRC_COLOR(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_ONE_MINUS_SRC_COLOR);
	}

	v8::Handle<v8::Value> GL::getDST_COLOR(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_DST_COLOR);
	}

	v8::Handle<v8::Value> GL::getONE_MINUS_DST_COLOR(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_ONE_MINUS_DST_COLOR);
	}

	v8::Handle<v8::Value> GL::getSRC_ALPHA(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_SRC_ALPHA);
	}

	v8::Handle<v8::Value> GL::getONE_MINUS_SRC_ALPHA(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_ONE_MINUS_SRC_ALPHA);
	}

	v8::Handle<v8::Value> GL::getDST_ALPHA(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_DST_ALPHA);
	}

	v8::Handle<v8::Value> GL::getONE_MINUS_DST_ALPHA(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_ONE_MINUS_DST_ALPHA);
	}

	v8::Handle<v8::Value> GL::getCONSTANT_COLOR(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_CONSTANT_COLOR);
	}

	v8::Handle<v8::Value> GL::getONE_MINUS_CONSTANT_COLOR(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_ONE_MINUS_CONSTANT_COLOR);
	}

	v8::Handle<v8::Value> GL::getCONSTANT_ALPHA(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_CONSTANT_ALPHA);
	}

	v8::Handle<v8::Value> GL::getONE_MINUS_CONSTANT_ALPHA(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_ONE_MINUS_CONSTANT_ALPHA);
	}

	v8::Handle<v8::Value> GL::getSRC_ALPHA_SATURATE(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_SRC_ALPHA_SATURATE);
	}

	v8::Handle<v8::Value> GL::handleBlendFunc(const v8::Arguments& args) {

		if (args.Length() == 2) {

			int srcFactor = args[0]->IntegerValue();
			int dstFactor = args[1]->IntegerValue();

			glBlendFunc((GLenum) srcFactor, (GLenum) dstFactor);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::handleBlendFuncSeparate(const v8::Arguments& args) {

		if (args.Length() == 4) {

			int srcRGB = args[0]->IntegerValue();
			int dstRGB = args[1]->IntegerValue();
			int srcAlpha = args[3]->IntegerValue();
			int dstAlpha = args[4]->IntegerValue();

			glBlendFuncSeparate(
				(GLenum) srcRGB, (GLenum) dstRGB,
				(GLenum) srcAlpha, (GLenum) dstAlpha
			);

		}

		return v8::Undefined();

	}



	/*
	 * Section C
	 */

	v8::Handle<v8::Value> GL::handleCallList(const v8::Arguments& args) {

		if (args.Length() == 1) {

			unsigned int list = args[0]->Uint32Value();

			glCallList((GLuint) list);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::getCOLOR_BUFFER_BIT(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_COLOR_BUFFER_BIT);
	}

	v8::Handle<v8::Value> GL::getDEPTH_BUFFER_BIT(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_DEPTH_BUFFER_BIT);
	}

	v8::Handle<v8::Value> GL::getACCUM_BUFFER_BIT(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_ACCUM_BUFFER_BIT);
	}

	v8::Handle<v8::Value> GL::getSTENCIL_BUFFER_BIT(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_STENCIL_BUFFER_BIT);
	}

	v8::Handle<v8::Value> GL::handleClear(const v8::Arguments& args) {

		if (args.Length() == 1) {

			unsigned int mask = args[0]->Uint32Value();

			glClear((GLbitfield) mask);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::handleClearAccum(const v8::Arguments& args) {

		if (args.Length() == 4) {

			double red   = args[0]->NumberValue();
			double green = args[1]->NumberValue();
			double blue  = args[2]->NumberValue();
			double alpha = args[3]->NumberValue();

			glClearAccum((GLfloat) red, (GLfloat) green, (GLfloat) blue, (GLfloat) alpha);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::handleClearColor(const v8::Arguments& args) {

		if (args.Length() == 4) {

			double red   = args[0]->NumberValue();
			double green = args[1]->NumberValue();
			double blue  = args[2]->NumberValue();
			double alpha = args[3]->NumberValue();

			glClearColor((GLclampf) red, (GLclampf) green, (GLclampf) blue, (GLclampf) alpha);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::handleClearDepth(const v8::Arguments& args) {

		if (args.Length() == 1) {

			double depth = args[0]->NumberValue();

			glClearDepth((GLclampd) depth);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::handleClearIndex(const v8::Arguments& args) {

		if (args.Length() == 1) {

			double index = args[0]->NumberValue();

			glClearIndex((GLfloat) index);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::handleClearStencil(const v8::Arguments& args) {

		if (args.Length() == 1) {

			int index = args[0]->IntegerValue();

			glClearStencil((GLint) index);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::handleClientActiveTexture(const v8::Arguments& args) {

		if (args.Length() == 1) {

			int texture = args[0]->IntegerValue();

			glClientActiveTexture((GLenum) texture);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::handleClipPlane(const v8::Arguments& args) {

		if (args.Length() == 2) {

			int plane = args[0]->IntegerValue();


			v8::Handle<v8::Array> equation_arr = v8::Handle<v8::Array>::Cast(args[1]);
			GLdouble* equation = new GLdouble[equation_arr->Length()];

			for (unsigned i = 0; i < equation_arr->Length(); i++) {
				v8::Handle<v8::Value> value(equation_arr->Get(v8::Integer::New(i)));
				equation[i] = (GLdouble) value->NumberValue();
			}


			glClipPlane((GLenum) plane, (GLdouble*) equation);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::handleColor3i(const v8::Arguments& args) {

		if (args.Length() == 3) {

			int red = args[0]->IntegerValue();
			int green = args[1]->IntegerValue();
			int blue = args[2]->IntegerValue();

			glColor3i((GLint) red, (GLint) green, (GLint) blue);

		}

	}





	/*
	 * Section M
	 */
	v8::Handle<v8::Value> GL::getMATRIX_MODE(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GL_MATRIX_MODE);
	}

	v8::Handle<v8::Value> GL::handleMatrixMode(const v8::Arguments& args) {

		if (args.Length() == 1) {

			int mode = args[0]->IntegerValue();

			glMatrixMode((GLenum) mode);

		}

		return v8::Undefined();

	}





	v8::Handle<v8::ObjectTemplate> GL::generate() {

		v8::HandleScope scope;

		v8::Handle<v8::ObjectTemplate> gltpl = v8::ObjectTemplate::New();


		/*
		 * Section A
		 */
		gltpl->Set(v8::String::NewSymbol("accum"),               v8::FunctionTemplate::New(GL::handleAccum));
		gltpl->Set(v8::String::NewSymbol("activeTexture"),       v8::FunctionTemplate::New(GL::handleActiveTexture));
		gltpl->SetAccessor(v8::String::NewSymbol("NEVER"),       GL::getNEVER);
		gltpl->SetAccessor(v8::String::NewSymbol("LESS"),        GL::getLESS);
		gltpl->SetAccessor(v8::String::NewSymbol("EQUAL"),       GL::getEQUAL);
		gltpl->SetAccessor(v8::String::NewSymbol("LEQUAL"),      GL::getLEQUAL);
		gltpl->SetAccessor(v8::String::NewSymbol("GREATER"),     GL::getGREATER);
		gltpl->SetAccessor(v8::String::NewSymbol("NOTEQUAL"),    GL::getNOTEQUAL);
		gltpl->SetAccessor(v8::String::NewSymbol("GEQUAL"),      GL::getGEQUAL);
		gltpl->SetAccessor(v8::String::NewSymbol("ALWAYS"),      GL::getALWAYS);
		gltpl->Set(v8::String::NewSymbol("alphaFunc"),           v8::FunctionTemplate::New(GL::handleAlphaFunc));
		gltpl->Set(v8::String::NewSymbol("areTexturesResident"), v8::FunctionTemplate::New(GL::handleAreTexturesResident));
		gltpl->Set(v8::String::NewSymbol("arrayElement"),        v8::FunctionTemplate::New(GL::handleArrayElement));

		/*
		 * Section B
		 */
		gltpl->Set(v8::String::NewSymbol("beginQuery"),					      v8::FunctionTemplate::New(GL::handleBeginQuery));
		gltpl->SetAccessor(v8::String::NewSymbol("ARRAY_BUFFER"),             GL::getARRAY_BUFFER);
		gltpl->SetAccessor(v8::String::NewSymbol("ELEMENT_ARRAY_BUFFER"),     GL::getELEMENT_ARRAY_BUFFER);
		gltpl->SetAccessor(v8::String::NewSymbol("PIXEL_PACK_BUFFER"),        GL::getPIXEL_PACK_BUFFER);
		gltpl->SetAccessor(v8::String::NewSymbol("PIXEL_UNPACK_BUFFER"),      GL::getPIXEL_UNPACK_BUFFER);
		gltpl->Set(v8::String::NewSymbol("bindBuffer"),                       v8::FunctionTemplate::New(GL::handleBindBuffer));
		gltpl->Set(v8::String::NewSymbol("bindTexture"),                      v8::FunctionTemplate::New(GL::handleBindTexture));
		gltpl->Set(v8::String::NewSymbol("bitmap"),                           v8::FunctionTemplate::New(GL::handleBitmap));
		gltpl->SetAccessor(v8::String::NewSymbol("BLEND_COLOR"),              GL::getBLEND_COLOR);
		gltpl->Set(v8::String::NewSymbol("blendColor"),                       v8::FunctionTemplate::New(GL::handleBlendColor));
		gltpl->SetAccessor(v8::String::NewSymbol("FUNC_ADD"),                 GL::getFUNC_ADD);
		gltpl->SetAccessor(v8::String::NewSymbol("FUNC_SUBTRACT"),            GL::getFUNC_SUBTRACT);
		gltpl->SetAccessor(v8::String::NewSymbol("FUNC_REVERSE_SUBTRACT"),    GL::getFUNC_REVERSE_SUBTRACT);
		gltpl->SetAccessor(v8::String::NewSymbol("MIN"),                      GL::getMIN);
		gltpl->SetAccessor(v8::String::NewSymbol("MAX"),                      GL::getMAX);
		gltpl->Set(v8::String::NewSymbol("blendEquation"),                    v8::FunctionTemplate::New(GL::handleBlendEquation));
		gltpl->Set(v8::String::NewSymbol("blendEquationSeparate"),            v8::FunctionTemplate::New(GL::handleBlendEquationSeparate));
		gltpl->SetAccessor(v8::String::NewSymbol("ZERO"),                     GL::getZERO);
		gltpl->SetAccessor(v8::String::NewSymbol("ONE"),                      GL::getONE);
		gltpl->SetAccessor(v8::String::NewSymbol("SRC_COLOR"),                GL::getSRC_COLOR);
		gltpl->SetAccessor(v8::String::NewSymbol("ONE_MINUS_SRC_COLOR"),      GL::getONE_MINUS_SRC_COLOR);
		gltpl->SetAccessor(v8::String::NewSymbol("DST_COLOR"),                GL::getDST_COLOR);
		gltpl->SetAccessor(v8::String::NewSymbol("ONE_MINUS_DST_COLOR"),      GL::getONE_MINUS_DST_COLOR);
		gltpl->SetAccessor(v8::String::NewSymbol("SRC_ALPHA"),                GL::getSRC_ALPHA);
		gltpl->SetAccessor(v8::String::NewSymbol("ONE_MINUS_SRC_ALPHA"),      GL::getONE_MINUS_SRC_ALPHA);
		gltpl->SetAccessor(v8::String::NewSymbol("DST_ALPHA"),                GL::getDST_ALPHA);
		gltpl->SetAccessor(v8::String::NewSymbol("ONE_MINUS_DST_ALPHA"),      GL::getONE_MINUS_DST_ALPHA);
		gltpl->SetAccessor(v8::String::NewSymbol("CONSTANT_COLOR"),           GL::getCONSTANT_COLOR);
		gltpl->SetAccessor(v8::String::NewSymbol("ONE_MINUS_CONSTANT_COLOR"), GL::getONE_MINUS_CONSTANT_COLOR);
		gltpl->SetAccessor(v8::String::NewSymbol("CONSTANT_ALPHA"),           GL::getCONSTANT_ALPHA);
		gltpl->SetAccessor(v8::String::NewSymbol("ONE_MINUS_CONSTANT_ALPHA"), GL::getONE_MINUS_CONSTANT_ALPHA);
		gltpl->SetAccessor(v8::String::NewSymbol("SRC_ALPHA_SATURATE"),       GL::getSRC_ALPHA_SATURATE);
		gltpl->Set(v8::String::NewSymbol("blendFunc"),                        v8::FunctionTemplate::New(GL::handleBlendFunc));

		/*
		 * Section C
		 */
		gltpl->Set(v8::String::NewSymbol("callList"),     v8::FunctionTemplate::New(GL::handleCallList));
		gltpl->Set(v8::String::NewSymbol("clear"),        v8::FunctionTemplate::New(GL::handleClear));
		gltpl->Set(v8::String::NewSymbol("clearAccum"),   v8::FunctionTemplate::New(GL::handleClearAccum));
		gltpl->Set(v8::String::NewSymbol("clearColor"),   v8::FunctionTemplate::New(GL::handleClearColor));
		gltpl->Set(v8::String::NewSymbol("clearDepth"),   v8::FunctionTemplate::New(GL::handleClearDepth));
		gltpl->Set(v8::String::NewSymbol("clearIndex"),   v8::FunctionTemplate::New(GL::handleClearIndex));
		gltpl->Set(v8::String::NewSymbol("clearStencil"), v8::FunctionTemplate::New(GL::handleClearStencil));
		gltpl->Set(v8::String::NewSymbol("TEXTURE0"),  v8::Uint32::New(GL_TEXTURE0),  v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE1"),  v8::Uint32::New(GL_TEXTURE1),  v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE2"),  v8::Uint32::New(GL_TEXTURE2),  v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE3"),  v8::Uint32::New(GL_TEXTURE3),  v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE4"),  v8::Uint32::New(GL_TEXTURE4),  v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE5"),  v8::Uint32::New(GL_TEXTURE5),  v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE6"),  v8::Uint32::New(GL_TEXTURE6),  v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE7"),  v8::Uint32::New(GL_TEXTURE7),  v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE8"),  v8::Uint32::New(GL_TEXTURE8),  v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE9"),  v8::Uint32::New(GL_TEXTURE9),  v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE10"), v8::Uint32::New(GL_TEXTURE10), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE11"), v8::Uint32::New(GL_TEXTURE11), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE12"), v8::Uint32::New(GL_TEXTURE12), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE13"), v8::Uint32::New(GL_TEXTURE13), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE14"), v8::Uint32::New(GL_TEXTURE14), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE15"), v8::Uint32::New(GL_TEXTURE15), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE16"), v8::Uint32::New(GL_TEXTURE16), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE17"), v8::Uint32::New(GL_TEXTURE17), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE18"), v8::Uint32::New(GL_TEXTURE18), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE19"), v8::Uint32::New(GL_TEXTURE19), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE20"), v8::Uint32::New(GL_TEXTURE20), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE21"), v8::Uint32::New(GL_TEXTURE21), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE22"), v8::Uint32::New(GL_TEXTURE22), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE23"), v8::Uint32::New(GL_TEXTURE23), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE24"), v8::Uint32::New(GL_TEXTURE24), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE25"), v8::Uint32::New(GL_TEXTURE25), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE26"), v8::Uint32::New(GL_TEXTURE26), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE27"), v8::Uint32::New(GL_TEXTURE27), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE28"), v8::Uint32::New(GL_TEXTURE28), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE29"), v8::Uint32::New(GL_TEXTURE29), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE30"), v8::Uint32::New(GL_TEXTURE30), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE31"), v8::Uint32::New(GL_TEXTURE31), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("clientActiveTexture"), v8::FunctionTemplate::New(GL::handleClientActiveTexture));

		/*
		 * Section M
		 */
		gltpl->Set(v8::String::NewSymbol("MODELVIEW"),           v8::Uint32::New(GL_MODELVIEW),  v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("PROJECTION"),          v8::Uint32::New(GL_PROJECTION), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE"),             v8::Uint32::New(GL_TEXTURE),    v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("COLOR"),               v8::Uint32::New(GL_COLOR),      v8::ReadOnly);
		gltpl->SetAccessor(v8::String::NewSymbol("MATRIX_MODE"), GL::getMATRIX_MODE);
		gltpl->Set(v8::String::NewSymbol("matrixMode"), v8::FunctionTemplate::New(GL::handleMatrixMode));



		return scope.Close(gltpl);

	}

}


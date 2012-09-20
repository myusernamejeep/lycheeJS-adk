
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
 * - gl.bindBuffer()
 * - gl.bufferData()
 * - gl.bufferSubData()
 * - gl.colorTable()
 * - gl.colorTableParameter
 * - gl.colorSubTable()
 * - gl.compressedTexImage1D
 * - gl.compressedTexImage2D
 * - gl.compressedTexImage3D
 * - gl.compressedTexSubImage1D
 * - gl.compressedTexSubImage2D
 * - gl.compressedTexSubImage3D
 * - gl.convolutionFilter1D
 * - gl.convolutionFilter2D
 * - gl.copyColorTable()
 * - gl.copyColorSubTable()
 * - gl.copyConvolutionFilter1D()
 * - gl.copyConvolutionFilter2D()
 *
 *
 * Incomplete Bindings (TODO):
 *
 * - gl.bindAttribLocation()
 *
 */



namespace binding {

	/*
	 * SECTION A
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
	 * SECTION B
	 */

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
	 * SECTION C
	 */

	v8::Handle<v8::Value> GL::handleCallList(const v8::Arguments& args) {

		if (args.Length() == 1) {

			unsigned int list = args[0]->Uint32Value();

			glCallList((GLuint) list);

		}

		return v8::Undefined();

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

	v8::Handle<v8::Value> GL::handleColor3f(const v8::Arguments& args) {

		if (args.Length() == 3) {

			double red =   args[0]->NumberValue();
			double green = args[1]->NumberValue();
			double blue =  args[2]->NumberValue();

			glColor3f((GLfloat) red, (GLfloat) green, (GLfloat) blue);

		}

		return v8::Undefined();

	}


	v8::Handle<v8::Value> GL::handleColor3fv(const v8::Arguments& args) {

		if (args.Length() == 1) {

			v8::Handle<v8::Array> arr = v8::Handle<v8::Array>::Cast(args[0]);
			GLfloat* colors = new GLfloat[arr->Length()];

			for (unsigned i = 0; i < arr->Length(); i++) {
				colors[i] = (GLfloat) arr->Get(v8::Integer::New(i))->NumberValue();
			}

			glColor3fv((const GLfloat*) colors);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::handleColor3i(const v8::Arguments& args) {

		if (args.Length() == 3) {

			int red =   args[0]->IntegerValue();
			int green = args[1]->IntegerValue();
			int blue =  args[2]->IntegerValue();

			glColor3i((GLint) red, (GLint) green, (GLint) blue);

		}

		return v8::Undefined();

	}


	v8::Handle<v8::Value> GL::handleColor3iv(const v8::Arguments& args) {

		if (args.Length() == 1) {

			v8::Handle<v8::Array> arr = v8::Handle<v8::Array>::Cast(args[0]);
			GLint* colors = new GLint[arr->Length()];

			for (unsigned i = 0; i < arr->Length(); i++) {
				colors[i] = arr->Get(v8::Integer::New(i))->IntegerValue();
			}

			glColor3iv((const GLint*) colors);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::handleColor4f(const v8::Arguments& args) {

		if (args.Length() == 4) {

			double red   = args[0]->NumberValue();
			double green = args[1]->NumberValue();
			double blue  = args[2]->NumberValue();
			double alpha = args[3]->NumberValue();

			glColor4f((GLfloat) red, (GLfloat) green, (GLfloat) blue, (GLfloat) alpha);

		}

		return v8::Undefined();

	}


	v8::Handle<v8::Value> GL::handleColor4fv(const v8::Arguments& args) {

		if (args.Length() == 1) {

			v8::Handle<v8::Array> arr = v8::Handle<v8::Array>::Cast(args[0]);
			GLfloat* colors = new GLfloat[arr->Length()];

			for (unsigned i = 0; i < arr->Length(); i++) {
				colors[i] = (GLfloat) arr->Get(v8::Integer::New(i))->NumberValue();
			}

			glColor4fv((const GLfloat*) colors);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::handleColor4i(const v8::Arguments& args) {

		if (args.Length() == 4) {

			int red   = args[0]->IntegerValue();
			int green = args[1]->IntegerValue();
			int blue  = args[2]->IntegerValue();
			int alpha = args[3]->IntegerValue();

			glColor4i((GLint) red, (GLint) green, (GLint) blue, (GLint) alpha);

		}

		return v8::Undefined();

	}


	v8::Handle<v8::Value> GL::handleColor4iv(const v8::Arguments& args) {

		if (args.Length() == 1) {

			v8::Handle<v8::Array> arr = v8::Handle<v8::Array>::Cast(args[0]);
			GLint* colors = new GLint[arr->Length()];

			for (unsigned i = 0; i < arr->Length(); i++) {
				colors[i] = arr->Get(v8::Integer::New(i))->IntegerValue();
			}

			glColor4iv((const GLint*) colors);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::handleColorMask(const v8::Arguments& args) {

		if (args.Length() == 4) {

			unsigned int red   = args[0]->Uint32Value();
			unsigned int green = args[1]->Uint32Value();
			unsigned int blue  = args[2]->Uint32Value();
			unsigned int alpha = args[3]->Uint32Value();

			glColorMask((GLboolean) red, (GLboolean) green, (GLboolean) blue, (GLboolean) alpha);


		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::handleColorMaterial(const v8::Arguments& args) {

		if (args.Length() == 2) {

			int face = args[0]->IntegerValue();
			int mode = args[0]->IntegerValue();

			glColorMaterial((GLenum) face, (GLenum) mode);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::handleCompileShader(const v8::Arguments& args) {

		if (args.Length() == 1) {

			unsigned int shader = args[0]->Uint32Value();

			glCompileShader((GLuint) shader);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::handleCopyPixels(const v8::Arguments& args) {

		if (args.Length() == 5) {

			int x      = args[0]->IntegerValue();
			int y      = args[1]->IntegerValue();
			int width  = args[2]->IntegerValue();
			int height = args[3]->IntegerValue();
			int type   = args[4]->IntegerValue();

			glCopyPixels(
				(GLint) x, (GLint) y,
				(GLsizei) width, (GLsizei) height,
				(GLenum) type
			);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::handleCreateProgram(const v8::Arguments& args) {
		return v8::Uint32::New(glCreateProgram());
	}

	v8::Handle<v8::Value> GL::handleCreateShader(const v8::Arguments& args) {

		if (args.Length() == 1) {

			int shaderType = args[0]->IntegerValue();

			return v8::Uint32::New(glCreateShader((GLenum) shaderType));

		}

		return v8::Null();

	}

	v8::Handle<v8::Value> GL::handleCullFace(const v8::Arguments& args) {

		if (args.Length() == 1) {

			int mode = args[0]->IntegerValue();

			glCullFace((GLenum) mode);

		}

		return v8::Undefined();

	}



	/*
	 * SECTION D
	 */

	v8::Handle<v8::Value> GL::handleDisable(const v8::Arguments& args) {

		if (args.Length() == 1) {

			int cap = args[0]->IntegerValue();

			glDisable((GLenum) cap);

		}

		return v8::Undefined();

	}



	/*
	 * SECTION E
	 */

	v8::Handle<v8::Value> GL::handleEnable(const v8::Arguments& args) {

		if (args.Length() == 1) {

			int cap = args[0]->IntegerValue();

			glEnable((GLenum) cap);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::handleEnd(const v8::Arguments& args) {

		if (args.Length() == 0) {
			glEnd();
		}

		return v8::Undefined();

	}



	/*
	 * SECTION L
	 */

	v8::Handle<v8::Value> GL::handleLoadIdentity(const v8::Arguments& args) {

		if (args.Length() == 0) {
			glLoadIdentity();
		}

		return v8::Undefined();

	}


	/*
	 * SECTION M
	 */

	v8::Handle<v8::Value> GL::handleMatrixMode(const v8::Arguments& args) {

		if (args.Length() == 1) {

			int mode = args[0]->IntegerValue();

			glMatrixMode((GLenum) mode);

		}

		return v8::Undefined();

	}



	/*
	 * O
	 */

	v8::Handle<v8::Value> GL::handleOrtho(const v8::Arguments& args) {

		if (args.Length() == 6) {

			double left    = args[0]->NumberValue();
			double right   = args[1]->NumberValue();
			double bottom  = args[2]->NumberValue();
			double top     = args[3]->NumberValue();
			double nearVal = args[4]->NumberValue();
			double farVal  = args[5]->NumberValue();

			glOrtho(
				(GLdouble) left, (GLdouble) right,
				(GLdouble) bottom, (GLdouble) top,
				(GLdouble) nearVal, (GLdouble) farVal
			);

		}

		return v8::Undefined();

	}



	/*
	 * SECTION T
	 */

	v8::Handle<v8::Value> GL::handleTexCoord2f(const v8::Arguments& args) {

		if (args.Length() == 2) {

			double x = args[0]->NumberValue();
			double y = args[1]->NumberValue();

			glTexCoord2f((GLfloat) x, (GLfloat) y);

		}

		return v8::Undefined();

	}



	/*
	 * SECTION V
	 */

	v8::Handle<v8::Value> GL::handleVertex2f(const v8::Arguments& args) {

		if (args.Length() == 2) {

			double x = args[0]->NumberValue();
			double y = args[1]->NumberValue();


			glVertex2f((GLfloat) x, (GLfloat) y);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GL::handleVertex2i(const v8::Arguments& args) {

		if (args.Length() == 2) {

			double x = args[0]->NumberValue();
			double y = args[1]->NumberValue();


			glVertex2i((GLint) x, (GLint) y);

		}

		return v8::Undefined();

	}






	v8::Handle<v8::ObjectTemplate> GL::generate() {

		v8::HandleScope scope;

		v8::Handle<v8::ObjectTemplate> gltpl = v8::ObjectTemplate::New();


		/*
		 * SECTION A
		 */

		gltpl->Set(v8::String::NewSymbol("accum"),               v8::FunctionTemplate::New(GL::handleAccum));
		gltpl->Set(v8::String::NewSymbol("activeTexture"),       v8::FunctionTemplate::New(GL::handleActiveTexture));
		gltpl->Set(v8::String::NewSymbol("NEVER"),               v8::Uint32::New(GL_NEVER),    v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("LESS"),                v8::Uint32::New(GL_LESS),     v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("EQUAL"),               v8::Uint32::New(GL_EQUAL),    v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("LEQUAL"),              v8::Uint32::New(GL_LEQUAL),   v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("GREATER"),             v8::Uint32::New(GL_GREATER),  v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("NOTEQUAL"),            v8::Uint32::New(GL_NOTEQUAL), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("GEQUAL"),              v8::Uint32::New(GL_GEQUAL),   v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("ALWAYS"),              v8::Uint32::New(GL_ALWAYS),   v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("alphaFunc"),           v8::FunctionTemplate::New(GL::handleAlphaFunc));
		gltpl->Set(v8::String::NewSymbol("areTexturesResident"), v8::FunctionTemplate::New(GL::handleAreTexturesResident));
		gltpl->Set(v8::String::NewSymbol("arrayElement"),        v8::FunctionTemplate::New(GL::handleArrayElement));
		gltpl->Set(v8::String::NewSymbol("attachShader"),        v8::FunctionTemplate::New(GL::handleAttachShader));

		/*
		 * SECTION B
		 */

		gltpl->Set(v8::String::NewSymbol("POINTS"),                   v8::Uint32::New(GL_POINTS),         v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("LINES"),                    v8::Uint32::New(GL_LINES),          v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("LINE_STRIP"),               v8::Uint32::New(GL_LINE_STRIP),     v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("LINE_LOOP"),                v8::Uint32::New(GL_LINE_LOOP),      v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TRIANGLES"),                v8::Uint32::New(GL_TRIANGLES),      v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TRIANGLE_STRIP"),           v8::Uint32::New(GL_TRIANGLE_STRIP), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TRIANGLE_FAN"),             v8::Uint32::New(GL_TRIANGLE_FAN),   v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("QUADS"),                    v8::Uint32::New(GL_QUADS),          v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("QUAD_STRIP"),               v8::Uint32::New(GL_QUAD_STRIP),     v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("POLYGON"),                  v8::Uint32::New(GL_POLYGON),        v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("begin"),				      v8::FunctionTemplate::New(GL::handleBegin));
		gltpl->Set(v8::String::NewSymbol("beginQuery"),				  v8::FunctionTemplate::New(GL::handleBeginQuery));
		gltpl->Set(v8::String::NewSymbol("ARRAY_BUFFER"),             v8::Uint32::New(GL_ARRAY_BUFFER),          v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("ELEMENT_ARRAY_BUFFER"),     v8::Uint32::New(GL_ELEMENT_ARRAY_BUFFER),  v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("PIXEL_PACK_BUFFER"),        v8::Uint32::New(GL_PIXEL_PACK_BUFFER),     v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("PIXEL_UNPACK_BUFFER"),      v8::Uint32::New(GL_PIXEL_UNPACK_BUFFER),   v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("bindBuffer"),               v8::FunctionTemplate::New(GL::handleBindBuffer));
		gltpl->Set(v8::String::NewSymbol("TEXTURE_2D"),               v8::Uint32::New(GL_TEXTURE_2D),            v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("bindTexture"),              v8::FunctionTemplate::New(GL::handleBindTexture));
		gltpl->Set(v8::String::NewSymbol("bitmap"),                   v8::FunctionTemplate::New(GL::handleBitmap));
		gltpl->Set(v8::String::NewSymbol("BLEND_COLOR"),              v8::Uint32::New(GL_BLEND_COLOR),           v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("blendColor"),               v8::FunctionTemplate::New(GL::handleBlendColor));
		gltpl->Set(v8::String::NewSymbol("FUNC_ADD"),                 v8::Uint32::New(GL_FUNC_ADD),              v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("FUNC_SUBTRACT"),            v8::Uint32::New(GL_FUNC_SUBTRACT),         v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("FUNC_REVERSE_SUBTRACT"),    v8::Uint32::New(GL_FUNC_REVERSE_SUBTRACT), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("MIN"),                      v8::Uint32::New(GL_MIN),                   v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("MAX"),                      v8::Uint32::New(GL_MAX),                   v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("blendEquation"),            v8::FunctionTemplate::New(GL::handleBlendEquation));
		gltpl->Set(v8::String::NewSymbol("blendEquationSeparate"),    v8::FunctionTemplate::New(GL::handleBlendEquationSeparate));
		gltpl->Set(v8::String::NewSymbol("ZERO"),                     v8::Uint32::New(GL_ZERO),                     v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("ONE"),                      v8::Uint32::New(GL_ONE),                      v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("SRC_COLOR"),                v8::Uint32::New(GL_SRC_COLOR),                v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("ONE_MINUS_SRC_COLOR"),      v8::Uint32::New(GL_ONE_MINUS_SRC_COLOR),      v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("DST_COLOR"),                v8::Uint32::New(GL_DST_COLOR),                v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("ONE_MINUS_DST_COLOR"),      v8::Uint32::New(GL_ONE_MINUS_DST_COLOR),      v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("SRC_ALPHA"),                v8::Uint32::New(GL_SRC_ALPHA),                v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("ONE_MINUS_SRC_ALPHA"),      v8::Uint32::New(GL_ONE_MINUS_SRC_ALPHA),      v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("DST_ALPHA"),                v8::Uint32::New(GL_DST_ALPHA),                v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("ONE_MINUS_DST_ALPHA"),      v8::Uint32::New(GL_ONE_MINUS_DST_ALPHA),      v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("CONSTANT_COLOR"),           v8::Uint32::New(GL_CONSTANT_COLOR),           v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("ONE_MINUS_CONSTANT_COLOR"), v8::Uint32::New(GL_ONE_MINUS_CONSTANT_COLOR), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("CONSTANT_ALPHA"),           v8::Uint32::New(GL_CONSTANT_ALPHA),           v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("ONE_MINUS_CONSTANT_ALPHA"), v8::Uint32::New(GL_ONE_MINUS_CONSTANT_ALPHA), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("SRC_ALPHA_SATURATE"),       v8::Uint32::New(GL_SRC_ALPHA_SATURATE),       v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("blendFunc"),                v8::FunctionTemplate::New(GL::handleBlendFunc));
		gltpl->Set(v8::String::NewSymbol("blendFuncSeparate"),        v8::FunctionTemplate::New(GL::handleBlendFuncSeparate));

		/*
		 * SECTION C
		 */

		gltpl->Set(v8::String::NewSymbol("callList"),     v8::FunctionTemplate::New(GL::handleCallList));
		gltpl->Set(v8::String::NewSymbol("clear"),        v8::FunctionTemplate::New(GL::handleClear));
		gltpl->Set(v8::String::NewSymbol("clearAccum"),   v8::FunctionTemplate::New(GL::handleClearAccum));
		gltpl->Set(v8::String::NewSymbol("clearColor"),   v8::FunctionTemplate::New(GL::handleClearColor));
		gltpl->Set(v8::String::NewSymbol("clearDepth"),   v8::FunctionTemplate::New(GL::handleClearDepth));
		gltpl->Set(v8::String::NewSymbol("clearIndex"),   v8::FunctionTemplate::New(GL::handleClearIndex));
		gltpl->Set(v8::String::NewSymbol("clearStencil"), v8::FunctionTemplate::New(GL::handleClearStencil));
		gltpl->Set(v8::String::NewSymbol("TEXTURE0"),     v8::Uint32::New(GL_TEXTURE0),  v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE1"),     v8::Uint32::New(GL_TEXTURE1),  v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE2"),     v8::Uint32::New(GL_TEXTURE2),  v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE3"),     v8::Uint32::New(GL_TEXTURE3),  v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE4"),     v8::Uint32::New(GL_TEXTURE4),  v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE5"),     v8::Uint32::New(GL_TEXTURE5),  v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE6"),     v8::Uint32::New(GL_TEXTURE6),  v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE7"),     v8::Uint32::New(GL_TEXTURE7),  v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE8"),     v8::Uint32::New(GL_TEXTURE8),  v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE9"),     v8::Uint32::New(GL_TEXTURE9),  v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE10"),    v8::Uint32::New(GL_TEXTURE10), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE11"),    v8::Uint32::New(GL_TEXTURE11), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE12"),    v8::Uint32::New(GL_TEXTURE12), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE13"),    v8::Uint32::New(GL_TEXTURE13), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE14"),    v8::Uint32::New(GL_TEXTURE14), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE15"),    v8::Uint32::New(GL_TEXTURE15), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE16"),    v8::Uint32::New(GL_TEXTURE16), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE17"),    v8::Uint32::New(GL_TEXTURE17), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE18"),    v8::Uint32::New(GL_TEXTURE18), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE19"),    v8::Uint32::New(GL_TEXTURE19), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE20"),    v8::Uint32::New(GL_TEXTURE20), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE21"),    v8::Uint32::New(GL_TEXTURE21), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE22"),    v8::Uint32::New(GL_TEXTURE22), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE23"),    v8::Uint32::New(GL_TEXTURE23), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE24"),    v8::Uint32::New(GL_TEXTURE24), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE25"),    v8::Uint32::New(GL_TEXTURE25), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE26"),    v8::Uint32::New(GL_TEXTURE26), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE27"),    v8::Uint32::New(GL_TEXTURE27), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE28"),    v8::Uint32::New(GL_TEXTURE28), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE29"),    v8::Uint32::New(GL_TEXTURE29), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE30"),    v8::Uint32::New(GL_TEXTURE30), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE31"),    v8::Uint32::New(GL_TEXTURE31), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("clientActiveTexture"), v8::FunctionTemplate::New(GL::handleClientActiveTexture));
		gltpl->Set(v8::String::NewSymbol("clipPlane"),           v8::FunctionTemplate::New(GL::handleClipPlane));
		gltpl->Set(v8::String::NewSymbol("color3f"),             v8::FunctionTemplate::New(GL::handleColor3f));
		gltpl->Set(v8::String::NewSymbol("color3fv"),            v8::FunctionTemplate::New(GL::handleColor3fv));
		gltpl->Set(v8::String::NewSymbol("color3i"),             v8::FunctionTemplate::New(GL::handleColor3i));
		gltpl->Set(v8::String::NewSymbol("color3iv"),            v8::FunctionTemplate::New(GL::handleColor3iv));
		gltpl->Set(v8::String::NewSymbol("color4f"),             v8::FunctionTemplate::New(GL::handleColor4f));
		gltpl->Set(v8::String::NewSymbol("color4fv"),            v8::FunctionTemplate::New(GL::handleColor4fv));
		gltpl->Set(v8::String::NewSymbol("color4i"),             v8::FunctionTemplate::New(GL::handleColor4i));
		gltpl->Set(v8::String::NewSymbol("color4iv"),            v8::FunctionTemplate::New(GL::handleColor4iv));
		gltpl->Set(v8::String::NewSymbol("colorMask"),           v8::FunctionTemplate::New(GL::handleColorMask));
		gltpl->Set(v8::String::NewSymbol("compileShader"),       v8::FunctionTemplate::New(GL::handleCompileShader));
		gltpl->Set(v8::String::NewSymbol("COLOR"),               v8::Uint32::New(GL_COLOR),   v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("DEPTH"),               v8::Uint32::New(GL_DEPTH),   v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("STENCIL"),             v8::Uint32::New(GL_STENCIL), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("copyPixels"),          v8::FunctionTemplate::New(GL::handleCopyPixels));
		gltpl->Set(v8::String::NewSymbol("createProgram"),       v8::FunctionTemplate::New(GL::handleCreateProgram));
		gltpl->Set(v8::String::NewSymbol("FRAGMENT_SHADER"),     v8::Uint32::New(GL_FRAGMENT_SHADER), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("VERTEX_SHADER"),       v8::Uint32::New(GL_VERTEX_SHADER),   v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("createShader"),        v8::FunctionTemplate::New(GL::handleCreateShader));

		gltpl->Set(v8::String::NewSymbol("FRONT"),               v8::Uint32::New(GL_FRONT),          v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("BACK"),                v8::Uint32::New(GL_BACK),           v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("FRONT_AND_BACK"),      v8::Uint32::New(GL_FRONT_AND_BACK), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("CULL_FACE"),           v8::Uint32::New(GL_CULL_FACE),      v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("cullFace"),            v8::FunctionTemplate::New(GL::handleCullFace));

		/*
		 * SECTION D
		 */

		gltpl->Set(v8::String::NewSymbol("BLEND"), v8::Uint32::New(GL_BLEND), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("DEPTH_TEST"), v8::Uint32::New(GL_DEPTH_TEST), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("COLOR_BUFFER_BIT"), v8::Uint32::New(GL_COLOR_BUFFER_BIT), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("DEPTH_BUFFER_BIT"), v8::Uint32::New(GL_DEPTH_BUFFER_BIT), v8::ReadOnly);

		gltpl->Set(v8::String::NewSymbol("disable"),             v8::FunctionTemplate::New(GL::handleDisable));

		/*
		 * SECTION E
		 */

		gltpl->Set(v8::String::NewSymbol("enable"),              v8::FunctionTemplate::New(GL::handleEnable));
		gltpl->Set(v8::String::NewSymbol("end"),                 v8::FunctionTemplate::New(GL::handleEnd));

		/*
		 * SECTION L
		 */

		gltpl->Set(v8::String::NewSymbol("loadIdentity"),        v8::FunctionTemplate::New(GL::handleLoadIdentity));

		/*
		 * SECTION M
		 */

		gltpl->Set(v8::String::NewSymbol("MODELVIEW"),   v8::Uint32::New(GL_MODELVIEW),   v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("PROJECTION"),  v8::Uint32::New(GL_PROJECTION),  v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("TEXTURE"),     v8::Uint32::New(GL_TEXTURE),     v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("MATRIX_MODE"), v8::Uint32::New(GL_MATRIX_MODE), v8::ReadOnly);
		gltpl->Set(v8::String::NewSymbol("matrixMode"),  v8::FunctionTemplate::New(GL::handleMatrixMode));

		/*
		 * SECTION O
		 */

		gltpl->Set(v8::String::NewSymbol("ortho"),       v8::FunctionTemplate::New(GL::handleOrtho));

		/*
		 * SECTION T
		 */

		gltpl->Set(v8::String::NewSymbol("texCoord2f"),  v8::FunctionTemplate::New(GL::handleTexCoord2f));

		/*
		 * SECTION V
		 */

		gltpl->Set(v8::String::NewSymbol("vertex2f"),  v8::FunctionTemplate::New(GL::handleVertex2f));
		gltpl->Set(v8::String::NewSymbol("vertex2i"),  v8::FunctionTemplate::New(GL::handleVertex2i));


		return scope.Close(gltpl);

	}

}



#include "glbind.h"

#if defined(V8_GL_USE_GLEW)
	#include "GL/glew.h"
#elif defined(__APPLE__)
	#include <OpenGL/OpenGL.h>
#else
	#define GL_GLEXT_PROTOTYPES
	#include <GL/gl.h>
#endif


v8::Persistent<v8::Object> GlFactory::self_;

v8::Handle<v8::Value> GLglDeleteTexturesCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
 	GLuint* arg1 = new	GLuint[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
 		GLuint aux = ( GLuint)arg->Uint32Value();
		arg1[j] = aux; 
	}
    
    

	glDeleteTextures((GLsizei) arg0, (const GLuint*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}

v8::Handle<v8::Value> GLglDisableClientStateCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();


	glDisableClientState((GLenum) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}

v8::Handle<v8::Value> GLglEdgeFlagCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();


	glEdgeFlag((GLboolean) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglEdgeFlagvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
 	GLboolean* arg0 = new GLboolean[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
 		GLboolean aux = ( GLboolean)arg->Uint32Value();
		arg0[j] = aux; 
	}
    
    

	glEdgeFlagv((const GLboolean*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglEnableClientStateCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();


	glEnableClientState((GLenum) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}

v8::Handle<v8::Value> GLglEndListCallback(const v8::Arguments& args) {
	
	if (args.Length() < 0) return v8::Undefined();



	glEndList();
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglEvalCoord1dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	double arg0 = args[0]->NumberValue();


	glEvalCoord1d((GLdouble) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglEvalCoord1dvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLdouble* arg0 = new GLdouble[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glEvalCoord1dv((const GLdouble*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglEvalCoord1fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	double arg0 = args[0]->NumberValue();


	glEvalCoord1f((GLfloat) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglEvalCoord1fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLfloat* arg0 = new	GLfloat[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glEvalCoord1fv((const GLfloat*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglEvalCoord2dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();


	glEvalCoord2d((GLdouble) arg0, (GLdouble) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglEvalCoord2dvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLdouble* arg0 = new GLdouble[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glEvalCoord2dv((const GLdouble*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglEvalCoord2fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();


	glEvalCoord2f((GLfloat) arg0, (GLfloat) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglEvalCoord2fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLfloat* arg0 = new	GLfloat[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glEvalCoord2fv((const GLfloat*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglEvalMesh1Callback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();


	glEvalMesh1((GLenum) arg0, (GLint) arg1, (GLint) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglEvalMesh2Callback(const v8::Arguments& args) {
	
	if (args.Length() < 5) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();
	int arg3 = args[3]->IntegerValue();
	int arg4 = args[4]->IntegerValue();


	glEvalMesh2((GLenum) arg0, (GLint) arg1, (GLint) arg2, (GLint) arg3, (GLint) arg4);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglEvalPoint1Callback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();


	glEvalPoint1((GLint) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglEvalPoint2Callback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();


	glEvalPoint2((GLint) arg0, (GLint) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglFeedbackBufferCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLfloat* arg2 = new GLfloat[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
   	GLfloat aux = (GLfloat)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glFeedbackBuffer((GLsizei) arg0, (GLenum) arg1, (GLfloat*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglFinishCallback(const v8::Arguments& args) {
	
	if (args.Length() < 0) return v8::Undefined();



	glFinish();
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglFlushCallback(const v8::Arguments& args) {
	
	if (args.Length() < 0) return v8::Undefined();



	glFlush();
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglFogfCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	double arg1 = args[1]->NumberValue();


	glFogf((GLenum) arg0, (GLfloat) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglFogfvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLfloat* arg1 = new	GLfloat[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg1[j] = aux; 
	}
    
    

	glFogfv((GLenum) arg0, (const GLfloat*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglFogiCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();


	glFogi((GLenum) arg0, (GLint) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglFogivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
 	GLint* arg1 = new	GLint[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg1[j] = aux; 
	}
    
    

	glFogiv((GLenum) arg0, (const GLint*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglFrontFaceCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();


	glFrontFace((GLenum) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglFrustumCallback(const v8::Arguments& args) {
	
	if (args.Length() < 6) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();
	double arg3 = args[3]->NumberValue();
	double arg4 = args[4]->NumberValue();
	double arg5 = args[5]->NumberValue();


	glFrustum((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLdouble) arg3, (GLdouble) arg4, (GLdouble) arg5);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGenListsCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();


	return v8::Uint32::New(glGenLists((GLsizei) arg0));
}




v8::Handle<v8::Value> GLglGenTexturesCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLuint* arg1 = new GLuint[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLuint aux = (GLuint)arg->Uint32Value();
		arg1[j] = aux; 
	}
    
    

	glGenTextures((GLsizei) arg0, (GLuint*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetBooleanvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLboolean* arg1 = new GLboolean[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLboolean aux = (GLboolean)arg->Uint32Value();
		arg1[j] = aux; 
	}
    
    

	glGetBooleanv((GLenum) arg0, (GLboolean*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}



v8::Handle<v8::Value> GLglGetClipPlaneCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
  GLdouble* arg1 = new GLdouble[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
   	GLdouble aux = (GLdouble)arg->NumberValue();
		arg1[j] = aux; 
	}
    
    

	glGetClipPlane((GLenum) arg0, (GLdouble*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetColorTableParameterfvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLfloat* arg2 = new GLfloat[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
   	GLfloat aux = (GLfloat)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glGetColorTableParameterfv((GLenum) arg0, (GLenum) arg1, (GLfloat*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetColorTableParameterivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLint* arg2 = new GLint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLint aux = (GLint)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    

	glGetColorTableParameteriv((GLenum) arg0, (GLenum) arg1, (GLint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetConvolutionParameterfvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLfloat* arg2 = new GLfloat[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
   	GLfloat aux = (GLfloat)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glGetConvolutionParameterfv((GLenum) arg0, (GLenum) arg1, (GLfloat*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetConvolutionParameterivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLint* arg2 = new GLint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLint aux = (GLint)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    

	glGetConvolutionParameteriv((GLenum) arg0, (GLenum) arg1, (GLint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetDoublevCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
  GLdouble* arg1 = new GLdouble[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
   	GLdouble aux = (GLdouble)arg->NumberValue();
		arg1[j] = aux; 
	}
    
    

	glGetDoublev((GLenum) arg0, (GLdouble*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetErrorCallback(const v8::Arguments& args) {
	
	if (args.Length() < 0) return v8::Undefined();



	return v8::Integer::New(glGetError());
}




v8::Handle<v8::Value> GLglGetFloatvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLfloat* arg1 = new GLfloat[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
   	GLfloat aux = (GLfloat)arg->NumberValue();
		arg1[j] = aux; 
	}
    
    

	glGetFloatv((GLenum) arg0, (GLfloat*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetHistogramParameterfvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLfloat* arg2 = new GLfloat[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
   	GLfloat aux = (GLfloat)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glGetHistogramParameterfv((GLenum) arg0, (GLenum) arg1, (GLfloat*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetHistogramParameterivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLint* arg2 = new GLint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLint aux = (GLint)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    

	glGetHistogramParameteriv((GLenum) arg0, (GLenum) arg1, (GLint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetIntegervCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLint* arg1 = new GLint[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLint aux = (GLint)arg->IntegerValue();
		arg1[j] = aux; 
	}
    
    

	glGetIntegerv((GLenum) arg0, (GLint*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetLightfvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLfloat* arg2 = new GLfloat[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
   	GLfloat aux = (GLfloat)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glGetLightfv((GLenum) arg0, (GLenum) arg1, (GLfloat*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetLightivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLint* arg2 = new GLint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLint aux = (GLint)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    

	glGetLightiv((GLenum) arg0, (GLenum) arg1, (GLint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetMapdvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
  GLdouble* arg2 = new GLdouble[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
   	GLdouble aux = (GLdouble)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glGetMapdv((GLenum) arg0, (GLenum) arg1, (GLdouble*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetMapfvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLfloat* arg2 = new GLfloat[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
   	GLfloat aux = (GLfloat)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glGetMapfv((GLenum) arg0, (GLenum) arg1, (GLfloat*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetMapivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLint* arg2 = new GLint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLint aux = (GLint)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    

	glGetMapiv((GLenum) arg0, (GLenum) arg1, (GLint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetMaterialfvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLfloat* arg2 = new GLfloat[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
   	GLfloat aux = (GLfloat)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glGetMaterialfv((GLenum) arg0, (GLenum) arg1, (GLfloat*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetMaterialivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLint* arg2 = new GLint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLint aux = (GLint)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    

	glGetMaterialiv((GLenum) arg0, (GLenum) arg1, (GLint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetMinmaxParameterfvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLfloat* arg2 = new GLfloat[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
   	GLfloat aux = (GLfloat)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glGetMinmaxParameterfv((GLenum) arg0, (GLenum) arg1, (GLfloat*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetMinmaxParameterivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLint* arg2 = new GLint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLint aux = (GLint)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    

	glGetMinmaxParameteriv((GLenum) arg0, (GLenum) arg1, (GLint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetPixelMapfvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLfloat* arg1 = new GLfloat[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
   	GLfloat aux = (GLfloat)arg->NumberValue();
		arg1[j] = aux; 
	}
    
    

	glGetPixelMapfv((GLenum) arg0, (GLfloat*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetPixelMapuivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLuint* arg1 = new GLuint[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLuint aux = (GLuint)arg->Uint32Value();
		arg1[j] = aux; 
	}
    
    

	glGetPixelMapuiv((GLenum) arg0, (GLuint*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetPixelMapusvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
  GLushort* arg1 = new GLushort[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
   	GLushort aux = (GLushort)arg->Uint32Value();
		arg1[j] = aux; 
	}
    
    

	glGetPixelMapusv((GLenum) arg0, (GLushort*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetPolygonStippleCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
  GLubyte* arg0 = new GLubyte[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
   	GLubyte aux = (GLubyte)arg->Uint32Value();
		arg0[j] = aux; 
	}
    
    

	glGetPolygonStipple((GLubyte*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetTexEnvfvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLfloat* arg2 = new GLfloat[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
   	GLfloat aux = (GLfloat)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glGetTexEnvfv((GLenum) arg0, (GLenum) arg1, (GLfloat*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetTexEnvivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLint* arg2 = new GLint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLint aux = (GLint)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    

	glGetTexEnviv((GLenum) arg0, (GLenum) arg1, (GLint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetTexGendvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
  GLdouble* arg2 = new GLdouble[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
   	GLdouble aux = (GLdouble)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glGetTexGendv((GLenum) arg0, (GLenum) arg1, (GLdouble*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetTexGenfvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLfloat* arg2 = new GLfloat[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
   	GLfloat aux = (GLfloat)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glGetTexGenfv((GLenum) arg0, (GLenum) arg1, (GLfloat*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetTexGenivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLint* arg2 = new GLint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLint aux = (GLint)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    

	glGetTexGeniv((GLenum) arg0, (GLenum) arg1, (GLint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetTexLevelParameterfvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle3 = v8::Handle<v8::Array>::Cast(args[3]);
	GLfloat* arg3 = new GLfloat[arrHandle3->Length()];

	for (unsigned j = 0; j < arrHandle3->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle3->Get(v8::Integer::New(j)));
   	GLfloat aux = (GLfloat)arg->NumberValue();
		arg3[j] = aux; 
	}
    
    

	glGetTexLevelParameterfv((GLenum) arg0, (GLint) arg1, (GLenum) arg2, (GLfloat*) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetTexLevelParameterivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle3 = v8::Handle<v8::Array>::Cast(args[3]);
	GLint* arg3 = new GLint[arrHandle3->Length()];

	for (unsigned j = 0; j < arrHandle3->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle3->Get(v8::Integer::New(j)));
		GLint aux = (GLint)arg->IntegerValue();
		arg3[j] = aux; 
	}
    
    

	glGetTexLevelParameteriv((GLenum) arg0, (GLint) arg1, (GLenum) arg2, (GLint*) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetTexParameterfvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLfloat* arg2 = new GLfloat[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
   	GLfloat aux = (GLfloat)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glGetTexParameterfv((GLenum) arg0, (GLenum) arg1, (GLfloat*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetTexParameterivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLint* arg2 = new GLint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLint aux = (GLint)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    

	glGetTexParameteriv((GLenum) arg0, (GLenum) arg1, (GLint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglHintCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();


	glHint((GLenum) arg0, (GLenum) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglHistogramCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();
	unsigned int arg3 = args[3]->Uint32Value();


	glHistogram((GLenum) arg0, (GLsizei) arg1, (GLenum) arg2, (GLboolean) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglIndexMaskCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();


	glIndexMask((GLuint) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglIndexdCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	double arg0 = args[0]->NumberValue();


	glIndexd((GLdouble) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglIndexdvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLdouble* arg0 = new GLdouble[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glIndexdv((const GLdouble*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglIndexfCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	double arg0 = args[0]->NumberValue();


	glIndexf((GLfloat) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglIndexfvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLfloat* arg0 = new	GLfloat[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glIndexfv((const GLfloat*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglIndexiCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();


	glIndexi((GLint) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglIndexivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
 	GLint* arg0 = new	GLint[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glIndexiv((const GLint*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglIndexsCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();


	glIndexs((GLshort) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglIndexsvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLshort* arg0 = new GLshort[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLshort aux = ( GLshort)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glIndexsv((const GLshort*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglIndexubCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();


	glIndexub((GLubyte) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglIndexubvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLubyte* arg0 = new GLubyte[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLubyte aux = ( GLubyte)arg->Uint32Value();
		arg0[j] = aux; 
	}
    
    

	glIndexubv((const GLubyte*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglInitNamesCallback(const v8::Arguments& args) {
	
	if (args.Length() < 0) return v8::Undefined();



	glInitNames();
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglIsEnabledCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();


	return v8::Uint32::New(glIsEnabled((GLenum) arg0));
}




v8::Handle<v8::Value> GLglIsListCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();


	return v8::Uint32::New(glIsList((GLuint) arg0));
}




v8::Handle<v8::Value> GLglIsTextureCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();


	return v8::Uint32::New(glIsTexture((GLuint) arg0));
}




v8::Handle<v8::Value> GLglLightModelfCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	double arg1 = args[1]->NumberValue();


	glLightModelf((GLenum) arg0, (GLfloat) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglLightModelfvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLfloat* arg1 = new	GLfloat[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg1[j] = aux; 
	}
    
    

	glLightModelfv((GLenum) arg0, (const GLfloat*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglLightModeliCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();


	glLightModeli((GLenum) arg0, (GLint) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglLightModelivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
 	GLint* arg1 = new	GLint[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg1[j] = aux; 
	}
    
    

	glLightModeliv((GLenum) arg0, (const GLint*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglLightfCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	double arg2 = args[2]->NumberValue();


	glLightf((GLenum) arg0, (GLenum) arg1, (GLfloat) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglLightfvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLfloat* arg2 = new	GLfloat[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glLightfv((GLenum) arg0, (GLenum) arg1, (const GLfloat*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglLightiCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();


	glLighti((GLenum) arg0, (GLenum) arg1, (GLint) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglLightivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
 	GLint* arg2 = new	GLint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    

	glLightiv((GLenum) arg0, (GLenum) arg1, (const GLint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglLineStippleCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	unsigned int arg1 = args[1]->Uint32Value();


	glLineStipple((GLint) arg0, (GLushort) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglLineWidthCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	double arg0 = args[0]->NumberValue();


	glLineWidth((GLfloat) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglListBaseCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();


	glListBase((GLuint) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglLoadMatrixdCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLdouble* arg0 = new GLdouble[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glLoadMatrixd((const GLdouble*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglLoadMatrixfCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLfloat* arg0 = new	GLfloat[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glLoadMatrixf((const GLfloat*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglLoadNameCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();


	glLoadName((GLuint) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglLogicOpCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();


	glLogicOp((GLenum) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMap1dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 6) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();
	int arg3 = args[3]->IntegerValue();
	int arg4 = args[4]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle5 = v8::Handle<v8::Array>::Cast(args[5]);
	GLdouble* arg5 = new GLdouble[arrHandle5->Length()];

	for (unsigned j = 0; j < arrHandle5->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle5->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg5[j] = aux; 
	}
    
    

	glMap1d((GLenum) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLint) arg3, (GLint) arg4, (const GLdouble*) arg5);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMap1fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 6) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();
	int arg3 = args[3]->IntegerValue();
	int arg4 = args[4]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle5 = v8::Handle<v8::Array>::Cast(args[5]);
	GLfloat* arg5 = new	GLfloat[arrHandle5->Length()];

	for (unsigned j = 0; j < arrHandle5->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle5->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg5[j] = aux; 
	}
    
    

	glMap1f((GLenum) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLint) arg3, (GLint) arg4, (const GLfloat*) arg5);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMap2dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 10) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();
	int arg3 = args[3]->IntegerValue();
	int arg4 = args[4]->IntegerValue();
	double arg5 = args[5]->NumberValue();
	double arg6 = args[6]->NumberValue();
	int arg7 = args[7]->IntegerValue();
	int arg8 = args[8]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle9 = v8::Handle<v8::Array>::Cast(args[9]);
	GLdouble* arg9 = new GLdouble[arrHandle9->Length()];

	for (unsigned j = 0; j < arrHandle9->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle9->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg9[j] = aux; 
	}
    
    

	glMap2d((GLenum) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLint) arg3, (GLint) arg4, (GLdouble) arg5, (GLdouble) arg6, (GLint) arg7, (GLint) arg8, (const GLdouble*) arg9);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMap2fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 10) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();
	int arg3 = args[3]->IntegerValue();
	int arg4 = args[4]->IntegerValue();
	double arg5 = args[5]->NumberValue();
	double arg6 = args[6]->NumberValue();
	int arg7 = args[7]->IntegerValue();
	int arg8 = args[8]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle9 = v8::Handle<v8::Array>::Cast(args[9]);
	GLfloat* arg9 = new	GLfloat[arrHandle9->Length()];

	for (unsigned j = 0; j < arrHandle9->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle9->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg9[j] = aux; 
	}
    
    

	glMap2f((GLenum) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLint) arg3, (GLint) arg4, (GLfloat) arg5, (GLfloat) arg6, (GLint) arg7, (GLint) arg8, (const GLfloat*) arg9);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMapGrid1dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();


	glMapGrid1d((GLint) arg0, (GLdouble) arg1, (GLdouble) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMapGrid1fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();


	glMapGrid1f((GLint) arg0, (GLfloat) arg1, (GLfloat) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMapGrid2dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 6) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();
	int arg3 = args[3]->IntegerValue();
	double arg4 = args[4]->NumberValue();
	double arg5 = args[5]->NumberValue();


	glMapGrid2d((GLint) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLint) arg3, (GLdouble) arg4, (GLdouble) arg5);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMapGrid2fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 6) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();
	int arg3 = args[3]->IntegerValue();
	double arg4 = args[4]->NumberValue();
	double arg5 = args[5]->NumberValue();


	glMapGrid2f((GLint) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLint) arg3, (GLfloat) arg4, (GLfloat) arg5);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMaterialfCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	double arg2 = args[2]->NumberValue();


	glMaterialf((GLenum) arg0, (GLenum) arg1, (GLfloat) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMaterialfvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLfloat* arg2 = new	GLfloat[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glMaterialfv((GLenum) arg0, (GLenum) arg1, (const GLfloat*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMaterialiCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();


	glMateriali((GLenum) arg0, (GLenum) arg1, (GLint) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMaterialivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
 	GLint* arg2 = new	GLint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    

	glMaterialiv((GLenum) arg0, (GLenum) arg1, (const GLint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}



v8::Handle<v8::Value> GLglMinmaxCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	unsigned int arg2 = args[2]->Uint32Value();


	glMinmax((GLenum) arg0, (GLenum) arg1, (GLboolean) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultMatrixdCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLdouble* arg0 = new GLdouble[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glMultMatrixd((const GLdouble*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultMatrixfCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLfloat* arg0 = new	GLfloat[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glMultMatrixf((const GLfloat*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglNewListCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();
	int arg1 = args[1]->IntegerValue();


	glNewList((GLuint) arg0, (GLenum) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglNormal3bCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();


	glNormal3b((GLbyte) arg0, (GLbyte) arg1, (GLbyte) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglNormal3bvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLbyte* arg0 = new GLbyte[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLbyte aux = ( GLbyte)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glNormal3bv((const GLbyte*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglNormal3dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();


	glNormal3d((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglNormal3dvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLdouble* arg0 = new GLdouble[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glNormal3dv((const GLdouble*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglNormal3fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();


	glNormal3f((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglNormal3fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLfloat* arg0 = new	GLfloat[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glNormal3fv((const GLfloat*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglNormal3iCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();


	glNormal3i((GLint) arg0, (GLint) arg1, (GLint) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglNormal3ivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
 	GLint* arg0 = new	GLint[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glNormal3iv((const GLint*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglNormal3sCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();


	glNormal3s((GLshort) arg0, (GLshort) arg1, (GLshort) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglNormal3svCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLshort* arg0 = new GLshort[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLshort aux = ( GLshort)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glNormal3sv((const GLshort*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}



v8::Handle<v8::Value> GLglPassThroughCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	double arg0 = args[0]->NumberValue();


	glPassThrough((GLfloat) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglPixelMapfvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLfloat* arg2 = new	GLfloat[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glPixelMapfv((GLenum) arg0, (GLint) arg1, (const GLfloat*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglPixelMapuivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
 	GLuint* arg2 = new	GLuint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
 		GLuint aux = ( GLuint)arg->Uint32Value();
		arg2[j] = aux; 
	}
    
    

	glPixelMapuiv((GLenum) arg0, (GLint) arg1, (const GLuint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglPixelMapusvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLushort* arg2 = new GLushort[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLushort aux = ( GLushort)arg->Uint32Value();
		arg2[j] = aux; 
	}
    
    

	glPixelMapusv((GLenum) arg0, (GLint) arg1, (const GLushort*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglPixelStorefCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	double arg1 = args[1]->NumberValue();


	glPixelStoref((GLenum) arg0, (GLfloat) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglPixelStoreiCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();


	glPixelStorei((GLenum) arg0, (GLint) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglPixelTransferfCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	double arg1 = args[1]->NumberValue();


	glPixelTransferf((GLenum) arg0, (GLfloat) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglPixelTransferiCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();


	glPixelTransferi((GLenum) arg0, (GLint) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglPixelZoomCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();


	glPixelZoom((GLfloat) arg0, (GLfloat) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglPointSizeCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	double arg0 = args[0]->NumberValue();


	glPointSize((GLfloat) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglPolygonModeCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();


	glPolygonMode((GLenum) arg0, (GLenum) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglPolygonOffsetCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();


	glPolygonOffset((GLfloat) arg0, (GLfloat) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglPolygonStippleCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLubyte* arg0 = new GLubyte[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLubyte aux = ( GLubyte)arg->Uint32Value();
		arg0[j] = aux; 
	}
    
    

	glPolygonStipple((const GLubyte*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglPopAttribCallback(const v8::Arguments& args) {
	
	if (args.Length() < 0) return v8::Undefined();



	glPopAttrib();
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglPopClientAttribCallback(const v8::Arguments& args) {
	
	if (args.Length() < 0) return v8::Undefined();



	glPopClientAttrib();
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglPopMatrixCallback(const v8::Arguments& args) {
	
	if (args.Length() < 0) return v8::Undefined();



	glPopMatrix();
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglPopNameCallback(const v8::Arguments& args) {
	
	if (args.Length() < 0) return v8::Undefined();



	glPopName();
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglPrioritizeTexturesCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
 	GLuint* arg1 = new	GLuint[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
 		GLuint aux = ( GLuint)arg->Uint32Value();
		arg1[j] = aux; 
	}
    
    
    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLclampf* arg2 = new GLclampf[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLclampf aux = ( GLclampf)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glPrioritizeTextures((GLsizei) arg0, (const GLuint*) arg1, (const GLclampf*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglPushAttribCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();


	glPushAttrib((GLbitfield) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglPushClientAttribCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();


	glPushClientAttrib((GLbitfield) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglPushMatrixCallback(const v8::Arguments& args) {
	
	if (args.Length() < 0) return v8::Undefined();



	glPushMatrix();
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglPushNameCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();


	glPushName((GLuint) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRasterPos2dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();


	glRasterPos2d((GLdouble) arg0, (GLdouble) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRasterPos2dvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLdouble* arg0 = new GLdouble[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glRasterPos2dv((const GLdouble*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRasterPos2fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();


	glRasterPos2f((GLfloat) arg0, (GLfloat) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRasterPos2fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLfloat* arg0 = new	GLfloat[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glRasterPos2fv((const GLfloat*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRasterPos2iCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();


	glRasterPos2i((GLint) arg0, (GLint) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRasterPos2ivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
 	GLint* arg0 = new	GLint[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glRasterPos2iv((const GLint*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRasterPos2sCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();


	glRasterPos2s((GLshort) arg0, (GLshort) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRasterPos2svCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLshort* arg0 = new GLshort[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLshort aux = ( GLshort)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glRasterPos2sv((const GLshort*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRasterPos3dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();


	glRasterPos3d((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRasterPos3dvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLdouble* arg0 = new GLdouble[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glRasterPos3dv((const GLdouble*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRasterPos3fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();


	glRasterPos3f((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRasterPos3fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLfloat* arg0 = new	GLfloat[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glRasterPos3fv((const GLfloat*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRasterPos3iCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();


	glRasterPos3i((GLint) arg0, (GLint) arg1, (GLint) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRasterPos3ivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
 	GLint* arg0 = new	GLint[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glRasterPos3iv((const GLint*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRasterPos3sCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();


	glRasterPos3s((GLshort) arg0, (GLshort) arg1, (GLshort) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRasterPos3svCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLshort* arg0 = new GLshort[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLshort aux = ( GLshort)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glRasterPos3sv((const GLshort*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRasterPos4dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();
	double arg3 = args[3]->NumberValue();


	glRasterPos4d((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLdouble) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRasterPos4dvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLdouble* arg0 = new GLdouble[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glRasterPos4dv((const GLdouble*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRasterPos4fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();
	double arg3 = args[3]->NumberValue();


	glRasterPos4f((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLfloat) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRasterPos4fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLfloat* arg0 = new	GLfloat[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glRasterPos4fv((const GLfloat*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRasterPos4iCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();
	int arg3 = args[3]->IntegerValue();


	glRasterPos4i((GLint) arg0, (GLint) arg1, (GLint) arg2, (GLint) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRasterPos4ivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
 	GLint* arg0 = new	GLint[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glRasterPos4iv((const GLint*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRasterPos4sCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();
	int arg3 = args[3]->IntegerValue();


	glRasterPos4s((GLshort) arg0, (GLshort) arg1, (GLshort) arg2, (GLshort) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRasterPos4svCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLshort* arg0 = new GLshort[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLshort aux = ( GLshort)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glRasterPos4sv((const GLshort*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglReadBufferCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();


	glReadBuffer((GLenum) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRectdCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();
	double arg3 = args[3]->NumberValue();


	glRectd((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLdouble) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRectdvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLdouble* arg0 = new GLdouble[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    
    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLdouble* arg1 = new GLdouble[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg1[j] = aux; 
	}
    
    

	glRectdv((const GLdouble*) arg0, (const GLdouble*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRectfCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();
	double arg3 = args[3]->NumberValue();


	glRectf((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLfloat) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRectfvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLfloat* arg0 = new	GLfloat[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    
    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLfloat* arg1 = new	GLfloat[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg1[j] = aux; 
	}
    
    

	glRectfv((const GLfloat*) arg0, (const GLfloat*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRectiCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();
	int arg3 = args[3]->IntegerValue();


	glRecti((GLint) arg0, (GLint) arg1, (GLint) arg2, (GLint) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRectivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
 	GLint* arg0 = new	GLint[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    
    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
 	GLint* arg1 = new	GLint[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg1[j] = aux; 
	}
    
    

	glRectiv((const GLint*) arg0, (const GLint*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRectsCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();
	int arg3 = args[3]->IntegerValue();


	glRects((GLshort) arg0, (GLshort) arg1, (GLshort) arg2, (GLshort) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRectsvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLshort* arg0 = new GLshort[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLshort aux = ( GLshort)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    
    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLshort* arg1 = new GLshort[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLshort aux = ( GLshort)arg->IntegerValue();
		arg1[j] = aux; 
	}
    
    

	glRectsv((const GLshort*) arg0, (const GLshort*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRenderModeCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();


	return v8::Integer::New(glRenderMode((GLenum) arg0));
}




v8::Handle<v8::Value> GLglResetHistogramCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();


	glResetHistogram((GLenum) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglResetMinmaxCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();


	glResetMinmax((GLenum) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRotatedCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();
	double arg3 = args[3]->NumberValue();


	glRotated((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLdouble) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglRotatefCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();
	double arg3 = args[3]->NumberValue();


	glRotatef((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLfloat) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglScaledCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();


	glScaled((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglScalefCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();


	glScalef((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglScissorCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();
	int arg3 = args[3]->IntegerValue();


	glScissor((GLint) arg0, (GLint) arg1, (GLsizei) arg2, (GLsizei) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglSelectBufferCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLuint* arg1 = new GLuint[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLuint aux = (GLuint)arg->Uint32Value();
		arg1[j] = aux; 
	}
    
    

	glSelectBuffer((GLsizei) arg0, (GLuint*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglShadeModelCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();


	glShadeModel((GLenum) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglStencilFuncCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	unsigned int arg2 = args[2]->Uint32Value();


	glStencilFunc((GLenum) arg0, (GLint) arg1, (GLuint) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglStencilMaskCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();


	glStencilMask((GLuint) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglStencilOpCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();


	glStencilOp((GLenum) arg0, (GLenum) arg1, (GLenum) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord1dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	double arg0 = args[0]->NumberValue();


	glTexCoord1d((GLdouble) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord1dvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLdouble* arg0 = new GLdouble[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glTexCoord1dv((const GLdouble*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord1fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	double arg0 = args[0]->NumberValue();


	glTexCoord1f((GLfloat) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord1fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLfloat* arg0 = new	GLfloat[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glTexCoord1fv((const GLfloat*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord1iCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();


	glTexCoord1i((GLint) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord1ivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
 	GLint* arg0 = new	GLint[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glTexCoord1iv((const GLint*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord1sCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();


	glTexCoord1s((GLshort) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord1svCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLshort* arg0 = new GLshort[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLshort aux = ( GLshort)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glTexCoord1sv((const GLshort*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord2dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();


	glTexCoord2d((GLdouble) arg0, (GLdouble) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord2dvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLdouble* arg0 = new GLdouble[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glTexCoord2dv((const GLdouble*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}


v8::Handle<v8::Value> GLglTexCoord2fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLfloat* arg0 = new	GLfloat[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glTexCoord2fv((const GLfloat*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord2iCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();


	glTexCoord2i((GLint) arg0, (GLint) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord2ivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
 	GLint* arg0 = new	GLint[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glTexCoord2iv((const GLint*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord2sCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();


	glTexCoord2s((GLshort) arg0, (GLshort) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord2svCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLshort* arg0 = new GLshort[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLshort aux = ( GLshort)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glTexCoord2sv((const GLshort*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord3dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();


	glTexCoord3d((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord3dvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLdouble* arg0 = new GLdouble[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glTexCoord3dv((const GLdouble*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord3fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();


	glTexCoord3f((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord3fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLfloat* arg0 = new	GLfloat[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glTexCoord3fv((const GLfloat*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord3iCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();


	glTexCoord3i((GLint) arg0, (GLint) arg1, (GLint) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord3ivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
 	GLint* arg0 = new	GLint[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glTexCoord3iv((const GLint*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord3sCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();


	glTexCoord3s((GLshort) arg0, (GLshort) arg1, (GLshort) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord3svCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLshort* arg0 = new GLshort[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLshort aux = ( GLshort)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glTexCoord3sv((const GLshort*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord4dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();
	double arg3 = args[3]->NumberValue();


	glTexCoord4d((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLdouble) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord4dvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLdouble* arg0 = new GLdouble[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glTexCoord4dv((const GLdouble*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord4fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();
	double arg3 = args[3]->NumberValue();


	glTexCoord4f((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLfloat) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord4fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLfloat* arg0 = new	GLfloat[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glTexCoord4fv((const GLfloat*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord4iCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();
	int arg3 = args[3]->IntegerValue();


	glTexCoord4i((GLint) arg0, (GLint) arg1, (GLint) arg2, (GLint) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord4ivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
 	GLint* arg0 = new	GLint[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glTexCoord4iv((const GLint*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord4sCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();
	int arg3 = args[3]->IntegerValue();


	glTexCoord4s((GLshort) arg0, (GLshort) arg1, (GLshort) arg2, (GLshort) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexCoord4svCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLshort* arg0 = new GLshort[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLshort aux = ( GLshort)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glTexCoord4sv((const GLshort*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexEnvfCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	double arg2 = args[2]->NumberValue();


	glTexEnvf((GLenum) arg0, (GLenum) arg1, (GLfloat) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexEnvfvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLfloat* arg2 = new	GLfloat[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glTexEnvfv((GLenum) arg0, (GLenum) arg1, (const GLfloat*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexEnviCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();


	glTexEnvi((GLenum) arg0, (GLenum) arg1, (GLint) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexEnvivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
 	GLint* arg2 = new	GLint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    

	glTexEnviv((GLenum) arg0, (GLenum) arg1, (const GLint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexGendCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	double arg2 = args[2]->NumberValue();


	glTexGend((GLenum) arg0, (GLenum) arg1, (GLdouble) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexGendvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLdouble* arg2 = new GLdouble[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glTexGendv((GLenum) arg0, (GLenum) arg1, (const GLdouble*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexGenfCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	double arg2 = args[2]->NumberValue();


	glTexGenf((GLenum) arg0, (GLenum) arg1, (GLfloat) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexGenfvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLfloat* arg2 = new	GLfloat[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glTexGenfv((GLenum) arg0, (GLenum) arg1, (const GLfloat*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexGeniCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();


	glTexGeni((GLenum) arg0, (GLenum) arg1, (GLint) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexGenivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
 	GLint* arg2 = new	GLint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    

	glTexGeniv((GLenum) arg0, (GLenum) arg1, (const GLint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexParameterfCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	double arg2 = args[2]->NumberValue();


	glTexParameterf((GLenum) arg0, (GLenum) arg1, (GLfloat) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexParameterfvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLfloat* arg2 = new	GLfloat[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glTexParameterfv((GLenum) arg0, (GLenum) arg1, (const GLfloat*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexParameteriCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();


	glTexParameteri((GLenum) arg0, (GLenum) arg1, (GLint) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTexParameterivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
 	GLint* arg2 = new	GLint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    

	glTexParameteriv((GLenum) arg0, (GLenum) arg1, (const GLint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTranslatedCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();


	glTranslated((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglTranslatefCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();


	glTranslatef((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertex2dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();


	glVertex2d((GLdouble) arg0, (GLdouble) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertex2dvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLdouble* arg0 = new GLdouble[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glVertex2dv((const GLdouble*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}

v8::Handle<v8::Value> GLglVertex2fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLfloat* arg0 = new	GLfloat[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glVertex2fv((const GLfloat*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}


v8::Handle<v8::Value> GLglVertex2ivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
 	GLint* arg0 = new	GLint[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glVertex2iv((const GLint*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertex2sCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();


	glVertex2s((GLshort) arg0, (GLshort) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertex2svCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLshort* arg0 = new GLshort[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLshort aux = ( GLshort)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glVertex2sv((const GLshort*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertex3dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();


	glVertex3d((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertex3dvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLdouble* arg0 = new GLdouble[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glVertex3dv((const GLdouble*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertex3fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();


	glVertex3f((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertex3fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLfloat* arg0 = new	GLfloat[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glVertex3fv((const GLfloat*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertex3iCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();


	glVertex3i((GLint) arg0, (GLint) arg1, (GLint) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertex3ivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
 	GLint* arg0 = new	GLint[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glVertex3iv((const GLint*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertex3sCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();


	glVertex3s((GLshort) arg0, (GLshort) arg1, (GLshort) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertex3svCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLshort* arg0 = new GLshort[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLshort aux = ( GLshort)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glVertex3sv((const GLshort*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertex4dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();
	double arg3 = args[3]->NumberValue();


	glVertex4d((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLdouble) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertex4dvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLdouble* arg0 = new GLdouble[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glVertex4dv((const GLdouble*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertex4fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();
	double arg3 = args[3]->NumberValue();


	glVertex4f((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLfloat) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertex4fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLfloat* arg0 = new	GLfloat[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glVertex4fv((const GLfloat*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertex4iCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();
	int arg3 = args[3]->IntegerValue();


	glVertex4i((GLint) arg0, (GLint) arg1, (GLint) arg2, (GLint) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertex4ivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
 	GLint* arg0 = new	GLint[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glVertex4iv((const GLint*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertex4sCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();
	int arg3 = args[3]->IntegerValue();


	glVertex4s((GLshort) arg0, (GLshort) arg1, (GLshort) arg2, (GLshort) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertex4svCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLshort* arg0 = new GLshort[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLshort aux = ( GLshort)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glVertex4sv((const GLshort*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglViewportCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();
	int arg3 = args[3]->IntegerValue();


	glViewport((GLint) arg0, (GLint) arg1, (GLsizei) arg2, (GLsizei) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglSampleCoverageCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	unsigned int arg1 = args[1]->Uint32Value();


	glSampleCoverage((GLclampf) arg0, (GLboolean) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglLoadTransposeMatrixfCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLfloat* arg0 = new	GLfloat[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glLoadTransposeMatrixf((const GLfloat*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglLoadTransposeMatrixdCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLdouble* arg0 = new GLdouble[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glLoadTransposeMatrixd((const GLdouble*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultTransposeMatrixfCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLfloat* arg0 = new	GLfloat[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glMultTransposeMatrixf((const GLfloat*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultTransposeMatrixdCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLdouble* arg0 = new GLdouble[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glMultTransposeMatrixd((const GLdouble*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglActiveTextureCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();


	glActiveTexture((GLenum) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglClientActiveTextureCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();


	glClientActiveTexture((GLenum) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord1dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	double arg1 = args[1]->NumberValue();


	glMultiTexCoord1d((GLenum) arg0, (GLdouble) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord1dvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLdouble* arg1 = new GLdouble[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg1[j] = aux; 
	}
    
    

	glMultiTexCoord1dv((GLenum) arg0, (const GLdouble*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord1fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	double arg1 = args[1]->NumberValue();


	glMultiTexCoord1f((GLenum) arg0, (GLfloat) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord1fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLfloat* arg1 = new	GLfloat[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg1[j] = aux; 
	}
    
    

	glMultiTexCoord1fv((GLenum) arg0, (const GLfloat*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord1iCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();


	glMultiTexCoord1i((GLenum) arg0, (GLint) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord1ivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
 	GLint* arg1 = new	GLint[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg1[j] = aux; 
	}
    
    

	glMultiTexCoord1iv((GLenum) arg0, (const GLint*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord1sCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();


	glMultiTexCoord1s((GLenum) arg0, (GLshort) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord1svCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLshort* arg1 = new GLshort[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLshort aux = ( GLshort)arg->IntegerValue();
		arg1[j] = aux; 
	}
    
    

	glMultiTexCoord1sv((GLenum) arg0, (const GLshort*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord2dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();


	glMultiTexCoord2d((GLenum) arg0, (GLdouble) arg1, (GLdouble) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord2dvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLdouble* arg1 = new GLdouble[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg1[j] = aux; 
	}
    
    

	glMultiTexCoord2dv((GLenum) arg0, (const GLdouble*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord2fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();


	glMultiTexCoord2f((GLenum) arg0, (GLfloat) arg1, (GLfloat) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord2fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLfloat* arg1 = new	GLfloat[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg1[j] = aux; 
	}
    
    

	glMultiTexCoord2fv((GLenum) arg0, (const GLfloat*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord2iCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();


	glMultiTexCoord2i((GLenum) arg0, (GLint) arg1, (GLint) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord2ivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
 	GLint* arg1 = new	GLint[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg1[j] = aux; 
	}
    
    

	glMultiTexCoord2iv((GLenum) arg0, (const GLint*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord2sCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();


	glMultiTexCoord2s((GLenum) arg0, (GLshort) arg1, (GLshort) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord2svCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLshort* arg1 = new GLshort[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLshort aux = ( GLshort)arg->IntegerValue();
		arg1[j] = aux; 
	}
    
    

	glMultiTexCoord2sv((GLenum) arg0, (const GLshort*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord3dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();
	double arg3 = args[3]->NumberValue();


	glMultiTexCoord3d((GLenum) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLdouble) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord3dvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLdouble* arg1 = new GLdouble[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg1[j] = aux; 
	}
    
    

	glMultiTexCoord3dv((GLenum) arg0, (const GLdouble*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord3fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();
	double arg3 = args[3]->NumberValue();


	glMultiTexCoord3f((GLenum) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLfloat) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord3fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLfloat* arg1 = new	GLfloat[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg1[j] = aux; 
	}
    
    

	glMultiTexCoord3fv((GLenum) arg0, (const GLfloat*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord3iCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();
	int arg3 = args[3]->IntegerValue();


	glMultiTexCoord3i((GLenum) arg0, (GLint) arg1, (GLint) arg2, (GLint) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord3ivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
 	GLint* arg1 = new	GLint[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg1[j] = aux; 
	}
    
    

	glMultiTexCoord3iv((GLenum) arg0, (const GLint*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord3sCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();
	int arg3 = args[3]->IntegerValue();


	glMultiTexCoord3s((GLenum) arg0, (GLshort) arg1, (GLshort) arg2, (GLshort) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord3svCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLshort* arg1 = new GLshort[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLshort aux = ( GLshort)arg->IntegerValue();
		arg1[j] = aux; 
	}
    
    

	glMultiTexCoord3sv((GLenum) arg0, (const GLshort*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord4dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 5) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();
	double arg3 = args[3]->NumberValue();
	double arg4 = args[4]->NumberValue();


	glMultiTexCoord4d((GLenum) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLdouble) arg3, (GLdouble) arg4);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord4dvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLdouble* arg1 = new GLdouble[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg1[j] = aux; 
	}
    
    

	glMultiTexCoord4dv((GLenum) arg0, (const GLdouble*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord4fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 5) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();
	double arg3 = args[3]->NumberValue();
	double arg4 = args[4]->NumberValue();


	glMultiTexCoord4f((GLenum) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLfloat) arg3, (GLfloat) arg4);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord4fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLfloat* arg1 = new	GLfloat[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg1[j] = aux; 
	}
    
    

	glMultiTexCoord4fv((GLenum) arg0, (const GLfloat*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord4ivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
 	GLint* arg1 = new	GLint[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg1[j] = aux; 
	}
    
    

	glMultiTexCoord4iv((GLenum) arg0, (const GLint*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord4sCallback(const v8::Arguments& args) {
	
	if (args.Length() < 5) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();
	int arg3 = args[3]->IntegerValue();
	int arg4 = args[4]->IntegerValue();


	glMultiTexCoord4s((GLenum) arg0, (GLshort) arg1, (GLshort) arg2, (GLshort) arg3, (GLshort) arg4);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiTexCoord4svCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLshort* arg1 = new GLshort[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLshort aux = ( GLshort)arg->IntegerValue();
		arg1[j] = aux; 
	}
    
    

	glMultiTexCoord4sv((GLenum) arg0, (const GLshort*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglFogCoordfCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	double arg0 = args[0]->NumberValue();


	glFogCoordf((GLfloat) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglFogCoordfvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLfloat* arg0 = new	GLfloat[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glFogCoordfv((const GLfloat*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglFogCoorddCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	double arg0 = args[0]->NumberValue();


	glFogCoordd((GLdouble) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglSecondaryColor3bCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();


	glSecondaryColor3b((GLbyte) arg0, (GLbyte) arg1, (GLbyte) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglSecondaryColor3bvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLbyte* arg0 = new GLbyte[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLbyte aux = ( GLbyte)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glSecondaryColor3bv((const GLbyte*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglSecondaryColor3dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();


	glSecondaryColor3d((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglSecondaryColor3dvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLdouble* arg0 = new GLdouble[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glSecondaryColor3dv((const GLdouble*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglSecondaryColor3fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();


	glSecondaryColor3f((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglSecondaryColor3fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLfloat* arg0 = new	GLfloat[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glSecondaryColor3fv((const GLfloat*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglSecondaryColor3iCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();


	glSecondaryColor3i((GLint) arg0, (GLint) arg1, (GLint) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglSecondaryColor3ivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
 	GLint* arg0 = new	GLint[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glSecondaryColor3iv((const GLint*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglSecondaryColor3sCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();


	glSecondaryColor3s((GLshort) arg0, (GLshort) arg1, (GLshort) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglSecondaryColor3svCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLshort* arg0 = new GLshort[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLshort aux = ( GLshort)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glSecondaryColor3sv((const GLshort*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglSecondaryColor3ubCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();
	unsigned int arg1 = args[1]->Uint32Value();
	unsigned int arg2 = args[2]->Uint32Value();


	glSecondaryColor3ub((GLubyte) arg0, (GLubyte) arg1, (GLubyte) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglSecondaryColor3ubvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLubyte* arg0 = new GLubyte[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLubyte aux = ( GLubyte)arg->Uint32Value();
		arg0[j] = aux; 
	}
    
    

	glSecondaryColor3ubv((const GLubyte*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglSecondaryColor3uiCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();
	unsigned int arg1 = args[1]->Uint32Value();
	unsigned int arg2 = args[2]->Uint32Value();


	glSecondaryColor3ui((GLuint) arg0, (GLuint) arg1, (GLuint) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglSecondaryColor3uivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
 	GLuint* arg0 = new	GLuint[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
 		GLuint aux = ( GLuint)arg->Uint32Value();
		arg0[j] = aux; 
	}
    
    

	glSecondaryColor3uiv((const GLuint*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglSecondaryColor3usCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();
	unsigned int arg1 = args[1]->Uint32Value();
	unsigned int arg2 = args[2]->Uint32Value();


	glSecondaryColor3us((GLushort) arg0, (GLushort) arg1, (GLushort) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglSecondaryColor3usvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLushort* arg0 = new GLushort[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLushort aux = ( GLushort)arg->Uint32Value();
		arg0[j] = aux; 
	}
    
    

	glSecondaryColor3usv((const GLushort*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglPointParameterfCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	double arg1 = args[1]->NumberValue();


	glPointParameterf((GLenum) arg0, (GLfloat) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglPointParameterfvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLfloat* arg1 = new GLfloat[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
   	GLfloat aux = (GLfloat)arg->NumberValue();
		arg1[j] = aux; 
	}
    
    

	glPointParameterfv((GLenum) arg0, (GLfloat*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglPointParameteriCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();


	glPointParameteri((GLenum) arg0, (GLint) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglPointParameterivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLint* arg1 = new GLint[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLint aux = (GLint)arg->IntegerValue();
		arg1[j] = aux; 
	}
    
    

	glPointParameteriv((GLenum) arg0, (GLint*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglBlendFuncSeparateCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();
	int arg3 = args[3]->IntegerValue();


	glBlendFuncSeparate((GLenum) arg0, (GLenum) arg1, (GLenum) arg2, (GLenum) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglMultiDrawArraysCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLint* arg1 = new GLint[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLint aux = (GLint)arg->IntegerValue();
		arg1[j] = aux; 
	}
    
    
    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLsizei* arg2 = new GLsizei[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLsizei aux = (GLsizei)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    	int arg3 = args[3]->IntegerValue();


	glMultiDrawArrays((GLenum) arg0, (GLint*) arg1, (GLsizei*) arg2, (GLsizei) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglWindowPos2dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();


	glWindowPos2d((GLdouble) arg0, (GLdouble) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglWindowPos2dvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLdouble* arg0 = new GLdouble[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glWindowPos2dv((const GLdouble*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglWindowPos2fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();


	glWindowPos2f((GLfloat) arg0, (GLfloat) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglWindowPos2fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLfloat* arg0 = new	GLfloat[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glWindowPos2fv((const GLfloat*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglWindowPos2iCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();


	glWindowPos2i((GLint) arg0, (GLint) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglWindowPos2ivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
 	GLint* arg0 = new	GLint[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glWindowPos2iv((const GLint*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglWindowPos2sCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();


	glWindowPos2s((GLshort) arg0, (GLshort) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglWindowPos2svCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLshort* arg0 = new GLshort[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLshort aux = ( GLshort)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glWindowPos2sv((const GLshort*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglWindowPos3dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();


	glWindowPos3d((GLdouble) arg0, (GLdouble) arg1, (GLdouble) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglWindowPos3dvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLdouble* arg0 = new GLdouble[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glWindowPos3dv((const GLdouble*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglWindowPos3fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	double arg0 = args[0]->NumberValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();


	glWindowPos3f((GLfloat) arg0, (GLfloat) arg1, (GLfloat) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglWindowPos3fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLfloat* arg0 = new	GLfloat[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg0[j] = aux; 
	}
    
    

	glWindowPos3fv((const GLfloat*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglWindowPos3iCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();


	glWindowPos3i((GLint) arg0, (GLint) arg1, (GLint) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglWindowPos3ivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
 	GLint* arg0 = new	GLint[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glWindowPos3iv((const GLint*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglWindowPos3sCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();


	glWindowPos3s((GLshort) arg0, (GLshort) arg1, (GLshort) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglWindowPos3svCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();


    
	v8::Handle<v8::Array> arrHandle0 = v8::Handle<v8::Array>::Cast(args[0]);
	GLshort* arg0 = new GLshort[arrHandle0->Length()];

	for (unsigned j = 0; j < arrHandle0->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle0->Get(v8::Integer::New(j)));
		GLshort aux = ( GLshort)arg->IntegerValue();
		arg0[j] = aux; 
	}
    
    

	glWindowPos3sv((const GLshort*) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGenQueriesCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLuint* arg1 = new GLuint[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLuint aux = (GLuint)arg->Uint32Value();
		arg1[j] = aux; 
	}
    
    

	glGenQueries((GLsizei) arg0, (GLuint*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}


v8::Handle<v8::Value> GLglIsQueryCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();


	return v8::Uint32::New(glIsQuery((GLuint) arg0));
}




v8::Handle<v8::Value> GLglBeginQueryCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	unsigned int arg1 = args[1]->Uint32Value();


	glBeginQuery((GLenum) arg0, (GLuint) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglEndQueryCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();


	glEndQuery((GLenum) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetQueryivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLint* arg2 = new GLint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLint aux = (GLint)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    

	glGetQueryiv((GLenum) arg0, (GLenum) arg1, (GLint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetQueryObjectivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLint* arg2 = new GLint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLint aux = (GLint)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    

	glGetQueryObjectiv((GLuint) arg0, (GLenum) arg1, (GLint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetQueryObjectuivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLuint* arg2 = new GLuint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLuint aux = (GLuint)arg->Uint32Value();
		arg2[j] = aux; 
	}
    
    

	glGetQueryObjectuiv((GLuint) arg0, (GLenum) arg1, (GLuint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglBindBufferCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	unsigned int arg1 = args[1]->Uint32Value();


	glBindBuffer((GLenum) arg0, (GLuint) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglDeleteBuffersCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
 	GLuint* arg1 = new	GLuint[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
 		GLuint aux = ( GLuint)arg->Uint32Value();
		arg1[j] = aux; 
	}
    
    

	glDeleteBuffers((GLsizei) arg0, (const GLuint*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGenBuffersCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLuint* arg1 = new GLuint[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLuint aux = (GLuint)arg->Uint32Value();
		arg1[j] = aux; 
	}
    
    

	glGenBuffers((GLsizei) arg0, (GLuint*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglIsBufferCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();


	return v8::Uint32::New(glIsBuffer((GLuint) arg0));
}




v8::Handle<v8::Value> GLglUnmapBufferCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();


	return v8::Uint32::New(glUnmapBuffer((GLenum) arg0));
}




v8::Handle<v8::Value> GLglGetBufferParameterivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLint* arg2 = new GLint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLint aux = (GLint)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    

	glGetBufferParameteriv((GLenum) arg0, (GLenum) arg1, (GLint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglDrawBuffersCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLenum* arg1 = new GLenum[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLenum aux = ( GLenum)arg->IntegerValue();
		arg1[j] = aux; 
	}
    
    

	glDrawBuffers((GLsizei) arg0, (const GLenum*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib1dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();
	double arg1 = args[1]->NumberValue();


	glVertexAttrib1d((GLuint) arg0, (GLdouble) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib1dvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLdouble* arg1 = new GLdouble[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg1[j] = aux; 
	}
    
    

	glVertexAttrib1dv((GLuint) arg0, (const GLdouble*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib1fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();
	double arg1 = args[1]->NumberValue();


	glVertexAttrib1f((GLuint) arg0, (GLfloat) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib1fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLfloat* arg1 = new	GLfloat[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg1[j] = aux; 
	}
    
    

	glVertexAttrib1fv((GLuint) arg0, (const GLfloat*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib1sCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();
	int arg1 = args[1]->IntegerValue();


	glVertexAttrib1s((GLuint) arg0, (GLshort) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib1svCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLshort* arg1 = new GLshort[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLshort aux = ( GLshort)arg->IntegerValue();
		arg1[j] = aux; 
	}
    
    

	glVertexAttrib1sv((GLuint) arg0, (const GLshort*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib2dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();


	glVertexAttrib2d((GLuint) arg0, (GLdouble) arg1, (GLdouble) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib2dvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLdouble* arg1 = new GLdouble[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg1[j] = aux; 
	}
    
    

	glVertexAttrib2dv((GLuint) arg0, (const GLdouble*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib2fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();


	glVertexAttrib2f((GLuint) arg0, (GLfloat) arg1, (GLfloat) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib2fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLfloat* arg1 = new	GLfloat[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg1[j] = aux; 
	}
    
    

	glVertexAttrib2fv((GLuint) arg0, (const GLfloat*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib2sCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();


	glVertexAttrib2s((GLuint) arg0, (GLshort) arg1, (GLshort) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib2svCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLshort* arg1 = new GLshort[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLshort aux = ( GLshort)arg->IntegerValue();
		arg1[j] = aux; 
	}
    
    

	glVertexAttrib2sv((GLuint) arg0, (const GLshort*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib3dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();
	double arg3 = args[3]->NumberValue();


	glVertexAttrib3d((GLuint) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLdouble) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib3dvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLdouble* arg1 = new GLdouble[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg1[j] = aux; 
	}
    
    

	glVertexAttrib3dv((GLuint) arg0, (const GLdouble*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib3fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();
	double arg3 = args[3]->NumberValue();


	glVertexAttrib3f((GLuint) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLfloat) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib3fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLfloat* arg1 = new	GLfloat[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg1[j] = aux; 
	}
    
    

	glVertexAttrib3fv((GLuint) arg0, (const GLfloat*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib3sCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();
	int arg3 = args[3]->IntegerValue();


	glVertexAttrib3s((GLuint) arg0, (GLshort) arg1, (GLshort) arg2, (GLshort) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib3svCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLshort* arg1 = new GLshort[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLshort aux = ( GLshort)arg->IntegerValue();
		arg1[j] = aux; 
	}
    
    

	glVertexAttrib3sv((GLuint) arg0, (const GLshort*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib4NbvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLbyte* arg1 = new GLbyte[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLbyte aux = (GLbyte)arg->IntegerValue();
		arg1[j] = aux; 
	}
    
    

	glVertexAttrib4Nbv((GLuint) arg0, (const GLbyte*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib4NivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
 	GLint* arg1 = new	GLint[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg1[j] = aux; 
	}
    
    

	glVertexAttrib4Niv((GLuint) arg0, (const GLint*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib4NsvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLshort* arg1 = new GLshort[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLshort aux = ( GLshort)arg->IntegerValue();
		arg1[j] = aux; 
	}
    
    

	glVertexAttrib4Nsv((GLuint) arg0, (const GLshort*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib4NubCallback(const v8::Arguments& args) {
	
	if (args.Length() < 5) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();
	unsigned int arg1 = args[1]->Uint32Value();
	unsigned int arg2 = args[2]->Uint32Value();
	unsigned int arg3 = args[3]->Uint32Value();
	unsigned int arg4 = args[4]->Uint32Value();


	glVertexAttrib4Nub((GLuint) arg0, (GLubyte) arg1, (GLubyte) arg2, (GLubyte) arg3, (GLubyte) arg4);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib4NubvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLubyte* arg1 = new GLubyte[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLubyte aux = ( GLubyte)arg->Uint32Value();
		arg1[j] = aux; 
	}
    
    

	glVertexAttrib4Nubv((GLuint) arg0, (const GLubyte*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib4NuivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
 	GLuint* arg1 = new	GLuint[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
 		GLuint aux = ( GLuint)arg->Uint32Value();
		arg1[j] = aux; 
	}
    
    

	glVertexAttrib4Nuiv((GLuint) arg0, (const GLuint*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib4NusvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLushort* arg1 = new GLushort[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLushort aux = ( GLushort)arg->Uint32Value();
		arg1[j] = aux; 
	}
    
    

	glVertexAttrib4Nusv((GLuint) arg0, (const GLushort*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib4bvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLbyte* arg1 = new GLbyte[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLbyte aux = ( GLbyte)arg->IntegerValue();
		arg1[j] = aux; 
	}
    
    

	glVertexAttrib4bv((GLuint) arg0, (const GLbyte*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib4dCallback(const v8::Arguments& args) {
	
	if (args.Length() < 5) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();
	double arg3 = args[3]->NumberValue();
	double arg4 = args[4]->NumberValue();


	glVertexAttrib4d((GLuint) arg0, (GLdouble) arg1, (GLdouble) arg2, (GLdouble) arg3, (GLdouble) arg4);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib4dvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLdouble* arg1 = new GLdouble[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLdouble aux = ( GLdouble)arg->NumberValue();
		arg1[j] = aux; 
	}
    
    

	glVertexAttrib4dv((GLuint) arg0, (const GLdouble*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib4fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 5) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();
	double arg3 = args[3]->NumberValue();
	double arg4 = args[4]->NumberValue();


	glVertexAttrib4f((GLuint) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLfloat) arg3, (GLfloat) arg4);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib4fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLfloat* arg1 = new	GLfloat[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg1[j] = aux; 
	}
    
    

	glVertexAttrib4fv((GLuint) arg0, (const GLfloat*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib4ivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
 	GLint* arg1 = new	GLint[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg1[j] = aux; 
	}
    
    

	glVertexAttrib4iv((GLuint) arg0, (const GLint*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib4sCallback(const v8::Arguments& args) {
	
	if (args.Length() < 5) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();
	int arg3 = args[3]->IntegerValue();
	int arg4 = args[4]->IntegerValue();


	glVertexAttrib4s((GLuint) arg0, (GLshort) arg1, (GLshort) arg2, (GLshort) arg3, (GLshort) arg4);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib4svCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLshort* arg1 = new GLshort[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLshort aux = ( GLshort)arg->IntegerValue();
		arg1[j] = aux; 
	}
    
    

	glVertexAttrib4sv((GLuint) arg0, (const GLshort*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib4ubvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLubyte* arg1 = new GLubyte[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLubyte aux = ( GLubyte)arg->Uint32Value();
		arg1[j] = aux; 
	}
    
    

	glVertexAttrib4ubv((GLuint) arg0, (const GLubyte*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib4uivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
 	GLuint* arg1 = new	GLuint[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
 		GLuint aux = ( GLuint)arg->Uint32Value();
		arg1[j] = aux; 
	}
    
    

	glVertexAttrib4uiv((GLuint) arg0, (const GLuint*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglVertexAttrib4usvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle1 = v8::Handle<v8::Array>::Cast(args[1]);
	GLushort* arg1 = new GLushort[arrHandle1->Length()];

	for (unsigned j = 0; j < arrHandle1->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle1->Get(v8::Integer::New(j)));
		GLushort aux = ( GLushort)arg->Uint32Value();
		arg1[j] = aux; 
	}
    
    

	glVertexAttrib4usv((GLuint) arg0, (const GLushort*) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglEnableVertexAttribArrayCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();


	glEnableVertexAttribArray((GLuint) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglDisableVertexAttribArrayCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();


	glDisableVertexAttribArray((GLuint) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetVertexAttribdvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
  GLdouble* arg2 = new GLdouble[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
   	GLdouble aux = (GLdouble)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glGetVertexAttribdv((GLuint) arg0, (GLenum) arg1, (GLdouble*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetVertexAttribfvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLfloat* arg2 = new GLfloat[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
   	GLfloat aux = (GLfloat)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glGetVertexAttribfv((GLuint) arg0, (GLenum) arg1, (GLfloat*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetVertexAttribivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLint* arg2 = new GLint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLint aux = (GLint)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    

	glGetVertexAttribiv((GLuint) arg0, (GLenum) arg1, (GLint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}


v8::Handle<v8::Value> GLglLinkProgramCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();


	glLinkProgram((GLuint) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglUseProgramCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();


	glUseProgram((GLuint) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}


v8::Handle<v8::Value> GLglValidateProgramCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();


	glValidateProgram((GLuint) arg0);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglUniform1fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	double arg1 = args[1]->NumberValue();


	glUniform1f((GLint) arg0, (GLfloat) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglUniform2fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();


	glUniform2f((GLint) arg0, (GLfloat) arg1, (GLfloat) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglUniform3fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();
	double arg3 = args[3]->NumberValue();


	glUniform3f((GLint) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLfloat) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglUniform4fCallback(const v8::Arguments& args) {
	
	if (args.Length() < 5) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	double arg1 = args[1]->NumberValue();
	double arg2 = args[2]->NumberValue();
	double arg3 = args[3]->NumberValue();
	double arg4 = args[4]->NumberValue();


	glUniform4f((GLint) arg0, (GLfloat) arg1, (GLfloat) arg2, (GLfloat) arg3, (GLfloat) arg4);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglUniform1iCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();


	glUniform1i((GLint) arg0, (GLint) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglUniform2iCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();


	glUniform2i((GLint) arg0, (GLint) arg1, (GLint) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglUniform3iCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();
	int arg3 = args[3]->IntegerValue();


	glUniform3i((GLint) arg0, (GLint) arg1, (GLint) arg2, (GLint) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglUniform4iCallback(const v8::Arguments& args) {
	
	if (args.Length() < 5) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();
	int arg3 = args[3]->IntegerValue();
	int arg4 = args[4]->IntegerValue();


	glUniform4i((GLint) arg0, (GLint) arg1, (GLint) arg2, (GLint) arg3, (GLint) arg4);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglUniform1fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLfloat* arg2 = new	GLfloat[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glUniform1fv((GLint) arg0, (GLsizei) arg1, (const GLfloat*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglUniform2fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLfloat* arg2 = new	GLfloat[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glUniform2fv((GLint) arg0, (GLsizei) arg1, (const GLfloat*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglUniform3fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLfloat* arg2 = new	GLfloat[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glUniform3fv((GLint) arg0, (GLsizei) arg1, (const GLfloat*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglUniform4fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLfloat* arg2 = new	GLfloat[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glUniform4fv((GLint) arg0, (GLsizei) arg1, (const GLfloat*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglUniform1ivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
 	GLint* arg2 = new	GLint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    

	glUniform1iv((GLint) arg0, (GLsizei) arg1, (const GLint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglUniform2ivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
 	GLint* arg2 = new	GLint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    

	glUniform2iv((GLint) arg0, (GLsizei) arg1, (const GLint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglUniform3ivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
 	GLint* arg2 = new	GLint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    

	glUniform3iv((GLint) arg0, (GLsizei) arg1, (const GLint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglUniform4ivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
 	GLint* arg2 = new	GLint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
 		GLint aux = ( GLint)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    

	glUniform4iv((GLint) arg0, (GLsizei) arg1, (const GLint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglUniformMatrix2fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	unsigned int arg2 = args[2]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle3 = v8::Handle<v8::Array>::Cast(args[3]);
	GLfloat* arg3 = new	GLfloat[arrHandle3->Length()];

	for (unsigned j = 0; j < arrHandle3->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle3->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg3[j] = aux; 
	}
    
    

	glUniformMatrix2fv((GLint) arg0, (GLsizei) arg1, (GLboolean) arg2, (const GLfloat*) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglUniformMatrix3fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	unsigned int arg2 = args[2]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle3 = v8::Handle<v8::Array>::Cast(args[3]);
	GLfloat* arg3 = new	GLfloat[arrHandle3->Length()];

	for (unsigned j = 0; j < arrHandle3->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle3->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg3[j] = aux; 
	}
    
    

	glUniformMatrix3fv((GLint) arg0, (GLsizei) arg1, (GLboolean) arg2, (const GLfloat*) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglUniformMatrix4fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	unsigned int arg2 = args[2]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle3 = v8::Handle<v8::Array>::Cast(args[3]);
	GLfloat* arg3 = new	GLfloat[arrHandle3->Length()];

	for (unsigned j = 0; j < arrHandle3->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle3->Get(v8::Integer::New(j)));
		GLfloat aux = ( GLfloat)arg->NumberValue();
		arg3[j] = aux; 
	}
    
    

	glUniformMatrix4fv((GLint) arg0, (GLsizei) arg1, (GLboolean) arg2, (const GLfloat*) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglIsShaderCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();


	return v8::Uint32::New(glIsShader((GLuint) arg0));
}




v8::Handle<v8::Value> GLglIsProgramCallback(const v8::Arguments& args) {
	
	if (args.Length() < 1) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();


	return v8::Uint32::New(glIsProgram((GLuint) arg0));
}




v8::Handle<v8::Value> GLglGetShaderivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLint* arg2 = new GLint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLint aux = (GLint)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    

	glGetShaderiv((GLuint) arg0, (GLenum) arg1, (GLint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetProgramivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLint* arg2 = new GLint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLint aux = (GLint)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    

	glGetProgramiv((GLuint) arg0, (GLenum) arg1, (GLint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetAttachedShadersCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLsizei* arg2 = new GLsizei[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLsizei aux = (GLsizei)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    
    
	v8::Handle<v8::Array> arrHandle3 = v8::Handle<v8::Array>::Cast(args[3]);
	GLuint* arg3 = new GLuint[arrHandle3->Length()];

	for (unsigned j = 0; j < arrHandle3->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle3->Get(v8::Integer::New(j)));
		GLuint aux = (GLuint)arg->Uint32Value();
		arg3[j] = aux; 
	}
    
    

	glGetAttachedShaders((GLuint) arg0, (GLsizei) arg1, (GLsizei*) arg2, (GLuint*) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetUniformfvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLfloat* arg2 = new GLfloat[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
   	GLfloat aux = (GLfloat)arg->NumberValue();
		arg2[j] = aux; 
	}
    
    

	glGetUniformfv((GLuint) arg0, (GLint) arg1, (GLfloat*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglGetUniformivCallback(const v8::Arguments& args) {
	
	if (args.Length() < 3) return v8::Undefined();

	unsigned int arg0 = args[0]->Uint32Value();
	int arg1 = args[1]->IntegerValue();

    
	v8::Handle<v8::Array> arrHandle2 = v8::Handle<v8::Array>::Cast(args[2]);
	GLint* arg2 = new GLint[arrHandle2->Length()];

	for (unsigned j = 0; j < arrHandle2->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle2->Get(v8::Integer::New(j)));
		GLint aux = (GLint)arg->IntegerValue();
		arg2[j] = aux; 
	}
    
    

	glGetUniformiv((GLuint) arg0, (GLint) arg1, (GLint*) arg2);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglStencilFuncSeparateCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();
	unsigned int arg3 = args[3]->Uint32Value();


	glStencilFuncSeparate((GLenum) arg0, (GLenum) arg1, (GLint) arg2, (GLuint) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglStencilOpSeparateCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	int arg2 = args[2]->IntegerValue();
	int arg3 = args[3]->IntegerValue();


	glStencilOpSeparate((GLenum) arg0, (GLenum) arg1, (GLenum) arg2, (GLenum) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglStencilMaskSeparateCallback(const v8::Arguments& args) {
	
	if (args.Length() < 2) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	unsigned int arg1 = args[1]->Uint32Value();


	glStencilMaskSeparate((GLenum) arg0, (GLuint) arg1);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglUniformMatrix2x3fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	unsigned int arg2 = args[2]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle3 = v8::Handle<v8::Array>::Cast(args[3]);
	GLfloat* arg3 = new	GLfloat[arrHandle3->Length()];

	for (unsigned j = 0; j < arrHandle3->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle3->Get(v8::Integer::New(j)));
		GLfloat aux = (GLfloat)arg->NumberValue();
		arg3[j] = aux; 
	}
    
    

	glUniformMatrix2x3fv((GLint) arg0, (GLsizei) arg1, (GLboolean) arg2, (const GLfloat*) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglUniformMatrix3x2fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	unsigned int arg2 = args[2]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle3 = v8::Handle<v8::Array>::Cast(args[3]);
	GLfloat* arg3 = new	GLfloat[arrHandle3->Length()];

	for (unsigned j = 0; j < arrHandle3->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle3->Get(v8::Integer::New(j)));
		GLfloat aux = (GLfloat)arg->NumberValue();
		arg3[j] = aux; 
	}
    
    

	glUniformMatrix3x2fv((GLint) arg0, (GLsizei) arg1, (GLboolean) arg2, (const GLfloat*) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglUniformMatrix2x4fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	unsigned int arg2 = args[2]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle3 = v8::Handle<v8::Array>::Cast(args[3]);
	GLfloat* arg3 = new	GLfloat[arrHandle3->Length()];

	for (unsigned j = 0; j < arrHandle3->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle3->Get(v8::Integer::New(j)));
		GLfloat aux = (GLfloat)arg->NumberValue();
		arg3[j] = aux; 
	}
    
    

	glUniformMatrix2x4fv((GLint) arg0, (GLsizei) arg1, (GLboolean) arg2, (const GLfloat*) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglUniformMatrix4x2fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	unsigned int arg2 = args[2]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle3 = v8::Handle<v8::Array>::Cast(args[3]);
	GLfloat* arg3 = new	GLfloat[arrHandle3->Length()];

	for (unsigned j = 0; j < arrHandle3->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle3->Get(v8::Integer::New(j)));
		GLfloat aux = (GLfloat)arg->NumberValue();
		arg3[j] = aux; 
	}
    
    

	glUniformMatrix4x2fv((GLint) arg0, (GLsizei) arg1, (GLboolean) arg2, (const GLfloat*) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglUniformMatrix3x4fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	unsigned int arg2 = args[2]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle3 = v8::Handle<v8::Array>::Cast(args[3]);
	GLfloat* arg3 = new	GLfloat[arrHandle3->Length()];

	for (unsigned j = 0; j < arrHandle3->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle3->Get(v8::Integer::New(j)));
		GLfloat aux = (GLfloat)arg->NumberValue();
		arg3[j] = aux; 
	}
    
    

	glUniformMatrix3x4fv((GLint) arg0, (GLsizei) arg1, (GLboolean) arg2, (const GLfloat*) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::Value> GLglUniformMatrix4x3fvCallback(const v8::Arguments& args) {
	
	if (args.Length() < 4) return v8::Undefined();

	int arg0 = args[0]->IntegerValue();
	int arg1 = args[1]->IntegerValue();
	unsigned int arg2 = args[2]->Uint32Value();

    
	v8::Handle<v8::Array> arrHandle3 = v8::Handle<v8::Array>::Cast(args[3]);
	GLfloat* arg3 = new	GLfloat[arrHandle3->Length()];

	for (unsigned j = 0; j < arrHandle3->Length(); j++) {
		v8::Handle<v8::Value> arg(arrHandle3->Get(v8::Integer::New(j)));
		GLfloat aux = (GLfloat)arg->NumberValue();
		arg3[j] = aux; 
	}
    
    

	glUniformMatrix4x3fv((GLint) arg0, (GLsizei) arg1, (GLboolean) arg2, (const GLfloat*) arg3);
	v8::Handle<v8::Object> res(GlFactory::self_);

	return res;
}




v8::Handle<v8::ObjectTemplate> GlFactory::createGl(void) {

	v8::HandleScope scope;

	v8::Handle<v8::ObjectTemplate> Gl = v8::ObjectTemplate::New();
      
	Gl->SetInternalFieldCount(1);
	Gl->Set(v8::String::NewSymbol("LOGIC_OP"), v8::Uint32::New(GL_LOGIC_OP), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_COMPONENTS"), v8::Uint32::New(GL_TEXTURE_COMPONENTS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VERSION_1_1"), v8::Uint32::New(GL_VERSION_1_1), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VERSION_1_2"), v8::Uint32::New(GL_VERSION_1_2), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VERSION_1_3"), v8::Uint32::New(GL_VERSION_1_3), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VERSION_1_4"), v8::Uint32::New(GL_VERSION_1_4), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VERSION_1_5"), v8::Uint32::New(GL_VERSION_1_5), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VERSION_2_0"), v8::Uint32::New(GL_VERSION_2_0), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VERSION_2_1"), v8::Uint32::New(GL_VERSION_2_1), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ACCUM"), v8::Uint32::New(GL_ACCUM), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LOAD"), v8::Uint32::New(GL_LOAD), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("RETURN"), v8::Uint32::New(GL_RETURN), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MULT"), v8::Uint32::New(GL_MULT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ADD"), v8::Uint32::New(GL_ADD), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("NEVER"), v8::Uint32::New(GL_NEVER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LESS"), v8::Uint32::New(GL_LESS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("EQUAL"), v8::Uint32::New(GL_EQUAL), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LEQUAL"), v8::Uint32::New(GL_LEQUAL), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("GREATER"), v8::Uint32::New(GL_GREATER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("NOTEQUAL"), v8::Uint32::New(GL_NOTEQUAL), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("GEQUAL"), v8::Uint32::New(GL_GEQUAL), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ALWAYS"), v8::Uint32::New(GL_ALWAYS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CURRENT_BIT"), v8::Uint32::New(GL_CURRENT_BIT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POINT_BIT"), v8::Uint32::New(GL_POINT_BIT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LINE_BIT"), v8::Uint32::New(GL_LINE_BIT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POLYGON_BIT"), v8::Uint32::New(GL_POLYGON_BIT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POLYGON_STIPPLE_BIT"), v8::Uint32::New(GL_POLYGON_STIPPLE_BIT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PIXEL_MODE_BIT"), v8::Uint32::New(GL_PIXEL_MODE_BIT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LIGHTING_BIT"), v8::Uint32::New(GL_LIGHTING_BIT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FOG_BIT"), v8::Uint32::New(GL_FOG_BIT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DEPTH_BUFFER_BIT"), v8::Uint32::New(GL_DEPTH_BUFFER_BIT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ACCUM_BUFFER_BIT"), v8::Uint32::New(GL_ACCUM_BUFFER_BIT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("STENCIL_BUFFER_BIT"), v8::Uint32::New(GL_STENCIL_BUFFER_BIT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VIEWPORT_BIT"), v8::Uint32::New(GL_VIEWPORT_BIT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TRANSFORM_BIT"), v8::Uint32::New(GL_TRANSFORM_BIT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ENABLE_BIT"), v8::Uint32::New(GL_ENABLE_BIT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_BUFFER_BIT"), v8::Uint32::New(GL_COLOR_BUFFER_BIT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("HINT_BIT"), v8::Uint32::New(GL_HINT_BIT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("EVAL_BIT"), v8::Uint32::New(GL_EVAL_BIT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LIST_BIT"), v8::Uint32::New(GL_LIST_BIT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_BIT"), v8::Uint32::New(GL_TEXTURE_BIT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SCISSOR_BIT"), v8::Uint32::New(GL_SCISSOR_BIT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ALL_ATTRIB_BITS"), v8::Uint32::New(GL_ALL_ATTRIB_BITS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POINTS"), v8::Uint32::New(GL_POINTS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LINES"), v8::Uint32::New(GL_LINES), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LINE_LOOP"), v8::Uint32::New(GL_LINE_LOOP), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LINE_STRIP"), v8::Uint32::New(GL_LINE_STRIP), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TRIANGLES"), v8::Uint32::New(GL_TRIANGLES), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TRIANGLE_STRIP"), v8::Uint32::New(GL_TRIANGLE_STRIP), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TRIANGLE_FAN"), v8::Uint32::New(GL_TRIANGLE_FAN), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("QUADS"), v8::Uint32::New(GL_QUADS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("QUAD_STRIP"), v8::Uint32::New(GL_QUAD_STRIP), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POLYGON"), v8::Uint32::New(GL_POLYGON), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ZERO"), v8::Uint32::New(GL_ZERO), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ONE"), v8::Uint32::New(GL_ONE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SRC_COLOR"), v8::Uint32::New(GL_SRC_COLOR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ONE_MINUS_SRC_COLOR"), v8::Uint32::New(GL_ONE_MINUS_SRC_COLOR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SRC_ALPHA"), v8::Uint32::New(GL_SRC_ALPHA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ONE_MINUS_SRC_ALPHA"), v8::Uint32::New(GL_ONE_MINUS_SRC_ALPHA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DST_ALPHA"), v8::Uint32::New(GL_DST_ALPHA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ONE_MINUS_DST_ALPHA"), v8::Uint32::New(GL_ONE_MINUS_DST_ALPHA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DST_COLOR"), v8::Uint32::New(GL_DST_COLOR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ONE_MINUS_DST_COLOR"), v8::Uint32::New(GL_ONE_MINUS_DST_COLOR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SRC_ALPHA_SATURATE"), v8::Uint32::New(GL_SRC_ALPHA_SATURATE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TRUE"), v8::Uint32::New(GL_TRUE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FALSE"), v8::Uint32::New(GL_FALSE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CLIP_PLANE0"), v8::Uint32::New(GL_CLIP_PLANE0), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CLIP_PLANE1"), v8::Uint32::New(GL_CLIP_PLANE1), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CLIP_PLANE2"), v8::Uint32::New(GL_CLIP_PLANE2), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CLIP_PLANE3"), v8::Uint32::New(GL_CLIP_PLANE3), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CLIP_PLANE4"), v8::Uint32::New(GL_CLIP_PLANE4), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CLIP_PLANE5"), v8::Uint32::New(GL_CLIP_PLANE5), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BYTE"), v8::Uint32::New(GL_BYTE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("UNSIGNED_BYTE"), v8::Uint32::New(GL_UNSIGNED_BYTE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SHORT"), v8::Uint32::New(GL_SHORT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("UNSIGNED_SHORT"), v8::Uint32::New(GL_UNSIGNED_SHORT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INT"), v8::Uint32::New(GL_INT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("UNSIGNED_INT"), v8::Uint32::New(GL_UNSIGNED_INT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FLOAT"), v8::Uint32::New(GL_FLOAT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("2_BYTES"), v8::Uint32::New(GL_2_BYTES), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("3_BYTES"), v8::Uint32::New(GL_3_BYTES), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("4_BYTES"), v8::Uint32::New(GL_4_BYTES), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DOUBLE"), v8::Uint32::New(GL_DOUBLE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("NONE"), v8::Uint32::New(GL_NONE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FRONT_LEFT"), v8::Uint32::New(GL_FRONT_LEFT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FRONT_RIGHT"), v8::Uint32::New(GL_FRONT_RIGHT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BACK_LEFT"), v8::Uint32::New(GL_BACK_LEFT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BACK_RIGHT"), v8::Uint32::New(GL_BACK_RIGHT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FRONT"), v8::Uint32::New(GL_FRONT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BACK"), v8::Uint32::New(GL_BACK), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LEFT"), v8::Uint32::New(GL_LEFT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("RIGHT"), v8::Uint32::New(GL_RIGHT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FRONT_AND_BACK"), v8::Uint32::New(GL_FRONT_AND_BACK), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("AUX0"), v8::Uint32::New(GL_AUX0), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("AUX1"), v8::Uint32::New(GL_AUX1), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("AUX2"), v8::Uint32::New(GL_AUX2), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("AUX3"), v8::Uint32::New(GL_AUX3), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("NO_ERROR"), v8::Uint32::New(GL_NO_ERROR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INVALID_ENUM"), v8::Uint32::New(GL_INVALID_ENUM), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INVALID_VALUE"), v8::Uint32::New(GL_INVALID_VALUE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("STACK_OVERFLOW"), v8::Uint32::New(GL_STACK_OVERFLOW), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("STACK_UNDERFLOW"), v8::Uint32::New(GL_STACK_UNDERFLOW), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("OUT_OF_MEMORY"), v8::Uint32::New(GL_OUT_OF_MEMORY), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("2D"), v8::Uint32::New(GL_2D), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("3D"), v8::Uint32::New(GL_3D), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("3D_COLOR"), v8::Uint32::New(GL_3D_COLOR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("3D_COLOR_TEXTURE"), v8::Uint32::New(GL_3D_COLOR_TEXTURE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("4D_COLOR_TEXTURE"), v8::Uint32::New(GL_4D_COLOR_TEXTURE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PASS_THROUGH_TOKEN"), v8::Uint32::New(GL_PASS_THROUGH_TOKEN), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POINT_TOKEN"), v8::Uint32::New(GL_POINT_TOKEN), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LINE_TOKEN"), v8::Uint32::New(GL_LINE_TOKEN), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POLYGON_TOKEN"), v8::Uint32::New(GL_POLYGON_TOKEN), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BITMAP_TOKEN"), v8::Uint32::New(GL_BITMAP_TOKEN), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DRAW_PIXEL_TOKEN"), v8::Uint32::New(GL_DRAW_PIXEL_TOKEN), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COPY_PIXEL_TOKEN"), v8::Uint32::New(GL_COPY_PIXEL_TOKEN), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LINE_RESET_TOKEN"), v8::Uint32::New(GL_LINE_RESET_TOKEN), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("EXP"), v8::Uint32::New(GL_EXP), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("EXP2"), v8::Uint32::New(GL_EXP2), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CW"), v8::Uint32::New(GL_CW), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CCW"), v8::Uint32::New(GL_CCW), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COEFF"), v8::Uint32::New(GL_COEFF), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ORDER"), v8::Uint32::New(GL_ORDER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DOMAIN"), v8::Uint32::New(GL_DOMAIN), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CURRENT_COLOR"), v8::Uint32::New(GL_CURRENT_COLOR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CURRENT_INDEX"), v8::Uint32::New(GL_CURRENT_INDEX), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CURRENT_NORMAL"), v8::Uint32::New(GL_CURRENT_NORMAL), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CURRENT_TEXTURE_COORDS"), v8::Uint32::New(GL_CURRENT_TEXTURE_COORDS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CURRENT_RASTER_COLOR"), v8::Uint32::New(GL_CURRENT_RASTER_COLOR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CURRENT_RASTER_INDEX"), v8::Uint32::New(GL_CURRENT_RASTER_INDEX), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CURRENT_RASTER_TEXTURE_COORDS"), v8::Uint32::New(GL_CURRENT_RASTER_TEXTURE_COORDS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CURRENT_RASTER_POSITION"), v8::Uint32::New(GL_CURRENT_RASTER_POSITION), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CURRENT_RASTER_POSITION_VALID"), v8::Uint32::New(GL_CURRENT_RASTER_POSITION_VALID), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CURRENT_RASTER_DISTANCE"), v8::Uint32::New(GL_CURRENT_RASTER_DISTANCE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POINT_SMOOTH"), v8::Uint32::New(GL_POINT_SMOOTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POINT_SIZE"), v8::Uint32::New(GL_POINT_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POINT_SIZE_RANGE"), v8::Uint32::New(GL_POINT_SIZE_RANGE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POINT_SIZE_GRANULARITY"), v8::Uint32::New(GL_POINT_SIZE_GRANULARITY), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LINE_SMOOTH"), v8::Uint32::New(GL_LINE_SMOOTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LINE_WIDTH"), v8::Uint32::New(GL_LINE_WIDTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LINE_WIDTH_RANGE"), v8::Uint32::New(GL_LINE_WIDTH_RANGE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LINE_WIDTH_GRANULARITY"), v8::Uint32::New(GL_LINE_WIDTH_GRANULARITY), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LINE_STIPPLE"), v8::Uint32::New(GL_LINE_STIPPLE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LINE_STIPPLE_PATTERN"), v8::Uint32::New(GL_LINE_STIPPLE_PATTERN), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LINE_STIPPLE_REPEAT"), v8::Uint32::New(GL_LINE_STIPPLE_REPEAT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LIST_MODE"), v8::Uint32::New(GL_LIST_MODE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_LIST_NESTING"), v8::Uint32::New(GL_MAX_LIST_NESTING), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LIST_BASE"), v8::Uint32::New(GL_LIST_BASE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LIST_INDEX"), v8::Uint32::New(GL_LIST_INDEX), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POLYGON_MODE"), v8::Uint32::New(GL_POLYGON_MODE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POLYGON_SMOOTH"), v8::Uint32::New(GL_POLYGON_SMOOTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POLYGON_STIPPLE"), v8::Uint32::New(GL_POLYGON_STIPPLE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("EDGE_FLAG"), v8::Uint32::New(GL_EDGE_FLAG), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CULL_FACE"), v8::Uint32::New(GL_CULL_FACE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CULL_FACE_MODE"), v8::Uint32::New(GL_CULL_FACE_MODE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FRONT_FACE"), v8::Uint32::New(GL_FRONT_FACE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LIGHTING"), v8::Uint32::New(GL_LIGHTING), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LIGHT_MODEL_LOCAL_VIEWER"), v8::Uint32::New(GL_LIGHT_MODEL_LOCAL_VIEWER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LIGHT_MODEL_TWO_SIDE"), v8::Uint32::New(GL_LIGHT_MODEL_TWO_SIDE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LIGHT_MODEL_AMBIENT"), v8::Uint32::New(GL_LIGHT_MODEL_AMBIENT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SHADE_MODEL"), v8::Uint32::New(GL_SHADE_MODEL), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_MATERIAL_FACE"), v8::Uint32::New(GL_COLOR_MATERIAL_FACE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_MATERIAL_PARAMETER"), v8::Uint32::New(GL_COLOR_MATERIAL_PARAMETER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_MATERIAL"), v8::Uint32::New(GL_COLOR_MATERIAL), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FOG"), v8::Uint32::New(GL_FOG), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FOG_INDEX"), v8::Uint32::New(GL_FOG_INDEX), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FOG_DENSITY"), v8::Uint32::New(GL_FOG_DENSITY), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FOG_START"), v8::Uint32::New(GL_FOG_START), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FOG_END"), v8::Uint32::New(GL_FOG_END), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FOG_MODE"), v8::Uint32::New(GL_FOG_MODE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FOG_COLOR"), v8::Uint32::New(GL_FOG_COLOR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DEPTH_RANGE"), v8::Uint32::New(GL_DEPTH_RANGE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DEPTH_TEST"), v8::Uint32::New(GL_DEPTH_TEST), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DEPTH_WRITEMASK"), v8::Uint32::New(GL_DEPTH_WRITEMASK), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DEPTH_CLEAR_VALUE"), v8::Uint32::New(GL_DEPTH_CLEAR_VALUE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DEPTH_FUNC"), v8::Uint32::New(GL_DEPTH_FUNC), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ACCUM_CLEAR_VALUE"), v8::Uint32::New(GL_ACCUM_CLEAR_VALUE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("STENCIL_TEST"), v8::Uint32::New(GL_STENCIL_TEST), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("STENCIL_CLEAR_VALUE"), v8::Uint32::New(GL_STENCIL_CLEAR_VALUE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("STENCIL_FUNC"), v8::Uint32::New(GL_STENCIL_FUNC), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("STENCIL_VALUE_MASK"), v8::Uint32::New(GL_STENCIL_VALUE_MASK), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("STENCIL_FAIL"), v8::Uint32::New(GL_STENCIL_FAIL), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("STENCIL_PASS_DEPTH_FAIL"), v8::Uint32::New(GL_STENCIL_PASS_DEPTH_FAIL), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("STENCIL_PASS_DEPTH_PASS"), v8::Uint32::New(GL_STENCIL_PASS_DEPTH_PASS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("STENCIL_REF"), v8::Uint32::New(GL_STENCIL_REF), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("STENCIL_WRITEMASK"), v8::Uint32::New(GL_STENCIL_WRITEMASK), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MATRIX_MODE"), v8::Uint32::New(GL_MATRIX_MODE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("NORMALIZE"), v8::Uint32::New(GL_NORMALIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VIEWPORT"), v8::Uint32::New(GL_VIEWPORT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MODELVIEW_STACK_DEPTH"), v8::Uint32::New(GL_MODELVIEW_STACK_DEPTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PROJECTION_STACK_DEPTH"), v8::Uint32::New(GL_PROJECTION_STACK_DEPTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_STACK_DEPTH"), v8::Uint32::New(GL_TEXTURE_STACK_DEPTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MODELVIEW_MATRIX"), v8::Uint32::New(GL_MODELVIEW_MATRIX), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PROJECTION_MATRIX"), v8::Uint32::New(GL_PROJECTION_MATRIX), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_MATRIX"), v8::Uint32::New(GL_TEXTURE_MATRIX), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ATTRIB_STACK_DEPTH"), v8::Uint32::New(GL_ATTRIB_STACK_DEPTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CLIENT_ATTRIB_STACK_DEPTH"), v8::Uint32::New(GL_CLIENT_ATTRIB_STACK_DEPTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ALPHA_TEST"), v8::Uint32::New(GL_ALPHA_TEST), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ALPHA_TEST_FUNC"), v8::Uint32::New(GL_ALPHA_TEST_FUNC), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ALPHA_TEST_REF"), v8::Uint32::New(GL_ALPHA_TEST_REF), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DITHER"), v8::Uint32::New(GL_DITHER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BLEND_DST"), v8::Uint32::New(GL_BLEND_DST), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BLEND_SRC"), v8::Uint32::New(GL_BLEND_SRC), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BLEND"), v8::Uint32::New(GL_BLEND), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LOGIC_OP_MODE"), v8::Uint32::New(GL_LOGIC_OP_MODE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INDEX_LOGIC_OP"), v8::Uint32::New(GL_INDEX_LOGIC_OP), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_LOGIC_OP"), v8::Uint32::New(GL_COLOR_LOGIC_OP), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("AUX_BUFFERS"), v8::Uint32::New(GL_AUX_BUFFERS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DRAW_BUFFER"), v8::Uint32::New(GL_DRAW_BUFFER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("READ_BUFFER"), v8::Uint32::New(GL_READ_BUFFER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SCISSOR_BOX"), v8::Uint32::New(GL_SCISSOR_BOX), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SCISSOR_TEST"), v8::Uint32::New(GL_SCISSOR_TEST), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INDEX_CLEAR_VALUE"), v8::Uint32::New(GL_INDEX_CLEAR_VALUE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INDEX_WRITEMASK"), v8::Uint32::New(GL_INDEX_WRITEMASK), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_CLEAR_VALUE"), v8::Uint32::New(GL_COLOR_CLEAR_VALUE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_WRITEMASK"), v8::Uint32::New(GL_COLOR_WRITEMASK), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INDEX_MODE"), v8::Uint32::New(GL_INDEX_MODE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("RGBA_MODE"), v8::Uint32::New(GL_RGBA_MODE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DOUBLEBUFFER"), v8::Uint32::New(GL_DOUBLEBUFFER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("STEREO"), v8::Uint32::New(GL_STEREO), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("RENDER_MODE"), v8::Uint32::New(GL_RENDER_MODE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PERSPECTIVE_CORRECTION_HINT"), v8::Uint32::New(GL_PERSPECTIVE_CORRECTION_HINT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POINT_SMOOTH_HINT"), v8::Uint32::New(GL_POINT_SMOOTH_HINT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LINE_SMOOTH_HINT"), v8::Uint32::New(GL_LINE_SMOOTH_HINT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POLYGON_SMOOTH_HINT"), v8::Uint32::New(GL_POLYGON_SMOOTH_HINT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FOG_HINT"), v8::Uint32::New(GL_FOG_HINT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_GEN_S"), v8::Uint32::New(GL_TEXTURE_GEN_S), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_GEN_T"), v8::Uint32::New(GL_TEXTURE_GEN_T), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_GEN_R"), v8::Uint32::New(GL_TEXTURE_GEN_R), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_GEN_Q"), v8::Uint32::New(GL_TEXTURE_GEN_Q), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PIXEL_MAP_I_TO_I"), v8::Uint32::New(GL_PIXEL_MAP_I_TO_I), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PIXEL_MAP_S_TO_S"), v8::Uint32::New(GL_PIXEL_MAP_S_TO_S), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PIXEL_MAP_I_TO_R"), v8::Uint32::New(GL_PIXEL_MAP_I_TO_R), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PIXEL_MAP_I_TO_G"), v8::Uint32::New(GL_PIXEL_MAP_I_TO_G), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PIXEL_MAP_I_TO_B"), v8::Uint32::New(GL_PIXEL_MAP_I_TO_B), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PIXEL_MAP_I_TO_A"), v8::Uint32::New(GL_PIXEL_MAP_I_TO_A), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PIXEL_MAP_R_TO_R"), v8::Uint32::New(GL_PIXEL_MAP_R_TO_R), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PIXEL_MAP_G_TO_G"), v8::Uint32::New(GL_PIXEL_MAP_G_TO_G), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PIXEL_MAP_B_TO_B"), v8::Uint32::New(GL_PIXEL_MAP_B_TO_B), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PIXEL_MAP_A_TO_A"), v8::Uint32::New(GL_PIXEL_MAP_A_TO_A), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PIXEL_MAP_I_TO_I_SIZE"), v8::Uint32::New(GL_PIXEL_MAP_I_TO_I_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PIXEL_MAP_S_TO_S_SIZE"), v8::Uint32::New(GL_PIXEL_MAP_S_TO_S_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PIXEL_MAP_I_TO_R_SIZE"), v8::Uint32::New(GL_PIXEL_MAP_I_TO_R_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PIXEL_MAP_I_TO_G_SIZE"), v8::Uint32::New(GL_PIXEL_MAP_I_TO_G_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PIXEL_MAP_I_TO_B_SIZE"), v8::Uint32::New(GL_PIXEL_MAP_I_TO_B_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PIXEL_MAP_I_TO_A_SIZE"), v8::Uint32::New(GL_PIXEL_MAP_I_TO_A_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PIXEL_MAP_R_TO_R_SIZE"), v8::Uint32::New(GL_PIXEL_MAP_R_TO_R_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PIXEL_MAP_G_TO_G_SIZE"), v8::Uint32::New(GL_PIXEL_MAP_G_TO_G_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PIXEL_MAP_B_TO_B_SIZE"), v8::Uint32::New(GL_PIXEL_MAP_B_TO_B_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PIXEL_MAP_A_TO_A_SIZE"), v8::Uint32::New(GL_PIXEL_MAP_A_TO_A_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("UNPACK_SWAP_BYTES"), v8::Uint32::New(GL_UNPACK_SWAP_BYTES), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("UNPACK_LSB_FIRST"), v8::Uint32::New(GL_UNPACK_LSB_FIRST), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("UNPACK_ROW_LENGTH"), v8::Uint32::New(GL_UNPACK_ROW_LENGTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("UNPACK_SKIP_ROWS"), v8::Uint32::New(GL_UNPACK_SKIP_ROWS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("UNPACK_SKIP_PIXELS"), v8::Uint32::New(GL_UNPACK_SKIP_PIXELS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("UNPACK_ALIGNMENT"), v8::Uint32::New(GL_UNPACK_ALIGNMENT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PACK_SWAP_BYTES"), v8::Uint32::New(GL_PACK_SWAP_BYTES), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PACK_LSB_FIRST"), v8::Uint32::New(GL_PACK_LSB_FIRST), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PACK_ROW_LENGTH"), v8::Uint32::New(GL_PACK_ROW_LENGTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PACK_SKIP_ROWS"), v8::Uint32::New(GL_PACK_SKIP_ROWS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PACK_SKIP_PIXELS"), v8::Uint32::New(GL_PACK_SKIP_PIXELS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PACK_ALIGNMENT"), v8::Uint32::New(GL_PACK_ALIGNMENT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAP_COLOR"), v8::Uint32::New(GL_MAP_COLOR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAP_STENCIL"), v8::Uint32::New(GL_MAP_STENCIL), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INDEX_SHIFT"), v8::Uint32::New(GL_INDEX_SHIFT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INDEX_OFFSET"), v8::Uint32::New(GL_INDEX_OFFSET), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("RED_SCALE"), v8::Uint32::New(GL_RED_SCALE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("RED_BIAS"), v8::Uint32::New(GL_RED_BIAS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ZOOM_X"), v8::Uint32::New(GL_ZOOM_X), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ZOOM_Y"), v8::Uint32::New(GL_ZOOM_Y), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("GREEN_SCALE"), v8::Uint32::New(GL_GREEN_SCALE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("GREEN_BIAS"), v8::Uint32::New(GL_GREEN_BIAS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BLUE_SCALE"), v8::Uint32::New(GL_BLUE_SCALE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BLUE_BIAS"), v8::Uint32::New(GL_BLUE_BIAS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ALPHA_SCALE"), v8::Uint32::New(GL_ALPHA_SCALE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ALPHA_BIAS"), v8::Uint32::New(GL_ALPHA_BIAS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DEPTH_SCALE"), v8::Uint32::New(GL_DEPTH_SCALE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DEPTH_BIAS"), v8::Uint32::New(GL_DEPTH_BIAS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_EVAL_ORDER"), v8::Uint32::New(GL_MAX_EVAL_ORDER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_LIGHTS"), v8::Uint32::New(GL_MAX_LIGHTS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_CLIP_PLANES"), v8::Uint32::New(GL_MAX_CLIP_PLANES), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_TEXTURE_SIZE"), v8::Uint32::New(GL_MAX_TEXTURE_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_PIXEL_MAP_TABLE"), v8::Uint32::New(GL_MAX_PIXEL_MAP_TABLE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_ATTRIB_STACK_DEPTH"), v8::Uint32::New(GL_MAX_ATTRIB_STACK_DEPTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_MODELVIEW_STACK_DEPTH"), v8::Uint32::New(GL_MAX_MODELVIEW_STACK_DEPTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_NAME_STACK_DEPTH"), v8::Uint32::New(GL_MAX_NAME_STACK_DEPTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_PROJECTION_STACK_DEPTH"), v8::Uint32::New(GL_MAX_PROJECTION_STACK_DEPTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_TEXTURE_STACK_DEPTH"), v8::Uint32::New(GL_MAX_TEXTURE_STACK_DEPTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_VIEWPORT_DIMS"), v8::Uint32::New(GL_MAX_VIEWPORT_DIMS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_CLIENT_ATTRIB_STACK_DEPTH"), v8::Uint32::New(GL_MAX_CLIENT_ATTRIB_STACK_DEPTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SUBPIXEL_BITS"), v8::Uint32::New(GL_SUBPIXEL_BITS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INDEX_BITS"), v8::Uint32::New(GL_INDEX_BITS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("RED_BITS"), v8::Uint32::New(GL_RED_BITS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("GREEN_BITS"), v8::Uint32::New(GL_GREEN_BITS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BLUE_BITS"), v8::Uint32::New(GL_BLUE_BITS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ALPHA_BITS"), v8::Uint32::New(GL_ALPHA_BITS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DEPTH_BITS"), v8::Uint32::New(GL_DEPTH_BITS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("STENCIL_BITS"), v8::Uint32::New(GL_STENCIL_BITS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ACCUM_RED_BITS"), v8::Uint32::New(GL_ACCUM_RED_BITS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ACCUM_GREEN_BITS"), v8::Uint32::New(GL_ACCUM_GREEN_BITS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ACCUM_BLUE_BITS"), v8::Uint32::New(GL_ACCUM_BLUE_BITS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ACCUM_ALPHA_BITS"), v8::Uint32::New(GL_ACCUM_ALPHA_BITS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("NAME_STACK_DEPTH"), v8::Uint32::New(GL_NAME_STACK_DEPTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("AUTO_NORMAL"), v8::Uint32::New(GL_AUTO_NORMAL), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAP1_COLOR_4"), v8::Uint32::New(GL_MAP1_COLOR_4), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAP1_INDEX"), v8::Uint32::New(GL_MAP1_INDEX), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAP1_NORMAL"), v8::Uint32::New(GL_MAP1_NORMAL), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAP1_TEXTURE_COORD_1"), v8::Uint32::New(GL_MAP1_TEXTURE_COORD_1), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAP1_TEXTURE_COORD_2"), v8::Uint32::New(GL_MAP1_TEXTURE_COORD_2), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAP1_TEXTURE_COORD_3"), v8::Uint32::New(GL_MAP1_TEXTURE_COORD_3), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAP1_TEXTURE_COORD_4"), v8::Uint32::New(GL_MAP1_TEXTURE_COORD_4), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAP1_VERTEX_3"), v8::Uint32::New(GL_MAP1_VERTEX_3), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAP1_VERTEX_4"), v8::Uint32::New(GL_MAP1_VERTEX_4), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAP2_COLOR_4"), v8::Uint32::New(GL_MAP2_COLOR_4), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAP2_INDEX"), v8::Uint32::New(GL_MAP2_INDEX), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAP2_NORMAL"), v8::Uint32::New(GL_MAP2_NORMAL), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAP2_TEXTURE_COORD_1"), v8::Uint32::New(GL_MAP2_TEXTURE_COORD_1), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAP2_TEXTURE_COORD_2"), v8::Uint32::New(GL_MAP2_TEXTURE_COORD_2), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAP2_TEXTURE_COORD_3"), v8::Uint32::New(GL_MAP2_TEXTURE_COORD_3), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAP2_TEXTURE_COORD_4"), v8::Uint32::New(GL_MAP2_TEXTURE_COORD_4), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAP2_VERTEX_3"), v8::Uint32::New(GL_MAP2_VERTEX_3), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAP2_VERTEX_4"), v8::Uint32::New(GL_MAP2_VERTEX_4), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAP1_GRID_DOMAIN"), v8::Uint32::New(GL_MAP1_GRID_DOMAIN), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAP1_GRID_SEGMENTS"), v8::Uint32::New(GL_MAP1_GRID_SEGMENTS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAP2_GRID_DOMAIN"), v8::Uint32::New(GL_MAP2_GRID_DOMAIN), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAP2_GRID_SEGMENTS"), v8::Uint32::New(GL_MAP2_GRID_SEGMENTS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_1D"), v8::Uint32::New(GL_TEXTURE_1D), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_2D"), v8::Uint32::New(GL_TEXTURE_2D), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FEEDBACK_BUFFER_POINTER"), v8::Uint32::New(GL_FEEDBACK_BUFFER_POINTER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FEEDBACK_BUFFER_SIZE"), v8::Uint32::New(GL_FEEDBACK_BUFFER_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FEEDBACK_BUFFER_TYPE"), v8::Uint32::New(GL_FEEDBACK_BUFFER_TYPE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SELECTION_BUFFER_POINTER"), v8::Uint32::New(GL_SELECTION_BUFFER_POINTER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SELECTION_BUFFER_SIZE"), v8::Uint32::New(GL_SELECTION_BUFFER_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_WIDTH"), v8::Uint32::New(GL_TEXTURE_WIDTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_HEIGHT"), v8::Uint32::New(GL_TEXTURE_HEIGHT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_INTERNAL_FORMAT"), v8::Uint32::New(GL_TEXTURE_INTERNAL_FORMAT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_BORDER_COLOR"), v8::Uint32::New(GL_TEXTURE_BORDER_COLOR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_BORDER"), v8::Uint32::New(GL_TEXTURE_BORDER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DONT_CARE"), v8::Uint32::New(GL_DONT_CARE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FASTEST"), v8::Uint32::New(GL_FASTEST), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("NICEST"), v8::Uint32::New(GL_NICEST), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LIGHT0"), v8::Uint32::New(GL_LIGHT0), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LIGHT1"), v8::Uint32::New(GL_LIGHT1), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LIGHT2"), v8::Uint32::New(GL_LIGHT2), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LIGHT3"), v8::Uint32::New(GL_LIGHT3), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LIGHT4"), v8::Uint32::New(GL_LIGHT4), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LIGHT5"), v8::Uint32::New(GL_LIGHT5), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LIGHT6"), v8::Uint32::New(GL_LIGHT6), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LIGHT7"), v8::Uint32::New(GL_LIGHT7), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("AMBIENT"), v8::Uint32::New(GL_AMBIENT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DIFFUSE"), v8::Uint32::New(GL_DIFFUSE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SPECULAR"), v8::Uint32::New(GL_SPECULAR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POSITION"), v8::Uint32::New(GL_POSITION), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SPOT_DIRECTION"), v8::Uint32::New(GL_SPOT_DIRECTION), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SPOT_EXPONENT"), v8::Uint32::New(GL_SPOT_EXPONENT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SPOT_CUTOFF"), v8::Uint32::New(GL_SPOT_CUTOFF), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COMPILE"), v8::Uint32::New(GL_COMPILE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COMPILE_AND_EXECUTE"), v8::Uint32::New(GL_COMPILE_AND_EXECUTE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CLEAR"), v8::Uint32::New(GL_CLEAR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("AND"), v8::Uint32::New(GL_AND), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("AND_REVERSE"), v8::Uint32::New(GL_AND_REVERSE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COPY"), v8::Uint32::New(GL_COPY), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("AND_INVERTED"), v8::Uint32::New(GL_AND_INVERTED), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("NOOP"), v8::Uint32::New(GL_NOOP), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("XOR"), v8::Uint32::New(GL_XOR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("OR"), v8::Uint32::New(GL_OR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("NOR"), v8::Uint32::New(GL_NOR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("EQUIV"), v8::Uint32::New(GL_EQUIV), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INVERT"), v8::Uint32::New(GL_INVERT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("OR_REVERSE"), v8::Uint32::New(GL_OR_REVERSE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COPY_INVERTED"), v8::Uint32::New(GL_COPY_INVERTED), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("OR_INVERTED"), v8::Uint32::New(GL_OR_INVERTED), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("NAND"), v8::Uint32::New(GL_NAND), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SET"), v8::Uint32::New(GL_SET), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("EMISSION"), v8::Uint32::New(GL_EMISSION), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SHININESS"), v8::Uint32::New(GL_SHININESS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("AMBIENT_AND_DIFFUSE"), v8::Uint32::New(GL_AMBIENT_AND_DIFFUSE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_INDEXES"), v8::Uint32::New(GL_COLOR_INDEXES), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MODELVIEW"), v8::Uint32::New(GL_MODELVIEW), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PROJECTION"), v8::Uint32::New(GL_PROJECTION), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE"), v8::Uint32::New(GL_TEXTURE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR"), v8::Uint32::New(GL_COLOR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DEPTH"), v8::Uint32::New(GL_DEPTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("STENCIL"), v8::Uint32::New(GL_STENCIL), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_INDEX"), v8::Uint32::New(GL_COLOR_INDEX), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("STENCIL_INDEX"), v8::Uint32::New(GL_STENCIL_INDEX), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DEPTH_COMPONENT"), v8::Uint32::New(GL_DEPTH_COMPONENT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("RED"), v8::Uint32::New(GL_RED), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("GREEN"), v8::Uint32::New(GL_GREEN), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BLUE"), v8::Uint32::New(GL_BLUE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ALPHA"), v8::Uint32::New(GL_ALPHA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("RGB"), v8::Uint32::New(GL_RGB), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("RGBA"), v8::Uint32::New(GL_RGBA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LUMINANCE"), v8::Uint32::New(GL_LUMINANCE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LUMINANCE_ALPHA"), v8::Uint32::New(GL_LUMINANCE_ALPHA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BITMAP"), v8::Uint32::New(GL_BITMAP), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POINT"), v8::Uint32::New(GL_POINT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LINE"), v8::Uint32::New(GL_LINE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FILL"), v8::Uint32::New(GL_FILL), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("RENDER"), v8::Uint32::New(GL_RENDER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FEEDBACK"), v8::Uint32::New(GL_FEEDBACK), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SELECT"), v8::Uint32::New(GL_SELECT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FLAT"), v8::Uint32::New(GL_FLAT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SMOOTH"), v8::Uint32::New(GL_SMOOTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("KEEP"), v8::Uint32::New(GL_KEEP), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("REPLACE"), v8::Uint32::New(GL_REPLACE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INCR"), v8::Uint32::New(GL_INCR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DECR"), v8::Uint32::New(GL_DECR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VENDOR"), v8::Uint32::New(GL_VENDOR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("RENDERER"), v8::Uint32::New(GL_RENDERER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VERSION"), v8::Uint32::New(GL_VERSION), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("EXTENSIONS"), v8::Uint32::New(GL_EXTENSIONS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("S"), v8::Uint32::New(GL_S), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("T"), v8::Uint32::New(GL_T), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("R"), v8::Uint32::New(GL_R), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("Q"), v8::Uint32::New(GL_Q), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MODULATE"), v8::Uint32::New(GL_MODULATE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DECAL"), v8::Uint32::New(GL_DECAL), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_ENV_MODE"), v8::Uint32::New(GL_TEXTURE_ENV_MODE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_ENV_COLOR"), v8::Uint32::New(GL_TEXTURE_ENV_COLOR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_ENV"), v8::Uint32::New(GL_TEXTURE_ENV), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("EYE_LINEAR"), v8::Uint32::New(GL_EYE_LINEAR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("OBJECT_LINEAR"), v8::Uint32::New(GL_OBJECT_LINEAR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SPHERE_MAP"), v8::Uint32::New(GL_SPHERE_MAP), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_GEN_MODE"), v8::Uint32::New(GL_TEXTURE_GEN_MODE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("OBJECT_PLANE"), v8::Uint32::New(GL_OBJECT_PLANE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("EYE_PLANE"), v8::Uint32::New(GL_EYE_PLANE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("NEAREST"), v8::Uint32::New(GL_NEAREST), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LINEAR"), v8::Uint32::New(GL_LINEAR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("NEAREST_MIPMAP_NEAREST"), v8::Uint32::New(GL_NEAREST_MIPMAP_NEAREST), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LINEAR_MIPMAP_NEAREST"), v8::Uint32::New(GL_LINEAR_MIPMAP_NEAREST), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("NEAREST_MIPMAP_LINEAR"), v8::Uint32::New(GL_NEAREST_MIPMAP_LINEAR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LINEAR_MIPMAP_LINEAR"), v8::Uint32::New(GL_LINEAR_MIPMAP_LINEAR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_MAG_FILTER"), v8::Uint32::New(GL_TEXTURE_MAG_FILTER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_MIN_FILTER"), v8::Uint32::New(GL_TEXTURE_MIN_FILTER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_WRAP_S"), v8::Uint32::New(GL_TEXTURE_WRAP_S), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_WRAP_T"), v8::Uint32::New(GL_TEXTURE_WRAP_T), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CLAMP"), v8::Uint32::New(GL_CLAMP), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("REPEAT"), v8::Uint32::New(GL_REPEAT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CLIENT_PIXEL_STORE_BIT"), v8::Uint32::New(GL_CLIENT_PIXEL_STORE_BIT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CLIENT_VERTEX_ARRAY_BIT"), v8::Uint32::New(GL_CLIENT_VERTEX_ARRAY_BIT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CLIENT_ALL_ATTRIB_BITS"), v8::Uint32::New(GL_CLIENT_ALL_ATTRIB_BITS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POLYGON_OFFSET_FACTOR"), v8::Uint32::New(GL_POLYGON_OFFSET_FACTOR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POLYGON_OFFSET_UNITS"), v8::Uint32::New(GL_POLYGON_OFFSET_UNITS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POLYGON_OFFSET_POINT"), v8::Uint32::New(GL_POLYGON_OFFSET_POINT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POLYGON_OFFSET_LINE"), v8::Uint32::New(GL_POLYGON_OFFSET_LINE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POLYGON_OFFSET_FILL"), v8::Uint32::New(GL_POLYGON_OFFSET_FILL), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ALPHA4"), v8::Uint32::New(GL_ALPHA4), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ALPHA8"), v8::Uint32::New(GL_ALPHA8), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ALPHA12"), v8::Uint32::New(GL_ALPHA12), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ALPHA16"), v8::Uint32::New(GL_ALPHA16), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LUMINANCE4"), v8::Uint32::New(GL_LUMINANCE4), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LUMINANCE8"), v8::Uint32::New(GL_LUMINANCE8), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LUMINANCE12"), v8::Uint32::New(GL_LUMINANCE12), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LUMINANCE16"), v8::Uint32::New(GL_LUMINANCE16), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LUMINANCE4_ALPHA4"), v8::Uint32::New(GL_LUMINANCE4_ALPHA4), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LUMINANCE6_ALPHA2"), v8::Uint32::New(GL_LUMINANCE6_ALPHA2), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LUMINANCE8_ALPHA8"), v8::Uint32::New(GL_LUMINANCE8_ALPHA8), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LUMINANCE12_ALPHA4"), v8::Uint32::New(GL_LUMINANCE12_ALPHA4), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LUMINANCE12_ALPHA12"), v8::Uint32::New(GL_LUMINANCE12_ALPHA12), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LUMINANCE16_ALPHA16"), v8::Uint32::New(GL_LUMINANCE16_ALPHA16), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INTENSITY"), v8::Uint32::New(GL_INTENSITY), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INTENSITY4"), v8::Uint32::New(GL_INTENSITY4), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INTENSITY8"), v8::Uint32::New(GL_INTENSITY8), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INTENSITY12"), v8::Uint32::New(GL_INTENSITY12), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INTENSITY16"), v8::Uint32::New(GL_INTENSITY16), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("R3_G3_B2"), v8::Uint32::New(GL_R3_G3_B2), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("RGB4"), v8::Uint32::New(GL_RGB4), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("RGB5"), v8::Uint32::New(GL_RGB5), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("RGB8"), v8::Uint32::New(GL_RGB8), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("RGB10"), v8::Uint32::New(GL_RGB10), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("RGB12"), v8::Uint32::New(GL_RGB12), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("RGB16"), v8::Uint32::New(GL_RGB16), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("RGBA2"), v8::Uint32::New(GL_RGBA2), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("RGBA4"), v8::Uint32::New(GL_RGBA4), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("RGB5_A1"), v8::Uint32::New(GL_RGB5_A1), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("RGBA8"), v8::Uint32::New(GL_RGBA8), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("RGB10_A2"), v8::Uint32::New(GL_RGB10_A2), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("RGBA12"), v8::Uint32::New(GL_RGBA12), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("RGBA16"), v8::Uint32::New(GL_RGBA16), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_RED_SIZE"), v8::Uint32::New(GL_TEXTURE_RED_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_GREEN_SIZE"), v8::Uint32::New(GL_TEXTURE_GREEN_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_BLUE_SIZE"), v8::Uint32::New(GL_TEXTURE_BLUE_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_ALPHA_SIZE"), v8::Uint32::New(GL_TEXTURE_ALPHA_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_LUMINANCE_SIZE"), v8::Uint32::New(GL_TEXTURE_LUMINANCE_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_INTENSITY_SIZE"), v8::Uint32::New(GL_TEXTURE_INTENSITY_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PROXY_TEXTURE_1D"), v8::Uint32::New(GL_PROXY_TEXTURE_1D), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PROXY_TEXTURE_2D"), v8::Uint32::New(GL_PROXY_TEXTURE_2D), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_PRIORITY"), v8::Uint32::New(GL_TEXTURE_PRIORITY), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_RESIDENT"), v8::Uint32::New(GL_TEXTURE_RESIDENT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_BINDING_1D"), v8::Uint32::New(GL_TEXTURE_BINDING_1D), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_BINDING_2D"), v8::Uint32::New(GL_TEXTURE_BINDING_2D), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_BINDING_3D"), v8::Uint32::New(GL_TEXTURE_BINDING_3D), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VERTEX_ARRAY"), v8::Uint32::New(GL_VERTEX_ARRAY), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("NORMAL_ARRAY"), v8::Uint32::New(GL_NORMAL_ARRAY), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_ARRAY"), v8::Uint32::New(GL_COLOR_ARRAY), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INDEX_ARRAY"), v8::Uint32::New(GL_INDEX_ARRAY), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_COORD_ARRAY"), v8::Uint32::New(GL_TEXTURE_COORD_ARRAY), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("EDGE_FLAG_ARRAY"), v8::Uint32::New(GL_EDGE_FLAG_ARRAY), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VERTEX_ARRAY_SIZE"), v8::Uint32::New(GL_VERTEX_ARRAY_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VERTEX_ARRAY_TYPE"), v8::Uint32::New(GL_VERTEX_ARRAY_TYPE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VERTEX_ARRAY_STRIDE"), v8::Uint32::New(GL_VERTEX_ARRAY_STRIDE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("NORMAL_ARRAY_TYPE"), v8::Uint32::New(GL_NORMAL_ARRAY_TYPE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("NORMAL_ARRAY_STRIDE"), v8::Uint32::New(GL_NORMAL_ARRAY_STRIDE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_ARRAY_SIZE"), v8::Uint32::New(GL_COLOR_ARRAY_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_ARRAY_TYPE"), v8::Uint32::New(GL_COLOR_ARRAY_TYPE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_ARRAY_STRIDE"), v8::Uint32::New(GL_COLOR_ARRAY_STRIDE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INDEX_ARRAY_TYPE"), v8::Uint32::New(GL_INDEX_ARRAY_TYPE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INDEX_ARRAY_STRIDE"), v8::Uint32::New(GL_INDEX_ARRAY_STRIDE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_COORD_ARRAY_SIZE"), v8::Uint32::New(GL_TEXTURE_COORD_ARRAY_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_COORD_ARRAY_TYPE"), v8::Uint32::New(GL_TEXTURE_COORD_ARRAY_TYPE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_COORD_ARRAY_STRIDE"), v8::Uint32::New(GL_TEXTURE_COORD_ARRAY_STRIDE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("EDGE_FLAG_ARRAY_STRIDE"), v8::Uint32::New(GL_EDGE_FLAG_ARRAY_STRIDE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VERTEX_ARRAY_POINTER"), v8::Uint32::New(GL_VERTEX_ARRAY_POINTER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("NORMAL_ARRAY_POINTER"), v8::Uint32::New(GL_NORMAL_ARRAY_POINTER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_ARRAY_POINTER"), v8::Uint32::New(GL_COLOR_ARRAY_POINTER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INDEX_ARRAY_POINTER"), v8::Uint32::New(GL_INDEX_ARRAY_POINTER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_COORD_ARRAY_POINTER"), v8::Uint32::New(GL_TEXTURE_COORD_ARRAY_POINTER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("EDGE_FLAG_ARRAY_POINTER"), v8::Uint32::New(GL_EDGE_FLAG_ARRAY_POINTER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("V2F"), v8::Uint32::New(GL_V2F), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("V3F"), v8::Uint32::New(GL_V3F), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("C4UB_V2F"), v8::Uint32::New(GL_C4UB_V2F), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("C4UB_V3F"), v8::Uint32::New(GL_C4UB_V3F), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("C3F_V3F"), v8::Uint32::New(GL_C3F_V3F), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("N3F_V3F"), v8::Uint32::New(GL_N3F_V3F), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("C4F_N3F_V3F"), v8::Uint32::New(GL_C4F_N3F_V3F), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("T2F_V3F"), v8::Uint32::New(GL_T2F_V3F), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("T4F_V4F"), v8::Uint32::New(GL_T4F_V4F), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("T2F_C4UB_V3F"), v8::Uint32::New(GL_T2F_C4UB_V3F), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("T2F_C3F_V3F"), v8::Uint32::New(GL_T2F_C3F_V3F), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("T2F_N3F_V3F"), v8::Uint32::New(GL_T2F_N3F_V3F), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("T2F_C4F_N3F_V3F"), v8::Uint32::New(GL_T2F_C4F_N3F_V3F), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("T4F_C4F_N3F_V4F"), v8::Uint32::New(GL_T4F_C4F_N3F_V4F), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BGR"), v8::Uint32::New(GL_BGR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BGRA"), v8::Uint32::New(GL_BGRA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CONSTANT_COLOR"), v8::Uint32::New(GL_CONSTANT_COLOR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ONE_MINUS_CONSTANT_COLOR"), v8::Uint32::New(GL_ONE_MINUS_CONSTANT_COLOR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CONSTANT_ALPHA"), v8::Uint32::New(GL_CONSTANT_ALPHA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ONE_MINUS_CONSTANT_ALPHA"), v8::Uint32::New(GL_ONE_MINUS_CONSTANT_ALPHA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BLEND_COLOR"), v8::Uint32::New(GL_BLEND_COLOR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FUNC_ADD"), v8::Uint32::New(GL_FUNC_ADD), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MIN"), v8::Uint32::New(GL_MIN), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX"), v8::Uint32::New(GL_MAX), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FUNC_SUBTRACT"), v8::Uint32::New(GL_FUNC_SUBTRACT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FUNC_REVERSE_SUBTRACT"), v8::Uint32::New(GL_FUNC_REVERSE_SUBTRACT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_MATRIX"), v8::Uint32::New(GL_COLOR_MATRIX), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_MATRIX_STACK_DEPTH"), v8::Uint32::New(GL_COLOR_MATRIX_STACK_DEPTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_COLOR_MATRIX_STACK_DEPTH"), v8::Uint32::New(GL_MAX_COLOR_MATRIX_STACK_DEPTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POST_COLOR_MATRIX_RED_SCALE"), v8::Uint32::New(GL_POST_COLOR_MATRIX_RED_SCALE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POST_COLOR_MATRIX_GREEN_SCALE"), v8::Uint32::New(GL_POST_COLOR_MATRIX_GREEN_SCALE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POST_COLOR_MATRIX_BLUE_SCALE"), v8::Uint32::New(GL_POST_COLOR_MATRIX_BLUE_SCALE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POST_COLOR_MATRIX_ALPHA_SCALE"), v8::Uint32::New(GL_POST_COLOR_MATRIX_ALPHA_SCALE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POST_COLOR_MATRIX_RED_BIAS"), v8::Uint32::New(GL_POST_COLOR_MATRIX_RED_BIAS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POST_COLOR_MATRIX_GREEN_BIAS"), v8::Uint32::New(GL_POST_COLOR_MATRIX_GREEN_BIAS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POST_COLOR_MATRIX_BLUE_BIAS"), v8::Uint32::New(GL_POST_COLOR_MATRIX_BLUE_BIAS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POST_COLOR_MATRIX_ALPHA_BIAS"), v8::Uint32::New(GL_POST_COLOR_MATRIX_ALPHA_BIAS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_TABLE"), v8::Uint32::New(GL_COLOR_TABLE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POST_CONVOLUTION_COLOR_TABLE"), v8::Uint32::New(GL_POST_CONVOLUTION_COLOR_TABLE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POST_COLOR_MATRIX_COLOR_TABLE"), v8::Uint32::New(GL_POST_COLOR_MATRIX_COLOR_TABLE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PROXY_COLOR_TABLE"), v8::Uint32::New(GL_PROXY_COLOR_TABLE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PROXY_POST_CONVOLUTION_COLOR_TABLE"), v8::Uint32::New(GL_PROXY_POST_CONVOLUTION_COLOR_TABLE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PROXY_POST_COLOR_MATRIX_COLOR_TABLE"), v8::Uint32::New(GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_TABLE_SCALE"), v8::Uint32::New(GL_COLOR_TABLE_SCALE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_TABLE_BIAS"), v8::Uint32::New(GL_COLOR_TABLE_BIAS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_TABLE_FORMAT"), v8::Uint32::New(GL_COLOR_TABLE_FORMAT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_TABLE_WIDTH"), v8::Uint32::New(GL_COLOR_TABLE_WIDTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_TABLE_RED_SIZE"), v8::Uint32::New(GL_COLOR_TABLE_RED_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_TABLE_GREEN_SIZE"), v8::Uint32::New(GL_COLOR_TABLE_GREEN_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_TABLE_BLUE_SIZE"), v8::Uint32::New(GL_COLOR_TABLE_BLUE_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_TABLE_ALPHA_SIZE"), v8::Uint32::New(GL_COLOR_TABLE_ALPHA_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_TABLE_LUMINANCE_SIZE"), v8::Uint32::New(GL_COLOR_TABLE_LUMINANCE_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_TABLE_INTENSITY_SIZE"), v8::Uint32::New(GL_COLOR_TABLE_INTENSITY_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CONVOLUTION_1D"), v8::Uint32::New(GL_CONVOLUTION_1D), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CONVOLUTION_2D"), v8::Uint32::New(GL_CONVOLUTION_2D), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SEPARABLE_2D"), v8::Uint32::New(GL_SEPARABLE_2D), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CONVOLUTION_BORDER_MODE"), v8::Uint32::New(GL_CONVOLUTION_BORDER_MODE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CONVOLUTION_FILTER_SCALE"), v8::Uint32::New(GL_CONVOLUTION_FILTER_SCALE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CONVOLUTION_FILTER_BIAS"), v8::Uint32::New(GL_CONVOLUTION_FILTER_BIAS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("REDUCE"), v8::Uint32::New(GL_REDUCE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CONVOLUTION_FORMAT"), v8::Uint32::New(GL_CONVOLUTION_FORMAT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CONVOLUTION_WIDTH"), v8::Uint32::New(GL_CONVOLUTION_WIDTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CONVOLUTION_HEIGHT"), v8::Uint32::New(GL_CONVOLUTION_HEIGHT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_CONVOLUTION_WIDTH"), v8::Uint32::New(GL_MAX_CONVOLUTION_WIDTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_CONVOLUTION_HEIGHT"), v8::Uint32::New(GL_MAX_CONVOLUTION_HEIGHT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POST_CONVOLUTION_RED_SCALE"), v8::Uint32::New(GL_POST_CONVOLUTION_RED_SCALE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POST_CONVOLUTION_GREEN_SCALE"), v8::Uint32::New(GL_POST_CONVOLUTION_GREEN_SCALE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POST_CONVOLUTION_BLUE_SCALE"), v8::Uint32::New(GL_POST_CONVOLUTION_BLUE_SCALE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POST_CONVOLUTION_ALPHA_SCALE"), v8::Uint32::New(GL_POST_CONVOLUTION_ALPHA_SCALE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POST_CONVOLUTION_RED_BIAS"), v8::Uint32::New(GL_POST_CONVOLUTION_RED_BIAS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POST_CONVOLUTION_GREEN_BIAS"), v8::Uint32::New(GL_POST_CONVOLUTION_GREEN_BIAS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POST_CONVOLUTION_BLUE_BIAS"), v8::Uint32::New(GL_POST_CONVOLUTION_BLUE_BIAS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POST_CONVOLUTION_ALPHA_BIAS"), v8::Uint32::New(GL_POST_CONVOLUTION_ALPHA_BIAS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CONSTANT_BORDER"), v8::Uint32::New(GL_CONSTANT_BORDER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("REPLICATE_BORDER"), v8::Uint32::New(GL_REPLICATE_BORDER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CONVOLUTION_BORDER_COLOR"), v8::Uint32::New(GL_CONVOLUTION_BORDER_COLOR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_ELEMENTS_VERTICES"), v8::Uint32::New(GL_MAX_ELEMENTS_VERTICES), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_ELEMENTS_INDICES"), v8::Uint32::New(GL_MAX_ELEMENTS_INDICES), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("HISTOGRAM"), v8::Uint32::New(GL_HISTOGRAM), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PROXY_HISTOGRAM"), v8::Uint32::New(GL_PROXY_HISTOGRAM), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("HISTOGRAM_WIDTH"), v8::Uint32::New(GL_HISTOGRAM_WIDTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("HISTOGRAM_FORMAT"), v8::Uint32::New(GL_HISTOGRAM_FORMAT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("HISTOGRAM_RED_SIZE"), v8::Uint32::New(GL_HISTOGRAM_RED_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("HISTOGRAM_GREEN_SIZE"), v8::Uint32::New(GL_HISTOGRAM_GREEN_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("HISTOGRAM_BLUE_SIZE"), v8::Uint32::New(GL_HISTOGRAM_BLUE_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("HISTOGRAM_ALPHA_SIZE"), v8::Uint32::New(GL_HISTOGRAM_ALPHA_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("HISTOGRAM_LUMINANCE_SIZE"), v8::Uint32::New(GL_HISTOGRAM_LUMINANCE_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("HISTOGRAM_SINK"), v8::Uint32::New(GL_HISTOGRAM_SINK), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MINMAX"), v8::Uint32::New(GL_MINMAX), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MINMAX_FORMAT"), v8::Uint32::New(GL_MINMAX_FORMAT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MINMAX_SINK"), v8::Uint32::New(GL_MINMAX_SINK), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TABLE_TOO_LARGE"), v8::Uint32::New(GL_TABLE_TOO_LARGE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("UNSIGNED_BYTE_3_3_2"), v8::Uint32::New(GL_UNSIGNED_BYTE_3_3_2), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("UNSIGNED_SHORT_4_4_4_4"), v8::Uint32::New(GL_UNSIGNED_SHORT_4_4_4_4), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("UNSIGNED_SHORT_5_5_5_1"), v8::Uint32::New(GL_UNSIGNED_SHORT_5_5_5_1), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("UNSIGNED_INT_8_8_8_8"), v8::Uint32::New(GL_UNSIGNED_INT_8_8_8_8), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("UNSIGNED_INT_10_10_10_2"), v8::Uint32::New(GL_UNSIGNED_INT_10_10_10_2), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("UNSIGNED_BYTE_2_3_3_REV"), v8::Uint32::New(GL_UNSIGNED_BYTE_2_3_3_REV), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("UNSIGNED_SHORT_5_6_5"), v8::Uint32::New(GL_UNSIGNED_SHORT_5_6_5), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("UNSIGNED_SHORT_5_6_5_REV"), v8::Uint32::New(GL_UNSIGNED_SHORT_5_6_5_REV), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("UNSIGNED_SHORT_4_4_4_4_REV"), v8::Uint32::New(GL_UNSIGNED_SHORT_4_4_4_4_REV), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("UNSIGNED_SHORT_1_5_5_5_REV"), v8::Uint32::New(GL_UNSIGNED_SHORT_1_5_5_5_REV), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("UNSIGNED_INT_8_8_8_8_REV"), v8::Uint32::New(GL_UNSIGNED_INT_8_8_8_8_REV), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("UNSIGNED_INT_2_10_10_10_REV"), v8::Uint32::New(GL_UNSIGNED_INT_2_10_10_10_REV), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("RESCALE_NORMAL"), v8::Uint32::New(GL_RESCALE_NORMAL), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LIGHT_MODEL_COLOR_CONTROL"), v8::Uint32::New(GL_LIGHT_MODEL_COLOR_CONTROL), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SINGLE_COLOR"), v8::Uint32::New(GL_SINGLE_COLOR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SEPARATE_SPECULAR_COLOR"), v8::Uint32::New(GL_SEPARATE_SPECULAR_COLOR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PACK_SKIP_IMAGES"), v8::Uint32::New(GL_PACK_SKIP_IMAGES), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PACK_IMAGE_HEIGHT"), v8::Uint32::New(GL_PACK_IMAGE_HEIGHT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("UNPACK_SKIP_IMAGES"), v8::Uint32::New(GL_UNPACK_SKIP_IMAGES), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("UNPACK_IMAGE_HEIGHT"), v8::Uint32::New(GL_UNPACK_IMAGE_HEIGHT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_3D"), v8::Uint32::New(GL_TEXTURE_3D), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PROXY_TEXTURE_3D"), v8::Uint32::New(GL_PROXY_TEXTURE_3D), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_DEPTH"), v8::Uint32::New(GL_TEXTURE_DEPTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_WRAP_R"), v8::Uint32::New(GL_TEXTURE_WRAP_R), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_3D_TEXTURE_SIZE"), v8::Uint32::New(GL_MAX_3D_TEXTURE_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CLAMP_TO_EDGE"), v8::Uint32::New(GL_CLAMP_TO_EDGE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CLAMP_TO_BORDER"), v8::Uint32::New(GL_CLAMP_TO_BORDER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_MIN_LOD"), v8::Uint32::New(GL_TEXTURE_MIN_LOD), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_MAX_LOD"), v8::Uint32::New(GL_TEXTURE_MAX_LOD), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_BASE_LEVEL"), v8::Uint32::New(GL_TEXTURE_BASE_LEVEL), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_MAX_LEVEL"), v8::Uint32::New(GL_TEXTURE_MAX_LEVEL), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SMOOTH_POINT_SIZE_RANGE"), v8::Uint32::New(GL_SMOOTH_POINT_SIZE_RANGE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SMOOTH_POINT_SIZE_GRANULARITY"), v8::Uint32::New(GL_SMOOTH_POINT_SIZE_GRANULARITY), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SMOOTH_LINE_WIDTH_RANGE"), v8::Uint32::New(GL_SMOOTH_LINE_WIDTH_RANGE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SMOOTH_LINE_WIDTH_GRANULARITY"), v8::Uint32::New(GL_SMOOTH_LINE_WIDTH_GRANULARITY), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ALIASED_POINT_SIZE_RANGE"), v8::Uint32::New(GL_ALIASED_POINT_SIZE_RANGE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ALIASED_LINE_WIDTH_RANGE"), v8::Uint32::New(GL_ALIASED_LINE_WIDTH_RANGE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE0"), v8::Uint32::New(GL_TEXTURE0), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE1"), v8::Uint32::New(GL_TEXTURE1), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE2"), v8::Uint32::New(GL_TEXTURE2), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE3"), v8::Uint32::New(GL_TEXTURE3), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE4"), v8::Uint32::New(GL_TEXTURE4), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE5"), v8::Uint32::New(GL_TEXTURE5), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE6"), v8::Uint32::New(GL_TEXTURE6), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE7"), v8::Uint32::New(GL_TEXTURE7), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE8"), v8::Uint32::New(GL_TEXTURE8), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE9"), v8::Uint32::New(GL_TEXTURE9), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE10"), v8::Uint32::New(GL_TEXTURE10), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE11"), v8::Uint32::New(GL_TEXTURE11), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE12"), v8::Uint32::New(GL_TEXTURE12), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE13"), v8::Uint32::New(GL_TEXTURE13), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE14"), v8::Uint32::New(GL_TEXTURE14), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE15"), v8::Uint32::New(GL_TEXTURE15), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE16"), v8::Uint32::New(GL_TEXTURE16), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE17"), v8::Uint32::New(GL_TEXTURE17), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE18"), v8::Uint32::New(GL_TEXTURE18), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE19"), v8::Uint32::New(GL_TEXTURE19), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE20"), v8::Uint32::New(GL_TEXTURE20), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE21"), v8::Uint32::New(GL_TEXTURE21), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE22"), v8::Uint32::New(GL_TEXTURE22), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE23"), v8::Uint32::New(GL_TEXTURE23), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE24"), v8::Uint32::New(GL_TEXTURE24), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE25"), v8::Uint32::New(GL_TEXTURE25), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE26"), v8::Uint32::New(GL_TEXTURE26), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE27"), v8::Uint32::New(GL_TEXTURE27), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE28"), v8::Uint32::New(GL_TEXTURE28), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE29"), v8::Uint32::New(GL_TEXTURE29), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE30"), v8::Uint32::New(GL_TEXTURE30), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE31"), v8::Uint32::New(GL_TEXTURE31), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ACTIVE_TEXTURE"), v8::Uint32::New(GL_ACTIVE_TEXTURE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CLIENT_ACTIVE_TEXTURE"), v8::Uint32::New(GL_CLIENT_ACTIVE_TEXTURE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_TEXTURE_UNITS"), v8::Uint32::New(GL_MAX_TEXTURE_UNITS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COMBINE"), v8::Uint32::New(GL_COMBINE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COMBINE_RGB"), v8::Uint32::New(GL_COMBINE_RGB), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COMBINE_ALPHA"), v8::Uint32::New(GL_COMBINE_ALPHA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("RGB_SCALE"), v8::Uint32::New(GL_RGB_SCALE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ADD_SIGNED"), v8::Uint32::New(GL_ADD_SIGNED), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INTERPOLATE"), v8::Uint32::New(GL_INTERPOLATE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CONSTANT"), v8::Uint32::New(GL_CONSTANT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PRIMARY_COLOR"), v8::Uint32::New(GL_PRIMARY_COLOR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PREVIOUS"), v8::Uint32::New(GL_PREVIOUS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SUBTRACT"), v8::Uint32::New(GL_SUBTRACT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SRC0_RGB"), v8::Uint32::New(GL_SRC0_RGB), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SRC1_RGB"), v8::Uint32::New(GL_SRC1_RGB), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SRC2_RGB"), v8::Uint32::New(GL_SRC2_RGB), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SRC0_ALPHA"), v8::Uint32::New(GL_SRC0_ALPHA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SRC1_ALPHA"), v8::Uint32::New(GL_SRC1_ALPHA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SRC2_ALPHA"), v8::Uint32::New(GL_SRC2_ALPHA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SOURCE0_RGB"), v8::Uint32::New(GL_SOURCE0_RGB), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SOURCE1_RGB"), v8::Uint32::New(GL_SOURCE1_RGB), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SOURCE2_RGB"), v8::Uint32::New(GL_SOURCE2_RGB), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SOURCE0_ALPHA"), v8::Uint32::New(GL_SOURCE0_ALPHA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SOURCE1_ALPHA"), v8::Uint32::New(GL_SOURCE1_ALPHA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SOURCE2_ALPHA"), v8::Uint32::New(GL_SOURCE2_ALPHA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("OPERAND0_RGB"), v8::Uint32::New(GL_OPERAND0_RGB), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("OPERAND1_RGB"), v8::Uint32::New(GL_OPERAND1_RGB), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("OPERAND2_RGB"), v8::Uint32::New(GL_OPERAND2_RGB), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("OPERAND0_ALPHA"), v8::Uint32::New(GL_OPERAND0_ALPHA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("OPERAND1_ALPHA"), v8::Uint32::New(GL_OPERAND1_ALPHA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("OPERAND2_ALPHA"), v8::Uint32::New(GL_OPERAND2_ALPHA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DOT3_RGB"), v8::Uint32::New(GL_DOT3_RGB), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DOT3_RGBA"), v8::Uint32::New(GL_DOT3_RGBA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TRANSPOSE_MODELVIEW_MATRIX"), v8::Uint32::New(GL_TRANSPOSE_MODELVIEW_MATRIX), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TRANSPOSE_PROJECTION_MATRIX"), v8::Uint32::New(GL_TRANSPOSE_PROJECTION_MATRIX), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TRANSPOSE_TEXTURE_MATRIX"), v8::Uint32::New(GL_TRANSPOSE_TEXTURE_MATRIX), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TRANSPOSE_COLOR_MATRIX"), v8::Uint32::New(GL_TRANSPOSE_COLOR_MATRIX), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("NORMAL_MAP"), v8::Uint32::New(GL_NORMAL_MAP), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("REFLECTION_MAP"), v8::Uint32::New(GL_REFLECTION_MAP), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_CUBE_MAP"), v8::Uint32::New(GL_TEXTURE_CUBE_MAP), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_BINDING_CUBE_MAP"), v8::Uint32::New(GL_TEXTURE_BINDING_CUBE_MAP), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_CUBE_MAP_POSITIVE_X"), v8::Uint32::New(GL_TEXTURE_CUBE_MAP_POSITIVE_X), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_CUBE_MAP_POSITIVE_Y"), v8::Uint32::New(GL_TEXTURE_CUBE_MAP_POSITIVE_Y), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_CUBE_MAP_POSITIVE_Z"), v8::Uint32::New(GL_TEXTURE_CUBE_MAP_POSITIVE_Z), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PROXY_TEXTURE_CUBE_MAP"), v8::Uint32::New(GL_PROXY_TEXTURE_CUBE_MAP), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_CUBE_MAP_TEXTURE_SIZE"), v8::Uint32::New(GL_MAX_CUBE_MAP_TEXTURE_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COMPRESSED_ALPHA"), v8::Uint32::New(GL_COMPRESSED_ALPHA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COMPRESSED_LUMINANCE"), v8::Uint32::New(GL_COMPRESSED_LUMINANCE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COMPRESSED_LUMINANCE_ALPHA"), v8::Uint32::New(GL_COMPRESSED_LUMINANCE_ALPHA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COMPRESSED_INTENSITY"), v8::Uint32::New(GL_COMPRESSED_INTENSITY), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COMPRESSED_RGB"), v8::Uint32::New(GL_COMPRESSED_RGB), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COMPRESSED_RGBA"), v8::Uint32::New(GL_COMPRESSED_RGBA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_COMPRESSION_HINT"), v8::Uint32::New(GL_TEXTURE_COMPRESSION_HINT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_COMPRESSED_IMAGE_SIZE"), v8::Uint32::New(GL_TEXTURE_COMPRESSED_IMAGE_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_COMPRESSED"), v8::Uint32::New(GL_TEXTURE_COMPRESSED), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("NUM_COMPRESSED_TEXTURE_FORMATS"), v8::Uint32::New(GL_NUM_COMPRESSED_TEXTURE_FORMATS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COMPRESSED_TEXTURE_FORMATS"), v8::Uint32::New(GL_COMPRESSED_TEXTURE_FORMATS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MULTISAMPLE"), v8::Uint32::New(GL_MULTISAMPLE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SAMPLE_ALPHA_TO_COVERAGE"), v8::Uint32::New(GL_SAMPLE_ALPHA_TO_COVERAGE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SAMPLE_ALPHA_TO_ONE"), v8::Uint32::New(GL_SAMPLE_ALPHA_TO_ONE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SAMPLE_COVERAGE"), v8::Uint32::New(GL_SAMPLE_COVERAGE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SAMPLE_BUFFERS"), v8::Uint32::New(GL_SAMPLE_BUFFERS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SAMPLES"), v8::Uint32::New(GL_SAMPLES), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SAMPLE_COVERAGE_VALUE"), v8::Uint32::New(GL_SAMPLE_COVERAGE_VALUE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SAMPLE_COVERAGE_INVERT"), v8::Uint32::New(GL_SAMPLE_COVERAGE_INVERT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MULTISAMPLE_BIT"), v8::Uint32::New(GL_MULTISAMPLE_BIT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DEPTH_COMPONENT16"), v8::Uint32::New(GL_DEPTH_COMPONENT16), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DEPTH_COMPONENT24"), v8::Uint32::New(GL_DEPTH_COMPONENT24), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DEPTH_COMPONENT32"), v8::Uint32::New(GL_DEPTH_COMPONENT32), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_DEPTH_SIZE"), v8::Uint32::New(GL_TEXTURE_DEPTH_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DEPTH_TEXTURE_MODE"), v8::Uint32::New(GL_DEPTH_TEXTURE_MODE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_COMPARE_MODE"), v8::Uint32::New(GL_TEXTURE_COMPARE_MODE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_COMPARE_FUNC"), v8::Uint32::New(GL_TEXTURE_COMPARE_FUNC), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COMPARE_R_TO_TEXTURE"), v8::Uint32::New(GL_COMPARE_R_TO_TEXTURE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("QUERY_COUNTER_BITS"), v8::Uint32::New(GL_QUERY_COUNTER_BITS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CURRENT_QUERY"), v8::Uint32::New(GL_CURRENT_QUERY), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("QUERY_RESULT"), v8::Uint32::New(GL_QUERY_RESULT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("QUERY_RESULT_AVAILABLE"), v8::Uint32::New(GL_QUERY_RESULT_AVAILABLE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SAMPLES_PASSED"), v8::Uint32::New(GL_SAMPLES_PASSED), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FOG_COORD_SRC"), v8::Uint32::New(GL_FOG_COORD_SRC), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FOG_COORD"), v8::Uint32::New(GL_FOG_COORD), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FRAGMENT_DEPTH"), v8::Uint32::New(GL_FRAGMENT_DEPTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CURRENT_FOG_COORD"), v8::Uint32::New(GL_CURRENT_FOG_COORD), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FOG_COORD_ARRAY_TYPE"), v8::Uint32::New(GL_FOG_COORD_ARRAY_TYPE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FOG_COORD_ARRAY_STRIDE"), v8::Uint32::New(GL_FOG_COORD_ARRAY_STRIDE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FOG_COORD_ARRAY_POINTER"), v8::Uint32::New(GL_FOG_COORD_ARRAY_POINTER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FOG_COORD_ARRAY"), v8::Uint32::New(GL_FOG_COORD_ARRAY), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FOG_COORDINATE_SOURCE"), v8::Uint32::New(GL_FOG_COORDINATE_SOURCE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FOG_COORDINATE"), v8::Uint32::New(GL_FOG_COORDINATE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CURRENT_FOG_COORDINATE"), v8::Uint32::New(GL_CURRENT_FOG_COORDINATE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FOG_COORDINATE_ARRAY_TYPE"), v8::Uint32::New(GL_FOG_COORDINATE_ARRAY_TYPE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FOG_COORDINATE_ARRAY_STRIDE"), v8::Uint32::New(GL_FOG_COORDINATE_ARRAY_STRIDE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FOG_COORDINATE_ARRAY_POINTER"), v8::Uint32::New(GL_FOG_COORDINATE_ARRAY_POINTER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FOG_COORDINATE_ARRAY"), v8::Uint32::New(GL_FOG_COORDINATE_ARRAY), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_SUM"), v8::Uint32::New(GL_COLOR_SUM), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CURRENT_SECONDARY_COLOR"), v8::Uint32::New(GL_CURRENT_SECONDARY_COLOR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SECONDARY_COLOR_ARRAY_SIZE"), v8::Uint32::New(GL_SECONDARY_COLOR_ARRAY_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SECONDARY_COLOR_ARRAY_TYPE"), v8::Uint32::New(GL_SECONDARY_COLOR_ARRAY_TYPE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SECONDARY_COLOR_ARRAY_STRIDE"), v8::Uint32::New(GL_SECONDARY_COLOR_ARRAY_STRIDE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SECONDARY_COLOR_ARRAY_POINTER"), v8::Uint32::New(GL_SECONDARY_COLOR_ARRAY_POINTER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SECONDARY_COLOR_ARRAY"), v8::Uint32::New(GL_SECONDARY_COLOR_ARRAY), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POINT_SIZE_MIN"), v8::Uint32::New(GL_POINT_SIZE_MIN), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POINT_SIZE_MAX"), v8::Uint32::New(GL_POINT_SIZE_MAX), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POINT_FADE_THRESHOLD_SIZE"), v8::Uint32::New(GL_POINT_FADE_THRESHOLD_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BLEND_DST_RGB"), v8::Uint32::New(GL_BLEND_DST_RGB), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BLEND_SRC_RGB"), v8::Uint32::New(GL_BLEND_SRC_RGB), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BLEND_DST_ALPHA"), v8::Uint32::New(GL_BLEND_DST_ALPHA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BLEND_SRC_ALPHA"), v8::Uint32::New(GL_BLEND_SRC_ALPHA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("GENERATE_MIPMAP"), v8::Uint32::New(GL_GENERATE_MIPMAP), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("GENERATE_MIPMAP_HINT"), v8::Uint32::New(GL_GENERATE_MIPMAP_HINT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INCR_WRAP"), v8::Uint32::New(GL_INCR_WRAP), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DECR_WRAP"), v8::Uint32::New(GL_DECR_WRAP), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MIRRORED_REPEAT"), v8::Uint32::New(GL_MIRRORED_REPEAT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_TEXTURE_LOD_BIAS"), v8::Uint32::New(GL_MAX_TEXTURE_LOD_BIAS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_FILTER_CONTROL"), v8::Uint32::New(GL_TEXTURE_FILTER_CONTROL), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_LOD_BIAS"), v8::Uint32::New(GL_TEXTURE_LOD_BIAS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ARRAY_BUFFER"), v8::Uint32::New(GL_ARRAY_BUFFER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ELEMENT_ARRAY_BUFFER"), v8::Uint32::New(GL_ELEMENT_ARRAY_BUFFER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ARRAY_BUFFER_BINDING"), v8::Uint32::New(GL_ARRAY_BUFFER_BINDING), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ELEMENT_ARRAY_BUFFER_BINDING"), v8::Uint32::New(GL_ELEMENT_ARRAY_BUFFER_BINDING), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VERTEX_ARRAY_BUFFER_BINDING"), v8::Uint32::New(GL_VERTEX_ARRAY_BUFFER_BINDING), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("NORMAL_ARRAY_BUFFER_BINDING"), v8::Uint32::New(GL_NORMAL_ARRAY_BUFFER_BINDING), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COLOR_ARRAY_BUFFER_BINDING"), v8::Uint32::New(GL_COLOR_ARRAY_BUFFER_BINDING), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INDEX_ARRAY_BUFFER_BINDING"), v8::Uint32::New(GL_INDEX_ARRAY_BUFFER_BINDING), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("TEXTURE_COORD_ARRAY_BUFFER_BINDING"), v8::Uint32::New(GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("EDGE_FLAG_ARRAY_BUFFER_BINDING"), v8::Uint32::New(GL_EDGE_FLAG_ARRAY_BUFFER_BINDING), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SECONDARY_COLOR_ARRAY_BUFFER_BINDING"), v8::Uint32::New(GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FOG_COORD_ARRAY_BUFFER_BINDING"), v8::Uint32::New(GL_FOG_COORD_ARRAY_BUFFER_BINDING), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("WEIGHT_ARRAY_BUFFER_BINDING"), v8::Uint32::New(GL_WEIGHT_ARRAY_BUFFER_BINDING), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VERTEX_ATTRIB_ARRAY_BUFFER_BINDING"), v8::Uint32::New(GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("STREAM_DRAW"), v8::Uint32::New(GL_STREAM_DRAW), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("STREAM_READ"), v8::Uint32::New(GL_STREAM_READ), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("STREAM_COPY"), v8::Uint32::New(GL_STREAM_COPY), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DYNAMIC_DRAW"), v8::Uint32::New(GL_DYNAMIC_DRAW), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DYNAMIC_READ"), v8::Uint32::New(GL_DYNAMIC_READ), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DYNAMIC_COPY"), v8::Uint32::New(GL_DYNAMIC_COPY), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("READ_ONLY"), v8::Uint32::New(GL_READ_ONLY), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("WRITE_ONLY"), v8::Uint32::New(GL_WRITE_ONLY), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("READ_WRITE"), v8::Uint32::New(GL_READ_WRITE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BUFFER_SIZE"), v8::Uint32::New(GL_BUFFER_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BUFFER_USAGE"), v8::Uint32::New(GL_BUFFER_USAGE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BUFFER_ACCESS"), v8::Uint32::New(GL_BUFFER_ACCESS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BUFFER_MAPPED"), v8::Uint32::New(GL_BUFFER_MAPPED), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BUFFER_MAP_POINTER"), v8::Uint32::New(GL_BUFFER_MAP_POINTER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FOG_COORDINATE_ARRAY_BUFFER_BINDING"), v8::Uint32::New(GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CURRENT_PROGRAM"), v8::Uint32::New(GL_CURRENT_PROGRAM), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SHADER_TYPE"), v8::Uint32::New(GL_SHADER_TYPE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DELETE_STATUS"), v8::Uint32::New(GL_DELETE_STATUS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COMPILE_STATUS"), v8::Uint32::New(GL_COMPILE_STATUS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LINK_STATUS"), v8::Uint32::New(GL_LINK_STATUS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VALIDATE_STATUS"), v8::Uint32::New(GL_VALIDATE_STATUS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INFO_LOG_LENGTH"), v8::Uint32::New(GL_INFO_LOG_LENGTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ATTACHED_SHADERS"), v8::Uint32::New(GL_ATTACHED_SHADERS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ACTIVE_UNIFORMS"), v8::Uint32::New(GL_ACTIVE_UNIFORMS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ACTIVE_UNIFORM_MAX_LENGTH"), v8::Uint32::New(GL_ACTIVE_UNIFORM_MAX_LENGTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SHADER_SOURCE_LENGTH"), v8::Uint32::New(GL_SHADER_SOURCE_LENGTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FLOAT_VEC2"), v8::Uint32::New(GL_FLOAT_VEC2), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FLOAT_VEC3"), v8::Uint32::New(GL_FLOAT_VEC3), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FLOAT_VEC4"), v8::Uint32::New(GL_FLOAT_VEC4), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INT_VEC2"), v8::Uint32::New(GL_INT_VEC2), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INT_VEC3"), v8::Uint32::New(GL_INT_VEC3), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("INT_VEC4"), v8::Uint32::New(GL_INT_VEC4), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BOOL"), v8::Uint32::New(GL_BOOL), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BOOL_VEC2"), v8::Uint32::New(GL_BOOL_VEC2), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BOOL_VEC3"), v8::Uint32::New(GL_BOOL_VEC3), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("BOOL_VEC4"), v8::Uint32::New(GL_BOOL_VEC4), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FLOAT_MAT2"), v8::Uint32::New(GL_FLOAT_MAT2), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FLOAT_MAT3"), v8::Uint32::New(GL_FLOAT_MAT3), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FLOAT_MAT4"), v8::Uint32::New(GL_FLOAT_MAT4), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SAMPLER_1D"), v8::Uint32::New(GL_SAMPLER_1D), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SAMPLER_2D"), v8::Uint32::New(GL_SAMPLER_2D), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SAMPLER_3D"), v8::Uint32::New(GL_SAMPLER_3D), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SAMPLER_CUBE"), v8::Uint32::New(GL_SAMPLER_CUBE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SAMPLER_1D_SHADOW"), v8::Uint32::New(GL_SAMPLER_1D_SHADOW), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SAMPLER_2D_SHADOW"), v8::Uint32::New(GL_SAMPLER_2D_SHADOW), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SHADING_LANGUAGE_VERSION"), v8::Uint32::New(GL_SHADING_LANGUAGE_VERSION), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VERTEX_SHADER"), v8::Uint32::New(GL_VERTEX_SHADER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_VERTEX_UNIFORM_COMPONENTS"), v8::Uint32::New(GL_MAX_VERTEX_UNIFORM_COMPONENTS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_VARYING_FLOATS"), v8::Uint32::New(GL_MAX_VARYING_FLOATS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_VERTEX_TEXTURE_IMAGE_UNITS"), v8::Uint32::New(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_COMBINED_TEXTURE_IMAGE_UNITS"), v8::Uint32::New(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ACTIVE_ATTRIBUTES"), v8::Uint32::New(GL_ACTIVE_ATTRIBUTES), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("ACTIVE_ATTRIBUTE_MAX_LENGTH"), v8::Uint32::New(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FRAGMENT_SHADER"), v8::Uint32::New(GL_FRAGMENT_SHADER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_FRAGMENT_UNIFORM_COMPONENTS"), v8::Uint32::New(GL_MAX_FRAGMENT_UNIFORM_COMPONENTS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_VERTEX_ATTRIBS"), v8::Uint32::New(GL_MAX_VERTEX_ATTRIBS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VERTEX_ATTRIB_ARRAY_ENABLED"), v8::Uint32::New(GL_VERTEX_ATTRIB_ARRAY_ENABLED), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VERTEX_ATTRIB_ARRAY_SIZE"), v8::Uint32::New(GL_VERTEX_ATTRIB_ARRAY_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VERTEX_ATTRIB_ARRAY_STRIDE"), v8::Uint32::New(GL_VERTEX_ATTRIB_ARRAY_STRIDE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VERTEX_ATTRIB_ARRAY_TYPE"), v8::Uint32::New(GL_VERTEX_ATTRIB_ARRAY_TYPE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VERTEX_ATTRIB_ARRAY_NORMALIZED"), v8::Uint32::New(GL_VERTEX_ATTRIB_ARRAY_NORMALIZED), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CURRENT_VERTEX_ATTRIB"), v8::Uint32::New(GL_CURRENT_VERTEX_ATTRIB), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VERTEX_ATTRIB_ARRAY_POINTER"), v8::Uint32::New(GL_VERTEX_ATTRIB_ARRAY_POINTER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VERTEX_PROGRAM_POINT_SIZE"), v8::Uint32::New(GL_VERTEX_PROGRAM_POINT_SIZE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("VERTEX_PROGRAM_TWO_SIDE"), v8::Uint32::New(GL_VERTEX_PROGRAM_TWO_SIDE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_TEXTURE_COORDS"), v8::Uint32::New(GL_MAX_TEXTURE_COORDS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_TEXTURE_IMAGE_UNITS"), v8::Uint32::New(GL_MAX_TEXTURE_IMAGE_UNITS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("MAX_DRAW_BUFFERS"), v8::Uint32::New(GL_MAX_DRAW_BUFFERS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DRAW_BUFFER0"), v8::Uint32::New(GL_DRAW_BUFFER0), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DRAW_BUFFER1"), v8::Uint32::New(GL_DRAW_BUFFER1), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DRAW_BUFFER2"), v8::Uint32::New(GL_DRAW_BUFFER2), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DRAW_BUFFER3"), v8::Uint32::New(GL_DRAW_BUFFER3), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DRAW_BUFFER4"), v8::Uint32::New(GL_DRAW_BUFFER4), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DRAW_BUFFER5"), v8::Uint32::New(GL_DRAW_BUFFER5), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DRAW_BUFFER6"), v8::Uint32::New(GL_DRAW_BUFFER6), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DRAW_BUFFER7"), v8::Uint32::New(GL_DRAW_BUFFER7), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DRAW_BUFFER8"), v8::Uint32::New(GL_DRAW_BUFFER8), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DRAW_BUFFER9"), v8::Uint32::New(GL_DRAW_BUFFER9), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DRAW_BUFFER10"), v8::Uint32::New(GL_DRAW_BUFFER10), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DRAW_BUFFER11"), v8::Uint32::New(GL_DRAW_BUFFER11), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DRAW_BUFFER12"), v8::Uint32::New(GL_DRAW_BUFFER12), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DRAW_BUFFER13"), v8::Uint32::New(GL_DRAW_BUFFER13), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DRAW_BUFFER14"), v8::Uint32::New(GL_DRAW_BUFFER14), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("DRAW_BUFFER15"), v8::Uint32::New(GL_DRAW_BUFFER15), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POINT_SPRITE"), v8::Uint32::New(GL_POINT_SPRITE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COORD_REPLACE"), v8::Uint32::New(GL_COORD_REPLACE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("POINT_SPRITE_COORD_ORIGIN"), v8::Uint32::New(GL_POINT_SPRITE_COORD_ORIGIN), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("LOWER_LEFT"), v8::Uint32::New(GL_LOWER_LEFT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("UPPER_LEFT"), v8::Uint32::New(GL_UPPER_LEFT), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("STENCIL_BACK_FUNC"), v8::Uint32::New(GL_STENCIL_BACK_FUNC), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("STENCIL_BACK_VALUE_MASK"), v8::Uint32::New(GL_STENCIL_BACK_VALUE_MASK), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("STENCIL_BACK_REF"), v8::Uint32::New(GL_STENCIL_BACK_REF), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("STENCIL_BACK_FAIL"), v8::Uint32::New(GL_STENCIL_BACK_FAIL), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("STENCIL_BACK_PASS_DEPTH_FAIL"), v8::Uint32::New(GL_STENCIL_BACK_PASS_DEPTH_FAIL), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("STENCIL_BACK_PASS_DEPTH_PASS"), v8::Uint32::New(GL_STENCIL_BACK_PASS_DEPTH_PASS), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("STENCIL_BACK_WRITEMASK"), v8::Uint32::New(GL_STENCIL_BACK_WRITEMASK), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("CURRENT_RASTER_SECONDARY_COLOR"), v8::Uint32::New(GL_CURRENT_RASTER_SECONDARY_COLOR), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PIXEL_PACK_BUFFER"), v8::Uint32::New(GL_PIXEL_PACK_BUFFER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PIXEL_UNPACK_BUFFER"), v8::Uint32::New(GL_PIXEL_UNPACK_BUFFER), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PIXEL_PACK_BUFFER_BINDING"), v8::Uint32::New(GL_PIXEL_PACK_BUFFER_BINDING), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("PIXEL_UNPACK_BUFFER_BINDING"), v8::Uint32::New(GL_PIXEL_UNPACK_BUFFER_BINDING), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FLOAT_MAT2x3"), v8::Uint32::New(GL_FLOAT_MAT2x3), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FLOAT_MAT2x4"), v8::Uint32::New(GL_FLOAT_MAT2x4), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FLOAT_MAT3x2"), v8::Uint32::New(GL_FLOAT_MAT3x2), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FLOAT_MAT3x4"), v8::Uint32::New(GL_FLOAT_MAT3x4), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FLOAT_MAT4x2"), v8::Uint32::New(GL_FLOAT_MAT4x2), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("FLOAT_MAT4x3"), v8::Uint32::New(GL_FLOAT_MAT4x3), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SRGB"), v8::Uint32::New(GL_SRGB), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SRGB8"), v8::Uint32::New(GL_SRGB8), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SRGB_ALPHA"), v8::Uint32::New(GL_SRGB_ALPHA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SRGB8_ALPHA8"), v8::Uint32::New(GL_SRGB8_ALPHA8), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SLUMINANCE_ALPHA"), v8::Uint32::New(GL_SLUMINANCE_ALPHA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SLUMINANCE8_ALPHA8"), v8::Uint32::New(GL_SLUMINANCE8_ALPHA8), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SLUMINANCE"), v8::Uint32::New(GL_SLUMINANCE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("SLUMINANCE8"), v8::Uint32::New(GL_SLUMINANCE8), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COMPRESSED_SRGB"), v8::Uint32::New(GL_COMPRESSED_SRGB), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COMPRESSED_SRGB_ALPHA"), v8::Uint32::New(GL_COMPRESSED_SRGB_ALPHA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COMPRESSED_SLUMINANCE"), v8::Uint32::New(GL_COMPRESSED_SLUMINANCE), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("COMPRESSED_SLUMINANCE_ALPHA"), v8::Uint32::New(GL_COMPRESSED_SLUMINANCE_ALPHA), v8::ReadOnly);
	Gl->Set(v8::String::NewSymbol("accum"), v8::FunctionTemplate::New(GLglAccumCallback));
	Gl->Set(v8::String::NewSymbol("alphaFunc"), v8::FunctionTemplate::New(GLglAlphaFuncCallback));
	Gl->Set(v8::String::NewSymbol("deleteLists"), v8::FunctionTemplate::New(GLglDeleteListsCallback));
	Gl->Set(v8::String::NewSymbol("deleteTextures"), v8::FunctionTemplate::New(GLglDeleteTexturesCallback));
	Gl->Set(v8::String::NewSymbol("depthFunc"), v8::FunctionTemplate::New(GLglDepthFuncCallback));
	Gl->Set(v8::String::NewSymbol("depthMask"), v8::FunctionTemplate::New(GLglDepthMaskCallback));
	Gl->Set(v8::String::NewSymbol("depthRange"), v8::FunctionTemplate::New(GLglDepthRangeCallback));
	Gl->Set(v8::String::NewSymbol("disable"), v8::FunctionTemplate::New(GLglDisableCallback));
	Gl->Set(v8::String::NewSymbol("disableClientState"), v8::FunctionTemplate::New(GLglDisableClientStateCallback));
	Gl->Set(v8::String::NewSymbol("drawArrays"), v8::FunctionTemplate::New(GLglDrawArraysCallback));
	Gl->Set(v8::String::NewSymbol("drawBuffer"), v8::FunctionTemplate::New(GLglDrawBufferCallback));
	Gl->Set(v8::String::NewSymbol("edgeFlag"), v8::FunctionTemplate::New(GLglEdgeFlagCallback));
	Gl->Set(v8::String::NewSymbol("edgeFlagv"), v8::FunctionTemplate::New(GLglEdgeFlagvCallback));
	Gl->Set(v8::String::NewSymbol("enable"), v8::FunctionTemplate::New(GLglEnableCallback));
	Gl->Set(v8::String::NewSymbol("enableClientState"), v8::FunctionTemplate::New(GLglEnableClientStateCallback));
	Gl->Set(v8::String::NewSymbol("end"), v8::FunctionTemplate::New(GLglEndCallback));
	Gl->Set(v8::String::NewSymbol("endList"), v8::FunctionTemplate::New(GLglEndListCallback));
	Gl->Set(v8::String::NewSymbol("evalCoord1d"), v8::FunctionTemplate::New(GLglEvalCoord1dCallback));
	Gl->Set(v8::String::NewSymbol("evalCoord1dv"), v8::FunctionTemplate::New(GLglEvalCoord1dvCallback));
	Gl->Set(v8::String::NewSymbol("evalCoord1f"), v8::FunctionTemplate::New(GLglEvalCoord1fCallback));
	Gl->Set(v8::String::NewSymbol("evalCoord1fv"), v8::FunctionTemplate::New(GLglEvalCoord1fvCallback));
	Gl->Set(v8::String::NewSymbol("evalCoord2d"), v8::FunctionTemplate::New(GLglEvalCoord2dCallback));
	Gl->Set(v8::String::NewSymbol("evalCoord2dv"), v8::FunctionTemplate::New(GLglEvalCoord2dvCallback));
	Gl->Set(v8::String::NewSymbol("evalCoord2f"), v8::FunctionTemplate::New(GLglEvalCoord2fCallback));
	Gl->Set(v8::String::NewSymbol("evalCoord2fv"), v8::FunctionTemplate::New(GLglEvalCoord2fvCallback));
	Gl->Set(v8::String::NewSymbol("evalMesh1"), v8::FunctionTemplate::New(GLglEvalMesh1Callback));
	Gl->Set(v8::String::NewSymbol("evalMesh2"), v8::FunctionTemplate::New(GLglEvalMesh2Callback));
	Gl->Set(v8::String::NewSymbol("evalPoint1"), v8::FunctionTemplate::New(GLglEvalPoint1Callback));
	Gl->Set(v8::String::NewSymbol("evalPoint2"), v8::FunctionTemplate::New(GLglEvalPoint2Callback));
	Gl->Set(v8::String::NewSymbol("feedbackBuffer"), v8::FunctionTemplate::New(GLglFeedbackBufferCallback));
	Gl->Set(v8::String::NewSymbol("finish"), v8::FunctionTemplate::New(GLglFinishCallback));
	Gl->Set(v8::String::NewSymbol("flush"), v8::FunctionTemplate::New(GLglFlushCallback));
	Gl->Set(v8::String::NewSymbol("fogf"), v8::FunctionTemplate::New(GLglFogfCallback));
	Gl->Set(v8::String::NewSymbol("fogfv"), v8::FunctionTemplate::New(GLglFogfvCallback));
	Gl->Set(v8::String::NewSymbol("fogi"), v8::FunctionTemplate::New(GLglFogiCallback));
	Gl->Set(v8::String::NewSymbol("fogiv"), v8::FunctionTemplate::New(GLglFogivCallback));
	Gl->Set(v8::String::NewSymbol("frontFace"), v8::FunctionTemplate::New(GLglFrontFaceCallback));
	Gl->Set(v8::String::NewSymbol("frustum"), v8::FunctionTemplate::New(GLglFrustumCallback));
	Gl->Set(v8::String::NewSymbol("genLists"), v8::FunctionTemplate::New(GLglGenListsCallback));
	Gl->Set(v8::String::NewSymbol("genTextures"), v8::FunctionTemplate::New(GLglGenTexturesCallback));
	Gl->Set(v8::String::NewSymbol("getBooleanv"), v8::FunctionTemplate::New(GLglGetBooleanvCallback));
	Gl->Set(v8::String::NewSymbol("getClipPlane"), v8::FunctionTemplate::New(GLglGetClipPlaneCallback));
	Gl->Set(v8::String::NewSymbol("getColorTableParameterfv"), v8::FunctionTemplate::New(GLglGetColorTableParameterfvCallback));
	Gl->Set(v8::String::NewSymbol("getColorTableParameteriv"), v8::FunctionTemplate::New(GLglGetColorTableParameterivCallback));
	Gl->Set(v8::String::NewSymbol("getConvolutionParameterfv"), v8::FunctionTemplate::New(GLglGetConvolutionParameterfvCallback));
	Gl->Set(v8::String::NewSymbol("getConvolutionParameteriv"), v8::FunctionTemplate::New(GLglGetConvolutionParameterivCallback));
	Gl->Set(v8::String::NewSymbol("getDoublev"), v8::FunctionTemplate::New(GLglGetDoublevCallback));
	Gl->Set(v8::String::NewSymbol("getError"), v8::FunctionTemplate::New(GLglGetErrorCallback));
	Gl->Set(v8::String::NewSymbol("getFloatv"), v8::FunctionTemplate::New(GLglGetFloatvCallback));
	Gl->Set(v8::String::NewSymbol("getHistogramParameterfv"), v8::FunctionTemplate::New(GLglGetHistogramParameterfvCallback));
	Gl->Set(v8::String::NewSymbol("getHistogramParameteriv"), v8::FunctionTemplate::New(GLglGetHistogramParameterivCallback));
	Gl->Set(v8::String::NewSymbol("getIntegerv"), v8::FunctionTemplate::New(GLglGetIntegervCallback));
	Gl->Set(v8::String::NewSymbol("getLightfv"), v8::FunctionTemplate::New(GLglGetLightfvCallback));
	Gl->Set(v8::String::NewSymbol("getLightiv"), v8::FunctionTemplate::New(GLglGetLightivCallback));
	Gl->Set(v8::String::NewSymbol("getMapdv"), v8::FunctionTemplate::New(GLglGetMapdvCallback));
	Gl->Set(v8::String::NewSymbol("getMapfv"), v8::FunctionTemplate::New(GLglGetMapfvCallback));
	Gl->Set(v8::String::NewSymbol("getMapiv"), v8::FunctionTemplate::New(GLglGetMapivCallback));
	Gl->Set(v8::String::NewSymbol("getMaterialfv"), v8::FunctionTemplate::New(GLglGetMaterialfvCallback));
	Gl->Set(v8::String::NewSymbol("getMaterialiv"), v8::FunctionTemplate::New(GLglGetMaterialivCallback));
	Gl->Set(v8::String::NewSymbol("getMinmaxParameterfv"), v8::FunctionTemplate::New(GLglGetMinmaxParameterfvCallback));
	Gl->Set(v8::String::NewSymbol("getMinmaxParameteriv"), v8::FunctionTemplate::New(GLglGetMinmaxParameterivCallback));
	Gl->Set(v8::String::NewSymbol("getPixelMapfv"), v8::FunctionTemplate::New(GLglGetPixelMapfvCallback));
	Gl->Set(v8::String::NewSymbol("getPixelMapuiv"), v8::FunctionTemplate::New(GLglGetPixelMapuivCallback));
	Gl->Set(v8::String::NewSymbol("getPixelMapusv"), v8::FunctionTemplate::New(GLglGetPixelMapusvCallback));
	Gl->Set(v8::String::NewSymbol("getPolygonStipple"), v8::FunctionTemplate::New(GLglGetPolygonStippleCallback));
	Gl->Set(v8::String::NewSymbol("getTexEnvfv"), v8::FunctionTemplate::New(GLglGetTexEnvfvCallback));
	Gl->Set(v8::String::NewSymbol("getTexEnviv"), v8::FunctionTemplate::New(GLglGetTexEnvivCallback));
	Gl->Set(v8::String::NewSymbol("getTexGendv"), v8::FunctionTemplate::New(GLglGetTexGendvCallback));
	Gl->Set(v8::String::NewSymbol("getTexGenfv"), v8::FunctionTemplate::New(GLglGetTexGenfvCallback));
	Gl->Set(v8::String::NewSymbol("getTexGeniv"), v8::FunctionTemplate::New(GLglGetTexGenivCallback));
	Gl->Set(v8::String::NewSymbol("getTexLevelParameterfv"), v8::FunctionTemplate::New(GLglGetTexLevelParameterfvCallback));
	Gl->Set(v8::String::NewSymbol("getTexLevelParameteriv"), v8::FunctionTemplate::New(GLglGetTexLevelParameterivCallback));
	Gl->Set(v8::String::NewSymbol("getTexParameterfv"), v8::FunctionTemplate::New(GLglGetTexParameterfvCallback));
	Gl->Set(v8::String::NewSymbol("getTexParameteriv"), v8::FunctionTemplate::New(GLglGetTexParameterivCallback));
	Gl->Set(v8::String::NewSymbol("hint"), v8::FunctionTemplate::New(GLglHintCallback));
	Gl->Set(v8::String::NewSymbol("histogram"), v8::FunctionTemplate::New(GLglHistogramCallback));
	Gl->Set(v8::String::NewSymbol("indexMask"), v8::FunctionTemplate::New(GLglIndexMaskCallback));
	Gl->Set(v8::String::NewSymbol("indexd"), v8::FunctionTemplate::New(GLglIndexdCallback));
	Gl->Set(v8::String::NewSymbol("indexdv"), v8::FunctionTemplate::New(GLglIndexdvCallback));
	Gl->Set(v8::String::NewSymbol("indexf"), v8::FunctionTemplate::New(GLglIndexfCallback));
	Gl->Set(v8::String::NewSymbol("indexfv"), v8::FunctionTemplate::New(GLglIndexfvCallback));
	Gl->Set(v8::String::NewSymbol("indexi"), v8::FunctionTemplate::New(GLglIndexiCallback));
	Gl->Set(v8::String::NewSymbol("indexiv"), v8::FunctionTemplate::New(GLglIndexivCallback));
	Gl->Set(v8::String::NewSymbol("indexs"), v8::FunctionTemplate::New(GLglIndexsCallback));
	Gl->Set(v8::String::NewSymbol("indexsv"), v8::FunctionTemplate::New(GLglIndexsvCallback));
	Gl->Set(v8::String::NewSymbol("indexub"), v8::FunctionTemplate::New(GLglIndexubCallback));
	Gl->Set(v8::String::NewSymbol("indexubv"), v8::FunctionTemplate::New(GLglIndexubvCallback));
	Gl->Set(v8::String::NewSymbol("initNames"), v8::FunctionTemplate::New(GLglInitNamesCallback));
	Gl->Set(v8::String::NewSymbol("isEnabled"), v8::FunctionTemplate::New(GLglIsEnabledCallback));
	Gl->Set(v8::String::NewSymbol("isList"), v8::FunctionTemplate::New(GLglIsListCallback));
	Gl->Set(v8::String::NewSymbol("isTexture"), v8::FunctionTemplate::New(GLglIsTextureCallback));
	Gl->Set(v8::String::NewSymbol("lightModelf"), v8::FunctionTemplate::New(GLglLightModelfCallback));
	Gl->Set(v8::String::NewSymbol("lightModelfv"), v8::FunctionTemplate::New(GLglLightModelfvCallback));
	Gl->Set(v8::String::NewSymbol("lightModeli"), v8::FunctionTemplate::New(GLglLightModeliCallback));
	Gl->Set(v8::String::NewSymbol("lightModeliv"), v8::FunctionTemplate::New(GLglLightModelivCallback));
	Gl->Set(v8::String::NewSymbol("lightf"), v8::FunctionTemplate::New(GLglLightfCallback));
	Gl->Set(v8::String::NewSymbol("lightfv"), v8::FunctionTemplate::New(GLglLightfvCallback));
	Gl->Set(v8::String::NewSymbol("lighti"), v8::FunctionTemplate::New(GLglLightiCallback));
	Gl->Set(v8::String::NewSymbol("lightiv"), v8::FunctionTemplate::New(GLglLightivCallback));
	Gl->Set(v8::String::NewSymbol("lineStipple"), v8::FunctionTemplate::New(GLglLineStippleCallback));
	Gl->Set(v8::String::NewSymbol("lineWidth"), v8::FunctionTemplate::New(GLglLineWidthCallback));
	Gl->Set(v8::String::NewSymbol("listBase"), v8::FunctionTemplate::New(GLglListBaseCallback));
	Gl->Set(v8::String::NewSymbol("loadIdentity"), v8::FunctionTemplate::New(GLglLoadIdentityCallback));
	Gl->Set(v8::String::NewSymbol("loadMatrixd"), v8::FunctionTemplate::New(GLglLoadMatrixdCallback));
	Gl->Set(v8::String::NewSymbol("loadMatrixf"), v8::FunctionTemplate::New(GLglLoadMatrixfCallback));
	Gl->Set(v8::String::NewSymbol("loadName"), v8::FunctionTemplate::New(GLglLoadNameCallback));
	Gl->Set(v8::String::NewSymbol("logicOp"), v8::FunctionTemplate::New(GLglLogicOpCallback));
	Gl->Set(v8::String::NewSymbol("map1d"), v8::FunctionTemplate::New(GLglMap1dCallback));
	Gl->Set(v8::String::NewSymbol("map1f"), v8::FunctionTemplate::New(GLglMap1fCallback));
	Gl->Set(v8::String::NewSymbol("map2d"), v8::FunctionTemplate::New(GLglMap2dCallback));
	Gl->Set(v8::String::NewSymbol("map2f"), v8::FunctionTemplate::New(GLglMap2fCallback));
	Gl->Set(v8::String::NewSymbol("mapGrid1d"), v8::FunctionTemplate::New(GLglMapGrid1dCallback));
	Gl->Set(v8::String::NewSymbol("mapGrid1f"), v8::FunctionTemplate::New(GLglMapGrid1fCallback));
	Gl->Set(v8::String::NewSymbol("mapGrid2d"), v8::FunctionTemplate::New(GLglMapGrid2dCallback));
	Gl->Set(v8::String::NewSymbol("mapGrid2f"), v8::FunctionTemplate::New(GLglMapGrid2fCallback));
	Gl->Set(v8::String::NewSymbol("materialf"), v8::FunctionTemplate::New(GLglMaterialfCallback));
	Gl->Set(v8::String::NewSymbol("materialfv"), v8::FunctionTemplate::New(GLglMaterialfvCallback));
	Gl->Set(v8::String::NewSymbol("materiali"), v8::FunctionTemplate::New(GLglMaterialiCallback));
	Gl->Set(v8::String::NewSymbol("materialiv"), v8::FunctionTemplate::New(GLglMaterialivCallback));
	Gl->Set(v8::String::NewSymbol("matrixMode"), v8::FunctionTemplate::New(GLglMatrixModeCallback));
	Gl->Set(v8::String::NewSymbol("minmax"), v8::FunctionTemplate::New(GLglMinmaxCallback));
	Gl->Set(v8::String::NewSymbol("multMatrixd"), v8::FunctionTemplate::New(GLglMultMatrixdCallback));
	Gl->Set(v8::String::NewSymbol("multMatrixf"), v8::FunctionTemplate::New(GLglMultMatrixfCallback));
	Gl->Set(v8::String::NewSymbol("newList"), v8::FunctionTemplate::New(GLglNewListCallback));
	Gl->Set(v8::String::NewSymbol("normal3b"), v8::FunctionTemplate::New(GLglNormal3bCallback));
	Gl->Set(v8::String::NewSymbol("normal3bv"), v8::FunctionTemplate::New(GLglNormal3bvCallback));
	Gl->Set(v8::String::NewSymbol("normal3d"), v8::FunctionTemplate::New(GLglNormal3dCallback));
	Gl->Set(v8::String::NewSymbol("normal3dv"), v8::FunctionTemplate::New(GLglNormal3dvCallback));
	Gl->Set(v8::String::NewSymbol("normal3f"), v8::FunctionTemplate::New(GLglNormal3fCallback));
	Gl->Set(v8::String::NewSymbol("normal3fv"), v8::FunctionTemplate::New(GLglNormal3fvCallback));
	Gl->Set(v8::String::NewSymbol("normal3i"), v8::FunctionTemplate::New(GLglNormal3iCallback));
	Gl->Set(v8::String::NewSymbol("normal3iv"), v8::FunctionTemplate::New(GLglNormal3ivCallback));
	Gl->Set(v8::String::NewSymbol("normal3s"), v8::FunctionTemplate::New(GLglNormal3sCallback));
	Gl->Set(v8::String::NewSymbol("normal3sv"), v8::FunctionTemplate::New(GLglNormal3svCallback));
	Gl->Set(v8::String::NewSymbol("ortho"), v8::FunctionTemplate::New(GLglOrthoCallback));
	Gl->Set(v8::String::NewSymbol("passThrough"), v8::FunctionTemplate::New(GLglPassThroughCallback));
	Gl->Set(v8::String::NewSymbol("pixelMapfv"), v8::FunctionTemplate::New(GLglPixelMapfvCallback));
	Gl->Set(v8::String::NewSymbol("pixelMapuiv"), v8::FunctionTemplate::New(GLglPixelMapuivCallback));
	Gl->Set(v8::String::NewSymbol("pixelMapusv"), v8::FunctionTemplate::New(GLglPixelMapusvCallback));
	Gl->Set(v8::String::NewSymbol("pixelStoref"), v8::FunctionTemplate::New(GLglPixelStorefCallback));
	Gl->Set(v8::String::NewSymbol("pixelStorei"), v8::FunctionTemplate::New(GLglPixelStoreiCallback));
	Gl->Set(v8::String::NewSymbol("pixelTransferf"), v8::FunctionTemplate::New(GLglPixelTransferfCallback));
	Gl->Set(v8::String::NewSymbol("pixelTransferi"), v8::FunctionTemplate::New(GLglPixelTransferiCallback));
	Gl->Set(v8::String::NewSymbol("pixelZoom"), v8::FunctionTemplate::New(GLglPixelZoomCallback));
	Gl->Set(v8::String::NewSymbol("pointSize"), v8::FunctionTemplate::New(GLglPointSizeCallback));
	Gl->Set(v8::String::NewSymbol("polygonMode"), v8::FunctionTemplate::New(GLglPolygonModeCallback));
	Gl->Set(v8::String::NewSymbol("polygonOffset"), v8::FunctionTemplate::New(GLglPolygonOffsetCallback));
	Gl->Set(v8::String::NewSymbol("polygonStipple"), v8::FunctionTemplate::New(GLglPolygonStippleCallback));
	Gl->Set(v8::String::NewSymbol("popAttrib"), v8::FunctionTemplate::New(GLglPopAttribCallback));
	Gl->Set(v8::String::NewSymbol("popClientAttrib"), v8::FunctionTemplate::New(GLglPopClientAttribCallback));
	Gl->Set(v8::String::NewSymbol("popMatrix"), v8::FunctionTemplate::New(GLglPopMatrixCallback));
	Gl->Set(v8::String::NewSymbol("popName"), v8::FunctionTemplate::New(GLglPopNameCallback));
	Gl->Set(v8::String::NewSymbol("prioritizeTextures"), v8::FunctionTemplate::New(GLglPrioritizeTexturesCallback));
	Gl->Set(v8::String::NewSymbol("pushAttrib"), v8::FunctionTemplate::New(GLglPushAttribCallback));
	Gl->Set(v8::String::NewSymbol("pushClientAttrib"), v8::FunctionTemplate::New(GLglPushClientAttribCallback));
	Gl->Set(v8::String::NewSymbol("pushMatrix"), v8::FunctionTemplate::New(GLglPushMatrixCallback));
	Gl->Set(v8::String::NewSymbol("pushName"), v8::FunctionTemplate::New(GLglPushNameCallback));
	Gl->Set(v8::String::NewSymbol("rasterPos2d"), v8::FunctionTemplate::New(GLglRasterPos2dCallback));
	Gl->Set(v8::String::NewSymbol("rasterPos2dv"), v8::FunctionTemplate::New(GLglRasterPos2dvCallback));
	Gl->Set(v8::String::NewSymbol("rasterPos2f"), v8::FunctionTemplate::New(GLglRasterPos2fCallback));
	Gl->Set(v8::String::NewSymbol("rasterPos2fv"), v8::FunctionTemplate::New(GLglRasterPos2fvCallback));
	Gl->Set(v8::String::NewSymbol("rasterPos2i"), v8::FunctionTemplate::New(GLglRasterPos2iCallback));
	Gl->Set(v8::String::NewSymbol("rasterPos2iv"), v8::FunctionTemplate::New(GLglRasterPos2ivCallback));
	Gl->Set(v8::String::NewSymbol("rasterPos2s"), v8::FunctionTemplate::New(GLglRasterPos2sCallback));
	Gl->Set(v8::String::NewSymbol("rasterPos2sv"), v8::FunctionTemplate::New(GLglRasterPos2svCallback));
	Gl->Set(v8::String::NewSymbol("rasterPos3d"), v8::FunctionTemplate::New(GLglRasterPos3dCallback));
	Gl->Set(v8::String::NewSymbol("rasterPos3dv"), v8::FunctionTemplate::New(GLglRasterPos3dvCallback));
	Gl->Set(v8::String::NewSymbol("rasterPos3f"), v8::FunctionTemplate::New(GLglRasterPos3fCallback));
	Gl->Set(v8::String::NewSymbol("rasterPos3fv"), v8::FunctionTemplate::New(GLglRasterPos3fvCallback));
	Gl->Set(v8::String::NewSymbol("rasterPos3i"), v8::FunctionTemplate::New(GLglRasterPos3iCallback));
	Gl->Set(v8::String::NewSymbol("rasterPos3iv"), v8::FunctionTemplate::New(GLglRasterPos3ivCallback));
	Gl->Set(v8::String::NewSymbol("rasterPos3s"), v8::FunctionTemplate::New(GLglRasterPos3sCallback));
	Gl->Set(v8::String::NewSymbol("rasterPos3sv"), v8::FunctionTemplate::New(GLglRasterPos3svCallback));
	Gl->Set(v8::String::NewSymbol("rasterPos4d"), v8::FunctionTemplate::New(GLglRasterPos4dCallback));
	Gl->Set(v8::String::NewSymbol("rasterPos4dv"), v8::FunctionTemplate::New(GLglRasterPos4dvCallback));
	Gl->Set(v8::String::NewSymbol("rasterPos4f"), v8::FunctionTemplate::New(GLglRasterPos4fCallback));
	Gl->Set(v8::String::NewSymbol("rasterPos4fv"), v8::FunctionTemplate::New(GLglRasterPos4fvCallback));
	Gl->Set(v8::String::NewSymbol("rasterPos4i"), v8::FunctionTemplate::New(GLglRasterPos4iCallback));
	Gl->Set(v8::String::NewSymbol("rasterPos4iv"), v8::FunctionTemplate::New(GLglRasterPos4ivCallback));
	Gl->Set(v8::String::NewSymbol("rasterPos4s"), v8::FunctionTemplate::New(GLglRasterPos4sCallback));
	Gl->Set(v8::String::NewSymbol("rasterPos4sv"), v8::FunctionTemplate::New(GLglRasterPos4svCallback));
	Gl->Set(v8::String::NewSymbol("readBuffer"), v8::FunctionTemplate::New(GLglReadBufferCallback));
	Gl->Set(v8::String::NewSymbol("rectd"), v8::FunctionTemplate::New(GLglRectdCallback));
	Gl->Set(v8::String::NewSymbol("rectdv"), v8::FunctionTemplate::New(GLglRectdvCallback));
	Gl->Set(v8::String::NewSymbol("rectf"), v8::FunctionTemplate::New(GLglRectfCallback));
	Gl->Set(v8::String::NewSymbol("rectfv"), v8::FunctionTemplate::New(GLglRectfvCallback));
	Gl->Set(v8::String::NewSymbol("recti"), v8::FunctionTemplate::New(GLglRectiCallback));
	Gl->Set(v8::String::NewSymbol("rectiv"), v8::FunctionTemplate::New(GLglRectivCallback));
	Gl->Set(v8::String::NewSymbol("rects"), v8::FunctionTemplate::New(GLglRectsCallback));
	Gl->Set(v8::String::NewSymbol("rectsv"), v8::FunctionTemplate::New(GLglRectsvCallback));
	Gl->Set(v8::String::NewSymbol("renderMode"), v8::FunctionTemplate::New(GLglRenderModeCallback));
	Gl->Set(v8::String::NewSymbol("resetHistogram"), v8::FunctionTemplate::New(GLglResetHistogramCallback));
	Gl->Set(v8::String::NewSymbol("resetMinmax"), v8::FunctionTemplate::New(GLglResetMinmaxCallback));
	Gl->Set(v8::String::NewSymbol("rotated"), v8::FunctionTemplate::New(GLglRotatedCallback));
	Gl->Set(v8::String::NewSymbol("rotatef"), v8::FunctionTemplate::New(GLglRotatefCallback));
	Gl->Set(v8::String::NewSymbol("scaled"), v8::FunctionTemplate::New(GLglScaledCallback));
	Gl->Set(v8::String::NewSymbol("scalef"), v8::FunctionTemplate::New(GLglScalefCallback));
	Gl->Set(v8::String::NewSymbol("scissor"), v8::FunctionTemplate::New(GLglScissorCallback));
	Gl->Set(v8::String::NewSymbol("selectBuffer"), v8::FunctionTemplate::New(GLglSelectBufferCallback));
	Gl->Set(v8::String::NewSymbol("shadeModel"), v8::FunctionTemplate::New(GLglShadeModelCallback));
	Gl->Set(v8::String::NewSymbol("stencilFunc"), v8::FunctionTemplate::New(GLglStencilFuncCallback));
	Gl->Set(v8::String::NewSymbol("stencilMask"), v8::FunctionTemplate::New(GLglStencilMaskCallback));
	Gl->Set(v8::String::NewSymbol("stencilOp"), v8::FunctionTemplate::New(GLglStencilOpCallback));
	Gl->Set(v8::String::NewSymbol("texCoord1d"), v8::FunctionTemplate::New(GLglTexCoord1dCallback));
	Gl->Set(v8::String::NewSymbol("texCoord1dv"), v8::FunctionTemplate::New(GLglTexCoord1dvCallback));
	Gl->Set(v8::String::NewSymbol("texCoord1f"), v8::FunctionTemplate::New(GLglTexCoord1fCallback));
	Gl->Set(v8::String::NewSymbol("texCoord1fv"), v8::FunctionTemplate::New(GLglTexCoord1fvCallback));
	Gl->Set(v8::String::NewSymbol("texCoord1i"), v8::FunctionTemplate::New(GLglTexCoord1iCallback));
	Gl->Set(v8::String::NewSymbol("texCoord1iv"), v8::FunctionTemplate::New(GLglTexCoord1ivCallback));
	Gl->Set(v8::String::NewSymbol("texCoord1s"), v8::FunctionTemplate::New(GLglTexCoord1sCallback));
	Gl->Set(v8::String::NewSymbol("texCoord1sv"), v8::FunctionTemplate::New(GLglTexCoord1svCallback));
	Gl->Set(v8::String::NewSymbol("texCoord2d"), v8::FunctionTemplate::New(GLglTexCoord2dCallback));
	Gl->Set(v8::String::NewSymbol("texCoord2dv"), v8::FunctionTemplate::New(GLglTexCoord2dvCallback));
	Gl->Set(v8::String::NewSymbol("texCoord2f"), v8::FunctionTemplate::New(GLglTexCoord2fCallback));
	Gl->Set(v8::String::NewSymbol("texCoord2fv"), v8::FunctionTemplate::New(GLglTexCoord2fvCallback));
	Gl->Set(v8::String::NewSymbol("texCoord2i"), v8::FunctionTemplate::New(GLglTexCoord2iCallback));
	Gl->Set(v8::String::NewSymbol("texCoord2iv"), v8::FunctionTemplate::New(GLglTexCoord2ivCallback));
	Gl->Set(v8::String::NewSymbol("texCoord2s"), v8::FunctionTemplate::New(GLglTexCoord2sCallback));
	Gl->Set(v8::String::NewSymbol("texCoord2sv"), v8::FunctionTemplate::New(GLglTexCoord2svCallback));
	Gl->Set(v8::String::NewSymbol("texCoord3d"), v8::FunctionTemplate::New(GLglTexCoord3dCallback));
	Gl->Set(v8::String::NewSymbol("texCoord3dv"), v8::FunctionTemplate::New(GLglTexCoord3dvCallback));
	Gl->Set(v8::String::NewSymbol("texCoord3f"), v8::FunctionTemplate::New(GLglTexCoord3fCallback));
	Gl->Set(v8::String::NewSymbol("texCoord3fv"), v8::FunctionTemplate::New(GLglTexCoord3fvCallback));
	Gl->Set(v8::String::NewSymbol("texCoord3i"), v8::FunctionTemplate::New(GLglTexCoord3iCallback));
	Gl->Set(v8::String::NewSymbol("texCoord3iv"), v8::FunctionTemplate::New(GLglTexCoord3ivCallback));
	Gl->Set(v8::String::NewSymbol("texCoord3s"), v8::FunctionTemplate::New(GLglTexCoord3sCallback));
	Gl->Set(v8::String::NewSymbol("texCoord3sv"), v8::FunctionTemplate::New(GLglTexCoord3svCallback));
	Gl->Set(v8::String::NewSymbol("texCoord4d"), v8::FunctionTemplate::New(GLglTexCoord4dCallback));
	Gl->Set(v8::String::NewSymbol("texCoord4dv"), v8::FunctionTemplate::New(GLglTexCoord4dvCallback));
	Gl->Set(v8::String::NewSymbol("texCoord4f"), v8::FunctionTemplate::New(GLglTexCoord4fCallback));
	Gl->Set(v8::String::NewSymbol("texCoord4fv"), v8::FunctionTemplate::New(GLglTexCoord4fvCallback));
	Gl->Set(v8::String::NewSymbol("texCoord4i"), v8::FunctionTemplate::New(GLglTexCoord4iCallback));
	Gl->Set(v8::String::NewSymbol("texCoord4iv"), v8::FunctionTemplate::New(GLglTexCoord4ivCallback));
	Gl->Set(v8::String::NewSymbol("texCoord4s"), v8::FunctionTemplate::New(GLglTexCoord4sCallback));
	Gl->Set(v8::String::NewSymbol("texCoord4sv"), v8::FunctionTemplate::New(GLglTexCoord4svCallback));
	Gl->Set(v8::String::NewSymbol("texEnvf"), v8::FunctionTemplate::New(GLglTexEnvfCallback));
	Gl->Set(v8::String::NewSymbol("texEnvfv"), v8::FunctionTemplate::New(GLglTexEnvfvCallback));
	Gl->Set(v8::String::NewSymbol("texEnvi"), v8::FunctionTemplate::New(GLglTexEnviCallback));
	Gl->Set(v8::String::NewSymbol("texEnviv"), v8::FunctionTemplate::New(GLglTexEnvivCallback));
	Gl->Set(v8::String::NewSymbol("texGend"), v8::FunctionTemplate::New(GLglTexGendCallback));
	Gl->Set(v8::String::NewSymbol("texGendv"), v8::FunctionTemplate::New(GLglTexGendvCallback));
	Gl->Set(v8::String::NewSymbol("texGenf"), v8::FunctionTemplate::New(GLglTexGenfCallback));
	Gl->Set(v8::String::NewSymbol("texGenfv"), v8::FunctionTemplate::New(GLglTexGenfvCallback));
	Gl->Set(v8::String::NewSymbol("texGeni"), v8::FunctionTemplate::New(GLglTexGeniCallback));
	Gl->Set(v8::String::NewSymbol("texGeniv"), v8::FunctionTemplate::New(GLglTexGenivCallback));
	Gl->Set(v8::String::NewSymbol("texParameterf"), v8::FunctionTemplate::New(GLglTexParameterfCallback));
	Gl->Set(v8::String::NewSymbol("texParameterfv"), v8::FunctionTemplate::New(GLglTexParameterfvCallback));
	Gl->Set(v8::String::NewSymbol("texParameteri"), v8::FunctionTemplate::New(GLglTexParameteriCallback));
	Gl->Set(v8::String::NewSymbol("texParameteriv"), v8::FunctionTemplate::New(GLglTexParameterivCallback));
	Gl->Set(v8::String::NewSymbol("translated"), v8::FunctionTemplate::New(GLglTranslatedCallback));
	Gl->Set(v8::String::NewSymbol("translatef"), v8::FunctionTemplate::New(GLglTranslatefCallback));
	Gl->Set(v8::String::NewSymbol("vertex2d"), v8::FunctionTemplate::New(GLglVertex2dCallback));
	Gl->Set(v8::String::NewSymbol("vertex2dv"), v8::FunctionTemplate::New(GLglVertex2dvCallback));
	Gl->Set(v8::String::NewSymbol("vertex2f"), v8::FunctionTemplate::New(GLglVertex2fCallback));
	Gl->Set(v8::String::NewSymbol("vertex2fv"), v8::FunctionTemplate::New(GLglVertex2fvCallback));
	Gl->Set(v8::String::NewSymbol("vertex2i"), v8::FunctionTemplate::New(GLglVertex2iCallback));
	Gl->Set(v8::String::NewSymbol("vertex2iv"), v8::FunctionTemplate::New(GLglVertex2ivCallback));
	Gl->Set(v8::String::NewSymbol("vertex2s"), v8::FunctionTemplate::New(GLglVertex2sCallback));
	Gl->Set(v8::String::NewSymbol("vertex2sv"), v8::FunctionTemplate::New(GLglVertex2svCallback));
	Gl->Set(v8::String::NewSymbol("vertex3d"), v8::FunctionTemplate::New(GLglVertex3dCallback));
	Gl->Set(v8::String::NewSymbol("vertex3dv"), v8::FunctionTemplate::New(GLglVertex3dvCallback));
	Gl->Set(v8::String::NewSymbol("vertex3f"), v8::FunctionTemplate::New(GLglVertex3fCallback));
	Gl->Set(v8::String::NewSymbol("vertex3fv"), v8::FunctionTemplate::New(GLglVertex3fvCallback));
	Gl->Set(v8::String::NewSymbol("vertex3i"), v8::FunctionTemplate::New(GLglVertex3iCallback));
	Gl->Set(v8::String::NewSymbol("vertex3iv"), v8::FunctionTemplate::New(GLglVertex3ivCallback));
	Gl->Set(v8::String::NewSymbol("vertex3s"), v8::FunctionTemplate::New(GLglVertex3sCallback));
	Gl->Set(v8::String::NewSymbol("vertex3sv"), v8::FunctionTemplate::New(GLglVertex3svCallback));
	Gl->Set(v8::String::NewSymbol("vertex4d"), v8::FunctionTemplate::New(GLglVertex4dCallback));
	Gl->Set(v8::String::NewSymbol("vertex4dv"), v8::FunctionTemplate::New(GLglVertex4dvCallback));
	Gl->Set(v8::String::NewSymbol("vertex4f"), v8::FunctionTemplate::New(GLglVertex4fCallback));
	Gl->Set(v8::String::NewSymbol("vertex4fv"), v8::FunctionTemplate::New(GLglVertex4fvCallback));
	Gl->Set(v8::String::NewSymbol("vertex4i"), v8::FunctionTemplate::New(GLglVertex4iCallback));
	Gl->Set(v8::String::NewSymbol("vertex4iv"), v8::FunctionTemplate::New(GLglVertex4ivCallback));
	Gl->Set(v8::String::NewSymbol("vertex4s"), v8::FunctionTemplate::New(GLglVertex4sCallback));
	Gl->Set(v8::String::NewSymbol("vertex4sv"), v8::FunctionTemplate::New(GLglVertex4svCallback));
	Gl->Set(v8::String::NewSymbol("viewport"), v8::FunctionTemplate::New(GLglViewportCallback));
	Gl->Set(v8::String::NewSymbol("sampleCoverage"), v8::FunctionTemplate::New(GLglSampleCoverageCallback));
	Gl->Set(v8::String::NewSymbol("loadTransposeMatrixf"), v8::FunctionTemplate::New(GLglLoadTransposeMatrixfCallback));
	Gl->Set(v8::String::NewSymbol("loadTransposeMatrixd"), v8::FunctionTemplate::New(GLglLoadTransposeMatrixdCallback));
	Gl->Set(v8::String::NewSymbol("multTransposeMatrixf"), v8::FunctionTemplate::New(GLglMultTransposeMatrixfCallback));
	Gl->Set(v8::String::NewSymbol("multTransposeMatrixd"), v8::FunctionTemplate::New(GLglMultTransposeMatrixdCallback));
	Gl->Set(v8::String::NewSymbol("activeTexture"), v8::FunctionTemplate::New(GLglActiveTextureCallback));
	Gl->Set(v8::String::NewSymbol("clientActiveTexture"), v8::FunctionTemplate::New(GLglClientActiveTextureCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord1d"), v8::FunctionTemplate::New(GLglMultiTexCoord1dCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord1dv"), v8::FunctionTemplate::New(GLglMultiTexCoord1dvCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord1f"), v8::FunctionTemplate::New(GLglMultiTexCoord1fCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord1fv"), v8::FunctionTemplate::New(GLglMultiTexCoord1fvCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord1i"), v8::FunctionTemplate::New(GLglMultiTexCoord1iCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord1iv"), v8::FunctionTemplate::New(GLglMultiTexCoord1ivCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord1s"), v8::FunctionTemplate::New(GLglMultiTexCoord1sCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord1sv"), v8::FunctionTemplate::New(GLglMultiTexCoord1svCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord2d"), v8::FunctionTemplate::New(GLglMultiTexCoord2dCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord2dv"), v8::FunctionTemplate::New(GLglMultiTexCoord2dvCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord2f"), v8::FunctionTemplate::New(GLglMultiTexCoord2fCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord2fv"), v8::FunctionTemplate::New(GLglMultiTexCoord2fvCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord2i"), v8::FunctionTemplate::New(GLglMultiTexCoord2iCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord2iv"), v8::FunctionTemplate::New(GLglMultiTexCoord2ivCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord2s"), v8::FunctionTemplate::New(GLglMultiTexCoord2sCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord2sv"), v8::FunctionTemplate::New(GLglMultiTexCoord2svCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord3d"), v8::FunctionTemplate::New(GLglMultiTexCoord3dCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord3dv"), v8::FunctionTemplate::New(GLglMultiTexCoord3dvCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord3f"), v8::FunctionTemplate::New(GLglMultiTexCoord3fCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord3fv"), v8::FunctionTemplate::New(GLglMultiTexCoord3fvCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord3i"), v8::FunctionTemplate::New(GLglMultiTexCoord3iCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord3iv"), v8::FunctionTemplate::New(GLglMultiTexCoord3ivCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord3s"), v8::FunctionTemplate::New(GLglMultiTexCoord3sCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord3sv"), v8::FunctionTemplate::New(GLglMultiTexCoord3svCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord4d"), v8::FunctionTemplate::New(GLglMultiTexCoord4dCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord4dv"), v8::FunctionTemplate::New(GLglMultiTexCoord4dvCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord4f"), v8::FunctionTemplate::New(GLglMultiTexCoord4fCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord4fv"), v8::FunctionTemplate::New(GLglMultiTexCoord4fvCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord4iv"), v8::FunctionTemplate::New(GLglMultiTexCoord4ivCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord4s"), v8::FunctionTemplate::New(GLglMultiTexCoord4sCallback));
	Gl->Set(v8::String::NewSymbol("multiTexCoord4sv"), v8::FunctionTemplate::New(GLglMultiTexCoord4svCallback));
	Gl->Set(v8::String::NewSymbol("fogCoordf"), v8::FunctionTemplate::New(GLglFogCoordfCallback));
	Gl->Set(v8::String::NewSymbol("fogCoordfv"), v8::FunctionTemplate::New(GLglFogCoordfvCallback));
	Gl->Set(v8::String::NewSymbol("fogCoordd"), v8::FunctionTemplate::New(GLglFogCoorddCallback));
	Gl->Set(v8::String::NewSymbol("secondaryColor3b"), v8::FunctionTemplate::New(GLglSecondaryColor3bCallback));
	Gl->Set(v8::String::NewSymbol("secondaryColor3bv"), v8::FunctionTemplate::New(GLglSecondaryColor3bvCallback));
	Gl->Set(v8::String::NewSymbol("secondaryColor3d"), v8::FunctionTemplate::New(GLglSecondaryColor3dCallback));
	Gl->Set(v8::String::NewSymbol("secondaryColor3dv"), v8::FunctionTemplate::New(GLglSecondaryColor3dvCallback));
	Gl->Set(v8::String::NewSymbol("secondaryColor3f"), v8::FunctionTemplate::New(GLglSecondaryColor3fCallback));
	Gl->Set(v8::String::NewSymbol("secondaryColor3fv"), v8::FunctionTemplate::New(GLglSecondaryColor3fvCallback));
	Gl->Set(v8::String::NewSymbol("secondaryColor3i"), v8::FunctionTemplate::New(GLglSecondaryColor3iCallback));
	Gl->Set(v8::String::NewSymbol("secondaryColor3iv"), v8::FunctionTemplate::New(GLglSecondaryColor3ivCallback));
	Gl->Set(v8::String::NewSymbol("secondaryColor3s"), v8::FunctionTemplate::New(GLglSecondaryColor3sCallback));
	Gl->Set(v8::String::NewSymbol("secondaryColor3sv"), v8::FunctionTemplate::New(GLglSecondaryColor3svCallback));
	Gl->Set(v8::String::NewSymbol("secondaryColor3ub"), v8::FunctionTemplate::New(GLglSecondaryColor3ubCallback));
	Gl->Set(v8::String::NewSymbol("secondaryColor3ubv"), v8::FunctionTemplate::New(GLglSecondaryColor3ubvCallback));
	Gl->Set(v8::String::NewSymbol("secondaryColor3ui"), v8::FunctionTemplate::New(GLglSecondaryColor3uiCallback));
	Gl->Set(v8::String::NewSymbol("secondaryColor3uiv"), v8::FunctionTemplate::New(GLglSecondaryColor3uivCallback));
	Gl->Set(v8::String::NewSymbol("secondaryColor3us"), v8::FunctionTemplate::New(GLglSecondaryColor3usCallback));
	Gl->Set(v8::String::NewSymbol("secondaryColor3usv"), v8::FunctionTemplate::New(GLglSecondaryColor3usvCallback));
	Gl->Set(v8::String::NewSymbol("pointParameterf"), v8::FunctionTemplate::New(GLglPointParameterfCallback));
	Gl->Set(v8::String::NewSymbol("pointParameterfv"), v8::FunctionTemplate::New(GLglPointParameterfvCallback));
	Gl->Set(v8::String::NewSymbol("pointParameteri"), v8::FunctionTemplate::New(GLglPointParameteriCallback));
	Gl->Set(v8::String::NewSymbol("pointParameteriv"), v8::FunctionTemplate::New(GLglPointParameterivCallback));
	Gl->Set(v8::String::NewSymbol("blendFuncSeparate"), v8::FunctionTemplate::New(GLglBlendFuncSeparateCallback));
	Gl->Set(v8::String::NewSymbol("multiDrawArrays"), v8::FunctionTemplate::New(GLglMultiDrawArraysCallback));
	Gl->Set(v8::String::NewSymbol("windowPos2d"), v8::FunctionTemplate::New(GLglWindowPos2dCallback));
	Gl->Set(v8::String::NewSymbol("windowPos2dv"), v8::FunctionTemplate::New(GLglWindowPos2dvCallback));
	Gl->Set(v8::String::NewSymbol("windowPos2f"), v8::FunctionTemplate::New(GLglWindowPos2fCallback));
	Gl->Set(v8::String::NewSymbol("windowPos2fv"), v8::FunctionTemplate::New(GLglWindowPos2fvCallback));
	Gl->Set(v8::String::NewSymbol("windowPos2i"), v8::FunctionTemplate::New(GLglWindowPos2iCallback));
	Gl->Set(v8::String::NewSymbol("windowPos2iv"), v8::FunctionTemplate::New(GLglWindowPos2ivCallback));
	Gl->Set(v8::String::NewSymbol("windowPos2s"), v8::FunctionTemplate::New(GLglWindowPos2sCallback));
	Gl->Set(v8::String::NewSymbol("windowPos2sv"), v8::FunctionTemplate::New(GLglWindowPos2svCallback));
	Gl->Set(v8::String::NewSymbol("windowPos3d"), v8::FunctionTemplate::New(GLglWindowPos3dCallback));
	Gl->Set(v8::String::NewSymbol("windowPos3dv"), v8::FunctionTemplate::New(GLglWindowPos3dvCallback));
	Gl->Set(v8::String::NewSymbol("windowPos3f"), v8::FunctionTemplate::New(GLglWindowPos3fCallback));
	Gl->Set(v8::String::NewSymbol("windowPos3fv"), v8::FunctionTemplate::New(GLglWindowPos3fvCallback));
	Gl->Set(v8::String::NewSymbol("windowPos3i"), v8::FunctionTemplate::New(GLglWindowPos3iCallback));
	Gl->Set(v8::String::NewSymbol("windowPos3iv"), v8::FunctionTemplate::New(GLglWindowPos3ivCallback));
	Gl->Set(v8::String::NewSymbol("windowPos3s"), v8::FunctionTemplate::New(GLglWindowPos3sCallback));
	Gl->Set(v8::String::NewSymbol("windowPos3sv"), v8::FunctionTemplate::New(GLglWindowPos3svCallback));
	Gl->Set(v8::String::NewSymbol("genQueries"), v8::FunctionTemplate::New(GLglGenQueriesCallback));
	Gl->Set(v8::String::NewSymbol("deleteQueries"), v8::FunctionTemplate::New(GLglDeleteQueriesCallback));
	Gl->Set(v8::String::NewSymbol("isQuery"), v8::FunctionTemplate::New(GLglIsQueryCallback));
	Gl->Set(v8::String::NewSymbol("beginQuery"), v8::FunctionTemplate::New(GLglBeginQueryCallback));
	Gl->Set(v8::String::NewSymbol("endQuery"), v8::FunctionTemplate::New(GLglEndQueryCallback));
	Gl->Set(v8::String::NewSymbol("getQueryiv"), v8::FunctionTemplate::New(GLglGetQueryivCallback));
	Gl->Set(v8::String::NewSymbol("getQueryObjectiv"), v8::FunctionTemplate::New(GLglGetQueryObjectivCallback));
	Gl->Set(v8::String::NewSymbol("getQueryObjectuiv"), v8::FunctionTemplate::New(GLglGetQueryObjectuivCallback));
	Gl->Set(v8::String::NewSymbol("bindBuffer"), v8::FunctionTemplate::New(GLglBindBufferCallback));
	Gl->Set(v8::String::NewSymbol("deleteBuffers"), v8::FunctionTemplate::New(GLglDeleteBuffersCallback));
	Gl->Set(v8::String::NewSymbol("genBuffers"), v8::FunctionTemplate::New(GLglGenBuffersCallback));
	Gl->Set(v8::String::NewSymbol("isBuffer"), v8::FunctionTemplate::New(GLglIsBufferCallback));
	Gl->Set(v8::String::NewSymbol("unmapBuffer"), v8::FunctionTemplate::New(GLglUnmapBufferCallback));
	Gl->Set(v8::String::NewSymbol("getBufferParameteriv"), v8::FunctionTemplate::New(GLglGetBufferParameterivCallback));
	Gl->Set(v8::String::NewSymbol("drawBuffers"), v8::FunctionTemplate::New(GLglDrawBuffersCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib1d"), v8::FunctionTemplate::New(GLglVertexAttrib1dCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib1dv"), v8::FunctionTemplate::New(GLglVertexAttrib1dvCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib1f"), v8::FunctionTemplate::New(GLglVertexAttrib1fCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib1fv"), v8::FunctionTemplate::New(GLglVertexAttrib1fvCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib1s"), v8::FunctionTemplate::New(GLglVertexAttrib1sCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib1sv"), v8::FunctionTemplate::New(GLglVertexAttrib1svCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib2d"), v8::FunctionTemplate::New(GLglVertexAttrib2dCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib2dv"), v8::FunctionTemplate::New(GLglVertexAttrib2dvCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib2f"), v8::FunctionTemplate::New(GLglVertexAttrib2fCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib2fv"), v8::FunctionTemplate::New(GLglVertexAttrib2fvCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib2s"), v8::FunctionTemplate::New(GLglVertexAttrib2sCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib2sv"), v8::FunctionTemplate::New(GLglVertexAttrib2svCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib3d"), v8::FunctionTemplate::New(GLglVertexAttrib3dCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib3dv"), v8::FunctionTemplate::New(GLglVertexAttrib3dvCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib3f"), v8::FunctionTemplate::New(GLglVertexAttrib3fCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib3fv"), v8::FunctionTemplate::New(GLglVertexAttrib3fvCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib3s"), v8::FunctionTemplate::New(GLglVertexAttrib3sCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib3sv"), v8::FunctionTemplate::New(GLglVertexAttrib3svCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib4Nbv"), v8::FunctionTemplate::New(GLglVertexAttrib4NbvCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib4Niv"), v8::FunctionTemplate::New(GLglVertexAttrib4NivCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib4Nsv"), v8::FunctionTemplate::New(GLglVertexAttrib4NsvCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib4Nub"), v8::FunctionTemplate::New(GLglVertexAttrib4NubCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib4Nubv"), v8::FunctionTemplate::New(GLglVertexAttrib4NubvCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib4Nuiv"), v8::FunctionTemplate::New(GLglVertexAttrib4NuivCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib4Nusv"), v8::FunctionTemplate::New(GLglVertexAttrib4NusvCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib4bv"), v8::FunctionTemplate::New(GLglVertexAttrib4bvCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib4d"), v8::FunctionTemplate::New(GLglVertexAttrib4dCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib4dv"), v8::FunctionTemplate::New(GLglVertexAttrib4dvCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib4f"), v8::FunctionTemplate::New(GLglVertexAttrib4fCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib4fv"), v8::FunctionTemplate::New(GLglVertexAttrib4fvCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib4iv"), v8::FunctionTemplate::New(GLglVertexAttrib4ivCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib4s"), v8::FunctionTemplate::New(GLglVertexAttrib4sCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib4sv"), v8::FunctionTemplate::New(GLglVertexAttrib4svCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib4ubv"), v8::FunctionTemplate::New(GLglVertexAttrib4ubvCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib4uiv"), v8::FunctionTemplate::New(GLglVertexAttrib4uivCallback));
	Gl->Set(v8::String::NewSymbol("vertexAttrib4usv"), v8::FunctionTemplate::New(GLglVertexAttrib4usvCallback));
	Gl->Set(v8::String::NewSymbol("enableVertexAttribArray"), v8::FunctionTemplate::New(GLglEnableVertexAttribArrayCallback));
	Gl->Set(v8::String::NewSymbol("disableVertexAttribArray"), v8::FunctionTemplate::New(GLglDisableVertexAttribArrayCallback));
	Gl->Set(v8::String::NewSymbol("getVertexAttribdv"), v8::FunctionTemplate::New(GLglGetVertexAttribdvCallback));
	Gl->Set(v8::String::NewSymbol("getVertexAttribfv"), v8::FunctionTemplate::New(GLglGetVertexAttribfvCallback));
	Gl->Set(v8::String::NewSymbol("getVertexAttribiv"), v8::FunctionTemplate::New(GLglGetVertexAttribivCallback));
	Gl->Set(v8::String::NewSymbol("deleteShader"), v8::FunctionTemplate::New(GLglDeleteShaderCallback));
	Gl->Set(v8::String::NewSymbol("detachShader"), v8::FunctionTemplate::New(GLglDetachShaderCallback));
	Gl->Set(v8::String::NewSymbol("createShader"), v8::FunctionTemplate::New(GLglCreateShaderCallback));
	Gl->Set(v8::String::NewSymbol("compileShader"), v8::FunctionTemplate::New(GLglCompileShaderCallback));
	Gl->Set(v8::String::NewSymbol("createProgram"), v8::FunctionTemplate::New(GLglCreateProgramCallback));
	Gl->Set(v8::String::NewSymbol("attachShader"), v8::FunctionTemplate::New(GLglAttachShaderCallback));
	Gl->Set(v8::String::NewSymbol("linkProgram"), v8::FunctionTemplate::New(GLglLinkProgramCallback));
	Gl->Set(v8::String::NewSymbol("useProgram"), v8::FunctionTemplate::New(GLglUseProgramCallback));
	Gl->Set(v8::String::NewSymbol("deleteProgram"), v8::FunctionTemplate::New(GLglDeleteProgramCallback));
	Gl->Set(v8::String::NewSymbol("validateProgram"), v8::FunctionTemplate::New(GLglValidateProgramCallback));
	Gl->Set(v8::String::NewSymbol("uniform1f"), v8::FunctionTemplate::New(GLglUniform1fCallback));
	Gl->Set(v8::String::NewSymbol("uniform2f"), v8::FunctionTemplate::New(GLglUniform2fCallback));
	Gl->Set(v8::String::NewSymbol("uniform3f"), v8::FunctionTemplate::New(GLglUniform3fCallback));
	Gl->Set(v8::String::NewSymbol("uniform4f"), v8::FunctionTemplate::New(GLglUniform4fCallback));
	Gl->Set(v8::String::NewSymbol("uniform1i"), v8::FunctionTemplate::New(GLglUniform1iCallback));
	Gl->Set(v8::String::NewSymbol("uniform2i"), v8::FunctionTemplate::New(GLglUniform2iCallback));
	Gl->Set(v8::String::NewSymbol("uniform3i"), v8::FunctionTemplate::New(GLglUniform3iCallback));
	Gl->Set(v8::String::NewSymbol("uniform4i"), v8::FunctionTemplate::New(GLglUniform4iCallback));
	Gl->Set(v8::String::NewSymbol("uniform1fv"), v8::FunctionTemplate::New(GLglUniform1fvCallback));
	Gl->Set(v8::String::NewSymbol("uniform2fv"), v8::FunctionTemplate::New(GLglUniform2fvCallback));
	Gl->Set(v8::String::NewSymbol("uniform3fv"), v8::FunctionTemplate::New(GLglUniform3fvCallback));
	Gl->Set(v8::String::NewSymbol("uniform4fv"), v8::FunctionTemplate::New(GLglUniform4fvCallback));
	Gl->Set(v8::String::NewSymbol("uniform1iv"), v8::FunctionTemplate::New(GLglUniform1ivCallback));
	Gl->Set(v8::String::NewSymbol("uniform2iv"), v8::FunctionTemplate::New(GLglUniform2ivCallback));
	Gl->Set(v8::String::NewSymbol("uniform3iv"), v8::FunctionTemplate::New(GLglUniform3ivCallback));
	Gl->Set(v8::String::NewSymbol("uniform4iv"), v8::FunctionTemplate::New(GLglUniform4ivCallback));
	Gl->Set(v8::String::NewSymbol("uniformMatrix2fv"), v8::FunctionTemplate::New(GLglUniformMatrix2fvCallback));
	Gl->Set(v8::String::NewSymbol("uniformMatrix3fv"), v8::FunctionTemplate::New(GLglUniformMatrix3fvCallback));
	Gl->Set(v8::String::NewSymbol("uniformMatrix4fv"), v8::FunctionTemplate::New(GLglUniformMatrix4fvCallback));
	Gl->Set(v8::String::NewSymbol("isShader"), v8::FunctionTemplate::New(GLglIsShaderCallback));
	Gl->Set(v8::String::NewSymbol("isProgram"), v8::FunctionTemplate::New(GLglIsProgramCallback));
	Gl->Set(v8::String::NewSymbol("getShaderiv"), v8::FunctionTemplate::New(GLglGetShaderivCallback));
	Gl->Set(v8::String::NewSymbol("getProgramiv"), v8::FunctionTemplate::New(GLglGetProgramivCallback));
	Gl->Set(v8::String::NewSymbol("getAttachedShaders"), v8::FunctionTemplate::New(GLglGetAttachedShadersCallback));
	Gl->Set(v8::String::NewSymbol("getUniformfv"), v8::FunctionTemplate::New(GLglGetUniformfvCallback));
	Gl->Set(v8::String::NewSymbol("getUniformiv"), v8::FunctionTemplate::New(GLglGetUniformivCallback));
	Gl->Set(v8::String::NewSymbol("stencilFuncSeparate"), v8::FunctionTemplate::New(GLglStencilFuncSeparateCallback));
	Gl->Set(v8::String::NewSymbol("stencilOpSeparate"), v8::FunctionTemplate::New(GLglStencilOpSeparateCallback));
	Gl->Set(v8::String::NewSymbol("stencilMaskSeparate"), v8::FunctionTemplate::New(GLglStencilMaskSeparateCallback));
	Gl->Set(v8::String::NewSymbol("uniformMatrix2x3fv"), v8::FunctionTemplate::New(GLglUniformMatrix2x3fvCallback));
	Gl->Set(v8::String::NewSymbol("uniformMatrix3x2fv"), v8::FunctionTemplate::New(GLglUniformMatrix3x2fvCallback));
	Gl->Set(v8::String::NewSymbol("uniformMatrix2x4fv"), v8::FunctionTemplate::New(GLglUniformMatrix2x4fvCallback));
	Gl->Set(v8::String::NewSymbol("uniformMatrix4x2fv"), v8::FunctionTemplate::New(GLglUniformMatrix4x2fvCallback));
	Gl->Set(v8::String::NewSymbol("uniformMatrix3x4fv"), v8::FunctionTemplate::New(GLglUniformMatrix3x4fvCallback));
	Gl->Set(v8::String::NewSymbol("uniformMatrix4x3fv"), v8::FunctionTemplate::New(GLglUniformMatrix4x3fvCallback));


	return scope.Close(Gl);

}    


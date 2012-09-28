
#include "webgl.h"

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
#else
	#define GL_GLEXT_PROTOTYPES
	#include <GL/gl.h>
#endif


/*
 * WebGL 1.0
 *
 * The WebGL bindings were implemented following the spec document available here:
 * http://www.khronos.org/registry/webgl/specs/1.0/
 */



namespace binding {

	v8::Handle<v8::Value> WEBGL::handleCreateBuffer(const v8::Arguments& args) {

		GLuint buffer;
		glGenBuffers(1, &buffer);

		return v8::Uint32::New(buffer);

	}

	v8::Handle<v8::Value> WEBGL::handleCreateFramebuffer(const v8::Arguments& args) {

		// TODO
		return v8::Uint32::New(0);

	}

	v8::Handle<v8::Value> WEBGL::handleCreateRenderbuffer(const v8::Arguments& args) {

		// TODO
		return v8::Uint32::New(0);

	}


	v8::Handle<v8::Value> WEBGL::handleCreateTexture(const v8::Arguments& args) {

		GLuint texture;
		glGenTextures(1, &texture);

		return v8::Uint32::New(texture);

	}

	v8::Handle<v8::Value> WEBGL::handleDeleteBuffer(const v8::Arguments& args) {

		if (args.Length() == 1) {

			unsigned int buffer = args[0]->Uint32Value();

			GLuint* buffers = new GLuint[1];
			buffers[0] = (GLuint) buffer;

			glDeleteBuffers((GLsizei) 1, (const GLuint*) buffers);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> WEBGL::handleDeleteFramebuffer(const v8::Arguments& args) {
		// TODO
		return v8::Undefined();
	}

	v8::Handle<v8::Value> WEBGL::handleDeleteRenderbuffer(const v8::Arguments& args) {
		// TODO
		return v8::Undefined();
	}

	v8::Handle<v8::Value> WEBGL::handleDeleteTexture(const v8::Arguments& args) {

		if (args.Length() == 1) {

			unsigned int texture = args[0]->Uint32Value();

			GLuint* textures = new GLuint[1];
			textures[0] = (GLuint) texture;

			glDeleteTextures((GLsizei) 1, (const GLuint*) textures);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> WEBGL::handleDrawElements(const v8::Arguments& args) {
		// TODO
		return v8::Undefined();
	}

	v8::Handle<v8::Value> WEBGL::handleFramebufferRenderbuffer(const v8::Arguments& args) {
		// TODO
		return v8::Undefined();
	}

	v8::Handle<v8::Value> WEBGL::handleFramebufferTexture2D(const v8::Arguments& args) {
		// TODO
		return v8::Undefined();
	}

	v8::Handle<v8::Value> WEBGL::handleGenerateMipmap(const v8::Arguments& args) {

		if (args.Length() == 1) {

			int target = args[0]->IntegerValue();

			glGenerateMipmap((GLenum) target);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> WEBGL::handleGetActiveAttrib(const v8::Arguments& args) {

		// TODO
		// See: http://www.opengl.org/sdk/docs/man/xhtml/glGetActiveAttrib.xml

		// if (args.Length() == 2) {

		// 	unsigned int program = args[0]->Uint32Value();
		// 	unsigned int index   = args[1]->Uint32Value();

		// }

		return v8::Undefined();

	}

	v8::Handle<v8::Value> WEBGL::handleGetActiveUniform(const v8::Arguments& args) {

		// TODO
		// See: http://www.opengl.org/sdk/docs/man/xhtml/glGetActiveUniform.xml

		// if (args.Length() == 2) {

		// 	unsigned int program = args[0]->Uint32Value();
		// 	unsigned int index   = args[1]->Uint32Value();

		// }

		return v8::Undefined();

	}

	v8::Handle<v8::Value> WEBGL::handleGetAttachedShaders(const v8::Arguments& args) {

		if (args.Length() == 1) {

			unsigned int program = args[0]->Uint32Value();

			GLint maxCount = (GLint) 0;
			glGetProgramiv((GLuint) program, GL_ATTACHED_SHADERS, &maxCount);


			GLsizei count = (GLsizei) 0;
			GLuint* shaders = new GLuint[(int) maxCount];

			glGetAttachedShaders(
				(GLuint) program, (GLsizei) maxCount,
				&count, shaders
			);


			v8::Handle<v8::Array> result = v8::Array::New((int)count);

			for (int i = 0; i < (int)count; i++) {
				result->Set(v8::Integer::New(i), v8::Uint32::New((unsigned int) shaders[i]));
			}

			return result;

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> WEBGL::handleShaderSource(const v8::Arguments& args) {

		if (args.Length() == 2) {

			GLuint shader = args[0]->Uint32Value();

			v8::String::Utf8Value source_str(args[1]);
			const GLchar *source = *source_str;

			GLint length = source_str.length();

			glShaderSource(shader, 1, &source, &length);

		}

		return v8::Undefined();

	}

}
 


#include "gles.h"

#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>


/*
 * GLES Bindings 2.0
 *
 *
 * These bindings were implemented following the headers available in 
 * Android API Level 14 (Android v4.1 Jelly Bean) and the GLESv2 library.
 *
 */



namespace binding {

	v8::Handle<v8::Value> GLES::handleEnable(const v8::Arguments& args) {

		if (args.Length() == 1) {

			int state = args[0]->IntegerValue();
			glEnable(state);

		}

		return v8::Undefined();

	}


	v8::Handle<v8::ObjectTemplate> GLES::generate() {

		v8::HandleScope scope;

		v8::Handle<v8::ObjectTemplate> glestpl = v8::ObjectTemplate::New();


		/* Type Definitions */
		glestpl->Set(v8::String::NewSymbol("FLOAT"), v8::Uint32::New(GL_FLOAT));

		/* Begin Modes */
		glestpl->Set(v8::String::NewSymbol("TRIANGLES"), v8::Uint32::New(GL_TRIANGLES));
		glestpl->Set(v8::String::NewSymbol("TRIANGLE_STRIP"), v8::Uint32::New(GL_TRIANGLE_STRIP));
		glestpl->Set(v8::String::NewSymbol("TRIANGLE_FAN"), v8::Uint32::New(GL_TRIANGLE_FAN));

		/* Methods */
		glestpl->Set(v8::String::NewSymbol("enable"), v8::FunctionTemplate::New(GLES::handleEnable));


		return scope.Close(glestpl);

	}

}


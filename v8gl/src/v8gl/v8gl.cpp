
#include <limits.h>
#include <string.h>
#include <fstream>

#include "v8gl.h"

#ifdef __ANDROID__

	#include "../binding/gles.h"
//	#include "../binding/glues.h"

#else

	#include "../binding/gl/glbind.h"
	#include "../binding/glu.h"
	#include "../binding/glut.h"

#endif


#include "../api/console.h"
#include "../api/navigator.h"
#include "../api/script.h"
#include "../api/text.h"
#include "../api/texture.h"


// Advanced @built-in JavaScript headers
#include "../js/interval.h"
#include "../js/timeout.h"

#include "../../lib/raw/lychee_core_js.h"
#include "../../lib/raw/lychee_Builder_js.h"
#include "../../lib/raw/lychee_Preloader_js.h"



namespace v8gl {

	bool V8GL::_v8gl_targeted = true;


	v8::Persistent<v8::Context> V8GL::initialize(int* pargc, char** argv) {

		v8::Local<v8::ObjectTemplate> global = v8::ObjectTemplate::New();

#ifdef __ANDROID__

		global->Set(v8::String::New("gl"), binding::GLES::generate());

		// TODO: GLUES port and freeglut android port
		// global->Set(v8::String::New("glu"), binding::GLUES::generate());
		// global->Set(v8::String::New("glut"), binding::GLUT::generate());

#else

		// GL/GLU/GLUT Bindings
		v8::Handle<v8::ObjectTemplate> Gl = GlFactory::createGl();
		global->Set(v8::String::New("gl"), Gl);
		global->Set(v8::String::New("glu"), binding::GLU::generate());
		global->Set(v8::String::New("glut"), binding::GLUT::generate(pargc, argv));

#endif

		// Console API
		global->Set(v8::String::New("console"), api::Console::generate());


		// Advanced Data Types
		global->Set(v8::String::New("Script"), api::Script::generate(), v8::ReadOnly);
		global->Set(v8::String::New("Text"), api::Text::generate(), v8::ReadOnly);
		global->Set(v8::String::New("Texture"), api::Texture::generate(), v8::ReadOnly);


		// Navigator API
		global->Set(v8::String::New("navigator"), api::Navigator::generate(), v8::ReadOnly);


		v8::Persistent<v8::Context> context = v8::Context::New(NULL, global);

		context->AllowCodeGenerationFromStrings(false);

#ifndef __ANDROID__
// FIXME: This crap needs to be all removed.

		v8::HandleScope scope;
		context->Enter();
		GlFactory::self_ = v8::Persistent<v8::Object>::New(Gl->NewInstance());
		context->Exit();

// END of removal
#endif

		return context;

	}


	bool V8GL::dispatch(v8::Handle<v8::Context> context, char* what) {

		// @built-in Polyfills for BOM/DOM like behaviours
		execute(context, v8::String::New((char*) js_interval_js), v8::String::New("@built-in/interval.js"));
		execute(context, v8::String::New((char*) js_timeout_js), v8::String::New("@built-in/timeout.js"));

		// @built-in lycheeJS libraries for communication between Engine & ADK and/or V8GL
		execute(context, v8::String::New((char*) lychee_core_js), v8::String::New("@built-in/lychee/core.js"));
		execute(context, v8::String::New((char*) lychee_Builder_js), v8::String::New("@built-in/lychee/Builder.js"));
		execute(context, v8::String::New((char*) lychee_platform_v8gl_Preloader_js), v8::String::New("@built-in/lychee/platform/v8gl/Preloader.js"));


		return true;

	}



	v8::Handle<v8::Value> V8GL::execute(v8::Handle<v8::Context> context, v8::Handle<v8::String> source, v8::Handle<v8::String> filename) {

		context->Enter();

		v8::HandleScope scope;
		v8::TryCatch try_catch;

		v8::Local<v8::Script> script = v8::Script::Compile(source, filename);
		v8::Handle<v8::Value> value;
		if (script.IsEmpty()) {

			V8GL::logException(&try_catch);
			value = v8::Null();

		} else {

			v8::Handle<v8::Value> result = script->Run();
			if (result.IsEmpty()) {

				// assert(try_catch.HasCaught());
				V8GL::logException(&try_catch);
				value = v8::Null();

            } else if (result->IsUndefined()) {

				value = v8::Undefined();

			} else {

				value = result;

			}

		}


		context->Exit();
		return scope.Close(value);

	}



	void V8GL::logException(v8::TryCatch* try_catch) {

		v8::HandleScope scope;

		v8::String::Utf8Value exception(try_catch->Exception());

		const char* exception_string = *exception;
		v8::Handle<v8::Message> message = try_catch->Message();

		fprintf(stderr, "\n");

		if (message.IsEmpty()) {

			fprintf(stderr, "%s\n", exception_string);

		} else {

			// Print (filename):(line number): (message).
			v8::String::Utf8Value filename(message->GetScriptResourceName());
			const char* filename_string = *filename;
			int linenum = message->GetLineNumber();
			fprintf(stderr, "%s:%i: %s\n", filename_string, linenum, exception_string);

			// Print line of source code.
			v8::String::Utf8Value sourceline(message->GetSourceLine());
			const char* sourceline_string = *sourceline;
			fprintf(stderr, "%s\n", sourceline_string);

			// Print wavy underline (GetUnderline is deprecated).
			int start = message->GetStartColumn();
			for (int i = 0; i < start; i++) {
				fprintf(stderr, "~");
			}

			int end = message->GetEndColumn();
			for (int i = start; i < end; i++) {
				fprintf(stderr, "^");
			}

			fprintf(stderr, "\n");


			v8::String::Utf8Value stack_trace(try_catch->StackTrace());
			if (stack_trace.length() > 0) {
				const char* stack_trace_string = *stack_trace;
				fprintf(stderr, "%s\n", stack_trace_string);
			}

		}

	}


	char* V8GL::read(char* filename) {

		FILE* file = fopen(filename, "rb");
		if (file == NULL) {
			return NULL;
		}


		fseek(file, 0, SEEK_END);
		int size = ftell(file);
		rewind(file);


		char* chars = new char[size + 1];
		chars[size] = '\0';

		for (int i = 0; i < size; ) {
			int read = static_cast<int>(fread(&chars[i], 1, size - i, file));
			i += read;
		}

		fclose(file);

		return chars;

	}


}


#include <string.h>

#include "v8gl.h"

#include "../lib/fs.h"
#include "../lib/os.h"

#include "../api/arraybuffer.h"
#include "../api/navigator.h"
#include "../api/script.h"
#include "../api/text.h"
#include "../api/texture.h"


// Advanced @built-in JavaScript headers
#include "../js/console.h"
#include "../js/interval.h"
#include "../js/timeout.h"

#include "../../lib/raw/lychee_core_js.h"
#include "../../lib/raw/lychee_Builder_js.h"
#include "../../lib/raw/lychee_Preloader_js.h"



namespace v8gl {

	bool V8GL::_v8gl_targeted = true;


	v8::Persistent<v8::Context> V8GL::initialize(int* pargc, char** argv) {

		v8::Local<v8::ObjectTemplate> global = v8::ObjectTemplate::New();


		// Static APIs
		global->Set(v8::String::New("fs"),        lib::FS::generate(),        v8::ReadOnly);
		global->Set(v8::String::New("os"),        lib::OS::generate(),        v8::ReadOnly);
		global->Set(v8::String::New("navigator"), api::Navigator::generate(), v8::ReadOnly);


		v8::Persistent<v8::Context> context = v8::Context::New(NULL, global);

		context->AllowCodeGenerationFromStrings(false);

		context->Enter();


		// Dynamic APIs
		context->Global()->Set(v8::String::New("ArrayBuffer"), api::ArrayBuffer::generate()->GetFunction(), v8::ReadOnly);
		context->Global()->Set(v8::String::New("Script"),  api::Script::generate()->GetFunction(),  v8::ReadOnly);
		context->Global()->Set(v8::String::New("Text"),    api::Text::generate()->GetFunction(),    v8::ReadOnly);
		context->Global()->Set(v8::String::New("Texture"), api::Texture::generate()->GetFunction(), v8::ReadOnly);


		context->Exit();


		return context;

	}


	bool V8GL::dispatch(v8::Handle<v8::Context> context, char* what) {

		// @built-in Polyfills for BOM/DOM like behaviours
		execute(context, v8::String::New((char*) js_console_js),  v8::String::New("@built-in/console.js"));
		execute(context, v8::String::New((char*) js_interval_js), v8::String::New("@built-in/interval.js"));
		execute(context, v8::String::New((char*) js_timeout_js),  v8::String::New("@built-in/timeout.js"));

		// @built-in lycheeJS libraries for communication between Engine & ADK and/or V8GL
		execute(context, v8::String::New((char*) lychee_core_js), v8::String::New("@built-in/lychee/core.js"));
		execute(context, v8::String::New((char*) lychee_Builder_js), v8::String::New("@built-in/lychee/Builder.js"));
		execute(context, v8::String::New((char*) lychee_platform_v8gl_Preloader_js), v8::String::New("@built-in/lychee/platform/v8gl/Preloader.js"));


		if (strcmp(what, "export-bash") == 0) {

			context->Enter();

			v8::Handle<v8::Object> lychee = context->Global()->Get(v8::String::New("lychee"))->ToObject();
			lychee->Set(v8::String::New("build"), v8::FunctionTemplate::New(V8GL::handleBuildExportBash)->GetFunction());

			context->Exit();

			return true;

		} else if (strcmp(what, "export-json") == 0) {

			context->Enter();

			v8::Handle<v8::Object> lychee = context->Global()->Get(v8::String::New("lychee"))->ToObject();
			lychee->Set(v8::String::New("build"), v8::FunctionTemplate::New(V8GL::handleBuildExportJSON)->GetFunction());

			context->Exit();

			return true;

		} else if (strcmp(what, "rewrite-v8gl") == 0) {

			V8GL::_v8gl_targeted = true;

			context->Enter();

			v8::Handle<v8::Object> lychee = context->Global()->Get(v8::String::New("lychee"))->ToObject();
			lychee->Set(v8::String::New("build"), v8::FunctionTemplate::New(V8GL::handleBuildRewrite)->GetFunction());

			context->Exit();

			return true;

		} else if (strcmp(what, "rewrite") == 0) {

			context->Enter();

			V8GL::_v8gl_targeted = false;

			v8::Handle<v8::Object> lychee = context->Global()->Get(v8::String::New("lychee"))->ToObject();
			lychee->Set(v8::String::New("build"), v8::FunctionTemplate::New(V8GL::handleBuildRewrite)->GetFunction());

			context->Exit();

			return true;

		}


		return false;

	}



	v8::Handle<v8::Value> V8GL::executeVM(v8::Handle<v8::Context> context, v8::Handle<v8::String> source, v8::Handle<v8::String> filename) {

		char* filepath = *v8::String::Utf8Value(filename);

		char *old_root = lib::FS::pushVMRoot(filepath);
		v8::Handle<v8::Value> result = V8GL::execute(context, source, filename);
		lib::FS::popVMRoot(old_root);

		delete old_root;

		return result;

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



	v8::Handle<v8::Value> V8GL::handleBuildExportJSON(const v8::Arguments& args) {

		v8::HandleScope scope;
		v8::Local<v8::Object> self = args.Holder();
		v8::Persistent<v8::Context> context(self->CreationContext());


		v8::Handle<v8::Value> result = V8GL::execute(context, v8::String::New("JSON.stringify(lychee.getEnvironment())"), v8::String::New("@runtime"));

		fprintf(stdout, "%s", (char*) *(v8::String::Utf8Value(result)));


		return scope.Close(v8::String::New(""));

	}

	v8::Handle<v8::Value> V8GL::handleBuildRewrite(const v8::Arguments& args) {

		v8::HandleScope scope;
		v8::Persistent<v8::Context> context(args.Holder()->CreationContext());

		v8::Handle<v8::Value> lychee_debug = V8GL::execute(context, v8::String::New("!!lychee.debug"), v8::String::New("@runtime"));
		v8::Handle<v8::Object> env = V8GL::execute(context, v8::String::New("lychee.getEnvironment();"), v8::String::New("@runtime"))->ToObject();

		if (V8GL::_v8gl_targeted == false) {
			// TODO: Modify platform to [ 'webgl', 'html' ] when lycheeJS webgl stack is ready.
			env->Get(v8::String::New("tags"))->ToObject()->Set(v8::String::New("platform"), v8::String::New("html"));
		}


		context->Enter();

		v8::Local<v8::Object> env_bases_old = env->Get(v8::String::New("bases"))->ToObject();
		v8::Local<v8::Object> env_tags = env->Get(v8::String::New("tags"))->ToObject();
		v8::Local<v8::Object> env_bases = v8::Object::New();


		v8::Local<v8::Array> env_bases_old_props = env_bases_old->GetPropertyNames();
		for (uint32_t i = 0; i < env_bases_old_props->Length(); i++) {

			v8::Local<v8::Value> key = env_bases_old_props->Get(i);
			v8::String::Utf8Value key_value(key);

			char value[100] = "./js/";
			strcat(value, *key_value);

			env_bases->Set(v8::String::New(*key_value), v8::String::New(value));

		}



		v8::Handle<v8::Object> JSON = context->Global()->Get(v8::String::New("JSON"))->ToObject();
		v8::Handle<v8::Function> JSON_stringify = v8::Handle<v8::Function>::Cast(JSON->Get(v8::String::New("stringify")));


		v8::Handle<v8::Value> args_0[1];
		args_0[0] = env_bases;

		v8::String::Utf8Value str_env_bases(JSON_stringify->Call(JSON, 1, args_0));


		v8::Handle<v8::Value> args_1[1];
		args_1[0] = env_tags;

		v8::String::Utf8Value str_env_tags(JSON_stringify->Call(JSON, 1, args_1));

		v8::Handle<v8::Function> callback = v8::Handle<v8::Function>::Cast(args[0]);
		v8::String::Utf8Value str_callback(callback->ToString());

		// api::Console::debug(args.Holder()->CreationContext(), env_bases);




		char code[1000] = "\n";

		if (lychee_debug == v8::True()) {
			strcat(code, "// This file is automatically generated by the lycheeJS-ADK.\n");
			strcat(code, "lychee.debug = true;");
		}

		strcat(code, "\nlychee.rebase(");
		strcat(code, *str_env_bases);
		strcat(code, ");");

		strcat(code, "\nlychee.tag(");
		strcat(code, *str_env_tags);
		strcat(code, ");\n");

		strcat(code, "\nlychee.build(");
		strcat(code, *str_callback);
		strcat(code, ");\n");

		fprintf(stdout, "%s\n", code);


		context->Exit();

		return scope.Close(v8::True());

	}

	v8::Handle<v8::Value> V8GL::handleBuildExportBash(const v8::Arguments& args) {

		const char *code = "\
			var env = lychee.getEnvironment();\
			\
			console.log(\"declare -A env_bases;\");\
			for (var base in env.bases) {\
				console.log(\"env_bases[\\\"\" + base + \"\\\"]=\\\"\" + env.bases[base] + \"\\\";\");\
			}\
			\
			console.log(\"declare -A env_tags;\");\
			for (var tag in env.tags) {\
				console.log(\"env_tags[\\\"\" + tag + \"\\\"]=\\\"\" + env.tags[tag] + \"\\\";\");\
			}\
		";


		v8::HandleScope scope;
		v8::Persistent<v8::Context> context(args.Holder()->CreationContext());

		V8GL::execute(context, v8::String::New(code), v8::String::New("@runtime"));

		return scope.Close(v8::String::New(""));

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

}

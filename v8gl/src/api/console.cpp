
#include "console.h"
#include "../v8gl/v8gl.h"


namespace api {

	int consoleMargin = 0;

	v8::Handle<v8::ObjectTemplate> Console::generate() {

		v8::Handle<v8::ObjectTemplate> tpl = v8::ObjectTemplate::New();

		tpl->Set(v8::String::New("debug"),    v8::FunctionTemplate::New(Console::handleDebug),    v8::ReadOnly);
		tpl->Set(v8::String::New("log"),      v8::FunctionTemplate::New(Console::handleLog),      v8::ReadOnly);
		tpl->Set(v8::String::New("warn"),     v8::FunctionTemplate::New(Console::handleWarn),     v8::ReadOnly);
		tpl->Set(v8::String::New("error"),    v8::FunctionTemplate::New(Console::handleError),    v8::ReadOnly);
		tpl->Set(v8::String::New("group"),    v8::FunctionTemplate::New(Console::handleGroup),    v8::ReadOnly);
		tpl->Set(v8::String::New("groupEnd"), v8::FunctionTemplate::New(Console::handleGroupEnd), v8::ReadOnly);

		return tpl;

	}

	v8::Handle<v8::Value> Console::debug(v8::Handle<v8::Context> context, v8::Handle<v8::Value> data) {

		v8::Handle<v8::Object> console = context->Global()->Get(v8::String::New("console"))->ToObject();
		v8::Handle<v8::Function> console_debug = v8::Handle<v8::Function>::Cast(console->Get(v8::String::New("debug")));

		v8::Handle<v8::Value> args[1];
		args[0] = data;

		return console_debug->Call(console, 1, args);

	}

	v8::Handle<v8::Value> Console::handleDebug(const v8::Arguments& args) {

		if (args.Length() < 1) {
			return v8::Undefined();
		}

		v8::HandleScope scope;
		v8::Local<v8::Object> self = args.Holder();
		v8::Persistent<v8::Context> context(self->CreationContext());

		context->Enter();

		v8::Handle<v8::Object> JSON = context->Global()->Get(v8::String::New("JSON"))->ToObject();
		v8::Handle<v8::Function> JSON_stringify = v8::Handle<v8::Function>::Cast(JSON->Get(v8::String::New("stringify")));
		

		for (signed a = 0; a < args.Length(); a++) {

			for (int m = 0; m < consoleMargin; m++) {
				fprintf(stdout, "\t");
			}

			v8::Handle<v8::Value> passargs[1];
			passargs[0] = args[a];

			v8::String::Utf8Value value(JSON_stringify->Call(JSON, 1, passargs));
			char* message = *value;

			fprintf(stdout, "%s\n", message);

		}

		context->Exit();

		return scope.Close(v8::Undefined());

	}

	v8::Handle<v8::Value> Console::handleLog(const v8::Arguments& args) {

		v8::HandleScope scope;

		if (args.Length() < 1) {
			return scope.Close(v8::Undefined());
		}


		for (int m = 0; m < consoleMargin; m++) {
			fprintf(stdout, "\t");
		}

		for (signed a = 0; a < args.Length(); a++) {

			v8::String::Utf8Value value(args[a]);
			char* message = *value;

			fprintf(stdout, "%s", message);

			if (args.Length() > 1 && a < (args.Length() - 1)) {
				fprintf(stdout, " | ");
			}

		}

		fprintf(stdout, "\n");


		return scope.Close(v8::Undefined());
	 
	}



	v8::Handle<v8::Value> Console::handleWarn(const v8::Arguments& args) {

		fprintf(stdout, "(w)");
		return handleLog(args);

	}

	v8::Handle<v8::Value> Console::handleError(const v8::Arguments& args) {

		fprintf(stdout, "(e)");
		return handleLog(args);

	}

	v8::Handle<v8::Value> Console::handleGroup(const v8::Arguments& args) {

		fprintf(stdout, "\n");

		v8::String::Utf8Value value(args[0]);
		char* label = *value;


		for (int m = 0; m < consoleMargin; m++) {
			fprintf(stdout, "\t");
		}


		fprintf(stdout, "~ %s ~\n", label);

		consoleMargin++;


		return v8::Undefined();

	}

	v8::Handle<v8::Value> Console::handleGroupEnd(const v8::Arguments& args) {

		consoleMargin--;

		for (int m = 0; m < consoleMargin; m++) {
			fprintf(stdout, "\t");
		}

		fprintf(stdout, "~ (end) ~\n\n");


		return v8::Undefined();

	}

}


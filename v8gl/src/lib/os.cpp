
#include "os.h"

#ifdef __ANDROID__

	#include <android/log.h>

#endif


namespace lib {

	v8::Handle<v8::ObjectTemplate> OS::generate() {

		v8::Handle<v8::ObjectTemplate> tpl = v8::ObjectTemplate::New();

		tpl->Set(v8::String::NewSymbol("log"),   v8::FunctionTemplate::New(OS::handleLog),   v8::ReadOnly);
		tpl->Set(v8::String::NewSymbol("warn"),  v8::FunctionTemplate::New(OS::handleWarn),  v8::ReadOnly);
		tpl->Set(v8::String::NewSymbol("error"), v8::FunctionTemplate::New(OS::handleError), v8::ReadOnly);

		return tpl;

	}

	v8::Handle<v8::Value> OS::handleLog(const v8::Arguments& args) {

		v8::HandleScope scope;

		if (args.Length() == 1) {
			v8::String::Utf8Value message(args[0]->ToString());
			OS::log(*message);
		}

		return scope.Close(v8::Undefined());

	}

	v8::Handle<v8::Value> OS::handleWarn(const v8::Arguments& args) {

		v8::HandleScope scope;

		if (args.Length() == 1) {
			v8::String::Utf8Value message(args[0]->ToString());
			OS::warn(*message);
		}

		return scope.Close(v8::Undefined());

	}

	v8::Handle<v8::Value> OS::handleError(const v8::Arguments& args) {

		v8::HandleScope scope;

		if (args.Length() == 1) {
			v8::String::Utf8Value message(args[0]->ToString());
			OS::error(*message);
		}

		return scope.Close(v8::Undefined());

	}

	void OS::log(char* message) {

#ifdef __ANDROID__
		__android_log_write(ANDROID_LOG_INFO, "ms.martens.v8gl", message);
#else
		fprintf(stdout, "%s\n", message);
#endif

	}

	void OS::warn(char* message) {

#ifdef __ANDROID__
		__android_log_write(ANDROID_LOG_WARN, "ms.martens.v8gl", message);
#else
		fprintf(stdout, "(w) %s\n", message);
#endif

	}

	void OS::error(char* message) {

#ifdef __ANDROID__
		__android_log_write(ANDROID_LOG_ERROR, "ms.martens.v8gl", message);
#else
		fprintf(stderr, "(e) %s\n", message);
#endif

	}

} 

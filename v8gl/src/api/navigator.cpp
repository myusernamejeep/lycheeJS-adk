
#include "navigator.h"


namespace api {

	v8::Handle<v8::ObjectTemplate> Navigator::generate() {

		v8::Handle<v8::ObjectTemplate> tpl = v8::ObjectTemplate::New();

		tpl->Set(v8::String::New("appName"), v8::String::New("V8GL"));

#ifdef __ANDROID__

		tpl->Set(v8::String::New("userAgent"),  v8::String::New("V8GL/2.0 (GLES; Android) lycheeJS-ADK"));
		tpl->Set(v8::String::New("appVersion"), v8::String::New("2.0 (GLES; Android) lycheeJS-ADK"));
		tpl->Set(v8::String::New("platform"),   v8::String::New("Android (API Level 9)"));

#else

		tpl->Set(v8::String::New("userAgent"),  v8::String::New("V8GL/2.0 (GL; Linux) lycheeJS-ADK"));
		tpl->Set(v8::String::New("appVersion"), v8::String::New("2.0 (GL; Linux) lycheeJS-ADK"));
		tpl->Set(v8::String::New("platform"),   v8::String::New("Linux"));

#endif

		tpl->Set(v8::String::New("product"),    v8::String::New("v8gl"));
		tpl->Set(v8::String::New("vendor"),     v8::String::New("lycheeJS-ADK"));


		return tpl;

	}

}


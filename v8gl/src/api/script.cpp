
#include <fstream>

#include "script.h"
#include "../v8gl/v8gl.h"
#include "../v8gl/path.h"


namespace api {


	Script::Script(const Script &cpy) {
	}



	v8::Handle<v8::FunctionTemplate> Script::generate() {

		v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(handleNew);
		tpl->SetClassName(v8::String::New("Script"));

		return tpl;

	}

	v8::Handle<v8::Value> Script::handleNew(const v8::Arguments& args) {

		v8::HandleScope scope;

		if (!args.IsConstructCall()) {
			return scope.Close(v8::ThrowException(v8::Exception::TypeError(v8::String::New("V8GL object constructor cannot be called as a function."))));
		}

		if (args.Length() != 1) {
			return scope.Close(v8::ThrowException(v8::Exception::SyntaxError(v8::String::New("Usage: new Script(url)"))));
		}

		v8::String::Utf8Value value(args[0]);
		char* url = *value;


		v8::Local<v8::ObjectTemplate> instanceTemplate = v8::ObjectTemplate::New();
		instanceTemplate->SetInternalFieldCount(0);

		instanceTemplate->Set(v8::String::New("load"), v8::FunctionTemplate::New(handleLoad), v8::ReadOnly);
		instanceTemplate->Set(v8::String::New("onload"), v8::FunctionTemplate::New());
		instanceTemplate->Set(v8::String::New("execute"), v8::FunctionTemplate::New(handleExecute), v8::ReadOnly);

		instanceTemplate->Set(v8::String::New("toString"), v8::FunctionTemplate::New(handleToString), v8::ReadOnly);

		v8::Local<v8::Object> instance = instanceTemplate->NewInstance();

		instance->Set(v8::String::New("url"), v8::String::New(url));
		instance->Set(v8::String::New("data"), v8::Null());


		return scope.Close(instance);

	}

	v8::Handle<v8::Value> Script::handleToString(const v8::Arguments& args) {
		return v8::String::New("[object Script]");
	}

	v8::Handle<v8::Value> Script::handleLoad(const v8::Arguments& args) {

		v8::HandleScope scope;
		v8::Local<v8::Object> thisObj = args.This();

		if (thisObj.IsEmpty()) {
			return scope.Close(v8::Null());
		}


		v8::Local<v8::String> property = v8::String::New("data");
		if (thisObj->Has(property)) {

			// Casting the already set properties via:
			// v8::Local<v8::String> myProp = thisObj->Get(property)->ToString();

			v8::String::Utf8Value value(thisObj->Get(v8::String::New("url")));
			char* url = v8gl::Path::getReal((char*) *value);

			char* data = api::Script::load(url);
			if (data == NULL) {

				thisObj->Set(property, v8::Null(), v8::ReadOnly);
				v8::ThrowException(v8::Exception::Error(v8::String::New("Could not read Script file.")));

			} else {

				// Recorrect the URL to make sure it's an absolute path
				thisObj->Set(v8::String::New("url"), v8::String::New(url), v8::ReadOnly);
				thisObj->Set(property, v8::String::New(data), v8::ReadOnly);

			}

			v8::Local<v8::Function> callback = v8::Function::Cast(*thisObj->Get(v8::String::New("onload")));
			if (!callback.IsEmpty()) {
				callback->Call(thisObj, 0, NULL);
			}

		}


		return scope.Close(v8::Null());

	}

	char* Script::load(char* filename) {

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

	v8::Handle<v8::Value> Script::handleExecute(const v8::Arguments& args) {

		v8::HandleScope scope;
		v8::Local<v8::Object> self = args.Holder();
		v8::Persistent<v8::Context> context(self->CreationContext());

		v8::Local<v8::Object> thisObj = args.This();

		if (thisObj.IsEmpty()) {
			return scope.Close(v8::False());
		}


		v8::Local<v8::String> property = v8::String::New("data");
		if (thisObj->Has(property) && !thisObj->Get(property)->IsNull()) {

			v8::Local<v8::String> data = v8::String::Cast(*thisObj->Get(property));
			v8::Local<v8::String> url = v8::String::Cast(*thisObj->Get(v8::String::New("url")));

			v8::String::Utf8Value utf8url(url);
			char* filepath = *utf8url;

			char *old_root = v8gl::Path::pushRoot(filepath);
			v8::Handle<v8::Value> value = v8gl::V8GL::execute(context, data, url);
			v8gl::Path::popRoot(old_root);

			return scope.Close(value);

		}


		return scope.Close(v8::False());

	}

}


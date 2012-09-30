
#include "text.h"
#include "../lib/fs.h"


namespace api {

	Text::Text(const Text &cpy) {}

	v8::Persistent<v8::FunctionTemplate> _text_tpl;

	v8::Handle<v8::FunctionTemplate> Text::generate() {

		_text_tpl = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(handleNew));
		_text_tpl->SetClassName(v8::String::New("Text"));

		v8::Local<v8::ObjectTemplate> instance_tpl = _text_tpl->InstanceTemplate();

		instance_tpl->SetInternalFieldCount(0);
		instance_tpl->Set(v8::String::New("load"),   v8::FunctionTemplate::New(handleLoad), v8::ReadOnly);
		instance_tpl->Set(v8::String::New("onload"), v8::FunctionTemplate::New());
		instance_tpl->Set(v8::String::New("url"),    v8::Null());
		instance_tpl->Set(v8::String::New("data"),   v8::Null());


		return _text_tpl;

	}

	v8::Handle<v8::Value> Text::handleNew(const v8::Arguments& args) {

		v8::HandleScope scope;

		if (!args.IsConstructCall()) {
			return v8::ThrowException(v8::Exception::TypeError(v8::String::New("V8GL object constructor cannot be called as a function.")));
		}

		if (args.Length() != 1 || !args[0]->IsString()) {
			return v8::ThrowException(v8::Exception::SyntaxError(v8::String::New("Usage: new Text(url)")));
		}


		v8::String::Utf8Value value(args[0]);
		char* url = *value;


		v8::Local<v8::Object> instance = args.This();

		instance->Set(v8::String::New("url"),  v8::String::New(url));
		instance->Set(v8::String::New("data"), v8::Null());


		return scope.Close(instance);

	}

	v8::Handle<v8::Value> Text::handleLoad(const v8::Arguments& args) {

		v8::HandleScope scope;
		v8::Local<v8::Object> self = args.This();


		if (!self.IsEmpty()) {

			v8::String::Utf8Value url_value(self->Get(v8::String::NewSymbol("url")));

			char* data = lib::FS::readVM(*url_value);
			char* url = lib::FS::getReal(*url_value);

			if (data == NULL) {
				self->Set(v8::String::NewSymbol("data"), v8::Null(),            v8::ReadOnly);
				return v8::ThrowException(v8::Exception::Error(v8::String::New("Could not read file.")));
			} else {
				self->Set(v8::String::NewSymbol("url"),  v8::String::New(url),  v8::ReadOnly);
				self->Set(v8::String::NewSymbol("data"), v8::String::New(data), v8::ReadOnly);
			}

			v8::Local<v8::Function> callback = v8::Function::Cast(*self->Get(v8::String::NewSymbol("onload")));
			if (!callback.IsEmpty()) {
				callback->Call(self, 0, NULL);
			}

		}


		return scope.Close(v8::Undefined());

	}

}


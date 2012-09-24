
#include <stdlib.h>
#include <string.h>

#include "arraybuffer.h"


namespace api {

	ArrayBuffer::ArrayBuffer(const ArrayBuffer &cpy) { }

	v8::Persistent<v8::FunctionTemplate> _arraybuffer_template;

	v8::Handle<v8::FunctionTemplate> ArrayBuffer::generate() {

		_arraybuffer_template = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(handleNew));
		_arraybuffer_template->SetClassName(v8::String::New("ArrayBuffer"));

		v8::Local<v8::ObjectTemplate> instance_tpl = _arraybuffer_template->InstanceTemplate();

		instance_tpl->SetInternalFieldCount(2);
		instance_tpl->Set(v8::String::NewSymbol("byteLength"), v8::Null());


		return _arraybuffer_template;

	}

	void ArrayBuffer::makeWeak(v8::Persistent<v8::Value> object, void* data) {

		free(data);
		object.Dispose();

	}

	v8::Handle<v8::Value> ArrayBuffer::handleNew(const v8::Arguments& args) {

		v8::HandleScope scope;

		if (!args.IsConstructCall()) {
			v8::ThrowException(v8::Exception::TypeError(v8::String::New("V8GL object constructor cannot be called as a function.")));
		}

		if (args.Length() != 1 || !args[0]->IsNumber()) {
			v8::ThrowException(v8::Exception::SyntaxError(v8::String::New("Usage: new ArrayBuffer(length)")));
		}


		v8::Local<v8::Object> instance = args.This();

		unsigned long length = args[0]->Uint32Value();

		void* data = malloc(length);
		memset(data, 0, length);

		v8::Persistent<v8::Object> handle = v8::Persistent<v8::Object>::New(instance);
		handle.MakeWeak(data, ArrayBuffer::makeWeak);


		instance->SetPointerInInternalField(0, data);
		instance->SetPointerInInternalField(1, (void*) length);
		instance->Set(v8::String::NewSymbol("byteLength"), v8::Int32::New(length), v8::ReadOnly);


		return scope.Close(instance);

	}

}


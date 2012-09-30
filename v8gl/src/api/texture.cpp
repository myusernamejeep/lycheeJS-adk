
#include <fstream>
#include <stdio.h>
#include <png.h>

#include "texture.h"
#include "../lib/fs.h"

#define TEXTURE_LOAD_ERROR 0

#ifndef __V8ADK__

	#ifdef __APPLE__
		#include <OpenGL/OpenGL.h>
	#elif __ANDROID__
		#define GL_GLEXT_PROTOTYPES
		#include <GLES2/gl2.h>
		#include <GLES2/gl2ext.h>
	#else
		#define GL_GLEXT_PROTOTYPES
		#include <GL/gl.h>
	#endif

#endif
 

namespace api {


	Texture::Texture(const Texture &cpy) { }

	v8::Persistent<v8::FunctionTemplate> _texture_tpl;

	v8::Handle<v8::FunctionTemplate> Texture::generate() {

		_texture_tpl = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(handleNew));
		_texture_tpl->SetClassName(v8::String::New("Texture"));

		v8::Local<v8::ObjectTemplate> instance_tpl = _texture_tpl->InstanceTemplate();

		instance_tpl->SetInternalFieldCount(1);
		instance_tpl->Set(v8::String::New("load"),     v8::FunctionTemplate::New(handleLoad),     v8::ReadOnly);
		instance_tpl->Set(v8::String::New("onload"),   v8::FunctionTemplate::New());
		instance_tpl->Set(v8::String::New("generate"), v8::FunctionTemplate::New(handleGenerate), v8::ReadOnly);


		return _texture_tpl;

	}

	v8::Handle<v8::Value> Texture::handleNew(const v8::Arguments& args) {

		v8::HandleScope scope;

		if (!args.IsConstructCall()) {
			return scope.Close(v8::ThrowException(v8::Exception::TypeError(v8::String::New("V8GL object constructor cannot be called as a function."))));
		}

		if (args.Length() != 1 || !args[0]->IsString()) {
			return scope.Close(v8::ThrowException(v8::Exception::SyntaxError(v8::String::New("Usage: new Texture(url)"))));
		}


		v8::String::Utf8Value value(args[0]);
		char* url = *value;


		v8::Local<v8::Object> instance = args.This();

		instance->Set(v8::String::New("url"),    v8::String::New(url));
		instance->Set(v8::String::New("id"),     v8::Null());
		instance->Set(v8::String::New("width"),  v8::Null());
		instance->Set(v8::String::New("height"), v8::Null());


		return scope.Close(instance);

	}

	v8::Handle<v8::Value> Texture::handleLoad(const v8::Arguments& args) {

		v8::HandleScope scope;
		v8::Local<v8::Object> self = args.This();


		if (!self.IsEmpty()) {
		
			v8::String::Utf8Value url_value(self->Get(v8::String::NewSymbol("url")));

			char* url = lib::FS::getReal(*url_value);

			int width;
			int height;


			png_byte *data = api::Texture::load(url, width, height);


			if (data == TEXTURE_LOAD_ERROR) {

#ifndef __V8ADK__
				self->SetPointerInInternalField(0, (GLvoid*) NULL);
#endif

				v8::ThrowException(v8::Exception::Error(v8::String::New("Could not read Texture file.")));

			} else {

#ifndef __V8ADK_
				self->SetPointerInInternalField(0, (GLvoid*) data);
#endif

				self->Set(v8::String::NewSymbol("url"),    v8::String::New(url),     v8::ReadOnly);
				self->Set(v8::String::NewSymbol("width"),  v8::Integer::New(width),  v8::ReadOnly);
				self->Set(v8::String::NewSymbol("height"), v8::Integer::New(height), v8::ReadOnly);

			}


			v8::Local<v8::Function> callback = v8::Function::Cast(*self->Get(v8::String::NewSymbol("onload")));
			if (!callback.IsEmpty()) {
				callback->Call(self, 0, NULL);
			}

		}


		return scope.Close(v8::Undefined());

	}


	v8::Handle<v8::Value> Texture::handleGenerate(const v8::Arguments& args) {

		v8::HandleScope scope;
		v8::Local<v8::Object> self = args.This();


		if (!self.IsEmpty()) {

#ifndef __V8ADK__

			int width  = self->Get(v8::String::NewSymbol("width"))->IntegerValue();
			int height = self->Get(v8::String::NewSymbol("height"))->IntegerValue();

			GLvoid* data = self->GetPointerFromInternalField(0);
			GLuint id    = api::Texture::generate(width, height, data);

			self->Set(v8::String::NewSymbol("id"), v8::Integer::New(id));

#endif

		}

		return scope.Close(v8::Undefined());

	}


	png_byte *Texture::load(char* filename, int &width, int &height) {

		png_byte header[8];

		//open file as binary
		FILE *fp = fopen(filename, "rb");
		if (!fp) {
			return TEXTURE_LOAD_ERROR;
		}


		//read the header
		fread(header, 1, 8, fp);


		//test if png
		int is_png = !png_sig_cmp(header, 0, 8);
		if (!is_png) {
			fclose(fp);
			return TEXTURE_LOAD_ERROR;
		}


		png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
		if (!png_ptr) {
			fclose(fp);
			return TEXTURE_LOAD_ERROR;
		}


		png_infop info_ptr = png_create_info_struct(png_ptr);
		if (!info_ptr) {
			png_destroy_read_struct(&png_ptr, (png_infopp) NULL, (png_infopp) NULL);
			fclose(fp);
			return TEXTURE_LOAD_ERROR;
		}

		png_infop end_info = png_create_info_struct(png_ptr);
		if (!end_info) {
			png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp) NULL);
			fclose(fp);
			return (TEXTURE_LOAD_ERROR);
		}
	 
		if (setjmp(png_jmpbuf(png_ptr))) {
			png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
			fclose(fp);
			return (TEXTURE_LOAD_ERROR);
		}
	 

		png_init_io(png_ptr, fp);
		png_set_sig_bytes(png_ptr, 8);
		png_read_info(png_ptr, info_ptr);


		int bit_depth, color_type;
		png_uint_32 twidth, theight;
		png_get_IHDR(png_ptr, info_ptr, &twidth, &theight, &bit_depth, &color_type, NULL, NULL, NULL);

		width = twidth;
		height = theight;

		png_read_update_info(png_ptr, info_ptr);
	 
		int rowbytes = png_get_rowbytes(png_ptr, info_ptr);
	 

		png_byte *image_data = new png_byte[rowbytes * height];
		if (!image_data) {
			png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
			fclose(fp);
			return TEXTURE_LOAD_ERROR;
		}
	 

		png_bytep *row_pointers = new png_bytep[height];
		if (!row_pointers) {
			png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
			delete[] image_data;
			fclose(fp);
			return TEXTURE_LOAD_ERROR;
		}


		// Does OpenGL really need the inverted row-based format?
		// Seems as it doesn't, maybe myth or rumor?
		// row_pointers[height - 1 - i] = image_data + i * rowbytes;

		for (int i = 0; i < height; ++i) {
			row_pointers[i] = image_data + i * rowbytes;
		}


		png_read_image(png_ptr, row_pointers);


		png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
		delete[] row_pointers;
		fclose(fp);

		return image_data;

	}

#ifndef __V8ADK__

	GLuint Texture::generate(int width, int height, GLvoid* data) {

		GLuint texture;


		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glGenTextures(1, &texture);

		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (int) width, (int) height, 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*) data);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


		return texture;

	}

#endif

}


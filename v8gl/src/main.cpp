
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#include "v8gl.h"
#include "./lib/fs.h"



int main(int argc, char* argv[]) {

	char buf0[PATH_MAX + 1];
	char buf1[PATH_MAX + 1];
	char *main_prog = realpath(argv[0], buf0);
	char *main_file = realpath("./main.js", buf1);

	if (main_file) {

		v8::HandleScope scope;
		v8::Persistent<v8::Context> context = v8gl::V8GL::initialize(&argc, argv);

		lib::FS::setVMRoot((char*) main_prog, (char*) main_file);


		v8gl::V8GL::dispatch(context);


		char* rawsource = lib::FS::read(main_file);

		v8::Local<v8::String> source = v8::String::New(rawsource);
		if (source.IsEmpty()) {
			fprintf(stderr, "\nERROR: Could not parse file %s\n", main_file);
		} else {
			v8gl::V8GL::execute(context, source, v8::String::New(main_file));
		}

	} else {
		fprintf(stderr, "\nERROR: No ./main.js file found.\n");
	}



/*
	v8::HandleScope scope;
	v8::Persistent<v8::Context> context = v8gl::V8GL::initialize(&argc, argv);


	lib::FS::setVMRoot((char*) root_prog, (char*) root_file);


	v8gl::V8GL::dispatch(context, (char*) "lycheeJS");

	v8gl::V8GL::execute(context, v8::String::New("glut.init()"), v8::String::New("@built-in/main.js"));
	v8gl::V8GL::execute(context, v8::String::New("glut.createWindow(\"V8GL runtime\");"), v8::String::New("@built-in/main.js"));
    // OLD main.js was EXECUTED HERE
	v8gl::V8GL::execute(context, v8::String::New("glut.mainLoop()"), v8::String::New("@built-in/main.js"));

	context.Dispose();

	return 0;

*/

}
 

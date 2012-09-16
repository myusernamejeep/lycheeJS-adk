
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#include "v8gl.h"
#include "path.h"



int main(int argc, char* argv[]) {

	char buf0[PATH_MAX + 1];
	char buf1[PATH_MAX + 1];
	char *root_prog = realpath(argv[0], buf0);
	char *root_file;

	if (argc == 1) {

		argc = 3;
		argv[1] = (char*) "./js/game/Main.js";
		argv[2] = (char*) "./init.js";

		root_file = realpath(argv[2], buf1);

	} else {

		root_file = realpath(argv[0], buf1);

	}


	v8::HandleScope scope;
	v8::Persistent<v8::Context> context = v8gl::V8GL::initialize(&argc, argv);


	v8gl::Path::setRoot((char*) root_prog, (char*) root_file);

	v8gl::V8GL::dispatch(context, (char*) "lycheeJS");

	v8gl::V8GL::execute(context, v8::String::New("glut.init()"), v8::String::New("@built-in/main.js"));
	v8gl::V8GL::execute(context, v8::String::New("glut.createWindow(\"V8GL runtime\");"), v8::String::New("@built-in/main.js"));

	for (int i = 1; i < argc; i++) {

		char buf[PATH_MAX + 1];
		char *path = realpath(argv[i], buf);

		if (path) {

			char* _source = v8gl::V8GL::read(path);
			v8::Local<v8::String> source = v8::String::New(_source);


			if (source.IsEmpty()) {

				fprintf(stderr, "Error reading file %s", path);

			} else {

				char *old_path = v8gl::Path::pushRoot(path);
				v8gl::V8GL::execute(context, source, v8::String::New(path));
				v8gl::Path::popRoot(old_path);

			}

		} else {

			fprintf(stderr, "Error reading file %s", path);

		}

	}

	v8gl::V8GL::execute(context, v8::String::New("glut.mainLoop()"), v8::String::New("@built-in/main.js"));

	context.Dispose();

	return 0;

}
 

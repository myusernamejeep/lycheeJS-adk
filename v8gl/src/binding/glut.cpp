
#include "glut.h"

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif


/*
 * The GLUT bindings were implemented following the spec document available here:
 * http://www.opengl.org/resources/libraries/glut/spec3/spec3.html
 *
 * MISSING bindings (due to cross-platform conflictions):
 *
 * - 4. from Window Management:
 *   > glut.setCursor
 *
 * - 6. Menu Management
 *
 * - 7. from Callback Registration:
 *   > glut.passiveMotionFunc
 *   > glut.visibilityFunc
 *   > glut.entryFunc
 *   > glut.specialFunc
 *   > glut.spaceballMotionFunc, glut.spaceballRotationFunc, glut.spaceballButtonFunc
 *   > glut.dialsFunc
 *   > glut.tabletMotionFunc
 *   > glut.tabletButtonFunc
 *   > glut.menuStatusFunc
 *
 * - 8. Color Index Colormap Management
 *
 * - 9. from State Retrieval:
 *   > glut.get
 *   > glut.layerGet
 *   > glut.deviceGet
 *
 * - 10. Font Rendering (use lychee.Font instead)
 * - 13. FORTRAN Binding
 *
 */


namespace binding {

	/*
	 * Initialization
	 */

	bool _glut_mainLoop = false;

	v8::Handle<v8::Value> GLUT::handleMainLoop(const v8::Arguments& args) {

		if (_glut_mainLoop == false) {
			glutMainLoop();
			_glut_mainLoop = true;
		}

		return v8::Undefined();

	}

	bool _glut_init = false;
	int* _glut_pargc;
	char** _glut_argv;

	v8::Handle<v8::Value> GLUT::handleInit(const v8::Arguments& args) {

		if (_glut_init == false) {
			glutInit((int*) _glut_pargc, (char**) _glut_argv);
			_glut_init = true;
		}

		return v8::Undefined();
	}


	v8::Handle<v8::Value> GLUT::handleInitWindowPosition(const v8::Arguments& args) {

		if (args.Length() == 2) {

			int posx = args[0]->IntegerValue();
			int posy = args[1]->IntegerValue();

			glutInitWindowPosition((int) posx, (int) posy);

		}

		return v8::Undefined();

	}
 
	v8::Handle<v8::Value> GLUT::handleInitWindowSize(const v8::Arguments& args) {

		if (args.Length() == 2) {

			int width = args[0]->IntegerValue();
			int height = args[1]->IntegerValue();

			glutInitWindowSize((int) width, (int) height);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GLUT::getRGBA(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GLUT_RGBA);
	}

	v8::Handle<v8::Value> GLUT::getRGB(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GLUT_RGB);
	}

	v8::Handle<v8::Value> GLUT::getINDEX(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GLUT_INDEX);
	}

	v8::Handle<v8::Value> GLUT::getSINGLE(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GLUT_SINGLE);
	}

	v8::Handle<v8::Value> GLUT::getDOUBLE(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GLUT_DOUBLE);
	}

	v8::Handle<v8::Value> GLUT::getACCUM(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GLUT_ACCUM);
	}

	v8::Handle<v8::Value> GLUT::getALPHA(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GLUT_ALPHA);
	}

	v8::Handle<v8::Value> GLUT::getDEPTH(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GLUT_DEPTH);
	}

	v8::Handle<v8::Value> GLUT::getSTENCIL(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GLUT_STENCIL);
	}

	v8::Handle<v8::Value> GLUT::getMULTISAMPLE(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GLUT_MULTISAMPLE);
	}

	v8::Handle<v8::Value> GLUT::getSTEREO(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GLUT_STEREO);
	}

	// FIXME: Evaluate where this is available
	// v8::Handle<v8::Value> GLUT::getLUMINANCE(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
	//	return v8::Uint32::New(GLUT_LUMINANCE);
	//}

	v8::Handle<v8::Value> GLUT::handleInitDisplayMode(const v8::Arguments& args) {

		if (args.Length() == 1) {

			unsigned int mode = args[0]->Uint32Value();

			glutInitDisplayMode((unsigned int) mode);

		}

		return v8::Undefined();

	}
 


	/*
	 * Window Management
	 */


	v8::Handle<v8::Value> GLUT::handleCreateSubWindow(const v8::Arguments& args) {

		if (args.Length() == 5) {

			int win    = args[0]->Uint32Value();
			int posx   = args[1]->Uint32Value();
			int posy   = args[2]->Uint32Value();
			int width  = args[3]->Uint32Value();
			int height = args[4]->Uint32Value();

			int id = glutCreateSubWindow((int) win, (int) posx, (int) posy, (int) width, (int) height);

			return v8::Uint32::New(id);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GLUT::handleGetWindow(const v8::Arguments& args) {

		int id = glutGetWindow();

		return v8::Uint32::New(id);

	}

	v8::Handle<v8::Value> GLUT::handleSetWindow(const v8::Arguments& args) {

		if (args.Length() == 1) {

			int win = args[0]->IntegerValue();

			glutSetWindow((int) win);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GLUT::handleDestroyWindow(const v8::Arguments& args) {

		if (args.Length() == 1) {

			int win = args[0]->IntegerValue();

			glutDestroyWindow((int) win);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GLUT::handlePostRedisplay(const v8::Arguments& args) {
		glutPostRedisplay();
		return v8::Undefined();
	}

	v8::Handle<v8::Value> GLUT::handleSwapBuffers(const v8::Arguments& args) {
		glutSwapBuffers();
		return v8::Undefined();
	}

	v8::Handle<v8::Value> GLUT::handlePositionWindow(const v8::Arguments& args) {

		if (args.Length() == 2) {

			int posx = args[0]->IntegerValue();
			int posy = args[1]->IntegerValue();

			glutPositionWindow((int) posx, (int) posy);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GLUT::handleReshapeWindow(const v8::Arguments& args) {

		if (args.Length() == 2) {

			int width = args[0]->IntegerValue();
			int height = args[1]->IntegerValue();

			glutReshapeWindow((int) width, (int) height);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GLUT::handleFullScreen(const v8::Arguments& args) {
		glutFullScreen();
		return v8::Undefined();
	}

	v8::Handle<v8::Value> GLUT::handlePopWindow(const v8::Arguments& args) {
		glutPopWindow();
		return v8::Undefined();
	}

	v8::Handle<v8::Value> GLUT::handlePushWindow(const v8::Arguments& args) {
		glutPushWindow();
		return v8::Undefined();
	}

	v8::Handle<v8::Value> GLUT::handleShowWindow(const v8::Arguments& args) {
		glutShowWindow();
		return v8::Undefined();
	}

	v8::Handle<v8::Value> GLUT::handleHideWindow(const v8::Arguments& args) {
		glutHideWindow();
		return v8::Undefined();
	}

	v8::Handle<v8::Value> GLUT::handleIconifyWindow(const v8::Arguments& args) {
		glutIconifyWindow();
		return v8::Undefined();
	}

	v8::Handle<v8::Value> GLUT::handleSetWindowTitle(const v8::Arguments& args) {

		if (args.Length() == 1) {

			v8::String::Utf8Value raw(args[0]);
			char* name = *raw;

			glutSetWindowTitle((char*) name);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GLUT::handleSetIconTitle(const v8::Arguments& args) {

		if (args.Length() == 1) {

			v8::String::Utf8Value raw(args[0]);
			char* name = *raw;

			glutSetIconTitle((char*) name);

		}

		return v8::Undefined();

	}



	/*
	 * Overlay Management
	 */

	v8::Handle<v8::Value> GLUT::handleEstablishOverlay(const v8::Arguments& args) {
		glutEstablishOverlay();
		return v8::Undefined();
	}

	v8::Handle<v8::Value> GLUT::handleRemoveOverlay(const v8::Arguments& args) {
		glutRemoveOverlay();
		return v8::Undefined();
	}

	v8::Handle<v8::Value> GLUT::handlePostOverlayRedisplay(const v8::Arguments& args) {
		glutPostOverlayRedisplay();
		return v8::Undefined();
	}

	v8::Handle<v8::Value> GLUT::handleShowOverlay(const v8::Arguments& args) {
		glutShowOverlay();
		return v8::Undefined();
	}

	v8::Handle<v8::Value> GLUT::handleHideOverlay(const v8::Arguments& args) {
		glutHideOverlay();
		return v8::Undefined();
	}



	/*
	 * Callback Registration
	 */

	v8::Persistent<v8::Function> _glut_displayFuncCallback;

	void _glut_displayFunc() {

		v8::HandleScope scope;

		v8::Local<v8::Object> callback_scope = _glut_displayFuncCallback->CreationContext()->Global()->Get(v8::String::NewSymbol("glut"))->ToObject();
		v8::Local<v8::Value> result = _glut_displayFuncCallback->Call(callback_scope, 0, NULL);

		scope.Close(result);

	}

	v8::Handle<v8::Value> GLUT::handleDisplayFunc(const v8::Arguments& args) {

		if (args.Length() == 1 && args[0]->IsFunction()) {

			_glut_displayFuncCallback.Dispose();
			v8::Handle<v8::Function> callback = v8::Handle<v8::Function>::Cast(args[0]);
			_glut_displayFuncCallback = v8::Persistent<v8::Function>::New(callback);

			glutDisplayFunc((void (*)(void)) _glut_displayFunc);

		}

		return v8::Undefined();

	}

	v8::Persistent<v8::Function> _glut_overlayDisplayFuncCallback;

	void _glut_overlayDisplayFunc() {

		v8::HandleScope scope;

		v8::Local<v8::Object> callback_scope = _glut_overlayDisplayFuncCallback->CreationContext()->Global()->Get(v8::String::NewSymbol("glut"))->ToObject();
		v8::Local<v8::Value> result = _glut_overlayDisplayFuncCallback->Call(callback_scope, 0, NULL);

		scope.Close(result);

	}

	v8::Handle<v8::Value> GLUT::handleOverlayDisplayFunc(const v8::Arguments& args) {

		if (args.Length() == 1 && args[0]->IsFunction()) {

			_glut_overlayDisplayFuncCallback.Dispose();
			v8::Handle<v8::Function> callback = v8::Handle<v8::Function>::Cast(args[0]);
			_glut_overlayDisplayFuncCallback = v8::Persistent<v8::Function>::New(callback);

			glutOverlayDisplayFunc((void (*)(void)) _glut_overlayDisplayFunc);

		}

		return v8::Undefined();

	}

	v8::Persistent<v8::Function> _glut_reshapeFuncCallback;

	void _glut_reshapeFunc(int width, int height) {

		v8::HandleScope scope;

		v8::Handle<v8::Value> args[2];
		args[0] = v8::Integer::New(width);
		args[1] = v8::Integer::New(height);

		v8::Local<v8::Object> callback_scope = _glut_reshapeFuncCallback->CreationContext()->Global()->Get(v8::String::NewSymbol("glut"))->ToObject();
		v8::Local<v8::Value> result = _glut_reshapeFuncCallback->Call(callback_scope, 2, args);

		scope.Close(result);

	}

	v8::Handle<v8::Value> GLUT::handleReshapeFunc(const v8::Arguments& args) {

		if (args.Length() == 1 && args[0]->IsFunction()) {

			_glut_reshapeFuncCallback.Dispose();
			v8::Handle<v8::Function> callback = v8::Handle<v8::Function>::Cast(args[0]);
			_glut_reshapeFuncCallback = v8::Persistent<v8::Function>::New(callback);

			glutReshapeFunc((void (*)(int width, int height)) _glut_reshapeFunc);

		}

		return v8::Undefined();

	}

	v8::Persistent<v8::Function> _glut_keyboardFuncCallback;

	void _glut_keyboardFunc(unsigned char key, int x, int y) {

		v8::HandleScope scope;

		const char* keyval = (char*) &key;

		v8::Handle<v8::Value> args[2];
		args[0] = v8::String::New(keyval);
		args[1] = v8::Integer::New(x);
		args[2] = v8::Integer::New(y);

		v8::Local<v8::Object> callback_scope = _glut_keyboardFuncCallback->CreationContext()->Global()->Get(v8::String::NewSymbol("glut"))->ToObject();
		v8::Local<v8::Value> result = _glut_keyboardFuncCallback->Call(callback_scope, 2, args);

		scope.Close(result);

	}

	v8::Handle<v8::Value> GLUT::handleKeyboardFunc(const v8::Arguments& args) {

		if (args.Length() == 1 && args[0]->IsFunction()) {

			_glut_keyboardFuncCallback.Dispose();
			v8::Handle<v8::Function> callback = v8::Handle<v8::Function>::Cast(args[0]);
			_glut_keyboardFuncCallback = v8::Persistent<v8::Function>::New(callback);

			glutKeyboardFunc((void (*)(unsigned char key, int x, int y)) _glut_keyboardFunc);

		}

		return v8::Undefined();

	}
 
	v8::Handle<v8::Value> GLUT::getLEFT_BUTTON(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GLUT_LEFT_BUTTON);
	}

	v8::Handle<v8::Value> GLUT::getMIDDLE_BUTTON(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GLUT_MIDDLE_BUTTON);
	}

	v8::Handle<v8::Value> GLUT::getRIGHT_BUTTON(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GLUT_RIGHT_BUTTON);
	}

	v8::Handle<v8::Value> GLUT::getUP(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GLUT_UP);
	}

	v8::Handle<v8::Value> GLUT::getDOWN(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GLUT_DOWN);
	}

	v8::Persistent<v8::Function> _glut_mouseFuncCallback;

	void _glut_mouseFunc(int button, int state, int x, int y) {

		v8::HandleScope scope;

		v8::Handle<v8::Value> args[4];
		args[0] = v8::Integer::New(button);
		args[1] = v8::Integer::New(state);
		args[2] = v8::Integer::New(x);
		args[3] = v8::Integer::New(y);

		v8::Local<v8::Object> callback_scope = _glut_mouseFuncCallback->CreationContext()->Global()->Get(v8::String::NewSymbol("glut"))->ToObject();
		v8::Local<v8::Value> result = _glut_mouseFuncCallback->Call(callback_scope, 4, args);

		scope.Close(result);

	}

	v8::Handle<v8::Value> GLUT::handleMouseFunc(const v8::Arguments& args) {

		if (args.Length() == 1 && args[0]->IsFunction()) {

			_glut_mouseFuncCallback.Dispose();
			v8::Handle<v8::Function> callback = v8::Handle<v8::Function>::Cast(args[0]);
			_glut_mouseFuncCallback = v8::Persistent<v8::Function>::New(callback);

			glutMouseFunc((void (*)(int button, int state, int x, int y)) _glut_mouseFunc);

		}

		return v8::Undefined();

	}

	v8::Persistent<v8::Function> _glut_motionFuncCallback;

	void _glut_motionFunc(int x, int y) {

		v8::HandleScope scope;

		v8::Handle<v8::Value> args[2];
		args[0] = v8::Integer::New(x);
		args[1] = v8::Integer::New(y);

		v8::Local<v8::Object> callback_scope = _glut_motionFuncCallback->CreationContext()->Global()->Get(v8::String::NewSymbol("glut"))->ToObject();
		v8::Local<v8::Value> result = _glut_motionFuncCallback->Call(callback_scope, 2, args);

		scope.Close(result);

	}

	v8::Handle<v8::Value> GLUT::handleMotionFunc(const v8::Arguments& args) {

		if (args.Length() == 1 && args[0]->IsFunction()) {

			_glut_motionFuncCallback.Dispose();
			v8::Handle<v8::Function> callback = v8::Handle<v8::Function>::Cast(args[0]);
			_glut_motionFuncCallback = v8::Persistent<v8::Function>::New(callback);

			glutMotionFunc((void (*)(int x, int y)) _glut_motionFunc);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GLUT::handleIdleFunc(const v8::Arguments& args) {
		return v8::Undefined();
	}


	typedef struct {
		v8::Persistent<v8::Object> scope;
		v8::Persistent<v8::Function> callback;
		v8::Persistent<v8::Value> value;
	} _glut_timer_data;

	_glut_timer_data * _glut_timerStack[50] = { NULL };

	void _glut_timerFunc(int id) {

		_glut_timer_data * timer = _glut_timerStack[id];

		if (timer != NULL) {

			v8::HandleScope scope;

			v8::Handle<v8::Value> args[1];
			args[0] = timer->value;

			timer->callback->Call(timer->scope, 1, args);

			timer->scope.Dispose();
			timer->callback.Dispose();
			timer->value.Dispose();

			delete timer;

			_glut_timerStack[id] = NULL;


		}

	}

	v8::Handle<v8::Value> GLUT::handleTimerFunc(const v8::Arguments& args) {

		v8::HandleScope scope;

		if (args.Length() == 3) {

			unsigned int milliseconds = args[0]->Uint32Value();

			v8::Handle<v8::Function> func = v8::Handle<v8::Function>::Cast(args[1]);
			v8::Persistent<v8::Function> callback = v8::Persistent<v8::Function>::New(func);

			v8::Local<v8::Object> argsThis = args.This();
			v8::Persistent<v8::Object> self = v8::Persistent<v8::Object>::New(argsThis);

			v8::Local<v8::Value> argsValue = args[2];
			v8::Persistent<v8::Value> value = v8::Persistent<v8::Value>::New(argsValue);

			bool found = false;
			int stackId = 0;
			for (; stackId < 50; stackId++) {

				if (_glut_timerStack[stackId] == NULL) {

					_glut_timer_data * data = new _glut_timer_data;

					data->value = value;
					data->scope = self;
					data->callback = callback;

					_glut_timerStack[stackId] = data;

					found = true;
					break;

				}

				stackId++;

			}


			if (found == true) {
				glutTimerFunc((unsigned int) milliseconds, (void (*)(int)) _glut_timerFunc, (int) stackId);
			}

		}

		return scope.Close(v8::Undefined());

	}



	/*
	 * State Retrieval
	 */

	v8::Handle<v8::Value> GLUT::getACTIVE_SHIFT(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GLUT_ACTIVE_SHIFT);
	}

	v8::Handle<v8::Value> GLUT::getACTIVE_CTRL(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GLUT_ACTIVE_CTRL);
	}

	v8::Handle<v8::Value> GLUT::getACTIVE_ALT(v8::Local<v8::String> property, const v8::AccessorInfo &info) {
		return v8::Uint32::New(GLUT_ACTIVE_ALT);
	}

	v8::Handle<v8::Value> GLUT::handleGetModifiers(const v8::Arguments& args) {
		int modifiers = glutGetModifiers();
		return v8::Uint32::New(modifiers);
	}

	v8::Handle<v8::Value> GLUT::handleExtensionSupported(const v8::Arguments& args) {

		if (args.Length() == 1) {

			v8::String::Utf8Value raw(args[0]);
			char* extension = *raw;

			int isSupported = glutExtensionSupported(extension);
			if (isSupported != 0) {
				return v8::True();
			}

		}

		return v8::False();

	}



	/*
	 * Geometric Object Rendering
	 */

	v8::Handle<v8::Value> GLUT::handleSolidSphere(const v8::Arguments& args) {

		if (args.Length() == 3) {

			double radius = args[0]->NumberValue();
			int slices = args[1]->IntegerValue();
			int stacks = args[2]->IntegerValue();

			glutSolidSphere((GLdouble) radius, (GLint) slices, (GLint) stacks);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GLUT::handleWireSphere(const v8::Arguments& args) {

		if (args.Length() == 3) {

			double radius = args[0]->NumberValue();
			int slices = args[1]->IntegerValue();
			int stacks = args[2]->IntegerValue();

			glutWireSphere((GLdouble) radius, (GLint) slices, (GLint) stacks);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GLUT::handleSolidCube(const v8::Arguments& args) {

		if (args.Length() == 1) {

			double size = args[0]->NumberValue();

			glutSolidCube((GLdouble) size);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GLUT::handleWireCube(const v8::Arguments& args) {

		if (args.Length() == 1) {

			double size = args[0]->NumberValue();

			glutWireCube((GLdouble) size);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GLUT::handleSolidCone(const v8::Arguments& args) {

		if (args.Length() == 4) {

			double base = args[0]->NumberValue();
			double height = args[1]->NumberValue();
			int slices = args[2]->IntegerValue();
			int stacks = args[3]->IntegerValue();

			glutSolidCone((GLdouble) base, (GLdouble) height, (GLint) slices, (GLint) stacks);

		}

		return v8::Undefined();

	}
 
	v8::Handle<v8::Value> GLUT::handleWireCone(const v8::Arguments& args) {

		if (args.Length() == 4) {

			double base = args[0]->NumberValue();
			double height = args[1]->NumberValue();
			int slices = args[2]->IntegerValue();
			int stacks = args[3]->IntegerValue();

			glutWireCone((GLdouble) base, (GLdouble) height, (GLint) slices, (GLint) stacks);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GLUT::handleSolidTorus(const v8::Arguments& args) {

		if (args.Length() == 4) {

			double innerRadius = args[0]->NumberValue();
			double outerRadius = args[1]->NumberValue();
			int nsides = args[2]->IntegerValue();
			int rings = args[3]->IntegerValue();

			glutSolidTorus((GLdouble) innerRadius, (GLdouble) outerRadius, (GLint) nsides, (GLint) rings);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GLUT::handleWireTorus(const v8::Arguments& args) {

		if (args.Length() == 4) {

			double innerRadius = args[0]->NumberValue();
			double outerRadius = args[1]->NumberValue();
			int nsides = args[2]->IntegerValue();
			int rings = args[3]->IntegerValue();

			glutWireTorus((GLdouble) innerRadius, (GLdouble) outerRadius, (GLint) nsides, (GLint) rings);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GLUT::handleSolidDodecahedron(const v8::Arguments& args) {
		glutSolidDodecahedron();
		return v8::Undefined();
	}

	v8::Handle<v8::Value> GLUT::handleWireDodecahedron(const v8::Arguments& args) {
		glutWireDodecahedron();
		return v8::Undefined();
	}

	v8::Handle<v8::Value> GLUT::handleSolidTetrahedron(const v8::Arguments& args) {
		glutSolidTetrahedron();
		return v8::Undefined();
	}

	v8::Handle<v8::Value> GLUT::handleWireTetrahedron(const v8::Arguments& args) {
		glutWireTetrahedron();
		return v8::Undefined();
	}

	v8::Handle<v8::Value> GLUT::handleSolidOctahedron(const v8::Arguments& args) {
		glutSolidOctahedron();
		return v8::Undefined();
	}

	v8::Handle<v8::Value> GLUT::handleWireOctahedron(const v8::Arguments& args) {
		glutWireOctahedron();
		return v8::Undefined();
	}

	v8::Handle<v8::Value> GLUT::handleSolidIcosahedron(const v8::Arguments& args) {
		glutSolidIcosahedron();
		return v8::Undefined();
	}

	v8::Handle<v8::Value> GLUT::handleWireIcosahedron(const v8::Arguments& args) {
		glutWireIcosahedron();
		return v8::Undefined();
	}

	v8::Handle<v8::Value> GLUT::handleSolidTeapot(const v8::Arguments& args) {

		if (args.Length() == 1) {
			double size = args[0]->NumberValue();
			glutSolidTeapot((GLdouble) size);
		}
 
		return v8::Undefined();
	}

	v8::Handle<v8::Value> GLUT::handleWireTeapot(const v8::Arguments& args) {

		if (args.Length() == 1) {
			double size = args[0]->NumberValue();
			glutWireTeapot((GLdouble) size);
		}

		return v8::Undefined();
	}



	/*
	 * Window Management: glut.createWindow()
	 *
	 * This is down here to automatically rebind all callbacks
	 */

	v8::Handle<v8::Value> GLUT::handleCreateWindow(const v8::Arguments& args) {

		if (args.Length() == 1) {

			v8::String::Utf8Value raw(args[0]);
			char* name = *raw;

			int win = glutCreateWindow((char*) name);


			if (_glut_displayFuncCallback.IsEmpty() == false) {
				glutDisplayFunc((void (*)(void)) _glut_displayFunc);
			}

			if (_glut_reshapeFuncCallback.IsEmpty() == false) {
				glutReshapeFunc((void (*)(int width, int height)) _glut_reshapeFunc);
			}

			if (_glut_keyboardFuncCallback.IsEmpty() == false) {
				glutKeyboardFunc((void (*)(unsigned char key, int x, int y)) _glut_keyboardFunc);
			}

			if (_glut_mouseFuncCallback.IsEmpty() == false) {
				glutMouseFunc((void (*)(int button, int state, int x, int y)) _glut_mouseFunc);
			}

			if (_glut_motionFuncCallback.IsEmpty() == false) {
				glutMotionFunc((void (*)(int x, int y)) _glut_motionFunc);
			}


			if (_glut_overlayDisplayFuncCallback.IsEmpty() == false) {
				glutOverlayDisplayFunc((void (*)(void)) _glut_overlayDisplayFunc);
			}


			return v8::Uint32::New(win);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::ObjectTemplate> GLUT::generate(int* pargc, char** argv) {

		_glut_pargc = pargc;
		_glut_argv = argv;


		v8::HandleScope scope;

		v8::Handle<v8::ObjectTemplate> gluttpl = v8::ObjectTemplate::New();



		/*
		 * Initialization
		 */
		gluttpl->Set(v8::String::NewSymbol("init"),               v8::FunctionTemplate::New(GLUT::handleInit));
		gluttpl->Set(v8::String::NewSymbol("initWindowPosition"), v8::FunctionTemplate::New(GLUT::handleInitWindowPosition));
		gluttpl->Set(v8::String::NewSymbol("initWindowSize"),     v8::FunctionTemplate::New(GLUT::handleInitWindowSize));
		gluttpl->Set(v8::String::NewSymbol("initDisplayMode"),    v8::FunctionTemplate::New(GLUT::handleInitDisplayMode));

		gluttpl->SetAccessor(v8::String::NewSymbol("RGBA"),        GLUT::getRGBA);
		gluttpl->SetAccessor(v8::String::NewSymbol("RGB"),         GLUT::getRGB);
		gluttpl->SetAccessor(v8::String::NewSymbol("INDEX"),       GLUT::getINDEX);
		gluttpl->SetAccessor(v8::String::NewSymbol("SINGLE"),      GLUT::getSINGLE);
		gluttpl->SetAccessor(v8::String::NewSymbol("DOUBLE"),      GLUT::getDOUBLE);
		gluttpl->SetAccessor(v8::String::NewSymbol("ACCUM"),       GLUT::getACCUM);
		gluttpl->SetAccessor(v8::String::NewSymbol("ALPHA"),       GLUT::getALPHA);
		gluttpl->SetAccessor(v8::String::NewSymbol("DEPTH"),       GLUT::getDEPTH);
		gluttpl->SetAccessor(v8::String::NewSymbol("STENCIL"),     GLUT::getSTENCIL);
		gluttpl->SetAccessor(v8::String::NewSymbol("MULTISAMPLE"), GLUT::getMULTISAMPLE);
		gluttpl->SetAccessor(v8::String::NewSymbol("STEREO"),      GLUT::getSTEREO);

		// FIXME: Evaluate where this is available
		// glut->SetAccessor(v8::String::NewSymbol("LUMINANCE"),    GLUT::getLUMINANCE);


		/*
		 * Event Processing
		 */
		gluttpl->Set(v8::String::NewSymbol("mainLoop"), v8::FunctionTemplate::New(GLUT::handleMainLoop));


		/*
		 * Window Management
		 */
		gluttpl->Set(v8::String::NewSymbol("createWindow"),    v8::FunctionTemplate::New(GLUT::handleCreateWindow));
		gluttpl->Set(v8::String::NewSymbol("createSubWindow"), v8::FunctionTemplate::New(GLUT::handleCreateSubWindow));
		gluttpl->Set(v8::String::NewSymbol("setWindow"),       v8::FunctionTemplate::New(GLUT::handleSetWindow));
		gluttpl->Set(v8::String::NewSymbol("getWindow"),       v8::FunctionTemplate::New(GLUT::handleGetWindow));
		gluttpl->Set(v8::String::NewSymbol("destroyWindow"),   v8::FunctionTemplate::New(GLUT::handleDestroyWindow));
		gluttpl->Set(v8::String::NewSymbol("postRedisplay"),   v8::FunctionTemplate::New(GLUT::handlePostRedisplay));
		gluttpl->Set(v8::String::NewSymbol("swapBuffers"),     v8::FunctionTemplate::New(GLUT::handleSwapBuffers));
		gluttpl->Set(v8::String::NewSymbol("positionWindow"),  v8::FunctionTemplate::New(GLUT::handlePositionWindow));
		gluttpl->Set(v8::String::NewSymbol("reshapeWindow"),   v8::FunctionTemplate::New(GLUT::handleReshapeWindow));
		gluttpl->Set(v8::String::NewSymbol("fullScreen"),      v8::FunctionTemplate::New(GLUT::handleFullScreen));
		gluttpl->Set(v8::String::NewSymbol("popWindow"),       v8::FunctionTemplate::New(GLUT::handlePopWindow));
		gluttpl->Set(v8::String::NewSymbol("pushWindow"),      v8::FunctionTemplate::New(GLUT::handlePushWindow));
		gluttpl->Set(v8::String::NewSymbol("showWindow"),      v8::FunctionTemplate::New(GLUT::handleShowWindow));
		gluttpl->Set(v8::String::NewSymbol("hideWindow"),      v8::FunctionTemplate::New(GLUT::handleHideWindow));
		gluttpl->Set(v8::String::NewSymbol("iconifyWindow"),   v8::FunctionTemplate::New(GLUT::handleIconifyWindow));
		gluttpl->Set(v8::String::NewSymbol("setWindowTitle"),  v8::FunctionTemplate::New(GLUT::handleSetWindowTitle));
		gluttpl->Set(v8::String::NewSymbol("setIconTitle"),    v8::FunctionTemplate::New(GLUT::handleSetIconTitle));


		/*
		 * Overlay Management
		 */
		gluttpl->Set(v8::String::NewSymbol("establishOverlay"),     v8::FunctionTemplate::New(GLUT::handleEstablishOverlay));
		gluttpl->Set(v8::String::NewSymbol("removeOverlay"),        v8::FunctionTemplate::New(GLUT::handleRemoveOverlay));
		gluttpl->Set(v8::String::NewSymbol("postOverlayRedisplay"), v8::FunctionTemplate::New(GLUT::handlePostOverlayRedisplay));
		gluttpl->Set(v8::String::NewSymbol("showOverlay"),          v8::FunctionTemplate::New(GLUT::handleShowOverlay));
		gluttpl->Set(v8::String::NewSymbol("hideOverlay"),          v8::FunctionTemplate::New(GLUT::handleHideOverlay));


		/*
		 * Callback Registration
		 */
		gluttpl->Set(v8::String::NewSymbol("displayFunc"),           v8::FunctionTemplate::New(GLUT::handleDisplayFunc));
		gluttpl->Set(v8::String::NewSymbol("overlayDisplayFunc"),    v8::FunctionTemplate::New(GLUT::handleOverlayDisplayFunc));
		gluttpl->Set(v8::String::NewSymbol("reshapeFunc"),           v8::FunctionTemplate::New(GLUT::handleReshapeFunc));
		gluttpl->Set(v8::String::NewSymbol("keyboardFunc"),          v8::FunctionTemplate::New(GLUT::handleKeyboardFunc));
		gluttpl->SetAccessor(v8::String::NewSymbol("LEFT_BUTTON"),   GLUT::getLEFT_BUTTON);
		gluttpl->SetAccessor(v8::String::NewSymbol("MIDDLE_BUTTON"), GLUT::getMIDDLE_BUTTON);
		gluttpl->SetAccessor(v8::String::NewSymbol("RIGHT_BUTTON"),  GLUT::getRIGHT_BUTTON);
		gluttpl->SetAccessor(v8::String::NewSymbol("UP"),            GLUT::getUP);
		gluttpl->SetAccessor(v8::String::NewSymbol("DOWN"),          GLUT::getDOWN);
		gluttpl->Set(v8::String::NewSymbol("mouseFunc"),             v8::FunctionTemplate::New(GLUT::handleMouseFunc));
		gluttpl->Set(v8::String::NewSymbol("motionFunc"),            v8::FunctionTemplate::New(GLUT::handleMotionFunc));
		gluttpl->Set(v8::String::NewSymbol("idleFunc"),              v8::FunctionTemplate::New(GLUT::handleIdleFunc));
		gluttpl->Set(v8::String::NewSymbol("timerFunc"),             v8::FunctionTemplate::New(GLUT::handleTimerFunc));


		/*
		 * State Retrieval
		 */
		gluttpl->SetAccessor(v8::String::NewSymbol("ACTIVE_SHIFT"), GLUT::getACTIVE_SHIFT);
		gluttpl->SetAccessor(v8::String::NewSymbol("ACTIVE_CTRL"),  GLUT::getACTIVE_CTRL);
		gluttpl->SetAccessor(v8::String::NewSymbol("ACTIVE_ALT"),   GLUT::getACTIVE_ALT);
		gluttpl->Set(v8::String::NewSymbol("getModifiers"),         v8::FunctionTemplate::New(GLUT::handleGetModifiers));
		gluttpl->Set(v8::String::NewSymbol("extensionSupported"),   v8::FunctionTemplate::New(GLUT::handleExtensionSupported));


		/*
		 * Geometric Object Rendering
		 */
		gluttpl->Set(v8::String::NewSymbol("solidSphere"),       v8::FunctionTemplate::New(GLUT::handleSolidSphere));
		gluttpl->Set(v8::String::NewSymbol("wireSphere"),        v8::FunctionTemplate::New(GLUT::handleWireSphere));
		gluttpl->Set(v8::String::NewSymbol("solidCube"),         v8::FunctionTemplate::New(GLUT::handleSolidCube));
		gluttpl->Set(v8::String::NewSymbol("wireCube"),          v8::FunctionTemplate::New(GLUT::handleWireCube));
		gluttpl->Set(v8::String::NewSymbol("solidCone"),         v8::FunctionTemplate::New(GLUT::handleSolidCone));
		gluttpl->Set(v8::String::NewSymbol("WireCone"),          v8::FunctionTemplate::New(GLUT::handleWireCone));
		gluttpl->Set(v8::String::NewSymbol("solidTorus"),        v8::FunctionTemplate::New(GLUT::handleSolidTorus));
		gluttpl->Set(v8::String::NewSymbol("wireTorus"),         v8::FunctionTemplate::New(GLUT::handleWireTorus));
		gluttpl->Set(v8::String::NewSymbol("solidDodecahedron"), v8::FunctionTemplate::New(GLUT::handleSolidDodecahedron));
		gluttpl->Set(v8::String::NewSymbol("wireDodecahedron"),  v8::FunctionTemplate::New(GLUT::handleWireDodecahedron));
		gluttpl->Set(v8::String::NewSymbol("solidOctahedron"),   v8::FunctionTemplate::New(GLUT::handleSolidOctahedron));
		gluttpl->Set(v8::String::NewSymbol("wireOctahedron"),    v8::FunctionTemplate::New(GLUT::handleWireOctahedron));
		gluttpl->Set(v8::String::NewSymbol("solidTetrahedron"),  v8::FunctionTemplate::New(GLUT::handleSolidTetrahedron));
		gluttpl->Set(v8::String::NewSymbol("wireTetrahedron"),   v8::FunctionTemplate::New(GLUT::handleWireTetrahedron));
		gluttpl->Set(v8::String::NewSymbol("solidIcosahedron"),  v8::FunctionTemplate::New(GLUT::handleSolidIcosahedron));
		gluttpl->Set(v8::String::NewSymbol("wireIcosahedron"),   v8::FunctionTemplate::New(GLUT::handleWireIcosahedron));
		gluttpl->Set(v8::String::NewSymbol("solidTeapot"),       v8::FunctionTemplate::New(GLUT::handleSolidTeapot));
		gluttpl->Set(v8::String::NewSymbol("wireTeapot"),        v8::FunctionTemplate::New(GLUT::handleWireTeapot));

		return scope.Close(gluttpl);

	}

}



#include "glu.h"

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glu.h>
#else
	#include <GL/glu.h>
#endif


/*
 * OpenGL Graphics Utility Library Version 1.3
 *
 * The GLU bindings were implemented following the spec document available here:
 * http://www.opengl.org/registry/doc/glu1.3.pdf
 *
 * MISSING Bindings:
 *
 * - 2. from Initialization:
 *   > glu.getString()
 *
 * - 5. Polygon Tessellation (TODO)
 * - 6. Quadrics (TODO)
 * - 7. NURBS (non-uniform rational B-Splines, TODO)
 * - 8. Errors (TODO)
 *
 */



namespace binding {

	GLint* _toViewport(v8::Handle<v8::Value> value) {

		GLint* viewport = new GLint[4];

		v8::Handle<v8::Array> arr_viewport = v8::Handle<v8::Array>::Cast(value);

		for (unsigned i = 0; i < 4; i++) {
			v8::Handle<v8::Value> value(arr_viewport->Get(v8::Integer::New(i)));
			viewport[i] = (GLint) value->IntegerValue();
		}

		return viewport;

	}

	GLdouble* _toMatrix(v8::Handle<v8::Value> value) {

		GLdouble* matrix = new GLdouble[16];

		v8::Handle<v8::Array> arr_matrix = v8::Handle<v8::Array>::Cast(value);

		for (unsigned i = 0; i < 16; i++) {

			v8::Handle<v8::Value> value(arr_matrix->Get(v8::Integer::New(i)));
			matrix[i] = (GLdouble) value->NumberValue();

		}

		return matrix;

	}



	/*
	 * Initialization
	 */
	v8::Handle<v8::Value> GLU::handleCheckExtension(const v8::Arguments& args) {

		if (args.Length() == 2) {

			v8::Handle<v8::Array> arr_arg0 = v8::Handle<v8::Array>::Cast(args[0]);
			GLubyte* arg0 = new GLubyte[arr_arg0->Length()];

			for (unsigned i = 0; i < arr_arg0->Length(); i++) {
				v8::Handle<v8::Value> value0(arr_arg0->Get(v8::Integer::New(i)));
				arg0[i] = (GLubyte) value0->Uint32Value();
			}


			v8::Handle<v8::Array> arr_arg1 = v8::Handle<v8::Array>::Cast(args[1]);
			GLubyte* arg1 = new GLubyte[arr_arg1->Length()];

			for (unsigned i = 0; i < arr_arg1->Length(); i++) {
				v8::Handle<v8::Value> value1(arr_arg1->Get(v8::Integer::New(i)));
				arg1[i] = (GLubyte) value1->Uint32Value();
			}


			int result = gluCheckExtension((const GLubyte*) arg0, (const GLubyte*) arg1);

			// GL_TRUE is 1, GL_FALSE is 0
			if (result == 1) {
				return v8::True();
			}

		}

		return v8::False();

	}



	/*
	 * Matrix Manipulation
	 */

	// equivalent to glOrtho(left, right, bottom, top, -1, 1);
	v8::Handle<v8::Value> GLU::handleOrtho2D(const v8::Arguments& args) {

		if (args.Length() == 4) {

			double left   = args[0]->NumberValue();
			double right  = args[1]->NumberValue();
			double bottom = args[2]->NumberValue();
			double top    = args[3]->NumberValue();

			gluOrtho2D((GLdouble) left, (GLdouble) right, (GLdouble) bottom, (GLdouble) top);

		}

		return v8::Undefined();

	}


	/*
	 * fovy defines the field-of-view angle (in degrees) in the y direction.
	 * aspect is the aspect ratio used to determine the field-of-view in
	 * the x direction. It is the ratio of x (width) to y (height). near and
	 * far define the near and far clipping planes (as positive distances
	 * from the eye point).
	 */
	v8::Handle<v8::Value> GLU::handlePerspective(const v8::Arguments& args) {

		if (args.Length() == 4) {

			double fovy   = args[0]->NumberValue();
			double aspect = args[1]->NumberValue();
			double near   = args[2]->NumberValue();
			double far    = args[3]->NumberValue();

			gluPerspective((GLdouble) fovy, (GLdouble) aspect, (GLdouble) near, (GLdouble) far);

		}

		return v8::Undefined();

	}


	/*
	 * The viewing matrix created is based on an eye point (eye),
	 * a reference point that represents the center of the scene (center),
	 * and an up vector (up). The matrix is designed to map the center of
	 * the scene to the negative Z axis, so that when a typical projection
	 * matrix is used, the center of the scene will map to the center of
	 * the viewport. Similarly, the projection of the up vector on the
	 * viewing plane is mapped to the positive Y axis so that it will point
	 * upward in the viewport. The up vector must not be parallel to the
	 * line-of-sight from the eye to the center of the scene.
	 */
	v8::Handle<v8::Value> GLU::handleLookAt(const v8::Arguments& args) {

		if (args.Length() == 9) {

			double eyex    = args[0]->NumberValue();
			double eyey    = args[1]->NumberValue();
			double eyez    = args[2]->NumberValue();
			double centerx = args[3]->NumberValue();
			double centery = args[4]->NumberValue();
			double centerz = args[5]->NumberValue();
			double upx     = args[6]->NumberValue();
			double upy     = args[7]->NumberValue();
			double upz     = args[8]->NumberValue();

			gluLookAt(
				(GLdouble) eyex,    (GLdouble) eyey,    (GLdouble) eyez,
				(GLdouble) centerx, (GLdouble) centery, (GLdouble) centerz,
				(GLdouble) upx,     (GLdouble) upy,     (GLdouble) upz
			);

		}

		return v8::Undefined();

	}


	/*
	 * Should be called just before applying a projection matrix to the
	 * stack (effectively pre-multiplying the projection matrix by the
	 * selection matrix). x and y specify the center of the selection
	 * bounding box in pixel coordinates. deltax and deltay specify its
	 * width and height in pixels. viewport should specify the current
	 * viewport's x, y, width and height. A convenient way to obtain
	 * this information is to call gl.getIntegerv(gl.VIEWPORT, viewport);
	 */
	v8::Handle<v8::Value> GLU::handlePickMatrix(const v8::Arguments& args) {

		if (args.Length() == 5) {

			double x      = args[0]->NumberValue();
			double y      = args[1]->NumberValue();
			double deltax = args[2]->NumberValue();
			double deltay = args[3]->NumberValue();

			GLint* viewport = _toViewport(args[4]);

			gluPickMatrix(
				(GLdouble) x, (GLdouble) y,
				(GLdouble) deltax, (GLdouble) deltay,
				viewport
			);

		}

		return v8::Undefined();

	}

	v8::Handle<v8::Value> GLU::handleProject(const v8::Arguments& args) {

		if (args.Length() == 9) {

			double objx = args[0]->NumberValue();
			double objy = args[1]->NumberValue();
			double objz = args[2]->NumberValue();

			GLdouble* modelMatrix = _toMatrix(args[3]);
			GLdouble* projMatrix  = _toMatrix(args[4]);
			GLint*    viewport    = _toViewport(args[5]);

			double winx = args[6]->NumberValue();
			double winy = args[7]->NumberValue();
			double winz = args[8]->NumberValue();

			GLdouble *_winx = new GLdouble(winx);
			GLdouble *_winy = new GLdouble(winy);
			GLdouble *_winz = new GLdouble(winz);

			int result = gluProject(
				(GLdouble) objx, (GLdouble) objy, (GLdouble) objz,
				modelMatrix,
				projMatrix,
				viewport,
				_winx, _winy, _winz
			);

			delete _winx;
			delete _winy;
			delete _winz;


			// GL_TRUE is 1, GL_FALSE is 0
			if (result == 1) {
				return v8::True();
			}

		}

		return v8::False();

	}

	v8::Handle<v8::Value> GLU::handleUnProject(const v8::Arguments& args) {

		if (args.Length() == 9) {

			double winx = args[0]->NumberValue();
			double winy = args[1]->NumberValue();
			double winz = args[2]->NumberValue();

			GLdouble* modelMatrix = _toMatrix(args[3]);
			GLdouble* projMatrix  = _toMatrix(args[4]);
			GLint*    viewport    = _toViewport(args[5]);

			double objx = args[6]->NumberValue();
			double objy = args[7]->NumberValue();
			double objz = args[8]->NumberValue();

			GLdouble *_objx = new GLdouble(objx);
			GLdouble *_objy = new GLdouble(objy);
			GLdouble *_objz = new GLdouble(objz);

			int result = gluUnProject(
				(GLdouble) winx, (GLdouble) winy, (GLdouble) winz,
				modelMatrix,
				projMatrix,
				viewport,
				_objx, _objy, _objz
			);

			delete _objx;
			delete _objy;
			delete _objz;


			// GL_TRUE is 1, GL_FALSE is 0
			if (result == 1) {
				return v8::True();
			}

		}

		return v8::False();

	}

	v8::Handle<v8::Value> GLU::handleUnProject4(const v8::Arguments& args) {

		if (args.Length() == 9) {

			double winx = args[0]->NumberValue();
			double winy = args[1]->NumberValue();
			double winz = args[2]->NumberValue();
			double clipw = args[3]->NumberValue();

			GLdouble* modelMatrix = _toMatrix(args[4]);
			GLdouble* projMatrix  = _toMatrix(args[5]);
			GLint*    viewport    = _toViewport(args[6]);

			double near = args[7]->NumberValue();
			double far  = args[8]->NumberValue();

			double objx = args[9]->NumberValue();
			double objy = args[10]->NumberValue();
			double objz = args[11]->NumberValue();
			double objw = args[12]->NumberValue();

			GLdouble *_objx = new GLdouble(objx);
			GLdouble *_objy = new GLdouble(objy);
			GLdouble *_objz = new GLdouble(objz);
			GLdouble *_objw = new GLdouble(objw);


			int result = gluUnProject4(
				(GLdouble) winx, (GLdouble) winy, (GLdouble) winz, (GLdouble) clipw,
				modelMatrix,
				projMatrix,
				viewport,
				near,
				far,
				_objx, _objy, _objz, _objw
			);


			delete _objx;
			delete _objy;
			delete _objz;
			delete _objw;


			// GL_TRUE is 1, GL_FALSE is 0
			if (result == 1) {
				return v8::True();
			}

		}

		return v8::False();

	}






	v8::Handle<v8::ObjectTemplate> GLU::generate() {

		v8::HandleScope scope;

		v8::Handle<v8::ObjectTemplate> glutpl = v8::ObjectTemplate::New();


		/*
		 * Initialization
		 */
		glutpl->Set(v8::String::NewSymbol("checkExtension"), v8::FunctionTemplate::New(GLU::handleCheckExtension));


		/*
		 * Matrix Manipulation
		 */
		glutpl->Set(v8::String::NewSymbol("ortho2D"),     v8::FunctionTemplate::New(GLU::handleOrtho2D));
		glutpl->Set(v8::String::NewSymbol("perspective"), v8::FunctionTemplate::New(GLU::handlePerspective));
		glutpl->Set(v8::String::NewSymbol("lookAt"),      v8::FunctionTemplate::New(GLU::handleLookAt));
		glutpl->Set(v8::String::NewSymbol("pickMatrix"),  v8::FunctionTemplate::New(GLU::handlePickMatrix));
		glutpl->Set(v8::String::NewSymbol("project"),     v8::FunctionTemplate::New(GLU::handleProject));
		glutpl->Set(v8::String::NewSymbol("unProject"),   v8::FunctionTemplate::New(GLU::handleUnProject));
		glutpl->Set(v8::String::NewSymbol("unProject4"),  v8::FunctionTemplate::New(GLU::handleUnProject4));

//		glutpl->SetAccessor(v8::String::NewSymbol("RGBA"), GLU::getRGBA);


		return scope.Close(glutpl);

	}

}


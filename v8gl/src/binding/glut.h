
#ifndef BINDING_GLUT_H
#define BINDING_GLUT_H

#include <v8.h>


namespace binding {

	class GLUT {

		private:

			static v8::Handle<v8::Value> handleMainLoop(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleInit(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleInitWindowPosition(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleInitWindowSize(const v8::Arguments& args);

			static v8::Handle<v8::Value> getRGBA(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getRGB(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getINDEX(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getSINGLE(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getDOUBLE(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getACCUM(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getALPHA(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getDEPTH(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getSTENCIL(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getMULTISAMPLE(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getSTEREO(v8::Local<v8::String> property, const v8::AccessorInfo &info);
//			static v8::Handle<v8::Value> getLUMINANCE(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> handleInitDisplayMode(const v8::Arguments& args);

			static v8::Handle<v8::Value> handleCreateWindow(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleCreateSubWindow(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleGetWindow(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleSetWindow(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleDestroyWindow(const v8::Arguments& args);
			static v8::Handle<v8::Value> handlePostRedisplay(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleSwapBuffers(const v8::Arguments& args);
			static v8::Handle<v8::Value> handlePositionWindow(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleReshapeWindow(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleFullScreen(const v8::Arguments& args);
			static v8::Handle<v8::Value> handlePopWindow(const v8::Arguments& args);
			static v8::Handle<v8::Value> handlePushWindow(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleShowWindow(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleHideWindow(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleIconifyWindow(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleSetWindowTitle(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleSetIconTitle(const v8::Arguments& args);


			static v8::Handle<v8::Value> handleEstablishOverlay(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleRemoveOverlay(const v8::Arguments& args);
			static v8::Handle<v8::Value> handlePostOverlayRedisplay(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleShowOverlay(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleHideOverlay(const v8::Arguments& args);

			static v8::Handle<v8::Value> handleDisplayFunc(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleOverlayDisplayFunc(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleReshapeFunc(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleKeyboardFunc(const v8::Arguments& args);
			static v8::Handle<v8::Value> getLEFT_BUTTON(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getMIDDLE_BUTTON(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getRIGHT_BUTTON(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getUP(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getDOWN(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> handleMouseFunc(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleMotionFunc(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleIdleFunc(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleTimerFunc(const v8::Arguments& args);

			static v8::Handle<v8::Value> getACTIVE_SHIFT(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getACTIVE_CTRL(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> getACTIVE_ALT(v8::Local<v8::String> property, const v8::AccessorInfo &info);
			static v8::Handle<v8::Value> handleGetModifiers(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleExtensionSupported(const v8::Arguments& args);

			static v8::Handle<v8::Value> handleSolidSphere(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleWireSphere(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleSolidCube(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleWireCube(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleSolidCone(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleWireCone(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleSolidTorus(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleWireTorus(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleSolidDodecahedron(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleWireDodecahedron(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleSolidOctahedron(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleWireOctahedron(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleSolidTetrahedron(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleWireTetrahedron(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleSolidIcosahedron(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleWireIcosahedron(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleSolidTeapot(const v8::Arguments& args);
			static v8::Handle<v8::Value> handleWireTeapot(const v8::Arguments& args);

		public:

			static v8::Handle<v8::ObjectTemplate> generate(int* pargc, char** argv);

	};

}

#endif


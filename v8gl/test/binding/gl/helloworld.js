
var render = function() {

	gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
	gl.matrixMode(gl.MODELVIEW);
	gl.loadIdentity();

	// Trapezoid
	gl.begin(gl.QUADS);
	gl.vertex3f(-0.7, -1.5, -5.0)
	gl.vertex3f(0.7, -1.5, -5.0)
	gl.vertex3f(0.4, -0.5, -5.0)
	gl.vertex3f(-0.4, -0.5, -5.0)
	gl.end();


	// Pentagon
	gl.begin(gl.TRIANGLES);
 	gl.vertex3f(0.5, 0.5, -5.0)
	gl.vertex3f(1.5, 0.5, -5.0)
	gl.vertex3f(0.5, 1.0, -5.0)

	gl.vertex3f(0.5, 1.0, -5.0)
	gl.vertex3f(1.5, 0.5, -5.0)
	gl.vertex3f(1.5, 1.0, -5.0)

	gl.vertex3f(0.5, 1.0, -5.0)
	gl.vertex3f(1.5, 1.0, -5.0)
	gl.vertex3f(1.0, 1.5, -5.0)
	gl.end();


	// Triangle
	gl.begin(gl.TRIANGLES);
	gl.vertex3f(-0.5, 0.5, -5.0)
	gl.vertex3f(-1.0, 1.5, -5.0)
	gl.vertex3f(-1.5, 0.5, -5.0)
	gl.end();


	glut.swapBuffers();

};


(function(global) {

	var reshape = function(width, height) {

		gl.viewport(0, 0, width, height);
		gl.matrixMode(gl.PROJECTION);
		gl.loadIdentity();

		glu.perspective(45.0, width / height, 1.0, 200.0);

	};


	glut.initDisplayMode(glut.DOUBLE | glut.RGB | glut.DEPTH);

	glut.initWindowSize(640, 480);
	glut.createWindow("Hello World example with simple shapes");


	gl.enable(gl.DEPTH_TEST);
	gl.enable(gl.COLOR_MATERIAL);


	glut.displayFunc(render);
	glut.reshapeFunc(reshape);

})(this);


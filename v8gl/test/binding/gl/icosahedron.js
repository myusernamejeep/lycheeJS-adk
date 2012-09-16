
(function(global) {

	var angle = 0;
	var fps = 1000 / 60;

	var render = function() {

		gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

		gl.matrixMode(gl.MODELVIEW);
		gl.loadIdentity();

		gl.translatef(0.0, 0.0, -10.0);

		gl.lightModelfv(gl.LIGHT_MODEL_AMBIENT, [ 0.3, 0.3, 0.3, 1.0 ]);
		gl.lightfv(gl.LIGHT0, gl.DIFFUSE, [ 0.7, 0.7, 0.5, 1.0 ]);
		gl.lightfv(gl.LIGHT0, gl.POSITION, [10.0, 10.0, 10.0, 1.0]);

		gl.rotatef(angle, 1.0, 1.0, 1.0);


		gl.color3f(1.0, 0.0, 0.5);
		glut.solidIcosahedron();

		gl.translatef(1.0, -2.5, 0.0);
		gl.color3f(0.8, 0.6, 0.5);
		glut.solidOctahedron();

 		gl.translatef(1.0, 5.0, 0.0);
		gl.color3f(0.8, 0.6, 0.5);
		glut.solidOctahedron();



		glut.swapBuffers();

	};

	var reshape = function(width, height) {

		gl.viewport(0, 0, width, height);
		gl.matrixMode(gl.PROJECTION);
		gl.loadIdentity();

		glu.perspective(45.0, width / height, 1.0, 200.0);

	};

	var timer = function(data) {

		angle += 3;
		angle %= 360;


		// Uncomment to see how to use the passed data object
		// console.log("next timer()" + JSON.stringify(data));
		// data.angle = angle;

		glut.postRedisplay();

		// data passed to timerFunc callback is the last parameter
		glut.timerFunc(fps, timer, data);

	};



	glut.initDisplayMode(glut.DOUBLE | glut.RGB | glut.DEPTH);

	glut.initWindowSize(640, 480);
	glut.createWindow("Lighting example with Icosahedron and Octahedrons");

	gl.enable(gl.DEPTH_TEST);
	gl.enable(gl.COLOR_MATERIAL);
	gl.enable(gl.LIGHTING);
	gl.enable(gl.LIGHT0);
	gl.enable(gl.NORMALIZE);


	glut.displayFunc(render);
	glut.reshapeFunc(reshape);
	glut.timerFunc(fps, timer, {});

})(this);


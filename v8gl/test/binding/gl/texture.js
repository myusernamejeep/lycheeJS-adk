
(function(global) {

	var texA, texB;

	var drawSprite = function(texture, x, y) {

		var x1 = x,
			x2 = x + texture.width,
			y1 = y,
			y2 = y + texture.height;


		gl.matrixMode(gl.MODELVIEW);
		gl.loadIdentity();

		gl.bindTexture(gl.TEXTURE_2D, texture.id);
		gl.enable(gl.TEXTURE_2D);
		gl.begin(gl.QUADS);


		gl.texCoord2f(0, 0);
		gl.vertex2f(x1, y1);

		gl.texCoord2f(1, 0);
		gl.vertex2f(x2, y1);

		gl.texCoord2f(1, 1);
		gl.vertex2f(x2, y2);

		gl.texCoord2f(0, 1);
		gl.vertex2f(x1, y2);


		gl.end();
		gl.disable(gl.TEXTURE_2D);

	};

	var render = function() {

		gl.clearColor(0, 0, 0, 0);
		gl.clear(gl.COLOR_BUFFER_BIT);


		drawSprite(texA, 100, 100);
		drawSprite(texB, 200, 200);


		gl.flush();
		glut.swapBuffers();

	};


	glut.initDisplayMode(glut.DOUBLE | glut.RGBA);

	glut.initWindowSize(640, 480);
	glut.createWindow("Texture drawing example");


	gl.matrixMode(gl.PROJECTION);
	gl.loadIdentity();
	gl.ortho(0, 640, 480, 0, 0, 1);


	texA = new Texture('../../asset/texture.png');
	texB = new Texture('../../asset/texture.png');

	texA.onload = function() {

		texA.generate();
		console.log('texture loaded: ' + this.id + ' (' + this.width +'x' + this.height + ')');


		texB.onload = function() {

			texB.generate();
			console.log('texture loaded: ' + this.id + ' (' + this.width +'x' + this.height + ')');

			glut.displayFunc(render);

		};

		texB.load();

	};

	texA.load();

})(this);


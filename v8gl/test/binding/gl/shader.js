
(function(global) {

	// Text API is synchronous
	var _shaders = {};
	_shaders.vertex = new Text('./shader-vertex.vs');
	_shaders.vertex.load();
	_shaders.fragment = new Text('./shader-fragment.fs');
	_shaders.fragment.load();


	var program = gl.createProgram();

	var vsHandle = gl.createShader(gl.VERTEX_SHADER);

	gl.shaderSource(vsHandle, _shaders['vertex'].data);
	gl.compileShader(vsHandle);

	var fsHandle = gl.createShader(gl.FRAGMENT_SHADER);

	gl.shaderSource(fsHandle, _shaders['fragment'].data);
	gl.compileShader(fsHandle);


	gl.attachShader(program, vsHandle);
	gl.attachShader(program, fsHandle);


	var arr = gl.getAttachedShaders(program);

	console.debug(arr);

	gl.linkProgram(program);
	gl.useProgram(program);


})(this);


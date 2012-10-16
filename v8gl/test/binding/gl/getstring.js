
(function(global) {

	var vendor = gl.getString(gl.VENDOR);
	console.log('vendor', vendor);

	var renderer = gl.getString(gl.RENDERER);
	console.log('renderer', renderer);

	var version = gl.getString(gl.VERSION);
	console.log('version', version);

})(this);


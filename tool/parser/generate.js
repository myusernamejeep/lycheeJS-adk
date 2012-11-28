
// var debug = true;
var debug = false;

var _ = { headers: {}, code: {} };
var raw = { headers: {}, code: {} };
var buffer = [];



var find_in_gl_headers = function(token) {

	var is_comment = false;



	/*
	 * Check OpenGL headers
	 */

	for (var g = 0, l = _.headers.gl.length; g < l; g++) {

		var current = _.headers.gl[g].trim();
		if (current === '') continue;


		// Ignore preprocessor instructions
		if (current.substr(0, 2) === '/*') {
			is_comment = true;
		}

		if (is_comment === false) {

			if (current.substr(0, 1) === '#') {
				current = current.replace('/^#\s\s*/', 'ASD');
			}


			// Constants
			if (
				token.type === 'enum'
				&& current.substr(0, 11) === '#define GL_'
			) {

				var str = '#define GL_' + token.name.toUpperCase();
				if (current.substr(0, str.length) === str) {
					token.gl = true;
					break;
				}

			} else if (
				token.type === 'method'
				&& current.substr(0, 24) === 'GLAPI void GLAPIENTRY gl'
				&& current.indexOf('(') > 0
			) {

				var str = 'GLAPI void GLAPIENTRY gl' + token.name.charAt(0).toUpperCase() + token.name.substr(1);
				if (current.substr(0, current.indexOf('(')).trim() === str) {
					token.gl = true;
					break;
				}

			} else if (
				token.type === 'method'
				&& current.substr(0, 22) === 'GLAPI void APIENTRY gl'
				&& current.indexOf('(') > 0
			) {

				var str = 'GLAPI void APIENTRY gl' + token.name.charAt(0).toUpperCase() + token.name.substr(1);
				if (current.substr(0, current.indexOf('(')).trim() === str) {
					token.gl = true;
					break;
				}

			}

		}

		is_comment = false;

	}



	/*
	 * Check OpenGL ES (2.0) headers
	 */

	for (var ge = 0, le = _.headers.gles.length; ge < le; ge++) {

		var current = _.headers.gles[ge].trim();

		if (current === '') continue;

		// Ignore preprocessor instructions
		if (current.substr(0, 2) === '/*') {
			is_comment = true;
		}

		if (is_comment === false) {

			if (current.substr(0, 1) === '#') {
				current = current.replace('/^#\s\s*/', 'ASD');
			}


			// Constants
			if (
				token.type === 'enum'
				&& current.substr(0, 11) === '#define GL_'
			) {

				var str = '#define GL_' + token.name.toUpperCase();
				if (current.substr(0, str.length) === str) {
					token.gles = true;
					break;
				}

			} else if (
				token.type === 'method'
				&& current.substr(0, 38) === 'GL_APICALL void         GL_APIENTRY gl'
			) {

				var str = 'GL_APICALL void         GL_APIENTRY gl' + token.name.charAt(0).toUpperCase() + token.name.substr(1);

				if (current.substr(0, str.length) === str) {
					token.gles = true;
					break;
				}

			}

		}

		is_comment = false;

	}


//	if (debug === true && token.gl === false && token.gles === false) {
//		console.warn('WebGL Token', token.type, token.name);
//	}

};



var find_in_gl_code = function(token, silent) {

	silent = silent === true ? true : false;


	for (var g = 0, l = _.code.gl.length; g < l; g++) {

		var current = _.code.gl[g].trim();
		if (current === '') continue;

		var prefix = 'gltpl->Set(v8::String::NewSymbol("' + token.name + '")';


		// Constants
		if (
			token.type === 'enum'
			&& current.substr(0, prefix.length) === prefix
		) {

			return true;

		} else if (
			token.type === 'method'
			&& current.substr(0, prefix.length) === prefix
		) {

			return true;

		}

	}


	if (debug === true && silent === false) {
		console.warn("GL Token not in code", token.type, token.name);
	}


	return false;

};

var find_in_gles_code = function(token) {

	for (var g = 0, l = _.code.gles.length; g < l; g++) {

		var current = _.code.gles[g].trim();
		if (current === '') continue;

		var prefix = 'glestpl->Set(v8::String::NewSymbol("' + token.name + '")';


		// Constants
		if (
			token.type === 'enum'
			&& current.substr(0, prefix.length) === prefix
		) {

			return true;

		} else if (
			token.type === 'method'
			&& current.substr(0, prefix.length) === prefix
		) {

			return true;

		}

	}


	if (debug === true) {
		console.warn("GLES Token not in code", token.type, token.name);
	}


	return false;

};



/*
 * WebGL API is implemented and added to
 * the origin gltpl inside the gl.cpp
 */

var find_in_webgl_code = function(token) {

	var found = find_in_gl_code(token, true);

	if (found === false && debug === true ) {
		console.warn("WebGL Token not in code", token.type, token.name);
	}


	return found;

};


var generate_token = function(line) {

	line = line.trim();

	var tmp, sig;
	var token = {
		gl: false,
		gles: false,
		type: null,
		name: null,
		signature: null
	};


	// Skip empty lines
	if (line === '') return token;


	var prefix_enum = 'const GLenum';

	if (line.substr(0, 2) === '/*') {

		token.type = 'comment';

		tmp = line.substr(2);

		if (tmp.indexOf('*/') >= 0) {
			tmp = tmp.substr(0, tmp.indexOf('*/')).trim();
		}

		token.name = tmp;


	// ENUM
	} else if (line.substr(0, prefix_enum.length) === prefix_enum) {

		token.type = 'enum';

		tmp = line.substr(prefix_enum.length);
		tmp = tmp.substr(0, tmp.indexOf('=')).trim();

		token.name = tmp;


	// METHOD
	} else if (
		line.split(' ')[0].match(/any|void|DOMString|GLboolean|GLenum|GLint|WebGLActiveInfo|WebGLBuffer|WebGLFramebuffer|WebGLRenderbuffer|WebGLProgram|WebGLShader|WebGLTexture|WebGLUniformLocation/)
	) {

		token.type = 'method';

		var spec_retval = line.split(' ')[0];

		switch(spec_retval) {
			case 'any':                  token.retval = 'v8::Value';                    break;
			case 'boolean':              token.retval = 'v8::Boolean';                  break;
			case 'void':                 token.retval = 'v8::Undefined';                break;
			case 'DOMString':            token.retval = 'v8::String';                   break;
			case 'DOMString[':           token.retval = 'v8::Array(v8::String)';        break;
			case 'GLboolean':            token.retval = 'v8::Boolean';                  break;
			case 'GLenum':               token.retval = 'v8::Uint32';                   break;
			case 'GLint':                token.retval = 'v8::Integer';                  break;
			case 'WebGLActiveInfo':      token.retval = 'api::WebGLActiveInfo';         break;
			case 'WebGLBuffer':          token.retval = 'api::WebGLBuffer';             break;
			case 'WebGLFramebuffer':     token.retval = 'api::WebGLFramebuffer';        break;
			case 'WebGLRenderbuffer':    token.retval = 'api::WebGLRenderbuffer';       break;
			case 'WebGLProgram':         token.retval = 'api::WebGLProgram';            break;
			case 'WebGLShader':          token.retval = 'api::WebGLShader';             break;
			case 'WebGLShader[':         token.retval = 'v8::Array(api::WebGLShader)';  break;
			case 'WebGLTexture':         token.retval = 'api::WebGLTexture';            break;
			case 'WebGLUniformLocation': token.retval = 'api::WebGLUniformLocation';    break;

			default:

				if (debug === true) {
					console.warn('No predefined return value for specification of ' + spec_retval);
				}

				token.returnval = spec_retval;

			break;
		}


		tmp = line.split(' ');
		tmp.reverse();
		tmp.pop();
		tmp.reverse();
		tmp = tmp.join(' ');

		if (tmp.charAt(0) === ']') {
			tmp = tmp.substr(2);
		}


		token.name = tmp.substr(0, tmp.indexOf('('));

		sig = tmp.substr(tmp.indexOf('('), tmp.indexOf(')')).split(',');

		for (var s = 0, l = sig.length; s < l; s++) {
			sig[s] = sig[s].trim();
		}

		token.signature = sig;

	} else if (debug === true ){
		console.error('Invalid Token', line);
	}

	return token;

};


var generate = function(token) {

	var _gltype = 'gl';
	if (token.gl !== true && token.gles === true) _gltype = 'gles';
	if (token.gl !== true && token.webgl === true) _gltype = 'webgl';

	if (token.type === 'comment') {
		return '\n/* ' + token.name + ' */\n';
	} else if (token.type === 'enum') {
		return _gltype + 'tpl->Set(v8::String::NewSymbol("' + token.name + '"), v8::Uint32::New(GL_' + token.name + '), v8::ReadOnly);';
	} else if (token.type === 'method') {
		return _gltype + 'tpl->Set(v8::String::NewSymbol("' + token.name + '"), v8::FunctionTemplate::New(' + _gltype.toUpperCase() + '::handle' + token.name.charAt(0).toUpperCase() + token.name.substr(1) + ');';
	}

};


String.prototype.trim = function() {
	return this.replace(/^\s\s*/, '').replace(/\s\s*$/, '');
};



(function(global) {


	raw.headers.webgl = new Text('./webgl.h');
	raw.headers.webgl.load();

	raw.headers.gl = new Text('./gl.h');
	raw.headers.gl.load();

	raw.headers.glext = new Text('./glext.h');
	raw.headers.glext.load();

	raw.headers.gles = new Text('./gles.h');
	raw.headers.gles.load();

	raw.code.gl = new Text('../../v8gl/src/binding/gl.cpp');
	raw.code.gl.load();

	raw.code.gles = new Text('../../v8gl/src/binding/gles.cpp');
	raw.code.gles.load();

	raw.code.webgl = new Text('../../v8gl/src/binding/webgl.cpp');
	raw.code.webgl.load();



	_.headers.gl    = (raw.headers.gl.data + '\n' + raw.headers.glext.data).split('\n');
	_.headers.gles  = raw.headers.gles.data.split('\n');
	_.headers.webgl = raw.headers.webgl.data.split('\n');

	_.code.gl       = raw.code.gl.data.split('\n');
	_.code.gles     = raw.code.gles.data.split('\n');
	_.code.webgl    = raw.code.webgl.data.split('\n');


	var cache = {
		gl: [],
		gles: [],
		webgl: []
	};

	var token;

	for (var w = 0, l = _.headers.webgl.length; w < l; w++) {

		token = generate_token(_.headers.webgl[w]);

		if (token.type === null) continue;

		// Evaluate if comments are somehow cool.
		// Pretty no meaningful comments in their headers -_-
		if (token.type === 'comment') continue;


		find_in_gl_headers(token);


		if (
			token.gl === true
		) {
			if (find_in_gl_code(token) === false) {
				cache.gl.push(token);
			}
		} else if (
			token.gles === true
		) {
			if (find_in_gles_code(token) === false) {
				cache.gles.push(token);
			}
		} else {

			if (find_in_webgl_code(token) === false) {
				token.webgl = true;
				cache.webgl.push(token);
			}
		}

	}



	for (var binding in cache) {

		buffer.push('\n\n\n\n\n\n');
		buffer.push('/* ' + binding.toUpperCase() + ' BINDINGS */');


		var token, t, tl;

		buffer.push('\n\n/* ' + binding.toUpperCase() + ' Enums */\n');
		for (t = 0, tl = cache[binding].length; t < tl; t++) {
			token = cache[binding][t];
			if (token.type === 'enum') { buffer.push(generate(token)); }
		}

		buffer.push('\n\n/* ' + binding.toUpperCase() + ' Methods */\n');
		for (t = 0, tl = cache[binding].length; t < tl; t++) {
			token = cache[binding][t];
			if (token.type === 'method') { buffer.push(generate(token)); }
		}

	}


	if (debug === false) {
		console.log(buffer.join('\n'));
	}

})(this);


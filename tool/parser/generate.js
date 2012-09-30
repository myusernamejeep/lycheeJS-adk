
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
			) {

				var str = 'GLAPI void GLAPIENTRY gl' + token.name.charAt(0).toUpperCase() + token.name.substr(1);

				if (current.substr(0, str.length) === str) {
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

};


var generate_token = function(line) {

	line = line.trim();

	var tmp, sig;
	var token = {
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
		token.signature = false;


	// ENUM
	} else if (line.substr(0, prefix_enum.length) === prefix_enum) {

		token.type = 'enum';

		tmp = line.substr(prefix_enum.length);
		tmp = tmp.substr(0, tmp.indexOf('=')).trim();

		token.name = tmp;
		token.signature = false;


	// METHOD
	} else if (
		line.split(' ')[0].match(/any|void|DOMString|GLboolean|GLenum|GLint|WebGLActiveInfo|WebGLBuffer|WebGLFramebuffer|WebGLRenderbuffer|WebGLProgram|WebGLShader|WebGLTexture|WebGLUniformLocation/)
	) {

		token.type = 'method';

		var spec_retval = line.split(' ')[0];

		switch(spec_retval) {
			case 'any':                  token.returnval = 'v8::Value';                    break;
			case 'boolean':              token.returnval = 'v8::Boolean';                  break;
			case 'void':                 token.returnval = 'v8::Undefined';                break;
			case 'DOMString':            token.returnval = 'v8::String';                   break;
			case 'DOMString[':           token.returnval = 'v8::Array(v8::String)';        break;
			case 'GLboolean':            token.returnval = 'v8::Boolean';                  break;
			case 'GLenum':               token.returnval = 'v8::Uint32';                   break;
			case 'GLint':                token.returnval = 'v8::Integer';                  break;
			case 'WebGLActiveInfo':      token.returnval = 'api::WebGLActiveInfo';         break;
			case 'WebGLBuffer':          token.returnval = 'api::WebGLBuffer';             break;
			case 'WebGLFramebuffer':     token.returnval = 'api::WebGLFramebuffer';        break;
			case 'WebGLRenderbuffer':    token.returnval = 'api::WebGLRenderbuffer';       break;
			case 'WebGLProgram':         token.returnval = 'api::WebGLProgram';            break;
			case 'WebGLShader':          token.returnval = 'api::WebGLShader';             break;
			case 'WebGLShader[':         token.returnval = 'v8::Array(api::WebGLShader)';  break;
			case 'WebGLTexture':         token.returnval = 'api::WebGLTexture';            break;
			case 'WebGLUniformLocation': token.returnval = 'api::WebGLUniformLocation';    break;

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

	raw.headers.glext = new Text('./gl.h');
	raw.headers.glext.load();

	raw.headers.gles = new Text('./gles.h');
	raw.headers.gles.load();

	raw.code.gl    = new Text('../../v8gl/src/binding/gl.cpp');
	raw.code.gl.load();

	raw.code.webgl = new Text('../../v8gl/src/binding/webgl.cpp');
	raw.code.webgl.load();



	_.headers.gl    = (raw.headers.gl.data + '\n' + raw.headers.glext.data).split('\n');
	_.headers.gles  = raw.headers.gles.data.split('\n');
	_.headers.webgl = raw.headers.webgl.data.split('\n');


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


		if (token.gl === true) {
			cache.gl.push(token);
		} else if (token.gles === true) {
			cache.gles.push(token);
		} else {
			token.webgl = true;
			cache.webgl.push(token);
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


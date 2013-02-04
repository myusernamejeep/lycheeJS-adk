
(function(global, adk, shell) {

	adk.Builder = function(main) {

		this.__main = main;

		var root = this.__main.getRoot();

		this.__paths = {
			v8:   root + '/external/v8',
			v8gl: root + '/v8gl',
			png:  root + '/external/libpng',
		};

	};


	adk.Builder.prototype = {

		/*
		 * PRIVATE API
		 */

		__getPath: function(what) {
			return this.__paths[what] || null;
		},



		/*
		 * PUBLIC API
		 */

		buildPNG: function(arch, path, asLibrary) {
		},

		buildV8: function(arch, path, asLibrary) {
		},

		buildV8GL: function(arch, path, asLibrary) {

			arch = typeof arch === 'string' ? arch : null;
			path = typeof path === 'string' ? path : null;
			asLibrary = asLibrary === true;


			var cmd, path, target;


			// Build required libraries
			path = this.__getPath('v8gl') + '/lib/' + arch;
			this.buildPNG(arch, path + '/libpng.a', true);
			this.buildV8(arch, path + '/libv8_*.a', true);



			// Build V8GL
			path   = this.__getPath('v8gl');
			target = this.__main.getBuildTarget(arch);

console.log('building v8gl now!', target, path, asLibrary);

			cmd = 'cd "' + path + '"; make ' + target + ';';
			shell.exec(cmd);


		}

	};

})(this, this.adk, this.shell);


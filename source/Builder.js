
(function(global, adk, shell) {

	adk.Builder = function(main) {

		this.__main = main;

		var root = this.__main.getRoot();

		this.__paths = {
			'android-ndk': root + '/external/android-ndk',
			'android-sdk': root + '/external/android-sdk',
			'v8':          root + '/external/v8',
			'v8gl':        root + '/v8gl',
			'png':         root + '/external/libpng',
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

		buildPNG: function(arch, toFile, asLibrary) {

			arch   = typeof arch === 'string' ? arch : null;
			toFile = typeof toFile === 'string' ? toFile : null;
			asLibrary = asLibrary === true;


			var cmd = '', path = '', target = '';


			// Build PNG
			path   = this.__getPath('png');
			target = this.__main.getBuildTarget(arch);

			cmd = 'cd "' + path + '";';
			if (arch.substr(0, 7) === 'android') {
				cmd += 'export ANDROID_NDK_ROOT="' + this.__getPath('android-ndk') + '";';
			}
			cmd += 'make ' + target + ';';

			shell.exec(cmd);


			if (toFile !== null) {

				if (asLibrary === true) {
					shell.copyFile(path + '/out/' + target + '/libpng.a', toFile);
				} else {
					console.error('Can\'t build PNG library as standalone program');
				}

			}

		},

		buildV8: function(arch, path, asLibrary) {

			arch   = typeof arch === 'string' ? arch : null;
			toFile = typeof toFile === 'string' ? toFile : null;
			asLibrary = asLibrary === true;


			var cmd = '', path = '', target = '';


			// Build PNG
			path   = this.__getPath('v8');
			target = this.__main.getBuildTarget(arch);

			cmd = 'cd "' + path + '";';
			if (arch.substr(0, 7) === 'android') {
				cmd += 'export ANDROID_NDK_ROOT="' + this.__getPath('android-ndk') + '";';
			}
			cmd += 'export snapshot=off;'; // disable v8 snapshots, as they are not supported on most SDKs
			cmd += 'make ' + target + ';';

			shell.exec(cmd);


			if (toFile !== null) {

				if (asLibrary === true) {

					var toFileBase       = toFile.replace('*', 'base');
					var toFileNoSnapshot = toFile.replace('*', 'nosnapshot');

					shell.copyFile(path + '/out/' + target + '/obj.target/tools/gyp/libv8_base.a',       toFileBase);
					shell.copyFile(path + '/out/' + target + '/obj.target/tools/gyp/libv8_nosnapshot.a', toFileNoSnapshot);

				} else {
					console.error('Can\'t build V8 library as standalone program');
				}

			}

		},

		buildV8GL: function(arch, toFile, asLibrary) {

			arch   = typeof arch === 'string' ? arch : null;
			toFile = typeof toFile === 'string' ? toFile : null;
			asLibrary = asLibrary === true;


			var cmd = '', path = '', target = '';


			// Build required libraries
			path = this.__getPath('v8gl') + '/lib/' + arch;

			this.buildPNG(arch, path + '/libpng.a', true);
			this.buildV8(arch, path + '/libv8_*.a', true);



			// Build V8GL
			path   = this.__getPath('v8gl');
			target = this.__main.getBuildTarget(arch);

			cmd = 'cd "' + path + '";';
			if (arch.substr(0, 7) === 'android') {
				cmd += 'export ANDROID_NDK_ROOT="' + this.__getPath('android-ndk') + '";';
			}
			cmd += 'make ' + target + ';';

			shell.exec(cmd);


			if (toFile !== null) {

				if (asLibrary === true) {
					shell.copyFile(path + '/out/' + target + '/libv8gl.a', toFile);
				} else {
					shell.copyFile(path + '/out/' + target + '/v8gl', toFile);
				}

			}

		}

	};

})(this, this.adk, this.shell);


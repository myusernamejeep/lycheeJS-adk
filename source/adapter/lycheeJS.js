
(function(global, adk, shell) {

	// Routine required for installation
	var _url = 'https://github.com/martensms/lycheeJS/zipball/master';
	var _install = function(temp, path) {

		if (shell.isDirectory(temp) === false) {
			shell.createDirectory(temp, true);
		}


		var cmd = '';

		if (shell.isDirectory(path) === false) {

			shell.createDirectory(path, true);

			cmd = 'wget -O ' + temp + '/lycheeJS.zip ' + _url + ';';
			shell.exec(cmd);

			if (shell.isFile(temp + '/lycheeJS.zip') === true) {

				cmd = 'unzip ' + temp + '/lycheeJS.zip -d ' + temp + ';';
				shell.exec(cmd);

				cmd = 'mv ' + temp + '/martensms-lycheeJS-*/* ' + path + ';';
				shell.exec(cmd);


				return true;

			}

		}


		return false;

	};

	adk.adapter.lycheeJS = function(main) {

		this.__main = main;

	};


	adk.adapter.lycheeJS.DESCRIPTION = 'Games made with the lycheeJS engine (http://martens.ms/lycheeJS).';


	adk.adapter.lycheeJS.prototype = {

		/*
		 * Helpers
		 */

		__generateMain: function(gameenv, buildenv) {

			var temp = this.__main.getTemporaryFolder() + '/main.js';

			// Use the new target folders, which were
			// linked by the Adapter and updated by
			// the Template
			var bases = {};
			for (var baseId in buildenv.bases) {
				bases[baseId] = buildenv.bases[baseId][1];
			}


			if (gameenv._build === null) {
				console.error('Could not parse lychee.build(callback, scope) in init.js');
				return null;
			}


			var code = '';

			code += 'lychee.debug = ' + gameenv.debug + ';\n';
			code += 'lychee.rebase(' + JSON.stringify(bases) + ');\n';
			code += 'lychee.tag(' + JSON.stringify(gameenv.tags) + ');\n';
			code += 'lychee.build(' + gameenv._build + ', this);\n';

			if (fs.write(temp, code) === true) {
				return temp;
			} else {
				return null;
			}

		},

		__getEnvironment: function(folder) {

			var env  = {
				data: {
					bases: {},
					tags: {}
				},
				folders: [],
				files:   []
			};

			var temp = this.__main.getTemporaryFolder() + '/lycheeJS_parser';

			if (shell.isDirectory(temp) === true) {
				shell.removeDirectory(temp);
			}


			if (shell.createDirectory(temp) === true) {

				var builder = this.__main.getBuilder();
				var arch    = this.__main.getHostArch();

				builder.buildV8GL(arch, temp + '/v8gl');

				shell.copyFile('./source/adapter/raw/lycheeJS/main.js', temp + '/main.js');
				shell.copyFile(folder + '/init.js', temp + '/init.js');

				shell.exec('cd "' + temp + '" && ./v8gl;');


				if (shell.isFile(temp + '/env.json') === true) {

					var data = null;
					var raw  = fs.read(temp + '/env.json');
					if (raw !== null) {

						try {
							data = JSON.parse(raw);
						} catch(e) {
						};

					}

					if (data !== null) {

						for (var namespace in data.bases) {
							var arr = [ folder + '/' + data.bases[namespace], './' + namespace ];
							env.data.bases[namespace] = arr;
							env.folders.push(arr);
						}

						for (var tagId in data.tags) {
							env.data.tags[tagId] = data.tags[tagId];
						}


						var assetdir = folder + '/asset';
						if (shell.isDirectory(assetdir) === true) {
							env.folders.push([ assetdir, './asset' ]);
						}

						var mainjs = this.__generateMain(data, env.data);
						if (mainjs !== null) {
							env.files.push([ mainjs, './main.js' ]);
						}

					}

				}

			}


			return env;

		},

		/*
		 * Bootstrapping
		 */

		bootstrap: function() {

			var temp = this.__main.getTemporaryFolder();

			if (shell.isDirectory('./external/lycheeJS') === true) {
				shell.removeDirectory('./external/lycheeJS');
			}

			_install(temp, './external/lycheeJS');

		},

		getEnvironment: function(folder) {

			if (shell.isDirectory('./external/lycheeJS') === false) {
				_install(this.__main.getTemporaryFolder(), './external/lycheeJS');
			}


			return this.__getEnvironment(folder);

		}

	};

})(this, this.adk, this.shell);


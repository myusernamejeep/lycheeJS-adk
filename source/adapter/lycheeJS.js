
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

		__getEnvironment: function(folder) {

			var env  = null;
			var temp = this.__main.getTemporaryFolder() + '/lycheeJS_parser';

			if (shell.isDirectory(temp) === true) {
				shell.removeDirectory(temp);
			}


			if (shell.createDirectory(temp) === true) {

				var builder = this.__main.getBuilder();

				builder.build('v8gl', temp + '/v8gl');

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

console.log('WOAH, it worked!', data);

					}

				}

			}

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

		getTree: function(folder) {

			if (shell.isDirectory('./external/lycheeJS') === false) {
				_install(this.__main.getTemporaryFolder(), './external/lycheeJS');
			}


			var env = this.__getEnvironment(folder);

			console.log('game directory', directory);

		}

	};

})(this, this.adk, this.shell);


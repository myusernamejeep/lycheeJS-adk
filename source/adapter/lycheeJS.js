
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
		 * Bootstrapping
		 */

		bootstrap: function() {

			var temp = this.__main.getTemporaryFolder();

			if (shell.isDirectory('./external/lycheeJS') === false) {
				shell.removeDirectory('./external/lycheeJS');
			}

			_install(temp, './external/lycheeJS');

		},

		getTree: function(directory) {

			var temp = this.__main.getTemporaryFolder();

			if (shell.isDirectory('./external/lycheeJS') === false) {
				_install(temp, './external/lycheeJS');
			}

			console.log('game directory', directory);


		}

	};

})(this, this.adk, this.shell);


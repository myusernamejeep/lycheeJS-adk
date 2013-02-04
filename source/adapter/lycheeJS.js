
(function(global, adk, shell) {

	// Routine required for installation
	var _install = function(temp, path) {

		var cmd = '';

		console.info()


	};

	adk.adapter.lycheeJS = function(main) {

		this.__main = main;

	};


	adk.adapter.lycheeJS.DESCRIPTION = 'Games made with the lycheeJS engine (http://martens.ms/lycheeJS).';


	adk.adapter.lycheeJS.prototype = {

		getTree: function(directory) {

			var temp = this.__main.getTemporaryFolder();

			if (shell.isDirectory('./external/lycheeJS') === false) {
				_install(temp, './external/lycheeJS');
			}


			console.log('game directory', directory);


		}

	};

})(this, this.adk, this.shell);


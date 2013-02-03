
(function(global, adk) {

	var shell = {};


	// Identical API, so reuse it
	shell.exec = os.exec;

	shell.isDirectory = function(directory) {

		var cmd = 'if [ -d "' + directory + '" ]; then echo "true"; else echo "false"; fi;';
		var result = shell.exec(cmd);

		return result === 'true';

	};


	return shell;

})(this, this.adk);


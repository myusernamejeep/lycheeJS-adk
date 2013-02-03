
this.shell = {};

(function(global, adk, shell) {

	// Identical API, so reuse it
	shell.exec = os.exec;

	shell.isDirectory = function(path) {

		var cmd = 'if [ -d "' + path + '" ]; then echo "true"; else echo "false"; fi;';
		var result = shell.exec(cmd);

		return result === 'true';

	};

	shell.isFile = function(path) {

		var cmd = 'if [ -f "' + path + '" ]; then echo "true"; else echo "false"; fi;';
		var result = shell.exec(cmd);

		return result === 'true';

	};


})(this, this.adk, this.shell);


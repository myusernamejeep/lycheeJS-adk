
this.shell = {};

(function(global, adk, shell) {

	// Identical API, so reuse it
	shell.exec = os.exec;

	shell.isDirectory = function(path) {

		path = typeof path === 'string' ? path : null;


		if (path !== null) {

			var cmd = 'if [ -d "' + path + '" ]; then echo "true"; else echo "false"; fi;';
			var result = shell.exec(cmd);

			return result === 'true';

		}


		return false;

	};

	shell.isFile = function(path) {

		path = typeof path === 'string' ? path : null;


		if (path !== null) {

			var cmd = 'if [ -f "' + path + '" ]; then echo "true"; else echo "false"; fi;';
			var result = shell.exec(cmd);

			return result === 'true';

		}


		return false;

	};

	shell.createDirectory = function(path, parents) {

		path = typeof path === 'string' ? path : null;
		parents = parents === true;


		if (path !== null) {

			var cmd = 'mkdir "' + path + '";';
			if (parents === true) {
				cmd = 'mkdir -p "' + path + '";';
			}

			shell.exec(cmd);

			return shell.isDirectory(path);

		}


		return false;

	};


})(this, this.adk, this.shell);


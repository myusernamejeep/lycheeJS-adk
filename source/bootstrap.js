
this.shell = {};

(function(global, adk, shell) {

	// Identical API, so reuse it

	shell.exec = function(command) {

		if (adk.debug === true) {

			if (
				shell.isFile('./log') === true
				&& command.charAt(command.length - 1) === ';'
			) {
				command = command.substr(0, command.length - 1) + ' >> ./log 2>&1;';
			}

		}


		os.exec(command);

	};

	shell.exec = os.exec;

	shell.isDirectory = function(path) {

		path = typeof path === 'string' ? path : null;


		if (path !== null) {

			var cmd = 'if [ -d "' + path + '" ]; then echo "true"; else echo "false"; fi;';
			var result = os.exec(cmd);

			return result === 'true';

		}


		return false;

	};

	shell.isFile = function(path) {

		path = typeof path === 'string' ? path : null;


		if (path !== null) {

			var cmd = 'if [ -f "' + path + '" ]; then echo "true"; else echo "false"; fi;';
			var result = os.exec(cmd);

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

			os.exec(cmd);

			return shell.isDirectory(path);

		}


		return false;

	};


})(this, this.adk, this.shell);


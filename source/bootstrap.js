
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

	shell.copyDirectory = function(from, to) {

		from = typeof from === 'string' ? from : null;
		to   = typeof to === 'string' ? to : null;


		if (
			from !== null
			&& to !== null
			&& shell.isDirectory(from) === true
			&& shell.isDirectory(to) === false
		) {

			var cmd = 'cp -r "' + from + '" "' + to + '";';

			os.exec(cmd);

			return shell.isDirectory(to) === true;

		}


		return false;

	};

	shell.copyFile = function(from, to) {

		from = typeof from === 'string' ? from : null;
		to   = typeof to === 'string' ? to : null;


		if (
			from !== null
			&& to !== null
			&& shell.isFile(from) === true
			&& shell.isFile(to) === false
		) {

			var cmd = 'cp "' + from + '" "' + to + '";';

			os.exec(cmd);

			return shell.isFile(to) === true;

		}


		return false;

	};

	shell.removeDirectory = function(path) {

		path = typeof path === 'string' ? path : null;


		if (
			path !== null
			&& shell.isDirectory(path) === true
		) {

			var cmd = 'rm -rf "' + path + '";';

			os.exec(cmd);


			return shell.isDirectory(path) === false;

		}


		return false;

	};

	shell.removeFile = function(path) {

		path = typeof path === 'string' ? path : null;


		if (
			path !== null
			&& shell.isFile(path) === true
		) {

			var cmd = 'rm "' + path + '";';

			os.exec(cmd);


			return shell.isFile(path) === false;

		}


		return false;

	};


})(this, this.adk, this.shell);


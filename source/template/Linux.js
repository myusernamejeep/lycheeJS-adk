
(function(global, adk, shell) {

	adk.template.Linux = function(main) {

		this.__main = main;

	};


	adk.template.Linux.DESCRIPTION = 'Linux builds with V8GL (requires OpenGL 2.1 on targeted system).';


	adk.template.Linux.prototype = {

		getEnvironment: function(folder, env) {
			// Don't modify the paths, keep them as the Adapter requested it
			return env;
		},

		build: function(folder, arch) {

			var builder = this.__main.getBuilder();

			builder.buildV8GL(arch, folder + '/v8gl', false);


		},

		clean: function() {
		},

		debug: function(folder, arch) {

			console.log('DEBUGGING...');

			var valgrindlog = this.__main.getRoot() + '/' + this.__main.getTemporaryFolder() + '/valgrind.log';

			var args = [
				'G_SLICE=always-malloc',
				'G_DEBUG=gc-friendly',
				'valgrind -v',
				'--tool=memcheck',
				'--leak-check=full',
				'--num-callers=40',
				'--log-file=' + valgrindlog,
				'$(which ./v8gl)'
			];


			var cmd = 'cd ' + folder + ' && ' + args.join(' ') + ';';
			shell.exec(cmd);

		}

	};

})(this, this.adk, this.shell);


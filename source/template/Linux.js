
(function(global, adk, shell) {

	adk.template.Linux = function(main) {

		this.__main = main;

	};


	adk.template.Linux.DESCRIPTION = 'Linux builds with V8GL (requires OpenGL 2.1 on targeted system).';


	adk.template.Linux.prototype = {

		getEnvironment: function(folder, env) {
			return env;
		},

		build: function() {
		},

		clean: function() {
		},

		debug: function() {
		}

	};

})(this, this.adk, this.shell);


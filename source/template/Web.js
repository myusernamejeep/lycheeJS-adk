
(function(global, adk, shell) {

	adk.template.Web = function(main) {

		this.__main = main;

	};


	adk.template.Web.DESCRIPTION = 'Facebook or Web builds (generates hostable folder).';


	adk.template.Web.prototype = {

		getEnvironment: function(indir, outdir, env) {
			return env;
		},

		build: function(indir, outdir, arch) {
		},

		clean: function(indir, outdir, arch) {
		},

		debug: function(indir, outdir, arch) {
		}

	};

})(this, this.adk, this.shell);


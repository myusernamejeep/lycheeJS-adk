
(function(global, adk, shell) {

	adk.template.Android = function(main) {

		this.__main = main;

	};


	adk.template.Android.DESCRIPTION = 'Android mobile builds (generates installable APK).';


	adk.template.Android.prototype = {

		getEnvironment: function(indir, outdir, env) {
			// Don't modify the paths, keep them as the Adapter requested it
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


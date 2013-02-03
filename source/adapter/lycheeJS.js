
(function(global, adk, shell) {

	adk.adapter.lycheeJS = function(main) {

		this.__main = main;

	};


	adk.adapter.lycheeJS.DESCRIPTION = 'Games made with the lycheeJS engine (http://martens.ms/lycheeJS).';


	adk.adapter.lycheeJS.prototype = {

		getTree: function(directory) {

			console.log('game directory', directory);


		}

	};

})(this, this.adk, this.shell);


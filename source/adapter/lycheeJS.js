
(function(global, adk, shell) {

	adk.adapter.lycheeJS = function(main) {

		this.__main = main;

	};


	adk.adapter.lycheeJS.prototype = {

		getTree: function() {

			var gamedir = this.__main.getSettings().gamedir;


			console.log('game directory', gamedir);


		}

	};

})(this, this.adk, this.shell);


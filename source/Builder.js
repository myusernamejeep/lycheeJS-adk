
(function(global, adk, shell) {

	adk.Builder = function(main) {

		this.__main = main;

	};


	adk.Builder.prototype = {

		/*
		 * PRIVATE API
		 */

		__buildV8GL: function(target) {
		},



		/*
		 * PUBLIC API
		 */

		build: function(what, target) {
		}


	};

})(this, this.adk, this.shell);



(function(global) {

	console.group("Starting test...");

	console.log("typeof Text: " + typeof Text);
	console.log("Text.toString(): " + Text.toString());


	console.group("var instance = new Text(url)");

		var instance = new Text("./text.js");

		console.log("instance.toString(): " + instance.toString());
		console.log("instance.url: " + instance.url);
		console.log("instance.data: " + instance.data);
		console.log("instance.load.toString(): " + instance.load.toString());
		console.log("instance.onload.toString(): " + instance.onload.toString());

		// Ignored
		instance.load = function() {};

		// Allowed
		instance.onload = function() {};

		console.log("instance.load.toString(): " + instance.load.toString());
		console.log("instance.onload.toString(): " + instance.onload.toString());

	console.groupEnd();


	console.group("instance.load()");

		instance.onload = function() {
			console.log("instance.onload callback(): " + this.toString());
		};

	    instance.load();


		console.log("instance.url: " + instance.url);
		console.log("typeof instance.data: " + typeof instance.data);

	console.groupEnd();


	console.groupEnd();

})(this);


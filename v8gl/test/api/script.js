
(function(global) {

	console.group("Starting test...");

	console.log("typeof Script: " + typeof Script);
	console.log("Script.toString(): " + Script.toString());


	console.group("var instance = new Script(url)");

		var instance = new Script("../binding/gl/icosahedron.js");

		console.log("instance.url: " + instance.url);
		console.log("instance.data: " + instance.data);
		console.log("instance.onload.toString(): " + instance.onload.toString());
		console.log("instance.toString(): " + instance.toString());

	console.groupEnd();


	console.group("instance.load()");

		instance.onload = function() {
			var data = this.data + '';
			console.log("instance.onload callback(): " + this.toString() + " > " + data.substr(0, 10) + "...");
		};

	    instance.load();


		console.log("instance.url: " + instance.url);
		console.log("typeof instance.data: " + typeof instance.data);

	console.groupEnd();

	console.group("instance.execute()");

		var success = instance.execute();
		console.log("success: " + success);

	console.groupEnd();


	console.groupEnd();

})(this);



(function(global) {

	console.group("Starting test...");

	console.log("typeof Texture: " + typeof Texture);
	console.log("Texture.toString(): " + Texture.toString());


	console.group("var instance = new Texture(url)");

		var instance = new Texture("../asset/texture.png");

		console.log("instance.url: " + instance.url);
		console.log("instance.width: " + instance.width);
		console.log("instance.height: " + instance.height);
		console.log("instance.id: " + instance.id);
		console.log("instance.onload.toString(): " + instance.onload.toString());
		console.log("instance.toString(): " + instance.toString());

	console.groupEnd();


	console.group("instance.load()");

		instance.onload = function() {
			console.log("instance.onload callback(): " + this.toString());
		};

	    instance.load();


		console.log("instance.url: " + instance.url);
		console.log("instance.id: " + instance.id);
		console.log("instance.width: " + instance.width);
		console.log("instance.height: " + instance.height);

	console.groupEnd();

	console.group("instance.generate()");

	    instance.generate();

		console.log("instance.url: " + instance.url);
		console.log("instance.id: " + instance.id);
		console.log("instance.width: " + instance.width);
		console.log("instance.height: " + instance.height);

	console.groupEnd();

	console.groupEnd();

})(this);


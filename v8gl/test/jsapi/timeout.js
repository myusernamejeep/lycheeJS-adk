
(function(global) {

	var _delay;

	glut.createWindow("Timeout Test");

	console.log("typeof setTimeout: " + typeof setTimeout);


	console.group("setTimeout");

		var setAt = Date.now();

		var verify = function(delay) {

			console.group('setTimeout callback');

			var difference = Math.abs(Math.abs(Date.now() - setAt) - delay) | 0;

			if (difference < 32) {
				console.log('success. (difference: ' + difference + 'ms)');
			} else {
				console.error('fail. (difference: ' + difference + 'ms)');
			}

			console.groupEnd();

		};

		_delay = (Math.random() * 1337) | 0;

		console.log("setTimeout(verify, " + _delay + ")");
		setTimeout(verify, _delay);

	console.groupEnd();

	console.group("clearTimeout");

		_delay = (Math.random() * 1337) | 0;

		console.log("var handle = setTimeout(verify, " + _delay + ")");
		var handle = setTimeout(function() {
			console.group('setTimeout callback');
			console.error("clearTimeout(handle) failed.");
			console.groupEnd();
		}, _delay);

		console.log("clearTimeout(handle)");
		clearTimeout(handle);

	console.groupEnd();

})(this);


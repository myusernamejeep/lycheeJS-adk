
(function(global) {

	var _delay;
	var _count = 0;
	var _handle;

	glut.createWindow("Interval Test");

	console.log("typeof setInterval: " + typeof setInterval);


	console.group("setInterval");

		var verify = function(delay) {

			_count++;

			if (_count > 10) {
				console.error("clearInterval failed.");
			}

			console.group('setInterval callback #' + _count);
			console.log('delay: ' + delay + 'ms');
			console.log('difference: ' + (delay % _delay) + 'ms');
			console.groupEnd();

			if (_count === 10) {
				clearInterval(_handle);
			}

		};


		_delay = (Math.random() * 1337) | 0;

		console.log("setInterval(verify, " + _delay + ")");
		_handle = setInterval(verify, _delay);

	console.groupEnd();

})(this);


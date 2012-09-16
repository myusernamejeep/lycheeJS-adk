
(function(global) {

	var _timeoutId = 0;

	global.setTimeout = function(callback, delay) {

		callback = callback instanceof Function ? callback : null;
		delay = typeof delay === 'number' ? delay : 0;

		if (callback !== null) {

			var timer = {
				id: _timeoutId++,
				_disabled: false,
				scope: global,
				callback: callback,
				delay: delay,
				start: Date.now()
			};

			glut.timerFunc(delay, function(timer) {

				if (timer._disabled !== true) {
					timer.callback.call(timer.scope, Date.now() - timer.start);
				}

			}, timer);


			return timer;

		}

		return null;

	};


	global.clearTimeout = function(timer) {

		timer = Object.prototype.toString.call(timer) === '[object Object]' ? timer : null;

		if (timer !== null) {
			timer._disabled = true;
			return true;
		}

		return false;

	};

})(this);


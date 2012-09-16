
(function(global) {

	var _intervalId = 0;

	global.setInterval = function(callback, delay) {

		callback = callback instanceof Function ? callback : null;
		delay = typeof delay === 'number' ? delay : 0;

		if (callback !== null) {

			var timer = {
				id: _intervalId++,
				_disabled: false,
				scope: global,
				callback: callback,
				delay: delay,
				start: Date.now()
			};

			timer._interval = function(timer) {

				if (timer._disabled === false) {
					timer.callback.call(timer.scope, Date.now() - timer.start);
					glut.timerFunc(timer.delay, timer._interval, timer);
				}

			};

			glut.timerFunc(timer.delay, timer._interval, timer);


			return timer;

		}

		return null;

	};


	global.clearInterval = function(timer) {

		timer = Object.prototype.toString.call(timer) === '[object Object]' ? timer : null;

		if (timer !== null) {
			timer._disabled = true;
			return true;
		}

		return false;

	};

})(this);


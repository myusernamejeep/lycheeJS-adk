
(function(global) {

	var _margin = 0;

	var _toString = function(object) {

		var data = object;
		if (typeof data !== 'string') {

			try {
				data = JSON.stringify(data);
			} catch(e) {
				data = null;
			}

		}

		return data + '';

	};



	var log = function(object) {

		var message = '';
		for (var m = 0; m < _margin; m++) {
			message += '\t';
		}
		message += _toString(object);

		global.os.log(message);

	};

	var warn = function(object) {

		var message = '';
		for (var m = 0; m < _margin; m++) {
			message += '\t';
		}
		message += _toString(object);

		global.os.warn(message);

	};

	var error = function(object) {

		var message = '';
		for (var m = 0; m < _margin; m++) {
			message += '\t';
		}
		message += _toString(object);

		global.os.error(message);

	};



	var group = function(title) {

		var message = '';
		for (var m = 0; m < _margin; m++) {
			message += '\t';
		}
		message += '~ (' + (title || 'group') + ') ~';

		global.os.log(message);

		_margin++;

	};

	var groupEnd = function() {

		_margin--;

		var message = '';
		for (var m = 0; m < _margin; m++) {
			message += '\t';
		}
		message += '~ (end) ~';

		global.os.log(message);

	};


	global.console = {
		debug: log,
		log: log,
		warn: warn,
		error: error,
		group: group,
		groupEnd: groupEnd
	};

})(this);


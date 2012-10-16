
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



	var log = function() {

		var message = '';
		for (var m = 0; m < _margin; m++) {
			message += '\t';
		}

		for (var a = 0, l = arguments.length; a < l; a++) {
			message += _toString(arguments[a]);
			if (l > a + 1) message += ' | ';
		}

		global.os.log(message);

	};

	var warn = function() {

		var message = '';
		for (var m = 0; m < _margin; m++) {
			message += '\t';
		}

		for (var a = 0, l = arguments.length; a < l; a++) {
			message += _toString(arguments[a]);
			if (l > a + 1) message += ' | ';
		}


		global.os.warn(message);

	};

	var error = function() {

		var message = '';
		for (var m = 0; m < _margin; m++) {
			message += '\t';
		}

		for (var a = 0, l = arguments.length; a < l; a++) {
			message += _toString(arguments[a]);
			if (l > a + 1) message += ' | ';
		}

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


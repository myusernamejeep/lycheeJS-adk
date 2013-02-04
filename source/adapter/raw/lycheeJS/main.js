
if (typeof global !== 'undefined') {
	global.lychee = {};
} else {
	this.lychee = {};
}


// Initialize Fake API
(function(lychee, global) {

	var _env = {
		bases: {
			lychee: './lychee'
		},
		tags: {},
	};


	lychee.debug = false;

	lychee.rebase = function(settings) {

		settings = Object.prototype.toString.call(settings) === '[object Object]' ? settings : null;


		if (settings !== null) {

			for (var namespace in settings) {
				_env.bases[namespace] = settings[namespace];
			}

		}

		return lychee;

	};

	lychee.tag = function(settings) {

		settings = Object.prototype.toString.call(settings) === '[object Object]' ? settings : null;


		if (settings !== null) {

			for (var tag in settings) {

				var values = null;

				if (Object.prototype.toString.call(settings[tag]) === '[object Array]') {
					values = settings[tag];
				} else if (typeof settings[tag] === 'string') {
					values = [ settings[tag] ];
				}


				if (values !== null) {
					_env.tags[tag] = values;
				}

			}

		}

		return lychee;

	};

	lychee.getEnvironment = function() {
		return _env;
	};

	lychee.build = function(callback, scope) {

		fs.write('./env.json', JSON.stringify(_env));

	};

})(lychee, typeof global !== 'undefined' ? global : this);


(function(global) {

	global.main = function(argc, argv) {

		var script = new Script('init.js');

		script.load();
		script.execute();

	};

})(this);


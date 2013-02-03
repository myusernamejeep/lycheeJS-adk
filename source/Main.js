
this.adk = {
	adapter:  {},
	config:   {},
	template: {}
};


(function(global, adk, shell) {

	adk.extend = function(obj) {

		for (var a = 1, al = arguments.length; a < al; a++) {

			var obj2 = arguments[a];
			if (obj2) {

				for (var prop in obj2) {
					obj[prop] = obj2[prop];
				}

			}

		}

	};


	(function(dependencies) {

		// Remember, lycheeJS-adk/ is root folder
		for (var d = 0, dl = dependencies.length; d < dl; d++) {
			include('./source/' + dependencies[d]);
		}

	})([
		'adapter/lycheeJS.js',
		'template/Android.js',
		'template/Linux.js',
		'template/Web.js'
	]);


	adk.Main = function(argc, argv, debug) {

		this.__debug    = debug === true;

		var settings = this.__parseArguments(argc, argv);

		if (settings.template !== null) {
			this.__template = new adk.template[settings.template](this);
		}

		if (settings.flags.adapter !== null) {
			this.__adapter = adk.adapter[settings.flags.adapter];
		}


		this.__settings = settings;


console.log('adk main', this.__settings);

	};


	adk.Main.ACTION = {
		build: 0,
		clean: 1,
		debug: 2
	};


	adk.Main.prototype = {

		/*
		 * PRIVATE API
		 */

		__parseArguments: function(argc, argv) {

			var data = {
				action:   null,
				gamedir:  null,
				flags:    {
					adapter: null
				},
				template: null
			};

			for (var av = 1, al = argv.length; av < al; av++) {

				var str  = argv[av];
				var str2 = argv[av].charAt(0).toUpperCase() + argv[av].substr(1);

				// ./adk build
				if (adk.Main.ACTION[str] !== undefined) {

					data.action = adk.Main.ACTION[str];

				// ./adk build web
				} else if (adk.template[str2] !== undefined) {

					data.template = str2;

				// ./adk build web ./external/lycheeJS/game/pong
				} else if (shell.isDirectory(str) === true) {

					data.gamedir = str;

				// ./adk build web ./game/path --flag=value
				} else if (str.substr(0, 2) === "--"){

					str = str.substr(2);

					var tmp = str.split('=');
					if (tmp[0] && tmp[1]) {

						if (tmp[0] === 'adapter' && adk.adapter[tmp[1]] !== undefined) {
							data.flags[tmp[0]] = tmp[1];
						}

					}

				} else if (this.__debug === true) {

					console.warn('Could not interpret argument "' + str + '"');

				}

			}


			return data;

		}

	};

})(this, this.adk, this.shell);


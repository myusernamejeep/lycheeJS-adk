
this.adk = {
	adapter:  {},
	config:   {},
	template: {}
};


(function(global, adk) {

	var shell = include('./shell.js');


	adk.Main = function(argc, argv) {

		this.__settings = this.__parseArguments(argc, argv);


console.log('adk main', this.__settings);

	};


	adk.Main.ACTIONS = {
		build: {},
		clean: {},
		debug: {}
	};


	adk.Main.prototype = {

		/*
		 * PRIVATE API
		 */

		__parseArguments: function(argc, argv) {

			var data = {
				action:   null,
				adapter:  null,
				gamedir:  null,
				flags:    {},
				template: null
			};

			for (var av = 1, al = argv.length; av < al; av++) {

				var str = argv[av];

				// ./adk build
				if (adk.Main.ACTIONS[str] !== undefined) {


				// ./adk build web
				} else if (adk.template[str] !== undefined) {

					data.template = new adk.template[str](this);


				// ./adk build web ./external/lycheeJS/game/pong
				} else if (shell.isDirectory(str) === true) {

					data.gamedir = str;

				// ./adk build web ./game/path --flag=value
				} else if (str.substr(2) === "--"){

					str = str.substr(2);

					var tmp = str.split('=');
					if (tmp[0] && tmp[1]) {
						data.flags[tmp[0]] = tmp[1];
					}

				}

			}


			return data;

		}

	};

})(this, this.adk);


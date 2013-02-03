
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
		'Help.js',
		'adapter/lycheeJS.js',
		'template/Android.js',
		'template/Linux.js',
		'template/Web.js'
	]);


	adk.Main = function(argc, argv, debug) {

		debug = debug === true;


		var settings = this.__parseArguments(argc, argv);


		// defaulted game engine adapter
		if (settings.flags.adapter === null) {
			settings.flags.adapter = 'lycheeJS';
		}

		if (settings.template === null) {
			console.error('Unsupported <template>!');
			return this;
		}

		if (settings.indir === null) {
			console.error('Unsupported <game-folder>!');
			return this;
		}

		if (settings.arch === null) {

			settings.arch = this.__getArch();

			if (settings.arch === null) {
				console.error('Unsupported <architecture>!');
				return this;
			} else if (debug === true) {
				console.warn('Using host <architecture> (' + settings.arch + ')');
			}

		}


		this.__adapter  = new adk.adapter[settings.flags.adapter](this);
		this.__debug    = debug;
		this.__help     = new adk.Help(this);
		this.__self     = argv[0];
		this.__settings = settings;
		this.__template = new adk.template[settings.template](this);



		if (settings.outdir === null) {
			settings.outdir = './out/' + settings.template + settings.arch;
		}


		switch(settings.task) {

			case "build": this.build(); break;
			case "clean": this.clean(); break;
			case "debug": this.debug(); break;

			default:
				this.__help.generate();
			break;

		}

	};


	adk.Main.TASKS = {
		build: 'Starts the build process, output depends on the <template>.',
		clean: 'Cleans up temporary files.',
		debug: 'Starts the debugger for the built (and installed) app, depends on the <template>.'
	};


	adk.Main.ARCHITECTURES = {
		ia32: '32 Bit (i686, x86)',
		x64:  '64 Bit (amd64, x86_64)',
		arm:  'ARM (armeabi-v7a)'
	};


	adk.Main.prototype = {

		/*
		 * PRIVATE API
		 */

		__getArch: function() {

			var arch   = null;
			var unamep = shell.exec("uname -p");

			if (unamep === 'x86_64') {
				arch = "x64";
			} else if (unamep === 'i686') {
				arch = 'ia32';
			}


			return arch;

		},

		__parseArguments: function(argc, argv) {

			var data = {
				task:     null,
				template: null,
				arch:     null,
				indir:    null,
				outdir:   null,
				flags:    {
					adapter: null
				}
			};


			var tmp;

			for (var av = 1, al = argv.length; av < al; av++) {

				var str  = argv[av];
				var id   = null;
				var arch = null;

				if (argv[av].match(/\./)) {

					tmp  = argv[av].split('.')[0];
					id   = tmp.charAt(0).toUpperCase() + tmp.substr(1);
					arch = argv[av].split('.')[1];

				} else {
					id = str.charAt(0).toUpperCase() + str.substr(1);
				}


				// ./adk build
				if (adk.Main.TASKS[str] !== undefined) {

					data.task = str;

				// ./adk build web
				} else if (adk.template[id] !== undefined) {

					data.template = id;


					// TODO: This needs a more generic solution
					if (id === 'Android') {

						if (arch === 'arm') {
							data.arch = 'android_arm';
						} else if (arch === 'ia32') {
							data.arch = 'android_ia32';
						}

					} else {
						data.arch = arch;
					}


				// ./adk build web ./external/lycheeJS/game/pong
				} else if (shell.isDirectory(str) === true) {

					data.indir = str;

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

		},



		/*
		 * PUBLIC API
		 */

		getSelf: function() {
			return this.__self;
		},

		getSettings: function() {
			return this.__settings;
		},

		build: function() {

			var indir  = this.__settings.indir;
			var outdir = this.__settings.outdir;


			var source = null;
			if (this.__adapter !== null) {
				source = this.__adapter.getTree(indir);
			}

/*
			var target = null;
			if (this.__template !== null) {
				target = this.__template.getTree();
			}
*/

			/*
			 * Required Steps:
			 *
			 * 1. adapter:  Create main.js for parsing.
			 * 2. adapter:  Parse the environment
			 * 3. adapter:  Create tree for file system hierarchy
			 * 4. template: Parse the tree, dependend on outdir (e.g. move all contents of ./external/lycheeJS/ to ./lychee)
			 * 5. template: Create a main.js for the outdir (only on V8GL build, so it's the template) and attach it to the tree
			 * 6. Copy all necessary files from the tree to the outdir
			 */

		},

		clean: function() {

		},

		debug: function() {

		}

	};

})(this, this.adk, this.shell);


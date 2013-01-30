
(function(global) {

	var ADK = function(argc, argv) {

		this.__self    = argv[0];
		this.__command = this.__parse(argc, argv);

		if (this.__command !== null) {

			if (this.__command.wait === true) {
				this.__bind(this.__command);
			} else {
				this.__execute(this.__command);
			}

		} else {
			this.__showHelp(false);
		}

	};


	ADK.COMMANDS = {

		'export': {
			callback: {
				wait:   false,
				method: '_export',
				args:   [ 2, 3, 4 ]
			},
			shell: {
				args: [ '<format>' , 'in/init.js', 'out/<file>' ],
				desc: 'Exports the environment to a file. <format> can be "json" or "bash"'
			}
		},

		'rewrite': {
			callback: {
				wait:   true,
				method: '_rewrite',
				args:   [ 2, 3, 4 ]
			},
			shell: {
				args: [ '<platform>', 'in/init.js', 'out/init.js' ],
				desc: 'Rewrites and prepares the init.js for a targeted platform'
			}
		}

	},



	ADK.prototype = {

		/*
		 * PRIVATE API
		 */

		__bind: function(command) {

			if (typeof lychee !== 'undefined') {

				var that = this;
				lychee.build = function(callback, scope) {

					command.args.push(callback);
					command.args.push(scope);

					that.__execute(command);

				};

			}

		},

		__showHelp: function(detailed) {

			detailed = detailed === true ? true : false;

			var message = '';
			var warning = null;

			// Show specific help for current command
			if (detailed === true && this.__command !== null) {

				var shell = ADK.COMMANDS[this.__command.id].shell;

				warning = 'Invalid arguments for current command "' + this.__command.id + '"';

				message += 'Command:     ' + this.__command.id + '\n';
				message += 'Description: ' + (shell.desc || '(No Description)') + '\n';
				message += '\n';
				message += '\n';
				message += 'Example call:' + '\n';
				message += this.__self + ' ' + shell.args.join(' ') + '\n';

			// Show command overview and examples
			} else {

				message += 'Commands:\n';

				for (var id in ADK.COMMANDS) {

					var shell  = ADK.COMMANDS[id].shell;
					var margin = '';
					for (var m = 0; m < 20 - id.length; m++) {
						margin += ' ';
					}

					message += '\t' + id + margin + (shell.desc || '(No Description)') + '\n';

				}


				message += '\n';
				message += '\n';
				message += 'Examples:\n';

				for (var id in ADK.COMMANDS) {

					var shell  = ADK.COMMANDS[id].shell;

					message += this.__self + ' ' + shell.args.join(' ') + '\n';

				}

			}


			if (warning !== null) {

				os.log(_header);
				os.log('\n');
				os.warn(warning);
				os.log('\n');
				os.log(message);

			} else {

				os.log(_header);
				os.log('\n');
				os.log(message);

			}

		},

		__parse: function(argc, argv) {

			if (
				typeof argc === 'number'
				&& argc > 1
				&& Object.prototype.toString.call(argv) === '[object Array]'
				&& ADK.COMMANDS[argv[1]] !== undefined
			) {

				var data = ADK.COMMANDS[argv[1]].callback;

				var args = [];
				for (var a = 0, al = data.args.length; a < al; a++) {
					args.push(argv[data.args[a]] || null);
				}

				var command = {
					id:       argv[1],
					callback: this[data.method],
					args:     args,
					wait:     !!data.wait
				};


				return command;

			}


			return null;

		},

		__execute: function(command) {

			if (
				Object.prototype.toString.call(command) === '[object Object]'
				&& command.callback instanceof Function
				&& Object.prototype.toString.call(command.args) === '[object Array]'
			) {

				command.callback.apply(this, command.args);

				return true;

			}


			return false;

		},


		/*
		 * CALLBACKS for the equivalent commands
		 */

		_export: function(type, inFile, outFile) {

			type    = (type === 'bash' || type === 'json') ? type : null;
			inFile  = typeof  inFile === 'string' ?  inFile : null;
			outFile = typeof outFile === 'string' ? outFile : null;


			var str = '':

			if (
				type !== null
				&& inFile !== null
				&& outFile !== null
			) {

				var script = new Script(inFile);
				script.load();
				script.execute();

				var env = lychee.getEnvironment();


				if (type === 'json') {

					str = JSON.encode(env);

				} else if (type === 'bash') {

					str += 'declare -A env_bases;';
					for (var base in env.bases) {
						str += 'env_bases["' + base + '"] = "' + env.bases[base] + '";';
					}

					str += 'declare -A env_tags;';
					for (var tag in env.tags) {
						str += 'env_tags["' + tag + '"] = "' + env.tags[tag] + '";';
					}

				}


				fs.write(outFile, str);

				return true;

			} else {

				this.__showHelp(true);

				return false;

			}

		},

		_rewrite: function(platform, inFile, outFile, callback, scope) {

			platforms = typeof platforms === 'string' ? platforms : null;
			inFile    = typeof    inFile === 'string' ?    inFile : null;
			outFile   = typeof   outFile === 'string' ?   outFile : null;


			/*
			 * This allows an array notation
			 * in shell via passing a serialized
			 * string to the ADK:
			 *
			 * ./v8adk rewrite "["webgl", "html", "nodejs"]" ./game/pong/init.js ./out.js
			 *
			 */

			var data = null;
			try {
				data = JSON.decode(platforms);
			} catch(e) {
			}

			if (
				data !== null
				&& Object.prototype.toString.call(data) === '[object Array]'
				&& data !== platforms
			) {
				platforms = data;
			} else {
				platforms = [ platforms ];
			}


			if (
				platform !== null
				&& inFile !== null
				&& outFile !== null
			) {

				var script = new Script(inFile);
				script.load();
				script.execute();

				var oldenv = lychee.getEnvironment();

				var newenv = {
					bases: {},
					tags: {
						platform: platforms
					}
				};


				for (var baseId in oldenv.bases) {
					newenv.bases[baseId] = './js/' + baseId;
				}

				for (var tagId in oldenv.tags) {
					if (tagId === 'platform') continue;
					newenv.tags[tagId] = oldenv.tags[tagId];
				}


				var str = '\n';

				if (lychee.debug === true) {
					str += 'lychee.debug = true\n';
					str += '\n'
				}

				str += 'lychee.rebase(' + JSON.stringify(newenv.bases) + ');\n';
				str += 'lychee.tag('    + JSON.stringify(newenv.tags)  + ');\n';
				str += 'lychee.build('  + callback.toString()          + ', typeof global !== \'undefined\' ? global : this);\n';


				fs.write(outFile, str);

				return true;

			} else {

				this.__showHelp(true);

				return false;

			}

		}

	};


	global.main = function(argc, argv) {

		var dependencies = [
			'./js/lychee/core.js',
			'./js/lychee/Builder.js',
			'./js/lychee/Preloader.js',
			'./js/lychee/platform/v8gl/bootstrap.js'
		];


		for (var d = 0, l = dependencies.length; d < l; d++) {

			var script = new Script(dependencies[d]);

			script.load();
			script.execute();

		}


		new ADK(argc, argv);

	};

})(typeof global !== 'undefined' ? global : this);


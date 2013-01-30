#!/bin/bash
#
# lycheeJS-ADK
# (App Development Kit)
#
# Copyright (c) 2012 by Christoph Martens
#
# The lycheeJS-ADK is released under the
# terms of the MIT license.
#



case "$1" in

	setup)

		echo -e "\nSetting Up...";

			cat ./js/lychee/core.js ./js/lychee/Builder.js ./js/lychee/Preloader.js ./js/lychee/platform/v8gl/bootstrap.js > ./bootstrap.js;

			cp $v8gl_path/v8gl ./v8adk;
			chmod +x ./v8adk;

		echo -e "Done.";

		exit;
		;;

	build)
		exit;
		;;

	package)
		exit;
		;;

	clean)
		exit;
		;;

	debug)

		exit;
		;;

esac;


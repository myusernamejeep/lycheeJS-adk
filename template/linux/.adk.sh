#!/bin/bash
#
# lycheeJS-ADK
# (App Development Kit)
#
# Copyright (c) 2012 by Christoph Martens
#
# This Open-Source version is released under
# the terms of GNU General Public License
# version 3
#
# Please see the LICENSE.txt included with this
# distribution for further details.
#



case "$1" in

	setup)

		echo -e "\nSetting Up...";

			cp $v8gl_path/v8gl ./start;
			chmod +x ./start;

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

		echo -e "\nDebugging...";

			gdb --eval-command=run --eval-command=quit --args ./start;
#			gdb -ex run --args ./start;

		echo -e "Done.";

		exit;
		;;

esac;


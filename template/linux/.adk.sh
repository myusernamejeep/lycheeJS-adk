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

		gdb --args ./start;

		exit;
		;;

esac;


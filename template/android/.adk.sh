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



usage() {

cat <<EOF

Template Integration Script for the lycheeJS ADK (App Development Kit) v0.5

Usage: $0 <task>


Each Template Integration Script has to offer the following tasks:

    setup             Setup everything and import required libraries
    build             Starts the build process
    package           Starts the packaging process
    clean             Cleans the folder up


Usage:

$0 prepare
$0 build
$0 package
$0 cleanup

EOF

}



case "$1" in
	help)

		usage;

		exit;
		;;

	setup)

		echo -e "\nSetting Up...";




		echo -e "Done.";


		exit;
		;;

	build)

		echo -e "\nBuilding...";

			export V=1;
			export NDK_LOG=1;

			$ANDROID_NDK_ROOT/ndk-build;

			ant debug;
			ant release;

		echo -e "Done.";

		exit;
		;;

	package)

		echo -e "\nPackaging...";

			mv ./bin/AndroidManifest.xml ./AndroidManifest.xml;
			mv ./bin/*-debug.apk ./;
			mv ./bin/*-release-unsigned.apk ./;

		echo -e "Done.";

		exit;
		;;

	clean)

		echo -e "\nCleaning Up...";

			if [ -d "./bin" ]
			then
				rm -rf "./bin";
				check_success;
			fi;

			if [ -d "./libs" ]
			then
				rm -rf "./libs";
				check_success;
			fi;

			if [ -d "./obj" ]
			then
				rm -rf "./obj";
				check_success;
			fi;

		echo -e "Done.";

		exit;
		;;

esac;


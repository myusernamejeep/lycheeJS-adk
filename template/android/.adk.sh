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

			mkdir ./assets;

			mv asset assets;
			mv init.js assets;
			mv js assets;


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

#			if [ -d "./bin" ]
#			then
#				rm -rf "./bin";
#				check_success;
#			fi;
#
#			if [ -d "./libs" ]
#			then
#				rm -rf "./libs";
#				check_success;
#			fi;
#
#			if [ -d "./obj" ]
#			then
#				rm -rf "./obj";
#				check_success;
#			fi;

		echo -e "Done.";

		exit;
		;;

	debug)

		echo -e "\nDebugging...";

			$ANDROID_HOME/platform-tools/adb uninstall "ms.martens.v8gl";
			$ANDROID_HOME/platform-tools/adb install V8GL-debug.apk;
			$ANDROID_HOME/platform-tools/adb shell am start -n "ms.martens.v8gl/android.app.NativeActivity";

		echo -e "Done.";

		exit;
		;;

esac;


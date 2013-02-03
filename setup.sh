#!/bin/bash
#
# lycheeJS-ADK
# (App Development Kit)
#
# Copyright (c) 2012-2013 by Christoph Martens
#
# The lycheeJS-adk is released under the terms
# of the MIT license. Please see the LICENSE.txt
# included with this distribution for further
# details.
#


UNAME_P=$(uname -p);

ROOT_PATH=$(cd "$(dirname "$0")"; pwd);
PNG_PATH=$ROOT_PATH/external/libpng;
V8_PATH=$ROOT_PATH/external/v8;
V8GL_PATH=$ROOT_PATH/v8gl;


if [ "$UNAME_P" == "x86_64" ]
then
	V8_PLATFORM="x64.release";
elif [ "$UNAME_P" == "i686" ]
then
	V8_PLATFORM="ia32.release";
else
	echo -e "No valid architecture detected ($UNAME_P).";
	exit 1;
fi;



help() {

cat <<EOF

lycheeJS ADK (App Development Kit) v0.6

This program comes with ABSOLUT NO WARRANTY;
This is free software, and you are welcome to redistribute it under certain conditions;
See the LICENSE.txt for details.

Recommended development environment: Ubuntu 12.10 amd64 (64 Bit)

This setup script will download all required dependencies and compile the ADK itself.
First, you need to select your game engine.


Usage: $0 <engine>

Available Engines:

    lycheeJS           The lycheeJS game engine (MIT license)

Examples:

$0 lycheeJS


EOF

}


install_dependencies() {

	echo -e "\n\n- - - Installing dependencies ($1) - - -\n\n";

	cd $ADK_PATH;

	install_command="sudo $1 -y install
	wget git unzip
	ant openjdk-7-jdk lib32ncurses5 lib32stdc++6 lib32gcc1
	build-essential g++ gcc-multilib zlib1g-dev
	libgl1-mesa-dev libglu1-mesa-dev
	freeglut3-dev";

	echo -e "\nDone.";

}

detect_platform() {

	if [ "$UNAME_P" == "x86_64" ]
	then
		HOST_PLATFORM="x64.release";
	elif [ "$UNAME_P" == "i686" ]
	then
		HOST_PLATFORM="ia32.release";
	else
		echo -e "No valid architecture detected ($UNAME_P).";
		exit 1;
	fi;

}

# build_libpng x64.release
build_libpng() {

	echo -e "\n\n- - - Building libpng ($1)- - -\n\n";

	cd "$PNG_PATH";
	make $1;

	echo -e "\nDone.";
	cd "$ROOT_PATH";

}

# build_v8 x64.release
build_v8() {

	echo -e "\n\n- - - Building v8 ($1) - - -\n\n";

	cd "$V8_PATH";
	make $1;

	echo -e "\nDone.";
	cd "$ROOT_PATH";

}

# build_v8gl x64.release
build_v8gl() {

	echo -e "\n\n- - - Building v8gl ($1) - - -\n\n";

	cd "$V8GL_PATH";
	make $1;

	echo -e "\nDone.";
	cd "$ROOT_PATH";

}

# build_adk lycheeJS
build_adk() {

	echo -e "\n\n- - - Building adk ($1) - - -\n\n";
	
	tpl_path="$ROOT_PATH/template/$1-adk";

	if [ -d "$tpl_path" ]
	then
		cp -R $tpl_path/* $ROOT_PATH;
	fi;

	echo -e "\nDone.";
	cd "$ROOT_PATH";

}


case "$1" in

	help)
		help;
		exit;
		;;

	lycheeJS)

		install_dependencies;

		ADK_PATH=$ADK_PATH/template/lycheeJS-adk;

		detect_platform;

		# build V8GL
		build_libpng "$HOST_PLATFORM";
		build_v8 "$HOST_PLATFORM";
		build_v8gl "$HOST_PLATFORM";

		# build ADK
		build_adk "lycheeJS";

		exit;
		;;

esac;


help;


#!/bin/bash
function clean {
	printf "=== CLEANING UP ===\n";
	for MAKES in $(find . -iname 'Makefile'); do
		make -f "$MAKES" clean;
	done
	for FILE in $(find . -iname 'Makefile' -or -iname 'CMakeCache.txt' -or -iname 'CMakeFiles' -or -iname 'cmake_install.cmake'); do
		rm -Rvf "$FILE";
	done
}
if [ "$1" == "clean" -o "$1" == "-c" ]; then
	clean;
	exit 0;
elif [ "$1" == "rebuild" -o "$1" == "-R" ]; then
	clean;
fi
cd lib;
if [ -e "gwen" ]; then
	cd ..;
else
	./extras.sh;
	cd ..;
fi;
printf "=== BUILDING ===\n";
export CC=/usr/bin/clang
export CXX=/usr/bin/clang++
if [ -e "Makefile" ]; then
	make;
	err=$?
else
	cmake .;
	make;
	err=$?
fi
if [ "$err" == "0" ]; then
	printf "=== DONE === \n";
	if [ "$2" == "-run" -o "$1" == "-r" -o "$1" == "-cr" -o "$1" == "-Rr" ]; then
		cd bin;
		./HackThePlanet;
		exit $?
	fi
	exit 0;
else
	exit 1;
fi

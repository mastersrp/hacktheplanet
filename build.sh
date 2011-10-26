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
if [[ "$1" == "clean" ]]; then
	clean;
	exit 0;
elif [[ "$1" == "rebuild" ]]; then
	clean;
fi
printf "=== BUILDING ===\n";
export CC=/usr/bin/clang
export CXX=/usr/bin/clang++
if [[ -e "Makefile" ]]; then
	make;
	err=$?
else
	cmake .;
	make;
	err=$?
fi
if [[ "$err" == "0" ]]; then
	printf "=== DONE === \n";
	exit 0;
else
	exit 1;
fi

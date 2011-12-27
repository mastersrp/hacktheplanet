#!/bin/bash

#rm -Rvf 'CMakeFiles/' 'CMakeCache.txt' 'cmake_install.cmake' 'Makefile'
for FILE in $(find . -type f -iname 'CMakeCache.txt' -or -iname 'cmake_install.cmake' -or -iname 'Makefile'); do
    rm -Rvf $FILE;
done
for DIR in $(find . -type d -iname 'CMakeFiles'); do
    rm -Rvf $DIR;
done
rm bin/HackThePlanet

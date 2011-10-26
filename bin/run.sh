#!/bin/bash

cd ..;
./build.sh
cd bin;
if [[ "$?" == "0" ]]; then
	./HackThePlanet;
else
	exit;
fi

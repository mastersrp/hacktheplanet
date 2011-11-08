#!/bin/bash
GIT=$(which git);
SVN=$(which svn);
CWD=$(cd $(basename .); pwd);
PREMAKE=$(which premake4);
PREMAKE_VERSION=$(${PREMAKE} --version);
function clone {
	printf "== CLONING ==\n";
	if [ "$GIT" == "" ]; then
		printf "${SVN} co $1 $2\n";
		${SVN} co $1 $2
	else
		printf "${GIT} svn clone $1 $2\n";
		${GIT} svn clone $1 $2;
	fi
}
function update {
	printf "== UPDATING ==\n";
	printf "cd $1\n";
	printf "${GIT} svn fetch\n";
	${GIT} svn fetch;
	cd $CWD;
}
printf "[GIT]: $GIT\n";
if [ "$GIT" == "" ]; then
	printf "Could not find git! Using svn only...\n";
fi
printf "[SVN]: $SVN\n";
if [ "$SVN" == "" ]; then
	printf "Couldn't find svn! Aborting...\n";
	exit 1;
fi
printf "[CWD]: $CWD\n";
if [ -e "gwen" ]; then
	update "gwen";
else
	clone "http://gwen.googlecode.com/svn/trunk" "gwen";
fi
cd "gwen/trunk/gwen/Projects";
if [ "$PREMAKE_VERSION" == "premake4 (Premake Build Script Generator) 4.3" ]; then
	cd inc;
	printf "Premake4 version 4.3. Replacing 'debugdir' with '--debugdir'.\n";
	sed s/debugdir/\-\-debugdir/ include.lua > include.tmp
	cp include.lua include.lua.bak
	mv include.tmp include.lua
	cd ..;
fi
if [ "$PREMAKE" == "" ]; then
	./premake4 gmake;
else
	premake4 gmake;
fi
cd "linux/gmake";
make "GWEN Static" "UnitTest" "Renderer-OpenGL_DebugFont"
if [[ "$?" == "0" ]]; then
	cp -v ../../../lib/linux/*.a "${CWD}"
	cd $CWD;
	printf "== DONE ==\n";
fi;

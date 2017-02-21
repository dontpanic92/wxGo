#!/bin/bash

if [ -z $1 ] || [ -z $2 ]; then
    echo -e "Please specify OS ARCH. Example:\nbash $0 linux amd64"
    exit 1
fi;

WXGO_SUFFIX=$1_$2

wxGoTmpDir="/tmp/wxGo_tmp_$WXGO_SUFFIX"

if [ -e $wxGoTmpDir ]; then
    rm -r $wxGoTmpDir
fi;


mkdir -p $wxGoTmpDir/pkg/$WXGO_SUFFIX/github.com/dontpanic92/wxGo/
mkdir -p $wxGoTmpDir/src/github.com/dontpanic92/wxGo/wx
cp $GOPATH/src/github.com/dontpanic92/wxGo/wx/$WXGO_SUFFIX/lib/*.a $wxGoTmpDir

cd $wxGoTmpDir

for file in `ls *.a`; do
    ar x $file;
done;

if [ "$1" == "darwin" ]; then
    # cocoa/power.mm compiled twice! Delete one of them
    rm baselib_cocoa_power.o
fi;

# Windows has a limit of maximum command line characers. If we simply copy 
# these .o file, the length of the link command will longer than the limit.
# So here we use * to link them into one object file first to workaround.
# Also, in Linux / Mac OS X, there is a limit of open files. You can use
# ulimit -a to check the limit, and use ulimit -n to modify the maximum files
# a process can open. On Mac OS X El Capitan the default value of this limit is
# 256 and it is toooo small.

if [ "$1" == windows ]; then
    a=0
    for file in `ls *.o`; do
        new=$(printf "%d.o" "$a") 
        mv -- "$file" "$new"
        let a=a+1
    done;
    if [ "$2" == "386" ]; then
        ld -m i386pe -r -o everything_$WXGO_SUFFIX.syso *.o
    else
        ld -r -o everything_$WXGO_SUFFIX.syso *.o
    fi;
    rm *.o
else
    for file in `ls *.o`; do
        mv "${file}" "${file/%.o/_$WXGO_SUFFIX.syso}"
    done;
fi;

rm *.a
mv *.syso $GOPATH/src/github.com/dontpanic92/wxGo/wx/

export GOARCH=$2
export GOOS=$1
export CGO_ENABLED=1
go version
go env
go install -tags "wxgo_binary_package_build" -x github.com/dontpanic92/wxGo/wx


cp $GOPATH/pkg/$WXGO_SUFFIX/github.com/dontpanic92/wxGo/wx.a $wxGoTmpDir/pkg/$WXGO_SUFFIX/github.com/dontpanic92/wxGo/wx.a

echo -e "//go:binary-only-package\n\npackage wx" > $wxGoTmpDir/src/github.com/dontpanic92/wxGo/wx/binary_only_package_$WXGO_SUFFIX.go

rm $GOPATH/src/github.com/dontpanic92/wxGo/wx/*_$WXGO_SUFFIX.syso

zip -9 wxGo_$WXGO_SUFFIX.zip -r pkg src

cd -

if [ -e wxGo_$WXGO_SUFFIX.zip ]; then
    rm wxGo_$WXGO_SUFFIX.zip
fi;

mv $wxGoTmpDir/wxGo_$WXGO_SUFFIX.zip .

rm -r $wxGoTmpDir


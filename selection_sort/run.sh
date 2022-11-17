#!/bin/bash


DIR=build
auto_test=auto_test.sh
if [ ! -d "$DIR" ]; then
    mkdir $DIR
fi
if [[ -f "$auto_test" && ! -f "$DIR/$auto_test" ]]; then
    cp $auto_test $DIR
fi
cd $DIR
cmake ..
make 
chmod +x $auto_test


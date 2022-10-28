#!/bin/bash


DIR=build
auto_test=auto_test.sh
if [ ! -d "$DIR" ]; then
    mkdir $DIR
fi
if [[ -f "$auto_test" && ! -f "$DIR/$auto_test" ]]; then
    cp $auto_test $DIR
    chmod +x $auto_test
fi
cd $DIR
cmake ..
make 

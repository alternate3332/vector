#!/bin/bash

pushd `dirname $0` 1>/dev/null
SCRIPT_DIR=`pwd`
popd 1>/dev/null

rm a.out 2>/dev/null

g++ -std=c++11 -O2 -I $SCRIPT_DIR/../include $SCRIPT_DIR/../test/VectorTest.cpp
./a.out

rm a.out
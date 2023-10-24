#!/bin/bash

# create a "Unix Makefiles" build
cmake -S . -G "Unix Makefiles" -B ../Unix_build
cmake --build ../Unix_build

# create an "Xcode" build 
cmake -S . -G "Xcode" -B ../Xcode_build 
cmake --build  ../Xcode_build

# execute 
../Unix_build/QuicksortTest
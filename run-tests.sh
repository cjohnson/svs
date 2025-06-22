#!/bin/bash

# Configure build
mkdir -p build
cmake . -B build

# Build
cmake build -DCMAKE_BUILD_TYPE=Debug
cmake --build build

if [ $? -eq 0 ]; then
    ./build/cpp_test
fi

#!/bin/bash

# Configure build
mkdir -p build
cmake . -B build

# Build
cmake --build build

./build/svsc ./assignment_operators.sv

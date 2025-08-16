# Configure build
New-Item -Force -ItemType Directory Build 
cmake . -B Build -G Ninja

# Build
cmake Build -DCMAKE_BUILD_TYPE=Debug
cmake --build Build

./build/cpp_test.exe

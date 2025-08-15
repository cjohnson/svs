# Configure build
New-Item -Force -ItemType Directory Build 
cmake . -B Build

# Build
cmake Build -G ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build Build

./build/Debug/cpp_test.exe

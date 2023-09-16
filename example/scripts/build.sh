mkdir -p cmake
mkdir -p build
cd cmake
cmake ..
make
cd ..
cp cmake/*.uf2 build

mkdir -p build

cmake -B build

(cd build && make clean && make && cd ..)
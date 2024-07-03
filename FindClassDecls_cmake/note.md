# Support cmake
This is an camke script for complied the code.

## complied
CMAKE_CXX_COMPILER help you to specify the toolchain(c++ or clang++), and 
`make VERBOSE=1` can print detail log.

    mkdir _build
    cd _build
    cmake ../ -DCMAKE_CXX_COMPILER=clang++
    make

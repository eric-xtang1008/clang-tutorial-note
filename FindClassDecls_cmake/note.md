# Support cmake
This is an camke script for complied the code.

## Complied
CMAKE_CXX_COMPILER help you to specify the toolchain(c++ or clang++), and 
`make VERBOSE=1` can print detail log.

    mkdir _build
    cd _build
    cmake ../ -DCMAKE_CXX_COMPILER=clang++
    make
usage:

    ./find-class-decls "namespace n { namespace m { class C {}; } }"

## Using clang libtooling
A reference: https://clang.llvm.org/docs/LibASTMatchersTutorial.html

usage:

    ./find-class-decls ../test.cpp

If the follow problem occur

    Error while trying to load a compilation database:
    Could not auto-detect compilation database for file "../test.cpp"
    No compilation database found in /home/eric/data/test/study/clang-tutorial-note/FindClassDecls_cmake/_build/.. or any parent directory
    fixed-compilation-database: Error while opening fixed database: No such file or directory
    json-compilation-database: Error while opening JSON database: No such file or directory
    Running without flags.
Recomipled with:

        cmake ../ -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS=1
OR:

    ./find-class-decls ../test.cpp --

More detailed explaination about it can be found on [Eli Bendersky's blog](https://eli.thegreenplace.net/2014/05/21/compilation-databases-for-clang-based-tools).

Reference: https://github.com/banach-space/clang-tutor?tab=readme-ov-file#run-the-plugin-through-ct-la-commenter
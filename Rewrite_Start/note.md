# Description
Output the test file to std::out with Rewriter

## Complied

    mkdir _build
    cd _build
    cmake ../ -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS=1
    make
usage:

    ./RewriteDemo ../Test_Rewrite.cpp

error problem:
    
    /usr/include/stdio.h:33:10: fatal error: 'stddef.h' file not found

This need add `HeaderSearch`, reference: https://github.com/loarabia/Clang-tutorial/wiki/TutorialOrig#tutorial-3-include-files
    


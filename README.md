# Clang Note

The code of this note comes from clang official website https://clang.llvm.org/docs/RAVFrontendAction.html,
from the website, complied the code need to add the code into the llvm project. This note got another way that complied the code out of tree.

## Setup Development Environment

### Install Clang On Ubuntu
You can intall the lastest stable version On Ubuntu from the official repository: https://apt.llvm.org/

    For convenience there is an automatic installation script available that installs LLVM for you.
    To install the latest stable version:
    bash -c "$(wget -O - https://apt.llvm.org/llvm.sh)"

    To install a specific version of LLVM:
    wget https://apt.llvm.org/llvm.sh
    chmod +x llvm.sh
    sudo ./llvm.sh <version number>
    To install all apt.llvm.org packages at once:
    wget https://apt.llvm.org/llvm.sh
    chmod +x llvm.sh
    sudo ./llvm.sh <version number> all
    or
    sudo ./llvm.sh all

### Building Clang from Source Code
Building clang from sources may not easy but useful for beginner. Offical website:https://llvm.org/docs/GettingStarted.html

    git clone https://github.com/llvm/llvm-project.git
    cd llvm-project
    mkdir _build
    cd _build
    cmake -DCMAKE_BUILD_TYPE=Release -DLLVM_TARGETS_TO_BUILD=host -DLLVM_ENABLE_PROJECTS="clang;clang-tools-extra" ../llvm/
    make -j2
    sudo make install

## Build & Test the example out of tree

### Build:

    clang++ FindClassDecls.cpp \
      -lclangTooling\
      -lclangFrontend\
      -lclangParse\
      -lclangSerialization\
      -lclangSema\
      -lclangAPINotes\
      -lclangEdit\
      -lclangAnalysis\
      -lclangSupport\
      -lclangDriver\
      -lclangASTMatchers\
      -lclangAST\
      -lclangFormat\
      -lclangToolingInclusions\
      -lclangToolingCore\
      -lclangRewrite\
      -lclangLex\
      -lclangBasic\
      `llvm-config --cxxflags --ldflags --system-libs --libs`  -fno-rtti -o find-class-decls

### Test:

    $ ./find-class-decls "namespace n { namespace m { class C {}; } }"
    Found declaration at 1:29


# How to parse C programs with Clang
A frontend consists of two parts, lexer and paser. This is most compiler textbook included. Clang's frontend
also uses this skeleton, but with some difference. 

## SourceManager & FileManager
A example:
        
    clang test.c -o test
clang first need read the file(test.c) and cache it. How to do? There are two class that can help us to finish this work.

`SourceManager` is used to load and cache source files. (allocated a buffer and store file data or use mmap).

`FileManager` which helps it manage files on disk and in cache. (open, read & close).

## Preprocessor & Lexer
`Lexer` converts the input from a stream of characters to a stream of tokens.

For example: for will be convert kw_for by lexer.

`Preprocessor` class is the main interface to the lexer.

This means that if you want to process the input characters to tokens, first,
you need create Preprocessor instances:
    
    Preprocessor PP(....)
    PP.Lex(tok)

## ParseAST and Sema
Clang's `parser` consumes token streams from the preprocessor and lexer and tries
to realize their semantic structures, `Sema` sub-system performs more semantic 
checking and analysis from the parser's result before generating the AST.
        
    kw_for -> ForStmt

## Work flow
clang Sema use callback-style design. When produced a token, it will be transfered to a 
AST node, then comsume the next character to produce the next token, and then
transfer to next AST node. It's not produced AST node after all tokens have been produced.

      |cache file | <- *ptr ---> consume(*ptr) ---> token ----> is kw_oef ---> end
                         ^                             |(other kind token)
                         |                            \ /
                         --- ptr++ <--- AST node <--- Parse(token) (call consume again if need)

[2. Kaleidoscope: Implementing a Parser and AST](https://llvm.org/docs/tutorial/MyFirstLanguageFrontend/LangImpl02.html) is very simple and can help us to understand the work flow of the frontend.
                                    
Reference:

[1] https://modocache.io/llvm-memory-buffer

[2] [LLVM Techniques, Tips, and Best Practices Clang and Middle-End Libraries](https://github.com/PacktPublishing/LLVM-Techniques-Tips-and-Best-Practices-Clang-and-Middle-End-Libraries)

[3] https://github.com/loarabia/Clang-tutorial/wiki/TutorialOrig


#C++11 parser and evaluator for mathematical expressions

This is a parser and evaluator created for a plotting application.

You can compile strings like `2^x` and evaluate their value for some values of `x`.

Also, in case of no variables you can use it as a simple calculator.

    >> 3+5^2
    28
    >> sin(pi/2)
    1

Part of the source code is generated on build time with flex and bison, so you need them in order to compile this. At the moment this project requires bison 2.7 (3.0 introduces some backward incompatible changes).

A C compatible API is also provided in order to help the usage of the parser in other languages than C++.

See `examples` directory for more information on usage.

##How to build

Regular CMake procedures apply. Remember to install `flex` and `bison27`.

    mkdir build && cd build
    cmake ..
    make

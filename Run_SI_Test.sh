#!/bin/bash
    g++ -c -o OpCodeFunctions_general.o OpCodeFunctions_general.cpp
    g++ -c -o OpCodeFunctions.o OpCodeFunctions.cpp
    g++ -c -o OpCodeCaller.o OpCodeCaller.cpp 

    g++ -o proj SI_GameLoop.cpp OpCodeFunctions_general.o OpCodeFunctions.o OpCodeCaller.o i8080_struct.cpp -lm -std=c++11 -ID:"C:\Dev Lib\SDL2-2.0.14\x86_64-w64-mingw32\include" -LD:"C:\Dev Lib\SDL2-2.0.14\x86_64-w64-mingw32\lib" -lSDL2main -lSDL2 -LD:"C:\Dev Lib\SDL2-2.0.14\x86_64-w64-mingw32\include\SDL2"

./proj 
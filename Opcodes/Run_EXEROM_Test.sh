#!/bin/bash
    g++ -c -o OpCodeFunctions_general.o OpCodeFunctions_general.cpp
    g++ -c -o OpCodeFunctions.o OpCodeFunctions.cpp
    g++ -c -o OpCodeCaller.o OpCodeCaller.cpp 

    g++ -o proj ROM_Tester.cpp OpCodeFunctions_general.o OpCodeFunctions.o OpCodeCaller.o ../i8080_struct.cpp -lm -std=c++11

./proj 
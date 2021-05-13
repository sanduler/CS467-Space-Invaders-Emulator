#!/bin/bash

if [ $1 == "p" ]
then
    g++ -DPRINT_OPT=2 OpCodeTester.cpp ../i8080_struct.cpp OpCodeFunctions.cpp OpCodeFunctions_general.cpp OpCodeCaller.cpp -o proj -lm -std=c++11
elif [ $1 == "f" ]
then
    g++ -DPRINT_OPT=3 OpCodeTester.cpp ../i8080_struct.cpp OpCodeFunctions.cpp OpCodeFunctions_general.cpp OpCodeCaller.cpp -o proj -lm -std=c++11
elif [ $1 == "u" ]
then
    g++ -DPRINT_OPT=4 OpCodeTester.cpp ../i8080_struct.cpp OpCodeFunctions.cpp OpCodeFunctions_general.cpp OpCodeCaller.cpp -o proj -lm -std=c++11
else
    g++ OpCodeTester.cpp ../i8080_struct.cpp OpCodeFunctions.cpp OpCodeFunctions_general.cpp OpCodeCaller.cpp -o proj -lm -std=c++11
fi
./proj 
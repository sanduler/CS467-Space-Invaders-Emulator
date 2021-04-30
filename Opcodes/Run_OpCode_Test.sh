#!/bin/bash

g++ OpCodeTester.cpp ../i8080_struct.cpp OpCodeFunctions.cpp OpcodeFunctions_general.cpp OpCodeCaller.cpp -o proj -lm 
./proj 
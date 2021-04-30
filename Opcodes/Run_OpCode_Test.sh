#!/bin/bash

g++ OpCodeTester.cpp ../i8080_struct.cpp OpCodeFunctions.cpp OpcodeFunctions_general.cpp  -o proj -lm 
./proj 
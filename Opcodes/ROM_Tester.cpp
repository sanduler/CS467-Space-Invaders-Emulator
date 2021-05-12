#include <stdio.h>
#include <string>
#include "../i8080_struct.h"
#include "OpCodeFunctions.h"

// PRINT VARS
#ifndef PRINT_OPT   
#define PRINT_OPT    1
#endif

// CPU VARIABLES 
i8080_CPU i8080;               // CPU to run functions on

int main(int argc, char* argv[])
{
    i8080.state.LoadRomFiles();

    // Reads the next OpCode and Executes the OpCode
    int i = 0;

    for (i = 0; i < 1000 ; i++)
    {
        i8080.state.exe_OpCode();
    }
    

    return 0;
} 


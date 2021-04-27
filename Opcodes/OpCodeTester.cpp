#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <string>
#include "i8080_struct.h"

i8080_CPU i8080_control;
//i8080_CPU i8080_variable;

void resetCpu()
{
    // Delete the old CPU

    // Call the constructor on the new CPU

}

int main(int argc, char* argv[])
{
    printf("Hello World\n");
    printf("flag_Z:");
    printf("%d\n", i8080_control.state.flags.flag_Z);
    return 0;
}
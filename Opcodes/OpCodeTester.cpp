#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <string>
#include "i8080_struct.h"
using namespace std;

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
    printf("This is reg_A from constructor:\n");
    printf("%d\n", i8080_control.state.registers.get_Reg());
    
    //loads the room into the loadRom function
    int bl;

    bl = i8080_control.loadRom("rom/invaders.h", 0);
    bl += i8080_control.loadRom("rom/invaders.g", 0x0800);
    bl += i8080_control.loadRom("rom/invaders.f", 0x1000);
    bl += i8080_control.loadRom("rom/invaders.e", 0x1800);

    return 0;
}
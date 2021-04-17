#ifndef EMULATOR
#define EMULATOR

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "CPU.h"
#include "emulator.h"

//Function used to start the emulator. import a file 
void startEmulator(char*file);

//check the file size and if the file is found
int fileSize(char*file) 

current_8080 startEmulator();

//Load the rom into the current state and location
//use pointer to find the address location of the state and pointer to find the file in the
//memory
current_8080* LoadROM(current_8080 *state, char*file, uint16_t location);


#endif
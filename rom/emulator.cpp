#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "CPU.h"
#include "emulator.h"

/****************************************
 * Functions bellow deal with the interrupt
 * 
 * 
 * 
 * **************************************/

void createInterrupt(current_8080 *state, int flag_interrupt)
{
    //perform PUSH PC
	

    
    //set the flag interrupt



    //enable the state (0 ->1)  
}

int64_t getTime()
{
	//struct to get the time
    struct timespec tms;

    //returns the time of the clock cycle
}


/****************************************
 * Functions bellow deal with the rom file
 * 
 * 
 * 
 * **************************************/

int fileSize(char*file) 
{

	//open rom file

    
    //if the file size does not match


    //close the file


    //return file size

}

current_8080* LoadROM(current_8080 *state, char*file, uint16_t location) 
{

    //if file is not found then seek the file and print the error message


    //get the size from getSize and compare


    // read in file


    //write in memort the location and the state.


    //print message that the rom is loaded


    //return the state of the rom when its loaded
   
}

/****************************************
 * Functions bellow deal with the starting
 * running and functioning of the emulator
 * 
 * 
 * **************************************/

//sets up the emulator initileses all the states and codes to false
current_8080 setEmulator()
{
	ConditionCodes cc;

	//sets the condition codes to 0 --> false
	c_Codes.z = 0;
    c_Codes.s = 0;
    c_Codes.p = 0;
    c_Codes.cy = 0;
    c_Codes.ac = 0;


    //sets the current state of the emulator to 0 --> false
    current_8080 state;
    state.a = 0;
    state.b = 0;
    state.c = 0;
    state.d = 0;
    state.e = 0;
    state.h = 0;
    state.l = 0;
    state.sp = 0;
    state.pc = 0;
    state.int_enable = 0;
    size_t max_size = 1 << 15;


    //returns the state
    return state;
}

//starts the emulator
void startEmulator(char*file)
{
	current_8080 state = startEmulator();
	LoadROM(&state, file, 0x0);

	int cyclesCPU = 0;
    int speedClock = 2e6 / 120;
    int fsize = fileSize(file);

	uint64_t cur_time = getTime();
    if (!state.int_enable) 
    {
        startTime = cur_time;
    }

cyclesCPU += NextInstruction(&state, &inp);
}
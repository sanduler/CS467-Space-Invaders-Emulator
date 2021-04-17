#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "CPU.h"
#include "emulator.h"

void createInterrupt(current_8080 *state, int flag_interrupt)
{
    //perform PUSH PC
	

    
    //set the flag interrupt



    //enable the state (0 ->1)  
}

int GetFileSize(char*file) 
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
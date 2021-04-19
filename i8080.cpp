//
// Created by Ruben Sanduleac on 4/18/21.
//

#include <iostream>
#include "i8080.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include<cstdarg>



#define Z_FLAG  (1 << 7)
#define S_FLAG  (1 << 6)
#define P_FLAG  (1 << 5)
#define CY_FLAG (1 << 4)
#define AC_FLAG (1 << 3)
#define ALL_FLAGS (Z_FLAG | S_FLAG | P_FLAG | CY_FLAG | AC_FLAG)


//cycles for the 8080 emulator described in each of the code
unsigned char cycles8080[] =
{
		//first line (line 15) 0x00..0x0f Line 16: 0x10..0x1f 
        4, 10, 7, 5, 5, 5, 7, 4, 4, 10, 7, 5, 5, 5, 7, 4, 			
        4, 10, 7, 5, 5, 5, 7, 4, 4, 10, 7, 5, 5, 5, 7, 4, 			
        4, 10, 16, 5, 5, 5, 7, 4, 4, 10, 16, 5, 5, 5, 7, 4, 		
        4, 10, 13, 5, 10, 10, 10, 4, 4, 10, 13, 5, 5, 5, 7, 4,

        //Line 21: 0x40..0x4f
        5, 5, 5, 5, 5, 5, 7, 5, 5, 5, 5, 5, 5, 5, 7, 5, 			
        5, 5, 5, 5, 5, 5, 7, 5, 5, 5, 5, 5, 5, 5, 7, 5,
        5, 5, 5, 5, 5, 5, 7, 5, 5, 5, 5, 5, 5, 5, 7, 5,
        7, 7, 7, 7, 7, 7, 7, 7, 5, 5, 5, 5, 5, 5, 7, 5,

        //Line 27: 0x80..8x4f
        4, 4, 4, 4, 4, 4, 7, 4, 4, 4, 4, 4, 4, 4, 7, 4, 			
        4, 4, 4, 4, 4, 4, 7, 4, 4, 4, 4, 4, 4, 4, 7, 4,
        4, 4, 4, 4, 4, 4, 7, 4, 4, 4, 4, 4, 4, 4, 7, 4,
        4, 4, 4, 4, 4, 4, 7, 4, 4, 4, 4, 4, 4, 4, 7, 4,

        //Line 33: 0xc0..0xcf 
        11, 10, 10, 10, 17, 11, 7, 11, 11, 10, 10, 10, 10, 17, 7, 11, 
        11, 10, 10, 10, 17, 11, 7, 11, 11, 10, 10, 10, 10, 17, 7, 11,
        11, 10, 10, 18, 17, 11, 7, 11, 11, 5, 10, 5, 17, 17, 7, 11,
        11, 10, 10, 4, 17, 11, 7, 11, 11, 5, 10, 4, 17, 17, 7, 11,
};

//detect error in 8 bit code
uint8_t errorParity(uint16_t value)
{
    //check the size of the 8 bit file using a for loop
}

/*****************************
 * Function Type: bool, checks if true
 * Discription: This function takes the bits balue to comapre the sizes
 * parity
 * this is done by checking the lower and upper limits of the bit value and com
 * comapring them using the modulus operator
 * **************/

bool parity(uint8_t b_bits)
{
    //lower and upper check for bits
    uint8_t upperbit = 8;
    uint8_t lowerbit = 0;

    //while loop to decrement to 8
    while (upperbit-- > 0)
    {
        //increment the bits
        lowerbit += ((b_bits >> upperbit) & 1);
    }

    //return the bit value
    return ((lowerbit % 2) == 0);
}

/*****************************
 * Function Type: constructor: i8080::i8080(size_t memorySize, uint16_t beginPoint)
 * Discription: This function allocates memory and sets the size
 * depending on the rom file then sets the starting point in 
 * memory
 * **************/
i8080::i8080(size_t memorySize, uint16_t beginPoint)
{
    //Find in memory
    this->memsize = memorySize;

    //allocate the memory set in specific point in memomory in an array 
    
    memory = new uint8_t[memorySize];
    
    PC = beginPoint;

}

/*****************************
 * Function Type: destructor, ~i8080();
 * Discription: clears the allocated memory 
 * **************/
i8080::~i8080()
{
    delete[] memory;
}

/*****************************
 * Function Type: int i8080::loadRom(const char * nameOfFile, size_t offset)
 * Discription: gets the name of the rom, loads the rom into the meormy and then
 *              checks if its loaded iof not breaks the loop and returns false 
 * **************/

int i8080::loadRom(const char * nameOfFile, size_t offset)
{

    //sets the size in memory to 0 = false
    size_t s = 0;

    //load the rom in usign ifstream 
    ifstream rom(nameOfFile, ios::binary);
    
    //use if statement to check if rom is loaded or rom exists
    if (!rom)
    {
        cout << "No rom loaded, please try again" << endl;
        return s;
    }

    //While loop, used when the rom does exists loads the rom into the memor
    while (true)
    {
        if ((offset + s) >= memsize)
            break;

        //get the rom
        auto i = rom.get();
        if (i == EOF)
            break;
        memory[offset + s] = i;
        ++s;
    }
    return s;
}


uint8_t auxiliaryCarryAdd(State8080 *state ,uint16_t value, uint16_t result)
{
    //take the Auxiliary Carry flag 
}

uint8_t auxiliaryCarrySub(State8080 *state ,uint16_t value, uint16_t result)
{
    //take the Auxiliary Carry flag 
}

uint8_t ifZero(uint16_t value) 
{
  //return the value if equal 0
}

uint8_t ifSign(uint16_t value) 
{
  //return value if =
}

uint8_t ifCarry(uint16_t value) 
{
    //return the vaulue if > 
}

//sets the flags for the code
void SetArithFlags(State8080 *state, uint16_t value, uint8_t flagstoset) 
{
    // remove trailing bits
    uint8_t clean = flagstoset & 0b11111000;
    if (clean & Z_FLAG) 
    {
        state->cc.z = Zero(value);
    }
    else if (clean & S_FLAG) 
    {
        state->cc.s = Sign(value);
    }
    else if (clean & P_FLAG) 
    {
        state->cc.p = Parity(value);
    }
    else if (clean & CY_FLAG) 
    {
        state->cc.cy = Carry(value);
    }

    else if (clean & AC_FLAG)
    { 
      state->cc.ac = 0;
    }
}

//start the emulation by receving the opcode from the opcodefunction.cpp
int Emulate8080Op(State8080* state)
{
    unsigned char *opcode = &state->memory[state->pc];
}
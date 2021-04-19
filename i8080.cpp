//
// Created by Ruben Sanduleac on 4/18/21.
//

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


bool parity(uint8_t b_bits)
{
    //lower and upper check for bits
    uint8_t upperbit = 8;
    uint8_t lowerbit = 0;

    //while loop to decrement to 8
    while (n-- > 0)
    {
        //increment the bits
        lowerbit += ((b_bits >> upperbit) & 1);
    }

    //return the bit value
    return ((lowerbit % 2) == 0);
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
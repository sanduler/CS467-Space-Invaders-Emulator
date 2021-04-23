/*********************************
 * i8080 Emulator
 * - Flags Class
 * - Register Class
 * - State Class
 * - i8080 Class
 ********************************/
#include "i8080.h"
#include <iostream>
#include <cstdint>
#include <cstring>
#include <fstream>

bool i8080_Flags::AC()
{
    return false;
}

i8080_Flags::i8080_Flags()
{

}

/*****************************
 * Function Type: destructor, ~i8080_Flags;
 * Discription: clears the allocated memory
 * **************/
i8080_Flags::~i8080_Flags()
{

}

double i8080_Flags::get_AC()
{
    return 0;
}

double i8080_Flags::set_AC()
{
    return 0;
}

bool i8080_Flags::unset_AC()
{
    return false;
}

double i8080_Registers::unint_get_A()
{
    return 0;
}

void i8080_Registers::set_A(int A)
{

}

int i8080_Registers::unint_PC()
{
    return 0;
}

int i8080_Registers::get_PC()
{
    return 0;
}

void i8080_Registers::set_PC(int PC)
{

}

i8080_State::i8080_State()
{

}

/*****************************
 * Function Type: destructor, ~i8080_State();
 * Discription: clears the allocated memory
 * **************/
i8080_State::~i8080_State()
{

}
int i8080_State::unint_SP()
{
    return 0;
}

double i8080_State::get_SP()
{
    return 0;
}

void i8080_State::set_SP(int SP)
{

}

int i8080_State::unset_AC()
{
    return 0;
}

//general contructor
i8080::i8080()
{

}

/*****************************
 * Function Type: destructor, ~i8080();
 * Discription: clears the allocated memory
 * **************/
i8080::~i8080()
{

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
    std::ifstream rom(nameOfFile, std::ios::binary);

    //use if statement to check if rom is loaded or rom exists
    if (!rom)
    {
        std::cout << "No rom loaded, please try again" << std::endl;
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

i8080_State i8080::setupEmulator()
{
    return i8080_State();
}

void i8080::startEmulator(char *file)
{
    //starts the emulator
}



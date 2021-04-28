/*********************************
 * i8080 Emulator
 * - Flags Class
 * - Register Class
 * - State Class
 * - i8080 Class
 ********************************/
#include "i8080_struct.h"
#include <iostream>
#include <cstdint>
#include <cstring>
#include <fstream>
using namespace  std;


bool i8080_Flags::AC()
{
    //debug
    cout << "Flag is off" << endl;
    return false;
}

/*****************************
 * Function Type: i8080_Flags(), constructor
 * Discription: initilize the flags and set them to 0 in the contructor
 * **************/
i8080_Flags::i8080_Flags()
{
    cout << "Constructor: Flags have been initilized " << endl;
    // Set Flags
    flag_S = 0;
    flag_Z = 0;
    flag_AC = 0;
    flag_P = 0;
    flag_C = 0;
}

/*****************************
 * Function Type: destructor, ~i8080_Flags;
 * Discription: clears the allocated memory
 * **************/
i8080_Flags::~i8080_Flags()
{
    cout << "Memory in Flags has been cleared " << endl;
}

double i8080_Flags::get_AC()
{
    cout << "Get the AC Flag" << endl;
    flag_AC = 0;
    return 0;
}

bool i8080_Flags::set_AC()
{
    cout << "Set the AC Flag" << endl;
    flag_AC = 0;
}

bool i8080_Flags::unset_AC()
{
    cout << "Unset the AC Flag" << endl;
    flag_AC = 0;
}

int i8080_Register::get_Reg()
{
    cout << "Get the Register" << endl;
    return reg_A;

}


void i8080_Register::set_Reg(uint8_t i)
{
    cout << "Set the Register" << endl;
    reg_A = i;
}

int i8080_Register::unint_PC() {
    return 0;
}

void i8080_Register::set_A(int A) {

}

double i8080_Register::unint_get_A() {
    return 0;
}


i8080_State::i8080_State()
{

    cout << "Constructor: State has been initilized...." << endl;

    registers.set_Reg(5);

    //i8080_State state;
    //size_t max_size = 1 << 15;
    //state.memory = (uint8_t*) malloc(max_size * sizeof(*state.memory));

}

/*****************************
 * Function Type: destructor, ~i8080_State();
 * Discription: clears the allocated memory
 * **************/
i8080_State::~i8080_State()
{
    cout << "Memory in State has been cleared " << endl;
}
int i8080_State::unint_SP()
{
    uint16_t SP;
    SP = 0;
}

double i8080_State::get_SP()
{
    cout << "Get SP" << endl;
    uint16_t  _sp;
}

void i8080_State::set_SP(int SP)
{
    cout << "SET SP" << endl;
}

bool i8080_State::unset_AC()
{
    cout << "UNSET AC" << endl;
}


//general contructor
i8080_CPU::i8080_CPU()
{
    cout << "Constructor: i8080_CPU has been initilized...." << endl;
    this->state.memsize = state.memsize;
    memory = new uint8_t[state.memsize];
    cout << "Memory: has been to allocated" << endl;
}

/*****************************
 * Function Type: destructor, ~i8080_CPU();
 * Discription: clears the allocated memory
 * **************/
i8080_CPU::~i8080_CPU()
{
    delete memory;
    cout << "Memory in i8080_CPU has been cleared " << endl;
}

/*****************************
 * Function Type: int i8080::loadRom(const char * nameOfFile, size_t offset)
 * Discription: gets the name of the rom, loads the rom into the meormy and then
 *              checks if its loaded iof not breaks the loop and returns false
 * **************/
int i8080_CPU::loadRom(const char * nameOfFile, size_t offset)
{
    cout << "Start Loading the Rom " << endl;
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
        if ((offset + s) >= state.memsize)
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
 * Function Type: constructor: i8080_CPU::i8080_CPU(size_t memorySize, uint16_t beginPoint)
 * Discription: This function allocates memory and sets the size
 * depending on the rom file then sets the starting point in
 * memory
 * **************/


i8080_State i8080_CPU::setupEmulator()
{
    cout << "Emulator is being set up" << endl;
    return i8080_State();
}

void i8080_CPU::startEmulator(char *file)
{
    cout << "Emulator has started " << endl;
    //starts the emulator
}


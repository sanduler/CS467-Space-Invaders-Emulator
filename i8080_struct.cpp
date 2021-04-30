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


void i8080_Flag::set(bool new_val)
{
    //cout << "Attempt to set flag (" + to_string(new_val) + ")...";
    val = new_val;
    //cout << "Success: " + to_string(val) << endl;
}

bool i8080_Flag::get()
{
    return val;
}

uint8_t i8080_Register::get_Large()
{
    return large_val;
}

uint8_t i8080_Register::get()
{
    return val;
}

void i8080_Register::set(uint8_t i)
{
    val = i;
}

void i8080_Register::set_Large(uint16_t i)
{
    large_val = i;
}

i8080_State::i8080_State()
{

    //cout << "Constructor: State has been initilized...." << endl;

    // Set Flags
    flag_Z.set(0);
    flag_S.set(0);
    flag_P.set(0);
    flag_C.set(0);
    flag_AC.set(0);

    //set registers
    reg_A.set(0);
    reg_B.set(0);
    reg_C.set(0);
    reg_D.set(0);
    reg_E.set(0);
    reg_H.set(0);
    reg_L.set(0);
    reg_SP.set(0);
    reg_PC.set(0);



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
    //cout << "Memory in State has been cleared " << endl;
    //cout << "START: ";
    //cout << __func__ ;
    //cout << "... END" << endl;;
}

//general contructor
i8080_CPU::i8080_CPU()
{
    //cout << "Constructor: i8080_CPU has been initilized...." << endl;
    //cout << "START: ";
    //cout << __func__ ;
    // COMMENTED OUT DUE TO ERROR - Woy
    //this->state.memsize = state.memsize;
    //memory = new uint8_t[state.memsize];
    //cout << "... END" << endl;;
    //cout << "Memory: has been to allocated" << endl;
}

/*****************************
 * Function Type: destructor, ~i8080_CPU();
 * Discription: clears the allocated memory
 * **************/
i8080_CPU::~i8080_CPU()
{
    //cout << "START: ";
    //cout << __func__ ;
    //delete memory;
    //cout << "... END" << endl;;
    //cout << "Memory in i8080_CPU has been cleared " << endl;
}

/*****************************
 * Function Type: int i8080::loadRom(const char * nameOfFile, size_t offset)
 * Discription: gets the name of the rom, loads the rom into the meormy and then
 *              checks if its loaded iof not breaks the loop and returns false
 * **************/
int i8080_CPU::loadRom(const char * nameOfFile, size_t offset)
{
    //cout << "Start Loading the Rom " << endl;
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

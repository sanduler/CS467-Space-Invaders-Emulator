//
// Created by Ruben Sanduleac on 4/21/21.
//

#include "i8080.h"
#include <stdint.h>
#include <string.h>

i8080::i8080(class memory *mem, uint8_t _ConsoleMode)
{
    
}


int i8080::state::unint_SP()
{
    return 0;
}

void i8080::state::set_SP(int SP)
{
    //sets the state of emulator
}

double i8080::state::get_SP()
{
    //returns the state of emulator
    return 0;
}

int i8080::state::unset_AC()
{
    //unsets the AC and returns the unset
    return 0;
}


bool i8080::state::Flags::AC()
{
    //retuns the sate of the flags
    return false;
}

double i8080::state::Flags::get_AC()
{
    return 0;
}

double i8080::state::Flags::set_AC()
{
    return 0;
}

bool i8080::state::Flags::unset_AC()
{
    return false;
}


int i8080::state::Inputs::get_Inputs()
{
    return 0;
}

double i8080::state::Registers::unint_get_A()
{
    return 0;
}

void i8080::state::Registers::set_A(int A)
{

}

int i8080::state::Registers::unint_PC()
{
    return 0;
}

int i8080::state::Registers::get_PC()
{
    return 0;
}

void i8080::state::Registers::set_PC(int PC)
{

}


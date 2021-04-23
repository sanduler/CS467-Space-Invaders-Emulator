/*********************************
 * i8080 Emulator
 * - Flags Class
 * - Register Class
 * - State Class
 * - i8080 Class
 ********************************/
#include "i8080.h"
#include <cstdint>
#include <cstring>

bool i8080_Flags::AC()
{
    return false;
}

i8080_Flags::i8080_Flags()
{

}

i8080_Flags::~i8080_Flags() {

}

double i8080_Flags::get_AC() {
    return 0;
}

double i8080_Flags::set_AC() {
    return 0;
}

bool i8080_Flags::unset_AC() {
    return false;
}

double i8080_Registers::unint_get_A() {
    return 0;
}

void i8080_Registers::set_A(int A) {

}

int i8080_Registers::unint_PC() \{
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


i8080::i8080()
{

}

i8080::~i8080()
{

}

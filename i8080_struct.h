/*********************************
 * i8080_CPU Emulator
 * - Flags Class
 * - Register Class
 * - State Class
 * - i8080_CPU Class
 ********************************/

#pragma once
#ifndef I8080_STRUCT_H
#define I8080_STRUCT_H
#include <cstdint>
#include <stdint.h>
#include <cstddef>
#include <iostream>
#include <stdio.h>
#include <array>


/*********************************
 * Flags class
 * Sets the flags for the opcodes
 ********************************/
class i8080_Flag
{
private:
    bool val;
public:
    void set(bool new_val);
    bool get();
};

/*********************************
 * Registers class
 * Intializes the Registers
 ********************************/
class i8080_Register {
private:
    uint8_t val;
    uint16_t large_val;
public:
    uint8_t get_Large();
    uint8_t get();
    void set(uint8_t i);
    void set_Large(uint16_t i);
};

/*********************************
 * State class
 * Gets the state of the emulator
 * uses the flags and registers objects
 * as members
 ********************************/
class i8080_State {
private:
    void LoadRom(const char* fileName, size_t address);
public:
    //Constructor and destructor
    i8080_State();
    ~i8080_State();

    // Opcode Array
    uint8_t opCode_Array[3];

    // Registers
    i8080_Register reg_A;
    i8080_Register reg_B;
    i8080_Register reg_C;
    i8080_Register reg_D;
    i8080_Register reg_E;
    i8080_Register reg_H;
    i8080_Register reg_L;
    i8080_Register reg_SP;
    i8080_Register reg_PC;
    i8080_Register reg_PSW;

    // Special registers
    uint16_t get_BC();
    uint16_t get_HL();
    uint16_t get_DE();
    void set_BC(uint16_t val);
    void set_HL(uint16_t val);
    void set_DE(uint16_t val);


    uint8_t get_PSW();

    // Flags
    //uint8_t FlagZSP[0x100]; // Precalculated ZSP
    i8080_Flag flag_Z; // Zero
    i8080_Flag flag_S; // Sign
    i8080_Flag flag_P; // Parity
    i8080_Flag flag_C; // Carry
    i8080_Flag flag_AC; // Auxiliar Carry
    i8080_Flag flag_INTE;

    //Memory
    uint8_t     get_Memory(uint16_t index);
    void        set_Memory(uint16_t index, uint8_t val);
    std::array<uint8_t, 65536> mem_Array;
    uint16_t    get_Adr();
    uint8_t     get_M();
    void        set_M(uint8_t val);
    void        LoadRomFiles();

    // User input handlers
    void move_right();
    void move_left();
    void insert_coin();
    void fire();
};

/*********************************
 * i8080 class
 * recieves the state class as a member
 * loads the rom and intilizes the emulator
 ********************************/
class i8080_CPU {
private:
public:
    i8080_CPU();
    i8080_State     state;
    ~i8080_CPU();
    unsigned char   ROM;
};


#endif
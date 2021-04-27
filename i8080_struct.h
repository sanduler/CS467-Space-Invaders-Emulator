/*********************************
 * i8080_CPU Emulator
 * - Flags Class
 * - Register Class
 * - State Class
 * - i8080_CPU Class
 ********************************/

#ifndef I8080_STRUCT_H
#define I8080_STRUCT_H
#include <cstdint>
#include <stdint.h>

/*********************************
 * Flags class
 * Sets the flags for the opcodes
 ********************************/
class i8080_Flags{
private:
public:
    i8080_Flags();
    ~i8080_Flags();
    bool S;
    bool Z;
    bool ZeroValue = 0;
    bool OneValue = 1;
    bool AC();
    double get_AC();
    double set_AC();
    bool unset_AC();
    // Flags
    uint8_t FlagZSP[0x100]; // Precalculated ZSP
    uint8_t flag_Z; // Zero
    uint8_t flag_S; // Sign
    uint8_t flag_P; // Parity
    uint8_t flag_C; // Carry
    uint8_t flag_AC; // Auxiliar Carry
};

/*********************************
 * Registers class
 * Intializes the Registers
 ********************************/
class i8080_Registers {
private:
public:
    double unint8_A;
    double unint_get_A();
    void set_A(int A);
    int unint_PC();
    int get_PC();
    void set_PC(int PC);

    uint8_t   a;
    uint8_t   b;
    uint8_t   c;
    uint8_t   d;
    uint8_t   e;
    uint8_t   h;
    uint8_t   l;
    uint16_t  sp;
    uint16_t  pc;
    uint8_t   *memory;
    i8080_Flags  ConditionCodes;
    uint8_t   int_enable;
};

/*********************************
 * State class
 * Gets the state of the emulator
 * uses the flags and registers objects
 * as members
 ********************************/
class i8080_State {
private:
public:
    i8080_State();
    ~i8080_State();
    i8080_Flags flags;
    i8080_Registers registers;
    int unint_SP();
    double get_SP();
    void set_SP(int SP);
    int unset_AC();
};

/*********************************
 * i8080 class
 * recieves the state class as a member
 * loads the rom and intilizes the emulator
 ********************************/
class i8080_CPU {
private:
public:
    i8080_State state;
    i8080_CPU();
    i8080_CPU(size_t memsize = 0x10000, uint16_t startpoint = 0);
    ~i8080_CPU();
    unsigned char ROM;
    double memory;

    i8080_State setupEmulator();

    //Loads the rom into the emulator
    int loadRom(const char * nameOfFile, size_t offset);

    void startEmulator (char*file);
};


#endif I8080_H

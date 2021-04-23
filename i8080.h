/*********************************
 * i8080 Emulator
 * - Flags Class
 * - Register Class
 * - State Class
 * - i8080 Class
 ********************************/

#ifndef PROJECT101_I8080_H
#define PROJECT101_I8080_H
#include <cstdint>
#include <stdint.h>
#include <opencl-c-base.h>


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
    uint16 A;
    uint8 B;
    uint8 C;
    uint16 PC;
    uint16 SP;

    double unint8_A;
    double unint_get_A();
    void set_A(int A);
    int unint_PC();
    int get_PC();
    void set_PC(int PC);

    uint8_t* reg_M;
    uint8_t true_reg_A;
    uint8_t* reg_A = &true_reg_A; // Pointer uniformity
    uint16_t reg_BC;
    uint8_t* reg_B = ((uint8_t*) &reg_BC) + 1;
    uint8_t* reg_C = ((uint8_t*) &reg_BC);
    uint16_t reg_DE;
    uint8_t* reg_D = ((uint8_t*) &reg_DE) + 1;
    uint8_t* reg_E = ((uint8_t*) &reg_DE);
    uint16_t reg_HL;
    uint8_t* reg_H = ((uint8_t*) &reg_HL) + 1;
    uint8_t* reg_L = ((uint8_t*) &reg_HL);
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
class i8080 {
private:
    i8080_State state;
public:
    i8080();
    i8080(size_t memsize = 0x10000, uint16_t startpoint = 0);
    ~i8080();
    unsigned char ROM;
    double memory;

    //Loads the rom into the emulator
    int loadRom(const char * nameOfFile, size_t offset)
};


#endif //PROJECT101_I8080_H

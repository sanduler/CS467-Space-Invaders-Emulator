//
// Created by Ruben Sanduleac on 4/18/21.
//
//https://git.megabeast.de/nanovna/ChibiOS/-/blob/1b5ab277a84f95e8fd54c313d512074e34af63ef/os/common/ports/AVR/chcore.h -> for the structure
//http://support.raisonance.com/content/possible-problem-stm8-compiler
#ifndef PROJECT_i8080_H
#define PROJECT_i8080_H

#include <iostream>
#include <vector>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unordered_map>
#include <fstream>
#include <cstdarg>
#include <iomanip>

//Header for opcodes that will get passed down to the strcuture of the scpu #include "////////"
using std::ifstream;
using std::ios;
using std::vector;
using std::std::sprintf

bool parity(uint8_t b_bits);
class i8080{
private:
public:
	union
    {
        struct
        {
            uint8_t I2; //instr byte 2 (lsb)
            uint8_t I3; //instr byte 3
        };
        uint16_t I; //I3-I2
    };
    //resgisters
    union
    {
        struct
        {
            uint8_t C; //lsb
            uint8_t B; //msb
        };
        uint16_t BC; //msb-lsb
    };
    union
    {
        struct
        {
            uint8_t E;
            uint8_t D;
        };
        uint16_t DE;
    };
    union
    {
        struct
        {
            uint8_t L;
            uint8_t H;
        };
        uint16_t HL;
    };
    union
    {
        struct
        {
            uint8_t Z;
            uint8_t W;
        };
        uint16_t WZ;
    };
    //stack pointer
    union
    {
        struct
        {
            uint8_t P;//l
            uint8_t S;//m
        };
        uint16_t SP;
    };
    //programm counter
    union
    {
        struct
        {
            uint8_t PCL;
            uint8_t PCH;
        };
        uint16_t programCounter;
    };

    //ALU
    uint8_t A;

    struct
    {
        uint8_t Z_, CY_, S_, P_, AC_;
    };

    //END ALU
	//debugging is set to false can be turned on if needed
	bool debug = false;
	//incremtn the program counter
	bool incrementPC;

	//create and iterupt switch --> set to false
	bool interruptSwitch = false; 

	// pointer pointing at memory for uint8_t
	uint8_t *memory;

	//Interrupt service routine used to handle
	//interupts as quickly as possible so one
	//can resume execution on threads

    uint8_t ISR = 0;
	//general constructor, sets memorysize and starting point
	i8080(size_t memSize = 0x10000, uint16_t beginPoint = 0);

	//general destructor that clears the memory
    ~i8080();

    //load the roam into memory
    int loadRom(const char* nameOfFile, size_t offset = 0x00);

    uint8_t cycleEmulate();

    void EnableInterrput();
    void Interrupt(uint8_t ISR);
    void initializeFlags(uint16_t result, uint8_t o);
    void SetFlags_NC(uint16_t result);

    //conditions
    bool _NZ();
    bool _Z();
    bool _NC();
    bool _C();
    bool _PO();
    bool _PE();
    bool _P();
    bool _M();

typedef struct ConditionCodes
{
    //conditional codes go here

} ConditionCodes;


typedef struct State8080
{
	//states of the emualtor are recorded here

}current_8080;


#endif
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

typedef struct ConditionCodes
{
    //conditional codes go here

} ConditionCodes;


typedef struct State8080
{
	//states of the emualtor are recorded here

}current_8080;


#endif
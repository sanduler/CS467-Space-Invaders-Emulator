//
// Created by Ruben Sanduleac on 4/18/21.
//

#ifndef PROJECT_i8080_H
#define PROJECT_i8080_H


#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<iostream>
#include<vector>
#include<unordered_map>
#include "i8080.h"
#include <fstream>
#include<cstdarg>
#include<iomanip>
//Header for opcodes that will get passed down to the strcuture of the scpu #include "////////"
using std::ifstream;
using std::ios;
using std::vector;

bool parity(uint8_t b_bits);
class i8080{
private:
public:

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


typedef struct ConditionCodes
{
    //conditional codes go here

} ConditionCodes;


typedef struct State8080
{
	//states of the emualtor are recorded here

}current_8080;


#endif
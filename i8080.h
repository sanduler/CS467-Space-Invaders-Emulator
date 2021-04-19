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
class i8080
{
	private:
	public:
	
typedef struct ConditionCodes
{
    //conditional codes go here

} ConditionCodes;


typedef struct State8080
{
	//states of the emualtor are recorded here

}current_8080;


#endif
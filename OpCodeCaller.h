//********************************************************
//* OpCodeCaller.h
//* CS467
//* Madison Woy
//* Ruben Sanduleac
//* Michael Matthews
//* Description: Serves as the header file for the library of Opcode Caller for the Intel 8080 processor.
//* 			
//*	
//* Last Modified: 5/11/2021
//*
//* Sites used for Information
//* https://pastraiser.com/cpu/i8080/i8080_opcodes.html - Good Page for visual layout of Opcodes
//* 
//* http://www.emulator101.com/8080-by-opcode.html
//********************************************************

#pragma once
#ifndef _OpCodeFunctions_H
#define _OpCodeFunctions_H

#include "i8080_struct.h"

using namespace std;

// CALLER FUNCTION
void eval_opCode(unsigned char passed_code);



#endif


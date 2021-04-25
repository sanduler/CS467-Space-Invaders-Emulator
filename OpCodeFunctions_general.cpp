//********************************************************
//* OpCodeFunctions.cpp
//* CS467
//* Madison Woy
//* Ruben Sanduleac
//* Michael Matthews
//* Description: Serves as the library of Opcode Functions for the Intel 8080 processor.
//* 			
//*	
//* Last Modified: 2/9/2020
//*
//* Sites used for Information
//* https://pastraiser.com/cpu/i8080/i8080_opcodes.html - Good Page for visual layout of Opcodes
//* 
//* http://www.emulator101.com/8080-by-opcode.html
//********************************************************

#include <stdio.h>
#include "OpCodeFunctions.h"
#include "i8080.h"

//***** REGISTERS *****//
// 15 ... 8	7 ... 0		For 16 bit instructions
// A		F (Flags)	PSW
// B		C			B
// D		E			D
// H		L			H
//
// 15 ... 0
// SP (Stack Pointer)
// PC (Program Counter)

//***** FLAGS *****//
// 7	6	5	4	3	2	1	0
// S	Z	0	AC	0	P	1	CY
// S = Sign Flag : Set to 1 when bit 7 of math result is set
// Z = Zero Flag : Set to 1 when result is Zero
// 0 = Not Used, Always Zero
// AC = Auxiliary Carry : Carry Out Bit, but for Bit 3 of the instruction result (Only used for DAA https://altairclone.com/downloads/manuals/8080%20Programmers%20Manual.pdf)
// P = Parity Flag : Set to 1 when the result has even parity, 0 when it has odd parity
// 1 = Not Used, Always One
// CY = Carry Flag : Set to 1 when a carry out or borrow was used in the carry bit
//

// Generic Add Function to pass the ADD OpCodes to
void func_ADD_Registers(uint8_t &uint8_Register)
{
	uint8_t uint8_InitialA = i8080.state.registers.get_A();
	uint8_t uint8_ResultTemp = i8080.state.registers.get_A() + uint8_Register;
	
	i8080.state.registers.set_A(uint8_ResultTemp);
	
	// S	Z	AC	P	CY
	
	i8080.state.flags.S.set(func_Check_Sign());
	i8080.state.flags.Z.set(func_Check_Zero());
	i8080.state.flags.AC.set(func_Check_AuxCarry(uint8_InitialA, uint8_Register));
	i8080.state.flags.P.set(func_Check_Parity());
	i8080.state.flags.CY.set(func_Check_Carry(uint8_InitialA, uint8_Register));
	
};

// Generic Sub Function to pass the SUB OpCodes to
int func_SUB_Registers(uint8_t &uint8_Register)
{
	uint8_t uint8_InitialA = i8080.state.registers.get_A();
	uint8_t uint8_RegisterTwosCompliment = (~uint8_Register) + 0x01;
	uint8_t uint8_ResultTemp = i8080.state.registers.get_A() - uint8_Register;
	
	i8080.state.registers.set_A(uint8_ResultTemp);
	
	// S	Z	AC	P	CY
	i8080.state.flags.S.set(func_Check_Sign());
	i8080.state.flags.Z.set(func_Check_Zero());
	// When checking the Auxiliary Carry Bit Source2 needs to be a 2's compliment
	i8080.state.flags.AC.set(func_Check_AuxCarry(uint8_InitialA, uint8_RegisterTwoCompliment);
	
	i8080.state.flags.P.set(func_Check_Parity());
	
	// When checking the Carry Bit Source2 needs to be a 2's compliment
	// the result has to be negated also before setting/resetting the flag.
	i8080.state.flags.CY.set(!func_Check_Carry(uint8_InitialA, uint8_RegisterTwosCompliment));
	
};

// Generic And Function to pass the ANA OpCodes to
int func_AND_Registers(uint8_t &uint8_Register)
{
	uint8_t uint8_ResultTemp = i8080.state.registers.get_A() & uint8_Register;
	
	i8080.state.registers.set_A(uint8_ResultTemp);
	
	// According to the i8080 Programming Manual the ANA instructions do not affect the AC Flag (pg 19)
	// This differs from the documentation on other sites.
	// S	Z	P	CY
	
	i8080.state.flags.S.set(func_Check_Sign());
	i8080.state.flags.Z.set(func_Check_Zero());
	i8080.state.flags.P.set(func_Check_Parity());
	i8080.state.flags.CY.set(0);
};

// Generic Or Function to pass the ORA OpCodes to
int func_OR_Registers(uint8_t &uint8_Register)
{
	uint8_t uint8_ResultTemp = i8080.state.registers.get_A() | uint8_Register;
	
	i8080.state.registers.set_A(uint8_ResultTemp);
	
	// According to the i8080 Programming Manual the ANA instructions do not affect the AC Flag (pg 19)
	// This differs from the documentation on other sites.
	// S	Z	P	CY
	i8080.state.flags.S.set(func_Check_Sign());
	i8080.state.flags.Z.set(func_Check_Zero());
	i8080.state.flags.P.set(func_Check_Parity());
	i8080.state.flags.CY.set(0);
	
};

// Generic Move Function to pass the MOV OpCodes to
int func_MOV_Registers(uint8_t &uint8_RegisterDestination, uint8_t &uint8_RegisterSource)
{
	// NOTE: How is this supposed to work if we are using set statements for the values of the Registers?????
	uint8_RegisterDestination = uint8_RegisterSource;
};

// Generic Check Sign Function to return the Sign of a register value
// Reference Material: https://www.cprogramming.com/tutorial/bitwise_operators.html
bool func_Check_Sign()
{
	bool boolResult = 0;
	
	if (i8080.state.registers.get_A() & 0x80 != 0x00){
		boolResult = 1;
	}
		
	return boolResult;
};

// Generic Check Sign Function to return the Sign of a register value
bool func_Check_Zero()
{
	bool boolResult = 0;
	
	if (i8080.state.registers.get_A() == 0x00){
		boolResult = 1;
	}
	
	return boolResult;
};

// Generic Check Auxiliary Carry Function to return if there was a carry from the bit position 3 addition/subtraction/etc.
bool func_Check_AuxCarry(uint8_t uint8_Source1, uint8_t uint8_Source2)
{
	bool boolResult = 0;
	
	uint8_t uint8_Carry = 0x00;
	
	int intBitPosition;
	uint8_t uint8_Source1Temp = 0x00;
	uint8_t uint8_Source2Temp = 0x00;
	uint8_t uint8_ResultTemp = 0x00;
	
	for (intBitPosition = 0; intBitPosition < 4 ; intBitPosition++){
		
		uint8_Source1Temp = 0x00;
		uint8_Source2Temp = 0x00;
		
		uint8_Carry = uint8_Carry >> 1;
		
		uint8_Source1Temp = ((uint8_Source1 >> intBitPosition) & 0x01);
		uint8_Source2Temp = ((uint8_Source2 >> intBitPosition) & 0x01);
		
		uint8_ResultTemp = uint8_Source1Temp + uint8_Source2Temp + uint8_Carry;
		
		if ((uint8_ResultTemp & 0x02) != 0x00){
			boolResult = 1;
		}
		else {
			boolResult = 0;
		};
		
		uint8_Carry = uint8_ResultTemp;
		 
		
	};
	
	return boolResult;
	
};

// Generic Check Parity Function to return the parity of a register value
bool func_Check_Parity()
{
	bool boolResult = 0;
	
	int intBitPosition = 0;
	int intBitCount = 0;
	
	uint8_t uint8_InitialA = i8080.state.registers.A.get();
	
	uint8_t uint8_RegisterTemp = 0x00;
	
	for (intBitPosition = 0; intBitPosition < 8 ; intBitPosition++){
		
		uint8_RegisterTemp = 0x00;
		
		uint8_RegisterTemp = ((uint8_InitialA >> intBitPosition) & 0x01);
		
		if (uint8_RegisterTemp == 0x01){
			intBitCount = intBitCount + 1;
		}
		 
		
	};
	
	if (intBitCount % 2 == 0){
		boolResult = 1;
	}
	
	return boolResult;
};

// Generic Check Carry Function to return if there was a carry from the bit position 7 addition/subtraction/etc.
bool func_Check_Carry(uint8_t uint8_Source1, uint8_t uint8_Source2)
{
	bool boolResult = 0;
	
	uint8_t uint8_Carry = 0x00;
	
	int intBitPosition;
	uint8_t uint8_Source1Temp = 0x00;
	uint8_t uint8_Source2Temp = 0x00;
	uint8_t uint8_ResultTemp = 0x00;
	
	for (intBitPosition = 0; intBitPosition < 8 ; intBitPosition++){
		
		uint8_Source1Temp = 0x00;
		uint8_Source2Temp = 0x00;
		
		uint8_Carry = uint8_Carry >> 1;
		
		uint8_Source1Temp = ((uint8_Source1 >> intBitPosition) & 0x01);
		uint8_Source2Temp = ((uint8_Source2 >> intBitPosition) & 0x01);
		
		uint8_ResultTemp = uint8_Source1Temp + uint8_Source2Temp + uint8_Carry;
		
		if ((uint8_ResultTemp & 0x02) != 0x00){
			boolResult = 1;
		}
		else {
			boolResult = 0;
		};
		
		uint8_Carry = uint8_ResultTemp;
		 
		
	};
	
	return boolResult;
	
};

// Generic Function to run a given number of Clock Cycles
void func_ClockCycles(int intClockCycles)
{
};
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
//*
//* http://www.classicgaming.cc/classics/space-invaders/sounds
//*
//* https://computerarcheology.com/Arcade/SpaceInvaders/Hardware.html
//********************************************************

#include <stdio.h>
#include "OpCodeFunctions.h"
// #include "../i8080_struct.h"


extern i8080_CPU i8080;

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

// Generic Move Imediate 16 bit Function to pass the LXI OpCodes to
void func_LXI_Registers(i8080_Register &reg_Source1, i8080_Register &reg_Source2)
{
	reg_Source1.set(i8080.state.opCode_Array[2]);
	reg_Source2.set(i8080.state.opCode_Array[1]);
};


//!!! NEEDS TO BE FILLED OUT
// Generic Increment 16 bit Function to pass the INX 8bit OpCodes to
void func_INX_Registers(i8080_Register &reg_Source1, i8080_Register &reg_Source2) 
{
	uint8_t uint8_Source1Temp = reg_Source1.get();
	uint8_t uint8_Source2Temp = reg_Source2.get();

	uint16_t uint16_RegisterTemp = 0x0000;

	uint16_RegisterTemp = uint16_RegisterTemp | uint8_Source1Temp;
	uint16_RegisterTemp = uint16_RegisterTemp << 8;

	uint16_RegisterTemp = uint16_RegisterTemp | uint8_Source2Temp;

	uint16_RegisterTemp = uint16_RegisterTemp + 0x0001;

	reg_Source2.set(uint16_RegisterTemp);

	reg_Source1.set(uint16_RegisterTemp >> 8);

}

// Generic Increment Function to pass the INR OpCodes to
void func_INR_Registers(i8080_Register &reg_Source)
{
	uint8_t uint8_RegisterTemp = reg_Source.get();
	uint8_t uint8_ResultTemp = uint8_RegisterTemp + 0x01;
	
	reg_Source.set(uint8_ResultTemp);
	
	// S	Z	AC	P
	
	i8080.state.flag_S.set(func_Check_Sign(uint8_ResultTemp));
	i8080.state.flag_Z.set(func_Check_Zero(uint8_ResultTemp));
	i8080.state.flag_AC.set(func_Check_AuxCarry(uint8_RegisterTemp, 0x01));
	i8080.state.flag_P.set(func_Check_Parity(uint8_ResultTemp));
	
};

// Generic Decrement Function to pass the DCR OpCodes to
void func_DCR_Registers(i8080_Register &reg_Source)
{
	uint8_t uint8_RegisterTemp = reg_Source.get();
	uint8_t uint8_RegisterTwosCompliment = (~(reg_Source.get())) + 0x01;
	uint8_t uint8_ResultTemp = uint8_RegisterTemp - 0x01;

	reg_Source.set(uint8_ResultTemp);
	
	// S	Z	AC	P
	i8080.state.flag_S.set(func_Check_Sign(uint8_ResultTemp));
	i8080.state.flag_Z.set(func_Check_Zero(uint8_ResultTemp));
	// When checking the Auxiliary Carry Bit Source2 needs to be a 2's compliment
	i8080.state.flag_AC.set(func_Check_AuxCarry(uint8_RegisterTemp, 0xFF));
	
	i8080.state.flag_P.set(func_Check_Parity(uint8_ResultTemp));
	
};

// Generic Move Function to pass the MOV OpCodes to
void func_MOV_Registers(i8080_Register &reg_Destination, i8080_Register &reg_Source)
{
	reg_Destination.set(reg_Source.get());
};

// Generic Immediate Move Function to pass the MVI OpCodes to
void func_MVI_Registers(i8080_Register &reg_Destination, uint8_t uint8_Source)
{
	reg_Destination.set(uint8_Source);
};

// Generic Add Function to pass the ADD OpCodes to
void func_ADD_Registers(i8080_Register &reg_Source)
{
	uint8_t uint8_InitialA = i8080.state.reg_A.get();
	uint8_t uint8_ResultTemp = uint8_InitialA + reg_Source.get();
	
	i8080.state.reg_A.set(uint8_ResultTemp);
	
	// S	Z	AC	P	CY
	
	i8080.state.flag_S.set(func_Check_Sign());
	i8080.state.flag_Z.set(func_Check_Zero());
	i8080.state.flag_AC.set(func_Check_AuxCarry(uint8_InitialA, reg_Source.get()));
	i8080.state.flag_P.set(func_Check_Parity());
	i8080.state.flag_C.set(func_Check_Carry(uint8_InitialA, reg_Source.get()));
	
};

// Generic Add Plus Carry Function to pass ADC OpCodes to
void func_ADC_Registers(i8080_Register &reg_Source)
{
	uint8_t uint8_InitialA = i8080.state.reg_A.get();
	
	if (i8080.state.flag_C.get() == true){
		uint8_InitialA = uint8_InitialA + 0x01;
	}
	
	uint8_t uint8_ResultTemp = uint8_InitialA + reg_Source.get();
	
	i8080.state.reg_A.set(uint8_ResultTemp);
	
	// S	Z	AC	P	CY
	
	i8080.state.flag_S.set(func_Check_Sign());
	i8080.state.flag_Z.set(func_Check_Zero());
	i8080.state.flag_AC.set(func_Check_AuxCarry(uint8_InitialA, reg_Source.get()));
	i8080.state.flag_P.set(func_Check_Parity());
	i8080.state.flag_C.set(func_Check_Carry(uint8_InitialA, reg_Source.get()));
	
};

// Generic Sub Function to pass the SUB OpCodes to
void func_SUB_Registers(i8080_Register &reg_Source)
{
	uint8_t uint8_InitialA = i8080.state.reg_A.get();
	uint8_t uint8_RegisterTwosCompliment = (~(reg_Source.get())) + 0x01;
	uint8_t uint8_ResultTemp = uint8_InitialA - reg_Source.get();
	
	i8080.state.reg_A.set(uint8_ResultTemp);
	
	// S	Z	AC	P	CY
	i8080.state.flag_S.set(func_Check_Sign());
	i8080.state.flag_Z.set(func_Check_Zero());
	// When checking the Auxiliary Carry Bit Source2 needs to be a 2's compliment
	i8080.state.flag_AC.set(func_Check_AuxCarry(uint8_InitialA, uint8_RegisterTwosCompliment));
	
	i8080.state.flag_P.set(func_Check_Parity());
	
	// When checking the Carry Bit Source2 needs to be a 2's compliment
	// the result has to be negated also before setting/resetting the flag.
	i8080.state.flag_C.set(!func_Check_Carry(uint8_InitialA, uint8_RegisterTwosCompliment));
	
};

// Generic Sub with Borrow Function to pass the SBB OpCodes to
void func_SBB_Registers(i8080_Register &reg_Source)
{
	uint8_t uint8_InitialA = i8080.state.reg_A.get();
	uint8_t uint8_RegisterTwosCompliment = (~(reg_Source.get())) + 0x01;
	uint8_t uint8_RegisterTemp = reg_Source.get();
	
	if (i8080.state.flag_C.get() == true){
		uint8_RegisterTemp = uint8_RegisterTemp + 0x01;
	}
	
	uint8_t uint8_ResultTemp = uint8_InitialA - uint8_RegisterTemp;
	
	i8080.state.reg_A.set(uint8_ResultTemp);
	
	// S	Z	AC	P	CY
	
	i8080.state.flag_S.set(func_Check_Sign());
	i8080.state.flag_Z.set(func_Check_Zero());
	// When checking the Auxiliary Carry Bit Source2 needs to be a 2's compliment
	i8080.state.flag_AC.set(func_Check_AuxCarry(uint8_InitialA, uint8_RegisterTwosCompliment));

	i8080.state.flag_P.set(func_Check_Parity());
	
	// When checking the Carry Bit Source2 needs to be a 2's compliment
	// the result has to be negated also before setting/resetting the flag.
	i8080.state.flag_C.set(!func_Check_Carry(uint8_InitialA, uint8_RegisterTwosCompliment));
	
};

// Generic And Function to pass the ANA OpCodes to
void func_ANA_Registers(i8080_Register &reg_Source)
{
	uint8_t uint8_ResultTemp = i8080.state.reg_A.get() & reg_Source.get();
	
	i8080.state.reg_A.set(uint8_ResultTemp);
	
	// According to the i8080 Programming Manual the ANA instructions do not affect the AC Flag (pg 19)
	// This differs from the documentation on other sites.
	// S	Z	P	CY
	
	i8080.state.flag_S.set(func_Check_Sign());
	i8080.state.flag_Z.set(func_Check_Zero());
	i8080.state.flag_P.set(func_Check_Parity());
	i8080.state.flag_C.set(0);
};

// Generic Exclusive OR Function to pass XRA OpCodes to
void func_XRA_Registers(i8080_Register &reg_Source)
{
	uint8_t uint8_ResultTemp = i8080.state.reg_A.get() ^ reg_Source.get();
	
	i8080.state.reg_A.set(uint8_ResultTemp);
	
	// S	Z	AC	P	CY
	
	i8080.state.flag_S.set(func_Check_Sign());
	i8080.state.flag_Z.set(func_Check_Zero());
	i8080.state.flag_AC.set(0);
	i8080.state.flag_P.set(func_Check_Parity());
	i8080.state.flag_C.set(0);
	
	
};

// Generic Or Function to pass the ORA OpCodes to
void func_ORA_Registers(i8080_Register &reg_Source)
{
	uint8_t uint8_ResultTemp = i8080.state.reg_A.get() | reg_Source.get();
	
	i8080.state.reg_A.set(uint8_ResultTemp);
	
	// According to the i8080 Programming Manual the ORA instructions do not affect the AC Flag (pg 19)
	// This differs from the documentation on other sites.
	// S	Z	P	CY
	i8080.state.flag_S.set(func_Check_Sign());
	i8080.state.flag_Z.set(func_Check_Zero());
	i8080.state.flag_P.set(func_Check_Parity());
	i8080.state.flag_C.set(0);
	
};

// Generic Compare Function to pass the CMP OpCodes to
void func_CMP_Registers(i8080_Register &reg_Source)
{
	uint8_t uint8_InitialA = i8080.state.reg_A.get();
	uint8_t uint8_RegisterTwosCompliment = (~reg_Source.get()) + 0x01;
	uint8_t uint8_ResultTemp = uint8_InitialA - reg_Source.get();
	
	// S	Z	AC	P	CY
	i8080.state.flag_S.set(func_Check_Sign(uint8_ResultTemp));
	
	if (uint8_InitialA == reg_Source.get()){
		i8080.state.flag_Z.set(1);
	}
	else {
		i8080.state.flag_Z.set(0);
	}
	
	// When checking the Auxiliary Carry Bit Source2 needs to be a 2's compliment
	i8080.state.flag_AC.set(func_Check_AuxCarry(uint8_InitialA, uint8_RegisterTwosCompliment));
	
	i8080.state.flag_P.set(func_Check_Parity(uint8_ResultTemp));
	
	// When checking the Carry Bit Source2 needs to be a 2's compliment
	// the result has to be negated also before setting/resetting the flag.
	i8080.state.flag_C.set(!func_Check_Carry(uint8_InitialA, uint8_RegisterTwosCompliment));
	
};

// Generic Push Function to pass the PUSH OpCodes to
void func_PUSH_Registers(i8080_Register &reg_Source1, i8080_Register &reg_Source2)
{
	uint16_t uint16_TempSP = i8080.state.reg_SP.get_Large();
	
	//uint16_TempSP = uint16_TempSP - 0x01;
	
	// Function to push data to memory
	i8080.state.set_Memory(uint16_TempSP - 0x0001, reg_Source1.get());
	
	//uint16_TempSP = uint16_TempSP - 0x01;
	
	// Function to push data to memory
	i8080.state.set_Memory(uint16_TempSP - 0x0002, reg_Source2.get());
	
	i8080.state.reg_SP.set_Large(uint16_TempSP - 0x0002);
};

// Generic Return function to pass the RET OpCodes to
void func_General_RET()
{
	uint16_t uint16_InitialSP = i8080.state.reg_SP.get_Large();
	uint8_t uint8_ResultTemp1 = 0x00;
	uint8_t uint8_ResultTemp2 = 0x00;
	uint16_t uint16_ResultTemp = 0x0000;
	
	//printf("InitialSP: %4X\n", uint16_InitialSP);

	uint8_ResultTemp1 = i8080.state.get_Memory(uint16_InitialSP); 
	
	//uint16_InitialSP = uint16_InitialSP + 0x0001;

	uint8_ResultTemp2 = i8080.state.get_Memory(uint16_InitialSP + 0x0001); 
	
	//uint16_InitialSP = uint16_InitialSP + 0x0001;
	
	uint16_ResultTemp = uint16_ResultTemp | uint8_ResultTemp2;
	
	uint16_ResultTemp = uint16_ResultTemp << 0x08;
	
	uint16_ResultTemp = uint16_ResultTemp | uint8_ResultTemp1;

	//printf("ReturnPC: %4X\n", uint16_ResultTemp);
	
	i8080.state.reg_PC.set_Large(uint16_ResultTemp);
	
	i8080.state.reg_SP.set_Large(uint16_InitialSP + 0x0002);
};

// Generic Call function to pass the CALL OpCodes to
void func_General_CALL()
{
	uint16_t uint16_InitialPC = i8080.state.reg_PC.get_Large();
	uint16_t uint16_InitialSP = i8080.state.reg_SP.get_Large();

    // Break the Program Counter into two bytes so that it can be stored in memory.
    uint8_t uint8_PCAddrLow = 0x00;
    uint8_t uint8_PCAddrHigh = 0x00;
	//printf("PC: %4X\n", uint16_InitialPC);
	//printf("SP: %4X\n", uint16_InitialSP);
    uint8_PCAddrLow = uint8_PCAddrLow | uint16_InitialPC;
    uint8_PCAddrHigh = uint8_PCAddrHigh | (uint16_InitialPC >> 8);
	//printf("PCLow: %4X\n", uint8_PCAddrLow);
	//printf("PCHigh: %4X\n", uint8_PCAddrHigh);

    // Combine the two bytes following the OpCode to form the address for where the Call
    // will take the program.
    uint16_t uint16_AddressTemp = 0x0000;
    uint16_t uint16_InitialAddrLow = i8080.state.opCode_Array[1];
    uint16_t uint16_InitialAddrHigh = i8080.state.opCode_Array[2];

    uint16_AddressTemp = uint16_AddressTemp | uint16_InitialAddrHigh;
    uint16_AddressTemp = uint16_AddressTemp << 8;
    uint16_AddressTemp = uint16_AddressTemp | uint16_InitialAddrLow;

	// Push the Program Counter to memory where the Stack Pointer - 1 and Stack Pointer - 2 point
	i8080.state.set_Memory((uint16_InitialSP - 0x01), uint8_PCAddrHigh);
    i8080.state.set_Memory((uint16_InitialSP - 0x02), uint8_PCAddrLow);
	
	// The Stack Pointer is updated
	i8080.state.reg_SP.set_Large(uint16_InitialSP - 0x02);
	//printf("CALL_NewPC: %4X\n", uint16_AddressTemp);
	i8080.state.reg_PC.set_Large(uint16_AddressTemp);

};

// Generic Check Sign Function to return the Sign of the Accumulator value
// Reference Material: https://www.cprogramming.com/tutorial/bitwise_operators.html
bool func_Check_Sign()
{
	return (0x80 == (i8080.state.reg_A.get() & 0x80));
};

// Generic Check Sign Function to return the Sign of a register value
// Reference Material: https://www.cprogramming.com/tutorial/bitwise_operators.html
bool func_Check_Sign(uint8_t uint8_Register)
{
	return (0x80 == (uint8_Register & 0x80));
};

// Generic Check Sign Function to return the Sign of Accumulator value
bool func_Check_Zero()
{
	bool boolResult = 0;
	
	if (i8080.state.reg_A.get() == 0x00){
		boolResult = 1;
	}
	
	return boolResult;
};

// Generic Check Sign Function to return the Sign of a register value
bool func_Check_Zero(uint8_t uint8_Register)
{
	bool boolResult = 0;
	
	if (uint8_Register == 0x00){
		boolResult = 1;
	}
	
	return boolResult;
};

// Generic Check Auxiliary Carry Function to return if there was a carry from the bit position 3 addition/subtraction/etc.
bool func_Check_AuxCarry(uint8_t uint8_Source1, uint8_t uint8_Source2)
{
	bool boolResult = false;
	
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
			boolResult = true;
		}
		else {
			boolResult = 0;
		};
		
		uint8_Carry = uint8_ResultTemp;
		 
		
	};
	
	return boolResult;
	
};

// Generic Check Parity Function to return the parity of the Accumulator value
bool func_Check_Parity()
{
	bool boolResult = false;
	
	int intBitPosition = 0;
	int intBitCount = 0;
	
	uint8_t uint8_InitialA = i8080.state.reg_A.get();
	
	uint8_t uint8_RegisterTemp = 0x00;
	
	for (intBitPosition = 0; intBitPosition < 8 ; intBitPosition++){
		
		uint8_RegisterTemp = 0x00;
		
		uint8_RegisterTemp = ((uint8_InitialA >> intBitPosition) & 0x01);
		
		if (uint8_RegisterTemp == 0x01){
			intBitCount = intBitCount + 1;
		}
		 	
	}
	
	if (intBitCount % 2 == 0){
		boolResult = true;
	}
	
	return boolResult;
};

// Generic Check Parity Function to return the parity of a register value
bool func_Check_Parity(uint8_t uint8_Register)
{
	bool boolResult = false;
	
	int intBitPosition = 0;
	int intBitCount = 0;
	
	uint8_t uint8_RegisterTemp = 0x00;
	
	for (intBitPosition = 0; intBitPosition < 8 ; intBitPosition++){
		
		uint8_RegisterTemp = 0x00;
		
		uint8_RegisterTemp = ((uint8_Register >> intBitPosition) & 0x01);
		
		if (uint8_RegisterTemp == 0x01){
			intBitCount = intBitCount + 1;
		}
		 
		
	}

	if (intBitCount % 2 == 0){
		boolResult = true;
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




// Generic Check Carry Function for 16 bit values to return if there was a carry from the bit position 7 addition/subtraction/etc.
bool func_Check_Carry(uint16_t uint16_Source1, uint16_t uint16_Source2)
{
	bool boolResult = 0;

	uint16_t uint16_Carry = 0x0000;

	int intBitPosition;
	uint16_t uint16_Source1Temp = 0x0000;
	uint16_t uint16_Source2Temp = 0x0000;
	uint16_t uint16_ResultTemp = 0x0000;

	for (intBitPosition = 0; intBitPosition < 16; intBitPosition++) {

		uint16_Source1Temp = 0x0000;
		uint16_Source2Temp = 0x0000;

		uint16_Carry = uint16_Carry >> 1;

		uint16_Source1Temp = ((uint16_Source1 >> intBitPosition) & 0x01);
		uint16_Source2Temp = ((uint16_Source2 >> intBitPosition) & 0x01);

		uint16_ResultTemp = uint16_Source1Temp + uint16_Source2Temp + uint16_Carry;

		if ((uint16_ResultTemp & 0x02) != 0x00) {
			boolResult = 1;
		}
		else {
			boolResult = 0;
		};

		uint16_Carry = uint16_ResultTemp;


	};

	return boolResult;

};




// Generic Function to run a given number of Clock Cycles
void func_ClockCycles(int intClockCycles)
{
	i8080.state.clock_cycles += intClockCycles;
}

void func_Inc_PC(int steps) 
{
	
	uint16_t uint16_RegisterTemp = i8080.state.reg_PC.get_Large() + steps;
	//printf("Increment PC: %4X, %4X\n", steps, uint16_RegisterTemp);
	i8080.state.reg_PC.set_Large(uint16_RegisterTemp);
}


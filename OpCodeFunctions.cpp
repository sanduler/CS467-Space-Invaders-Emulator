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
#include "Intel8080.h"

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
int func_ADD_Registers(char &Destination, char &Source1, char &Source2)
{
};

// Generic Sub Function to pass the SUB OpCodes to
int func_SUB_Registers(char &Destination, char &Source1, char &Source2)
{
};

// Generic And Function to pass the ANA OpCodes to
int func_AND_Registers(char &Destination, char &Source1, char &Source2)
{
};

// Generic Or Function to pass the ORA OpCodes to
int func_OR_Registers(char &Destination, char &Source1, char &Source2)
{
};

// Generic Move Function to pass the MOV OpCodes to
int func_MOV_Registers(char &Destination, char &Source)
{
};

// Generic Check Parity Function to return the parity of a register value_comp
bool func_Check_Parity(char %Register)
{
};


int func_NOP()
{
	// 4 Clock Cycles
	// No Flags Effected
};

// Madison		
int func_LXI_B_D16(struct_8080State &state)
{
	// B <- byte 3, C <- byte 2
	// 10 clock cycles
	// No Flags Effected
};

// Ruben
int func_STAX_B(struct_8080State &state)
{
	// (BC) <- A
	// 7 clock cycles
	// No Flags Effected
};

// Michael
int func_INX_B(struct_8080State &state)
{
	// BC <- BC+1
	// 5 clock cycles
	// No Flags Effected
};

// Madison
int func_INR_B(struct_8080State &state)
{
	// B <- B+1
	// 5 clock cycles
	// S	Z	AC	P
};

// Ruben
int func_DCR_B(struct_8080State &state)
{
	// B <- B-1
	// 5 clock cycles
	// S	Z	AC	P
};

// Michael
int func_MVI_B_D8(struct_8080State &state)
{
	// B <- byte 2
	// 7 clock cycles
	// No Flags Effected
};

// Madison
int func_RLC(struct_8080State &state)
{
	// A = A << 1; bit 0 = prev bit 7; CY = prev bit 7
	// 4 clock cycles
	// Carry Flag (CY) Effected
};

// Ruben			
int func_DAD_B(struct_8080State &state)
{
	// HL = HL + BC
	// 10 clock cycles
	// Carry Flag (CY) Effected
};

// Michael
int func_LDAX_B(struct_8080State &state)
{
	// A <- (BC)
	// 7 clock cycles
	// No Flags Effected
};

// Madison
int func_DCX_B(struct_8080State &state)
{
	// BC = BC-1
	// 5 clock cycles
	// No Flags Effected
};

// Ruben
int func_INR_C(struct_8080State &state)
{
	// C <- C+1
	// 5 clock cycles
	// S	Z	AC	P
};

// Michael
int func_DCR_C(struct_8080State &state)
{
	// C <-C-1
	// 5 clock cycles
	// S	Z	AC	P
};

// Madison
int func_MVI_C_D8(struct_8080State &state)
{
	// C <- byte 2
	// 7 clock cycles
	// No Flags Effected
};

// Ruben
int func_RRC(struct_8080State &state)
{
	// A = A >> 1; bit 7 = prev bit 0; CY = prev bit 0
	// 4 clock cycles
	// Carry Flag (CY) Effected
};

// Michael			
int func_LXI_D_D16(struct_8080State &state)
{
	// D <- byte 3, E <- byte 2
	// 10 clock cycles
	// No Flags Effected
};

// Michael
int func_STAX_D(struct_8080State &state)
{
	// (DE) <- A
	// 7 clock cycles
	// No Flags Effected
};

// Madison
int func_INX_D(struct_8080State &state)
{
	// DE <- DE + 1
	// 5 clock cycles
	// No Flags Effected
};

// Ruben
int func_INR_D(struct_8080State &state)
{
	// D <- D+1
	// 5 clock cycles
	// S	Z	AC	P
};

// Michael
int func_DCR_D(struct_8080State &state)
{
	// D <- D-1
	// 5 clock cycles
	// S	Z	AC	P
};

// Madison
int func_MVI_D_D8(struct_8080State &state)
{
	// D <- byte 2
	// 7 clock cycles
	// No Flags Effected
};

// Ruben
int func_RAL(struct_8080State &state)
{
	// A = A << 1; bit 0 = prev CY; CY = prev bit 7
	// 4 clock cycles
	// Carry Flag (CY) Effected
};

// Michael			
int func_DAD_D(struct_8080State &state)
{
	// HL = HL + DE
	// 10 clock cycles
	// Carry Flag (CY) Effected
};

// Michael
int func_LDAX_D(struct_8080State &state)
{
	// A <- (DE)
	// 7 clock cycles
	// No Flags Effected
};

// Madison
int func_DCX_D(struct_8080State &state)
{
	// DE = DE-1
	// 5 clock cycles
	// No Flags Effected
};

// Ruben
int func_INR_E(struct_8080State &state)
{
	// E <-E+1
	// 5 clock cycles
	// S	Z	AC	P
};

// Michael
int func_DCR_E(struct_8080State &state)
{
	// E <- E-1
	// 5 clock cycles
	// S	Z	AC	P
};

// Madison
int func_MVI_E_D8(struct_8080State &state)
{
	// E <- byte 2
	// 7 clock cycles
	// No Flags Effected
};

// Ruben
int func_RAR(struct_8080State &state)
{
	// A = A >> 1; bit 7 = prev bit 7; CY = prev bit 0
	// 4 clock cycles
	// Carry Flag (CY) Effected
};

// Madison
int func_LXI_H_D16(struct_8080State &state)
{
	// H <- byte 3, L <- byte 2
	// 10 clock cycles
	// No Flags Effected
};

// Ruben
int func_SHLD_A16(struct_8080State &state)
{
	// (adr) <-L; (adr+1)<-H
	// 16 clock cycles
	// No Flags Effected
};

// Michael
int func_INX_H(struct_8080State &state)
{
	// HL <- HL + 1
	// 5 clock cycles
	// No Flags Effected
};

// Madison
int func_INR_H(struct_8080State &state)
{
	// H <- H+1
	// 5 clock cycles
	// S	Z	AC	P
};

// Ruben
int func_DCR_H(struct_8080State &state)
{
	// H <- H-1
	// 5 clock cycles
	// S	Z	AC	P
};

// Michael
int func_MVI_H_D8(struct_8080State &state)
{
	// L <- byte 2
	// 7 clock cycles
	// No Flags Effected
};

// Madison
int func_DAA()
{
	// special
	// 4 clock cycles
	// S	Z	AC	P	C
};

// Ruben			
int func_DAD_H(struct_8080State &state)
{
	// HL = HL + HI
	// 10 clock cycles
	// Carry Flag (CY) Effected
};

// Michael
int func_LHLD_A16(struct_8080State &state)
{
	// L <- (adr); H<-(adr+1)
	// 16 clock cycles
	// No Flags Effected
};

// Madison
int func_DCX_H(struct_8080State &state)
{
	// HL = HL-1
	// 5 clock cycles
	// No Flags Effected
};

// Ruben
int func_INR_L(struct_8080State &state)
{
	// L <- L+1
	// 5 clock cycles
	// S	Z	AC	P
};

// Michael
int func_DCR_L(struct_8080State &state)
{
	// L <- L-1
	// 5 clock cycles
	// S	Z	AC	P
};

// Madison
int func_MVI_L_D8(struct_8080State &state)
{
	// L <- byte 2
	// 7 clock cycles
	// No Flags Effected
};

// Ruben
int func_CMA(struct_8080State &state)
{
	// A <- !A
	// 4 clock cycles
	// No Flags Effected
};

// Michael
int func_LXI_SP_D16(struct_8080State &state)
{
	// SP.hi <- byte 3, SP.lo <- byte 2
	// 10 clock cycles
	// No Flags Effected
};

// Madison
int func_STA_A16(struct_8080State &state)
{
	// (adr) <- A
	// 13 clock cycles
	// No Flags Effected
};

// Ruben
int func_INX_SP(struct_8080State &state)
{
	// SP = SP + 1
	// 5 clock cycles
	// No Flags Effected
};

// Michael
int func_INR_M(struct_8080State &state)
{
	// (HL) <- (HL)+1
	// 10 clock cycles
	// S	Z	AC	P
};

// Madison
int func_DCR_M(struct_8080State &state)
{
	// (HL) <- (HL)-1
	// 10 clock cycles
	// S	Z	AC	P
};

// Ruben
int func_MVI_M_D8(struct_8080State &state)
{
	// (HL) <- byte 2
	// 10 clock cycles
	// No Flags Effected
};

// Michael
int func_STC(struct_8080State &state)
{
	// CY = 1
	// 4 clock cycles
	// Carry Flag (CY) Effected
};

// Madison		
int func_DAD_SP(struct_8080State &state)
{
	// HL = HL + SP
	// 10 clock cycles
	// Carry Flag (CY) Effected
};

// Ruben
int func_LDA_A16(struct_8080State &state)
{
	// A <- (adr)
	// 13 clock cycles
	// No Flags Effected
};

// Michael
int func_DCX_SP(struct_8080State &state)
{
	// SP = SP-1
	// 5 clock cycles
	// No Flags Effected
};

// Madison
int func_INR_A(struct_8080State &state)
{
	// A <- A+1
	// 5 clock cycles
	// S	Z	AC	P
};

// Ruben
int func_DCR_A(struct_8080State &state)
{
	// A <- A-1
	// 5 clock cycles
	// S	Z	AC	P
};

// Michael
int func_MVI_A_D8(struct_8080State &state)
{
	// A <- byte 2
	// 7 clock cycles
	// No Flags Effected
};

// Madison
int func_CMC(struct_8080State &state)
{
	// CY=!CY
	// 4 clock cycles
	// Carry Flag (CY) Effected
};

// Ruben
int func_MOV_B_B(struct_8080State &state)
{
	// B <- B
	// 5 clock cycles
	// No Flags Effected
};

// Michael
int func_MOV_B_C(struct_8080State &state)
{
	// B <- C
	// 5 clock cycles
	// No Flags Effected
};

// Madison
int func_MOV_B_D(struct_8080State &state)
{
	// B <- D
	// 5 clock cycles
	// No Flags Effected
};

// Ruben
int func_MOV_B_E(struct_8080State &state)
{
	// B <- E
	// 5 clock cycles
	// No Flags Effected
};

// Michael
int func_MOV_B_H(struct_8080State &state)
{
	// B <- H
	// 5 clock cycles
	// No Flags Effected
};

// Madison
int func_MOV_B_L(struct_8080State &state)
{
	// B <- L
	// 5 clock cycles
	// No Flags Effected
};

// Ruben
int func_MOV_B_M(struct_8080State &state)
{
	// B <- (HL)
	// 7 clock cycles
	// No Flags Effected
};

// Michael
int func_MOV_B_A(struct_8080State &state)
{
	// B <- A
	// 5 clock cycles
	// No Flags Effected
};

// Madison
int func_MOV_C_B(struct_8080State &state)
{
	// C <- B
	// 5 clock cycles
	// No Flags Effected
};

// Ruben
int func_MOV_C_C(struct_8080State &state)
{
	// C <- C
	// 5 clock cycles
	// No Flags Effected
};

// Michael
int func_MOV_C_D(struct_8080State &state)
{
	// C <- D
	// 5 clock cycles
	// No Flags Effected
};

// Madison
int func_MOV_C_E(struct_8080State &state)
{
	// C <- E
	// 5 clock cycles
	// No Flags Effected
};

// Ruben
int func_MOV_C_H(struct_8080State &state)
{
	// C <- H
	// 5 clock cycles
	// No Flags Effected
};

// Michael
int func_MOV_C_L(struct_8080State &state)
{
	// C <- L
	// 5 clock cycles
	// No Flags Effected
};

// Madison
int func_MOV_C_M(struct_8080State &state)
{
	// C <- (HL)
	// 7 clock cycles
	// No Flags Effected
};

// Ruben
int func_MOV_C_A(struct_8080State &state)
{
	// C <- A
	// 5 clock cycles
	// No Flags Effected
};

// Michael
int func_MOV_D_B(struct_8080State &state)
{
	// D <- B
	// 5 clock cycles
	// No Flags Effected
};

// Madison
int func_MOV_D_C(struct_8080State &state)
{
	// D <- C
	// 5 clock cycles
	// No Flags Effected
};

// Ruben
int func_MOV_D_D(struct_8080State &state)
{
	// D <- D
	// 5 clock cycles
	// No Flags Effected
};

// Michael
int func_MOV_D_E(struct_8080State &state)
{
	// D <- E
	// 5 clock cycles
	// No Flags Effected
};

// Madison
int func_MOV_D_H(struct_8080State &state)
{
	// D <- H
	// 5 clock cycles
	// No Flags Effected
};

// Ruben
int func_MOV_D_L(struct_8080State &state)
{
	// D <- L
	// 5 clock cycles
	// No Flags Effected
};

// Michael
int func_MOV_D_M(struct_8080State &state)
{
	// D <- (HL)
	// 7 clock cycles
	// No Flags Effected
};

// Madison
int func_MOV_D_A(struct_8080State &state)
{
	// D <- A
	// 5 clock cycles
	// No Flags Effected
};

// Ruben
int func_MOV_E_B(struct_8080State &state)
{
	// E <- B
	// 5 clock cycles
	// No Flags Effected
};

// Michael
int func_MOV_E_C(struct_8080State &state)
{
	// E <- C
	// 5 clock cycles
	// No Flags Effected
};

// Madison
int func_MOV_E_D(struct_8080State &state)
{
	// E <- D
	// 5 clock cycles
	// No Flags Effected
};

// Ruben
int func_MOV_E_E(struct_8080State &state)
{
	// E <- E
	// 5 clock cycles
	// No Flags Effected
};

// Michael
int func_MOV_E_H(struct_8080State &state)
{
	// E <- H
	// 5 clock cycles
	// No Flags Effected
};

// Madison
int func_MOV_E_L(struct_8080State &state)
{
	// E <- L
	// 5 clock cycles
	// No Flags Effected
};

// Ruben
int func_MOV_E_M(struct_8080State &state)
{
	// E <- (HL)
	// 7 clock cycles
	// No Flags Effected
};

// Michael
int func_MOV_E_A(struct_8080State &state)
{
	// E <- A
	// 5 clock cycles
	// No Flags Effected
};

// Madison
int func_MOV_H_B(struct_8080State &state)
{
	// H <- B
	// 5 clock cycles
	// No Flags Effected
};

// Ruben
int func_MOV_H_C(struct_8080State &state)
{
	// H <- C
	// 5 clock cycles
	// No Flags Effected
};

// Michael
int func_MOV_H_D(struct_8080State &state)
{
	// H <- D
	// 5 clock cycles
	// No Flags Effected
};

// Madison
int func_MOV_H_E(struct_8080State &state)
{
	// H <- E
	// 5 clock cycles
	// No Flags Effected
};

// Ruben
int func_MOV_H_H(struct_8080State &state)
{
	// H <- H
	// 5 clock cycles
	// No Flags Effected
};

// Michael
int func_MOV_H_L(struct_8080State &state)
{
	// H <- L
	// 5 clock cycles
	// No Flags Effected
};

// Madison
int func_MOV_H_M(struct_8080State &state)
{
	// H <- (HL)
	// 7 clock cycles
	// No Flags Effected
};

// Ruben
int func_MOV_H_A(struct_8080State &state)
{
	// H <- A
	// 5 clock cycles
	// No Flags Effected
};

// Michael
int func_MOV_L_B(struct_8080State &state)
{
	// L <- B
	// 5 clock cycles
	// No Flags Effected
};

// Madison
int func_MOV_L_C(struct_8080State &state)
{
	// L <- C
	// 5 clock cycles
	// No Flags Effected
};

// Ruben
int func_MOV_L_D(struct_8080State &state)
{
	// L <- D
	// 5 clock cycles
	// No Flags Effected
};

// Michael
int func_MOV_L_E(struct_8080State &state)
{
	// L <- E
	// 5 clock cycles
	// No Flags Effected
};

// Madison
int func_MOV_L_H(struct_8080State &state)
{
	// L <- H
	// 5 clock cycles
	// No Flags Effected
};

// Ruben
int func_MOV_L_L(struct_8080State &state)
{
	// L <- L
	// 5 clock cycles
	// No Flags Effected
};

// Michael
int func_MOV_L_M(struct_8080State &state)
{
	// L <- (HL)
	// 7 clock cycles
	// No Flags Effected
};

// Madison
int func_MOV_L_A(struct_8080State &state)
{
	// L <- A
	// 5 clock cycles
	// No Flags Effected
};

// Ruben
int func_MOV_M_B(struct_8080State &state)
{
	// (HL) <- B
	// 7 clock cycles
	// No Flags Effected
};

// Michael
int func_MOV_M_C(struct_8080State &state)
{
	// (HL) <- C
	// 7 clock cycles
	// No Flags Effected
};

// Madison
int func_MOV_M_D(struct_8080State &state)
{
	// (HL) <- D
	// 7 clock cycles
	// No Flags Effected
};

// Ruben
int func_MOV_M_E(struct_8080State &state)
{
	// (HL) <- E
	// 7 clock cycles
	// No Flags Effected
};

// Michael
int func_MOV_M_H(struct_8080State &state)
{
	// (HL) <- H
	// 7 clock cycles
	// No Flags Effected
};

// Madison
int func_MOV_M_L(struct_8080State &state)
{
	// (HL) <- L
	// 7 clock cycles
	// No Flags Effected
};

// Ruben
int func_HLT()
{
	// special
	// 7 clock cycles
	// No Flags Effected
};

// Michael
int func_MOV_M_A(struct_8080State &state)
{
	// (HL) <- C
	// 7 clock cycles
	// No Flags Effected
};

// Madison
int func_MOV_A_B(struct_8080State &state)
{
	// A <- B
	// 5 clock cycles
	// No Flags Effected
};

// Ruben
int func_MOV_A_C(struct_8080State &state)
{
	// A <- C
	// 5 clock cycles
	// No Flags Effected
};

// Michael
int func_MOV_A_D(struct_8080State &state)
{
	// A <- D
	// 5 clock cycles
	// No Flags Effected
};

// Madison
int func_MOV_A_E(struct_8080State &state)
{
	// A <- E
	// 5 clock cycles
	// No Flags Effected
};

// Ruben
int func_MOV_A_H(struct_8080State &state)
{
	// A <- H
	// 5 clock cycles
	// No Flags Effected
};

// Michael
int func_MOV_A_L(struct_8080State &state)
{
	// A <- L
	// 5 clock cycles
	// No Flags Effected
};

// Madison
int func_MOV_A_M(struct_8080State &state)
{
	// A <- (HL)
	// 7 clock cycles
	// No Flags Effected
};

// Ruben
int func_MOV_A_A(struct_8080State &state)
{
	// A <- A
	// 5 clock cycles
	// No Flags Effected
};

// Michael
int func_ADD_B(struct_8080State &state)
{
	// A <- A + B
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Madison
int func_ADD_C(struct_8080State &state)
{
	// A <- A + C
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Ruben
int func_ADD_D(struct_8080State &state)
{
	// A <- A + D
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Michael
int func_ADD_E(struct_8080State &state)
{
	// A <- A + E
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Madison
int func_ADD_H(struct_8080State &state)
{
	// A <- A + H
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Ruben
int func_ADD_L(struct_8080State &state)
{
	// A <- A + L
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Michael
int func_ADD_M(struct_8080State &state)
{
	// A <- A + (HL)
	// 7 clock cycles
	// S	Z	AC	P	CY
};

// Madison
int func_ADD_A(struct_8080State &state)
{
	// A <- A + A
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Ruben
int func_ADC_B(struct_8080State &state)
{
	// A <- A + B + CY
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Michael
int func_ADC_C(struct_8080State &state)
{
	// A <- A + C + CY
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Madison
int func_ADC_D(struct_8080State &state)
{
	// A <- A + D + CY
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Ruben
int func_ADC_E(struct_8080State &state)
{
	// A <- A + E + CY
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Michael
int func_ADC_H(struct_8080State &state)
{
	// A <- A + H + CY
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Madison
int func_ADC_L(struct_8080State &state)
{
	// A <- A + L + CY
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Ruben
int func_ADC_M(struct_8080State &state)
{
	// A <- A + (HL) + CY
	// 7 clock cycles
	// S	Z	AC	P	CY
};

// Michael
int func_ADC_A(struct_8080State &state)
{
	// A <- A + A + CY
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Madison
int func_SUB_B(struct_8080State &state)
{
	// A <- A - B
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Ruben
int func_SUB_C(struct_8080State &state)
{
	// A <- A - C
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Michael
int func_SUB_D(struct_8080State &state)
{
	// A <- A + D
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Madison
int func_SUB_E(struct_8080State &state)
{
	// A <- A - E
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Ruben
int func_SUB_H(struct_8080State &state)
{
	// A <- A - H
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Michael
int func_SUB_L(struct_8080State &state)
{
	// A <- A - L
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Madison
int func_SUB_M(struct_8080State &state)
{
	// A <- A - (HL)
	// 7 clock cycles
	// S	Z	AC	P	CY
};

// Ruben
int func_SUB_A(struct_8080State &state)
{
	// A <- A - A
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Michael
int func_SBB_B(struct_8080State &state)
{
	// A <- A - B - CY
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Madison
int func_SBB_C(struct_8080State &state)
{
	// A <- A - C - CY
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Ruben
int func_SBB_D(struct_8080State &state)
{
	// A <- A - D - CY
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Michael
int func_SBB_E(struct_8080State &state)
{
	// A <- A - E - CY
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Madison
int func_SBB_H(struct_8080State &state)
{
	// A <- A - H - CY
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Ruben
int func_SBB_L(struct_8080State &state)
{
	// A <- A - L - CY
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Michael
int func_SBB_M(struct_8080State &state)
{
	// A <- A - (HL) - CY
	// 7 clock cycles
	// S	Z	AC	P	CY
};

// Madison
int func_SBB_A(struct_8080State &state)
{
	// A <- A - A - CY
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Ruben
int func_ANA_B(struct_8080State &state)
{
	// A <- A & B
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Michael
int func_ANA_C(struct_8080State &state)
{
	// A <- A & C
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Madison
int func_ANA_D(struct_8080State &state)
{
	// A <- A & D
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Ruben
int func_ANA_E(struct_8080State &state)
{
	// A <- A & E
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Michael
int func_ANA_H(struct_8080State &state)
{
	// A <- A & H
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Madison
int func_ANA_L(struct_8080State &state)
{
	// A <- A & L
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Ruben
int func_ANA_M(struct_8080State &state)
{
	// A <- A & (HL)
	// 7 clock cycles
	// S	Z	AC	P	CY
};

// Michael
int func_ANA_A(struct_8080State &state)
{
	// A <- A & A
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Madison
int func_XRA_B(struct_8080State &state)
{
	// A <- A ^ B
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Ruben
int func_XRA_C(struct_8080State &state)
{
	// A <- A ^ C
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Michael
int func_XRA_D(struct_8080State &state)
{
	// A <- A ^ D
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Madison
int func_XRA_E(struct_8080State &state)
{
	// A <- A ^ E
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Ruben
int func_XRA_H(struct_8080State &state)
{
	// A <- A ^ H
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Michael
int func_XRA_L(struct_8080State &state)
{
	// A <- A ^ L
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Madison
int func_XRA_M(struct_8080State &state)
{
	// A <- A ^ (HL)
	// 7 clock cycles
	// S	Z	AC	P	CY
};

// Ruben
int func_XRA_A(struct_8080State &state)
{
	// A <- A ^ A
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Michael
int func_ORA_B(struct_8080State &state)
{
	// A <- A | B
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Madison
int func_ORA_C(struct_8080State &state)
{
	// A <- A | C
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Ruben
int func_ORA_D(struct_8080State &state)
{
	// A <- A | D
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Michael
int func_ORA_E(struct_8080State &state)
{
	// A <- A | E
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Madison
int func_ORA_H(struct_8080State &state)
{
	// A <- A | H
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Ruben
int func_ORA_L(struct_8080State &state)
{
	// A <- A | L
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Michael
int func_ORA_M(struct_8080State &state)
{
	// A <- A | (HL)
	// 7 clock cycles
	// S	Z	AC	P	CY
};

// Madison
int func_ORA_A(struct_8080State &state)
{
	// A <- A | A
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Ruben
int func_CMP_B(struct_8080State &state)
{
	// A - B
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Michael
int func_CMP_C(struct_8080State &state)
{
	// A - C
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Madison
int func_CMP_D(struct_8080State &state)
{
	// A - D
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Ruben
int func_CMP_E(struct_8080State &state)
{
	// A - E
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Michael
int func_CMP_H(struct_8080State &state)
{
	// A - H
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Madison
int func_CMP_L(struct_8080State &state)
{
	// A - L
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Ruben
int func_CMP_M(struct_8080State &state)
{
	// A - (HL)
	// 7 clock cycles
	// S	Z	AC	P	CY
};

// Michael
int func_CMP_A(struct_8080State &state)
{
	// A - A
	// 4 clock cycles
	// S	Z	AC	P	CY
};

// Madison
int func_RNZ(struct_8080State &state)
{
	// if NZ, RET
	// 11 if taken/ 5 if not taken clock cycles
	// No Flags Effected
};

// Ruben
int func_POP_B(struct_8080State &state)
{
	// C <- (sp); B <- (sp+1); sp <- sp+2
	// 10 clock cycles
	// No Flags Effected
};

// Michael
int func_JNZ_A16(struct_8080State &state)
{
	// if NZ, PC <- adr
	// 10 clock cycles
	// No Flags Effected
};

// Madison
int func_JMP_A16(struct_8080State &state)
{
	// PC <= adr
	// 10 clock cycles
	// No Flags Effected
};

// Ruben
int func_CNZ_A16(struct_8080State &state)
{
	// if NZ, CALL adr
	// 17 if taken / 11 if not taken clock cycles
	// No Flags Effected
};

// Michael
int func_PUSH_B(struct_8080State &state)
{
	// (sp-2)<-C; (sp-1)<-B; sp <- sp - 2
	// 11 clock cycles
	// No Flags Effected
};

// Madison
int func_ADI_D8(struct_8080State &state)
{
	// A <- A + byte
	// 7 clock cycles
	// S	Z	AC	P	CY
};

// Ruben
int func_RST_0(struct_8080State &state)
{
	// CALL $0
	// 11 clock cycles
	// No Flags Effected
};

// Michael
int func_RZ(struct_8080State &state)
{
	// if Z, RET
	// 11 clock cycles
	// No Flags Effected
};

// Madison
int func_RET(struct_8080State &state)
{
	// PC.lo <- (sp); PC.hi<-(sp+1); SP <- SP+2
	// 10 clock cycles
	// No Flags Effected
};

// Ruben
int func_JZ_A16(struct_8080State &state)
{
	// if Z, PC <- adr
	// 10 clock cycles
	// No Flags Effected
};

// Michael		
int func_CZ_A16(struct_8080State &state)
{
	// if Z, CALL adr
	// 17 if taken / 11 if not taken clock cycles
	// No Flags Effected
};

// Madison
int func_CALL_A16(struct_8080State &state)
{
	// (SP-1)<-PC.hi;(SP-2)<-PC.lo;SP<-SP+2;PC=adr
	// 17 clock cycles
	// No Flags Effected
};

// Ruben
int func_ACI_D8(struct_8080State &state)
{
	// A <- A + data + CY
	// 7 clock cycles
	// S	Z	AC	P	CY
};

// Michael
int func_RST_1(struct_8080State &state)
{
	// CALL $8
	// 11 clock cycles
	// No Flags Effected
};

// Madison
int func_RNC(struct_8080State &state)
{
	// if NCY, RET
	// 11 if taken / 5 if not taken clock cycles
	// No Flags Effected
};

// Ruben
int func_POP_D(struct_8080State &state)
{
	// E <- (sp); D <- (sp+1); sp <- sp+2
	// 10 clock cycles
	// No Flags Effected
};

// Michael
int func_JNC_A16(struct_8080State &state)
{
	// if NCY, PC<-adr
	// 10 clock cycles
	// No Flags Effected
};

// Madison
int func_OUT_D8(struct_8080State &state)
{
	// special
	// 10 clock cycles
	// No Flags Effected
};

// Ruben
int func_CNC_A16(struct_8080State &state)
{
	// if NCY, CALL adr
	// 17 if taken / 11 if not taken clock cycles
	// No Flags Effected
};

// Michael
int func_PUSH_D(struct_8080State &state)
{
	// (sp-2)<-E; (sp-1)<-D; sp <- sp - 2
	// 11 clock cycles
	// No Flags Effected
};

// Madison
int func_SUI_D8(struct_8080State &state)
{
	// A <- A - data
	// 7 clock cycles
	// S	Z	AC	P	CY
};

// Ruben
int func_RST_2(struct_8080State &state)
{
	// CALL $10
	// 11 clock cycles
	// No Flags Effected
};

// Michael
int func_RC(struct_8080State &state)
{
	// if CY, RET
	// 11 if taken / 5 if not taken clock cycles
	// No Flags Effected
};

// Madison		
int func_JC_A16(struct_8080State &state)
{
	// if CY, PC<-adr
	// 10 clock cycles
	// No Flags Effected
};

// Ruben
int func_IN_D8()
{
	// special
	// 10 clock cycles
	// No Flags Effected
};

// Michael
int func_CC_A16(struct_8080State &state)
{
	// if CY, CALL adr
	// 17 if taken / 11 if not taken clock cycles
	// No Flags Effected
};

// Madison			
int func_SBI_D8(struct_8080State &state)
{
	// A <- A - data - CY
	// 7 clock cycles
	// S	Z	AC	P	CY
};

// Ruben
int func_RST_3(struct_8080State &state)
{
	// CALL $18
	// 11 clock cycles
	// No Flags Effected
};

// Michael
int func_RPO(struct_8080State &state)
{
	// if PO, RET
	// 11 if taken / 5 if not taken clock cycles
	// No Flags Effected
};

// Madison
int func_POP_H(struct_8080State &state)
{
	// L <- (sp); H <- (sp+1); sp <- sp+2
	// 10 clock cycles
	// No Flags Effected
};

// Ruben
int func_JPO_A16(struct_8080State &state)
{
	// if PO, PC <- adr
	// 10 clock cycles
	// No Flags Effected
};

// Michael
int func_XTHL(struct_8080State &state)
{
	// L <-> (SP); H <-> (SP+1)
	// 18 clock cycles
	// No Flags Effected
};

// Madison
int func_CPO_A16(struct_8080State &state)
{
	// if PO, CALL adr
	// 17 if taken / 11 if not taken clock cycles
	// No Flags Effected
};

// Ruben
int func_PUSH_H(struct_8080State &state)
{
	// (sp-2)<-L; (sp-1)<-H; sp <- sp - 2
	// 11 clock cycles
	// No Flags Effected
};

// Michael
int func_ANI_D8(struct_8080State &state)
{
	// A <- A & data
	// 7 clock cycles
	// S	Z	AC	P	CY
};

// Madison
int func_RST_4(struct_8080State &state)
{
	// CALL $20
	// 11 clock cycles
	// No Flags Effected
};

// Ruben
int func_RPE(struct_8080State &state)
{
	// if PE, RET
	// 11 if taken / 5 if not taken clock cycles
	// No Flags Effected
};

// Michael
int func_PCHL(struct_8080State &state)
{
	// PC.hi <- H; PC.lo <- L
	// 5 clock cycles
	// No Flags Effected
};

// Madison
int func_JPE_A16(struct_8080State &state)
{
	// if PE, PC <- adr
	// 10 clock cycles
	// No Flags Effected
};

// Ruben
int func_XCHG(struct_8080State &state)
{
	// H <-> D; L <-> E
	// 5 clock cycles
	// No Flags Effected
};

// Michael
int func_CPE_A16(struct_8080State &state)
{
	// if PE, CALL adr
	// 17 if taken / 11 if not taken clock cycles
	// No Flags Effected
};

// Madison		
int func_XRI_D8(struct_8080State &state)
{
	// A <- A ^ data
	// 7 clock cycles
	// S	Z	AC	P	CY
};

// Ruben
int func_RST_5(struct_8080State &state)
{
	// CALL $28
	// 11 clock cycles
	// No Flags Effected
};

// Michael
int func_RP(struct_8080State &state)
{
	// if P, RET
	// 11 if taken / 5 if not taken clock cycles
	// No Flags Effected
};

// Madison
int func_POP_PSW(struct_8080State &state)
{
	// flags <- (sp); A <- (sp+1); sp <- sp+2
	// 10 clock cycles
	// S	Z	AC	P	CY
};

// Ruben
int func_JP_A16(struct_8080State &state)
{
	// if P=1 PC <- adr
	// 10 clock cycles
	// No Flags Effected
};

// Michael
int func_DI()
{
	// special
	// 4 clock cycles
	// No Flags Effected
};

// Madison
int func_CP_A16(struct_8080State &state)
{
	// if P, PC <- adr
	// 17 if taken / 11 if not taken clock cycles
	// No Flags Effected
};

// Ruben
int func_PUSH_PSW(struct_8080State &state)
{
	// (sp-2)<-flags; (sp-1)<-A; sp <- sp - 2
	// 11 clock cycles
	// No Flags Effected
};

// Michael
int func_ORI_D8(struct_8080State &state)
{
	// A <- A | data
	// 7 clock cycles
	// S	Z	AC	P	CY
};

// Madison
int func_RST_6(struct_8080State &state)
{
	// CALL $30
	// 11 clock cycles
	// No Flags Effected
};

// Ruben
int func_RM(struct_8080State &state)
{
	// if M, RET
	// 11 if taken / 5 if not taken clock cycles
	// No Flags Effected
};

// Michael
int func_SPHL(struct_8080State &state)
{
	// SP=HL
	// 5 clock cycles
	// No Flags Effected
};

// Madison
int func_JM_A16(struct_8080State &state)
{
	// if M, PC <- adr
	// 10 clock cycles
	// No Flags Effected
};

// Ruben
int func_EI()
{
	// special
	// 4 clock cycles
	// No Flags Effected
};

// Michael
int func_CM_A16(struct_8080State &state)
{
	// if M, CALL adr
	// 17 if taken / 11 if not taken clock cycles
	// No Flags Effected
};

// Madison		
int func_CPI_D8(struct_8080State &state)
{
	// A - data
	// 7 clock cycles
	// S	Z	AC	P	CY
};

// Ruben
int func_RST_7(struct_8080State &state)
{
	// CALL $38
	// 11 clock cycles
	// No Flags Effected
};



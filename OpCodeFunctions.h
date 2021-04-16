//********************************************************
//* OpCodeFunctions.h
//* CS467
//* Madison Woy
//* Ruben Sanduleac
//* Michael Matthews
//* Description: Serves as the header file for the library of Opcode Functions for the Intel 8080 processor.
//* 			
//*	
//* Last Modified: 2/9/2020
//*
//* Sites used for Information
//* https://pastraiser.com/cpu/i8080/i8080_opcodes.html - Good Page for visual layout of Opcodes
//* 
//* http://www.emulator101.com/8080-by-opcode.html
//********************************************************

#ifndef _OpCodeFunctions_H
#define _OpCodeFunctions_H

#include "Intel8080.h"

// Generic Add Function to pass the ADD OpCodes to
int func_ADD_Registers(char &Destination, char &Source1, char &Source2);

// Generic Move Function to pass the MOV OpCodes to
int func_MOV_Registers(char &Destination, char &Source);

//Opcode	Instruction	size	flags	function
int func_NOP();

// Madison		
int func_LXI_B_D16(struct_8080State &state);

// Ruben
int func_STAX_B(struct_8080State &state);

// Michael
int func_INX_B(struct_8080State &state);

// Madison
int func_INR_B(struct_8080State &state);

// Ruben
int func_DCR_B(struct_8080State &state);

// Michael
int func_MVI_B(struct_8080State &state);

// Madison
int func_RLC(struct_8080State &state);

// Ruben			
int func_DAD_B(struct_8080State &state);

// Michael
int func_LDAX_B(struct_8080State &state);

// Madison
int func_DCX_B(struct_8080State &state);

// Ruben
int func_INR_C(struct_8080State &state);

// Michael
int func_DCR_C(struct_8080State &state);

// Madison
int func_MVI_C(struct_8080State &state);

// Ruben
int func_RRC(struct_8080State &state);

// Michael			
int func_LXI_D_D16(struct_8080State &state);

// Michael
int func_STAX_D(struct_8080State &state);

// Madison
int func_INX_D(struct_8080State &state);

// Ruben
int func_INR_D(struct_8080State &state);

// Michael
int func_DCR_D(struct_8080State &state);

// Madison
int func_MVI_D(struct_8080State &state);

// Ruben
int func_RAL(struct_8080State &state);

// Michael			
int func_DAD_D(struct_8080State &state);

// Michael
int func_LDAX_D(struct_8080State &state);

// Madison
int func_DCX_D(struct_8080State &state);

// Ruben
int func_INR_E(struct_8080State &state);

// Michael
int func_DCR_E(struct_8080State &state);

// Madison
int func_MVI_E(struct_8080State &state);

// Ruben
int func_RAR(struct_8080State &state);

// Michael
call func_NOP(); according to pastriser.com

// Madison
int func_LXI_H_D16(struct_8080State &state);

// Ruben
int func_SHLD_A16(struct_8080State &state);

// Michael
int func_INX_H(struct_8080State &state);

// Madison
int func_INR_H(struct_8080State &state);

// Ruben
int func_DCR_H(struct_8080State &state);

// Michael
int func_MVI_H_D8(struct_8080State &state);

// Madison
int func_DAA();

// Ruben			
int func_DAD_H(struct_8080State &state);

// Michael
int func_LHLD_A16(struct_8080State &state);

// Madison
int func_DCX_H(struct_8080State &state);

// Ruben
int func_INR_L(struct_8080State &state);

// Michael
int func_DCR_L(struct_8080State &state);

// Madison
int func_MVI_L_D8(struct_8080State &state);

// Ruben
int func_CMA(struct_8080State &state);

// Michael
int func_LXI_SP_D16(struct_8080State &state);

// Madison
int func_STA_A16(struct_8080State &state);

// Ruben
int func_INX_SP(struct_8080State &state);

// Michael
int func_INR_M(struct_8080State &state);

// Madison
int func_DCR_M(struct_8080State &state);

// Ruben
int func_MVI_M_D8(struct_8080State &state);

// Michael
int func_STC(struct_8080State &state);

// Madison		
int func_DAD_SP(struct_8080State &state);

// Ruben
int func_LDA_A16(struct_8080State &state);

// Michael
int func_DCX_SP(struct_8080State &state);

// Madison
int func_INR_A(struct_8080State &state);

// Ruben
int func_DCR_A(struct_8080State &state);

// Michael
int func_MVI_A_D8(struct_8080State &state);

// Madison
int func_CMC(struct_8080State &state);

// Ruben
int func_MOV_B_B(struct_8080State &state);

// Michael
int func_MOV_B_C(struct_8080State &state);

// Madison
int func_MOV_B_D(struct_8080State &state);

// Ruben
int func_MOV_B_E(struct_8080State &state);

// Michael
int func_MOV_B_H(struct_8080State &state);

// Madison
int func_MOV_B_L(struct_8080State &state);

// Ruben
int func_MOV_B_M(struct_8080State &state);

// Michael
int func_MOV_B_A(struct_8080State &state);

// Madison
int func_MOV_C_B(struct_8080State &state);

// Ruben
int func_MOV_C_C(struct_8080State &state);

// Michael
int func_MOV_C_D(struct_8080State &state);

// Madison
int func_MOV_C_E(struct_8080State &state);

// Ruben
int func_MOV_C_H(struct_8080State &state);

// Michael
int func_MOV_C_L(struct_8080State &state);

// Madison
int func_MOV_C_M(struct_8080State &state);

// Ruben
int func_MOV_C_A(struct_8080State &state);

// Michael
int func_MOV_D_B(struct_8080State &state);

// Madison
int func_MOV_D_C(struct_8080State &state);

// Ruben
int func_MOV_D_D(struct_8080State &state);

// Michael
int func_MOV_D_E(struct_8080State &state);

// Madison
int func_MOV_D_H(struct_8080State &state);

// Ruben
int func_MOV_D_L(struct_8080State &state);

// Michael
int func_MOV_D_M(struct_8080State &state);

// Madison
int func_MOV_D_A(struct_8080State &state);

// Ruben
int func_MOV_E_B(struct_8080State &state);

// Michael
int func_MOV_E_C(struct_8080State &state);

// Madison
int func_MOV_E_D(struct_8080State &state);

// Ruben
int func_MOV_E_E(struct_8080State &state);

// Michael
int func_MOV_E_H(struct_8080State &state);

// Madison
int func_MOV_E_L(struct_8080State &state);

// Ruben
int func_MOV_E_M(struct_8080State &state);

// Michael
int func_MOV_E_A(struct_8080State &state);

// Madison
int func_MOV_H_B(struct_8080State &state);

// Ruben
int func_MOV_H_C(struct_8080State &state);

// Michael
int func_MOV_H_D(struct_8080State &state);

// Madison
int func_MOV_H_E(struct_8080State &state);

// Ruben
int func_MOV_H_H(struct_8080State &state);

// Michael
int func_MOV_H_L(struct_8080State &state);

// Madison
int func_MOV_H_M(struct_8080State &state);

// Ruben
int func_MOV_H_A(struct_8080State &state);

// Michael
int func_MOV_L_B(struct_8080State &state);

// Madison
int func_MOV_L_C(struct_8080State &state);

// Ruben
int func_MOV_L_D(struct_8080State &state);

// Michael
int func_MOV_L_E(struct_8080State &state);

// Madison
int func_MOV_L_H(struct_8080State &state);

// Ruben
int func_MOV_L_L(struct_8080State &state);

// Michael
int func_MOV_L_M(struct_8080State &state);

// Madison
int func_MOV_L_A(struct_8080State &state);

// Ruben
int func_MOV_M_B(struct_8080State &state);

// Michael
int func_MOV_M_C(struct_8080State &state);

// Madison
int func_MOV_M_D(struct_8080State &state);

// Ruben
int func_MOV_M_E(struct_8080State &state);

// Michael
int func_MOV_M_H(struct_8080State &state);

// Madison
int func_MOV_M_L(struct_8080State &state);

// Ruben
int func_HLT();

// Michael
int func_MOV_M_A(struct_8080State &state);

// Madison
int func_MOV_A_B(struct_8080State &state);

// Ruben
int func_MOV_A_C(struct_8080State &state);

// Michael
int func_MOV_A_D(struct_8080State &state);

// Madison
int func_MOV_A_E(struct_8080State &state);

// Ruben
int func_MOV_A_H(struct_8080State &state);

// Michael
int func_MOV_A_L(struct_8080State &state);

// Madison
int func_MOV_A_M(struct_8080State &state);

// Ruben
int func_MOV_A_A(struct_8080State &state);

// Michael
int func_ADD_B(struct_8080State &state);

// Madison
int func_ADD_C(struct_8080State &state);

// Ruben
int func_ADD_D(struct_8080State &state);

// Michael
int func_ADD_E(struct_8080State &state);

// Madison
int func_ADD_H(struct_8080State &state);

// Ruben
int func_ADD_L(struct_8080State &state);

// Michael
int func_ADD_M(struct_8080State &state);

// Madison
int func_ADD_A(struct_8080State &state);

// Ruben
int func_ADC_B(struct_8080State &state);

// Michael
int func_ADC_C(struct_8080State &state);

// Madison
int func_ADC_D(struct_8080State &state);

// Ruben
int func_ADC_E(struct_8080State &state);

// Michael
int func_ADC_H(struct_8080State &state);

// Madison
int func_ADC_L(struct_8080State &state);

// Ruben
int func_ADC_M(struct_8080State &state);

// Michael
int func_ADC_A(struct_8080State &state);

// Madison
int func_SUB_B(struct_8080State &state);

// Ruben
int func_SUB_C(struct_8080State &state);

// Michael
int func_SUB_D(struct_8080State &state);

// Madison
int func_SUB_E(struct_8080State &state);

// Ruben
int func_SUB_H(struct_8080State &state);

// Michael
int func_SUB_L(struct_8080State &state);

// Madison
int func_SUB_M(struct_8080State &state);

// Ruben
int func_SUB_A(struct_8080State &state);

// Michael
int func_SBB_B(struct_8080State &state);

// Madison
int func_SBB_C(struct_8080State &state);

// Ruben
int func_SBB_D(struct_8080State &state);

// Michael
int func_SBB_E(struct_8080State &state);

// Madison
int func_SBB_H(struct_8080State &state);

// Ruben
int func_SBB_L(struct_8080State &state);

// Michael
int func_SBB_M(struct_8080State &state);

// Madison
int func_SBB_A(struct_8080State &state);

// Ruben
int func_ANA_B(struct_8080State &state);

// Michael
int func_ANA_C(struct_8080State &state);

// Madison
int func_ANA_D(struct_8080State &state);

// Ruben
int func_ANA_E(struct_8080State &state);

// Michael
int func_ANA_H(struct_8080State &state);

// Madison
int func_ANA_L(struct_8080State &state);

// Ruben
int func_ANA_M(struct_8080State &state);

// Michael
int func_ANA_A(struct_8080State &state);

// Madison
int func_XRA_B(struct_8080State &state);

// Ruben
int func_XRA_C(struct_8080State &state);

// Michael
int func_XRA_D(struct_8080State &state);

// Madison
int func_XRA_E(struct_8080State &state);

// Ruben
int func_XRA_H(struct_8080State &state);

// Michael
int func_XRA_L(struct_8080State &state);

// Madison
int func_XRA_M(struct_8080State &state);

// Ruben
int func_XRA_A(struct_8080State &state);

// Michael
int func_ORA_B(struct_8080State &state);

// Madison
int func_ORA_C(struct_8080State &state);

// Ruben
int func_ORA_D(struct_8080State &state);

// Michael
int func_ORA_E(struct_8080State &state);

// Madison
int func_ORA_H(struct_8080State &state);

// Ruben
int func_ORA_L(struct_8080State &state);

// Michael
int func_ORA_M(struct_8080State &state);

// Madison
int func_ORA_A(struct_8080State &state);

// Ruben
int func_CMP_B(struct_8080State &state);

// Michael
int func_CMP_C(struct_8080State &state);

// Madison
int func_CMP_D(struct_8080State &state);

// Ruben
int func_CMP_E(struct_8080State &state);

// Michael
int func_CMP_H(struct_8080State &state);

// Madison
int func_CMP_L(struct_8080State &state);

// Ruben
int func_CMP_M(struct_8080State &state);

// Michael
int func_CMP_A(struct_8080State &state);

// Madison
int func_RNZ(struct_8080State &state);

// Ruben
int func_POP_B(struct_8080State &state);

// Michael
int func_JNZ_A16(struct_8080State &state);

// Madison
int func_JMP_A16(struct_8080State &state);

// Ruben
int func_CNZ_A16(struct_8080State &state);

// Michael
int func_PUSH_B(struct_8080State &state);

// Madison
int func_ADI_D8(struct_8080State &state);

// Ruben
int func_RST_0(struct_8080State &state);

// Michael
int func_RZ(struct_8080State &state);

// Madison
int func_RET(struct_8080State &state);

// Ruben
int func_JZ_A16(struct_8080State &state);

// Michael		
int func_CZ_A16(struct_8080State &state);

// Madison
int func_CALL_A16(struct_8080State &state);

// Ruben
int func_ACI_D8(struct_8080State &state);

// Michael
int func_RST_1(struct_8080State &state);

// Madison
int func_RNC(struct_8080State &state);

// Ruben
int func_POP_D(struct_8080State &state);

// Michael
int func_JNC_A16(struct_8080State &state);

// Madison
int func_OUT_D8(struct_8080State &state);

// Ruben
int func_CNC_A16(struct_8080State &state);

// Michael
int func_PUSH_D(struct_8080State &state);

// Madison
int func_SUI_D8(struct_8080State &state);

// Ruben
int func_RST_2(struct_8080State &state);

// Michael
int func_RC(struct_8080State &state);

// Madison		
int func_JC_A16(struct_8080State &state);

// Ruben
int func_IN_D8();

// Michael
int func_CC_A16(struct_8080State &state);

// Madison			
int func_SBI_D8(struct_8080State &state);

// Ruben
int func_RST_3(struct_8080State &state);

// Michael
int func_RPO(struct_8080State &state);

// Madison
int func_POP_H(struct_8080State &state);

// Ruben
int func_JPO_A16(struct_8080State &state);

// Michael
int func_XTHL(struct_8080State &state);

// Madison
int func_CPO_A16(struct_8080State &state);

// Ruben
int func_PUSH_H(struct_8080State &state);

// Michael
int func_ANI_D8(struct_8080State &state);

// Madison
int func_RST_4(struct_8080State &state);

// Ruben
int func_RPE(struct_8080State &state);

// Michael
int func_PCHL(struct_8080State &state);

// Madison
int func_JPE_A16(struct_8080State &state);

// Ruben
int func_XCHG(struct_8080State &state);

// Michael
int func_CPE_A16(struct_8080State &state);

// Madison		
int func_XRI_D8(struct_8080State &state);

// Ruben
int func_RST_5(struct_8080State &state);

// Michael
int func_RP(struct_8080State &state);

// Madison
int func_POP_PSW(struct_8080State &state);

// Ruben
int func_JP_A16(struct_8080State &state);

// Michael
int func_DI();

// Madison
int func_CP_A16(struct_8080State &state);

// Ruben
int func_PUSH_PSW(struct_8080State &state);

// Michael
int func_ORI_D8(struct_8080State &state);

// Madison
int func_RST_6(struct_8080State &state);

// Ruben
int func_RM(struct_8080State &state);

// Michael
int func_SPHL(struct_8080State &state);

// Madison
int func_JM_A16(struct_8080State &state);

// Ruben
int func_EI();

// Michael
int func_CM_A16(struct_8080State &state);

// Madison		
int func_CPI_D8(struct_8080State &state);

// Ruben
int func_RST_8(struct_8080State &state);

#endif


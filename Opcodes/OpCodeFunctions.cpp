////////////////////
// Description: 
// OpCode: 0x00	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_NOP() {

	// Logic for: 
	// @TODO [Madison]: fill in logic

	func_ClockCycles(4);

}

////////////////////
// Description: 
// OpCode: 0x01	|| Size: 3 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_LXI_B_D16() {

	// Logic for: B <- byte 3, C <- byte 2
	// @TODO [Ruben ]: fill in logic

	func_ClockCycles(10);

	// Inc PC to account for additional size
	func_Inc_PC(2);

}

////////////////////
// Description: 
// OpCode: 0x02	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_STAX_B() {

	// Logic for: (BC) <- A
	// @TODO [Michael]: fill in logic

	func_ClockCycles(7);

}

////////////////////
// Description: 
// OpCode: 0x03	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_INX_B() {

	// Logic for: BC <- BC+1
	// @TODO [Madison]: fill in logic

	func_ClockCycles(5);

}

////////////////////
// Description: Increments the register below
// OpCode: 0x04	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers: B and A
// Written By: Ruben 
////////////////////
void func_INR_B() {

	// Logic for: B <- B+1
	func_INR_Registers(i8080.state.registers.B);

	// Set flags: Z, S, P, AC
	func_ClockCycles(5);

}

////////////////////
// Description: Decrements the register below
// OpCode: 0x05	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_DCR_B() {

	// Logic for: B <- B-1
	func_DCR_Registers(i8080.state.registers.B);

	// Set flags: Z, S, P, AC
	func_ClockCycles(5);

}

////////////////////
// Description: Adds byte 2 to the register below
// OpCode: 0x06	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: B and A
// Written By: Madison
////////////////////
void func_MVI_B_D8() {

	// Logic for: B <- byte 2
	func_MVI_Registers(i8080.state.registers.B);

	func_ClockCycles(7);

	// Inc PC to account for additional size
	func_Inc_PC(1);

}

////////////////////
// Description: 
// OpCode: 0x07	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: CY
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_RLC() {

	// Logic for: A = A << 1; bit 0 = prev bit 7; CY = prev bit 7
	// @TODO [Ruben ]: fill in logic

	// Set flags: CY
	func_ClockCycles(4);

}

// Opcode 0x08 not implemented

////////////////////
// Description: 
// OpCode: 0x09	|| Size: 1 bit	|| Clock cycles: 10
// Modifed Flags: CY
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_DAD_B() {

	// Logic for: HL = HL + BC
	// @TODO [Madison]: fill in logic

	// Set flags: CY
	func_ClockCycles(10);

}

////////////////////
// Description: 
// OpCode: 0x0a	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_LDAX_B() {

	// Logic for: A <- (BC)
	// @TODO [Ruben ]: fill in logic

	func_ClockCycles(7);

}

////////////////////
// Description: 
// OpCode: 0x0b	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_DCX_B() {

	// Logic for: BC = BC-1
	// @TODO [Michael]: fill in logic

	func_ClockCycles(5);

}

////////////////////
// Description: Increments the register below
// OpCode: 0x0c	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers: C and A
// Written By: Madison
////////////////////
void func_INR_C() {

	// Logic for: C <- C+1
	func_INR_Registers(i8080.state.registers.C);

	// Set flags: Z, S, P, AC
	func_ClockCycles(5);

}

////////////////////
// Description: Decrements the register below
// OpCode: 0x0d	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_DCR_C() {

	// Logic for: C <-C-1
	func_DCR_Registers(i8080.state.registers.C);

	// Set flags: Z, S, P, AC
	func_ClockCycles(5);

}

////////////////////
// Description: Adds byte 2 to the register below
// OpCode: 0x0e	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: C and A
// Written By: Michael
////////////////////
void func_MVI_C_D8() {

	// Logic for: C <- byte 2
	func_MVI_Registers(i8080.state.registers.C);

	func_ClockCycles(7);

	// Inc PC to account for additional size
	func_Inc_PC(1);

}

////////////////////
// Description: 
// OpCode: 0x0f	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: CY
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_RRC() {

	// Logic for: A = A >> 1; bit 7 = prev bit 0; CY = prev bit 0
	// @TODO [Madison]: fill in logic

	// Set flags: CY
	func_ClockCycles(4);

}

// Opcode 0x10 not implemented

////////////////////
// Description: 
// OpCode: 0x11	|| Size: 3 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_LXI_D_D16() {

	// Logic for: D <- byte 3, E <- byte 2
	// @TODO [Michael]: fill in logic

	func_ClockCycles(10);

	// Inc PC to account for additional size
	func_Inc_PC(2);

}

////////////////////
// Description: 
// OpCode: 0x12	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_STAX_D() {

	// Logic for: (DE) <- A
	// @TODO [Madison]: fill in logic

	func_ClockCycles(7);

}

////////////////////
// Description: 
// OpCode: 0x13	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_INX_D() {

	// Logic for: DE <- DE + 1
	// @TODO [Ruben ]: fill in logic

	func_ClockCycles(5);

}

////////////////////
// Description: Increments the register below
// OpCode: 0x14	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers: D and A
// Written By: Michael
////////////////////
void func_INR_D() {

	// Logic for: D <- D+1
	func_INR_Registers(i8080.state.registers.D);

	// Set flags: Z, S, P, AC
	func_ClockCycles(5);

}

////////////////////
// Description: Decrements the register below
// OpCode: 0x15	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_DCR_D() {

	// Logic for: D <- D-1
	func_DCR_Registers(i8080.state.registers.D);

	// Set flags: Z, S, P, AC
	func_ClockCycles(5);

}

////////////////////
// Description: Adds byte 2 to the register below
// OpCode: 0x16	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: D and A
// Written By: Ruben 
////////////////////
void func_MVI_D_D8() {

	// Logic for: D <- byte 2
	func_MVI_Registers(i8080.state.registers.D);

	func_ClockCycles(7);

	// Inc PC to account for additional size
	func_Inc_PC(1);

}

////////////////////
// Description: 
// OpCode: 0x17	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: CY
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_RAL() {

	// Logic for: A = A << 1; bit 0 = prev CY; CY = prev bit 7
	// @TODO [Michael]: fill in logic

	// Set flags: CY
	func_ClockCycles(4);

}

// Opcode 0x18 not implemented

////////////////////
// Description: 
// OpCode: 0x19	|| Size: 1 bit	|| Clock cycles: 10
// Modifed Flags: CY
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_DAD_D() {

	// Logic for: HL = HL + DE
	// @TODO [Ruben ]: fill in logic

	// Set flags: CY
	func_ClockCycles(10);

}

////////////////////
// Description: 
// OpCode: 0x1a	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_LDAX_D() {

	// Logic for: A <- (DE)
	// @TODO [Michael]: fill in logic

	func_ClockCycles(7);

}

////////////////////
// Description: 
// OpCode: 0x1b	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_DCX_D() {

	// Logic for: DE = DE-1
	// @TODO [Madison]: fill in logic

	func_ClockCycles(5);

}

////////////////////
// Description: Increments the register below
// OpCode: 0x1c	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers: E and A
// Written By: Ruben 
////////////////////
void func_INR_E() {

	// Logic for: E <-E+1
	func_INR_Registers(i8080.state.registers.E);

	// Set flags: Z, S, P, AC
	func_ClockCycles(5);

}

////////////////////
// Description: Decrements the register below
// OpCode: 0x1d	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_DCR_E() {

	// Logic for: E <- E-1
	func_DCR_Registers(i8080.state.registers.E);

	// Set flags: Z, S, P, AC
	func_ClockCycles(5);

}

////////////////////
// Description: Adds byte 2 to the register below
// OpCode: 0x1e	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: E and A
// Written By: Madison
////////////////////
void func_MVI_E_D8() {

	// Logic for: E <- byte 2
	func_MVI_Registers(i8080.state.registers.E);

	func_ClockCycles(7);

	// Inc PC to account for additional size
	func_Inc_PC(1);

}

////////////////////
// Description: 
// OpCode: 0x1f	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: CY
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_RAR() {

	// Logic for: A = A >> 1; bit 7 = prev bit 7; CY = prev bit 0
	// @TODO [Ruben ]: fill in logic

	// Set flags: CY
	func_ClockCycles(4);

}

////////////////////
// Description: 
// OpCode: 0x20	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_RIM() {

	// Logic for: special
	// @TODO [Michael]: fill in logic

	func_ClockCycles(4);

}

////////////////////
// Description: 
// OpCode: 0x21	|| Size: 3 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_LXI_H_D16() {

	// Logic for: H <- byte 3, L <- byte 2
	// @TODO [Madison]: fill in logic

	func_ClockCycles(10);

	// Inc PC to account for additional size
	func_Inc_PC(2);

}

////////////////////
// Description: 
// OpCode: 0x22	|| Size: 3 bit	|| Clock cycles: 16
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_SHLD_ADR() {

	// Logic for: (adr) <-L; (adr+1)<-H
	// @TODO [Ruben ]: fill in logic

	func_ClockCycles(16);

	// Inc PC to account for additional size
	func_Inc_PC(2);

}

////////////////////
// Description: 
// OpCode: 0x23	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_INX_H() {

	// Logic for: HL <- HL + 1
	// @TODO [Michael]: fill in logic

	func_ClockCycles(5);

}

////////////////////
// Description: Increments the register below
// OpCode: 0x24	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers: H and A
// Written By: Madison
////////////////////
void func_INR_H() {

	// Logic for: H <- H+1
	func_INR_Registers(i8080.state.registers.H);

	// Set flags: Z, S, P, AC
	func_ClockCycles(5);

}

////////////////////
// Description: Decrements the register below
// OpCode: 0x25	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_DCR_H() {

	// Logic for: H <- H-1
	func_DCR_Registers(i8080.state.registers.H);

	// Set flags: Z, S, P, AC
	func_ClockCycles(5);

}

////////////////////
// Description: Adds byte 2 to the register below
// OpCode: 0x26	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: H and A
// Written By: Michael
////////////////////
void func_MVI_H_D8() {

	// Logic for: L <- byte 2
	func_MVI_Registers(i8080.state.registers.H);

	func_ClockCycles(7);

	// Inc PC to account for additional size
	func_Inc_PC(1);

}

////////////////////
// Description: 
// OpCode: 0x27	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_DAA() {

	// Logic for: special
	// @TODO [Madison]: fill in logic

	func_ClockCycles(4);

}

// Opcode 0x28 not implemented

////////////////////
// Description: 
// OpCode: 0x29	|| Size: 1 bit	|| Clock cycles: 10
// Modifed Flags: CY
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_DAD_H() {

	// Logic for: HL = HL + HI
	// @TODO [Michael]: fill in logic

	// Set flags: CY
	func_ClockCycles(10);

}

////////////////////
// Description: 
// OpCode: 0x2a	|| Size: 3 bit	|| Clock cycles: 16
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_LHLD_ADR() {

	// Logic for: L <- (adr); H<-(adr+1)
	// @TODO [Madison]: fill in logic

	func_ClockCycles(16);

	// Inc PC to account for additional size
	func_Inc_PC(2);

}

////////////////////
// Description: 
// OpCode: 0x2b	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_DCX_H() {

	// Logic for: HL = HL-1
	// @TODO [Ruben ]: fill in logic

	func_ClockCycles(5);

}

////////////////////
// Description: Increments the register below
// OpCode: 0x2c	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers: L and A
// Written By: Michael
////////////////////
void func_INR_L() {

	// Logic for: L <- L+1
	func_INR_Registers(i8080.state.registers.L);

	// Set flags: Z, S, P, AC
	func_ClockCycles(5);

}

////////////////////
// Description: Decrements the register below
// OpCode: 0x2d	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_DCR_L() {

	// Logic for: L <- L-1
	func_DCR_Registers(i8080.state.registers.L);

	// Set flags: Z, S, P, AC
	func_ClockCycles(5);

}

////////////////////
// Description: Adds byte 2 to the register below
// OpCode: 0x2e	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: L and A
// Written By: Ruben 
////////////////////
void func_MVI_L_D8() {

	// Logic for: L <- byte 2
	func_MVI_Registers(i8080.state.registers.L);

	func_ClockCycles(7);

	// Inc PC to account for additional size
	func_Inc_PC(1);

}

////////////////////
// Description: 
// OpCode: 0x2f	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_CMA() {

	// Logic for: A <- !A
	// @TODO [Michael]: fill in logic

	func_ClockCycles(4);

}

////////////////////
// Description: 
// OpCode: 0x30	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_SIM() {

	// Logic for: special
	// @TODO [Madison]: fill in logic

	func_ClockCycles(4);

}

////////////////////
// Description: 
// OpCode: 0x31	|| Size: 3 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_LXI_SP_D16() {

	// Logic for: SP.hi <- byte 3, SP.lo <- byte 2
	// @TODO [Ruben ]: fill in logic

	func_ClockCycles(10);

	// Inc PC to account for additional size
	func_Inc_PC(2);

}

////////////////////
// Description: 
// OpCode: 0x32	|| Size: 3 bit	|| Clock cycles: 13
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_STA_ADR() {

	// Logic for: (adr) <- A
	// @TODO [Michael]: fill in logic

	func_ClockCycles(13);

	// Inc PC to account for additional size
	func_Inc_PC(2);

}

////////////////////
// Description: 
// OpCode: 0x33	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_INX_SP() {

	// Logic for: SP = SP + 1
	// @TODO [Madison]: fill in logic

	func_ClockCycles(5);

}

////////////////////
// Description: Increments the register below
// OpCode: 0x34	|| Size: 1 bit	|| Clock cycles: 10
// Modifed Flags: Z, S, P, AC
// Modifed Registers: M and A
// Written By: Ruben 
////////////////////
void func_INR_M() {

	// Logic for: (HL) <- (HL)+1
	func_INR_Registers(i8080.state.registers.M);

	// Set flags: Z, S, P, AC
	func_ClockCycles(10);

}

////////////////////
// Description: Decrements the register below
// OpCode: 0x35	|| Size: 1 bit	|| Clock cycles: 10
// Modifed Flags: Z, S, P, AC
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_DCR_M() {

	// Logic for: (HL) <- (HL)-1
	func_DCR_Registers(i8080.state.registers.M);

	// Set flags: Z, S, P, AC
	func_ClockCycles(10);

}

////////////////////
// Description: Adds byte 2 to the register below
// OpCode: 0x36	|| Size: 2 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers: M and A
// Written By: Madison
////////////////////
void func_MVI_M_D8() {

	// Logic for: (HL) <- byte 2
	func_MVI_Registers(i8080.state.registers.M);

	func_ClockCycles(10);

	// Inc PC to account for additional size
	func_Inc_PC(1);

}

////////////////////
// Description: 
// OpCode: 0x37	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: CY
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_STC() {

	// Logic for: CY = 1
	// @TODO [Ruben ]: fill in logic

	// Set flags: CY
	func_ClockCycles(4);

}

// Opcode 0x38 not implemented

////////////////////
// Description: 
// OpCode: 0x39	|| Size: 1 bit	|| Clock cycles: 10
// Modifed Flags: CY
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_DAD_SP() {

	// Logic for: HL = HL + SP
	// @TODO [Madison]: fill in logic

	// Set flags: CY
	func_ClockCycles(10);

}

////////////////////
// Description: 
// OpCode: 0x3a	|| Size: 3 bit	|| Clock cycles: 13
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_LDA_ADR() {

	// Logic for: A <- (adr)
	// @TODO [Ruben ]: fill in logic

	func_ClockCycles(13);

	// Inc PC to account for additional size
	func_Inc_PC(2);

}

////////////////////
// Description: 
// OpCode: 0x3b	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_DCX_SP() {

	// Logic for: SP = SP-1
	// @TODO [Michael]: fill in logic

	func_ClockCycles(5);

}

////////////////////
// Description: Increments the register below
// OpCode: 0x3c	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers: A and A
// Written By: Madison
////////////////////
void func_INR_A() {

	// Logic for: A <- A+1
	func_INR_Registers(i8080.state.registers.A);

	// Set flags: Z, S, P, AC
	func_ClockCycles(5);

}

////////////////////
// Description: Decrements the register below
// OpCode: 0x3d	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_DCR_A() {

	// Logic for: A <- A-1
	func_DCR_Registers(i8080.state.registers.A);

	// Set flags: Z, S, P, AC
	func_ClockCycles(5);

}

////////////////////
// Description: Adds byte 2 to the register below
// OpCode: 0x3e	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: A and A
// Written By: Michael
////////////////////
void func_MVI_A_D8() {

	// Logic for: A <- byte 2
	func_MVI_Registers(i8080.state.registers.A);

	func_ClockCycles(7);

	// Inc PC to account for additional size
	func_Inc_PC(1);

}

////////////////////
// Description: 
// OpCode: 0x3f	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: CY
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_CMC() {

	// Logic for: CY=!CY
	// @TODO [Madison]: fill in logic

	// Set flags: CY
	func_ClockCycles(4);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x40	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: B and B
// Written By: Ruben 
////////////////////
void func_MOV_B_B() {

	// Logic for: B <- B
	func_MOV_Registers(i8080.state.registers.B, i8080.state.registers.B);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x41	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: B and C
// Written By: Michael
////////////////////
void func_MOV_B_C() {

	// Logic for: B <- C
	func_MOV_Registers(i8080.state.registers.B, i8080.state.registers.C);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x42	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: B and D
// Written By: Madison
////////////////////
void func_MOV_B_D() {

	// Logic for: B <- D
	func_MOV_Registers(i8080.state.registers.B, i8080.state.registers.D);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x43	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: B and E
// Written By: Ruben 
////////////////////
void func_MOV_B_E() {

	// Logic for: B <- E
	func_MOV_Registers(i8080.state.registers.B, i8080.state.registers.E);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x44	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: B and H
// Written By: Michael
////////////////////
void func_MOV_B_H() {

	// Logic for: B <- H
	func_MOV_Registers(i8080.state.registers.B, i8080.state.registers.H);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x45	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: B and L
// Written By: Madison
////////////////////
void func_MOV_B_L() {

	// Logic for: B <- L
	func_MOV_Registers(i8080.state.registers.B, i8080.state.registers.L);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x46	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: B and M
// Written By: Ruben 
////////////////////
void func_MOV_B_M() {

	// Logic for: B <- (HL)
	func_MOV_Registers(i8080.state.registers.B, i8080.state.registers.M);

	func_ClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x47	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: B and A
// Written By: Michael
////////////////////
void func_MOV_B_A() {

	// Logic for: B <- A
	func_MOV_Registers(i8080.state.registers.B, i8080.state.registers.A);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x48	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: C and B
// Written By: Madison
////////////////////
void func_MOV_C_B() {

	// Logic for: C <- B
	func_MOV_Registers(i8080.state.registers.C, i8080.state.registers.B);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x49	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: C and C
// Written By: Ruben 
////////////////////
void func_MOV_C_C() {

	// Logic for: C <- C
	func_MOV_Registers(i8080.state.registers.C, i8080.state.registers.C);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x4a	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: C and D
// Written By: Michael
////////////////////
void func_MOV_C_D() {

	// Logic for: C <- D
	func_MOV_Registers(i8080.state.registers.C, i8080.state.registers.D);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x4b	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: C and E
// Written By: Madison
////////////////////
void func_MOV_C_E() {

	// Logic for: C <- E
	func_MOV_Registers(i8080.state.registers.C, i8080.state.registers.E);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x4c	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: C and H
// Written By: Ruben 
////////////////////
void func_MOV_C_H() {

	// Logic for: C <- H
	func_MOV_Registers(i8080.state.registers.C, i8080.state.registers.H);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x4d	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: C and L
// Written By: Michael
////////////////////
void func_MOV_C_L() {

	// Logic for: C <- L
	func_MOV_Registers(i8080.state.registers.C, i8080.state.registers.L);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x4e	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: C and M
// Written By: Madison
////////////////////
void func_MOV_C_M() {

	// Logic for: C <- (HL)
	func_MOV_Registers(i8080.state.registers.C, i8080.state.registers.M);

	func_ClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x4f	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: C and A
// Written By: Ruben 
////////////////////
void func_MOV_C_A() {

	// Logic for: C <- A
	func_MOV_Registers(i8080.state.registers.C, i8080.state.registers.A);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x50	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: D and B
// Written By: Michael
////////////////////
void func_MOV_D_B() {

	// Logic for: D <- B
	func_MOV_Registers(i8080.state.registers.D, i8080.state.registers.B);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x51	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: D and C
// Written By: Madison
////////////////////
void func_MOV_D_C() {

	// Logic for: D <- C
	func_MOV_Registers(i8080.state.registers.D, i8080.state.registers.C);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x52	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: D and D
// Written By: Ruben 
////////////////////
void func_MOV_D_D() {

	// Logic for: D <- D
	func_MOV_Registers(i8080.state.registers.D, i8080.state.registers.D);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x53	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: D and E
// Written By: Michael
////////////////////
void func_MOV_D_E() {

	// Logic for: D <- E
	func_MOV_Registers(i8080.state.registers.D, i8080.state.registers.E);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x54	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: D and H
// Written By: Madison
////////////////////
void func_MOV_D_H() {

	// Logic for: D <- H
	func_MOV_Registers(i8080.state.registers.D, i8080.state.registers.H);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x55	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: D and L
// Written By: Ruben 
////////////////////
void func_MOV_D_L() {

	// Logic for: D <- L
	func_MOV_Registers(i8080.state.registers.D, i8080.state.registers.L);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x56	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: D and M
// Written By: Michael
////////////////////
void func_MOV_D_M() {

	// Logic for: D <- (HL)
	func_MOV_Registers(i8080.state.registers.D, i8080.state.registers.M);

	func_ClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x57	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: D and A
// Written By: Madison
////////////////////
void func_MOV_D_A() {

	// Logic for: D <- A
	func_MOV_Registers(i8080.state.registers.D, i8080.state.registers.A);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x58	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: E and B
// Written By: Ruben 
////////////////////
void func_MOV_E_B() {

	// Logic for: E <- B
	func_MOV_Registers(i8080.state.registers.E, i8080.state.registers.B);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x59	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: E and C
// Written By: Michael
////////////////////
void func_MOV_E_C() {

	// Logic for: E <- C
	func_MOV_Registers(i8080.state.registers.E, i8080.state.registers.C);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x5a	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: E and D
// Written By: Madison
////////////////////
void func_MOV_E_D() {

	// Logic for: E <- D
	func_MOV_Registers(i8080.state.registers.E, i8080.state.registers.D);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x5b	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: E and E
// Written By: Ruben 
////////////////////
void func_MOV_E_E() {

	// Logic for: E <- E
	func_MOV_Registers(i8080.state.registers.E, i8080.state.registers.E);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x5c	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: E and H
// Written By: Michael
////////////////////
void func_MOV_E_H() {

	// Logic for: E <- H
	func_MOV_Registers(i8080.state.registers.E, i8080.state.registers.H);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x5d	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: E and L
// Written By: Madison
////////////////////
void func_MOV_E_L() {

	// Logic for: E <- L
	func_MOV_Registers(i8080.state.registers.E, i8080.state.registers.L);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x5e	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: E and M
// Written By: Ruben 
////////////////////
void func_MOV_E_M() {

	// Logic for: E <- (HL)
	func_MOV_Registers(i8080.state.registers.E, i8080.state.registers.M);

	func_ClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x5f	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: E and A
// Written By: Michael
////////////////////
void func_MOV_E_A() {

	// Logic for: E <- A
	func_MOV_Registers(i8080.state.registers.E, i8080.state.registers.A);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x60	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: H and B
// Written By: Madison
////////////////////
void func_MOV_H_B() {

	// Logic for: H <- B
	func_MOV_Registers(i8080.state.registers.H, i8080.state.registers.B);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x61	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: H and C
// Written By: Ruben 
////////////////////
void func_MOV_H_C() {

	// Logic for: H <- C
	func_MOV_Registers(i8080.state.registers.H, i8080.state.registers.C);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x62	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: H and D
// Written By: Michael
////////////////////
void func_MOV_H_D() {

	// Logic for: H <- D
	func_MOV_Registers(i8080.state.registers.H, i8080.state.registers.D);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x63	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: H and E
// Written By: Madison
////////////////////
void func_MOV_H_E() {

	// Logic for: H <- E
	func_MOV_Registers(i8080.state.registers.H, i8080.state.registers.E);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x64	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: H and H
// Written By: Ruben 
////////////////////
void func_MOV_H_H() {

	// Logic for: H <- H
	func_MOV_Registers(i8080.state.registers.H, i8080.state.registers.H);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x65	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: H and L
// Written By: Michael
////////////////////
void func_MOV_H_L() {

	// Logic for: H <- L
	func_MOV_Registers(i8080.state.registers.H, i8080.state.registers.L);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x66	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: H and M
// Written By: Madison
////////////////////
void func_MOV_H_M() {

	// Logic for: H <- (HL)
	func_MOV_Registers(i8080.state.registers.H, i8080.state.registers.M);

	func_ClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x67	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: H and A
// Written By: Ruben 
////////////////////
void func_MOV_H_A() {

	// Logic for: H <- A
	func_MOV_Registers(i8080.state.registers.H, i8080.state.registers.A);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x68	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: L and B
// Written By: Michael
////////////////////
void func_MOV_L_B() {

	// Logic for: L <- B
	func_MOV_Registers(i8080.state.registers.L, i8080.state.registers.B);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x69	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: L and C
// Written By: Madison
////////////////////
void func_MOV_L_C() {

	// Logic for: L <- C
	func_MOV_Registers(i8080.state.registers.L, i8080.state.registers.C);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x6a	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: L and D
// Written By: Ruben 
////////////////////
void func_MOV_L_D() {

	// Logic for: L <- D
	func_MOV_Registers(i8080.state.registers.L, i8080.state.registers.D);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x6b	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: L and E
// Written By: Michael
////////////////////
void func_MOV_L_E() {

	// Logic for: L <- E
	func_MOV_Registers(i8080.state.registers.L, i8080.state.registers.E);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x6c	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: L and H
// Written By: Madison
////////////////////
void func_MOV_L_H() {

	// Logic for: L <- H
	func_MOV_Registers(i8080.state.registers.L, i8080.state.registers.H);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x6d	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: L and L
// Written By: Ruben 
////////////////////
void func_MOV_L_L() {

	// Logic for: L <- L
	func_MOV_Registers(i8080.state.registers.L, i8080.state.registers.L);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x6e	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: L and M
// Written By: Michael
////////////////////
void func_MOV_L_M() {

	// Logic for: L <- (HL)
	func_MOV_Registers(i8080.state.registers.L, i8080.state.registers.M);

	func_ClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x6f	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: L and A
// Written By: Madison
////////////////////
void func_MOV_L_A() {

	// Logic for: L <- A
	func_MOV_Registers(i8080.state.registers.L, i8080.state.registers.A);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x70	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: M and B
// Written By: Ruben 
////////////////////
void func_MOV_M_B() {

	// Logic for: (HL) <- B
	func_MOV_Registers(i8080.state.registers.M, i8080.state.registers.B);

	func_ClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x71	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: M and C
// Written By: Michael
////////////////////
void func_MOV_M_C() {

	// Logic for: (HL) <- C
	func_MOV_Registers(i8080.state.registers.M, i8080.state.registers.C);

	func_ClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x72	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: M and D
// Written By: Madison
////////////////////
void func_MOV_M_D() {

	// Logic for: (HL) <- D
	func_MOV_Registers(i8080.state.registers.M, i8080.state.registers.D);

	func_ClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x73	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: M and E
// Written By: Ruben 
////////////////////
void func_MOV_M_E() {

	// Logic for: (HL) <- E
	func_MOV_Registers(i8080.state.registers.M, i8080.state.registers.E);

	func_ClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x74	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: M and H
// Written By: Michael
////////////////////
void func_MOV_M_H() {

	// Logic for: (HL) <- H
	func_MOV_Registers(i8080.state.registers.M, i8080.state.registers.H);

	func_ClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x75	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: M and L
// Written By: Madison
////////////////////
void func_MOV_M_L() {

	// Logic for: (HL) <- L
	func_MOV_Registers(i8080.state.registers.M, i8080.state.registers.L);

	func_ClockCycles(7);

}

////////////////////
// Description: 
// OpCode: 0x76	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_HLT() {

	// Logic for: special
	// @TODO [Ruben ]: fill in logic

	func_ClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x77	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: M and A
// Written By: Michael
////////////////////
void func_MOV_M_A() {

	// Logic for: (HL) <- C
	func_MOV_Registers(i8080.state.registers.M, i8080.state.registers.A);

	func_ClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x78	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: A and B
// Written By: Madison
////////////////////
void func_MOV_A_B() {

	// Logic for: A <- B
	func_MOV_Registers(i8080.state.registers.A, i8080.state.registers.B);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x79	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: A and C
// Written By: Ruben 
////////////////////
void func_MOV_A_C() {

	// Logic for: A <- C
	func_MOV_Registers(i8080.state.registers.A, i8080.state.registers.C);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x7a	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: A and D
// Written By: Michael
////////////////////
void func_MOV_A_D() {

	// Logic for: A <- D
	func_MOV_Registers(i8080.state.registers.A, i8080.state.registers.D);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x7b	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: A and E
// Written By: Madison
////////////////////
void func_MOV_A_E() {

	// Logic for: A <- E
	func_MOV_Registers(i8080.state.registers.A, i8080.state.registers.E);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x7c	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: A and H
// Written By: Ruben 
////////////////////
void func_MOV_A_H() {

	// Logic for: A <- H
	func_MOV_Registers(i8080.state.registers.A, i8080.state.registers.H);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x7d	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: A and L
// Written By: Michael
////////////////////
void func_MOV_A_L() {

	// Logic for: A <- L
	func_MOV_Registers(i8080.state.registers.A, i8080.state.registers.L);

	func_ClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x7e	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: A and M
// Written By: Madison
////////////////////
void func_MOV_A_M() {

	// Logic for: A <- (HL)
	func_MOV_Registers(i8080.state.registers.A, i8080.state.registers.M);

	func_ClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x7f	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: A and A
// Written By: Ruben 
////////////////////
void func_MOV_A_A() {

	// Logic for: A <- A
	func_MOV_Registers(i8080.state.registers.A, i8080.state.registers.A);

	func_ClockCycles(5);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x80	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: B and A
// Written By: Michael
////////////////////
void func_ADD_B() {

	// Logic for: A <- A + B
	func_AD_Registers(i8080.state.registers.B, false);

	// Set flags: Z, S, P, CY, AC
	// Flags set in AD function

	func_ClockCycles(4);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x81	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: C and A
// Written By: Madison
////////////////////
void func_ADD_C() {

	// Logic for: A <- A + C
	func_AD_Registers(i8080.state.registers.C, false);

	// Set flags: Z, S, P, CY, AC
	// Flags set in AD function

	func_ClockCycles(4);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x82	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: D and A
// Written By: Ruben 
////////////////////
void func_ADD_D() {

	// Logic for: A <- A + D
	func_AD_Registers(i8080.state.registers.D, false);

	// Set flags: Z, S, P, CY, AC
	// Flags set in AD function

	func_ClockCycles(4);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x83	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: E and A
// Written By: Michael
////////////////////
void func_ADD_E() {

	// Logic for: A <- A + E
	func_AD_Registers(i8080.state.registers.E, false);

	// Set flags: Z, S, P, CY, AC
	// Flags set in AD function

	func_ClockCycles(4);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x84	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: H and A
// Written By: Madison
////////////////////
void func_ADD_H() {

	// Logic for: A <- A + H
	func_AD_Registers(i8080.state.registers.H, false);

	// Set flags: Z, S, P, CY, AC
	// Flags set in AD function

	func_ClockCycles(4);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x85	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: L and A
// Written By: Ruben 
////////////////////
void func_ADD_L() {

	// Logic for: A <- A + L
	func_AD_Registers(i8080.state.registers.L, false);

	// Set flags: Z, S, P, CY, AC
	// Flags set in AD function

	func_ClockCycles(4);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x86	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: M and A
// Written By: Michael
////////////////////
void func_ADD_M() {

	// Logic for: A <- A + (HL)
	func_AD_Registers(i8080.state.registers.M, false);

	// Set flags: Z, S, P, CY, AC
	// Flags set in AD function

	func_ClockCycles(7);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x87	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: A and A
// Written By: Madison
////////////////////
void func_ADD_A() {

	// Logic for: A <- A + A
	func_AD_Registers(i8080.state.registers.A, false);

	// Set flags: Z, S, P, CY, AC
	// Flags set in AD function

	func_ClockCycles(4);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x88	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: B and A
// Written By: Ruben 
////////////////////
void func_ADC_B() {

	// Logic for: A <- A + B + CY
	func_AD_Registers(i8080.state.registers.B, true);

	// Set flags: Z, S, P, CY, AC
	// Flags set in AD function

	func_ClockCycles(4);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x89	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: C and A
// Written By: Michael
////////////////////
void func_ADC_C() {

	// Logic for: A <- A + C + CY
	func_AD_Registers(i8080.state.registers.C, true);

	// Set flags: Z, S, P, CY, AC
	// Flags set in AD function

	func_ClockCycles(4);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x8a	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: D and A
// Written By: Madison
////////////////////
void func_ADC_D() {

	// Logic for: A <- A + D + CY
	func_AD_Registers(i8080.state.registers.D, true);

	// Set flags: Z, S, P, CY, AC
	// Flags set in AD function

	func_ClockCycles(4);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x8b	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: E and A
// Written By: Ruben 
////////////////////
void func_ADC_E() {

	// Logic for: A <- A + E + CY
	func_AD_Registers(i8080.state.registers.E, true);

	// Set flags: Z, S, P, CY, AC
	// Flags set in AD function

	func_ClockCycles(4);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x8c	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: H and A
// Written By: Michael
////////////////////
void func_ADC_H() {

	// Logic for: A <- A + H + CY
	func_AD_Registers(i8080.state.registers.H, true);

	// Set flags: Z, S, P, CY, AC
	// Flags set in AD function

	func_ClockCycles(4);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x8d	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: L and A
// Written By: Madison
////////////////////
void func_ADC_L() {

	// Logic for: A <- A + L + CY
	func_AD_Registers(i8080.state.registers.L, true);

	// Set flags: Z, S, P, CY, AC
	// Flags set in AD function

	func_ClockCycles(4);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x8e	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: M and A
// Written By: Ruben 
////////////////////
void func_ADC_M() {

	// Logic for: A <- A + (HL) + CY
	func_AD_Registers(i8080.state.registers.M, true);

	// Set flags: Z, S, P, CY, AC
	// Flags set in AD function

	func_ClockCycles(7);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x8f	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: A and A
// Written By: Michael
////////////////////
void func_ADC_A() {

	// Logic for: A <- A + A + CY
	func_AD_Registers(i8080.state.registers.A, true);

	// Set flags: Z, S, P, CY, AC
	// Flags set in AD function

	func_ClockCycles(4);

}

////////////////////
// Description: 
// OpCode: 0x90	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_SUB_B() {

	// Logic for: A <- A - B
	// @TODO [Madison]: fill in logic

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: 
// OpCode: 0x91	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_SUB_C() {

	// Logic for: A <- A - C
	// @TODO [Ruben ]: fill in logic

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: 
// OpCode: 0x92	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_SUB_D() {

	// Logic for: A <- A + D
	// @TODO [Michael]: fill in logic

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: 
// OpCode: 0x93	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_SUB_E() {

	// Logic for: A <- A - E
	// @TODO [Madison]: fill in logic

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: 
// OpCode: 0x94	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_SUB_H() {

	// Logic for: A <- A + H
	// @TODO [Ruben ]: fill in logic

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: 
// OpCode: 0x95	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_SUB_L() {

	// Logic for: A <- A - L
	// @TODO [Michael]: fill in logic

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: 
// OpCode: 0x96	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_SUB_M() {

	// Logic for: A <- A + (HL)
	// @TODO [Madison]: fill in logic

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(7);

}

////////////////////
// Description: 
// OpCode: 0x97	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_SUB_A() {

	// Logic for: A <- A - A
	// @TODO [Ruben ]: fill in logic

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Subtracts the register below from register A
// OpCode: 0x98	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: B and 
// Written By: Michael
////////////////////
void func_SBB_B() {

	// Logic for: A <- A - B - CY
	func_SBB_Registers(i8080.state.registers.B);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Subtracts the register below from register A
// OpCode: 0x99	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: C and 
// Written By: Madison
////////////////////
void func_SBB_C() {

	// Logic for: A <- A - C - CY
	func_SBB_Registers(i8080.state.registers.C);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Subtracts the register below from register A
// OpCode: 0x9a	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: D and 
// Written By: Ruben 
////////////////////
void func_SBB_D() {

	// Logic for: A <- A - D - CY
	func_SBB_Registers(i8080.state.registers.D);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Subtracts the register below from register A
// OpCode: 0x9b	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: E and 
// Written By: Michael
////////////////////
void func_SBB_E() {

	// Logic for: A <- A - E - CY
	func_SBB_Registers(i8080.state.registers.E);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Subtracts the register below from register A
// OpCode: 0x9c	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: H and 
// Written By: Madison
////////////////////
void func_SBB_H() {

	// Logic for: A <- A - H - CY
	func_SBB_Registers(i8080.state.registers.H);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Subtracts the register below from register A
// OpCode: 0x9d	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: L and 
// Written By: Ruben 
////////////////////
void func_SBB_L() {

	// Logic for: A <- A - L - CY
	func_SBB_Registers(i8080.state.registers.L);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Subtracts the register below from register A
// OpCode: 0x9e	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: M and 
// Written By: Michael
////////////////////
void func_SBB_M() {

	// Logic for: A <- A - (HL) - CY
	func_SBB_Registers(i8080.state.registers.M);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(7);

}

////////////////////
// Description: Subtracts the register below from register A
// OpCode: 0x9f	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: A and 
// Written By: Madison
////////////////////
void func_SBB_A() {

	// Logic for: A <- A - A - CY
	func_SBB_Registers(i8080.state.registers.A);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Perform bitwise AND on registers below
// OpCode: 0xa0	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: B and A
// Written By: Ruben 
////////////////////
void func_ANA_B() {

	// Logic for: A <- A & B
	func_AND_Registers(i8080.state.registers.B);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Perform bitwise AND on registers below
// OpCode: 0xa1	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: C and A
// Written By: Michael
////////////////////
void func_ANA_C() {

	// Logic for: A <- A & C
	func_AND_Registers(i8080.state.registers.C);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Perform bitwise AND on registers below
// OpCode: 0xa2	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: D and A
// Written By: Madison
////////////////////
void func_ANA_D() {

	// Logic for: A <- A & D
	func_AND_Registers(i8080.state.registers.D);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Perform bitwise AND on registers below
// OpCode: 0xa3	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: E and A
// Written By: Ruben 
////////////////////
void func_ANA_E() {

	// Logic for: A <- A & E
	func_AND_Registers(i8080.state.registers.E);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Perform bitwise AND on registers below
// OpCode: 0xa4	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: H and A
// Written By: Michael
////////////////////
void func_ANA_H() {

	// Logic for: A <- A & H
	func_AND_Registers(i8080.state.registers.H);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Perform bitwise AND on registers below
// OpCode: 0xa5	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: L and A
// Written By: Madison
////////////////////
void func_ANA_L() {

	// Logic for: A <- A & L
	func_AND_Registers(i8080.state.registers.L);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Perform bitwise AND on registers below
// OpCode: 0xa6	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: M and A
// Written By: Ruben 
////////////////////
void func_ANA_M() {

	// Logic for: A <- A & (HL)
	func_AND_Registers(i8080.state.registers.M);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(7);

}

////////////////////
// Description: Perform bitwise AND on registers below
// OpCode: 0xa7	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: A and A
// Written By: Michael
////////////////////
void func_ANA_A() {

	// Logic for: A <- A & A
	func_AND_Registers(i8080.state.registers.A);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Raises register A to the power of the register below
// OpCode: 0xa8	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: B and 
// Written By: Madison
////////////////////
void func_XRA_B() {

	// Logic for: A <- A ^ B
	func_XRA_Registers(i8080.state.registers.B);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Raises register A to the power of the register below
// OpCode: 0xa9	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: C and 
// Written By: Ruben 
////////////////////
void func_XRA_C() {

	// Logic for: A <- A ^ C
	func_XRA_Registers(i8080.state.registers.C);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Raises register A to the power of the register below
// OpCode: 0xaa	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: D and 
// Written By: Michael
////////////////////
void func_XRA_D() {

	// Logic for: A <- A ^ D
	func_XRA_Registers(i8080.state.registers.D);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Raises register A to the power of the register below
// OpCode: 0xab	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: E and 
// Written By: Madison
////////////////////
void func_XRA_E() {

	// Logic for: A <- A ^ E
	func_XRA_Registers(i8080.state.registers.E);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Raises register A to the power of the register below
// OpCode: 0xac	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: H and 
// Written By: Ruben 
////////////////////
void func_XRA_H() {

	// Logic for: A <- A ^ H
	func_XRA_Registers(i8080.state.registers.H);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Raises register A to the power of the register below
// OpCode: 0xad	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: L and 
// Written By: Michael
////////////////////
void func_XRA_L() {

	// Logic for: A <- A ^ L
	func_XRA_Registers(i8080.state.registers.L);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Raises register A to the power of the register below
// OpCode: 0xae	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: M and 
// Written By: Madison
////////////////////
void func_XRA_M() {

	// Logic for: A <- A ^ (HL)
	func_XRA_Registers(i8080.state.registers.M);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(7);

}

////////////////////
// Description: Raises register A to the power of the register below
// OpCode: 0xaf	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: A and 
// Written By: Ruben 
////////////////////
void func_XRA_A() {

	// Logic for: A <- A ^ A
	func_XRA_Registers(i8080.state.registers.A);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Performs OR on the two registers below
// OpCode: 0xb0	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: B and 
// Written By: Michael
////////////////////
void func_ORA_B() {

	// Logic for: A <- A | B
	func_ORA_Registers(i8080.state.registers.B, i8080.state.registers.);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Performs OR on the two registers below
// OpCode: 0xb1	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: C and 
// Written By: Madison
////////////////////
void func_ORA_C() {

	// Logic for: A <- A | C
	func_ORA_Registers(i8080.state.registers.C, i8080.state.registers.);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Performs OR on the two registers below
// OpCode: 0xb2	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: D and 
// Written By: Ruben 
////////////////////
void func_ORA_D() {

	// Logic for: A <- A | D
	func_ORA_Registers(i8080.state.registers.D, i8080.state.registers.);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Performs OR on the two registers below
// OpCode: 0xb3	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: E and 
// Written By: Michael
////////////////////
void func_ORA_E() {

	// Logic for: A <- A | E
	func_ORA_Registers(i8080.state.registers.E, i8080.state.registers.);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Performs OR on the two registers below
// OpCode: 0xb4	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: H and 
// Written By: Madison
////////////////////
void func_ORA_H() {

	// Logic for: A <- A | H
	func_ORA_Registers(i8080.state.registers.H, i8080.state.registers.);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Performs OR on the two registers below
// OpCode: 0xb5	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: L and 
// Written By: Ruben 
////////////////////
void func_ORA_L() {

	// Logic for: A <- A | L
	func_ORA_Registers(i8080.state.registers.L, i8080.state.registers.);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Performs OR on the two registers below
// OpCode: 0xb6	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: M and 
// Written By: Michael
////////////////////
void func_ORA_M() {

	// Logic for: A <- A | (HL)
	func_ORA_Registers(i8080.state.registers.M, i8080.state.registers.);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(7);

}

////////////////////
// Description: Performs OR on the two registers below
// OpCode: 0xb7	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: A and 
// Written By: Madison
////////////////////
void func_ORA_A() {

	// Logic for: A <- A | A
	func_ORA_Registers(i8080.state.registers.A, i8080.state.registers.);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Compares the two registers below
// OpCode: 0xb8	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: B and A
// Written By: Ruben 
////////////////////
void func_CMP_B() {

	// Logic for: A - B
	func_CMP_Registers(i8080.state.registers.B);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Compares the two registers below
// OpCode: 0xb9	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: C and A
// Written By: Michael
////////////////////
void func_CMP_C() {

	// Logic for: A - C
	func_CMP_Registers(i8080.state.registers.C);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Compares the two registers below
// OpCode: 0xba	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: D and A
// Written By: Madison
////////////////////
void func_CMP_D() {

	// Logic for: A - D
	func_CMP_Registers(i8080.state.registers.D);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Compares the two registers below
// OpCode: 0xbb	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: E and A
// Written By: Ruben 
////////////////////
void func_CMP_E() {

	// Logic for: A - E
	func_CMP_Registers(i8080.state.registers.E);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Compares the two registers below
// OpCode: 0xbc	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: H and A
// Written By: Michael
////////////////////
void func_CMP_H() {

	// Logic for: A - H
	func_CMP_Registers(i8080.state.registers.H);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Compares the two registers below
// OpCode: 0xbd	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: L and A
// Written By: Madison
////////////////////
void func_CMP_L() {

	// Logic for: A - L
	func_CMP_Registers(i8080.state.registers.L);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: Compares the two registers below
// OpCode: 0xbe	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: M and A
// Written By: Ruben 
////////////////////
void func_CMP_M() {

	// Logic for: A - (HL)
	func_CMP_Registers(i8080.state.registers.M);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(7);

}

////////////////////
// Description: Compares the two registers below
// OpCode: 0xbf	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: A and A
// Written By: Michael
////////////////////
void func_CMP_A() {

	// Logic for: A - A
	func_CMP_Registers(i8080.state.registers.A);

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(4);

}

////////////////////
// Description: 
// OpCode: 0xc0	|| Size: 1 bit	|| Clock cycles: 44505
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_RNZ() {

	// Logic for: if NZ, RET
	// @TODO [Madison]: fill in logic

	func_ClockCycles(44505);

}

////////////////////
// Description: 
// OpCode: 0xc1	|| Size: 1 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_POP_B() {

	// Logic for: C <- (sp); B <- (sp+1); sp <- sp+2
	// @TODO [Ruben ]: fill in logic

	func_ClockCycles(10);

}

////////////////////
// Description: 
// OpCode: 0xc2	|| Size: 3 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_JNZ_ADR() {

	// Logic for: if NZ, PC <- adr
	// @TODO [Michael]: fill in logic

	func_ClockCycles(10);

	// Inc PC to account for additional size
	func_Inc_PC(2);

}

////////////////////
// Description: 
// OpCode: 0xc3	|| Size: 3 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_JMP_ADR() {

	// Logic for: PC <= adr
	// @TODO [Madison]: fill in logic

	func_ClockCycles(10);

	// Inc PC to account for additional size
	func_Inc_PC(2);

}

////////////////////
// Description: 
// OpCode: 0xc4	|| Size: 3 bit	|| Clock cycles: 17/11
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_CNZ_ADR() {

	// Logic for: if NZ, CALL adr
	// @TODO [Ruben ]: fill in logic

	func_ClockCycles(17/11);

	// Inc PC to account for additional size
	func_Inc_PC(2);

}

////////////////////
// Description: 
// OpCode: 0xc5	|| Size: 1 bit	|| Clock cycles: 11
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_PUSH_B() {

	// Logic for: (sp-2)<-C; (sp-1)<-B; sp <- sp - 2
	// @TODO [Michael]: fill in logic

	func_ClockCycles(11);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0xc6	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: D and A
// Written By: Madison
////////////////////
void func_ADI_D8() {

	// Logic for: A <- A + byte
	func_AD_Registers(i8080.state.registers.D, false);

	// Set flags: Z, S, P, CY, AC
	// Flags set in AD function

	func_ClockCycles(7);

	// Inc PC to account for additional size
	func_Inc_PC(1);

}

////////////////////
// Description: 
// OpCode: 0xc7	|| Size: 1 bit	|| Clock cycles: 11
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_RST_0() {

	// Logic for: CALL $0
	// @TODO [Ruben ]: fill in logic

	func_ClockCycles(11);

}

////////////////////
// Description: 
// OpCode: 0xc8	|| Size: 1 bit	|| Clock cycles: 44505
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_RZ() {

	// Logic for: if Z, RET
	// @TODO [Michael]: fill in logic

	func_ClockCycles(44505);

}

////////////////////
// Description: 
// OpCode: 0xc9	|| Size: 1 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_RET() {

	// Logic for: PC.lo <- (sp); PC.hi<-(sp+1); SP <- SP+2
	// @TODO [Madison]: fill in logic

	func_ClockCycles(10);

}

////////////////////
// Description: 
// OpCode: 0xca	|| Size: 3 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_JZ_ADR() {

	// Logic for: if Z, PC <- adr
	// @TODO [Ruben ]: fill in logic

	func_ClockCycles(10);

	// Inc PC to account for additional size
	func_Inc_PC(2);

}

// Opcode 0xcb not implemented

////////////////////
// Description: 
// OpCode: 0xcc	|| Size: 3 bit	|| Clock cycles: 17/11
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_CZ_ADR() {

	// Logic for: if Z, CALL adr
	// @TODO [Madison]: fill in logic

	func_ClockCycles(17/11);

	// Inc PC to account for additional size
	func_Inc_PC(2);

}

////////////////////
// Description: 
// OpCode: 0xcd	|| Size: 3 bit	|| Clock cycles: 17
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_CALL_ADR() {

	// Logic for: (SP-1)<-PC.hi;(SP-2)<-PC.lo;SP<-SP+2;PC=adr
	// @TODO [Ruben ]: fill in logic

	func_ClockCycles(17);

	// Inc PC to account for additional size
	func_Inc_PC(2);

}

////////////////////
// Description: 
// OpCode: 0xce	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_ACI_D8() {

	// Logic for: A <- A + data + CY
	// @TODO [Michael]: fill in logic

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(7);

	// Inc PC to account for additional size
	func_Inc_PC(1);

}

////////////////////
// Description: 
// OpCode: 0xcf	|| Size: 1 bit	|| Clock cycles: 11
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_RST_1() {

	// Logic for: CALL $8
	// @TODO [Madison]: fill in logic

	func_ClockCycles(11);

}

////////////////////
// Description: 
// OpCode: 0xd0	|| Size: 1 bit	|| Clock cycles: 44505
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_RNC() {

	// Logic for: if NCY, RET
	// @TODO [Ruben ]: fill in logic

	func_ClockCycles(44505);

}

////////////////////
// Description: 
// OpCode: 0xd1	|| Size: 1 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_POP_D() {

	// Logic for: E <- (sp); D <- (sp+1); sp <- sp+2
	// @TODO [Michael]: fill in logic

	func_ClockCycles(10);

}

////////////////////
// Description: 
// OpCode: 0xd2	|| Size: 3 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_JNC_ADR() {

	// Logic for: if NCY, PC<-adr
	// @TODO [Madison]: fill in logic

	func_ClockCycles(10);

	// Inc PC to account for additional size
	func_Inc_PC(2);

}

////////////////////
// Description: 
// OpCode: 0xd3	|| Size: 2 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_OUT_D8() {

	// Logic for: special
	// @TODO [Ruben ]: fill in logic

	func_ClockCycles(10);

	// Inc PC to account for additional size
	func_Inc_PC(1);

}

////////////////////
// Description: 
// OpCode: 0xd4	|| Size: 3 bit	|| Clock cycles: 17/11
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_CNC_ADR() {

	// Logic for: if NCY, CALL adr
	// @TODO [Michael]: fill in logic

	func_ClockCycles(17/11);

	// Inc PC to account for additional size
	func_Inc_PC(2);

}

////////////////////
// Description: 
// OpCode: 0xd5	|| Size: 1 bit	|| Clock cycles: 11
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_PUSH_D() {

	// Logic for: (sp-2)<-E; (sp-1)<-D; sp <- sp - 2
	// @TODO [Madison]: fill in logic

	func_ClockCycles(11);

}

////////////////////
// Description: 
// OpCode: 0xd6	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_SUI_D8() {

	// Logic for: A <- A - data
	// @TODO [Ruben ]: fill in logic

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(7);

	// Inc PC to account for additional size
	func_Inc_PC(1);

}

////////////////////
// Description: 
// OpCode: 0xd7	|| Size: 1 bit	|| Clock cycles: 11
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_RST_2() {

	// Logic for: CALL $10
	// @TODO [Michael]: fill in logic

	func_ClockCycles(11);

}

////////////////////
// Description: 
// OpCode: 0xd8	|| Size: 1 bit	|| Clock cycles: 44505
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_RC() {

	// Logic for: if CY, RET
	// @TODO [Madison]: fill in logic

	func_ClockCycles(44505);

}

// Opcode 0xd9 not implemented

////////////////////
// Description: 
// OpCode: 0xda	|| Size: 3 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_JC_ADR() {

	// Logic for: if CY, PC<-adr
	// @TODO [Michael]: fill in logic

	func_ClockCycles(10);

	// Inc PC to account for additional size
	func_Inc_PC(2);

}

////////////////////
// Description: 
// OpCode: 0xdb	|| Size: 2 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_IN_D8() {

	// Logic for: special
	// @TODO [Madison]: fill in logic

	func_ClockCycles(10);

	// Inc PC to account for additional size
	func_Inc_PC(1);

}

////////////////////
// Description: 
// OpCode: 0xdc	|| Size: 3 bit	|| Clock cycles: 17/11
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_CC_ADR() {

	// Logic for: if CY, CALL adr
	// @TODO [Ruben ]: fill in logic

	func_ClockCycles(17/11);

	// Inc PC to account for additional size
	func_Inc_PC(2);

}

// Opcode 0xdd not implemented

////////////////////
// Description: 
// OpCode: 0xde	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_SBI_D8() {

	// Logic for: A <- A - data - CY
	// @TODO [Madison]: fill in logic

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(7);

	// Inc PC to account for additional size
	func_Inc_PC(1);

}

////////////////////
// Description: 
// OpCode: 0xdf	|| Size: 1 bit	|| Clock cycles: 11
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_RST_3() {

	// Logic for: CALL $18
	// @TODO [Ruben ]: fill in logic

	func_ClockCycles(11);

}

////////////////////
// Description: 
// OpCode: 0xe0	|| Size: 1 bit	|| Clock cycles: 44505
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_RPO() {

	// Logic for: if PO, RET
	// @TODO [Michael]: fill in logic

	func_ClockCycles(44505);

}

////////////////////
// Description: 
// OpCode: 0xe1	|| Size: 1 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_POP_H() {

	// Logic for: L <- (sp); H <- (sp+1); sp <- sp+2
	// @TODO [Madison]: fill in logic

	func_ClockCycles(10);

}

////////////////////
// Description: 
// OpCode: 0xe2	|| Size: 3 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_JPO_ADR() {

	// Logic for: if PO, PC <- adr
	// @TODO [Ruben ]: fill in logic

	func_ClockCycles(10);

	// Inc PC to account for additional size
	func_Inc_PC(2);

}

////////////////////
// Description: 
// OpCode: 0xe3	|| Size: 1 bit	|| Clock cycles: 18
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_XTHL() {

	// Logic for: L <-> (SP); H <-> (SP+1)
	// @TODO [Michael]: fill in logic

	func_ClockCycles(18);

}

////////////////////
// Description: 
// OpCode: 0xe4	|| Size: 3 bit	|| Clock cycles: 17/11
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_CPO_ADR() {

	// Logic for: if PO, CALL adr
	// @TODO [Madison]: fill in logic

	func_ClockCycles(17/11);

	// Inc PC to account for additional size
	func_Inc_PC(2);

}

////////////////////
// Description: 
// OpCode: 0xe5	|| Size: 1 bit	|| Clock cycles: 11
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_PUSH_H() {

	// Logic for: (sp-2)<-L; (sp-1)<-H; sp <- sp - 2
	// @TODO [Ruben ]: fill in logic

	func_ClockCycles(11);

}

////////////////////
// Description: 
// OpCode: 0xe6	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_ANI_D8() {

	// Logic for: A <- A & data
	// @TODO [Michael]: fill in logic

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(7);

	// Inc PC to account for additional size
	func_Inc_PC(1);

}

////////////////////
// Description: 
// OpCode: 0xe7	|| Size: 1 bit	|| Clock cycles: 11
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_RST_4() {

	// Logic for: CALL $20
	// @TODO [Madison]: fill in logic

	func_ClockCycles(11);

}

////////////////////
// Description: 
// OpCode: 0xe8	|| Size: 1 bit	|| Clock cycles: 44505
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_RPE() {

	// Logic for: if PE, RET
	// @TODO [Ruben ]: fill in logic

	func_ClockCycles(44505);

}

////////////////////
// Description: 
// OpCode: 0xe9	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_PCHL() {

	// Logic for: PC.hi <- H; PC.lo <- L
	// @TODO [Michael]: fill in logic

	func_ClockCycles(5);

}

////////////////////
// Description: 
// OpCode: 0xea	|| Size: 3 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_JPE_ADR() {

	// Logic for: if PE, PC <- adr
	// @TODO [Madison]: fill in logic

	func_ClockCycles(10);

	// Inc PC to account for additional size
	func_Inc_PC(2);

}

////////////////////
// Description: 
// OpCode: 0xeb	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_XCHG() {

	// Logic for: H <-> D; L <-> E
	// @TODO [Ruben ]: fill in logic

	func_ClockCycles(5);

}

////////////////////
// Description: 
// OpCode: 0xec	|| Size: 3 bit	|| Clock cycles: 17/11
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_CPE_ADR() {

	// Logic for: if PE, CALL adr
	// @TODO [Michael]: fill in logic

	func_ClockCycles(17/11);

	// Inc PC to account for additional size
	func_Inc_PC(2);

}

// Opcode 0xed not implemented

////////////////////
// Description: 
// OpCode: 0xee	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_XRI_D8() {

	// Logic for: A <- A ^ data
	// @TODO [Ruben ]: fill in logic

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(7);

	// Inc PC to account for additional size
	func_Inc_PC(1);

}

////////////////////
// Description: 
// OpCode: 0xef	|| Size: 1 bit	|| Clock cycles: 11
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_RST_5() {

	// Logic for: CALL $28
	// @TODO [Michael]: fill in logic

	func_ClockCycles(11);

}

////////////////////
// Description: 
// OpCode: 0xf0	|| Size: 1 bit	|| Clock cycles: 44505
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_RP() {

	// Logic for: if P, RET
	// @TODO [Madison]: fill in logic

	func_ClockCycles(44505);

}

////////////////////
// Description: 
// OpCode: 0xf1	|| Size: 1 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_POP_PSW() {

	// Logic for: flags <- (sp); A <- (sp+1); sp <- sp+2
	// @TODO [Ruben ]: fill in logic

	func_ClockCycles(10);

}

////////////////////
// Description: 
// OpCode: 0xf2	|| Size: 3 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_JP_ADR() {

	// Logic for: if P=1 PC <- adr
	// @TODO [Michael]: fill in logic

	func_ClockCycles(10);

	// Inc PC to account for additional size
	func_Inc_PC(2);

}

////////////////////
// Description: 
// OpCode: 0xf3	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_DI() {

	// Logic for: special
	// @TODO [Madison]: fill in logic

	func_ClockCycles(4);

}

////////////////////
// Description: 
// OpCode: 0xf4	|| Size: 3 bit	|| Clock cycles: 17/11
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_CP_ADR() {

	// Logic for: if P, PC <- adr
	// @TODO [Ruben ]: fill in logic

	func_ClockCycles(17/11);

	// Inc PC to account for additional size
	func_Inc_PC(2);

}

////////////////////
// Description: 
// OpCode: 0xf5	|| Size: 1 bit	|| Clock cycles: 11
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_PUSH_PSW() {

	// Logic for: (sp-2)<-flags; (sp-1)<-A; sp <- sp - 2
	// @TODO [Michael]: fill in logic

	func_ClockCycles(11);

}

////////////////////
// Description: 
// OpCode: 0xf6	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_ORI_D8() {

	// Logic for: A <- A | data
	// @TODO [Madison]: fill in logic

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(7);

	// Inc PC to account for additional size
	func_Inc_PC(1);

}

////////////////////
// Description: 
// OpCode: 0xf7	|| Size: 1 bit	|| Clock cycles: 11
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_RST_6() {

	// Logic for: CALL $30
	// @TODO [Ruben ]: fill in logic

	func_ClockCycles(11);

}

////////////////////
// Description: 
// OpCode: 0xf8	|| Size: 1 bit	|| Clock cycles: 44505
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_RM() {

	// Logic for: if M, RET
	// @TODO [Michael]: fill in logic

	func_ClockCycles(44505);

}

////////////////////
// Description: 
// OpCode: 0xf9	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_SPHL() {

	// Logic for: SP=HL
	// @TODO [Madison]: fill in logic

	func_ClockCycles(5);

}

////////////////////
// Description: 
// OpCode: 0xfa	|| Size: 3 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Ruben 
////////////////////
void func_JM_ADR() {

	// Logic for: if M, PC <- adr
	// @TODO [Ruben ]: fill in logic

	func_ClockCycles(10);

	// Inc PC to account for additional size
	func_Inc_PC(2);

}

////////////////////
// Description: 
// OpCode: 0xfb	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_EI() {

	// Logic for: special
	// @TODO [Michael]: fill in logic

	func_ClockCycles(4);

}

////////////////////
// Description: 
// OpCode: 0xfc	|| Size: 3 bit	|| Clock cycles: 17/11
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_CM_ADR() {

	// Logic for: if M, CALL adr
	// @TODO [Madison]: fill in logic

	func_ClockCycles(17/11);

	// Inc PC to account for additional size
	func_Inc_PC(2);

}

// Opcode 0xfd not implemented

////////////////////
// Description: 
// OpCode: 0xfe	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: 
// Written By: Michael
////////////////////
void func_CPI_D8() {

	// Logic for: A - data
	// @TODO [Michael]: fill in logic

	// Set flags: Z, S, P, CY, AC
	func_ClockCycles(7);

	// Inc PC to account for additional size
	func_Inc_PC(1);

}

////////////////////
// Description: 
// OpCode: 0xff	|| Size: 1 bit	|| Clock cycles: 11
// Modifed Flags: No Flags Effected
// Modifed Registers: 
// Written By: Madison
////////////////////
void func_RST_7() {

	// Logic for: CALL $38
	// @TODO [Madison]: fill in logic

	func_ClockCycles(11);

}

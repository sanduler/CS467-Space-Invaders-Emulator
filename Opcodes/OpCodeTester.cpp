#include <stdio.h>
#include <string>
#include "../i8080_struct.h"
#include "OpCodeFunctions.h"

// PRINT VARS
#ifndef PRINT_OPT   
#define PRINT_OPT    1
#endif

// CPU VARIABLES
i8080_CPU i8080_control;                // CPU to compare to 
i8080_CPU i8080;               // CPU to run functions on
i8080_State *cs = &i8080_control.state;

// Test Counters
int incomplete_tests = 0;
int passed_tests = 0;
int failed_tests = 0;
bool test_implemented = true;
bool check_PC = false;      // Used to only check the PC when opcode alters 
                            // it in a obscure way

void setControlTestState();
void setVariableTestState();
bool compareCPUs();
void test_opCode(unsigned char passed_code);
void resetCpu(i8080_CPU *cpu);
void printStates();


int main(int argc, char* argv[])
{
    i8080.state.LoadRomFiles();

    // Call all of the opcodes
    for( int i = 0; i <= 0xff; i++ ) 
    {
        test_implemented = true;
        check_PC = false;

        if (i == 0xc8) {
            i8080.state.flag_Z.set(1);
        }

        if (i == 0xca) {
            i8080.state.flag_Z.set(1);
        }

        if (i == 0xcc) {
            i8080.state.flag_Z.set(1);
        }

        if (i == 0xd8) {
            i8080.state.flag_C.set(1);
        }

        if (i == 0xda) {
            i8080.state.flag_C.set(1);
        }

        if (i == 0xdc) {
            i8080.state.flag_C.set(1);
        }

        if (i == 0xe8) {
            i8080.state.flag_P.set(1);
        }

        if (i == 0xea) {
            i8080.state.flag_P.set(1);
        }

        if (i == 0xec) {
            i8080.state.flag_P.set(1);
        }

        if (i == 0xf8) {
            i8080.state.flag_S.set(1);
        }

        if (i == 0xfa) {
            i8080.state.flag_S.set(1);
        }

        if (i == 0xfc) {
            i8080.state.flag_S.set(1);
        }

        // Send the Op Code to the main switch statement to act on i8080
        eval_opCode(i);

        // Send the Op Code to the test switch statement to act on the control
        test_opCode(i);

        // Only print count as test/fail if the test was implemented
        if (test_implemented) {
            // Compare the results 
            if (compareCPUs()) {
                //if (PRINT_OPT == 1 || PRINT_OPT == 2) {printf( "%04x  PASSED\n", i); }
                passed_tests++;
            } else {
                //if (PRINT_OPT == 1 || PRINT_OPT == 3) {printf( "%04x  FAILED\n", i); }
                failed_tests++;
                //printStates();
            }
        } else if (!compareCPUs()) {
            //if (PRINT_OPT == 1 || PRINT_OPT == 4) {printf( "UNIMPLEMENTED TEST %04x FAILED\n", i);}
        } else {
           //if (PRINT_OPT == 1 || PRINT_OPT == 4) {printf( "UNIMPLEMENTED TEST %04x PASSED\n", i);}
        }

        // Use this to catch a specific opcode to print detail on
        if (i == 0x90) {
            //printStates();
        }
        // Reset both CPUs to their initial testing state
        resetCpu(&i8080);
        resetCpu(&i8080_control);
    }

    //printf("\nSUMMARY: \n");
    //printf("    INCOMPLETE: %d\n", incomplete_tests);
    //printf("    PASSED: %d\n", passed_tests);
    //printf("    FAILED: %d\n", failed_tests);

    return 0;
} 

/*
    Function to reset the CPU
*/
void resetCpu(i8080_CPU *cpu) 
{
    // Flags
    cpu->state.flag_Z.set(0);
    cpu->state.flag_S.set(0);
    cpu->state.flag_P.set(0);
    cpu->state.flag_C.set(0);
    cpu->state.flag_AC.set(0);
    cpu->state.flag_INTE.set(0);

    // DO NOT CHANGE =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    // BC = 0000001000000011
    // HL = 0000011000000111
    // DE = 0000010000000101
    cpu->state.reg_A.set(0b00000001);
    cpu->state.reg_B.set(0b00000010);
    cpu->state.reg_C.set(0b00000011);
    cpu->state.reg_D.set(0b00000100);
    cpu->state.reg_E.set(0b00000101);
    cpu->state.reg_H.set(0b00000110);
    cpu->state.reg_L.set(0b00000111);
    cpu->state.reg_SP.set_Large(0b0000000000001000);
    cpu->state.reg_PC.set_Large(0b0000000000001001);
    cpu->state.reg_PSW.set_Large(0b0000000000001010);
    cpu->state.opCode_Array[0] = 0b00000001;
    cpu->state.opCode_Array[1] = 0b00000010;
    cpu->state.opCode_Array[2] = 0b00000011;

    std::fill(std::begin(cpu->state.mem_Array), std::end(cpu->state.mem_Array), 0);
    // DO NOT CHANGE =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
}

void printStates()
{
    if (cs->flag_Z.get() != i8080.state.flag_Z.get()) 
        printf("        flag_Z  Ctl: %d Var: %d \n", cs->flag_Z.get(), i8080.state.flag_Z.get());
    if (cs->flag_S.get() != i8080.state.flag_S.get()) 
        printf("        flag_S  Ctl: %d Var: %d \n", cs->flag_S.get(), i8080.state.flag_S.get());
    if (cs->flag_P.get() != i8080.state.flag_P.get()) 
        printf("        flag_P  Ctl: %d Var: %d \n", cs->flag_P.get(), i8080.state.flag_P.get());
    if (cs->flag_C.get() != i8080.state.flag_C.get()) 
        printf("        flag_C  Ctl: %d Var: %d \n", cs->flag_C.get(), i8080.state.flag_C.get());
    if (cs->flag_AC.get() != i8080.state.flag_AC.get()) 
        printf("        flag_AC  Ctl: %d Var: %d \n", cs->flag_AC.get(), i8080.state.flag_AC.get());
    if (cs->flag_INTE.get() != i8080.state.flag_INTE.get()) 
        printf("        flag_INTE  Ctl: %d Var: %d \n", cs->flag_INTE.get(), i8080.state.flag_INTE.get());
    if (cs->reg_A.get() != i8080.state.reg_A.get()) 
        printf("        reg_A Ctl: %d Var: %d \n", cs->reg_A.get(), i8080.state.reg_A.get());
    if (cs->reg_B.get() != i8080.state.reg_B.get()) 
        printf("        reg_B Ctl: %d Var: %d \n", cs->reg_B.get(), i8080.state.reg_B.get());
    if (cs->reg_C.get() != i8080.state.reg_C.get()) 
        printf("        reg_C Ctl: %d Var: %d \n", cs->reg_C.get(), i8080.state.reg_C.get());
    if (cs->reg_D.get() != i8080.state.reg_D.get()) 
        printf("        reg_D Ctl: %d Var: %d \n", cs->reg_D.get(), i8080.state.reg_D.get());
    if (cs->reg_E.get() != i8080.state.reg_E.get()) 
        printf("        reg_E Ctl: %d Var: %d \n", cs->reg_E.get(), i8080.state.reg_E.get());
    if (cs->reg_H.get() != i8080.state.reg_H.get()) 
        printf("        reg_H Ctl: %d Var: %d \n", cs->reg_H.get(), i8080.state.reg_H.get());
    if (cs->reg_L.get() != i8080.state.reg_L.get()) 
        printf("        reg_L Ctl: %d Var: %d \n", cs->reg_L.get(), i8080.state.reg_L.get());
    if (cs->reg_SP.get_Large() != i8080.state.reg_SP.get_Large()) 
        printf("        reg_SP Ctl: %d Var: %d \n", cs->reg_SP.get_Large(), i8080.state.reg_SP.get_Large());
    if ((cs->reg_PC.get_Large() != i8080.state.reg_PC.get_Large()) && check_PC) 
        printf("        reg_PC Ctl: %d Var: %d \n", cs->reg_PC.get_Large(), i8080.state.reg_PC.get_Large());
    if (cs->reg_PSW.get() != i8080.state.reg_PSW.get()) 
        printf("        reg_PSW Ctl: %d Var: %d \n", cs->reg_PSW.get(), i8080.state.reg_PSW.get());
    if (i8080_control.state.mem_Array != i8080.state.mem_Array) 
        printf("        Mem Arrays != \n");
}

/*
    Compares the control and variable CPU and returns bool
*/
bool compareCPUs()
{
    bool pc_eq = true;
    // If the PC flag is set then check that
    if (check_PC) {
        if (i8080.state.reg_PC.get_Large() != i8080_control.state.reg_PC.get_Large()) {
            pc_eq = false;
        }
    }

    if(
        // Check the 8 bit register values
        i8080_control.state.reg_A.get() != i8080.state.reg_A.get() ||
        i8080_control.state.reg_B.get() != i8080.state.reg_B.get() ||
        i8080_control.state.reg_C.get() != i8080.state.reg_C.get() ||
        i8080_control.state.reg_D.get() != i8080.state.reg_D.get() ||
        i8080_control.state.reg_E.get() != i8080.state.reg_E.get() ||
        i8080_control.state.reg_H.get() != i8080.state.reg_H.get() ||
        i8080_control.state.reg_L.get() != i8080.state.reg_L.get() ||
        i8080_control.state.reg_PSW.get() != i8080.state.reg_PSW.get() ||
        // Check the 16 bit register values
        i8080_control.state.reg_SP.get_Large() != i8080.state.reg_SP.get_Large() ||
        // Check the flags
        //i8080_control.state.flag_AC.get() != i8080.state.flag_AC.get() ||
        i8080_control.state.flag_C.get() != i8080.state.flag_C.get() ||
        i8080_control.state.flag_P.get() != i8080.state.flag_P.get() ||
        i8080_control.state.flag_S.get() != i8080.state.flag_S.get() ||
        i8080_control.state.flag_Z.get() != i8080.state.flag_Z.get() ||
        i8080_control.state.mem_Array != i8080.state.mem_Array ||
        // Check that the PC flag has not been triggered
        pc_eq == false
    ) 
    {
        return false;
    } else
    {
        return true;
    }
}

void incomplete() {
    //printf("TEST NOT COMPLETE   ");
    incomplete_tests++;
    test_implemented = false;
}

void test_opCode(unsigned char passed_code) {
    switch(passed_code) {
        case 0x00:
            // NOP No Changes
            break;
        case 0x01:
            // B <- byte 3, C <- byte 2
            cs->reg_B.set(0b00000011);
            cs->reg_C.set(0b00000010);
            break;
        case 0x02:
            // (BC) <- A
            cs->set_Memory(0b0000001000000011, 0b00000001);
            break;
        case 0x03:
            // BC <- BC+1
            // BC = 0000001000000011 + 1 = 00000010 00000100
            cs->reg_B.set(0b00000010);
            cs->reg_C.set(0b00000100);
            break;
        case 0x04:
            // B <- B+1
            cs->reg_B.set(0b00000011);            
            cs->flag_P.set(true);
            break;
        case 0x05:
            // B <- B-1
            cs->reg_B.set(0b00000001);
            break;
        case 0x06:
            // B <- byte 2
            cs->reg_B.set(0b00000010);
            break;
        case 0x07:
            // A = A << 1; bit 0 = prev bit 7; CY = prev bit 7
            cs->reg_A.set(0b00000010);
            break;
        case 0x08: 
            // NOP Repeated OpCode
        break;
        case 0x09:
            // HL = HL + BC = 00001000 00001010
            cs->reg_H.set(0b00001000);
            cs->reg_L.set(0x0a);
            break;
        case 0x0a:
            // A <- (BC)
            cs->reg_A.set(0b00000000);
            break;
        case 0x0b:
            // BC = BC-1
            // BC = 0000001000000011 - 1 = 00000010 00000010
            cs->reg_B.set(0b00000010);
            cs->reg_C.set(0b00000010);
            break;
        case 0x0c:
            // C <- C+1
            cs->reg_C.set(0b0000100);
            break;
        case 0x0d:
            // C <-C-1
            cs->reg_C.set(0b00000010);
            break;
        case 0x0e:
            // C <- byte 2
            cs->reg_C.set(0b00000010);
            break;
        case 0x0f:
            // A = A >> 1; bit 7 = prev bit 0; CY = prev bit 0
            cs->reg_A.set(0b10000000);
            cs->flag_C.set(true);
            break;
        case 0x10:
            // NOP Repeated OpCode
        break;
        case 0x11:
            // D <- byte 3, E <- byte 2
            cs->reg_D.set(0b00000011);
            cs->reg_E.set(0b00000010);
            break;
        case 0x12:
            // (DE) <- A
            cs->set_Memory(0b0000010000000101, 0b00000001);
            break;
        case 0x13:
            // DE <- DE + 1
            // DE = 0000010000000101 + 1 = 00000100 00000110
            cs->reg_D.set(0b00000100);
            cs->reg_E.set(0b00000110);
            break;
        case 0x14:
            // D <- D+1
            cs->reg_D.set(0b00000101);
            cs->flag_P.set(true);
            break;
        case 0x15:
            // D <- D-1
            cs->reg_D.set(0b00000011);
            cs->flag_P.set(true);
            break;
        case 0x16:
            // D <- byte 2
            cs->reg_D.set(0b00000010);
            break;
        case 0x17:
            // A = A << 1; bit 0 = prev CY; CY = prev bit 7
            cs->reg_A.set(0b00000010);
            break;
        case 0x18:
            // NOP Repeated OpCode
        break;
        case 0x19:
            // HL = HL + DE = 00001010 00001100
            cs->reg_H.set(0b00001010);
            cs->reg_L.set(0b00001100);
            break;
        case 0x1a:
            // A <- (DE)
            cs->reg_A.set(0b00000000);
            break;
        case 0x1b:
            // DE = DE-1 = 00000100 00000100
            cs->reg_D.set(0b00000100);
            cs->reg_E.set(0b00000100);
            break;
        case 0x1c:
            // E <-E+1
            cs->reg_E.set(0b00000110);
            cs->flag_P.set(true);
            break;
        case 0x1d:
            // E <- E-1
            cs->reg_E.set(0b0000100);
            break;
        case 0x1e:
            // E <- byte 2
            cs->reg_E.set(0b00000010);
            break;
        case 0x1f:
            // A = A >> 1; bit 7 = prev bit 7; CY = prev bit 0
            cs->reg_A.set(0b00000000);
            cs->flag_C.set(true);
            break;
        case 0x20:
            // NOP Repeated OpCode
        break;
        case 0x21:
            // H <- byte 3, L <- byte 2
            cs->reg_H.set(0b00000011);
            cs->reg_L.set(0b00000010);
            break;
        case 0x22:
            // (adr) <-L; (adr+1)<-H
            cs->reg_H.set(0b00000110);
            cs->reg_L.set(0b00000111);
            cs->set_Memory(0b0000001100000010, cs->reg_L.get());
            cs->set_Memory(0b0000001100000011, cs->reg_H.get());
            break;
        case 0x23:
            // HL <- HL + 1 = 00000110 00001000
            cs->reg_H.set(0b00000110);
            cs->reg_L.set(0b00001000);
            break;
        case 0x24:
            // H <- H+1
            cs->reg_H.set(0b00000111);
            break;
        case 0x25:
            // H <- H-1
            cs->reg_H.set(0b00000101);
            cs->flag_P.set(true);
            break;
        case 0x26:
            // L <- byte 2
            cs->reg_H.set(0b00000010);
            break;
        case 0x27:
            // special
            printf("DAA: Not implemented currently, since it is not used\n");
            cs->flag_C.set(false);
            break;
        case 0x28:
            // NOP Repeated OpCode
        break;
        case 0x29:
            // HL = HL + HI = 00001100 00001110  (I think this is a typo and should be HL + HL)
            cs->reg_H.set(0b00001100);
            cs->reg_L.set(0b00001110);
            break;
        case 0x2a:
            // L <- (adr); H<-(adr+1)
            cs->reg_L.set(0x00);
            cs->reg_H.set(0x00);    
            break;
        case 0x2b:
            // HL = HL-1 = 00000110 00000110
            cs->reg_H.set(0b00000110);
            cs->reg_L.set(0b00000110);
            break;
        case 0x2c:
            // L <- L+1
            cs->reg_L.set(0b00001000);
            break;
        case 0x2d:
            // L <- L-1
            cs->reg_L.set(0b00000110);
            cs->flag_P.set(true);
            break;
        case 0x2e:
            // L <- byte 2
            cs->reg_L.set(0b00000010);
            break;
        case 0x2f:
            // A <- !A
            cs->reg_A.set(0b11111110);
            break;
        case 0x30:
            // NOP Repeated OpCode
        break;
        case 0x31:
            // SP.hi <- byte 3, SP.lo <- byte 2
            cs->reg_SP.set_Large(0b0000001100000010);
            break;
        case 0x32:
            // (adr) <- A
            cs->set_Memory(0b0000001000000011, 0b00000001);
            break;
        case 0x33:
            // SP = SP + 1
            cs->reg_SP.set_Large(0b0000000000001001);
            break;
        case 0x34:
            // (HL) <- (HL)+1
            cs->set_Memory(0b0000011000000111, 0x01);
            break;
        case 0x35:
            // (HL) <- (HL)-1
            cs->set_Memory(0b0000011000000111, 0xff);
            break;
        case 0x36:
            // (HL) <- byte 2
            cs->set_Memory(0b0000011000000111, 0b00000010);
            break;
        case 0x37:
            // CY = 1
            cs->flag_C.set(true);
            break;
        case 0x38:
            // NOP Repeated OpCode
        break;
        case 0x39:
            // HL = HL + SP = 00000110 00001111
            cs->reg_H.set(0b00000110);
            cs->reg_L.set(0b00001111);
            break;
        case 0x3a:
            // A <- (adr)
            cs->reg_A.set(0x00);
            break;
        case 0x3b:
            // SP = SP-1
            cs->reg_SP.set_Large(0b0000000000000111);
            break;
        case 0x3c:
            // A <- A+1
            cs->reg_A.set(0b00000010);
            break;
        case 0x3d:
            // A <- A-1
            cs->reg_A.set(0b00000000);
            cs->flag_Z.set(true);
            cs->flag_P.set(true);
            break;
        case 0x3e:
            // A <- byte 2
            cs->reg_A.set(0b00000010);
            break;
        case 0x3f:
            // CY=!CY
            cs->flag_C.set(true);
            break;
        case 0x40:
            // B <- B
            cs->reg_B.set(0b00000010);
            break;
        case 0x41:
            // B <- C
            cs->reg_B.set(0b00000011);
            break;
        case 0x42:
            // B <- D
            cs->reg_B.set(0b00000100);
            break;
        case 0x43:
            // B <- E
            cs->reg_B.set(0b00000101);
            break;
        case 0x44:
            // B <- H
            cs->reg_B.set(0b00000110);
            break;
        case 0x45:
            // B <- L
            cs->reg_B.set(0b00000111);
            break;
        case 0x46:
            // B <- (HL)
            cs->reg_B.set(0b00000000);
            break;
        case 0x47:
            // B <- A
            cs->reg_B.set(0b00000001);
            break;
        case 0x48:
            // C <- B
            cs->reg_C.set(0b00000010);
            break;
        case 0x49:
            // C <- C
            cs->reg_C.set(0b00000011);
            break;
        case 0x4a:
            // C <- D
            cs->reg_C.set(0b00000100);
            break;
        case 0x4b:
            // C <- E
            cs->reg_C.set(0b00000101);
            break;
        case 0x4c:
            // C <- H
            cs->reg_C.set(0b00000110);
            break;
        case 0x4d:
            // C <- L
            cs->reg_C.set(0b00000111);
            break;
        case 0x4e:
            // C <- (HL)
            cs->reg_C.set(0b00000000);
            break;
        case 0x4f:
            // C <- A
            cs->reg_C.set(0b00000001);
            break;
        case 0x50:
            // D <- B
            cs->reg_D.set(0b00000010);
            break;
        case 0x51:
            // D <- C
            cs->reg_D.set(0b00000011);
            break;
        case 0x52:
            // D <- D
            cs->reg_D.set(0b00000100);
            break;
        case 0x53:
            // D <- E
            cs->reg_D.set(0b00000101);
            break;
        case 0x54:
            // D <- H
            cs->reg_D.set(0b00000110);
            break;
        case 0x55:
            // D <- L
            cs->reg_D.set(0b00000111);
            break;
        case 0x56:
            // D <- (HL)
            cs->reg_D.set(0b00000000);
            break;
        case 0x57:
            // D <- A
            cs->reg_D.set(0b00000001);
            break;
        case 0x58:
            // E <- B
            cs->reg_E.set(0b00000010);
            break;
        case 0x59:
            // E <- C
            cs->reg_E.set(0b00000011);
            break;
        case 0x5a:
            // E <- D
            cs->reg_E.set(0b00000100);
            break;
        case 0x5b:
            // E <- E
            cs->reg_E.set(0b00000101);
            break;
        case 0x5c:
            // E <- H
            cs->reg_E.set(0b00000110);
            break;
        case 0x5d:
            // E <- L
            cs->reg_E.set(0b00000111);
            break;
        case 0x5e:
            // E <- (HL)
            cs->reg_E.set(0b00000000);
            break;
        case 0x5f:
            // E <- A
            cs->reg_E.set(0b00000001);
            break;
        case 0x60:
            // H <- B
            cs->reg_H.set(0b00000010);
            break;
        case 0x61:
            // H <- C
            cs->reg_H.set(0b00000011);
            break;
        case 0x62:
            // H <- D
            cs->reg_H.set(0b00000100);
            break;
        case 0x63:
            // H <- E
            cs->reg_H.set(0b00000101);
            break;
        case 0x64:
            // H <- H
            cs->reg_H.set(0b00000110);
            break;
        case 0x65:
            // H <- L
            cs->reg_H.set(0b00000111);
            break;
        case 0x66:
            // H <- (HL)
            cs->reg_H.set(0b00000000);
            break;
        case 0x67:
            // H <- A
            cs->reg_H.set(0b00000001);
            break;
        case 0x68:
            // L <- B
            cs->reg_L.set(0b00000010);
            break;
        case 0x69:
            // L <- C
            cs->reg_L.set(0b00000011);
            break;
        case 0x6a:
            // L <- D
            cs->reg_L.set(0b00000100);
            break;
        case 0x6b:
            // L <- E
            cs->reg_L.set(0b00000101);
            break;
        case 0x6c:
            // L <- H
            cs->reg_L.set(0b00000110);
            break;
        case 0x6d:
            // L <- L
            cs->reg_L.set(0b00000111);
            break;
        case 0x6e:
            // L <- (HL)
            cs->reg_L.set(0b00000000);
            break;
        case 0x6f:
            // L <- A
            cs->reg_L.set(0b00000001);
            break;
        case 0x70:
            // (HL) <- B
            cs->set_Memory(0b0000011000000111, 0b00000010);
            break;
        case 0x71:
            // (HL) <- C
            cs->set_Memory(0b0000011000000111, 0b00000011);
            break;
        case 0x72:
            // (HL) <- D
            cs->set_Memory(0b0000011000000111, 0b00000100);
            break;
        case 0x73:
            // (HL) <- E
            cs->set_Memory(0b0000011000000111, 0b00000101);
            break;
        case 0x74:
            // (HL) <- H
            cs->set_Memory(0b0000011000000111, 0b00000110);
            break;
        case 0x75:
            // (HL) <- L
            cs->set_Memory(0b0000011000000111, 0b00000111);
            break;
        case 0x76:
            // special
            // HALT
            break;
        case 0x77:
            // (HL) <- C
            cs->set_Memory(0b0000011000000111, 0b00000011);
            break;
        case 0x78:
            // A <- B
            cs->reg_A.set(0b00000010);
            break;
        case 0x79:
            // A <- C
            cs->reg_A.set(0b00000011);
            break;
        case 0x7a:
            // A <- D
            cs->reg_A.set(0b00000100);
            break;
        case 0x7b:
            // A <- E
            cs->reg_A.set(0b00000101);
            break;
        case 0x7c:
            // A <- H
            cs->reg_A.set(0b00000110);
            break;
        case 0x7d:
            // A <- L
            cs->reg_A.set(0b00000111);
            break;
        case 0x7e:
            // A <- (HL)
            cs->reg_A.set(0b00000000);
            break;
        case 0x7f:
            // A <- A
            cs->reg_A.set(0b00000001);
            break;
        case 0x80:
            // A <- A + B 
            cs->reg_A.set(0b00000011);
            cs->flag_P.set(true);
            break;
        case 0x81:
            // A <- A + C
            cs->reg_A.set(0b00000100);
            break;
        case 0x82:
            // A <- A + D
            cs->reg_A.set(0b00000101);
            cs->flag_P.set(true);
            break;
        case 0x83:
            // A <- A + E
            cs->reg_A.set(0b00000110);
            cs->flag_P.set(true);
            break;
        case 0x84:
            // A <- A + H
            cs->reg_A.set(0b00000111);
            break;
        case 0x85:
            // A <- A + L
            cs->reg_A.set(0b00001000);
            break;
        case 0x86:
            // A <- A + (HL)
            cs->reg_A.set(0b00000001);
            break;
        case 0x87:
            // A <- A + A
            cs->reg_A.set(0b00000010);
            break;
        case 0x88:
            // A <- A + B + CY
            cs->reg_A.set(0b00000011);
            cs->flag_P.set(true);
            break;
        case 0x89:
            // A <- A + C + CY
            cs->reg_A.set(0b00000100);
            break;
        case 0x8a:
            // A <- A + D + CY
            cs->reg_A.set(0b00000101);
            cs->flag_P.set(true);
            break;
        case 0x8b:
            // A <- A + E + CY
            cs->reg_A.set(0b00000110);
            cs->flag_P.set(true);
            break;
        case 0x8c:
            // A <- A + H + CY
            cs->reg_A.set(0b00000111);
            break;
        case 0x8d:
            // A <- A + L + CY
            cs->reg_A.set(0b00001000);
            break;
        case 0x8e:
            // A <- A + (HL) + CY
            cs->reg_A.set(0b00000001);
            break;
        case 0x8f:
            // A <- A + A + CY
            cs->reg_A.set(0b00000010);
            break;
        case 0x90:
            // A <- A - B 
            cs->reg_A.set(0b11111111);
            cs->flag_P.set(true);
            cs->flag_S.set(true);
            cs->flag_C.set(true);
            break;
        case 0x91:
            // A <- A - C = 00000001 + 11111101
            cs->reg_A.set(0b11111110);
            cs->flag_C.set(true);
            cs->flag_S.set(true);
            break;
        case 0x92:
            // A <- A - D = 00000001 + 11111100
            cs->reg_A.set(0b11111101);
            cs->flag_C.set(true);
            cs->flag_S.set(true);
            break;
        case 0x93:
            // A <- A - E
            cs->reg_A.set(0b11111100);
            cs->flag_C.set(true);
            cs->flag_S.set(true);
            cs->flag_P.set(true);
            break;
        case 0x94:
            // A <- A - H
            cs->reg_A.set(0b11111011);
            cs->flag_S.set(true);
            cs->flag_C.set(true);
            break;
        case 0x95:
            // A <- A - L
            cs->reg_A.set(0b11111010);
            cs->flag_S.set(true);
            cs->flag_C.set(true);
            cs->flag_P.set(true);
            break;
        case 0x96:
            // A <- A - (HL)
            cs->flag_C.set(true);
            break;
        case 0x97:
            // A <- A - A
            cs->reg_A.set(0b00000000);
            cs->flag_Z.set(true);
            cs->flag_P.set(true);
            break;
        case 0x98:
            // A <- A - B - CY
            cs->reg_A.set(0xff);
            cs->flag_S.set(true);
            cs->flag_C.set(true);
            cs->flag_P.set(true);
            break;
        case 0x99:
            // A <- A - C - CY
            cs->reg_A.set(0xfe);
            cs->flag_S.set(true);
            cs->flag_C.set(true);
            break;
        case 0x9a:
            // A <- A - D - CY
            cs->reg_A.set(0xfd);
            cs->flag_S.set(true);
            cs->flag_C.set(true);
            break;
        case 0x9b:
            // A <- A - E - CY
            cs->reg_A.set(0xfc);
            cs->flag_S.set(true);
            cs->flag_C.set(true);
            cs->flag_P.set(true);
            break;
        case 0x9c:
            // A <- A - H - CY
            cs->reg_A.set(0xfb);
            cs->flag_S.set(true);
            cs->flag_C.set(true);
            break;
        case 0x9d:
            // A <- A - L - CY
            cs->reg_A.set(0xfa);
            cs->flag_S.set(true);
            cs->flag_C.set(true);
            cs->flag_P.set(true);
            break;
        case 0x9e:
            // A <- A - (HL) - CY
            cs->flag_C.set(true);
            break;
        case 0x9f:
            // A <- A - A - CY
            cs->reg_A.set(0x00);
            cs->flag_S.set(false);
            cs->flag_Z.set(true);
            cs->flag_P.set(true);
            break;
        case 0xa0:
            // A <- A & B
            cs->reg_A.set(0x00);
            cs->flag_Z.set(true);
            cs->flag_P.set(true);
            break;
        case 0xa1:
            // A <- A & C
            cs->reg_A.set(0x01);
            cs->flag_Z.set(false);
            cs->flag_P.set(false);
            break;
        case 0xa2:
            // A <- A & D
            cs->reg_A.set(0x00);
            cs->flag_Z.set(true);
            cs->flag_P.set(true);
            break;
        case 0xa3:
            // A <- A & E
            cs->reg_A.set(0x01);
            cs->flag_Z.set(false);
            cs->flag_P.set(false);
            break;
        case 0xa4:
            // A <- A & H
            cs->reg_A.set(0x00);
            cs->flag_Z.set(true);
            cs->flag_P.set(true);
            break;
        case 0xa5:
            // A <- A & L
            cs->reg_A.set(0x01);
            cs->flag_Z.set(false);
            cs->flag_P.set(false);
            break;
        case 0xa6:
            // A <- A & (HL)
            cs->reg_A.set(0x00);
            cs->flag_Z.set(true);
            cs->flag_P.set(true);
            break;
        case 0xa7:
            // A <- A & A
            cs->reg_A.set(0x01);
            cs->flag_Z.set(false);
            cs->flag_P.set(false);
            break;
        case 0xa8:
            // A <- A ^ B
            cs->reg_A.set(0x03);
            cs->flag_P.set(true);
            break;
        case 0xa9:
            // A <- A ^ C
            cs->reg_A.set(0x02);
            break;
        case 0xaa:
            // A <- A ^ D
            cs->reg_A.set(0x05);
            cs->flag_P.set(true);
            break;
        case 0xab:
            // A <- A ^ E
            cs->reg_A.set(0x04);
            break;
        case 0xac:
            // A <- A ^ H
            cs->reg_A.set(0x07);
            break;
        case 0xad:
            // A <- A ^ L
            cs->reg_A.set(0x06);
            cs->flag_P.set(true);
            break;
        case 0xae:
            // A <- A ^ (HL)
            cs->reg_A.set(0x01);
            cs->flag_P.set(false);
            cs->flag_Z.set(false);
            break;
        case 0xaf:
            // A <- A ^ A
            cs->reg_A.set(0x00);
            cs->flag_P.set(true);
            cs->flag_Z.set(true);
            break;
        case 0xb0:
            // A <- A | B
            cs->reg_A.set(0x03);
            cs->flag_P.set(true);
            break;
        case 0xb1:
            // A <- A | C
            cs->reg_A.set(0x03);
            cs->flag_P.set(true);
            break;
        case 0xb2:
            // A <- A | D
            cs->reg_A.set(0x05);
            cs->flag_P.set(true);
            break;
        case 0xb3:
            // A <- A | E
            cs->reg_A.set(0x05);
            cs->flag_P.set(true);
            break;
        case 0xb4:
            // A <- A | H
            cs->reg_A.set(0x07);
            break;
        case 0xb5:
            // A <- A | L
            cs->reg_A.set(0x07);
            break;
        case 0xb6:
            // A <- A | (HL)
            cs->reg_A.set(0x01);
            cs->flag_Z.set(false);
            cs->flag_P.set(false);
            break;
        case 0xb7:
            // A <- A | A
            cs->reg_A.set(0x01);
            cs->flag_Z.set(false);
            cs->flag_P.set(false);
            break;
        case 0xb8:
            // A - B
            cs->flag_S.set(true);
            cs->flag_P.set(true);
            cs->flag_C.set(true);
            break;
        case 0xb9:
            // A - C
            cs->flag_S.set(true);
            cs->flag_C.set(true);
            break;
        case 0xba:
            // A - D
            cs->flag_S.set(true);
            cs->flag_C.set(true);
            break;
        case 0xbb:
            // A - E
            cs->flag_S.set(true);
            cs->flag_P.set(true);
            cs->flag_C.set(true);
            break;
        case 0xbc:
            // A - H
            cs->flag_S.set(true);
            cs->flag_C.set(true);
            break;
        case 0xbd:
            // A - L
            cs->flag_S.set(true);
            cs->flag_P.set(true);
            cs->flag_C.set(true);
            break;
        case 0xbe:
            // A - (HL)
            cs->flag_C.set(true);
            break;
        case 0xbf:
            // A - A
            cs->flag_P.set(true);
            cs->flag_Z.set(true);
            break;
        case 0xc0:
            // if NZ, RET
            cs->reg_SP.set_Large(0b0000000000001010);
            break;
        case 0xc1:
            // C <- (sp); B <- (sp+1); sp <- sp+2
            cs->reg_C.set(0x00);
            cs->reg_B.set(0x00);
            cs->reg_SP.set_Large(0b0000000000001010);
            break;
        case 0xc2:
            // if NZ, PC <- adr
            check_PC = true;
            cs->reg_PC.set_Large(0b0000001100000010);
            break;
        case 0xc3:
            // PC <= adr
            check_PC = true;
            cs->reg_PC.set_Large( 0b0000001000000011);
            break;
        case 0xc4:
            // if NZ, CALL adr
            cs->reg_SP.set_Large(0b0000000000001000);

            cs->set_Memory((cs->reg_SP.get_Large() - 1), (cs->reg_PC.get_Large() >> 8));
            cs->set_Memory((cs->reg_SP.get_Large() - 2), (cs->reg_PC.get_Large()));
            cs->reg_SP.set_Large(0b0000000000000110);

            cs->reg_PC.set_Large((cs->opCode_Array[1] >> 8) + (cs->opCode_Array[2]) );
            break;
        case 0xc5:
            // (sp-2)<-C; (sp-1)<-B; sp <- sp - 2
            cs->set_Memory(0b00000110, 0b00000011);
            cs->set_Memory(0b00000111, 0b00000010);
            cs->reg_SP.set_Large(0b00000110);
            break;
        case 0xc6:
            // A <- A + byte
            cs->reg_A.set(0b00000011);
            break;
        case 0xc7:
            // CALL $0
            check_PC = true;
            cs->set_Memory(0b00000111, 0b00000000);
            cs->set_Memory(0b00000110, 0b00001001);
            cs->reg_SP.set_Large( 0b0000000000000110);
            cs->reg_PC.set_Large( 0b0000000000000000);
            break;
        case 0xc8:
            // if Z, RET
            cs->flag_Z.set(true);
            cs->reg_SP.set_Large( 0b0000000000001010);
            cs->reg_PC.set_Large( 0b0000000000000000);
            break;
        case 0xc9:
            // PC.lo <- (sp); PC.hi<-(sp+1); SP <- SP+2
            cs->reg_PC.set_Large(0b0000000000000000);
            cs->reg_SP.set_Large(0b0000000000001010);
            break;
        case 0xca:
            // if Z, PC <- adr
            cs->flag_Z.set(true);
            cs->reg_PC.set_Large(0b0000000000000000);
            cs->reg_SP.set_Large(0b0000000000001000);
            break;
        case 0xcb: break;        // NOT IMPLEMENTED
        case 0xcc:
            // if Z, CALL adr
            
            cs->flag_Z.set(1);


            cs->reg_SP.set_Large(0b0000000000001000);

            cs->set_Memory((cs->reg_SP.get_Large() - 1), (cs->reg_PC.get_Large() >> 8));
            cs->set_Memory((cs->reg_SP.get_Large() - 2), (cs->reg_PC.get_Large()));
            cs->reg_SP.set_Large(0b0000000000000110);

            cs->reg_PC.set_Large((cs->opCode_Array[1] >> 8) + (cs->opCode_Array[2]) );
            break;
        case 0xcd:
            // (SP-1)<-PC.hi;(SP-2)<-PC.lo;SP<-SP+2;PC=adr
            cs->set_Memory(0b00000111, 0b00000000);
            cs->set_Memory(0b00000110, 0b00001001);
            cs->reg_SP.set_Large(0b0000000000000110);
            check_PC = true;
            cs->reg_PC.set_Large(0b0000001100000010);
            break;
        case 0xce:
            // A <- A + data + CY
            cs->reg_A.set(0b00000011);
            cs->flag_P.set(true);
            break;
        case 0xcf:
            // CALL $8
            check_PC = true;
            cs->set_Memory(0b00000111, 0b00000000);
            cs->set_Memory(0b00000110, 0b00001001);
            cs->reg_SP.set_Large( 0b0000000000000110);
            cs->reg_PC.set_Large( 0b0000000000001000);
            break;
        case 0xd0:
            // if NCY, RET
            cs->reg_SP.set_Large( 0b0000000000001010);
            break;
        case 0xd1:
            // E <- (sp); D <- (sp+1); sp <- sp+2
            cs->reg_E.set(0x00);
            cs->reg_D.set(0x00);
            cs->reg_SP.set_Large(0b0000000000001010);
            break;
        case 0xd2:
            // if NCY, PC<-adr
            check_PC = true;
            cs->reg_PC.set_Large(0b0000001100000010);
            break;
        case 0xd3:
            // special
            incomplete();
            break;
        case 0xd4:
            // if NCY, CALL adr
            cs->reg_SP.set_Large(0b0000000000001000);

            cs->set_Memory((cs->reg_SP.get_Large() - 1), (cs->reg_PC.get_Large() >> 8));
            cs->set_Memory((cs->reg_SP.get_Large() - 2), (cs->reg_PC.get_Large()));
            cs->reg_SP.set_Large(0b0000000000000110);

            cs->reg_PC.set_Large((cs->opCode_Array[1] >> 8) + (cs->opCode_Array[2]) );

            break;
        case 0xd5:
            // (sp-2)<-E; (sp-1)<-D; sp <- sp - 2
            cs->set_Memory(0x06, 0b00000101);
            cs->set_Memory(0x07, 0b00000100);
            cs->reg_SP.set_Large(0x06);
            break;
        case 0xd6:
            // A <- A - data
            cs->reg_A.set(0b11111111);
            cs->flag_P.set(true);
            cs->flag_S.set(true);
            cs->flag_C.set(true);
            break;
        case 0xd7:
            // CALL $10
            check_PC = true;
            cs->set_Memory(0b00000111, 0b00000000);
            cs->set_Memory(0b00000110, 0b00001001);
            cs->reg_SP.set_Large( 0b0000000000000110);
            cs->reg_PC.set_Large( 0b0000000000010000);
            break;
        case 0xd8:
            // if CY, RET
            cs->flag_C.set(1);
            cs->reg_SP.set_Large( 0b0000000000001010);
            break;
        case 0xd9:
        // PC.lo <- (sp); PC.hi<-(sp+1); SP <- SP+2
            cs->reg_PC.set_Large(0b0000000000000000);
            cs->reg_SP.set_Large(0b0000000000001010);
        break;
        case 0xda:
            // if CY, PC<-adr
            check_PC = true;
            cs->flag_C.set(1);
            cs->reg_PC.set_Large(0b0000001100000010);
            break;
        case 0xdb:
            // special
            incomplete();
            break;
        case 0xdc:
            // if CY, CALL adr
            cs->flag_C.set(1);


            cs->reg_SP.set_Large(0b0000000000001000);

            cs->set_Memory((cs->reg_SP.get_Large() - 1), (cs->reg_PC.get_Large() >> 8));
            cs->set_Memory((cs->reg_SP.get_Large() - 2), (cs->reg_PC.get_Large()));
            cs->reg_SP.set_Large(0b0000000000000110);

            cs->reg_PC.set_Large((cs->opCode_Array[1] >> 8) + (cs->opCode_Array[2]) );
            break;
        case 0xdd:
            // (SP-1)<-PC.hi;(SP-2)<-PC.lo;SP<-SP+2;PC=adr
            cs->set_Memory(0b00000111, 0b00000000);
            cs->set_Memory(0b00000110, 0b00001001);
            cs->reg_SP.set_Large(0b0000000000000110);
            check_PC = true;
            cs->reg_PC.set_Large(0b0000001100000010);
        break;
        case 0xde:
            // A <- A - data - CY
            cs->reg_A.set(0xff);
            cs->flag_S.set(true);
            cs->flag_C.set(true);
            cs->flag_P.set(true);
            break;
        case 0xdf:
            // CALL $18
            check_PC = true;
            cs->set_Memory(0b00000111, 0b00000000);
            cs->set_Memory(0b00000110, 0b00001001);
            cs->reg_SP.set_Large( 0b0000000000000110);
            cs->reg_PC.set_Large( 0b0000000000011000);
            break;
        case 0xe0:
            // if PO, RET
            cs->reg_SP.set_Large( 0b0000000000001010);
            break;
        case 0xe1:
            // L <- (sp); H <- (sp+1); sp <- sp+2
            cs->reg_L.set(0x00);
            cs->reg_H.set(0x00);
            cs->reg_SP.set_Large(0b0000000000001010);
            break;
        case 0xe2:
            // if PO, PC <- adr
            check_PC = true;
            cs->reg_PC.set_Large(0b0000001100000010);
            break;
        case 0xe3:
            // L <-> (SP); H <-> (SP+1)
            cs->reg_SP.set_Large(0b0000000000001000);

            cs->set_Memory(cs->reg_SP.get_Large(), cs->reg_L.get());
            cs->set_Memory((cs->reg_SP.get_Large() + 1), cs->reg_H.get());
            cs->reg_H.set(0x00);
            cs->reg_L.set(0x00);
            cs->reg_SP.set_Large(0b0000000000001010);
            
            break;
        case 0xe4:
            // if PO, CALL adr
            cs->reg_SP.set_Large(0b0000000000001000);

            cs->set_Memory((cs->reg_SP.get_Large() - 1), (cs->reg_PC.get_Large() >> 8));
            cs->set_Memory((cs->reg_SP.get_Large() - 2), (cs->reg_PC.get_Large()));
            cs->reg_SP.set_Large(0b0000000000000110);

            cs->reg_PC.set_Large((cs->opCode_Array[1] >> 8) + (cs->opCode_Array[2]) );
            break;
        case 0xe5:
            // (sp-2)<-L; (sp-1)<-H; sp <- sp - 2
            cs->set_Memory(0b00000110, 0b00000111);
            cs->set_Memory(0b00000111, 0b00000110);
            cs->reg_SP.set_Large(0b0000000000000110);
            break;
        case 0xe6:
            // A <- A & data
            cs->reg_A.set(0x00);
            cs->flag_Z.set(true);
            cs->flag_P.set(true);
            break;
        case 0xe7:
            // CALL $20
            check_PC = true;
            cs->set_Memory(0b00000111, 0b00000000);
            cs->set_Memory(0b00000110, 0b00001001);
            cs->reg_SP.set_Large( 0b0000000000000110);
            cs->reg_PC.set_Large( 0b0000000000100000);
            break;
        case 0xe8:
            // if PE, RET
            cs->flag_P.set(1);
            cs->reg_SP.set_Large( 0b0000000000001010);
            break;
        case 0xe9:
            // PC.hi <- H; PC.lo <- L
            cs->reg_PC.set_Large(0b0000011000000111);
            break;
        case 0xea:
            // if PE, PC <- adr
            check_PC = true;
            cs->flag_P.set(true);
            cs->reg_PC.set_Large(0b0000001100000010);
            break;
        case 0xeb:
            // H <-> D; L <-> E
            cs->reg_H.set(0b00000100);
            cs->reg_D.set(0b00000110);
            cs->reg_L.set(0b00000101);
            cs->reg_E.set(0b00000111);
            break;
        case 0xec:
            // if PE, CALL adr
            cs->flag_P.set(1);


            cs->reg_SP.set_Large(0b0000000000001000);

            cs->set_Memory((cs->reg_SP.get_Large() - 1), (cs->reg_PC.get_Large() >> 8));
            cs->set_Memory((cs->reg_SP.get_Large() - 2), (cs->reg_PC.get_Large()));
            cs->reg_SP.set_Large(0b0000000000000110);

            cs->reg_PC.set_Large((cs->opCode_Array[1] >> 8) + (cs->opCode_Array[2]) );
            break;
        case 0xed:
            // (SP-1)<-PC.hi;(SP-2)<-PC.lo;SP<-SP+2;PC=adr
            cs->set_Memory(0b00000111, 0b00000000);
            cs->set_Memory(0b00000110, 0b00001001);
            cs->reg_SP.set_Large(0b0000000000000110);
            check_PC = true;
            cs->reg_PC.set_Large(0b0000001100000010);
        break;
        case 0xee:
            // A <- A ^ data
            cs->reg_A.set(0x03);
            cs->flag_P.set(true);
            break;
        case 0xef:
            // CALL $28
            check_PC = true;
            cs->set_Memory(0b00000111, 0b00000000);
            cs->set_Memory(0b00000110, 0b00001001);
            cs->reg_SP.set_Large( 0b0000000000000110);
            cs->reg_PC.set_Large( 0b0000000000101000);
            break;
        case 0xf0:
            // if P, RET
            cs->reg_SP.set_Large( 0b0000000000001010);
            break;
        case 0xf1:
            // flags <- (sp); A <- (sp+1); sp <- sp+2
            cs->reg_A.set(0x00);
            cs->reg_SP.set_Large(0b0000000000001010);
            cs->flag_P.set(false);
            break;
        case 0xf2:
            // if P=1 PC <- adr
            check_PC = true;
            cs->reg_PC.set_Large(0b0000001100000010);
            break;
        case 0xf3:
            // special
            incomplete();
            break;
        case 0xf4:
            // if P, PC <- adr
            cs->reg_SP.set_Large(0b0000000000001000);

            cs->set_Memory((cs->reg_SP.get_Large() - 1), (cs->reg_PC.get_Large() >> 8));
            cs->set_Memory((cs->reg_SP.get_Large() - 2), (cs->reg_PC.get_Large()));
            cs->reg_SP.set_Large(0b0000000000000110);

            cs->reg_PC.set_Large((cs->opCode_Array[1] >> 8) + (cs->opCode_Array[2]) );
            break;
        case 0xf5:
            // (sp-2)<-flags; (sp-1)<-A; sp <- sp - 2
            cs->reg_SP.set_Large(0b0000000000001000);
            cs->set_Memory((cs->reg_SP.get_Large() - 1), 0b00000001);
            cs->set_Memory((cs->reg_SP.get_Large() - 2), 0b00000000);
            cs->reg_SP.set_Large(0b0000000000000110);
            break;
        case 0xf6:
            // A <- A | data
            cs->reg_A.set(0x03);
            cs->flag_P.set(true);
            break;
        case 0xf7:
            // CALL $30
            check_PC = true;
            cs->set_Memory(0b00000111, 0b00000000);
            cs->set_Memory(0b00000110, 0b00001001);
            cs->reg_SP.set_Large( 0b0000000000000110);
            cs->reg_PC.set_Large( 0b0000000000110000);
            break;
        case 0xf8:
            // if M, RET
            cs->flag_S.set(1);
            cs->reg_SP.set_Large( 0b0000000000001010);
            break;
        case 0xf9:
            // SP=HL
            cs->reg_SP.set_Large(0b0000011000000111);
            break;
        case 0xfa:
            // if M, PC <- adr
            check_PC = true;
            cs->flag_S.set(true);
            cs->reg_PC.set_Large(0b0000001100000010);
            break;
        case 0xfb:
            // special
            incomplete();
            break;
        case 0xfc:
            // if M, CALL adr
            cs->flag_S.set(1);


            cs->reg_SP.set_Large(0b0000000000001000);

            cs->set_Memory((cs->reg_SP.get_Large() - 1), (cs->reg_PC.get_Large() >> 8));
            cs->set_Memory((cs->reg_SP.get_Large() - 2), (cs->reg_PC.get_Large()));
            cs->reg_SP.set_Large(0b0000000000000110);

            cs->reg_PC.set_Large((cs->opCode_Array[1] >> 8) + (cs->opCode_Array[2]) );
            break;
        case 0xfd:
            // (SP-1)<-PC.hi;(SP-2)<-PC.lo;SP<-SP+2;PC=adr
            cs->set_Memory(0b00000111, 0b00000000);
            cs->set_Memory(0b00000110, 0b00001001);
            cs->reg_SP.set_Large(0b0000000000000110);
            check_PC = true;
            cs->reg_PC.set_Large(0b0000001100000010);
        break;
        case 0xfe:
            // A - data
            cs->flag_S.set(true);
            cs->flag_P.set(true);
            cs->flag_C.set(true);
            break;
        case 0xff:
            // CALL $38
            check_PC = true;
            cs->set_Memory(0b00000111, 0b00000000);
            cs->set_Memory(0b00000110, 0b00001001);
            cs->reg_SP.set_Large( 0b0000000000000110);
            cs->reg_PC.set_Large( 0b0000000000111000);
            break;
    }
}
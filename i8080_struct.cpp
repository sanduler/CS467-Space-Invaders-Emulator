/*********************************
 * i8080 Emulator
 * - Flags Class
 * - Register Class
 * - State Class
 * - i8080 Class
 ********************************/

#include "i8080_struct.h"
#include <iostream>
#include <cstdint>
#include <cstring>
#include <fstream>
using namespace  std;

void i8080_Flag::set(bool new_val)
{
    val = new_val;
}

bool i8080_Flag::get()
{
    return val;
}

uint16_t i8080_Register::get_Large()
{
    return large_val;
}

uint8_t i8080_Register::get()
{
    return val;
}

void i8080_Register::set(uint8_t i)
{
    val = i;
}

void i8080_Register::set_Large(uint16_t i)
{
    large_val = i;
}

i8080_State::i8080_State()
{

    //cout << "Constructor: State has been initilized...." << endl;
    clock_cycles = 0;

    // Set Flags
    flag_Z.set(0);
    flag_S.set(0);
    flag_P.set(0);
    flag_C.set(0);
    flag_AC.set(0);

    //set registers
    reg_A.set(0);
    reg_B.set(0);
    reg_C.set(0);
    reg_D.set(0);
    reg_E.set(0);
    reg_H.set(0);
    reg_L.set(0);
    reg_SP.set_Large(0);
    reg_PC.set_Large(0);
    reg_PSW.set(0);

    // Initialize arrays
    mem_Array = (uint8_t*)malloc(0x10000);
    video_RAM = (uint8_t*)malloc(224 * 256 * 4 * sizeof(video_RAM));

    // Inputs
    inputs[255] = { 0 };

    // Ouputs
    outputs[255] = { 0 };

    // Shift Register
    shiftRegister = 0x0000;

}

void i8080_State::SendInterrupt(int itr_num)
{
    // first check if interuppts are enabled, only act if they are
    if (flag_INTE.get()) {
        //perform "PUSH PC"    
        //uint16_t sp_addr;
        //sp_addr = reg_SP.get_Large();
        //set_Memory(sp_addr - 1, reg_PC.get_Large() & 0xFF00 >> 8);
        //set_Memory(sp_addr - 2, reg_PC.get_Large() & 0xff);
        //reg_SP.set_Large(sp_addr - 2);

        // Break the Program Counter into two bytes so that it can be stored in memory.
        uint16_t uint16_InitialSP = reg_SP.get_Large();
        uint16_t uint16_InitialPC = reg_PC.get_Large();
        uint8_t uint8_PCAddrLow = 0x00;
        uint8_t uint8_PCAddrHigh = 0x00;
        //printf("PC: %4X\n", uint16_InitialPC);
        //printf("SP: %4X\n", uint16_InitialSP);
        uint8_PCAddrLow = uint8_PCAddrLow | uint16_InitialPC;
        uint8_PCAddrHigh = uint8_PCAddrHigh | (uint16_InitialPC >> 8);
        //printf("PCLow: %4X\n", uint8_PCAddrLow);
        //printf("PCHigh: %4X\n", uint8_PCAddrHigh);
        // Push the Program Counter to memory where the Stack Pointer - 1 and Stack Pointer - 2 point
        set_Memory((uint16_InitialSP - 0x01), uint8_PCAddrHigh);
        set_Memory((uint16_InitialSP - 0x02), uint8_PCAddrLow);

        // The Stack Pointer is updated
        reg_SP.set_Large(uint16_InitialSP - 0x02);



        //Set the PC to the low memory vector.    
        //This is identical to an "RST interrupt_num" instruction.
        switch (itr_num)
        {
        case 0x00: reg_PC.set_Large(0x0000);
        case 0x01: reg_PC.set_Large(0x0008);
        case 0x02: reg_PC.set_Large(0x0010);
        case 0x03: reg_PC.set_Large(0x0018);
        case 0x04: reg_PC.set_Large(0x0020);
        case 0x05: reg_PC.set_Large(0x0028);
        case 0x06: reg_PC.set_Large(0x0030);
        case 0x07: reg_PC.set_Large(0x0038);


        }
        

        // reset the int enable bit
        flag_INTE.set(0);
    }

}

uint8_t i8080_State::get_Memory(uint16_t index)
{
    return mem_Array[index];
}

void i8080_State::set_Memory(uint16_t index, uint8_t val)
{
    mem_Array[index] = val;
}

uint16_t i8080_State::get_BC() 
{
    return (reg_B.get() << 8) | reg_C.get();
}

uint16_t i8080_State::get_HL()
{
    return (reg_H.get() << 8) | reg_L.get();
}

uint16_t i8080_State::get_DE()
{
    return (reg_D.get() << 8) | reg_E.get();
}

uint16_t i8080_State::get_Adr()
{
    // MM-Modified this from [1] to [2] first according to i8080 Manual for JMP
    uint16_t uint16_AddrTemp = 0x0000;
    uint16_AddrTemp = uint16_AddrTemp | opCode_Array[2];
    uint16_AddrTemp = uint16_AddrTemp << 8;
    uint16_AddrTemp = uint16_AddrTemp | opCode_Array[1];
    return uint16_AddrTemp;      //(opCode_Array[2] << 8) | opCode_Array[1];
}

uint8_t i8080_State::get_M()
{
    return get_Memory(get_HL());
}

void i8080_State::set_M(uint8_t val)
{
    set_Memory(get_HL(), val);
}

void i8080_State::move_right()
{
    // Handle user input to move right
    printf("MOVE RIGHT\n");
}

void i8080_State::move_left()
{
    // Handle user input to move left 
    printf("MOVE LEFT\n");
}

void i8080_State::insert_coin()
{
    // Handle user input to insert coin
    printf("COIN INSERTED\n");
}

void i8080_State::fire()
{
    // Handle fire command
    printf("FIRE\n");
}



void i8080_State::set_BC(uint16_t val)
{
    // Split the passed val to the two 8 bit registers
    reg_C.set(val & 0xff); 
    reg_B.set((val >> 8) & 0xff);
}

void i8080_State::set_HL(uint16_t val)
{
    reg_L.set(val & 0xff); 
    reg_H.set((val >> 8) & 0xff);
}

void i8080_State::set_DE(uint16_t val)
{
    reg_E.set(val & 0xff); 
    reg_D.set((val >> 8) & 0xff);
}

uint8_t i8080_State::get_PSW()
{
	uint8_t uint8_RegPSW = 0x00;
	
	if (flag_S.get() == true) {
		uint8_RegPSW = uint8_RegPSW | 0x01;

	}
	
	uint8_RegPSW = uint8_RegPSW << 1;
	
	if (flag_Z.get() == true) {
		uint8_RegPSW = uint8_RegPSW | 0x01;
		
	}
	
	uint8_RegPSW = uint8_RegPSW << 2;
	
	if (flag_AC.get() == true) {
		uint8_RegPSW = uint8_RegPSW | 0x01;
	}
	
	uint8_RegPSW = uint8_RegPSW << 2;
	
	if (flag_P.get() == true) {
		uint8_RegPSW = uint8_RegPSW | 0x01;
	}
	
	uint8_RegPSW = uint8_RegPSW << 1;
	uint8_RegPSW = uint8_RegPSW | 0x01;
	uint8_RegPSW = uint8_RegPSW << 1;
	
	if (flag_C.get() == true) {
		uint8_RegPSW = uint8_RegPSW | 0x01;
	}

    return uint8_RegPSW;
}

void i8080_State::LoadRomFiles() 
{
    LoadRom("rom/invaders.h", 0);
    LoadRom("rom/invaders.g", 0x0800);
    LoadRom("rom/invaders.f", 0x1000);
    LoadRom("rom/invaders.e", 0x1800);
}

void i8080_State::load_screen_update()
{
    // Load the current state of memory into an array that will 
    // eventually be loaded to the screen
    
    // Loop through the bytes 
    for (int byte_cnt = 0; byte_cnt < (256 * 224) / 28; byte_cnt++) {
        // Get the row and column of the current byte
        int row = (byte_cnt * 28) / 256;
        int col = (byte_cnt * 8) % 256;

        /*
        uint8_t byte = mem_Array[0x2400 + byte_cnt];

        for (int bit = 0; bit < 8; bit++)
        {
            int x = row + bit;
            //read 1 bit from the original byte
            int pixel = (byte >> bit) & 1;
            const int temp_x = x;

            int px = col;
            int py = -temp_x + 256 - 1;
            int pix_pos = (py * 224 + px) * 4;
            uint8_t pixel_val;
            if (pixel) pixel_val = 255; else pixel_val = 0;
            video_RAM[pix_pos] = pixel_val;
            video_RAM[pix_pos + 1] = pixel_val;
            video_RAM[pix_pos + 2] = pixel_val;
        }
        */

        ///*
        // Get the value of the byte out of memory
        uint8_t* byte = (uint8_t*)&mem_Array[0x2400] + byte_cnt;

        unsigned int* pix;
        for (int bit = 0; bit < 8; bit++) {

            int offset = (255 - (col + bit)) * 224 * 4 + (row * 4);

            pix = (unsigned int*)((uint8_t*)video_RAM + offset);

            if ((*byte & (1 << bit)) != 0) {
                *pix = 0xffffffffL;
            }                
            else {
                *pix = 0x00000000L;
            }

            pix -= 224;
        }
        //*/
    }

}

void i8080_State::LoadRom(const char * fileName, size_t address)
{
    // Open the ROM file
#pragma warning(disable:4996)
    FILE *f= fopen(fileName, "rb");

    // Check if the file was opened
	if (f==NULL)
	{
		printf("ERROR OPENING %s\nn", fileName);
	}

    // Find the end of the file
#pragma warning(disable:6387)
	fseek(f, 0L, SEEK_END);
	int file_size = ftell(f);
	fseek(f, 0L, SEEK_SET);
	
    // Create a temporary pointer to the location we want to copy the
    // ROM into 
	uint8_t *temp_buffer = &mem_Array[address];

    // Read the data from the file into the temporary pointer which
    // copies it into the mem_array
	fread(temp_buffer, file_size, 1, f);

    // Close the file
	fclose(f);

    return;
}

void i8080_State::exe_OpCode()
{
    uint16_t uint16_ProgramCounter = reg_PC.get_Large();
	opCode_Array[0] = get_Memory(uint16_ProgramCounter);
	opCode_Array[1] = get_Memory(uint16_ProgramCounter + 0x01);
	opCode_Array[2] = get_Memory(uint16_ProgramCounter + 0x02);

    printf("PC: %04X\n", uint16_ProgramCounter);
    //printf("OpCode0: %04X\n", opCode_Array[0]);
    printf("OpCode1: %04X\n", opCode_Array[1]);
    printf("OpCode2: %04X\n", opCode_Array[2]);
	
	eval_opCode(opCode_Array[0]);
}

/*****************************
 * Function Type: destructor, ~i8080_State();
 * Discription: clears the allocated memory
 * **************/
i8080_State::~i8080_State()
{
    //cout << "Memory in State has been cleared " << endl;
    free(video_RAM);
}

//general contructor
i8080_CPU::i8080_CPU()
{
    //cout << "Constructor: i8080_CPU has been initilized...." << endl;
}

/*****************************
 * Function Type: destructor, ~i8080_CPU();
 * Discription: clears the allocated memory
 * **************/
i8080_CPU::~i8080_CPU()
{
    //cout << "Memory in i8080_CPU has been cleared " << endl;
}

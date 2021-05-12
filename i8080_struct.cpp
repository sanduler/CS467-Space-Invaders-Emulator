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

uint8_t i8080_Register::get_Large()
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
    return (opCode_Array[1] << 8) | opCode_Array[2];
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
    LoadRom("../rom/invaders.h", 0);
    LoadRom("../rom/invaders.g", 0x0800);
    LoadRom("../rom/invaders.f", 0x1000);
    LoadRom("../rom/invaders.e", 0x1800);
}

void i8080_State::LoadRom(const char * fileName, size_t address)
{
    // Open the ROM file
    FILE *f= fopen(fileName, "rb");

    // Check if the fiule was opened
	if (f==NULL)
	{
		printf("ERROR OPENING %s\nn", fileName);
	}

    // Find the end of the file
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

/*****************************
 * Function Type: destructor, ~i8080_State();
 * Discription: clears the allocated memory
 * **************/
i8080_State::~i8080_State()
{
    //cout << "Memory in State has been cleared " << endl;
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

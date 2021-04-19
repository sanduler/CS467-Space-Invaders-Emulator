
#ifndef DISASSEMBLY_H
#define DISASSEMBLY_H


struct disassemblyStruct
{
	const char *disassembly;
	uint8_t nOperands;
	//Clock Cycle
	uint8_t states;
	void(*instr)(i8080& i);
};

const instruction disassemble[256] = 
{
	//disassemble Instructions go here  // exemple first opcode
	{ "NOP", 1, 4, NOP },
}
#endif
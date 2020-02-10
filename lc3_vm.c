#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

/** Memory
 * LC-3 has 65536 memory locations, since it is a 16-bit machine
 * (pow(2, 16) == 65536).
 * It can store a total of 128KB
 */
uint16_t memory[UINT16_MAX];

/** Registers
 * LC-3 has 10 total registers of 16 bits each. Roles are:
 * - General purpose (R0 - R7)
 * - Program counter (PC)
 * - Condition flag (COND)
 */
enum {
	R_R0 = 0,
	R_R1,
	R_R2,
	R_R3,
	R_R4,
	R_R5,
	R_R6,
	R_R7,
	R_PC,
	R_COND,
	R_COUNT
};

uint16_t reg[R_COUNT];

/** Instruction set
 * 16 opcodes, instructions are 16 bits long, most
 * significant 4 bits belong to the opcode.
 */
enum {
	OP_BR = 0,	// Branch
	OP_ADD,		// Add
	OP_LD,		// Load
	OP_ST,		// Store
	OP_JSR,		// Jump register
	OP_AND,		// Bitwise AND
	OP_LDR,		// Load register
	OP_STR,		// Store register
	OP_RTI,		// Unused
	OP_NOT,		// Bitwise NOT
	OP_LDI,		// Load indirect
	OP_STI,		// Store indirect
	OP_JMP,		// Jump
	OP_RES,		// Reserved (unused)
	OP_LEA,		// Load effective address
	OP_TRAP		// Execute trap
};

/** Condition flags
 * {positive,zero,negative} flags for R_COND register
 */
enum {
	FL_POS = 1 << 0,	// Positive
	FL_ZRO = 1 << 1,	// Zero
	FL_NEG = 1 << 2		// Negative
};

// Memory utils
int mem_read(int addr) {
	return memory[addr];
}

int main(int argc, char **argv) {
	// Load arguments
	if (argc < 2) {
		printf ("Usage: %s [file]\n", argv[0]);
		return 2;
	}

	// Set PC to starting position: 0x3000
	enum { PC_START = 0x3000 };
	reg[R_PC] = PC_START;

	bool running = true;

	// Pipeline cycle loop
	while (running) {
		// IF: Instruction Fetch
		uint16_t instr = mem_read(reg[R_PC]);
		uint16_t op = instr >> 12;
		reg[R_PC]++;

		switch (op) {

		}
	}
}

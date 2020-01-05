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

int main(int argc, char **argv) {
	return 0;
}

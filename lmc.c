#include "lmc.h"
#include "lmc_asm.h"
#include <string.h>

/** Initialises the LMC structure and sets components like accumulator, program counter, instruction 
 * register, halt flag and the variables responsible for hanfling I/O to default values (i.e 0)
 */

void init_lmc(LMC* lmc){
	memset(lmc->memory, 0, sizeof(lmc->memory));
	lmc->accumulator = 0;
	lmc->pc = 0;
	lmc->ir = 0;
	lmc->halted = 0;
	lmc->input_count = 0;
	lmc->input_index = 0;
	lmc->output_count = 0;
	memset(lmc->input_buffer, 0, sizeof(lmc->input_buffer));
	memset(lmc->output_buffer, 0, sizeof(lmc->output_buffer));
}

void reset_lmc(LMC* lmc) {
	lmc->accumulator = 0;
	lmc->pc = 0;
	lmc->ir = 0;
	lmc->halted = 0;
	lmc->input_index = 0;
	lmc->output_count = 0;
}

void load_program(LMC*lmc, int* program, int size) {
	if (size>MEMORY_SIZE){
		size = MEMORY_SIZE;
	}
	asm_memcpy_fast(lmc->memory, program, size);
}


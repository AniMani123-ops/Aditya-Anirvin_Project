#ifndef LMC_H
#define LMC_H

#define MEMORY_SIZE 100
#define MAX_IO_BUFFER 100

// LMC Instruction Opcodes
typedef enum {
    HLT = 0,   // Halt
    ADD = 1,   // Add
    SUB = 2,   // Subtract
    STA = 3,   // Store
    LDA = 5,   // Load
    BRA = 6,   // Branch always
    BRZ = 7,   // Branch if zero
    BRP = 8,   // Branch if positive
    INP = 901, // Input
    OUT = 902  // Output
} Opcode;

// LMC Structure
typedef struct {
    int memory[MEMORY_SIZE];        // Main memory (mailboxes)
    int accumulator;                // Accumulator register
    int pc;                         // Program counter
    int ir;                         // Instruction register
    int halted;                     // Halt flag
    int input_buffer[MAX_IO_BUFFER];   // Input buffer
    int input_count;                // Number of inputs
    int input_index;                // Current input index
    int output_buffer[MAX_IO_BUFFER];  // Output buffer
    int output_count;               // Number of outputs
} LMC;

// Function prototypes
void init_lmc(LMC* lmc);
void reset_lmc(LMC* lmc);
void load_program(LMC* lmc, int* program, int size);

#endif // LMC_H

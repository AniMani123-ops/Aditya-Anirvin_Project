#ifndef LMC_H
#define LMC_H

#define MEMORY_SIZE 100

// Function declarations
void loadProgram();
void execute();
void executeInstruction();

// Assembly function declarations
extern void fetch();
extern void decode();

// Global variables (extern declarations)
extern int memory[MEMORY_SIZE];
extern int accumulator;
extern int programCounter;
extern int instructionRegister;
extern int opcode;
extern int address;

#endif
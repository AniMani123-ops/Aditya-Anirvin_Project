#ifndef LMC_H
#define LMC_H

#define MEMORY_SIZE 100

// Function declarations (same as original)
void loadProgram();
void execute();
void fetch();
void decode();
void executeInstruction();

// Global variables ( declarations)
extern int memory[MEMORY_SIZE];
extern int accumulator;
extern int programCounter;
extern int instructionRegister;
extern int opcode;
extern int address;

#endif
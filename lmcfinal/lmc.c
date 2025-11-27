#include <stdio.h>
#include <stdlib.h>
#include "lmc.h"

// Global variables definition
int memory[MEMORY_SIZE];
int accumulator = 0;
int programCounter = 0;
int instructionRegister = 0;
int opcode = 0;
int address = 0;

void loadProgram() {
    printf("Enter program instructions (enter -1 to stop):\n");
    int instruction;
    int i = 0;
    
    while (i < MEMORY_SIZE) {
        printf("%02d ? ", i);
        scanf("%d", &instruction);
        
        if (instruction == -1) {
            break;
        }
        
        if (instruction < 0 || instruction > 999) {
            printf("Invalid instruction! Must be between 000 and 999.\n");
            continue;
        }
        
        memory[i] = instruction;
        i++;
    }
}

void execute() {
    while (1) {
        fetch();        // Now implemented in assembly
        decode();       // Now implemented in assembly
        executeInstruction();
        
        if (opcode == 0) { // HLT instruction
            break;
        }
    }
}

void executeInstruction() {
    int input;
    
    switch (opcode) {
        case 1: // ADD
            accumulator += memory[address];
            break;
        case 2: // SUB
            accumulator -= memory[address];
            break;
        case 3: // STA
            memory[address] = accumulator;
            break;
        case 5: // LDA
            accumulator = memory[address];
            break;
        case 6: // BRA
            programCounter = address;
            break;
        case 7: // BRZ
            if (accumulator == 0) {
                programCounter = address;
            }
            break;
        case 8: // BRP
            if (accumulator >= 0) {
                programCounter = address;
            }
            break;
        case 9: // I/O
            if (address == 1) { // INP
                printf("Input: ");
                scanf("%d", &input);
                accumulator = input;
            } else if (address == 2) { // OUT
                printf("Output: %d\n", accumulator);
            }
            break;
        case 0: // HLT
            printf("Program halted\n");
            break;
        default:
            printf("Unknown instruction! Program halted\n");
            opcode = 0; // Force halt
            break;
    }
    
    // Ensure accumulator stays within 3-digit range
    if (accumulator > 999) accumulator = 999;
    if (accumulator < -999) accumulator = -999;
}
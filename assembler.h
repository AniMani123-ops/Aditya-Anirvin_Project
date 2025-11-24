#ifndef ASSEMBLER_H
#ifndef ASSEMBLER_H

#include "lmc.h"

#define MAX_LABELS 50
#define MAX_LABEL_LENGTH 20
#define MAX_LINE_LENGTH 100

// Label Structure
typedef struct {
	char name[MAX_LABEL_LENGTH];
	int address;
} Label;

// Assembler Structure
typedef struct {
	Label labels[MAX_LABELS];
	int label_count;
	int machine_code[MEMORY_SIZE];
	int code_size;
	char error_message[256];
} Assembler;

// Function Declaration
void init_assembler(Assembler* asm_ctx);
int assemble(Assembler* asm_ctx, const char* source_code);
int get_opcode(const* char mnemonic);
int find_label(Assembler* asm_ctx, const char* label);
void add_label(Assembler* asm_ctx, const chat* label, int address);

#endif

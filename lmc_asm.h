#ifndef LMC_ASM_H
#define LMC_ASM_H

// Assembly Function Declarations


/** The line of code is used to decode an LMC Instruction into Opcode and Operand, where
 * instrct - stores the full instruction value
 * opcode - pointer to show where to store the opcode
 * operand - pointer to show where to store the operand
 */
void asm_decode_instruction(int insrct, int* opcode, int* operand);

/** The line of code is used to check if the address is withing the memory bounds
 * address - stores the address that is to be validated
 * mem_size - stores the size of memory
 * it returns 1 if valid and 0 if invalid
 */
int asm_validate_address(int address, int mem_size);

/** Add two numbers with LMC-style overflow (modulo 1000)
 * returns (a+b)%1000
 */
int asm_with_overflow(int a, int b);

/** Subtract with LMC underflow principles
 * return (a-b) with underflow compensation
 */
int asm_with_underflow(int a, int b);

/** A fast memory copy function used to transport large block of int data
 * dest - points to the destination array
 * src- points to the source array
 * count - used to count the number of integers to copy
 */
void asm_memcpy_fast(int* dest, int* src, int count);

/** Count number of non-zero instructions in memory
 * memory - pointer to the memory array
 * size - size of the array
 * it returns the count of non-zero values
 */
int asm_count_instructions(int* memory, int size);

#endif

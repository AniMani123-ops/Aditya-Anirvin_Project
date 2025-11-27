section .text
global fetch

; External variables from C code
extern memory
extern programCounter
extern instructionRegister

fetch:
    push rbp
    mov rbp, rsp
    push rbx
    push r12
    
    ; Get programCounter value
    mov eax, [programCounter]
    
    ; Calculate memory address: memory[programCounter]
    ; memory is an array of integers (4 bytes each)
    mov rbx, memory             ; Base address of memory array
    mov r12d, eax               ; Copy programCounter to r12d
    shl r12d, 2                 ; Multiply by 4 (size of int)
    add rbx, r12                ; memory + programCounter * 4
    
    ; Load instruction from memory
    mov eax, [rbx]              ; instruction = memory[programCounter]
    mov [instructionRegister], eax
    
    ; Increment programCounter
    mov eax, [programCounter]
    inc eax
    mov [programCounter], eax
    
    pop r12
    pop rbx
    pop rbp
    ret
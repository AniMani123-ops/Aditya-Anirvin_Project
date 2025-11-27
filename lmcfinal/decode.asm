section .text
global decode

; External variables from C code
extern instructionRegister
extern opcode
extern address

decode:
    push rbp
    mov rbp, rsp
    push rbx
    
    ; Get instructionRegister value
    mov eax, [instructionRegister]
    
    ; Calculate opcode = instructionRegister / 100
    xor edx, edx                ; Clear EDX for division
    mov ebx, 100
    div ebx                     ; EAX = quotient (opcode), EDX = remainder (address)
    
    ; Store results
    mov [opcode], eax
    mov [address], edx
    
    pop rbx
    pop rbp
    ret
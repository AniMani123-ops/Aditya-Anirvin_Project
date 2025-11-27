# Makefile

# target program
lmc: main.o lmc.o fetch.o decode.o
	gcc -no-pie main.o lmc.o fetch.o decode.o -o lmc

# compile source files into object files
main.o: main.c lmc.h
	gcc -Wall -Wextra -std=c99 -c main.c

lmc.o: lmc.c lmc.h
	gcc -Wall -Wextra -std=c99 -c lmc.c

fetch.o: fetch.asm
	nasm -f elf64 fetch.asm -o fetch.o

decode.o: decode.asm
	nasm -f elf64 decode.asm -o decode.o

# clean up build files
clean:
	rm -f *.o lmc

# run the program
run: lmc
	./lmc

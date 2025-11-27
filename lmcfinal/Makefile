# Makefile

lmc: main.o lmc.o fetch.o decode.o
	gcc main.o lmc.o fetch.o decode.o -o lmc

main.o: main.c lmc.h
	gcc -c main.c

lmc.o: lmc.c lmc.h  
	gcc -c lmc.c

fetch.o: fetch.asm
	nasm -f elf64 fetch.asm -o fetch.o

decode.o: decode.asm
	nasm -f elf64 decode.asm -o decode.o

clean:
	rm -f *.o lmc

run:
	./lmc
# Makefile

lmc: main.o lmc.o
	gcc main.o lmc.o -o lmc

main.o: main.c lmc.h
	gcc -c main.c

lmc.o: lmc.c lmc.h
	gcc -c lmc.c

clean:
	rm -f *.o lmc

run: lmc
	./lmc

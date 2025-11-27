# Makefile

# target program
lmc: main.o lmc.o
	gcc main.o lmc.o -o lmc

# compile source files into object files  
main.o: main.c lmc.h
	gcc -c main.c

lmc.o: lmc.c lmc.h
	gcc -c lmc.c

# clean up build files
clean:
	rm -f *.o lmc

# run the program
run: lmc
	./lmc
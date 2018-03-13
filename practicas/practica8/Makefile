LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c files.c
	 gcc -c main.c
	 gcc -o files.exe files.o main.o $(LIB)

filestest: clean
	 gcc -c files.c
	 gcc -c filestest.c
	 gcc -o filestest.exe files.o filestest.o
	 ./filestest.exe

test:	 filestest

clean:
	 rm *.out *.o *.exe || exit 0

files: clean
	 gcc -c files.c
	 gcc -c main.c
	 gcc -o files.exe files.o main.o $(LIB)

run: files
	 ./files.exe

runtest: files
	 ./maintest.tcl ./files.exe


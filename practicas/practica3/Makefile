all:
	gcc main.c -o needforspeed

main.o: main.c
	gcc -c main.c

runtest: main.o
	gcc main.o -o needforspeed
	./testmain.tcl ./needforspeed

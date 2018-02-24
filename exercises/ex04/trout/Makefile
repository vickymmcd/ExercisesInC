trout.o: trout.h util.h trout.c
	gcc -c trout.c

util.o: util.h util.c
	gcc -c util.c

main.o: util.h trout.h main.c
	gcc -c main.c

main: main.o trout.o util.o
	gcc -g -o main main.o trout.o util.o

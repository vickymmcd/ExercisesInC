main: trout.h util.h trout.c util.c main.c
	gcc -g -o main main.c trout.c util.c

trout: trout.h util.h util.c trout.c
	gcc -g -o trout trout.c util.c

util: trout.h util.h trout.c util.c
	gcc -g -o util util.c

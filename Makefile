OBJECTS = proj3.c completepieces.c output.c saveline.c scanlines.c hashtable.c structs.c tetraminoe.c
CFLAGS =  -ansi -Wall -pedantic proj3.c


all:	proj3

proj3: 	$(OBJECTS)
	gcc -o proj3 $(OBJECTS)

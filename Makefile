#  Compiler
CC = gcc

#  Compiler Flags
CFLAGS = -g -o3 -Wall -ansi -pedantic

#  Sources
SOURCES =	graph.c	connected.c	biconnected.c	cyclic.c	commer_connected.c	main.c

#  Objects
OBJECTS =	graph.o	connected.o	biconnected.o	cyclic.o	commer_connected.o	main.o

program: $(OBJECTS)
	gcc	-o $@ $(OBJECTS)	-lm
	rm -f *.o *~

graph.o:	graph.h

connected.o:	connected.h

biconnected.o:	biconnected.h

cyclic.o:	cyclic.h

commer_connected.o:	commer_connected.h

clean::
	rm -f *.o core	a.out program	*~

depend::
	makedepend $(SOURCES)

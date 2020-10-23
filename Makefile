#  Compiler
CC = gcc

#  Compiler Flags
CFLAGS = -o3 -Wall -ansi -pedantic

#  Sources
SOURCES =	graph.c	connected.c	biconnected.c	cyclic.c	main.c

#  Objects
OBJECTS =	graph.o	connected.o	biconnected.o	cyclic.o	main.o

program: $(OBJECTS)
	gcc -o $@ $(OBJECTS)	-lm
	rm -f *.o *~

graph.o:	graph.h

connected.o:	connected.h

biconnected.o:	biconnected.h

cyclic.o:	cyclic.h


clean::
	rm -f *.o core	a.out program	*~

depend::
	makedepend $(SOURCES)

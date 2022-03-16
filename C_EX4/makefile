FLAGS=-Wall -g
CC=gcc
AR=ar
OBJECTS_MAIN=main.o
all: graph
libclassstr.a:my_graph.o
	$(AR) -rcs libclassstr.a my_graph.o
my_graph.o: my_graph.h my_graph.c
	$(CC) $(FLAGS) -c my_graph.c
graph:$(OBJECTS_MAIN) libclassstr.a
	$(CC) $(FLAGS) -o graph $(OBJECTS_MAIN) libclassstr.a
main.o: main.c my_graph.h
	$(CC) $(FLAGS) -c main.c
.PHONY: clean all 
clean:
	rm -f graph *.o *.a

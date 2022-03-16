FLAGS=-Wall -g
CC=gcc
AR=ar
OBJECTS_MAIN=main.o
all: connections
libclassmat.a:my_mat.o
	$(AR) -rcs libclassmat.a my_mat.o
my_mat.o: my_mat.h my_mat.c
	$(CC) $(FLAGS) -c my_mat.c
connections:$(OBJECTS_MAIN) libclassmat.a
	$(CC) $(FLAGS) -o connections $(OBJECTS_MAIN) libclassmat.a
main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c
.PHONY: clean all 
clean:
	rm -f connections *.o *.a

FLAGS=-Wall -g
CC=gcc
AR =ar
OBJECTS_MAIN=main.o
CLASSR= advancedClassificationRecursion.o
CLASSL=advancedClassificationLoop.o
CLASSB=basicClassification.o
all: recursived loopd recursives loops mains maindloop maindrec
recursived: libclassrec.so
loopd: libclassloops.so
recursives: libclassrec.a
loops: libclassloops.a
libclassrec.so: $(CLASSR) $(CLASSB) 
	$(CC)  -shared -o libclassrec.so $(CLASSR) $(CLASSB)
libclassloops.so:$(CLASSB) $(CLASSL)
	$(CC)  -shared -o libclassloops.so $(CLASSB) $(CLASSL)	
libclassrec.a:  $(CLASSR) $(CLASSB)
	$(AR) -rcs libclassrec.a $(CLASSR) $(CLASSB)
libclassloops.a: $(CLASSB) $(CLASSL)
	$(AR) -rcs libclassloops.a $(CLASSB) $(CLASSL)
basicClassification.o: NumClass.h basicClassification.c
	$(CC) $(FLAGS) -c basicClassification.c
advancedClassificationLoop.o: NumClass.h advancedClassificationLoop.c
	$(CC) $(FLAGS) -c advancedClassificationLoop.c
advancedClassificationRecursion.o: NumClass.h advancedClassificationRecursion.c
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c
mains: libclassrec.a $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libclassrec.a
maindloop: libclassloops.so $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o maindloop $(OBJECTS_MAIN) ./libclassloops.so
maindrec: libclassrec.so $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o maindrec $(OBJECTS_MAIN) ./libclassrec.so
main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c
.PHONY: clean all recursived loopd recursives loops
clean:
	rm -f mains maindloop maindrec *.o *.a *.so

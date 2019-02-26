main: main.o
	cc main.o -o main

main.0: main.c LinkedList.h
	cc -c main.c

HashTable.o: HashTable.c HashTable.h
	cc -c HashTable.c

LinkedList.o: LinkedList.c LinkedList.h HashTable.h
	cc -c LinkedList.c	
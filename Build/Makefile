CFLAGS = -c -fPIC -ansi -pedantic -Wall -Werror -O0

All: Clean Build Run

Run:
	gcc ../Clean/*.o -o ../Main/Main

Build: Main TriTree

Main:
	gcc $(CFLAGS) ../Source/Main.c -I../Headers -o ../Clean/Main.o

TriTree:
	gcc $(CFLAGS) ../Source/TriTree.c -I../Headers -o ../Clean/TriTree.o

Clean:
	rm -rf ../Clean/*
	rm -rf ../Main/*

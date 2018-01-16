CFLAGS = -c -fPIC -ansi -pedantic -Wall -Werror -O0

All: Clean Build Run

Run:
	gcc ../Clean/*.o -o ../Main/Main

Build: Main Map Noise TriTree

Main:
	gcc $(CFLAGS) ../Source/Main.c -I../Headers -o ../Clean/Main.o

Map:
	gcc &(CFLAGS) ../Source/Map.c -I../Headers -o ../Clean/Map.o

Noise:
	gcc $(CFLAGS) ../Source/Noise.c -I../Headers -o ../Clean/Noise.o

TriTree:
	gcc $(CFLAGS) ../Source/TriTree.c -I../Headers -o ../Clean/TriTree.o

Clean:
	rm -rf ../Clean/*
	rm -rf ../Main/*

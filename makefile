all : minesweeper
minesweeper : minesweeper.o conio.o
	gcc minesweeper.o conio.o -o minesweeper
minesweeper.o : minesweeper.c conio.h
	gcc -c minesweeper.c 
conio.o : conio.c conio.h
	gcc -c conio.c
.PHONY : all clean
clean:
	rm minesweeper.o conio.o minesweeper

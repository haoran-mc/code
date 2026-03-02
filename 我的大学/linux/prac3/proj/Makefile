Max.o: Max.c
	gcc -c Max.c
Min.o: Min.c 
	gcc -c Min.c
Sum.o: Sum.c 
	gcc -c Sum.c
Avg.o: Avg.c 
	gcc -c Avg.c
Main.o: Main.c head.h
	gcc -c Main.c
main: Main.o Max.o Min.o Sum.o Avg.o
	gcc -o main Main.o Max.o Min.o Sum.o Avg.o

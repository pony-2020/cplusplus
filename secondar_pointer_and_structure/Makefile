
main : main.o teacher.o
	gcc main.o teacher.o -o main 

main.o : main.s
	gcc -c main.s -o main.o

main.s : main.i 
	gcc -S main.i -o main.s

main.i : main.c
	gcc -E main.c -o main.i

teacher : teacher.o
	gcc teacher.o -o teacher

teacher.o : teacher.s
	gcc -c teacher.s -o teacher.o

teacher.s : teacher.i
	gcc -S teacher.i -o teacher.s

teacher.i : teacher.c
	gcc -E teacher.c -o teacher.i


.PHONY :
CLEAR :
	rm -rf teacher.i teacher.s teacher.o main.i main.s main.o
CLR:
	rm -rf main

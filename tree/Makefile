cc=gcc

main:tree.o main.o
	cc -o main tree.o main.o
tree.o:tree.c tree.h
	cc -c tree.c
main.o:main.c tree.h
	cc -c main.c
clean:
	rm -rf *.o
	rm -rf main

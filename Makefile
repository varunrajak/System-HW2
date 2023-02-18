all: search

search: search.o
	gcc search.o -o search

search.o: main.c
	gcc -c -Wall main.c -o search.o

clean:
	rm search search.o

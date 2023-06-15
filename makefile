CC= clang
CFLAGS= -Wall -g

vectortest: vector.o lsearch.o vectortest.c
		$(CC) $(CFLAGS) vector.o lsearch.o vectortest.c -o vectortest

vector.o: lsearch.o vector.c
		$(CC) $(CFLAGS) -c vector.c

lsearch.o: lsearch.c
		$(CC) $(CFLAGS) -c lsearch.c

clean: vectortest vector.o lsearch.o
	rm -f ./??*.o rm -f ./vectortest

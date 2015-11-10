
CC = gcc
CFLAGS = -Wall -g 
LDFLAGS = -lm
PROGS = principal

all: $(PROGS)

principal: principal.o grafo.o memo.o
principal.o: principal.c grafo.h memo.h
grafo.o: grafo.c grafo.h
memo.o: memo.c memo.h

clean:
	rm -f *.o principal

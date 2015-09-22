
CC = gcc
CFLAGS = -Wall -g 
LDFLAGS = -lm
PROGS = principal

all: $(PROGS)

principal: principal.o pilha.o
principal.o: principal.c pilha.h
lista.o: pilha.c pilha.h

clean:
	rm -f *.o principal

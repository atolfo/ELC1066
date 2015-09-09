
CC = gcc
CFLAGS = -Wall -g 
LDFLAGS = -lm
PROGS = principal

all: $(PROGS)

principal: principal.o lista.o
principal.o: principal.c lista.h
lista.o: lista.c lista.h

clean:
	rm -f *.o principal

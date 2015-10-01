
CC = gcc
CFLAGS = -Wall -g 
LDFLAGS = -lm
PROGS = principal

all: $(PROGS)

principal: principal.o fila.o
principal.o: principal.c fila.h
fila.o: fila.c fila.h

clean:
	rm -f *.o principal

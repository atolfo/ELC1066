
# uma variavel com o nome do programa
PROG = cadeias
# compilador
CC = gcc
# algumas flags
CFLAGS = -Wall 

# alvo principal -> nosso caso e o programa
all: $(PROG)

# cadeias (o programa) depende de cadeias.c (o fonte)
# Com um Makefile, ele chama o compilador acima sozinho
# Se quisessemos dizer como compilar, usar linha abaixo:
#	$(CC) $(CFLAGS) -o cadeias cadeias.c
cadeias: cadeias.c

# se digitar make clean, limpa arquivos
clean:
	rm -f $(PROG) *.o


# uma variavel com o nome do programa
PROG = ordenacaoBolha
# compilador
CC = gcc
# algumas flags
CFLAGS = -Wall 

# alvo principal -> nosso caso e o programa
all: $(PROG)

# ordenacaoBolha (o programa) depende de ordenacaoBolha.c (o fonte)
# Com um Makefile, ele chama o compilador acima sozinho
# Se quisessemos dizer como compilar, usar linha abaixo:
#	$(CC) $(CFLAGS) -o ordenacaoBolha ordenacaoBolha.c
ordenacaoBolha: ordenacaoBolha.c

# se digitar make clean, limpa arquivos
clean:
	rm -f $(PROG) *.o

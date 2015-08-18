
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprime(char* s)
{
	printf("%s", s);
}

int comprimento(char* s)
{
	return -1;
}

void copia(char* dest, char* orig)
{
	dest[0] = '\0';
}

void concatena(char* dest, char* orig)
{
}

int compara(char* s1, char* s2)
{
	return -1;
}

char* le_linha(void)
{
	char* s;
	/* aloca para 120 letras + 1 para o '\0' */
	s = (char*)malloc(121*sizeof(char));
	scanf(" %120[^\n]", s);
	return s;
}

int main(int argc, char** argv)
{
	char* linha;
	char* s1 = "abc123";
	char* s2 = "aabb";
	char* s3 = "abc123aabb";
	char s4[11];

	/* exemplo da linha */
	imprime("Digite uma linha: \n");
	linha = le_linha();
	imprime(linha);
	printf("\n");

	printf("Teste das funcoes ...\n");

	/* teste do comprimento */
	if(comprimento(s1) != 6)
		printf("-> Erro tamanho de s1\n");
	if(comprimento(s2) != 4)
		printf("-> Erro tamanho de s2\n");
	if(comprimento(s3) != 10)
		printf("-> Erro tamanho de s3\n");

	/* teste da copia */
	copia(s4, s1);
	if(compara(s4, s1) != 0)
		printf("-> Erro na copia\n");

	/* teste que concatena s1 e s2 */
	concatena(s4, s2);
	if(compara(s4, s3) != 0)
		printf("-> Erro na concatenacao\n");

	return 0;
}

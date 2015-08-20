/*
 * cadeias.c
 * Exercício sobre cadeias de caracteres.
 *
 * The MIT License (MIT)
 * 
 * Copyright (c) 2014, 2015 João V. Lima, UFSM
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprime(char* s)
{
	printf("%s", s);
}

int comprimento(char* s)
{
	return strlen(s);
}

void copia(char* dest, char* orig)
{
	strcpy(dest, orig);
}

void concatena(char* dest, char* orig)
{
	/* TODO faça a função aqui! */
}

int compara(char* s1, char* s2)
{
	return strcmp(s1, s2);
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

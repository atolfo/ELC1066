/*
 * principal.c Programa que testa a TAD lista_t - lista duplamente encadeada.
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
#include <stdbool.h>
#include <time.h>

#include "lista.h"

typedef struct {
	float x;
	float y;
} ponto_t;

bool 
compara(void *a, void *b)
{
	/* primeiro faz typecast dos ponteiros para ponto_t */
	ponto_t        *p1 = (ponto_t *) a;
	ponto_t        *p2 = (ponto_t *) b;

	/* compara os pontos aqui */
	if ((p1->x == p2->x) && (p1->y == p2->y))
		return true;

	return false;
}

void imprime(void* a)
{
	ponto_t* p1 = (ponto_t*)a;
	printf(" (%.2f,%.2f) ", p1->x, p1->y);
}

int 
main(int argc, char **argv)
{
	lista_t        *lista;
	ponto_t        *p1;
	int npontos = 30;
	int i;

	/* semente para números aleatórios */
	srand(time(NULL));

	/* cria a lista */
	lista = lista_cria();

	printf("Inserindo na lista %d elementos...\n", npontos);
	for(i= 0; i < npontos; i++){
		/* cria pontos aleatórios */
		p1 = (ponto_t *) malloc(sizeof(ponto_t));
		p1->x = rand() / (float)RAND_MAX;
		p1->y = rand() / (float)RAND_MAX;
		lista = lista_insere(lista, (void *)p1);
	}

	/* imprime todos, fazer a função void imprime(void* p) */
	lista_imprime( lista, imprime );

	lista_destroi(lista);

	return 0;
}

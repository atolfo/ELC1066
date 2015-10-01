/*
 * principal.c Programa que testa a TAD fila_t (FIFO).
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

#include "fila.h"

typedef struct {
	float x;
	float y;
} ponto_t;

void* ponto_cria(float x, float y) 
{
	ponto_t* p = (ponto_t *) malloc(sizeof(ponto_t));
	p->x = x;
	p->y = y;
	return p;
}

bool compara(void *a, void *b)
{
	/* primeiro faz typecast dos ponteiros para ponto_t */
	ponto_t        *p1 = (ponto_t *) a;
	ponto_t        *p2 = (ponto_t *) b;

	if(p1 != NULL && p2 != NULL) {
		/* compara os pontos aqui */
		if ((p1->x == p2->x) && (p1->y == p2->y))
			return true;
	}

	return false;
}

void imprime(void* a)
{
	ponto_t* p1 = (ponto_t*)a;
	printf(" (%.2f,%.2f) ", p1->x, p1->y);
}

int main(int argc, char **argv)
{
	fila_t *fila;
	ponto_t *p1;
	ponto_t *p2;
	ponto_t *p3;
	
	/* cria os pontos */
	printf("Criando os pontos...\n");
	p1 = ponto_cria(1.0, 1.0);
	p2 = ponto_cria(2.0, 2.0);
	p3 = ponto_cria(3.0, 3.0);

	/* cria a fila */
	fila = fila_cria();
	
	/* insere os pontos na fila */
	printf("Inserindo os pontos na fila...\n");
	fila_insere(fila, (void *)p1);
	fila_insere(fila, (void *)p2);
	fila_insere(fila, (void *)p3);
	
	/* imprime a fila com os elementos */
	printf("\nFila atual:\n");
	fila_imprime( fila, imprime );
	
	/* remove os elementos */
	printf("\nRemovendo da fila (P1)...\n");
	if(compara(fila_retira(fila), p1)) 
		printf("SUCESSO! P1 foi removido.\n");
	else
		printf("ERRO! P1 não foi removido corretamente.\n");
	
	printf("\nRemovendo da fila (P2)...\n");
	if(compara(fila_retira(fila), p2)) 
		printf("SUCESSO! P2 foi removido.\n");
	else
		printf("ERRO! P2 não foi removido corretamente.\n");
	
	printf("\nRemovendo topo da fila (P3)...\n");
	if(compara(fila_retira(fila), p3)) 
		printf("SUCESSO! P3 foi removido.\n");
	else
		printf("ERRO! P3 não foi removido corretamente.\n");
	
	/* libera a memória */
	printf("\nLiberando a memória...\n");
	fila_destroi(fila);
	free(p1);
	free(p2);
	free(p3);

	return 0;
}

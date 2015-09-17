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

void* ponto_cria(float x, float y) {
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

int main(int argc, char **argv)
{
	lista_t *lista;
	ponto_t *p1;
	ponto_t *p2;
	ponto_t *p3;
	ponto_t *p4;

	/* cria a lista */
	lista = lista_cria();
	
	/* cria pontos e os insere na lista */
	printf("Criando e inserindo os elementos...\n");
	p4 = ponto_cria(4.0, 4.0);
	lista = lista_insere(lista, (void *)p4);
	
	p3 = ponto_cria(3.0, 3.0);
	lista = lista_insere(lista, (void *)p3);
	
	p2 = ponto_cria(2.0, 2.0);
	lista = lista_insere(lista, (void *)p2);
	
	p1 = ponto_cria(1.0, 1.0);
	lista = lista_insere(lista, (void *)p1);
	
	/* imprime todos */
	printf("\nLista inicial...\n");
	lista_imprime( lista, imprime );
	
	/* remove primeiro elemento */
	printf("\nRemovendo P1...\n");
	lista = lista_remove(lista, p1, compara);
	if(! lista_busca(lista, p1, compara)) 
		printf("SUCESSO! P1 foi removido.\n");
	else
		printf("ERRO! P1 continua na lista.\n");
	
	/* remove elemento do meio */
	printf("Removendo P3...\n");
	lista = lista_remove(lista, p3, compara);
	if(! lista_busca(lista, p3, compara)) 
		printf("SUCESSO! P3 foi removido.\n");
	else
		printf("ERRO! P3 continua na lista.\n");
	
	/* remove último elemento */
	printf("Removendo P4...\n");
	lista = lista_remove(lista, p4, compara);
	if(! lista_busca(lista, p4, compara)) 
		printf("SUCESSO! P4 foi removido.\n");
	else
		printf("ERRO! P4 continua na lista.\n");
	
	/* imprime todos */
	printf("\nLista final...\n");
	lista_imprime( lista, imprime );
	
	/* libera a memória */
	printf("\nLiberando a memória...\n");
	lista_destroi(lista);
	free(p1);
	free(p2);
	free(p3);
	free(p4);

	return 0;
}

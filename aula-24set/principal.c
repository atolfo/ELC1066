/*
 * principal.c Programa que testa a TAD pilha_t.
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

#include "pilha.h"

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
	pilha_t *pilha;
	ponto_t *p1;
	ponto_t *p2;
	ponto_t *p3;
	
	/* cria os pontos */
	printf("Criando os pontos...\n");
	p1 = ponto_cria(1.0, 1.0);
	p2 = ponto_cria(2.0, 2.0);
	p3 = ponto_cria(3.0, 3.0);

	/* cria a pilha */
	pilha = pilha_cria();
	
	/* insere os pontos na pilha */
	printf("Inserindo os pontos na pilha...\n");
	pilha_empilha(pilha, (void *)p1);
	pilha_empilha(pilha, (void *)p2);
	pilha_empilha(pilha, (void *)p3);
	
	/* imprime a pilha com os elementos */
	printf("\nPilha atual:\n");
	pilha_imprime( pilha, imprime );
	
	/* remove os elementos */
	printf("\nRemovendo topo da pilha (P3)...\n");
	if(compara(pilha_desempilha(pilha), p3)) 
		printf("SUCESSO! Topo da pilha (P3) foi removido.\n");
	else
		printf("ERRO! O topo da pilha (P3) não foi removido corretamente.\n");
	
	printf("\nRemovendo topo da pilha (P2)...\n");
	if(compara(pilha_desempilha(pilha), p2)) 
		printf("SUCESSO! Topo da pilha (P2) foi removido.\n");
	else
		printf("ERRO! O topo da pilha (P2) não foi removido corretamente.\n");
	
	printf("\nRemovendo topo da pilha (P1)...\n");
	if(compara(pilha_desempilha(pilha), p1)) 
		printf("SUCESSO! Topo da pilha (P1) foi removido.\n");
	else
		printf("ERRO! O topo da pilha (P1) não foi removido corretamente.\n");
	
	/* libera a memória */
	printf("\nLiberando a memória...\n");
	pilha_destroi(pilha);
	free(p1);
	free(p2);
	free(p3);

	return 0;
}

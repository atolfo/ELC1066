/*
 * pilha.c
 * Implementação da TAD pilha_t - pilha.
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

#include "pilha.h"

/* estrutura TAD lista_t */
struct _lista {
	void* dado;
	struct _lista* prox;
};

typedef struct _lista	lista_t;

/* define a struct TAD pilha */
struct _pilha {
	lista_t* primeiro;
};

/* cria uma pilha vazia, sendo:
 * - alocar memória para a pilha (chamar malloc)
 * - inicializa lista com NULL (vazia)
 * - retorna a pilha criada
 */
pilha_t* pilha_cria (void)
{
	/* TODO implementar aqui a criação da pilha */
	printf("ERRO! Falha ao alocar a pilha!\n");
	return NULL;
}

/* retorna se a pilha esta vazia (true), ou false caso contrario */
bool pilha_vazia( pilha_t* p )
{
	return (p->primeiro == NULL);
}

/* insere um elemento na pilha, sendo:
 - aloca memória para um novo elemento da lista
 - insere o elemento na primeira posição da lista
 */
void pilha_empilha( pilha_t* p, void* dado )
{
	/* TODO implementar aqui a inserção */
}

/* retira o elemento do topo da pilha, sendo:
 * - verificar se a pilha está vazia (chamar função pilha vazia)
 * - armazena o dado removido para ser retornado
 * - retira o primeiro elemento da lista e libera memória.
 * - retornar o valor removido
 */
void* pilha_desempilha( pilha_t* p ) 
{
	/* TODO implementar aqui a remoção */
	return NULL;
}

/* remove todos os elementos */
void pilha_destroi( pilha_t* p )
{
	lista_t* elem;
	lista_t* prox;

	elem = p->primeiro;
	while(elem != NULL){
		prox = elem->prox;
		free(elem);
		elem = prox;
	}
	free(p);
}

/* imprime os elementos da pilha */
void pilha_imprime( pilha_t* p, void (*imprime)(void*) )
{
	lista_t* elem = p->primeiro;
	if(pilha_vazia(p)) {
		printf("ERRO! Não é possível imprimir. Pilha vazia.\n");
		return;
	}

	while(elem != NULL){
		imprime( elem->dado );
		elem = elem->prox;
		printf("\n");
	}
}

/*
 * fila.c
 * Implementação da TAD fila_t - fila (FIFO).
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

#include "fila.h"

/* estrutura TAD lista_t */
struct _lista {
	void* dado;
	struct _lista* prox;
};

typedef struct _lista	lista_t;

/* define a struct TAD fila */
struct _fila {
	lista_t* inicio;
	lista_t* fim;
};

/* cria uma fila vazia, sendo:
 * - alocar memória para a fila (chamar malloc)
 * - inicializa lista com NULL (vazia)
 * - retorna a fila criada
 */
fila_t* fila_cria (void)
{
	/* TODO implementar aqui a criação da fila */
	printf("ERRO! Falha ao alocar a fila!\n");
	return NULL;
}

/* retorna se a fila esta vazia (true), ou false caso contrario */
bool fila_vazia( fila_t* f )
{
	return (f->inicio == NULL);
}

/* insere um elemento no final da fila, sendo:
 - aloca memória para um novo elemento da lista
 - insere o elemento na última posição da lista
 */
void fila_insere( fila_t* f, void* dado )
{
	/* TODO implementar aqui a inserção */
}

/* retira o elemento do início da fila, sendo:
 * - verificar se a fila está vazia (chamar função fila_vazia)
 * - armazena o dado removido para ser retornado
 * - retira o primeiro elemento da lista e libera memória.
 * - retornar o valor removido
 */
void* fila_retira( fila_t* f )
{
	/* TODO implementar aqui a remoção */
	return NULL;
}

/* remove todos os elementos */
void fila_destroi( fila_t* f )
{
	lista_t* elem;
	lista_t* prox;

	elem = f->inicio;
	while(elem != NULL){
		prox = elem->prox;
		free(elem);
		elem = prox;
	}
	free(f);
}

/* imprime os elementos da fila */
void fila_imprime( fila_t* f, void (*imprime)(void*) )
{
	lista_t* elem = f->inicio;
	if(fila_vazia(f)) {
		printf("ERRO! Não é possível imprimir. Pilha vazia.\n");
		return;
	}

	while(elem != NULL){
		imprime( elem->dado );
		elem = elem->prox;
		printf("\n");
	}
}

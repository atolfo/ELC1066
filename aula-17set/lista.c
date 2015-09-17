/*
 * lista.c
 * Implementação da TAD lista_t - lista duplamente encadeada.
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

#include "lista.h"

/* define a struct TAD lista */
struct _lista {
  void* dado;	      /* ponteiro para o dado (tipo void*) */
  struct _lista *prox; /* ponteiro para o proximo elemento */
  struct _lista *ant; /* ponteiro para o elemento anterior */
};

/* cria lista vazia */
lista_t* lista_cria(void)
{
	return NULL;
}

/* retorna se a lista esta vazia (true), ou false caso contrario */
bool lista_vazia( lista_t* l )
{
	return (l == NULL);
}

/* insere no comeco da lista, retorna a lista atualizada */
lista_t* lista_insere( lista_t* l, void* dado )
{
	lista_t* novo;
	novo = (lista_t*) malloc(sizeof(lista_t));
	novo->dado = dado;
	novo->prox = NULL;
	novo->ant  = NULL;
	
	if(!lista_vazia(l)) {
		novo->prox = l;
		l->ant = novo;
	}	

	return novo;
}

/* Remove todos os elementos */
void lista_destroi( lista_t* l )
{
	lista_t* elem = l;
	while( lista_vazia(elem) == false ){
		lista_t* t = elem->prox;
		free(elem);
		elem = t;
	}
}

void lista_imprime( lista_t* l, void (*imprime)(void*)  )
{
	lista_t *tmp, *ultimo;

	if(lista_vazia(l))
		printf("%s: ERRO: lista vazia!\n", __FUNCTION__);
	else {
		printf("(%s) EM ORDEM: ", __FUNCTION__);
		tmp = l;
		ultimo = l;
		while(lista_vazia(tmp) == false){
			imprime(tmp->dado);
			ultimo = tmp;
			tmp = tmp->prox;
		}
		printf("\n\n");
		printf("(%s) ORDEM INVERSA: ", __FUNCTION__);
		while(lista_vazia(ultimo) == false){
			imprime(ultimo->dado);
			ultimo = ultimo->ant;
		}
		printf("\n");
	}
}

bool lista_busca( lista_t* l, void* dado, bool (*compara)(void*, void*)  ) 
{
	lista_t* elem = l;
	while(! lista_vazia(elem)) {
		/* Se encontrou */
		if(compara(elem->dado, dado))
			return true;
		
		elem = elem->prox;
	}
	
	return false;
}

lista_t* lista_remove( lista_t* l, void* dado, bool (*compara)(void*, void*)  ) 
{
	/* TODO implementar aqui a remoção */
	return l;
}

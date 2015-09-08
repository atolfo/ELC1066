/*
 * lista.c
 * Implementação da TAD lista_t.
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
	novo = (lista_t*)malloc(sizeof(lista_t));
	novo->dado = dado;
	novo->prox = NULL;
	if(!lista_vazia(l))
		novo->prox = l;

	return novo;
}

/* busca um elemento na lista por meio da funcao f():
  bool f(void* a, void* b) {}
  que retonar 'true' caso a e b sejam iguais.
*/
bool lista_busca( lista_t* l, void* dado, bool (*f)(void*, void*)  )
{
	lista_t* primeiro = l;

	while( lista_vazia(primeiro) == false ){
		if( f(primeiro->dado, dado) == true )
			return true;

		primeiro = primeiro->prox;
	}
	return false;
}


/* remove da lista o elemento que contem 'dado'.
   Se lista ficar vazia, retorna NULL.
   Se encontrou, o elemento da lista deve ser liberado com free(). ATENCAO: nao liberar o dado.
   Se nao encontrou, retorna a lista 'l'.

   Use o exemplo da função lista_busca para fazer esta função.
*/
lista_t* lista_remove( lista_t* l, void* dado, bool (*f)(void*, void*)  )
{
	/* TODO: nesta aula ! */
	return l;
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

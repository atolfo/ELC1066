/*
 * lista.h
 * Definição da TAD lista_t.
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
#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdbool.h>

/* define a TAD lista_t */
typedef struct _lista {
  void* dado;	      /* ponteiro para o dado (tipo void*) */
  struct _lista *prox; /* ponteiro para o proximo elemento */
} lista_t;

/* cria uma lista vazia, ou seja, retorna NULL */
lista_t* lista_cria(void);

/* insere no começo da lista, retorna a lista atualizada,
 * ou seja, o novo 1o elemento da lista.
 */
lista_t* lista_insere( lista_t* l, void* dado );

/* retorna se a lista esta vazia (true), ou false caso contrario */
bool lista_vazia( lista_t* l );

/* busca um elemento na lista por meio da funcao f():
  bool f(void* a, void* b) {}
  que retonar 'true' caso a e b sejam iguais.
*/
bool lista_busca( lista_t* l, void* dado, bool (*f)(void*, void*)  );

/* remove da lista o elemento que contem 'dado'.  Se lista ficar vazia, retorna NULL.
   Se nao encontrou, retorna a lista 'l'.
   Senao, o elemento removido deve ser liberrado com free. ATENCAO: nao liberar o dado.
*/
lista_t* lista_remove( lista_t* l, void* dado, bool (*f)(void*, void*)  );

#endif

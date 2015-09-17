/*
 * lista.h
 * Definição da TAD lista_t - lista duplamente encadeada.
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

/* define o tipo lista_t, derivado da 'struct _lista' */
typedef struct _lista lista_t;

/* cria uma lista vazia, ou seja, retorna NULL */
lista_t* lista_cria(void);

/* insere no começo da lista, retorna a lista atualizada,
 * ou seja, o novo 1o elemento da lista.
 */
lista_t* lista_insere( lista_t* l, void* dado );

/* retorna se a lista esta vazia (true), ou false caso contrario */
bool lista_vazia( lista_t* l );

/* libera a memória de cada nó da lista.
 * ATENÇÃO: não libera memória dos dados.
 */
void lista_destroi( lista_t* l );

/* imprime todos os elementos da lista usando a função f 
 */
void lista_imprime( lista_t* l, void (*imprime)(void*)  );

/* busca um ponto na lista.
 * retorna se o mesmo foi encontrado (true), ou false caso contrario
 */
bool lista_busca( lista_t* l, void* dado, bool (*compara)(void*, void*)  );

/* remove um ponto da lista.
 * O ponto (void* dado) deve ser buscado na lista utilizando a função compara. 
 * Caso seja encontrado, o mesmo deve ser removido, liberando a memória do nó.
 * Retornar a lista sem o elemento removido (caso ele tenha sido encontrado).
 * ATENÇÃO: não liberar a memória dos dados.
 */
lista_t* lista_remove( lista_t* l, void* dado, bool (*compara)(void*, void*)  );

#endif

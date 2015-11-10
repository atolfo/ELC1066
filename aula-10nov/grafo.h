#ifndef _GRAFO_H_
#define _GRAFO_H_
/*
 * grafo.h
 * Funções para um grafo não-direcionado sem pesos.
 *
 * The MIT License (MIT)
 * 
 * Copyright (c) 2015 João V. F. Lima, UFSM
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

#include <stdlib.h>
#include <stdbool.h>

#include "memo.h"

/* o tipo vértice está em vertice.h */

#define MAX_VERTICES    100

typedef struct {
	bool arestas[MAX_VERTICES][MAX_VERTICES];     /* matriz de adjacencia */
	int nvertices;     /* numero de vértices */
  int narestas;     /* numero de arestas */
} grafo_t;

/* cria um grafo vazio */
grafo_t* grafo_cria(void);

/* essa função apenas le/importa um grafo do arquivo de entrada */
void grafo_importa(grafo_t* g, char* arquivo);

/*
 * Insere uma aresta entre os vértices v1 e v2. 
 */
bool grafo_insere_aresta(grafo_t* g, int v1, int v2);

/* função que imprime vértices e arestas conforme formato */
void grafo_imprime(grafo_t* g);

/* destroi e libera memória de um grafo */
void grafo_destroi(grafo_t* g);

#endif /* _GRAFO_H_ */

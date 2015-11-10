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

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "memo.h"
#include "grafo.h"

void grafo_imprime(grafo_t* g)
{
  /* TODO: fazer função */
}

grafo_t* grafo_cria(void)
{
  grafo_t* g = memo_aloca(sizeof(grafo_t));
  int i, j;

  /* inicia toda a matriz como false, nenhuma aresta */
  for(i= 0; i < MAX_VERTICES; i++)
    for(j= 0; j < MAX_VERTICES; j++)
      g->arestas[i][j] = false;

  g->nvertices = 0;
  g->narestas = 0;
  return g;
}


bool grafo_insere_aresta(grafo_t* g, int v1, int v2)
{
  if(v1 >= MAX_VERTICES || v2 >= MAX_VERTICES){
    printf("ERRO: vertice invalido!\n");
    return false;
  }

  /* Em um grafo não-direcionado temos a aresta v1 -> v2 */
  g->arestas[v1][v2] = true;
  /* e  a aresta v2 -> v1 */
  g->arestas[v2][v1] = true;
  g->narestas++;
  return true;
}


void grafo_importa(grafo_t* g, char* arquivo)
{
  int nvertices, narestas;
  int i, v1, v2;
  FILE* f = fopen(arquivo, "r");

  fscanf(f, "%d", &nvertices);
  fscanf(f, "%d", &narestas);
  g->nvertices = nvertices;
  g->narestas = narestas;
  for(i = 0; i < narestas; i++){
    fscanf(f, "%d %d", &v1, &v2);
    g->arestas[v1][v2] = true;
    g->arestas[v2][v1] = true;
  }
  fclose(f);
}

void grafo_destroi(grafo_t* g)
{
  memo_libera(g);
}

/*
 * principal.c
 * Programa que testa a TAD lista_t.
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

#include "lista.h"

typedef struct {
  int x;
  int y;
} ponto_t;

bool compara( void *a, void *b )
{
  /* primeiro faz typecast dos ponteiros para ponto_t */
  ponto_t *p1 = (ponto_t*)a;
  ponto_t *p2 = (ponto_t*)b;

  /* compara os pontos aqui */
  if( (p1->x == p2->x) && (p1->y == p2->y) ) 
    return true;

  return false;
}

int main(int argc, char **argv)
{
  lista_t* lista;
  ponto_t *p1, *p2;

  /* cria a lista */
  lista = lista_cria();

  /* aloca alguns pontos para inserir */
  p1 = (ponto_t*)malloc(sizeof(ponto_t));
  p1->x = p1->y = 1.0;
  p2 = (ponto_t*)malloc(sizeof(ponto_t));
  p2->x = p2->y = 2.0;

  /* insere os dois pontos */
  lista= lista_insere( lista, (void*)p1 );
  lista= lista_insere( lista, (void*)p2 );
  
  /* testa se estão na lista */
  if(lista_busca(lista, p1, compara) == true){
    printf("Hoooray! Ao buscar encontrei p1...\n");
  } else {
    printf("ERRO! Ao buscar nao encontrei p1...\n");
  }
  if(lista_busca(lista, p2, compara) == true){
    printf("Hoooray! Ao buscar encontrei p2...\n");
  } else {
    printf("ERRO! Ao buscar nao encontrei p2...\n");
  }

#if 0
  /* remove um elemento da lista e testa se ele esta na lista */
  lista = lista_remove(lista, p1, compara);
  if(lista_busca(lista, p1, compara) == true){
    printf("Hoooray! Ao remover encontrei p1...\n");
  } else {
    printf("ERRO! Ao remover nao encontrei p1...\n");
  }
#endif

  printf("Tudo Ok\n");

  /* libera memoria */
  lista = lista_remove(lista, p2, compara);
  free(p1);
  free(p2);

  return 0;
}


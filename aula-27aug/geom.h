/*
 * geom.h
 * Exercício sobre structs.
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

/* O teste abaixo serva para iniciar a inclusão do arquivo.
 * Caso _GEOM_H_ já esteja definido, ele não inclui novamente o que vem abaixo.
 */
#ifndef _GEOM_H_
#define _GEOM_H_

#include <stdbool.h>

/* Neste arquivo, defina as estruturas de dados. */

/* TODO struct ponto */
/* TODO tipo ponto_t */

/* TODO struct circulo */
/* TODO tipo circulo_t */

/* TODO struct retangulo */
/* TODO tipo retangulo_t */

/* completar funções abaixo dentro do arquivo geom.c */

struct ponto* ponto_cria( float x, float y );
float ponto_distancia( struct ponto* p1, struct ponto* p2 );
void ponto_libera( struct ponto* p );

struct circulo* circ_cria( struct ponto p, float raio );
/* retorna se o ponto esta dentro do círculo */
bool circ_tem_ponto( struct circulo* c, struct ponto* p );
void circ_libera( struct circulo* c );

struct retangulo* ret_cria( struct ponto pos, float alt, float larg );
float ret_area( struct retangulo* ret );
void ret_libera( struct retangulo* ret );

#endif /* _GEOM_H_ */

/*
 * principal.c
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> /* apenas para gerar numeros aleatorios */
#include <stdbool.h>

#include "geom.h"

void testa_ponto(void)
{
	ponto_t p1;
	ponto_t p2;
	float distancia = 0.0f;
	float x, y;

	/* criar pontos aleatórios */
	x = (1.0 * (rand()%100)) / 33.3;
	y = (1.0 * (rand()%100)) / 33.3;
	p1 = ponto_cria(x, y);

	x = (1.0 * (rand()%100)) / 33.3;
	y = (1.0 * (rand()%100)) / 33.3;
	p2 = ponto_cria(x, y);
	distancia = ponto_distancia(p1, p2);
	printf("pontos distancia p1 %.2f %.2f p2 %.2f %.2f valor %.2f\n",
		p1->x, p1->y, p2->x, p2->y, distancia);
	ponto_libera( p1 );
	ponto_libera( p2 );

}

void testa_circulo(void)
{
	circulo_t c1;
	ponto_t p1;
	ponto_t p2;
	float x, y;

	/* criar pontos aleatórios */
	x = (1.0 * (rand()%100)) / 33.3;
	y = (1.0 * (rand()%100)) / 33.3;
	p1 = ponto_cria(x, y);

	x = (1.0 * (rand()%100)) / 33.3;
	y = (1.0 * (rand()%100)) / 33.3;
	p2 = ponto_cria(x, y);

	/* testa círculo */
	c1 = circ_cria( *p1, 10.0f);
	/* testa se p2 esta dentro do círculo criado */
	if( circ_tem_ponto(c1, p2) == true ){
		printf("ponto p2 (%.2f, %.2f) esta em circulo c1 em %.2f %.2f raio %.2f\n",
			p2->x, p2->y, c1->p.x, c1->p.y, c1->raio );
	} else {
		printf("ponto p2 (%.2f, %.2f) NAO esta em circulo c1 em %.2f %.2f raio %.2f\n",
			p2->x, p2->y, c1->p.x, c1->p.y, c1->raio );
	}

	ponto_libera( p1 );
	ponto_libera( p2 );
	circ_libera( c1 );
}

void testa_retangulo(void)
{
	retangulo_t ret1;
	ponto_t p1;
	float x, y;
	float area = 0.0f;

	/* criar pontos aleatórios */
	x = (1.0 * (rand()%100)) / 33.3;
	y = (1.0 * (rand()%100)) / 33.3;
	p1 = ponto_cria(x, y);

	/* testa retangulo */
	ret1 = ret_cria( *p1, 10.0f, 10.f );
	area = ret_area( ret1 );
	printf("area do retangulo (%.2f, %.2f) tamanho (%.2f, %.2f) e %.2f\n",
		ret1->pos.x, ret1->pos.y, ret1->alt, ret1->larg, area);

	ponto_libera( p1 );
	ret_libera( ret1 );
}

/* Provável que os valores gerados sejam:
   - PONTO = 0
   - CIRCULO = 1
   - RETANGULO = 2
*/
typedef enum {PONTO, CIRCULO, RETANGULO} geom_tipo_t;

int main(int argc, char** argv)
{
	geom_tipo_t tipo;
	int i;
	int n = 20;

	/* semente para números aleatórios */
	srand(time(NULL));
	
	/* gera n testes de objetos aleatórios */
	for(i = 0; i < n;  i++){
		/* gera o número do tipo aleatório, ou seja,
		 * números de 0 a 2.
		 */
		tipo = (geom_tipo_t)(rand() % 3);
		switch(tipo){
			case PONTO:
				printf("Testando ponto...\n");
				testa_ponto();
				break;
			case CIRCULO:
				printf("Testando circulo...\n");
				testa_circulo();
				break;
			case RETANGULO:
				printf("Testando retangulo...\n");
				testa_retangulo();
				break;
			default:
				printf("tipo invalido!\n");
				break;
		}
	}


	return 0;
}

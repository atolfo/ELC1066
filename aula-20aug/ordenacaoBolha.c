/*
 * ordenacaoBolha.c
 * Exercício sobre vetores e ordenação.
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

/* crie cada uma das funções neste espaços sem alterar a main */

/* função vetor_aloca
 * aloca dinamicamento elementos de um vetor.
 */

/* função ordena_bolha
 * Ordena numeros inteiros dados por n usando o algoritmo de bolha.
 */

/* função vetor_libera 
 * Libera a memória alocada dinâmicamente 
 */

int main(int argc, char** argv)
{
	int n = 20; /* elementos para serem ordenados */
	int* v;
	int i;
	
	/* testa se algum número foi passado como argumento do programa */
	if( argc > 1 )
		n = atoi( argv[1] );

	printf("alocando %d elementos ...\n", n);
	/* aloca memória */
	v = vetor_aloca( n );

	/* inicia a sequencia de números pseudo-aleatórios rand() baseado no tempo */
	srand(time(NULL));
	/* inicializa o vetor */
	for(i = 0; i < n; i++)
		v[i] = rand() % n;

	printf("iniciando ordenacao dos %d elementos ...\n", n);
	/* ordena números */
	ordena_bolha( v, n );

	/* imprime resultado */
	for(i = 0; i < n; i++)
		printf( "%d ", v[i] );
	printf( "\n" );

	printf("liberando memoria ...\n");
	/* libera memória do vetor anterior */
	vetor_libera( v );

	return 0;
}

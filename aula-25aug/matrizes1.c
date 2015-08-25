/*
 * matrizes1.c
 * Exercício sobre multiplicação de matrizes.
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

/* faça aqui suas funções */

/* matriz_aloca */

/* matriz_multiplica */

/* matriz_libera */

int main(int argc, char** argv)
{
	int n = 20; /* tamanho de uma matriz n x n */
	int *A, *B, *C; /* matrizes com um vetor inteiro */
	int i, j;
	
	/* testa se algum número foi passado como argumento do programa */
	if( argc > 1 )
		n = atoi( argv[1] );

	printf("alocando %d elementos ...\n", n);
	/* aloca memória de tamanho n X n */
	A = matriz_aloca( n, n );
	B = matriz_aloca( n, n );
	C = matriz_aloca( n, n );

	/* inicia a sequencia de números pseudo-aleatórios rand() baseado no tempo */
	srand(time(NULL));
	/* inicializa a matriz */
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			A[ i*n+j ] = rand() % n;
			B[ i*n+j ] = rand() % n;
			C[ i*n+j ] = 0;
		}
	}

	printf("iniciando multiplicacao dos %d x %d elementos ...\n", n, n);
	/* multiplica  matrizes C = A * B */
	matriz_multiplica( A, B, C );

	/* imprime resultado */
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf( "%d ", C[i*n+j] );
		}
		printf( "\n" );
	}

	printf("liberando memoria ...\n");
	/* libera memória do vetor anterior */
	matriz_libera( A );
	matriz_libera( B );
	matriz_libera( C );

	return 0;
}

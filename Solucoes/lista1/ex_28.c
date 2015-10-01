/* 
 * File:   ex_28.c
 * Author: Vinicius
 */

#include <stdio.h>
#include <stdlib.h>


float soma_inferior (float* mat, int n);

int main(int argc, char** argv) {
    float *mat;
    int n,i,j,d;
    printf("Digiite o numero de linhas/colunas da matriz: ");
    scanf("%d",&n);
    mat=(float *)malloc(n*n*sizeof(float) );
    if (!mat) {
	printf("Erro alocação");
	exit(1);
    }
    printf("\nDigite a matriz:\n");
    for(i=0;i<n;i++){
	 for(j=0;j<n;j++){
	   d = i*n+j;
	   printf("Digite o valor [%d][%d]: ",i,j);
           scanf("%f",mat + d);	
	 }
    }
    printf("Retorno: %f ",soma_inferior(mat,n));
    free(mat);
    return (EXIT_SUCCESS);
}


float soma_inferior (float* mat, int n){
    int i,j,d;
    float soma;
    for (i=0; i<n; i++){		 
	for (j=0; j<n; j++){
            d=i*n+j;
            if(i > j)  soma += *(mat+d);		
        }
    }
    return soma;  
}
/* 
 * File:   ex_24.c
 * Author: Vinicius
 */


//   *** Considerando que o exercicio se refere a diagonal PRINCIPAL


#include <stdio.h>
#include <stdlib.h>

float produto_diagonal (float* mat, int n);

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
    printf("Retorno: %f ",produto_diagonal(mat,n));
    free(mat);
    return (EXIT_SUCCESS);
}


float produto_diagonal (float* mat, int n){
    int i,j,d,cont=0;
    float produto;
    for (i=0; i<n; i++){		 
	for (j=0; j<n; j++){
            d=i*n+j;
            if(i == j){
                cont++;
                if(cont == 1) produto = *(mat+d);
                else  produto = (produto) *  (*(mat + d));         
           }		
        }
    }
    return produto;
}
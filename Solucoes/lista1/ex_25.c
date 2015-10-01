/* 
 * File:   ex_25.c
 * Author: Vinicius

 **** Considerando que o exercicio se refere a diagonal PRINCIPAL

 */

#include <stdio.h>
#include <stdlib.h>

float produto_diagonal(float** mat, int n);

int main(int argc, char** argv) {
    int **mat;
    int n,i,j;
    printf("Digiite o numero de linhas/colunas da matriz: ");
    scanf("%d",&n);
    mat=(int**)malloc(n*sizeof(float*));
    for (i=0; i<n; i++)
       mat[i] = (float*) malloc(n*sizeof(float));
    printf("\nDigite a matriz:\n");
    for(i=0;i<n;i++){
	 for(j=0;j<n;j++){
	    printf("Digite o valor [%d][%d]: ",i,j);
            scanf("%f",&mat[i][j]);
	 }
    }
    printf("\nRetorno: %f ",produto_diagonal (mat,n));
    for (i=0; i<n; i++)
       free (mat[i]);
    free (mat);
    return (EXIT_SUCCESS);
}


float produto_diagonal (float** mat, int n){
    int i,j,d,cont=0;
    float produto;
    for (i=0; i<n; i++){		 
	for (j=0; j<n; j++){
            if(i == j){
                cont++;
                if(cont == 1) produto = mat[i][j];
                else  produto = produto *  mat[i][j];         
           }		
        }
    }
    return produto;
}
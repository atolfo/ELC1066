/* 
 * File:   ex_29.c
 * Author: Vinicius
 */

#include <stdio.h>
#include <stdlib.h>

float soma_inferior (float** mat, int n);

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
    printf("\nRetorno: %f ",soma_inferior (mat,n));
    for (i=0; i<n; i++)
       free (mat[i]);
    free (mat);
    return (EXIT_SUCCESS);
}

float soma_inferior (float** mat, int n){
    int i,j;
    float soma;
    for (i=0; i<n; i++){		 
	for (j=0; j<n; j++){
            if(i > j)  soma += mat[i][j];		
        }
    }
    return soma;  
}

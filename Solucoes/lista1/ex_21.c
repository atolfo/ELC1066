/* 
 * File:   ex_21.c
 * Author: Vinicius
*/

#include <stdio.h>
#include <stdlib.h>

/*
* matriz triangular inferior é aquela em que os elementos acima da diagonal principal são nulos ( 0 )
 */

int triangular_inferior (int** mat, int n);

int main(int argc, char** argv) {
    int **mat;
    int n,i,j,d;
    printf("Digiite o numero de linhas/colunas da matriz: ");
    scanf("%d",&n);
    mat=(int**)malloc(n*sizeof(int*));
    for (i=0; i<n; i++)
       mat[i] = (int*) malloc(n*sizeof(int));
    printf("\nDigite a matriz:\n");
    for(i=0;i<n;i++){
	 for(j=0;j<n;j++){
	    printf("Digite o valor [%d][%d]: ",i,j);
            scanf("%d",&mat[i][j]);
	 }
    }
    printf("\nRetorno: %d ",triangular_inferior(mat,n));
    for (i=0; i<n; i++)
       free (mat[i]);
    free (mat);
    return (EXIT_SUCCESS);
}


int triangular_inferior (int** mat, int n){
    int i,j,d,cont=0,qtd_elem=0;
    for (i=0; i<n; i++){		 
	for (j=0; j<n; j++){
            if(i < j){
                 qtd_elem++;
                 if (mat[i][j] == 0) cont++;  
            }
        }		
    }
    if (qtd_elem == cont) return 1;
    else return 0;   
}
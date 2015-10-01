/* 
 * File:   ex_23.c
 * Author: Vinicius
*/


#include <stdio.h>
#include <stdlib.h>


int tridiagonal (int** mat, int n);

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
    printf("Retorno: %d ",tridiagonal(mat,n));
    free(mat);
    return (EXIT_SUCCESS);
}


int tridiagonal (int** mat, int n){
    int i,j,d;
    for (i=0; i<n; i++){		 
	for (j=0; j<n; j++){
            d=i*n+j;
            // verifica se elemento não é da diagonal principal e adjacente
            if(!(i==j || i+1 == j || i == j+1)){
                if (mat[i][j] != 0) return 0;  
            }
        }		
    }
    return 1;   
}
        
   //     diag princ i == j
     //   dia adjac  i +1 == j  e i == j+1
      
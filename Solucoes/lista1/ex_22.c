/* 
 * File:   ex_22.c
 * Author: Vinicius
*/

#include <stdio.h>
#include <stdlib.h>

int tridiagonal (int* mat, int n);

int main(int argc, char** argv) {
    int *mat;
    int n,i,j,d;
    printf("Digiite o numero de linhas/colunas da matriz: ");
    scanf("%d",&n);
    mat=(int *)malloc(n*n*sizeof(int) );
    if (!mat) {
	printf("Erro alocação");
	exit(1);
    }
    printf("\nDigite a matriz:\n");
    for(i=0;i<n;i++){
	 for(j=0;j<n;j++){
	   d = i*n+j;
	   printf("Digite o valor [%d][%d]: ",i,j);
           scanf("%d",mat + d);	
	 }
    }
    printf("Retorno: %d ",tridiagonal(mat,n));
    free(mat);
    return (EXIT_SUCCESS);
}


int tridiagonal (int* mat, int n){
    int i,j,d;
    for (i=0; i<n; i++){		 
	for (j=0; j<n; j++){
            d=i*n+j;
            // verifica se elemento não é da diagonal principal e adjacente
            if(!(i==j || i+1 == j || i == j+1)){
                if (*(mat+ d) != 0) return 0;  
            }
        }		
    }
    return 1;   
}
        
   //     diag princ i == j
     //   dia adjac  i +1 == j  e i == j+1
      
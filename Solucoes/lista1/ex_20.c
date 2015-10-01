/* 
 * File:   ex_20.c
 * Author: Vinicius
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * matriz triangular inferior é aquela em que os elementos acima da diagonal principal são nulos ( 0 )
 */

int triangular_inferior (int* mat, int n);

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
    printf("Retorno: %d ",triangular_inferior(mat,n));
    free(mat);
    return (EXIT_SUCCESS);
}


int triangular_inferior (int* mat, int n){
    int i,j,d,cont=0,qtd_elem=0;
    for (i=0; i<n; i++){		 
	for (j=0; j<n; j++){
            if(i < j){
                 qtd_elem++;
                 d=i*n+j;
                 if (*(mat+ d) == 0) cont++;  
            }
        }		
    }
    if (qtd_elem == cont) return 1;
    else return 0;   
}
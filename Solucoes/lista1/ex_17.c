/* 
 * File:   ex_17.c
 * Author: Vinicius
 */

#include <stdio.h>
#include <stdlib.h>

int matriz_identidade(int** mat, int n);

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
    printf("\nRetorno: %d ",matriz_identidade(mat,n));
    for (i=0; i<n; i++)
       free (mat[i]);
    free (mat);
    return (EXIT_SUCCESS);
}


int matriz_identidade (int** mat, int n){
    int i,j,d,cont=0,cont2=0,qtd_diag_princ=0,qtd_nao_diag=0;
    for (i=0; i<n; i++){		 
	for (j=0; j<n; j++){
            if(i == j){
                 qtd_diag_princ++;
                 d=i*n+j;
                 if (mat[i][j] == 1) cont++;  
            }
            else if(i != j){
                 qtd_nao_diag++;
                 d=i*n+j;
                 if (mat[i][j] == 0) cont2++;  
            }
        }		
    }
    
    if (n == cont) return 1;
    else return 0;   
}
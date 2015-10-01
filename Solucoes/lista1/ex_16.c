/* 
 * File:   ex_16.c
 * Author: Vinicius
 */

#include <stdio.h>
#include <stdlib.h>

/* matriz quadrada - todos elementos diagonal principal é 1 e
 *  os demais elementos da matriz é 0 */

int matriz_identidade (int* mat, int n);

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
    printf("Retorno: %d ",matriz_identidade(mat,n));
    free(mat);
    return (EXIT_SUCCESS);
}


int matriz_identidade (int* mat, int n){
    int i,j,d,cont=0,qtd_nao_diag=0,qtd_diag_princ=0,cont2=0;
    for (i=0; i<n; i++){		 
	for (j=0; j<n; j++){
            if(i == j){
                 qtd_diag_princ++;
                 d=i*n+j;
                 if (*(mat+ d) == 1) cont++;  
            }
            else if(i != j){
                 qtd_nao_diag++;
                 d=i*n+j;
                 if (*(mat+ d) == 0) cont2++;  
            }
        }		
    }
    if (qtd_diag_princ == cont && qtd_nao_diag == cont2) return 1;
    else return 0;   
}
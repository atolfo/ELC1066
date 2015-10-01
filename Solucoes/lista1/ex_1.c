/* 
 * File:   ex_1.c
 * Author: Vinicius
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>


char *quebrar(char *s, int n);

int main(){
   char s1[20];
   char *s2; //Ponteiro para receber resultado da função
   int n1, tam;
   printf("\nDigite a palavra: ");
   fflush(stdin);
   gets(s1);
   printf("\nNumero para retirada do prefixo: ");
   scanf("%d", &n1);
   tam = strlen(s1);
   //Tamanho desejado > palavra, operação não pode ser feita
   if (n1 > tam){
       printf("\nA palavra é menor que o tamanho desejado!");
       return(EXIT_SUCCESS);
   }
   //Função passando a palavra por parametro
   s2=quebrar(s1, n1);
   printf("\n%s", s1);
   printf("\n%s", s2);

 return(EXIT_SUCCESS);
}

char *quebrar(char *s, int n){
    // *s é um ponteiro de s1, portanto altera-lo irá alterar também s1
    int i;
    char var[n];
    // para não alterar s1, cria-se um novo ponteiro para resultado
    char *ps;
    for(i=0; i<n; i++){
    //novo ponteiro recebe resultado  
         *(ps+i) = *(s+i);
    }
    *(ps+i) = '\0';
    // retorna novo ponteiro, como a função manda
    return ps;
}
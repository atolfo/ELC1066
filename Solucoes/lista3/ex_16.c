/* 
 * File:   ex_16.c
 * Author: Vinicius
 */

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

//void imprime (Pilha* p);
void retira_impares (Pilha* p1);

int main(int argc, char** argv) {
    int op;
    int v;
    Pilha *p1;
    p1 = cria();
    printf("Digite valores da Pilha:\n");
    do {
        printf("Digite o valor: ");
        scanf("%d",&v);
        push (p1, v);
        printf("\nDeseja inserir mais elementos: 1 - Sim, 0 - Nao ");
        scanf("%d",&op);
    }while(op == 1);
    retira_impares(p1);
    return (EXIT_SUCCESS);
}

void retira_impares (Pilha* p1) {
    int v, cont=0, i=0;
    Pilha* p_aux = cria();
    No* p_paux = p_aux->topo;
    No* p_p1 = p1->topo;
    do{
        v = p_p1->valor;
        if (v % 2 == 0){
           push (p_aux,v);
           cont++;
        }
        p_p1 = p_p1->prox;
    }while(p_p1 != NULL);  
    p_p1 = p1->topo;
    do{ p_p1 =  ret_ini(p_p1); }while (p_p1 != NULL);
    p1 = p1->topo;
    p_paux = p_aux->topo;
    do{
      v = p_paux->valor;
      push(p1,v);
      p_paux = p_paux->prox;
    }while(p_paux != NULL);
    printf("Imprimir Pilha 1:\n\n");
    for (p_p1=p1->topo; i < cont; p_p1=p_p1->prox){
      printf("%f\n",p_p1->valor);
      i++;
    }
    return;
}

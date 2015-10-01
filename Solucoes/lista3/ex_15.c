/* 
 * File:   ex_15.c
 * Author: Vinicius
 */

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void imprime (Pilha* p);
void concatena_pilhas (Pilha* p1, Pilha* p2);

int main(int argc, char** argv) {
    int op;
    float v;
    Pilha *p1, *p2;
    p1 = cria();
    p2 = cria();
    printf("Digite valores da Pilha 1:\n");
    do {
        printf("Digite o valor: ");
        scanf("%f",&v);
        push (p1, v);
        printf("\nDeseja inserir mais elementos: 1 - Sim, 0 - Nao ");
        scanf("%d",&op);
    }while(op == 1);
    printf("Digite valores da Pilha 2:\n");
    do {
        printf("Digite o valor: ");
        scanf("%f",&v);
        push (p2, v);
        printf("\nDeseja inserir mais elementos: 1 - Sim, 0 - Nao ");
        scanf("%d",&op);
    }while(op == 1);
    concatena_pilhas(p1,p2);
    libera(p2);
    printf("Imprimir Pilha 1:\n\n");
    imprime(p1);
    return (EXIT_SUCCESS);
}

/* imprime: versão com lista */
void imprime (Pilha* p) {
    No* q;
    for (q=p->topo; q!=NULL; q=q->prox)
    printf("%f\n",q->valor);
}

void concatena_pilhas (Pilha* p1, Pilha* p2) {
    float v;
    Pilha* p_aux = cria();
    No* p_p2 = p2->topo;
    No* p_paux = p_aux->topo;
    do{
        v = p_p2->valor;
         push (p_aux,v);
        p_p2 = p_p2->prox;

    }while(p_p2 != NULL);
    p_paux = p_aux->topo;
    do{
        v = p_paux->valor;
        push(p1,v);
        p_paux = p_paux->prox;
    }while (p_paux != NULL);
    return;
    
}
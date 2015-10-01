/* 
 * File:   ex_13.c
 * Author: Vinicius
 */

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
/*
 * 
 */
void combina_filas (Fila* f_res, Fila* f1, Fila* f2);

int main() {
    int op;
    float v;
    Fila *f1, *f2, *f_res;
    f1 = cria();
    f2 = cria();
    f_res = cria();
    printf("Digite valores da fila 1:\n");
    do {
        printf("Digite o valor: ");
        scanf("%f",&v);
        insere (f1, v);
        printf("\nDeseja inserir mais elementos: 1 - Sim, 0 - Nao ");
        scanf("%d",&op);
    }while(op == 1);
    printf("Digite valores da fila 2:\n");
    do {
        printf("Digite o valor: ");
        scanf("%f",&v);
        insere (f2, v);
        printf("\nDeseja inserir mais elementos: 1 - Sim, 0 - Nao ");
        scanf("%d",&op);
    }while(op == 1);
    combina_filas (f_res, f1, f2);
    printf("Imprimir fila resultado:\n\n");
    No* pres;
    for (pres=f_res->ini; pres!=NULL; pres=pres->prox)
        printf("%f\n",pres->valor);    
    
    return (EXIT_SUCCESS);
}

void combina_filas (Fila* f_res, Fila* f1, Fila* f2) {
    int i=0;
    float v;
    No* pf1; //percorer fila1
    pf1 = f1->ini;
    No* pf2; //percorrer fila2
    pf2 = f2->ini;
    while(pf1 != NULL && pf2 != NULL) { //inserir valores alternando
      v = pf1->valor;
      pf1 = pf1->prox;
      insere (f_res, v);
      v = pf2->valor;
      pf2 = pf2->prox;
      insere (f_res, v);
    }
    if (pf1 == NULL){ //termino fila1 mss fila2
        while(pf2 != NULL){
            v = pf2->valor;
            pf2 = pf2->prox;
            insere (f_res, v); 
        } 
    }
    else if (pf2 == NULL){ //termino fila2 mas fila1
        while(pf1 != NULL){
            v = pf1->valor;
            pf1 = pf1->prox;
            insere (f_res, v); 
        } 
    }
    libera(f1);
    libera(f2);
    return; 
}
/* 
 * File:   ex_14.c
 * Author: Vinicius
 */

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void separa_filas (Fila* f, Fila* f_pares, Fila* f_impares);
void imprimir(Fila* f);

int main(int argc, char** argv) {
    int op;
    int v;
    Fila *f, *f_pares, *f_impares;
    f = cria();
    f_pares = cria();
    f_impares = cria();
    printf("Digite valores da fila 1:\n");
    do {
        printf("Digite o valor: ");
        scanf("%d",&v);
        insere (f, v);
        printf("\nDeseja inserir mais elementos: 1 - Sim, 0 - Nao ");
        scanf("%d",&op);
    }while(op == 1);
    separa_filas (f, f_pares, f_impares);
    printf("Imprimir fila par:\n\n");
    imprimir(f_pares);
    printf("Imprimir fila impar:\n\n");
    imprimir(f_impares);
    return (EXIT_SUCCESS);
}

void separa_filas (Fila* f, Fila* f_pares, Fila* f_impares) {
    int i=0;
    int v;
    No* pf; //percorer fila
    pf = f->ini;
    while(pf != NULL) { //inserir valores
      v = pf->valor;
      pf = pf->prox;
      if(v % 2 == 0)
         insere (f_pares, v);
      else
        insere (f_impares, v);
    }
    libera(f);
    return;
}

void imprimir(Fila* f){
    No* p;
    for (p=f->ini; p!=NULL; p=p->prox)
        printf("%f\n",p->valor);    
    return;
}
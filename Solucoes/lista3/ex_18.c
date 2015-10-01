/* 
 * File:   ex_18.c
 * Author: Vinicius
 */

#include <stdio.h>
#include <stdlib.h>

struct arv {
int info;
struct arv* esq;
struct arv* dir;
};
typedef struct arv Arv;

int vazia(Arv* a);
Arv* Inicializa(void);
Arv* Cria_Arv(int num,Arv* sae,Arv* sad);
int maiores (Arv* a, int x);


int main(int argc, char** argv) {
    int x;
    //Exemplo de árvore binária
    Arv* F = Cria_Arv(12,Inicializa(),Inicializa());
    Arv* D = Cria_Arv(7,F,Inicializa());
    Arv* E = Cria_Arv(5,Inicializa(),Inicializa());
    Arv* B = Cria_Arv(2,D,E);
    Arv* J = Cria_Arv(0,Inicializa(),Inicializa());
    Arv* I = Cria_Arv(7,Inicializa(),J);
    Arv* G = Cria_Arv(2,Inicializa(),Inicializa());
    Arv* H = Cria_Arv(45,Inicializa(),I);
    Arv* C = Cria_Arv(3,G,H);
    Arv* A = Cria_Arv(4,B,C);
    printf("Digite o valor a ser comparado: ");
    scanf("%d",&x);
    printf("Quantidade nos maiores que %d :  %d ", x, maiores(A,x));  
    return (EXIT_SUCCESS);
}

int vazia(Arv* a){
    return a == NULL;
}
Arv* Inicializa(void){
    return NULL;
}

Arv* Cria_Arv(int num,Arv* sae,Arv* sad){
    Arv* p = (Arv*)malloc(sizeof(Arv));
    p->info = num;
    p->esq = sae;
    p->dir = sad;
    return p;
}

int maiores (Arv* a, int x){
    int cont=0;
    if (vazia(a)) return 0;
    if(a->info > x)
        cont=1;
    return cont + maiores (a->esq,x) + maiores (a->dir,x);
}

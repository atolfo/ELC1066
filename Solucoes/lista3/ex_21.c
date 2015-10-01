/* 
 * File:   ex_21.c
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
int um_filho (Arv* a);
int intermediarios (Arv* a);

int main(int argc, char** argv) {
    int x;
    //Exemplo de árvore binária ex:2
    Arv* i= Cria_Arv(12,Inicializa(),Inicializa());
    Arv* j= Cria_Arv(7,Inicializa(),Inicializa());
    Arv* g= Cria_Arv(5,i,Inicializa());
    Arv* h= Cria_Arv(2,j,Inicializa());
    Arv* e= Cria_Arv(0,g,Inicializa());
    Arv* f = Cria_Arv(7,Inicializa(),h);
    Arv* d= Cria_Arv(2,e,f);
    Arv* c = Cria_Arv(45,d,Inicializa());
    Arv* b= Cria_Arv(3,Inicializa(),c);
    Arv* a = Cria_Arv(4,Inicializa(),b);
    printf("Quantidade de nos nao folha:  %d ",intermediarios(a));  
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

int intermediarios (Arv* a){
    int cont=0;
    if(vazia(a)) return 0;
    else if(a->esq != NULL || a->dir != NULL)
        cont++; 
    return cont + intermediarios(a->esq) + intermediarios(a->dir);
}
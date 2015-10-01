/* 
 * File:   ex_26.c
 * Author: Vinicius
 */

#include <stdio.h>
#include <stdlib.h>

struct arvgen {
    int info;
    struct arvgen* primeiro_filho;
    struct arvgen* proximo_irmao;
};
typedef struct arvgen ArvGen;

ArvGen* cria (int c);
void    insere (ArvGen* a, ArvGen* sa);
int    intermediarios (ArvGen* a);
void    libera (ArvGen* a);

int main(int argc, char** argv) {
    /* cria nós como folhas */
    ArvGen* a = cria(1);
    ArvGen* b = cria(2);
    ArvGen* c = cria(3);
    ArvGen* d = cria(4);
    ArvGen* e = cria(5);
    ArvGen* f = cria(6);
    ArvGen* g = cria(7);
    ArvGen* h = cria(8);
    ArvGen* i = cria(9);
    ArvGen* j = cria(10);
    /* monta a hierarquia */
    insere(c,d);
    insere(b,e);
    insere(b,c);
    insere(i,j);
    insere(g,i);
    insere(g,h);
    insere(a,g);
    insere(a,f);
    insere(a,b);
    printf("Qtd nos com pelo menos um filho: %d ",intermediarios(a));
    return (EXIT_SUCCESS);
}

ArvGen* cria (int c)
{
   ArvGen *a =(ArvGen *) malloc(sizeof(ArvGen));
   a->info = c;
   a->primeiro_filho = NULL;
   a->proximo_irmao = NULL;
   return a;
}

void insere (ArvGen* a, ArvGen* sa)
{
   sa->proximo_irmao = a->primeiro_filho;
   a->primeiro_filho = sa;
}

int intermediarios(ArvGen* a){
    int cont=0;
    if(vazia(a)) return 0;
    else if(a->primeiro_filho != NULL || a->proximo_irmao != NULL)
        cont++; 
    return cont + intermediarios(a->primeiro_filho) + intermediarios(a->proximo_irmao);
}

int vazia(ArvGen* a){
    
    return a == NULL;
}


void libera (ArvGen* a)
{
   ArvGen* p = a->primeiro_filho;
   while (p!=NULL) {
      ArvGen* t = p->proximo_irmao;
      libera(p);
      p = t;
   }
   free(a);
}
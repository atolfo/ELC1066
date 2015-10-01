/* 
 * File:   ex_23.c
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
int    maiores (ArvGen* a, int x);
void    libera (ArvGen* a);

int main(int argc, char** argv) {
    int x;
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
    printf("Digite o numero a ser comparado: ");
    scanf("%d",&x);
    printf("Qtd numeros maiores que %d: %d ",x,maiores(a,x));
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

int maiores(ArvGen* a, int x){
    int cont=0;
    if (vazia(a)) return 0;
    if(a->info > x)
        cont=1;
   return cont + maiores (a->primeiro_filho,x) + maiores (a->proximo_irmao,x);
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
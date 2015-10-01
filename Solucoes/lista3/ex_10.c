/* 
 * File:   ex_10.c
 * Author: Vinicius
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista {
    char nome[81];
    char matricula[8];
    char turma;
    float p1;
    float p2;
    float p3;
    struct lista* prox;
};

typedef struct lista Lista;

int vazia(Lista* l);
Lista* inicializa(void);
void imprimir(Lista* l);
Lista* inserir_elem(Lista* l);
Lista* insere_ord(Lista* l, char* nome, char* matricula,char turma, float p1, float p2, float p3);
int listas_iguais(Lista* l1, Lista* l2);

int main(int argc, char** argv) {
    Lista* l1;
    Lista* l2;
    float p1,p2,p3;
    char turma,matricula[8],nome[81];
    int r;
    l1 = inicializa();
    l2 = inicializa();
    printf("LISTA 1:\n\n");
    l1 = inserir_elem(l1);
    printf("\n\nLISTA 2:\n\n");
    l2 = inserir_elem(l2);
    printf("Retorno: %d ",listas_iguais(l1,l2));
    return (EXIT_SUCCESS);
}


Lista* inserir_elem(Lista* l) {
      float p1,p2,p3;
      char turma[1],matricula[8],nome[81];
      int r;
      do{
        getchar();
        printf("\nDigite os dados do aluno:\n\n");
        printf("Nome: ");
        gets(nome);
        printf("Matricula: ");
        scanf("%s",matricula);
        printf("Turma: ");
        scanf("%c",&turma);
        getchar();
        printf("Prova 1: ");
        scanf("%f",&p1);
        getchar();
        printf("Prova 2: ");
        scanf("%f",&p2);
        getchar();
        printf("Prova 3: ");
        scanf("%f",&p3);
        l = insere_ord(l, nome, matricula, turma, p1, p2, p3);
        printf("\n\nDeseja inserir mais elementos: 1 - Sim 0 - Nao ");
        scanf("%d",&r);
    }while(r == 1);
    return l;
 }

int vazia(Lista* l){
  return l == NULL;
}

Lista* inicializa(void){
  return NULL;
}

Lista* insere_ord(Lista* l, char* nome, char* matricula,char turma, float p1, float p2, float p3){   
        Lista* q = l; //cria ponteiro para percorrer
        Lista* ant = NULL;
        //cria novo nó
        Lista* p = (Lista*) malloc(sizeof(Lista));
        strcpy(p->nome, nome);
        strcpy(p->matricula, matricula);
        p->turma = turma;
        p->p1 = p1;
        p->p2 = p2;
        p->p3 = p3;
        
        /* procura posição de inserção */
        while (q != NULL && ( strcmp(q->nome,p->nome) < 0 ) ) {
          ant = q;
          q = q->prox;
        }
        /* insere elemento em lista vazia */
        if (ant == NULL) { /* insere elemento no início */
          p->prox = l;
          l = p;
        }
        else { /* insere elemento no lugar certo da lista */
          p->prox = ant->prox;
          ant->prox = p;
        }
        return l;    
}

int listas_iguais(Lista* l1, Lista* l2){
    Lista* p = l1;
    Lista* q = l2;
    while(p != NULL && q != NULL){
        if(strcmp(p->nome,q->nome) != 0) return 0;
        if(strcmp(p->matricula,q->matricula) != 0) return 0;
        if(p->turma != q->turma) return 0;
        if(p->p1 != q->p1 || p->p2 != q->p2 || p->p3 != q->p3) return 0;
        p = p->prox; 
        q = q->prox;   
    }
    if (p == NULL && q != NULL) return 0;
    else if (q == NULL && p != NULL) return 0;
    return 1;
   
}

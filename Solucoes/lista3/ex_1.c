/* 
 * File:   main.c
 * Author: Vinicius
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

Lista* l;

int vazia(Lista* l);
Lista* inicializa(void);
void imprimir(Lista* l);
Lista* insere_ord(Lista* l, char* nome, char* matricula,char turma, float p1, float p2, float p3);


int main(int argc, char** argv) {
    float p1,p2,p3;
    char turma[1],matricula[8],nome[81];
    int r;
    l = inicializa();
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
    imprimir(l);
    
    return (EXIT_SUCCESS);
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


void imprimir(Lista* l){
  Lista* p;
  printf("\n");
  printf("Nome Matricula Turma Prova1 Prova2 Prova3\n\n");
  for(p=l;p!=NULL;p=p->prox){
      printf("\n%s %s %c %f %f %f",p->nome,p->matricula,p->turma,p->p1,p->p2,p->p3);
  }
  return;
}
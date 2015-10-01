/* 
 * File:   ex_12.c
 * Author: Vinicius
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista {
    char nome[81];
    char telefone[15];
    char celular[15];
    char endereco[101];
    struct lista* prox;
};

typedef struct lista Lista;

int vazia(Lista* l);
Lista* inicializa(void);
void imprimir(Lista* l);
Lista* inserir_elem(Lista* l);
Lista* insere_ord(Lista* l, char* nome, char* telefone, char* celular, char* endereco);
int listas_iguais(Lista* l1, Lista* l2);

int main(int argc, char** argv) {
    Lista* l1;
    Lista* l2;
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
      char telefone[15],celular[15],nome[81],endereco[101];
      int r;
      do{
        getchar();
        printf("\nDigite os dados da agenda:\n\n");
        printf("Nome: ");
        gets(nome);
        printf("Telefone: ");
        scanf("%s",telefone);
        printf("Celular: ");
        scanf("%s",celular);
        getchar();
        printf("Endereco: ");
        scanf("%s",endereco);
        l = insere_ord(l, nome, telefone, celular, endereco);
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

Lista* insere_ord(Lista* l, char* nome, char* telefone,char* celular, char* endereco){   
        Lista* q = l; //cria ponteiro para percorrer
        Lista* ant = NULL;
        //cria novo nó
        Lista* p = (Lista*) malloc(sizeof(Lista));
        strcpy(p->nome, nome);
        strcpy(p->telefone, telefone);
        strcpy(p->celular, celular);
        strcpy(p->endereco, endereco);

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
       if(strcmp(p->telefone,q->telefone) != 0) return 0;
       if(strcmp(p->celular,q->celular) != 0) return 0;
       if(strcmp(p->endereco,q->endereco) != 0) return 0;
       p = p->prox; 
       q = q->prox;   
    }
    if (p == NULL && q != NULL) return 0;
    else if (q == NULL && p != NULL) return 0;
    return 1;
   
}

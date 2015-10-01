/* 
 * File:   ex_9.c
 * Author: Vinicius
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct lista {
    char nome[81];
    char telefone[15];
    char celular[15];
    char endereco[101];
    struct lista* prox;
};

typedef struct lista Lista;

Lista* l;
int vazia(Lista* l);
Lista* inicializa(void);
void imprimir(Lista* l);
Lista* insere_ord(Lista* l, char* nome, char* telefone, char* celular, char* endereco);
Lista* copia(Lista* l);

int main(int argc, char** argv) {
    Lista* cop;
    char telefone[15],celular[15],nome[81],endereco[101];
    int r;
    l = inicializa();
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
    cop = copia(l);
    imprimir(l);
   
    return (EXIT_SUCCESS);
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

Lista* copia(Lista* l){
    Lista* copia = l;
    return copia;      
}

void imprimir(Lista* l){
  Lista* p;
  printf("\nIMPRIMIR LISTA COPIA\n");
  printf("Nome Telefone Celular Endereco\n\n");
  for(p=l;p!=NULL;p=p->prox){
      printf("\n%s %s %s %s",p->nome,p->telefone,p->celular,p->endereco);
  }
  return;
}

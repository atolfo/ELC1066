/* 
 * File:   ex_11.c
 * Author: Vinicius
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista {
    char nome[81];
    int matricula;
    char departamento[21];
    float salario;
    struct lista* prox;
};

typedef struct lista Lista;

int vazia(Lista* l);
Lista* inicializa(void);
void imprimir(Lista* l);
Lista* inserir_elem(Lista* l);
Lista* insere_ord(Lista* l, char* nome, int matricula,char *dep, float salario);
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
      int matricula;
      float salario;
      char nome[81], dep[21];
      int r;
      do{
        getchar();
        printf("\nDigite os dados do funcionario:\n\n");
        printf("Nome: ");
        gets(nome);
        getchar();
        printf("Matricula: ");
        scanf("%d",&matricula);
        printf("Departamento: ");
        gets(dep);
        getchar();
        printf("Salario: ");
        scanf("%f",&salario);
        //Inserir dados na lista encadeada
        l = insere_ord(l, nome, matricula, dep, salario);
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

Lista* insere_ord(Lista* l, char* nome, int matricula,char *dep, float salario){   
        Lista* q = l; //cria ponteiro para percorrer
        Lista* ant = NULL;
        //cria novo nó
        Lista* p = (Lista*) malloc(sizeof(Lista));
        strcpy(p->nome, nome);
        p->matricula = matricula;
        strcpy(p->departamento,dep);
        p->salario = salario;
        
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
       if(p->matricula != q->matricula) return 0;
       if(strcmp(p->departamento,q->departamento) != 0) return 0;
       if (p->salario != q->salario) return 0; 
       p = p->prox; 
       q = q->prox;   
    }
    if (p == NULL && q != NULL) return 0;
    else if (q == NULL && p != NULL) return 0;
    return 1;
   
}

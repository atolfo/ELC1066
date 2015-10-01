/* 
 * File:   main.c
 * Author: Vinicius
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

Lista* l;

int vazia(Lista* l);
Lista* inicializa(void);
void imprimir(Lista* l);
Lista* insere_ord(Lista* l, char* nome, int matricula, char* departamento, float salario);
Lista* copia(Lista* l);

int main(int argc, char** argv) {
    Lista* cop;
    float salario;
    char departamento[21],nome[81];
    int matricula, r;
    l = inicializa();
    do{
        getchar();
        printf("\nDigite os dados do funcionario:\n\n");
        printf("Nome: ");
        gets(nome);
        printf("Matricula: ");
        scanf("%d",&matricula);
        printf("Departamento: ");
        scanf("%s",&departamento);
        getchar();
        printf("Salario: ");
        scanf("%f",&salario);
        l = insere_ord(l, nome, matricula, departamento, salario);
        printf("\n\nDeseja inserir mais elementos: 1 - Sim 0 - Nao ");
        scanf("%d",&r);
    }while(r == 1);
    cop = copia(l);
    imprimir(cop);
    
    return (EXIT_SUCCESS);
}
        

int vazia(Lista* l){
  return l == NULL;
}

Lista* inicializa(void){
  return NULL;
}

Lista* insere_ord(Lista* l, char* nome, int matricula, char* departamento, float salario){   
        Lista* q = l; //cria ponteiro para percorrer
        Lista* ant = NULL;
        //cria novo nó
        Lista* p = (Lista*) malloc(sizeof(Lista));
        strcpy(p->nome, nome);
        p->matricula = matricula;
        strcpy(p->departamento, departamento);
        p->salario = salario;
        /* procura posição de inserção */
        while ( q != NULL && (strcmp(q->nome,p->nome) < 0) ) {
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
  printf("Nome Matricula Departamento Salario\n\n");
  for(p=l;p!=NULL;p=p->prox){
      printf("\n%s %d %s %f",p->nome,p->matricula,p->departamento,p->salario);
  }
  return;
}
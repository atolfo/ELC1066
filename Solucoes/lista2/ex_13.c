/* 
 * File:   ex_11.c
 * Author: Vinicius
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
    int mat; /* n´umero de matr´ıcula */
    char turma; /* turma do aluno: a, b, c, d, ou e */
    char nome[81]; /* nome do aluno */
    float p1, p2, p3; /* notas */
};
typedef struct aluno Aluno;

void inserir_dados(Aluno** v,int i);
void cadastro_Aluno(Aluno** v, int i,int m,char t,char* n,float n1,float n2, float n3);
void ordenar(Aluno** v, int n);
int busca (int n, Aluno** v, char* nome);

int main(int argc, char** argv) {
    Aluno **vetor;
    int n,i=0,indice;
    char nome[81];
    printf("Tamanho do vetor: ");
    scanf("%d",&n);
    vetor = (int **)malloc(n *sizeof(Aluno*));
   for (i=0; i<n; i++)
       vetor[i] = (Aluno*) malloc(sizeof(Aluno));
   for (i=0; i<n; i++) {
    printf("\nAluno %d:\n",i+1); 
    inserir_dados(vetor,i);
   }
    ordenar(vetor,n);
    getchar();
    printf("Digite o nome do aluno a ser buscado: ");
    gets(nome);
    indice = busca (n,vetor, nome);
    if (indice == -1) printf("%d Nao encontrado ",indice);
    else printf("O indice do nome e %d ",indice);
    return (EXIT_SUCCESS);
}



void inserir_dados(Aluno** v,int i){
    int m;
    float n1,n2,n3;
    char t;
    char nome[81];
    printf("Digite a matricula: ");
    scanf("%d",&m);
    getchar();
    printf("Turma: ");
    scanf("%c",&t);
   getchar();
    printf("Nome: ");
    gets(nome);
    printf("Nota 1, 2 e 3: ");
    scanf("%f %f %f",&n1,&n2,&n3);
    cadastro_Aluno(v,i,m,t,nome,n1,n2,n3);
    return;
}

void cadastro_Aluno(Aluno** v, int i,int m,char t,char* n,float n1,float n2, float n3){
    v[i]->mat = m;
    v[i]->turma = t;
    strcpy(v[i]->nome,n);
    v[i]->p1 = n1;
    v[i]->p2 = n2;
    v[i]->p3 = n3;
    return;
}


void ordenar(Aluno** v, int n){
    int i=0,j=0,m;
    char t;
    char nome[81];
    float n1,n2,n3;
    //ordenação por seleção
    for(i=0;i<n-1;i++){
        for(j=1+i;j<n;j++){
            if(strcmp(v[j]->nome,v[i]->nome) < 0) {
                //variavel auziliar
                m = v[i]->mat;
                t = v[i]->turma;
                strcpy(nome,v[i]->nome);
                n1 = v[i]->p1, n2 = v[i]->p2, n3 = v[i]->p3;
                //troca de valores entre os elementos             
                v[i]->mat=  v[j]->mat;
                v[i]->turma = v[j]->turma;
                strcpy(v[i]->nome,v[j]->nome);
                v[i]->p1 = v[j]->p1, v[i]->p2 = v[j]->p2, v[i]->p3 = v[j]->p3;
              
                v[j]->mat = m;
                v[j]->turma = t;
                strcpy(v[j]->nome, nome);
                v[j]->p1 = n1, v[j]->p2 = n2,v[j]->p3 = n3;
            }
            
        }
        
    }
    
    return;
}

int busca (int n, Aluno** v, char* nome){
 int ini=0,fim=n-1,meio;
 while (ini <= fim)
 {
      meio =(ini+fim)/2;
      if (strcmp(nome, v[meio]->nome) == 0) //encontrou
           return meio;
      else if (strcmp(nome,v[meio]->nome) < 0) //nome buscado menor
           fim=meio-1;
      else
           ini=meio+1;
 }
 return -1;   /* não encontrado */

}
        
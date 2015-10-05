/* 
 * File:   ex_17.c
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
void ordena(int n, Aluno** v);
void imprimir(Aluno** v,int n);

int main(int argc, char** argv) {
    Aluno **vetor;
    int n,i=0,indice;
    printf("Tamanho do vetor: ");
    scanf("%d",&n);
    vetor = (int **)malloc(n *sizeof(Aluno*));
   for (i=0; i<n; i++)
       vetor[i] = (Aluno*) malloc(sizeof(Aluno));
   for (i=0; i<n; i++) {
    printf("\nAluno %d:\n",i+1); 
    inserir_dados(vetor,i);
   }
    ordena(n,vetor);
    imprimir(vetor,n);
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


void ordena(int n, Aluno** v){
    int i=0,j=0,m;
    char t;
    char nome[81];
    float n1,n2,n3;
    //ordenação por seleção
    for(i=0;i<n-1;i++){
        for(j=1+i;j<n;j++){
            if(v[j]->turma < v[i]->turma ||
              (v[j]->turma == v[i]->turma && (strcmp(v[j]->nome,v[i]->nome) < 0))) {
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

void imprimir(Aluno** v,int n){
    int i=0;
    printf("\nAlunos\n\n");
    for(i=0;i<n;i++){
        printf("\nMatricula: %d\nTurma: %c\nNome: %s\nNota 1: %f\nNota 2: %f\nNota3: %f\n",
               v[i]->mat,v[i]->turma,v[i]->nome,v[i]->p1,v[i]->p2,v[i]->p3);   
    }
    return; 
}
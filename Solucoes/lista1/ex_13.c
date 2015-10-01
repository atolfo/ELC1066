/* 
 * File:   ex_13.c
 * Author: Vinicius
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct aluno {
char nome[81];
char matricula[8];
char turma;
float p1;
float p2;
float p3;
};
typedef struct aluno Aluno;

void imprime_reprovados (Aluno** turmas, int n);

int main(int argc, char** argv) {
   int n,i=0,j=0;
   Aluno **turmas;
   printf("Tamanho do vetor: ",n);
   scanf("%d",&n);
   turmas = (int **)malloc(n *sizeof(Aluno*));
   for (i=0; i<n; i++)
       turmas[i] = (Aluno*) malloc(sizeof(Aluno));
   printf("\nCadastre os alunos:\n");
   for (i=0; i<n; i++) {
       printf("\nAluno %d: Digite: \n",i+1);
       getchar();
       printf("Nome: ");
       gets(turmas[i]->nome);
       printf("Matricula: ");
       scanf("%s",turmas[i]->matricula);
       getchar();
       printf("Turma: ");
       scanf("%c",&turmas[i]->turma);
       printf("P1 P2 e P3: ");
       scanf("%f %f %f",&turmas[i]->p1,&turmas[i]->p2,&turmas[i]->p3);
   }
       imprime_reprovados(turmas,n);
       return (EXIT_SUCCESS);

}

void imprime_reprovados (Aluno** turmas, int n){
    int i;
    float media;
    for(i=0;i<n;i++){
        media = (turmas[i]->p1 + turmas[i]->p2 + turmas[i]->p3 ) /3;
        if (media < 5)
            printf("\n%s %s %c %f",turmas[i]->matricula,turmas[i]->nome,turmas[i]->turma,media);
    }
    return;
}
/* 
 * File:   ex_14.c
 * Author: Vinicius
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

void imprime_media (Aluno** turmas, int n, float media);

int main(int argc, char** argv) {
   int n,i=0,j=0;
   float media;
   Aluno **turmas;
   printf("Tamanho do vetor: ",n);
   scanf("%d",&n);
   turmas = (int **)malloc(n *sizeof(Aluno*));
   for (i=0; i<n; i++)
       turmas[i] = (Aluno*) malloc(sizeof(Aluno));
   printf("Defina media de aprovacao: ");
   scanf("%f",&media);
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
       imprime_media(turmas,n,media);
       return (EXIT_SUCCESS);

}

void imprime_media (Aluno** turmas, int n,float media){
    int i;
    float med;
    for(i=0;i<n;i++){
        med = (turmas[i]->p1 + turmas[i]->p2 + turmas[i]->p3 ) /3;
        if (med >= media)
            printf("\n%s %s %c %f",turmas[i]->matricula,turmas[i]->nome,turmas[i]->turma,med);
    }
    return;
}
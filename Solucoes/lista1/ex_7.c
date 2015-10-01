/* 
 * File:   ex_7.c
 * Author: Vinicius
 */

#include <stdio.h>
#include <stdlib.h>

struct Ponto {
int x;
int y;
};

struct Ponto p,v1,v2;

int dentroRet (struct Ponto* v1, struct Ponto* v2, struct Ponto* p);

int main(int argc, char** argv) {
    int retorno;
    printf("Digite x e y do ponto v1: ");
    scanf("%d %d",&v1.x,&v1.y);
    printf("Digite x e y do ponto v2: ");
    scanf("%f %f",&v2.x,&v2.y);
    retorno = dentroRet(&v1,&v2,&p);
    printf("Retorno: %d ",retorno);
    return (EXIT_SUCCESS);
}


int dentroRet (struct Ponto* v1, struct Ponto* v2, struct Ponto* p){
    p->x = v2->x - v1->x;
    p->y = v2->y - v1->y;
    if (p->x >=0 &  p->y >= 0) return 1;
    return 0;
}
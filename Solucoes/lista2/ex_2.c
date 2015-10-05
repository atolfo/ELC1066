/* 
 * File:   ex_2.c
 * Author: Vinicius
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Ponto {
int x;
int y;
};

struct Ponto c, p;

int dentroCirculo (struct Ponto* c, int raio, struct Ponto* p);

int main(int argc, char** argv) {
    float raio;
    printf("Digite o X e Y de c: ");
    scanf("%d %d",&c.x,&c.y);
    printf("Digite o X e Y do ponto P: ");
    scanf("%d %d",&p.x,&p.y);
    raio = pow(c.x,2) + pow(c.y,2);
    printf("Retorno %d ",dentroCirculo(&c,raio,&p));  
    return (EXIT_SUCCESS);
}


int dentroCirculo (struct Ponto* c, int raio, struct Ponto* p){
    if ( (pow(c->x - p->x,2) + pow(c->y - p->y,2)) > raio) return 0;
    else return 1;
}
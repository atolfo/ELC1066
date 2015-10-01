/* 
 * File:   ex_12.c
 * Author: Vinicius
 */

#include <stdio.h>
#include <stdlib.h>

struct Vetor {
    float x;
    float y;
    float z;
};

void mult (struct Vetor* v, float escalar);

int main() {
    struct Vetor v;
    float escalar;
    printf("Digite X Y Z do vetor: ");
    scanf("%f %f %f",&v.x,&v.y,&v.z);
    printf("Digite o valor do escalar: ");
    scanf("%f",&escalar);
    mult(&v,escalar);
    printf("Vetor: (%f,%f,%f) ",v.x,v.y,v.z);
    return (EXIT_SUCCESS);
}

void mult (struct Vetor* v, float escalar){
    // v é ponteiro do vetor v e por isso a função altera o valor da main
    v->x = v->x * escalar;
    v->y = v->y * escalar;
    v->z = v->z * escalar;
    return;
}
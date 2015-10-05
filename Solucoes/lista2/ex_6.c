/* 
 * File:   ex6.c
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
    mult(&v,escalar);
    printf("Vetor: (%f,%f,%f) ",v.x,v.y,v.z);
    return (EXIT_SUCCESS);
}

void mult (struct Vetor* v, float escalar){
    float res;
    // v é ponteiro do vetor v e por isso é alterado na função
    res = v->x * escalar;
    v->x = res;
    v->y = v->y * escalar;
    v->z = v->z * escalar;
}
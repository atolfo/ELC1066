/* 
 * File:   ex_11.c
 * Author: Vinicius
 */

#include <stdio.h>
#include <stdlib.h>

struct Vetor {
    float x;
    float y;
    float z;
};

float dot (struct Vetor* v1, struct Vetor* v2);


int main() {
    struct Vetor v1;
    struct Vetor v2;
    float res;
    printf("Digite X Y Z do vetor 1: ");
    scanf("%f %f %f",&v1.x,&v1.y,&v1.z);
    printf("Digite X Y Z do vetor 2: ");
    scanf("%f %f %f",&v2.x,&v2.y,&v2.z);
    res=dot(&v1,&v2);
    printf("Produto Escalar (%f) ",res);
    return (EXIT_SUCCESS);
}

float dot (struct Vetor* v1, struct Vetor* v2){
    float res;
    res = v1->x * v2->x;
    res += v1->y * v2->y;
    res += v1->z * v2->z;
    return res;
}
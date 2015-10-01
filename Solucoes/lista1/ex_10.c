/* 
 * File:   ex_10.c
 * Author: Vinicius
 */

#include <stdio.h>
#include <stdlib.h>

struct Vetor {
    float x;
    float y;
    float z;
};

void sub (struct Vetor* v1, struct Vetor* v2, struct Vetor* res);


int main() {
    struct Vetor v1;
    struct Vetor v2;
    struct Vetor res;
    printf("Digite X Y Z do vetor 1: ");
    scanf("%f %f %f",&v1.x,&v1.y,&v1.z);
    printf("Digite X Y Z do vetor 2: ");
    scanf("%f %f %f",&v2.x,&v2.y,&v2.z);
    sub(&v1,&v2,&res);
    printf("Vetor res (%f,%f,%f) ",res.x,res.y,res.z);
    return (EXIT_SUCCESS);
}

void sub (struct Vetor* v1, struct Vetor* v2, struct Vetor* res){
    res->x = v1->x - v2->x;
    res->y = v1->y - v2->y;
    res->z = v1->z - v2->z;
    return;
}
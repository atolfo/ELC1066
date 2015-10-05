/* 
 * File:   Ex_8.c
 * Author: Vinicius
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159;

FILE* abri_arquivo ();
void vazio_arquivo(FILE* farq);

int main(int argc, char** argv) {
    FILE *farq;
    char tipo = {'r','t','c'};
    char c;
    float cont[3], v[2] = {0,0}; // area de -> r t
    float b=0,h=0,r=0;
    
    farq = abri_arquivo();
    vazio_arquivo(farq);
    
    fseek(farq,0,SEEK_SET);
    while(!feof(farq)) {
        c = fgetc(farq); //ler tipo
        fscanf(farq,"%f",&b); //ler primeiro valor
        if (c == 'r'){
           fscanf(farq,"%f",&h); //ler segundo valor
           v[0] += (b * h);
           cont[0]++;
        }
        
        else if (c == 't'){
           fscanf(farq,"%f",&h);
           v[1] += (b * h);
           cont[1]++;
        }
        
        else if (c == 'c'){
           h=0;
           b = pow(b,2) * PI;
           r += b;
           cont[2]++;
        }
     
    }
    
    fclose(farq);
    printf("Media areas de retangulo: %.2f \n",v[0]/cont[0]);
    printf("Media areas de triangulo: %.2f \n",v[1]/cont[1]);
    printf("Media areas de circulo: %.2f \n",r/cont[2]);
    return (EXIT_SUCCESS);
}



FILE* abri_arquivo (){
    FILE* farq;
    if ( (farq = fopen("entrada.txt", "r")) == NULL ) {
        printf("Erro ao abrir o arquivo. ");
         exit(1);
    }
    return farq;
}


void vazio_arquivo(FILE* farq){
    char frase[5];
    if(fgets(frase, 4, farq) == NULL) {
        printf("VAZIO");
        exit(1);
    }
}
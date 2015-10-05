/* 
 * File:   Ex_7.c
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
    float v[2] = {0,0}; // area de -> r t
    float b=0,h=0,r=0;
    
    farq = abri_arquivo();
    vazio_arquivo(farq);
    
    fseek(farq,0,SEEK_SET);
    while(!feof(farq)) {
        c = fgetc(farq); //ler tipo
        fscanf(farq,"%f",&b); //ler primeiro valor
        if (c == 'r'){
           fscanf(farq,"%f",&h); //ler segundo valor
           if((b * h) > v[0])  v[0] = b * h;
        }
        
        else if (c == 't'){
           fscanf(farq,"%f",&h);
           if((b * h) > v[1])  v[1] = b * h;
        }
        
        else if (c == 'c'){
           h=0;
           b = pow(b,2) * PI;
           if( b > r)  r = b;
        }
     
    }
    
    fclose(farq);
    printf("Maior area de retangulo: %.2f \n",v[0]);
    printf("Maior area de triangulo: %.2f \n",v[1]);
    printf("Maior area de circulo: %.2f \n",r);
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
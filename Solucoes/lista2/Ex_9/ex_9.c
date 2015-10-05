/* 
 * File:   Ex_9.c
 * Author: Vinicius
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define TAM 80

FILE* abri_arquivo ();
void vazio_arquivo(FILE* farq);

int main(int argc, char** argv) {
    FILE *farq;
    char c;
    float notas[3] = {0,0,0}; // três notas
    float media, media_alun;
    int cont=0;
    farq = abri_arquivo();
    vazio_arquivo(farq);
    fseek(farq,0,SEEK_SET);
    char ascii = 39; //aspa simples em ascii
    while(!feof(farq)) {
        // tratar o nome da pessoa q não interessa
         while(cont < 2) {
            c = fgetc(farq);
            if( c == ascii) cont++;
        }
        cont=0;  
        fscanf(farq,"%f",&notas[0]);
        fscanf(farq,"%f",&notas[1]);
        fscanf(farq,"%f",&notas[2]);
        media_alun = (notas[0] + notas[1] + notas[2]) / 3;
        if( media_alun > media)
            media = media_alun;     

    }
    fclose(farq);
    printf("A maior Media obtida foi: %.1f \n",media);
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
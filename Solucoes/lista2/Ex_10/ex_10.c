/* 
 * File:   Ex_10.c
 * Author: Vinicius
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

FILE* abri_arquivo ();
void vazio_arquivo(FILE* farq);

int main(int argc, char** argv) {
    FILE *farq;
    char c;
    float media_alun, notas[3] = {0,0,0}; // três notas
    int maior_media=0, cont=0;
    char ascii = 39; //aspa simples em ascii
    farq = abri_arquivo();
    vazio_arquivo(farq);
    fseek(farq,0,SEEK_SET);
    while(!feof(farq)) {
        // tratar o nome da pessoa q não interessa
         while(cont < 2) {
            c = fgetc(farq);
            if( c == ascii) cont++;
        }
        cont=0,media_alun=0;  
        fscanf(farq,"%f",&notas[0]);
        fscanf(farq,"%f",&notas[1]);
        fscanf(farq,"%f",&notas[2]);
        media_alun = (notas[0] + notas[1] + notas[2]) / 3;
        if( media_alun >= 5)
            maior_media++;   

    }
    fclose(farq);
    printf("O numero de alunos com media >= 5 e: %d \n",maior_media);
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
/* 
 * File:   ex_3.c
 * Author: Vinicius
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* troca_letra (char* str, char original, char novo);

int main(int argc, char** argv) {
    char nova,antiga;
    char palavra[20];
    char *p;
    printf("Digite a palavra: ");
    scanf("%s",palavra);
    getchar();
    printf("Digite letra a ser substituida: ");
    scanf("%c",&antiga);
    getchar();
    printf("Digite letra a nova letra: ");
    scanf("%c",&nova);
    p=troca_letra (palavra, antiga, nova);
    printf("Antiga: %s\nNova: %s",palavra,p);
    return (EXIT_SUCCESS);
}

char* troca_letra (char* str, char original, char novo){
    int i;
    char *p;
    for(i=0;str[i];i++){
        if(*(str+i) == original)
            *(p+i) = novo;
        else
            *(p+i) = *(str+i);
    }
    *(p+i) = '\0';
    return p;
}
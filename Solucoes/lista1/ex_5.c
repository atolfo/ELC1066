/* 
 * File:   ex_5.c
 * Author: Vinicius

 */

#include <stdio.h>
#include <stdlib.h>

char* string_oposta (char* str);

int main() {
    char str[20];
    char *p;
    printf("Digite a palavra: ");
    scanf("%s",str);
    getchar();
    p=string_oposta (str);
    printf("Antiga: %s\nNova: %s ",str,p);
    return (EXIT_SUCCESS);
}

char* string_oposta (char* str){
    int i,dif;
    char *p;
    for(i=0;str[i];i++){
        //Verifica letra maiscula e minuscula
        if(*(str+i) >= 'a' && str[i] <= 'z'){
            //Codigo da tabela ASCII em decimal https://pt.wikipedia.org/wiki/ASCII
            //Calcula diferença da letra para a "a"
            dif = str[i];
            dif = str[i] - 97;
            //diminui o valor de "z" = 122 para descobrir o numero da letra correspondente
            *(p+i) = 122-dif;
        }
        else if(*(str+i) >= 'A' && str[i] <= 'Z'){
            dif = str[i];
            dif = str[i] - 65;
            *(p+i) = 90-dif;
        }
        else *(p+i) = str[i];
    }
    *(p+i) = '\0';
    return p;
}
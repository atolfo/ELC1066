/* 
 * File:   ex_6.c
 * Author: Vinicius
 */

#include <stdio.h>
#include <stdlib.h>

char* inverte_string (char* str);

int main(int argc, char** argv) {
    char str[20];
    char *p;
    printf("Digite a palavra: ");
    scanf("%s",str);
    getchar();
    p=inverte_string (str);
    printf("Antiga: %s\nNova: %s ",str,p);
    return (EXIT_SUCCESS);
}

char* inverte_string (char* str){
    char *p;
    int i,j;
    for(i=0;str[i];i++);
    while (i >= 0){
        i--;
        *(p+j) = str[i];
        j++;    
    }
    return p;
}
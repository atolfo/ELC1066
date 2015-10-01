/* 
 * File:   ex_2.c
 * Author: Vinicius

 */

#include <stdio.h>
#include <stdlib.h>

char* inverte_letra (char* str);

int main() {
    char str[20];
    char *p;
    printf("Digite a palavra: ");
    scanf("%s",str);
    getchar();
    p=inverte_letra (str);
    printf("Antiga: %s\nNova: %s ",str,p);
    return (EXIT_SUCCESS);
}

char* inverte_letra (char* str){
    int i;
    char *p;
    for(i=0;str[i];i++){
        if(*(str+i) >= 'a' && str[i] <= 'z'){ 
            *(p+i) = str[i] -32  ;}
        else if(*(str+i) >= 'A' && str[i] <= 'Z'){ 
            *(p+i) = str[i] +32  ;}
        else *(p+i) = str[i];
    }
   *(p+i) = '\0';
    return p;
}
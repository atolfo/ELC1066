/* 
 * File:   ex_4.c
 * Author: Vinicius
 */

#include <stdio.h>
#include <stdlib.h>

char* shift_string (char* str);

int main() {
    char str[20];
    char *p;
    printf("Digite a palavra: ");
    scanf("%s",str);
    getchar();
    p=shift_string (str);
    printf("Antiga: %s\nNova: %s ",str,p);
    return (EXIT_SUCCESS);
}

char* shift_string (char* str){
    int i;
    char *p;
    for(i=0;str[i];i++){
        if(*(str+i) >= 'a' && str[i] < 'z')
            *(p+i) = str[i] +1;
        else if(*(str+i) >= 'A' && str[i] < 'Z')
            *(p+i) = str[i] +1;
        else if (*(str+i) == 'z') *(p+i) = 'a'  ;
        else if (*(str+i) == 'Z') *(p+i) = 'A'  ;
        else *(p+i) = str[i];
    }
    *(p+i) = '\0';
    return p;
}
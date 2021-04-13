#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int VerificaAlphaNum(const char *x){
    int i;
    for(i=0; x[i] != '\0'; i++){
        if(!isalnum(x[i])){
            return 0;
        }
    }
    return 1;
}

int VerificaAlpha(const char *x){
    int i;
    for(i=0; x[i] != '\0'; i++){
        if(!isalpha(x[i])){
            return 0;
        }
    }
    return 1;
}

int VerificaNum(const char *x){
    int i;
    for(i=0; x[i] != '\0'; i++){
        if(!isdigit(x[i])){
            return 0;
        }
    }
    return 1;
}

void VerificaPonteiro(void *x){
    if(x == NULL){
        printf("Ponterio nao alocado\n");
        exit(1);
    }
}

void MeuPrint(char *imprime, int verbosity){
    if(verbosity){
        printf("%s", imprime);
    }
}

void Clean(){
    printf("\e[1;1H\e[2J");
};

#endif //UTILIDADES_H//

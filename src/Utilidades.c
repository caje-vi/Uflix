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
int ValidaData(const char* data){

    int dia, mes, ano;


    sscanf(data, "%2d/%2d/%4d", &dia, &mes, &ano);
    
    //checar ano

    if (ano >= 1900 && ano <= 9999)
    {
        //checar ano
        if (mes >= 1 && mes <= 12)
        {
            //checar dia
            if ((dia >= 1 && dia <= 31) && 
                (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || 
                 mes == 10 || mes == 12)){
                return 1;
            }

            else if ((dia >= 1 && dia <= 30) && 
                    (mes == 4 || mes == 6 || mes == 9 || mes == 11)){
                return 1;
            }

            else if ((dia >= 1 && dia <= 28) && (mes == 2)){
                return 1;
            }

            else if (dia == 29 && mes == 2 && 
                    (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0))){
                return 1;
            }
            else
                return 0;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }

return 1;
} 

void MeuPrint(char *imprime, int verbosity){
    if(verbosity){
        printf("%s", imprime);
    }
}

void Clean(){
    printf("\e[1;1H\e[2J");
}

#endif //UTILIDADES_H//

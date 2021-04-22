
#include "../include/Utilidades.h"
#include "../include/Filmes.h"
#include "../include/Usuario.h"
#include "../include/Historico.h"
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


    sscanf(data, "%d/%d/%d", &dia, &mes, &ano);

    

    if (ano >= 1900 && ano <= 9999)
    {

        if (mes >= 1 && mes <= 12)
        {
 
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

void Clean(int verbosity){
    if(verbosity){
        //system("clear");
    }
}

void MenuPrincipal(tUsuario* user, const int posuser,
                    const int verbosity, tMetadados* filmes){
    char *auxprincipal, *fraseProcura;
    auxprincipal = malloc(100 * sizeof(char));
    fraseProcura = malloc(129 * sizeof(char));
    tMetadados *FilmesProcurados;

    while(1){
        Clean(verbosity);
        MeuPrint("1.Listar filmes\n2.Meu perfil\n3.Procurar filmes\n4.Sair\n", verbosity);
        while(1){
            scanf("%s", auxprincipal);
            if(strcmp(auxprincipal, "1") == 0){
                Clean(verbosity);
                ListaFilmes(filmes, verbosity, user, posuser);
                break;
            }
            else if(strcmp(auxprincipal, "2") == 0){
                if(MeuPerfil(user, posuser, verbosity, filmes) == 1){
                    free(auxprincipal);
                    free(fraseProcura);
                    return;
                }
                else{
                    break;
                }
            }
            else if(strcmp(auxprincipal, "3") == 0){
                Clean(verbosity);
                MeuPrint("Digite a palavra/frase procurada: ", verbosity);
                scanf("%s", fraseProcura);
                FilmesProcurados = ProcuraFilmes(filmes, fraseProcura);
                Clean(verbosity);
                ListaFilmes(FilmesProcurados, verbosity, user, posuser);
                
                free(FilmesProcurados);
                break;
            }
            else if(strcmp(auxprincipal, "4") == 0){
                free(auxprincipal);
                free(fraseProcura);
                return;
            }
            else{
                MeuPrint("Digite uma opcao valida.\n", verbosity);
            }
        }
    }


}

void MenuLogin(tUsuario* users, const int verbosity, tMetadados* filmes, 
                int *tamUser, int *userAtivos){
    
    int PosUser;
    char* auxlogin;
    auxlogin = malloc(100 * (sizeof(char)));

    while(1){
        Clean(verbosity);
        MeuPrint("1.Login\n2.Cadastro\n3.Sair\n", verbosity); 
        while(1){
            scanf("%s", auxlogin);
            if(strcmp(auxlogin, "1") == 0){
                PosUser = Login(users, verbosity, userAtivos);            
                if(PosUser == -1){
                    break;
                }
                else{
                    MenuPrincipal(users, PosUser, verbosity, filmes);
                    break;
                }
            }
            else if(strcmp(auxlogin, "2") == 0){
                getchar();
                users = CadastraUsuario(verbosity, 
                        users, tamUser, userAtivos);
                break;
            }
            else if(strcmp(auxlogin, "3") == 0){
                free(auxlogin); 
                
                return;
            }
            else{
                MeuPrint("Digite uma opcao valida.\n", verbosity);
            }
        } 
    }
}

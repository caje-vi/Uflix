#include "../include/Usuario.h"

#define ARQUIVOUSUARIO "data/usuarios.csv"
#define TAMANHO 20

//static char ARQUIVOUSUARIO[] = "data/usuarios.csv";

static unsigned int QUANTIDADEDEUSUARIOS;

typedef struct Usuario
{
    char *login;
    char *password;
    int Ativa;
    int Id;
    //historico
}tUsuario;

tUsuario *CarregaUsuarios(){
    FILE *arquivo;
    tUsuario *user;
    char aux[1000], koe[20];
    int i=0, tam, k;
    user = malloc(TAMANHO * sizeof(tUsuario));
    VerificaPonteiro(user);
    QUANTIDADEDEUSUARIOS = TAMANHO;
    arquivo = fopen(ARQUIVOUSUARIO, "r");

    if(arquivo == NULL){
        user[0].Id = -1;
        fclose(arquivo);
        return user;
    }

    else{
        while(fgets(aux, sizeof(aux), arquivo) != NULL){
            user[i].login = strdup(strtok(aux, ","));
            VerificaPonteiro(user[i].login);
            user[i].password = strdup(strtok(NULL, ",\n"));
            VerificaPonteiro(user[i].password);
            tam = strlen(user[i].login) + strlen(user[i].password) + 2;
            if(aux[tam] == '\0'){
                for(k=1; k<= QUANTIDADEDEUSUARIOS +1; k++){
                    if(VerificaId(user, k) == -1){
                        user[i].Id = k;
                        user[i].Ativa = 1;
                        user[i].Ativa = 1;
                        break;
                    }
                }
            }
            else{
                user[i].Id = atoi(strtok(NULL, ",\n"));
                user[i].Ativa = atoi(strtok(NULL, "\n"));
            }

            printf("%d \n", user[i].Id);

            i++;

            if(i == QUANTIDADEDEUSUARIOS){
                QUANTIDADEDEUSUARIOS += TAMANHO; 
                user = realloc(user, sizeof(tUsuario) * QUANTIDADEDEUSUARIOS);
            }
        }
        user[i].Id = -1;
        fclose(arquivo);
        return user;
    }

}

tUsuario CadastrasUsuario(int verbosity, tUsuario *user){
    int i;
    char login[1000], senha[1000];
    for(i=0; i<QUANTIDADEDEUSUARIOS; i++){
        if(user[i].Id == -1){
            if(verbosity){
                printf("Usuario: ");
            }
            fgets(login, 1000, stdin);
            if(VerificaAlphaNum(login)){

            }
        }
    }
}

static int VerificaAlphaNum(char *x){
    int i;
    for(i=0; x[i] != '\0'; i++){
        if(!isalnum(x[i])){
            return 0;
        }
    }
    return 1;
}

static int VerificaLogin(tUsuario *user, char *x){
    int i;
    for(i=0; user[i].Id != -1; i++){
        if(strcmp(x, user[i].login) == 0){
            return 1;
        }
    }
    return 0;
}

void DestroyUsuario(tUsuario *x){
    int i;
    for(i=0; i<QUANTIDADEDEUSUARIOS; i++){
        free(x->login);
        free(x->password);
    }
    free(x);
}

static int VerificaId(tUsuario *x, unsigned int test){
    int i;
    for(i=0; x[i].Id != -1; i++){
        if(x[i].Id == test){
            return i;
        }
    }
    return -1;
}

static void VerificaPonteiro(void *x){
    if(x == NULL){
        printf("Ponterio nao alocado\n");
        exit(1);
    }
}
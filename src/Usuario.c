#include "../include/Usuario.h"

#define ARQUIVOUSUARIO "data/usuarios.csv"
#define TAMANHO 20



typedef struct Usuario
{
    char *login;
    char *password;
    int Ativa;
    //historico
}tUsuario;

void ImprimeAllUser(tUsuario *x, int *qtdUser){
    int i=0;

    for(i=0; i<*qtdUser; i++){
        printf("%s - %s - %d\n", x[i].login, x[i].password, x[i].Ativa);
    }
    printf("%d\n\n", *qtdUser);
}

static void MeuPrint(char *imprime, int verbosity){
    if(verbosity){
        printf("%s", imprime);
    }
}

tUsuario *CarregaUsuarios(int *tamUser, int *qtdUser){
    FILE *arquivo;
    tUsuario *user;
    char aux[1000];
    int i=0;
    user = malloc(TAMANHO * sizeof(tUsuario));
    VerificaPonteiro(user);
    *tamUser = TAMANHO;
    arquivo = fopen(ARQUIVOUSUARIO, "r");

    if(arquivo == NULL){
        fclose(arquivo);
        *qtdUser = 0;
        return user;
    }

    else{
        while(fgets(aux, sizeof(aux), arquivo) != NULL){
            user[i].login = strdup(strtok(aux, ","));
            VerificaPonteiro(user[i].login);
            user[i].password = strdup(strtok(NULL, ","));
            VerificaPonteiro(user[i].password);
            user[i].Ativa = atoi(strtok(NULL, ",\n"));
            printf("%d\n", i);
            

            i++;

            if(i == *tamUser){
                printf("koe\n");
                *tamUser += TAMANHO;

                user = realloc(user, sizeof(tUsuario) * (*tamUser));
            }
        }
        *qtdUser = i;

        fclose(arquivo);
        return user;
    }

}

tUsuario *CadastraUsuario(const int verbosity, tUsuario *user, int *tamUser, int *qtdUser){
    int i, k;
    char login[100], senha[100], confirmacao[100];
    MeuPrint("Usuario: ", verbosity);
    fgets(login, 100, stdin);
    login[strlen(login) - 1] = '\0';//retira o \n
    if(VerificaAlphaNum(login)){//verifica alpha numerico
        if(VerificaLogin(user, login, qtdUser)){//verifica se ja existe o mesmo login
            MeuPrint("Senha: ", verbosity);
            fgets(senha, 100, stdin);
            senha[strlen(senha) - 1] = '\0';//retira o \n
            if(VerificaAlphaNum(senha)){//verifica senha alpha numerica
                MeuPrint("Confirmar senha: ", verbosity);
                fgets(confirmacao, 100, stdin);
                confirmacao[strlen(confirmacao) - 1] = '\0';//retira o \n
                if(strcmp( senha, confirmacao) == 0){//verifica se a confirmacao é igual
                    user[(*qtdUser)].password = strdup(senha);
                    user[(*qtdUser)].Ativa = 1;
                    user[(*qtdUser)].login = strdup(login);
                    printf("%d\n", *qtdUser);
                    *qtdUser += 1;
                    printf("%d\n", *qtdUser);
                }
                else{
                    printf("Senha incorreta.\n");
                    return user;
                }
            }
            else{
                printf("Senha fora do padrao.\n");
                return user;
            }
        }
        else{
            printf("Usuario ja cadastrado.\n");
            return user;
        }
        
    }
    else{
        printf("Usuario fora do padrao.\n");
        return user;
    }
    if(*qtdUser == *tamUser){//aumenta em TAMNHO o ponteiro se for o ultimo usuario disponiivel
        *tamUser += TAMANHO;
        user = realloc(user, sizeof(tUsuario) * (*tamUser));
    }

    return user;    
}

void SalvaDadosUser(tUsuario *user, int *qtdUser){
    int i;
    FILE *arquivo;
    arquivo = fopen(ARQUIVOUSUARIO, "w");
    if(arquivo == NULL){
        printf("Arquivo para salvar nao foi aberto");
        exit(1);
    }

    for(i=0; i<*qtdUser; i++){
        fprintf(arquivo, "%s,%s,%d\n", 
        user[i].login, user[i].password, user[i].Ativa);
    }
    fclose(arquivo);
}

int Login(tUsuario *user, const int verbosity, int *qtdUser){
    int i;
    char login[100], senha[100];
    MeuPrint("Login: ", verbosity);
    scanf("%s", login);
    for(i=0; i< *qtdUser; i++){
        if(strcmp(login, user[i].login) == 0 && user[i].Ativa){
            MeuPrint("Senha: ", verbosity);
            scanf("%s", senha);
            if(strcmp(senha, user[i].password) == 0){
                return i;
            }
            else{
                printf("Senha incorreta.\n");
                return -1;
            }
        }

    }
    printf("Usuario nao cadastado.\n");
    return -1;
}

void ExcluirConta(tUsuario *user, const int posicao){
    user[posicao].Ativa = 0;
}

static int VerificaAlphaNum(const char *x){
    int i;
    for(i=0; x[i] != '\0'; i++){
        if(!isalnum(x[i])){
            return 0;
        }
    }
    return 1;
}

static int VerificaLogin(tUsuario *user, const char *x, int *qtdUser){
    int i;
    for(i=0; i<*qtdUser; i++){
        if(strcmp(x, user[i].login) == 0){
            return 0;
        }
    }
    return 1;
}

void DestroyUsuario(tUsuario *x, int *tamUser){
    int i;
    for(i=0; i<*tamUser; i++){
        free(x[i].login);
        free(x[i].password);
    }
    free(x);
}

static void VerificaPonteiro(void *x){
    if(x == NULL){
        printf("Ponterio nao alocado\n");
        exit(1);
    }
}
#include "../include/Utilidades.h"
#include "../include/Usuario.h"
#include "../include/Historico.h"
#include "../include/Filmes.h"

#define ARQUIVOUSUARIO "data/usuarios.csv"
#define TAMANHO 30



typedef struct Usuario
{
    char *login;
    char *password;
    int Ativa;
    tHistorico *historico;
    int *tamHistorico;
}tUsuario;

tUsuario *CarregaUsuarios(int *tamUser, int *qtdUser){
    FILE *arquivo;
    tUsuario *user;
    char *aux;
    int i=0;
    aux = malloc(10000 * sizeof(char));
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
        while(fgets(aux, 10000, arquivo) != NULL){
            user[i].login = strdup(strtok(aux, ","));
            VerificaPonteiro(user[i].login);
            user[i].password = strdup(strtok(NULL, ","));
            VerificaPonteiro(user[i].password);
            user[i].Ativa = atoi(strtok(NULL, ",\n"));
            user[i].tamHistorico = malloc(sizeof(int));
            user[i].historico = CarregaHistorico(strtok(NULL, "\n"), user[i].tamHistorico);
            

            

            i++;

            if(i == *tamUser){
                *tamUser += TAMANHO;

                user = realloc(user, sizeof(tUsuario) * (*tamUser));
            }
        }
        *qtdUser = i;

        free(aux);
        fclose(arquivo);
        return user;
    }

}

tUsuario *CadastraUsuario(const int verbosity, tUsuario *user, int *tamUser, int *qtdUser){
    char login[129], senha[129], confirmacao[129];
    Clean(verbosity);
    MeuPrint("Usuario: ", verbosity);
    fgets(login, 129, stdin);
    login[strlen(login) - 1] = '\0';//retira o \n
    if(VerificaAlphaNum(login)){//verifica alpha numerico
        if(VerificaLogin(user, login, qtdUser)){//verifica se ja existe o mesmo login
            MeuPrint("Senha: ", verbosity);
            fgets(senha, 129, stdin);
            senha[strlen(senha) - 1] = '\0';//retira o \n
            if(VerificaAlphaNum(senha)){//verifica senha alpha numerica
                MeuPrint("Confirmar senha: ", verbosity);
                fgets(confirmacao, 129, stdin);
                confirmacao[strlen(confirmacao) - 1] = '\0';//retira o \n
                if(strcmp( senha, confirmacao) == 0){//verifica se a confirmacao é igual
                    user[(*qtdUser)].password = strdup(senha);
                    user[(*qtdUser)].Ativa = 1;
                    user[(*qtdUser)].login = strdup(login);
                    user[(*qtdUser)].historico = alocaHistorico(TAMANHO);
                    int *aux = malloc(sizeof(int));
                    *aux = TAMANHO;
                    user[(*qtdUser)].tamHistorico = aux;
                    setUltimoHistorico(user[(*qtdUser)].historico, 0);
                    *qtdUser += 1;
                }
                else{
                    MeuPrint("Senha incorreta.\n", verbosity);
                    return user;
                }
            }
            else{
                MeuPrint("Senha fora do padrao.\n", verbosity);
                return user;
            }
        }
        else{
            MeuPrint("Usuario ja cadastrado.\n", verbosity);
            return user;
        }
        
    }
    else{
        MeuPrint("Usuario fora do padrao.\n", verbosity);
        return user;
    }
    //aumenta em TAMNHO o ponteiro se for o ultimo usuario disponiivel
    if(*qtdUser == *tamUser){
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
        fprintf(arquivo, "%s,%s,%d", 
        user[i].login, user[i].password, user[i].Ativa);
        salvaHistorico(arquivo, user[i].historico);
    }
    fclose(arquivo);
}

int Login(tUsuario *user, const int verbosity, int *qtdUser){
    int i;
    char login[129], senha[129];
    Clean(verbosity); 
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
                MeuPrint("Senha incorreta.\n", verbosity);
                return -1;
            }
        }

    }
    MeuPrint("Usuario nao cadastado.\n", verbosity);
    return -1;
}

void ExcluirConta(tUsuario *user, const int posicao){
    user[posicao].Ativa = 0;
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
        free(x[i].tamHistorico);
        free(x[i].historico);
    }
    free(x);
}

void adicionarHistorico(tUsuario* user, const int posUser, float nota,
                         int idfilme, char *data){
    user[posUser].historico = AddHistorico(user[posUser].historico, user[posUser].tamHistorico, nota, idfilme, data);
}

void *DevolveHistorico(tUsuario *users, const int PosUser){
    return users[PosUser].historico;
}

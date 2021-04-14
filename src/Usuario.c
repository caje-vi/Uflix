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

void ImprimeAllUser(tUsuario *x, int *qtdUser){
    int i=0;

    for(i=0; i<*qtdUser; i++){
        printf("\n%s - %s - %d\t", x[i].login, x[i].password, x[i].Ativa);
        ImprimeHistorico(x[i].historico);
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
            user[i].tamHistorico = malloc(sizeof(int));
            user[i].historico = CarregaHistorico(strtok(NULL, "\n"), user[i].tamHistorico);
            

            

            i++;

            if(i == *tamUser){
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


int VerificaLogin(tUsuario *user, const char *x, int *qtdUser){
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
    AddHistorico(user[posUser].historico, user[posUser].tamHistorico, nota, idfilme, data);
}

int MeuPerfil(tUsuario *users, const int PosUser, const int verbosity, tMetadados *filmes){
    char *auxperfil;
    auxperfil = malloc(100 * sizeof(char));


    while(1){
        Clean(verbosity)
        MeuPrint("D ou N- Histórico ordenado por data ou por Nota\n2. Excluir minha conta\n3. Voltar\n", verbosity);
        while(1){
            scanf("%s", auxperfil);
            if(strcasecmp(auxperfil, "D") == 0){
                OrdenaData(users[PosUser].historico);
                ImprimeHistorico(users[PosUser].historico, filmes);
                break;
            }
            else if(strcasecmp(auxperfil, "N") == 0){
                OrdenaNota(users[PosUser].historico);
                ImprimeHistorico(users[PosUser].historico, filmes);
                break;
            }
            else if(strcmp(auxperfil, "2") == 0){
                ExcluirConta(users, PosUser);
                return 1;

            }
            else if(strcmp(auxperfil, "3") == 0){
                return 0;
            }
            else{
                MeuPrint("Digite uma opcao valida.\n", verbosity);
            }
        }
    }




}

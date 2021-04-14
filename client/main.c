#include "../include/Utilidades.h"
#include "../include/Filmes.h"
#include "../include/Usuario.h"
#include "../include/Historico.h"

int main(int argc, char *argv[]){

    int verbosity = 1, PosUser, *tamUser = 0 , *userAtivos = 0;
    char* auxlogin;
    
    tMetadados* filmes;
    tUsuario *users;

    filmes = CarregaMetadados();
    tamUser = malloc(sizeof(int));
    userAtivos = malloc(sizeof(int));
    users = CarregaUsuarios(tamUser, userAtivos);
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
                SalvaDadosUser(users, userAtivos);
                DestroyUsuario(users, userAtivos);
                DestroyMetadados(filmes);
                
                free(tamUser);
                free(userAtivos);
                free(auxlogin);
                
                return 0;
            }
            else{
                MeuPrint("Digite uma opcao valida.\n", verbosity);
            }
        } 
    }
};

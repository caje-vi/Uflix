#include "../include/Filmes.h"
#include "../include/Usuario.h"
#include "../include/Historico.h"

int main(int argc, char *argv[]){

    int verbosity = 1, PosUser, *tamUser = 0 , *userAtivos = 0;
    /*tamUser = malloc(sizeof(int));
    userAtivos = malloc(sizeof(int));
    tUsuario *users;

    users = CarregaUsuarios(tamUser, userAtivos);
    CadastraUsuario(verbosity, users, tamUser, userAtivos);
    SalvaDadosUser(users, userAtivos);
    ImprimeAllUser(users, userAtivos);
    DestroyUsuario(users, tamUser);
    free(tamUser);
    free(userAtivos);
    */
    /*;
    int i = 0;
    *for(i; i < 10; i++){
        
            printf("%s ", filmes[i].titulo);
            printf("%d ", filmes[i].duracao);
            printf("%d ", filmes[i].ano);
            printf("%.2f ", filmes[i].nota);
            printf("%s \n", filmes[i].descri);
    }*/
    tMetadados* filmes;
    filmes = CarregaMetadados();
    ListaFilmes(filmes);
    

return 0;
}

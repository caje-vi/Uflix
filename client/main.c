#include "../include/Utilidades.h"
#include "../include/Filmes.h"
#include "../include/Usuario.h"
#include "../include/Historico.h"

int main(int argc, char *argv[]){

    int verbosity, *tamUser, *userAtivos;
    tMetadados* filmes;
    tUsuario *users;

    if(argc == 2){
        verbosity = atoi(argc[1]);
    }
    else{
        verbosity = 1;
    }

    filmes = CarregaMetadados();
    users = CarregaUsuarios(tamUser, userAtivos);
    
    MenuLogin(users, verbosity, filmes, tamUser, userAtivos);

    SalvaDadosUser(users, userAtivos);
    DestroyUsuario(users, userAtivos);
    DestroyMetadados(filmes);
    
    
};

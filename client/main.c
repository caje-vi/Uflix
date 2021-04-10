#include "../include/Usuario.h"

int main(int argc, char *argv[]){

    int verbosity, PosUser, *tamUser = 0, *userAtivos = 0;
    tamUser = malloc(sizeof(int));
    userAtivos = malloc(sizeof(int));

    verbosity = atoi(argv[1]);
    tUsuario *user;
    user = CarregaUsuarios(tamUser, userAtivos);
    user = CadastraUsuario(verbosity, user, tamUser, userAtivos);
    user = CadastraUsuario(verbosity, user, tamUser, userAtivos);
    //PosUser = Login(user, verbosity);
    ImprimeAllUser(user, userAtivos);
    SalvaDadosUser(user, userAtivos);
    DestroyUsuario(user, tamUser);
    

return 0;
}
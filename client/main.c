#include "../include/Usuario.h"

int main(int argc, char *argv[]){

    int verbosity, PosUser;
    verbosity = atoi(argv[1]);
    tUsuario *user;
    user = CarregaUsuarios();
    user = CadastraUsuario( verbosity, user);
    //PosUser = Login(user, verbosity);
    ImprimeAllUser(user);
    SalvaDadosUser(user);
    

return 0;
}
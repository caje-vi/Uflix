#include "../include/Filmes.h"
#include "../include/Usuario.h"
int main(int argc, char *argv[]){

    //int verbosity, PosUser, *tamUser = 0, *userAtivos = 0;

    tMetadados* filmes;
    int i = 0;
    filmes = CarregaMetadados();
    /*for(i; i < 10; i++){
        
            printf("%s ", filmes[i].titulo);
            printf("%d ", filmes[i].duracao);
            printf("%d ", filmes[i].ano);
            printf("%.2f ", filmes[i].nota);
            printf("%s \n", filmes[i].descri);
    }*/
    ListaFilmes(filmes);
    

return 0;
}

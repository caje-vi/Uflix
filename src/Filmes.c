#include "../include/Filmes.h"
#include <ctype.h>
#include <features.h>

typedef struct Metadados
{
    char *titulo;
    char *descri;
    int duracao;
    int ano;
    float nota;
} tMetadados;

void ListaFilmes(tMetadados* Lista){
    
    int i;
    int id;
    int proximo;

    while(1){
        id = 1;
        while(1){
            for(i = 1; i <= 10; i++){ 
                if(Lista[id - 1].titulo == NULL){
                    printf("\nFim dos filmes disponiveis \n");
                    break;
                }
            printf("%d - %s\n",  id, Lista[id - 1].titulo);
            id++;
            }
            proximo = EntradaProximo(id);

            if(proximo == -1){
                id -= 10;
                break;
            }
            if(proximo == -2) {
                continue;
            }
            else if(proximo >= 0) {
                if(Dados(proximo, Lista) == 1){
                    Avaliacao(Lista, proximo);
                }
                else {
                    id -= 10;
                };
            }
        }
        break;
    }

}

int EntradaProximo(int n){

    char opcao;
    int saida = 0;
    int i;
        printf("\nDigite o id do filme que deseja assitir \n");
        printf("M - mais filmes \n");
        printf("0 - voltar \n");

        while(1) {
            scanf("%s", &opcao);
            if(opcao == 'm' || opcao == 'M'){
                saida = -2;
                break;
            }
            i = atoi(&opcao);
            if(i == 0){
                saida = -1;
                break;
            }
            else if(n - 10 <= i && i < n){
                saida =  i - 1;
                break;
            }
            else{
                printf("Digite uma entrada valida \n");
            }
        }   
        Clean();
return saida;
};

tMetadados* CarregaMetadados(){
    FILE *arquivo;
    tMetadados *filme;
    char aux[1000];
    int i=0;
    filme = malloc(1000 * sizeof(tMetadados));
    arquivo = fopen(LISTAFILME, "r");

    if(arquivo == NULL){
        fclose(arquivo);
    }

    else{
        while(fgets(aux, sizeof(aux), arquivo) != NULL){
            filme[i].titulo = strdup(strtok(aux, ","));
            filme[i].duracao = atoi(strtok(NULL, ","));
            filme[i].ano = atoi(strtok(NULL, ","));
            filme[i].nota = atoi(strtok(NULL, ","));
            filme[i].descri = strdup(strtok(NULL, "\""));
            i++;
        }
        

    }
    fclose(arquivo);
    return filme;

return filme;
};

int Dados(int i, tMetadados* filme) {

    int opcao = 0;

    printf("Titulo: %s \n", filme[i].titulo);
    printf("Ano: %d \n", filme[i].ano);
    printf("Duracao: %d minutos \n", filme[i].duracao);
    printf("Avalicacao %.2f \n", filme[i].nota);
    printf("Descricao: %s \n", filme[i].descri);

    printf("\n 1- Assistir \n");
    printf("\n 2- Voltar \n");

    while(1){
        scanf("%d", &opcao);
        if(opcao != 1 && opcao != 2){
            printf("Digite um opcao valida \n");
        } 
        else{
            break;
        }
    }
    Clean();
return opcao;
};

void Avaliacao(tMetadados* Lista, int i){
    float nota;
    int dia;
    int mes;
    int ano;

    printf("O que achou de %s? De uma nota entre 0 e 10: ", Lista[i].titulo);
    scanf("%f", &nota);
    printf("\nData: ");
    scanf("%d/%d/%d", &dia, &mes, &ano);
};

void Clean(){
    printf("\e[1;1H\e[2J");
};

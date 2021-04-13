#include "../include/Filmes.h"
#include "../include/Utilidades.h"

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
        id = 0;
        while(1){
            for(i = 1; i <= 10; i++){ 
                id++;
                if(Lista[id - 1].titulo == NULL){
                    printf("\nFim dos filmes disponiveis \n");
                    break;
                }
            printf("%d - %s\n",  id, Lista[id - 1].titulo);
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

    char opcao[100];
    int saida = 0;
    int i;
        printf("\nDigite o id do filme que deseja assitir \n");
        printf("M - mais filmes \n");
        printf("0 - voltar \n");

        while(1) {
            scanf("%s", opcao);
            if(!(strcmp("m", opcao)) || !(strcmp("M", opcao))){
                saida = -2;
                break;
            }
            else if('a' <= opcao[1] && opcao[1] <= 'z') break;
            i = atoi(opcao);
            if(i == 0){
                saida = -1;
                break;
            }
            else if(n - 9 <= i && i <= n){
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
            filme[i].ano = atoi(strtok(NULL, ","));
            filme[i].duracao = atoi(strtok(NULL, ","));
            filme[i].nota = atoi(strtok(NULL, ","));
            filme[i].descri = strdup(strtok(NULL, "\""));
            i++;
        };
        filme[i].titulo = NULL;
    }
    fclose(arquivo);

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
    while(1){
        scanf("%f", &nota);
        if(nota < 0 && 10 < nota){
            printf("Digite uma nota valida \n");
        }
        else{
            break;
        }
    };
    printf("\nData: ");
    scanf("%d/%d/%d", &dia, &mes, &ano);
};

void Clean(){
    printf("\e[1;1H\e[2J");
};

static void MeuPrint(char *imprime, int verbosity){
    if(verbosity){
        printf("%s", imprime);
    }
}

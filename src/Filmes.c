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

void ListaFilmes(tMetadados* Lista, const int verbosity){
    
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
            proximo = EntradaProximo(id, verbosity);

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

int EntradaProximo(int n, const int verbosity){

    char opcao[100];
    int saida = 0;
    int i;
        MeuPrint("\nDigite o id do filme que deseja assitir \n", verbosity);
        MeuPrint("M - mais filmes \n", verbosity);
        MeuPrint("0 - voltar \n", verbosity);

        while(1) {
            scanf("%s", opcao);
            if(VerificaAlpha(opcao)){
                if((strcasecmp("m", opcao) == 0)){
                    saida = -2;
                    break;
                }
            }
            if(VerificaNum(opcao)){
                i = atoi(opcao);
                if(i == 0){
                    saida = -1;
                    break;
                }
                else if(n - 9 <= i && i <= n){
                    saida =  i - 1;
                    break;
                }
            }
            printf("Digite uma entrada valida \n");
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

    int saida;
    char opcao[100];

    printf("Titulo: %s \n", filme[i].titulo);
    printf("Ano: %d \n", filme[i].ano);
    printf("Duracao: %d minutos \n", filme[i].duracao);
    printf("Avalicacao %.2f \n", filme[i].nota);
    printf("Descricao: %s \n", filme[i].descri);

    printf("\n 1- Assistir \n");
    printf("\n 2- Voltar \n");

    while(1){
        scanf("%s", opcao);
        if((strcmp("1", opcao) != 0) && (strcmp("2", opcao) != 0)){
            printf("Digite um opcao valida \n");
        } 
        else{
            break;
        }
    }
    saida = atoi(opcao);
    Clean();
return saida;
};

void Avaliacao(tMetadados* Lista, int i){

    char data[15];
    char nota[15];

    printf("O que achou de %s? De uma nota entre 0 e 10: ", Lista[i].titulo);

    printf("\nNota: ");
    while(1){
        scanf("%s", nota);
        if(!CheckNota(nota)){
            printf("Digite uma nota valida\n");
        }
        else{
            break;
        }
    }

    printf("\nData: ");
    while(1){
        scanf("%s", data);
        if(!ValidaData(data)){
            printf("Digite uma data valida\n");
        }
        else{
            break;
        }

    };
Clean();
}

int CheckNota(const char* nota){
    int i;
    int y;
    int ponto = 0;

    for(i=0; nota[i] != '\0'; i++){
        if(nota[i] == '.'){
            ponto++;
        }
    }
    if(VerificaNum(nota) && ponto <= 1){
       y = atoi(nota); 
       if(0 <= y && y <= 10){
           return 1;
       }
    }
return 0;
};

tMetadados *ProcuraFilmes(tMetadados *todos, char *frase){
    int i, tamanho = 30, alocados = 0;
    tMetadados *filmes;

    filmes = malloc(sizeof(tMetadados) * tamanho);
    for(i=0; todos[i].titulo != NULL; i++){
        if(strstr(todos[i].titulo, frase) != NULL){
            filmes[alocados] = todos[i];
            alocados++;
        }

        if(alocados == tamanho){
            tamanho += 30;
            filmes = realloc(filmes, sizeof(tMetadados) * tamanho);
        }
    }
    filmes[alocados].titulo = NULL;
    return filmes;
};

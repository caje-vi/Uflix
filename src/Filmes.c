#include "../include/Filmes.h"
#include "../include/Utilidades.h"
#include "../include/Usuario.h"

typedef struct Metadados
{
    char *titulo;
    char *descri;
    int duracao;
    int ano;
    float nota;
    int Id;
} tMetadados;

void ListaFilmes(tMetadados* Lista, const int verbosity, tUsuario* user, const int posuser){
    
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
                break;
            }
            if(proximo == -2) {
                continue;
            }
            else if(proximo >= 0) {
                if(Dados(proximo, Lista, verbosity) == 1){
                    Avaliacao(Lista, proximo, verbosity, user, posuser);
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
            MeuPrint("Digite uma entrada valida \n", verbosity);
        }   
        Clean(verbosity);
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
            filme[i].Id = i;
            i++;
        };
        filme[i].titulo = NULL;
    }
    fclose(arquivo);

return filme;
};

int Dados(int i, tMetadados* filme, const int verbosity) {

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
    Clean(verbosity);
return saida;
};

void Avaliacao(tMetadados* Lista, int idfilme, const int verbosity, tUsuario* user, const int posuser){

    char *data;
    char *nota;
    char *frase;
    float notaNum;
    data = malloc(15 * sizeof(char));
    nota = malloc(15 * sizeof(char));
    frase = malloc(200 * sizeof(char));

    sprintf(frase, "O que achou de %s? De uma nota entre 0 e 10: ", Lista[idfilme].titulo);
    MeuPrint(frase, verbosity);
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
    notaNum = atof(nota);
    

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
    adicionarHistorico(user, posuser, notaNum, Lista[idfilme].Id, data);
    free(nota);
    free(frase);
    free(data);
Clean(verbosity);
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
    if(VerificaFloat(nota) && ponto <= 1){
       y = atof(nota); 
       if(y == -1){
           return 1;
       }
       if(0 <= y && y <= 10){
           return 1;
       }
    }
return 0;
};

int VerificaFloat(const char* x){
    int i;
    for(i=0; x[i] != '\0'; i++){
        if(!(('0' <= x[i] && x[i] <= '9') || x[i] == '.')){
            return 0;
        }
    }
    return 1;
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

void DestroyMetadados(tMetadados *filmes){
    int i;
    for(i=0; filmes[i].titulo != NULL; i++){
        free(filmes[i].titulo);
        free(filmes[i].descri);
    }
    free(filmes);
};

void ImprimeTitulo(int idfilme, tMetadados *filmes){
    printf("%s: ", filmes[idfilme].titulo);
};

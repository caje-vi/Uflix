#include "../include/Historico.h"

#define TAMANHO 30

typedef struct Historico{
    float nota;
    int id_filme;
    int data_somada;
}tHistorico;

void ImprimeHistorico(tHistorico *x){
    int i;
    char *data;
    for(i=0; x[i].id_filme != -1; i++){
        data = strdata(x[i].data_somada);
        printf("%d - %.2f - %s;", x[i].id_filme, x[i].nota, data);
        free(data);
    }
}

tHistorico *CarregaHistorico(char *historico, int *tamHistorico){

    int dia, mes, ano, i=0;
    char *token;

    tHistorico *novo;
    *tamHistorico = TAMANHO;

    novo = malloc(sizeof(tHistorico) * (*tamHistorico));
    if(historico == NULL){
        novo[0].id_filme = -1;
        return novo;
    }

    token = strtok(historico, ",");
    while(1){
        novo[i].id_filme = atoi(token);

        token = strtok(NULL, ",");
        novo[i].nota = atof(token);

        token = strtok(NULL, ",");
        sscanf(token, "%2d/%2d/%4d", &dia, &mes, &ano);
        novo[i].data_somada = SomaData(dia, mes, ano);


        i++;
        if(i == (*tamHistorico)){
            *tamHistorico += TAMANHO;
            novo = realloc(novo, (*tamHistorico));
        }

        token = strtok(NULL, ",\0");
        if(token == NULL){
            novo[i].id_filme = -1;
            return novo;
        }
    }



}

void salvaHistorico(FILE *arq, tHistorico *dados){
    int i;
    char *data;
    for(i=0; dados[i].id_filme != -1; i++){
        data = strdata(dados[i].data_somada);
        fprintf(arq, ",%d,%.2f,%s", dados[i].id_filme, dados[i].nota, data);
        fprintf(arq,",13,4.32,12/43/1232" );
        free(data);
    }
    fprintf(arq, "\n");
}

int SomaData(int dia, int mes, int ano){
    int transformada;
    transformada = (ano * 10000) + (mes * 100) + dia;
    return transformada;
}

char *strdata(int somada){
    char *data;
    int dia, mes, ano, dma;
    dia = somada % 100;
    mes = (somada % 10000) / 100;
    ano = somada / 10000;
    data = malloc(sizeof(char) * 11);

    sprintf(data, "%02d/%02d/%04d", dia, mes, ano);
    return data;

}

tHistorico *alocaHistorico(int tam){
    tHistorico *x = malloc(sizeof(tHistorico) * tam);
    return x;
}

void setUltimoHistorico(tHistorico *x, int pos){
    x[pos].id_filme = -1;
}

void *OrdenaData(tHistorico *dados){
    int tamanho, troca, i, j;
    tHistorico memoria;
    for(i=0; dados[i].id_filme != -1; i++){}
    tamanho = i;
	troca=1; /*A variável "troca" será a verificação da troca em cada passada*/
	for(j=tamanho-1; (j>=1) && (troca==1); j--){
		troca=0; /*Se o valor continuar 0 na próxima passada quer dizer que não houve troca e a função é encerrada.*/
		for(i=0; i<j; i++){
				if(dados[i].data_somada>dados[i+1].data_somada){
					memoria=dados[i];
					dados[i]=dados[i+1];
					dados[i+1]=memoria;
					troca=1; /*Se houve troca, "troca" recebe 1 para continuar rodando.*/
			}
		}
	}


}

void *OrdenaNota(tHistorico *dados){
    int tamanho, troca, i, j;
    tHistorico memoria;
    for(i=0; dados[i].id_filme != -1; i++){}
    tamanho = i;
	troca=1; /*A variável "troca" será a verificação da troca em cada passada*/
	for(j=tamanho-1; (j>=1) && (troca==1); j--){
		troca=0; /*Se o valor continuar 0 na próxima passada quer dizer que não houve troca e a função é encerrada.*/
		for(i=0; i<j; i++){
				if(dados[i].nota>dados[i+1].nota){
					memoria=dados[i];
					dados[i]=dados[i+1];
					dados[i+1]=memoria;
					troca=1; /*Se houve troca, "troca" recebe 1 para continuar rodando.*/
			}
		}
	}


}

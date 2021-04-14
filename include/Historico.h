#ifndef HISTORICO_H
#define HISTORICO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Historico tHistorico;

void ImprimeHistorico(tHistorico *x);

tHistorico *CarregaHistorico(char *historico, int *tamHistorico);

void salvaHistorico(FILE *arq, tHistorico *dados);

int SomaData(int dia, int mes, int ano);

char *strdata(int somada);

tHistorico *alocaHistorico(int tam);

void setUltimoHistorico(tHistorico *x, int pos);

void *OrdenaData(tHistorico *dados);

void *OrdenaNota(tHistorico *dados);

tHistorico *AddHistorico(tHistorico *userHistorico, int *tam, float nota, int idfilme, char *data);





#endif // HISTORICO_H
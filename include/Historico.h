#ifndef HISTORICO_H
#define HISTORICO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Historico tHistorico;

void ImprimeHistorico(tHistorico *x);

tHistorico *CarregaHistorico(char *historico, int *tamHistorico);

int SomaData(int dia, int mes, int ano);

char *strdata(int somada);

tHistorico *alocaHistorico(int tam);

void setUltimoHistorico(tHistorico *x, int pos);





#endif // HISTORICO_H
#ifndef HISTORICO_H
#define HISTORICO_H

#define LISTAFILME "data/filmes-grande.csv"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Metadados tMetadados;

tMetadados* CarregaMetadados();

void ListaFilmes(tMetadados* Lista, const int verbosity);

int EntradaProximo(int n, const int verbosity);

int Dados(int i, tMetadados* filme);

void Avaliacao(tMetadados* Lista, int proximo);

void Clean();

int CheckAlpha(char* frase);

#endif //USUARIO_H//

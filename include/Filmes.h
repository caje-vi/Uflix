#ifndef FILMES_H
#define FILMES_H

#define LISTAFILME "data/filmes-grande.csv"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Metadados tMetadados;

tMetadados* CarregaMetadados();

void ListaFilmes(tMetadados* Lista, const int verbosity);

tMetadados *ProcuraFilmes(tMetadados *todos, char *frase);

int EntradaProximo(int n, const int verbosity);

int Dados(int i, tMetadados* filme, const int verbosity);

void Avaliacao(tMetadados* Lista, int proximo, const int verbosity);

int CheckNota(const char* nota);

void Clean();

int CheckAlpha(char* frase);

#endif //FILMES_H

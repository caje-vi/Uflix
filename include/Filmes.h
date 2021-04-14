#ifndef FILMES_H
#define FILMES_H

#define LISTAFILME "data/filmes-grande.csv"
#include "../include/Usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Metadados tMetadados;

tMetadados* CarregaMetadados();

void ListaFilmes(tMetadados* Lista, const int verbosity, tUsuario* user, const int posuser);

tMetadados *ProcuraFilmes(tMetadados *todos, char *frase);

int EntradaProximo(int n, const int verbosity);

int Dados(int i, tMetadados* filme, const int verbosity);

void Avaliacao(tMetadados* Lista, int idfilme, const int verbosity, tUsuario* user, const int posuser);

int CheckNota(const char* nota);

int VerificaFloat(const char* x);

void Clean();

int CheckAlpha(char* frase);

void DestroyMetadados(tMetadados *filmes);

#endif //FILMES_H

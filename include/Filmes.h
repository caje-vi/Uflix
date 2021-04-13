#ifndef HISTORICO_H
#define HISTORICO_H

#define LISTAFILME "data/filmes-grande.csv"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Metadados tMetadados;

tMetadados* CarregaMetadados();

tMetadados *ProcuraFilmes(tMetadados *todos, char *frase);

void ListaFilmes();

int EntradaProximo(int n);

int Dados(int i, tMetadados* filme);

void Avaliacao(tMetadados* Lista, int proximo);

int CheckNota(const char* nota);

void Clean();

int CheckAlpha(char* frase);

#endif //USUARIO_H//

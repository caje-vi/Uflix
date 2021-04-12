#ifndef HISTORICO_H
#define HISTORICO_H
#define LISTAFILME "data/filmes-grande.csv"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Metadados tMetadados;

tMetadados* CarregaMetadados();

void ListaFilmes();

int EntradaProximo(int n);

int Dados(int i, tMetadados* filme);

void Avaliacao(tMetadados* Lista, int proximo);

void Clean();
#endif //USUARIO_H//

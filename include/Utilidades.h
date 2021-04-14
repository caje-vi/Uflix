#ifndef UTILIDADES_H
#define UTILIDADES_H

#include "Filmes.h"

int VerificaAlphaNum(const char *x);

int VerificaAlpha(const char *x);

int VerificaNum(const char *x);

void VerificaPonteiro(void *x);

int ValidaData(const char *entrada);

void MeuPrint(char *imprime, int verbosity);

void Clean(int verbosity);

void MenuPrincipal(tUsuario* user, const int posuser, const int verbosity, tMetadados* filmes);

void MenuLogin(tUsuario* users, const int verbosity, tMetadados* filmes, int *tamUser, int *userAtivos);

int MeuPerfil(tUsuario *users, const int PosUser, const int verbosity, tMetadados *filmes);
#endif //UTILIDADES_H

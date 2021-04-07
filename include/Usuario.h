#ifndef USUARIO_H
#define USUARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct Usuario tUsuario;

void ImprimeAllUser(tUsuario *x);

static void MeuPrint(char *imprime, int verbosity);

tUsuario *CarregaUsuarios();

tUsuario *CadastraUsuario(const int verbosity, tUsuario *user);

void SalvaDadosUser(tUsuario *user);

int Login(tUsuario *user, const int verbosity);

void ExcluirConta(tUsuario *user, int posicao);

static int VerificaAlphaNum(const char *x);

static int VerificaLogin(tUsuario *user, const char *x);

void DestroyUsuario(tUsuario *x);

static void VerificaPonteiro(void *x);










#endif //USUARIO_H//
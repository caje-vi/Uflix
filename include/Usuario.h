#ifndef USUARIO_H
#define USUARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct Usuario tUsuario;

void DestroyUsuario(tUsuario *x);

tUsuario *CarregaUsuarios();

tUsuario CadastrasUsuario(int verbosity, tUsuario *user);

static int VerificaId(tUsuario *x, unsigned int test);

static void VerificaPonteiro(void *x);

static int VerificaAlphaNum(char *x);

static int VerificaLogin(tUsuario *user, char *x);




#endif //USUARIO_H//
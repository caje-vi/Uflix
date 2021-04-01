#ifndef USUARIO_H
#define USUARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARQUIVOUSUARIO "../data/usuarios"

typedef struct Usuario tUsuario;

void TestaPonteiroUsuario(tUsuario *x);

void DestroyUsuario(tUsuario *x);

tUsuario *CarregaUsuarios();



#endif //USUARIO_H//
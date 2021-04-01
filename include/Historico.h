#ifndef HISTORICO_H
#define HISTORICO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuario.h"

typedef struct Historico tHistorico;

void MenuHistorico();

void AddHistorico (Usuario* Id, int* IdFilme);

void OrdemNota (Usuario* Id, char Tipo);





#endif //USUARIO_H//

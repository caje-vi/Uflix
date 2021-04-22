#ifndef HISTORICO_H
#define HISTORICO_H

#include "Filmes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Historico tHistorico;

/**
 * @brief Imprime o historico lido ordenado de acordo como o usuario pediu.
 * @param *x Ponteiro de historico.
 * @param *filmes Ponteiro de metadados dos filmes.
 * @param verbosity Verbosidade do programa.
 */
void ImprimeHistorico(tHistorico *x, void *filmes, const int verbosity);

/**
 * @brief Carrega os historico salvo no arquivo Usuario.csv
 * Pré-Condição: A string esta nos formato ,histórico1,avaliação1,data1,histórico2,avaliação2,data2...
 * @param *historico String com a sequencia do historico.
 * @param *tamHistorico Tamanho do historico alocado.
 * @return Ponteiro de tHistorico alocado.
 */
tHistorico *CarregaHistorico(char *historico, int *tamHistorico);

/**
 * @brief Salva o historico no arquivo passado.
 * @param *arq Ponteiro do arquivo para ser salvo.
 * @param *dados Ponteiro de historico a ser salvo
 */
void salvaHistorico(FILE *arq, tHistorico *dados);

/**
 * @brief Cria um inteiro com a data no formato aaaammdd.
 * @param dia dia.
 * @param mes mes.
 * @param ano ano.
 * @return O dia, mes e ano somado no formato aaaammdd
 */
int SomaData(int dia, int mes, int ano);

/**
 * @brief Transforma um inteiro do tipo aaaammdd em uma string no formato dd/mm/aaaa.
 * Pré-Condição: O inteiro estar no formato aaaammdd.
 * Pós-condição: Uma string no formato dd/mm/aaaa, ela deve ser desalocada quando parar de usar.
 * @param somada inteiro com a data somada
 * @return String alocada com a data no formato dd/mm/aaaa.
 */
char *strdata(int somada);

/**
 * @brief Alloca um tHistorico do tamanho informado.
 * @param tam Tamanho do ponteiro alocado.
 * @return Ponteiro de tHistorico alocado.
 */
tHistorico *alocaHistorico(int tam);

/**
 * @brief Coloca -1 no Id_filme que e considerado o ultimo filme adicionado.
 * @param *x Ponteiro de tHistorico.
 * @param pos Posicao no array onde o Id_filme deve ser igualado a -1.
 */
void setUltimoHistorico(tHistorico *x, int pos);

/**
 * @brief Ordena o array de historico da menor data para maior.
 * @param *dados Ponteiro de historico a ser ordenado.
 */
void *OrdenaData(tHistorico *dados);

/**
 * @brief Ordena o array de historico da maior nota para a menor.
 * @param *dados Ponteiro de historico a ser ordenado.
 */
void *OrdenaNota(tHistorico *dados);

/**
 * @brief Adiciona um novo filme assistido ao historico.
 * Pré-Condição: A data tem que estar no formato dd/mm/aaaa.
 * @param *userHistorico Ponteiro do historico.
 * @param *tam Tamanho do historico alocado.
 * @param nota Nota dada pelo usuario ao filme.
 * @param idfilme Posicao do array de filmes do filme assistido.
 * @param *data String com a data data pelo usuario.
 * @return Ponteiro he historico, devolve um novo se for preciso realocar, caso nao precise devolve o mesmo.
 */
tHistorico *AddHistorico(tHistorico *userHistorico, int *tam, float nota, int idfilme, char *data);

#endif // HISTORICO_H
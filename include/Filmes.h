#ifndef FILMES_H
#define FILMES_H

#define LISTAFILME "data/filmes-grande.csv"

#include "Usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief Struct tMetadados 
 *
 * @var titulo
 * @var descri descricao do filme
 * @var duracao
 * @var ano
 * @var nota
 * @var Id linha do csv onde o filme se encontra
 *
 */
typedef struct Metadados tMetadados;

/**
 * @brief carrega os dados do csv da lista de filmes na memoria
 * @return Ponteiro de tMedadados
 */
tMetadados* CarregaMetadados();

/**
 * @brief Menu para se listar os filmes passados pelo ponteiro
 * @param Lista Ponteiro da lista de filmes
 * @param verbosity Verbosidade
 * @param user Ponteiro da lista de usuarios
 * @param posuser Inteiro correspondente a posicao do usuario dentro do array
 */
void ListaFilmes(tMetadados* Lista, const int verbosity, tUsuario* user, const int posuser);

/**
 * @brief Funcao para procurar filmes os quais contem paralavras passadas pelo 
 * parametro
 * @param todos Ponteiro para array de filmes
 * @param  frase string que sera procurada dentro dos titulos
 * @return  Ponteiro para array de filmes que possuem a frase no titulo
 */
tMetadados *ProcuraFilmes(tMetadados *todos, char *frase);

/**
 * @brief funcao chamada pela ListaFilmes para imprimir as opcoes e capturar as entradas
 * @param n Inteiro correspondente ao ultimo filme impresso na tela
 * @param verbosity Verbosidade
 * @return -2 caso o usuario tenha optado por ver a proxima pagina da lista, -1 caso ele tenha optado por voltar ao menu anterior e retorna a linha do csv correspondente ao filme escolhido
 */
int EntradaProximo(int n, const int verbosity);

/**
 * @brief Imprime os metadados do filme escolhido
 * @param i Inteiro correspondente ao filme selecionado na funcao EntradaProximo
 * @param filme Ponteiro para o array onde se encontra a lista de filmes
 * @return retorna a opcao selecionada pelo usuario 1 caso queira assistir e 2 caso queira voltar ao menu anterior
 */
int Dados(int i, tMetadados* filme, const int verbosity);

/**
 * @brief Funcao imprime menu de avalicao de filme e chama funcao para salvar nota e data
 * @param Lista Ponteiro para array de lista de filmes
 * @param idfilme Indice do filme assistido dentro do array
 * @param verbosity Verbosidade
 * @param user Ponteiro para array dos usuarios salvos na memoria
 * @param posuser Inteiro correspondente ao indice do usuario o qual assistiu o filme
 */
void Avaliacao(tMetadados* Lista, int idfilme, const int verbosity, tUsuario* user, const int posuser);

/**
 * @brief Funcao para checar se a nota inserida e valida
 * @param nota String correspondente a nota inserida pelo usuario
 * @return Retorna 1 caso a nota seja valida e 0 caso nao seja
 */
int CheckNota(const char* nota);

/**
 * @brief verifica caso uma string e um numero float
 * @param x String que sera analisada
 * @return Retorna 1 caso a string seja um float
 */
int VerificaFloat(const char* x);


int CheckAlpha(char* frase);

/**
 * @brief Libera a memoria alocada para os metadados do filme
 * @param filmes Ponteiro para array de filmes salvos
 */
void DestroyMetadados(tMetadados *filmes);

/**
 * @brief Imprime titulo do filme correspondente ao idfilme
 * @param filmes Ponteiro para array de filmes salvos
 */
void ImprimeTitulo(int idfilme, tMetadados *filmes);

#endif //FILMES_H

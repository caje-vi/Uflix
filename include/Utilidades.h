#ifndef UTILIDADES_H
#define UTILIDADES_H

#include "Filmes.h"

/**
 * @brief Verifica se uma string possui apenas letras e digitos
 * @param String que sera analisada
 * @return Retorna 1 caso a string possua apenas letras e digitos
 */
int VerificaAlphaNum(const char *x);

/**
 * @brief Verifica se uma string possui apenas letras
 * @param String que sera analisada
 * @return Retorna 1 caso a string possua apenas letras
 */
int VerificaAlpha(const char *x);

/**
 * @brief Verifica se uma string possui apenas digitos
 * @param String que sera analisada
 * @return Retorna 1 caso a string possua apenas digitos
 */
int VerificaNum(const char *x);

/**
 * @brief Verifica se o ponteiro foi criado com sucesso e imprime aviso caso o ponteiro nao tenha sido alocado
 * @param x Ponteiro que sera analisado
 */
void VerificaPonteiro(void *x);

/**
 * @brief Funcao que analisa se uma data e valida
 * Pré-Condição: Dada passada como parametro deve ser string do tipo dd/mm/aa
 * @param entrada String da data
 * @return Retorna 1 caso a data seja valida
 */
int ValidaData(const char *entrada);

/**
 * @brief Funcao para imprimir apenas caso a verbosidade seja 1
 * param imprime String para ser imprimida
 * param verbosity Verbosidade
 */
void MeuPrint(char *imprime, int verbosity);

/**
 * @brief Funcao para limpar o terminal
 * param verbosity Verbosidade
 */
void Clean(int verbosity);

/**
 * @brief Funcao para imprimir e gerenciar o menu principal
 * @param user Ponteiro para o array de usuarios
 * @param posuser Inteiro correspondente ao indice do usuario
 * @param verbosity Verbosidade
 * @param filmes Ponteiro para o array de filmes
 */
void MenuPrincipal(tUsuario* user, const int posuser, const int verbosity, tMetadados* filmes);

/**
 * @brief Funcao para imprimir e gerenciar o menu de entrada
 * @param users Ponteiro para o array de usuarios
 * @param verbosity Verbosidade
 * @param filmes Ponteiro para o array de filmes
 * @param tamUser Ponteiro que aponta para o array alocado para os usuarios
 * @param userAtivos Ponteiro que aponta o array de usar que estao sendo usados 
 */
void MenuLogin(tUsuario* users, const int verbosity, tMetadados* filmes, int *tamUser, int *userAtivos);

/**
 * @brief Funcao que gerencia o Perfil do usuario 
 * @param users Ponteiro para o array de usuarios
 * @param posuser Inteiro correspondente ao indice do usuario
 * @param verbosity Verbosidade
 * @param filmes Ponteiro para o array de filmes
 * @return Retorna 1 caso o usario queira excluir a nota e 0 caso queira voltar
 */
int MeuPerfil(tUsuario *users, const int PosUser, const int verbosity, tMetadados *filmes);
#endif //UTILIDADES_H

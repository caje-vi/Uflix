#ifndef USUARIO_H
#define USUARIO_H

#include "../include/Filmes.h"
#include "../include/Utilidades.h"
#include "../include/Historico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief Struct de Usuarios.
 * 
 * 
*/
typedef struct Usuario tUsuario;

void ImprimeAllUser(tUsuario *x, int *qtdUser);

/**
 * @brief Imprime uma string se verbosidade for 1.
 * 
 * @param imprime String a ser imprimida.
 * @param verbosity Verbosidade.
 *
static void MeuPrint(char *imprime, int verbosity);*/

/**
 * @brief Carrega os dados do arquivo usuarios.csv.
 *  
 * @param tamUser Ponteiro com o tamanho do do struct de usuario alocado.
 * @param qtdUser Ponteiro com a quantidade de usuario salvo, ativos ou nao.
 * @return Ponteiro de tUsuario.
 */
tUsuario *CarregaUsuarios(int *tamUser, int *qtdUser);

/**
 * @brief Cadastra um novo usuario.
 * 
 * @param verbosity Verbosidade.
 * @param user Ponteiro de tUsuario.
 * @param tamUser Ponteiro com o tamanho do do struct de usuario alocado.
 * @param qtdUser Ponteiro com a quantidade de usuario salvo, ativos ou nao.
 * @return Ponteiro de tUsuario.
 */
tUsuario *CadastraUsuario(const int verbosity, tUsuario *user, int *tamUser, int *qtdUser);

/**
 * @brief Salva os dados dos usuario no arquivo usuarios.csv.
 * 
 * @param user Ponteiro de tUsuario.
 * @param qtdUser Ponteiro com a quantidade de usuario salvo, ativos ou nao.
 */
void SalvaDadosUser(tUsuario *user, int *qtdUser);

/**
 * @brief Faz o login em uma conta
 * 
 * @param verbosity Verbosidade.
 * @param user Ponteiro de tUsuario.
 * @param qtdUser Ponteiro com a quantidade de usuario salvo, ativos ou nao.
 * @return Posicao do usuario logado ou -1 caso nao exista usuario.
 */
int Login(tUsuario *user, const int verbosity, int *qtdUser);

/**
 * @brief Coloca o campo Ativa so usuario com 0.
 * 
 * @param user Ponteiro de tUsuario.
 * @param posicao Posicao do usuario a ser excluido.
 */
void ExcluirConta(tUsuario *user, const int posicao);

/**
 * @brief Verifica se uma string eh inteira de caracteres alpha-numericos.
 * 
 * @param x String a ser verificada.
 * @return 1 se for alpha-numerico ou 0 se nao for.
 */
//static int VerificaAlphaNum(const char *x);

/**
 * @brief Verifica se nao tem nenhum usuario com o mesmo nome.
 * 
 * @param user Ponteiro de usuario.
 * @param x string com o usuario a ser verificado.
 * @param qtdUser Ponteiro com a quantidade de usuario salvo, ativos ou nao.
 * @return 1 se nao tiver nenhum usuario com o mesmo nome ou 0 se ja tiver.
 */
//static int VerificaLogin(tUsuario *user, const char *x, int *qtdUser);

/**
 * @brief Libera todo espaco usado pelo ponteiro.
 * 
 * @param x Ponteiro de tUsuario.
 * @param tamUser Ponteiro com o tamanho do do struct de usuario alocado.
 */
void DestroyUsuario(tUsuario *x, int *tamUser);

/**
 * @brief Verifica se o ponteiro eh valido.
 * 
 * @param x Ponteiro de tUsuario.
 */
//static void VerificaPonteiro(void *x);

void adicionarHistorico(tUsuario* user, const int posUser, float nota, int idfilme, char *data);

int MeuPerfil(tUsuario *users, const int PosUser, const int verbosity, tMetadados *filmes);








#endif //USUARIO_H//

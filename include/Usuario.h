#ifndef USUARIO_H
#define USUARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief Struct de Usuarios.
 * 
 * @var *login String com login.
 * @var *password String com a senha
 * @var Ativa Inteiro com 1 para conta ativa ou 0 para conta intiva
 * @var *historico Ponteiro de tHistorico
 * @var *tamHistorico Tamanho do historico alocado
*/
typedef struct Usuario tUsuario;

/**
 * @brief Carrega os dados do arquivo usuarios.csv.
 *  
 * @param tamUser Ponteiro com o tamanho do do struct de usuario alocado.
 * @param qtdUser Ponteiro com a quantidade de usuario salvo, ativos ou nao.
 * @return Ponteiro de tUsuario alocado.
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
 * @brief Verifica se nao tem nenhum usuario com o mesmo nome.
 * 
 * @param user Ponteiro de usuario.
 * @param x string com o usuario a ser verificado.
 * @param qtdUser Ponteiro com a quantidade de usuario salvo, ativos ou nao.
 * @return 1 se nao tiver nenhum usuario com o mesmo nome ou 0 se ja tiver.
 */
static int VerificaLogin(tUsuario *user, const char *x, int *qtdUser);

/**
 * @brief Libera todo espaco usado pelo ponteiro.
 * 
 * @param x Ponteiro de tUsuario.
 * @param tamUser Ponteiro com o tamanho do do struct de usuario alocado.
 */
void DestroyUsuario(tUsuario *x, int *tamUser);

/**
 * @brief Chama a função para adicionar um novo filme ao historico.
 * Pré-Condição: A data tem que estar no formato dd/mm/aaaa.
 * @param *user Ponteiro de Usuarios.
 * @param posUser Posicao do array do usuario logado.
 * @param nota Nota dada pelo usuario ao filme.
 * @param idfilme Posicao do array de filmes do filme assistido.
 * @param *data String com a data data pelo usuario.
 */
void adicionarHistorico(tUsuario* user, const int posUser, float nota, int idfilme, char *data);

/**
 * @brief Devolve o ponterio de tHistorioco.
 * Pré-Condição: colocar (tHistorioco *) na hora de chamar a função.
 * @param *users Ponteiro de usuario.
 * @param PosUser Posicao do array do usuario logado.
 * @return Ponteiro de tHistorico
 */
void *DevolveHistorico(tUsuario *users, const int PosUser);

/**
 * @brief Funcao que gerencia o Perfil do usuario 
 * @param users Ponteiro para o array de usuarios
 * @param posuser Inteiro correspondente ao indice do usuario
 * @param verbosity Verbosidade
 * @param filmes Ponteiro para o array de filmes
 * @return Retorna 1 caso o usario queira excluir a nota e 0 caso queira voltar
 */
int MeuPerfil(tUsuario *users, const int PosUser, const int verbosity, void *filmes);

#endif //USUARIO_H//

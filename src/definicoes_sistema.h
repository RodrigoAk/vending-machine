#ifndef DEFINICOES_SISTEMA_H_INCLUDED
#define DEFINICOES_SISTEMA_H_INCLUDED


#define true 1
#define false 0
#define NUM_SLOTS 12
#define NAME_SIZE 21
#define NUM_MOEDAS 5


#define NUM_ESTADOS 8
#define NUM_EVENTOS 16

// ESTADOS
#define IDLE                0
#define CLIENTE_IDLE        1
#define ADMINISTRADOR_IDLE  2
#define LIBERANDO_PRODUTO   3
#define CALCULANDO_TROCO    4
#define CADASTRANDO_TROCO   5
#define CADASTRANDO_PRODUTO 6
#define CHECANDO_CODIGO     7


// EVENTOS
#define NENHUM_EVENTO     -1
#define LIBERAR_PRODUTO    0
#define LIBERAR_TROCO      1
#define CANCELAR           2
#define SEL_CLIENTE        3
#define SEL_ADMIN          4
#define MOEDA_INSERIDA     5
#define CARACTERE_INSERIDO 6
#define PRODUTO            7
#define TROCO              8
#define VOLTAR             9
#define CADASTRO_CONCLUIDO 10
#define CHECAR_CODIGO      11
#define CODIGO_INVALIDO    12
#define CODIGO_VALIDO      13
#define CALCULA_TROCO      14
#define RETIRA_PRODUTO     15


// ACOES
#define NENHUMA_ACAO -1
#define A01 0  // Entrar como administrador
#define A02 1  // Entrar como cliente
#define A03 2  // Inserir dinheiro
#define A04 3  // Insere codigo
#define A05 4  // Cancelar
#define A06 5  // Cadastrar produto
#define A07 6  // Cadastrar troco
#define A08 7  // Liberando o produto
#define A09 8  // Liberando troco
#define A10 9  // Voltar
#define A11 10  // Notificacao
#define A12 11  // Checa codigo
#define A13 12  // Codigo validado
#define A14 13  // Calcula o troco
#define A15 14  // Retira um produto


#endif

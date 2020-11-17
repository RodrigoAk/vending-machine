#ifndef TECLA_H_INCLUDED
#define TECLA_H_INCLUDED

#define NENHUMA_TECLA -1

extern int codigo;
extern char buf[21];

/*
 * obterTeclas
 * Recebe o input do usuário
 * entradas
 *     nenhuma
 * saidas
 *     char*: Input do usuário
 */
extern char* obterTeclas();

/*
 * inserir_codigo
 * Recebe o codigo do produto que o cliente quer
 * comprar.
 * entradas
 *     nenhuma
 * saidas
 *     nenhuma
 */
extern void inserir_codigo();

#endif

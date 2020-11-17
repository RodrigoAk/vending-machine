#ifndef SISTEMA_PRODUTO_H_INCLUDED
#define SISTEMA_PRODUTO_H_INCLUDED


extern char produto[NUM_SLOTS][NAME_SIZE];
extern float preco[NUM_SLOTS];
extern int quantidade[NUM_SLOTS];
extern float acumulador;
extern int codigo;

/*
 * compra
 * Libera o produto comprado pelo cliente
 * e diminui a sua quantidade no estoque
 * entradas
 *     nenhuma
 * saidas
 *     nenhuma
 */
extern void compra();

/* 
 * cadastrar_produto
 * Permite o administrador cadastrar um produto
 * entradas
 *  Nenhuma
 * saidas
 *  Nenhuma
 */
extern void cadastrar_produto();

/*
 * retira_produto
 * Permite o administrador a retirar um produto
 * da vending machine
 * entradas
 *  nenhuma
 * saidas
 *  nenhuma
 */
extern void retira_produto();

/*
 * checa_codigo
 * Verifica se o codigo do produto que o cliente
 * inseriu é valido ou não, ou seja, se o produto
 * está disponível e o cliente inseriu dinheiro
 * suficiente.
 * entradas
 *     codigo: Codigo do produto
 * saidas
 *     TRUE: Codigo valido
 *     FALSE: Codigo invalido
 */
extern int checa_codigo(int codigo);

#endif

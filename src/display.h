#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

extern char produto[NUM_SLOTS][NAME_SIZE];
extern int quantidade[NUM_SLOTS];
extern float preco[NUM_SLOTS];
extern int troco_moedas[NUM_MOEDAS];
extern int troco[NUM_MOEDAS];
extern int codigo;
extern float acumulador;
extern int user;

/*
 * display
 * Imprime na tela todos os produtos da vending machine e
 * as ações e informações para o usuário atual.
 * entradas
 *     nenhuma
 * saidas
 *     nenhuma
 */
extern void display();

/*
 * notification
 * Imprime na tela uma notificação
 * entradas
 *     text: Texto a ser impresso
 * saidas
 *     nenhuma
 */
extern void notification(char* text);

/*
 * notification_troco
 * Imprime na tela o troco do cliente, como a quantidade
 * de cada moeda.
 * entradas
 *     troco_moedas: Array com as moedas disponiveis para troco
 * saida
 *     nenhuma
 */
extern void notification_troco(int troco_moedas[NUM_MOEDAS]);

/*
 * notification_produto
 * Imprime na tela o produto que o cliente comprou.
 * entradas
 *     produto: Array com os produtos da vending machine
 * saida
 *     nenhuma
 */
extern void notification_produto(char produto[NUM_SLOTS][NAME_SIZE]);


#endif

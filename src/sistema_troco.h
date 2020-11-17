#ifndef SISTEMA_TROCO_H_INCLUDED
#define SISTEMA_TROCO_H_INCLUDED


extern int troco[NUM_MOEDAS];
extern int troco_moedas[NUM_MOEDAS];
extern char produto[NUM_SLOTS][NAME_SIZE];
extern int quantidade[NUM_SLOTS];
extern float preco[NUM_SLOTS];
extern float acumulador;
extern int codigo;

/*
 * calcula_troco
 * Faz o cálculo do troco do cliente dando prioridade
 * para as moedas de maior valor.
 * entradas
 *     nenhuma
 * saidas
 *     nenhuma
 */
extern void calcula_troco();

/*
 * cancelar
 * O cliente cancela a operacao e recebe o dinheiro
 * de volta
 * entradas
 *     nenhuma
 * saidas
 *     nenhuma
 */
extern void cancelar();


/*
 * cadastrar_troco
 * Permite o administrador cadastrar o troco
 * entradas
 *  nenhuma
 * saidas
 *  nenhuma
 */
extern void cadastrar_troco();


#endif

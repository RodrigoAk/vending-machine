#ifndef INPUT_MOEDA_H_INCLUDED
#define INPUT_MOEDA_H_INCLUDED

extern float acumulador;
extern int codigo;
extern char produto[NUM_SLOTS][NAME_SIZE];
extern int quantidade[NUM_SLOTS];
extern float preco[NUM_SLOTS];

/*
 * inserir_moeda
 * Recebe um input do cliente, verifica o valor
 * inserido
 * entradas
 *     moeda: valor escolhido pelo cliente
 * saidas
 *     valor: valor da moeda inserida
 */
extern float inserir_moeda(int moeda);





#endif

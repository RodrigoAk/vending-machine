#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Detalhes sobre as funções estão no sistema_troco.h
 */

#include "definicoes_sistema.h"
#include "sistema_troco.h"


void calcula_troco() {
    float resto;
    int num_moedas;
    float moedas[NUM_MOEDAS] = {0.05, 0.10, 0.25, 0.50, 1.00};
    
    resto = acumulador - preco[codigo];

    for(int i=0; i < NUM_MOEDAS; i++) {
        troco[i] = 0;
    }  // Inicializa o troco

    for(int i=NUM_MOEDAS-1; i > -1; i--) {
        if(troco_moedas[i] > 0) {
            num_moedas = floor(resto/moedas[i]);
            if(num_moedas <= troco_moedas[i]) {
                troco[i] = num_moedas;
                resto = fmodf(resto, moedas[i]);
                troco_moedas[i] -= num_moedas;
            } else {
                troco[i] = troco_moedas[i];
                resto -= troco_moedas[i]*moedas[i];
                troco_moedas[i] = 0;
            }
        }
    }  // Calcula o numero de moedas de troco
    acumulador = 0;
}

void cadastrar_troco()
{
    int i;
    float moedas[NUM_MOEDAS] = {0.05, 0.1, 0.25, 0.5, 1.0};

    for(i = 0; i < 5; i++)
    {
        printf("R$%.2f: \nQuantidade: ", moedas[i]);
        scanf("\n%d", &troco_moedas[i]);
    } 
}

void cancelar()
{
    acumulador = 0;
}

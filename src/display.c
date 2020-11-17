#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Detalhes sobre as funções estão no display.h
 */

#include "definicoes_sistema.h"
#include "display.h"


void display() {
    int row;
    int col;
    int index=0;
    float moedas[NUM_MOEDAS] = {0.05, 0.10, 0.25, 0.50, 1.00};

    for(row = 0; row < 4; row++) {
        for(col=0; col < 3; col++) {
            printf("#%d: %s (R$%.2f, %du) | ", index, produto + index, preco[index], quantidade[index]);
            index++;
        }
        printf("\n");
    }
    printf("-----------------------------------------------\n\n");
    printf("Troco disponivel:\n");
    for(int i=0; i < NUM_MOEDAS; i++) {
        printf("R$%.2f (%d) | ", moedas[i], troco_moedas[i]);
    }
    printf("\n-----------------------------------------------\n\n");

    // Imprime as ações de cada usuário
    if(user == CLIENTE_IDLE) {
        printf("Inserir moeda:\n");
        printf("0: R$0.05 | 1: R$0.10 | 2: R$0.25 |\n3: R$0.50 | 4: R$1.00 |\n\n");
        printf("Acumulado: R$%.2f\n\n", acumulador);
        printf("Acoes:\nvoltar -> volta para o estado IDLE\ncodigo -> insere codigo do produto para comprar\n");
        printf("0/1/2/3/4 -> insere moedas\ncancelar -> Cancela a compra\n\n");
    } else if(user == ADMINISTRADOR_IDLE) {
        printf("Acoes:\nvoltar -> volta para o estado IDLE\ntroco -> cadastro de troco\n");
        printf("produto -> cadastro/edicao de produto\nretirar -> Retira um produto\n\n");
    } else if(user == IDLE) {
        printf("Acoes: \nadmin -> Entra como administrador\ncliente -> Entra como cliente\n\n");
    }
}

void notification(char* text) {
    printf("%s\n", text);
}

void notification_troco(int troco_moedas[NUM_MOEDAS]) {
    float moedas[NUM_MOEDAS] = {0.05, 0.10, 0.25, 0.50, 1.00};

    if(codigo != -1) {
        printf("Seu troco:");
        for(int i=0; i < NUM_MOEDAS; i++) {
            printf("R$%.2f -> %d moedas | ", moedas[i], troco[i]);
        }
        printf("\n\n");
    } else {
        printf("Retire seu dinheiro...\n");
    }
}

void notification_produto(char produto[NUM_SLOTS][NAME_SIZE]) {
    printf("Retire seu produto: %s\n\n", produto + codigo);
}

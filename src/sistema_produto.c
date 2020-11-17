#include <stdio.h>
#include <stdlib.h>

/*
 * Detalhes sobre as funções estão no sistema_libera_produto.h
 */

#include "definicoes_sistema.h"
#include "sistema_produto.h"


void compra() {
    quantidade[codigo] -= 1;
}


void cadastrar_produto()
{
    printf("Posicao (0 ate 11): ");
    scanf("\n%d", &codigo);

    printf("Nome do produto: ");
    scanf("\n%[^\n]", produto[codigo]);

    printf("Quantidade: ");
    scanf("\n%d", &quantidade[codigo]);

    printf("Preco: ");
    scanf("\n%f", &preco[codigo]);
}


void retira_produto() {
    printf("Insira o codigo: ");
    scanf("\n%d", &codigo);
    *produto[codigo] = '\0';
    quantidade[codigo] = 0;
    preco[codigo] = 0;
}

int checa_codigo(int codigo)
{
    if(quantidade[codigo] > 0) {
        if(acumulador >= preco[codigo]) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

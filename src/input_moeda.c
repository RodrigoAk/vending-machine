#include <stdio.h>
#include <stdlib.h>

/*
 * Detalhes sobre as funções estão no cliente.h
 */

#include "definicoes_sistema.h"
#include "input_moeda.h"


float inserir_moeda(int moeda)
{
    float valor;

    switch(moeda)
    {
        case 0:
            valor = 0.05;
            break;
        case 1:
            valor = 0.10;
            break;
        case 2:
            valor = 0.25;
            break;
        case 3:
            valor = 0.50;
            break;
        case 4:
            valor = 1.00;
            break;
    }
    return valor;
}





#include <stdio.h>
#include <stdlib.h>

/*
 * Detalhes sobre as funções estão na tecla.h
 */

#include "definicoes_sistema.h"
#include "tecla.h"


char buf[21];
char* obterTeclas()
{
    printf("Input: ");
    scanf("%s", buf);
    return buf;
}

void inserir_codigo()
{
    printf("Codigo do produto: ");
    scanf("%d", &codigo);
}

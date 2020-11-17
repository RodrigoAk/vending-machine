#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * VENDING MACHINE
*/

#include "definicoes_sistema.h"
#include "input_moeda.h"
#include "tecla.h"
#include "display.h"
#include "sistema_troco.h"
#include "sistema_produto.h"

/*
 * ESTATICOS
 * variaveis a serem usadas pelo programa inteiro
 */
int condigoEvento;
int codigoAcao;
int estado;
int acao_matrizTransicaoEstados[NUM_ESTADOS][NUM_EVENTOS];
int proximo_estado_matrizTransicaoEstados[NUM_ESTADOS][NUM_EVENTOS];

int user=IDLE;
float acumulador = 0.0;
int codigo;
int moeda;
int troco[NUM_MOEDAS];
int troco_moedas[NUM_MOEDAS];
char produto[NUM_SLOTS][NAME_SIZE];
int quantidade[NUM_SLOTS];
float preco[NUM_SLOTS];

/*
 * executarAcao
 * Executa uma acao
 * entradas
 *     codigoAcao: codigo da acao a ser executada
 * saidas
 *     codigo do evento interno ou NENHUM_EVENTO
 */
int executarAcao(int codigoAcao)
{
    int retval;

    retval = NENHUM_EVENTO;
    if(codigoAcao == NENHUMA_ACAO)
    {
        return retval;
    }

    switch(codigoAcao)
    {
        case A01:  // Entrar como administrador
            user = ADMINISTRADOR_IDLE;
            notification("ADMINISTRADOR");
            break;
        case A02:  // Entrar como cliente
            user = CLIENTE_IDLE;
            notification("CLIENTE");
            break;
        case A03:  // Inserir moeda
            acumulador += inserir_moeda(moeda);
            break;
        case A04:  // Inserir codigo do produto
            inserir_codigo();
            return CHECAR_CODIGO;
        case A05:  // Cancelar compra
            cancelar();
            codigo = -1;
            return LIBERAR_TROCO;
        case A06:  // Cadastrar produto
            cadastrar_produto();
            return CADASTRO_CONCLUIDO;
        case A07:  // Cadastrar troco
            cadastrar_troco();
            return CADASTRO_CONCLUIDO;
        case A08:  // Libera o produto
            notification_produto(produto);
            compra();
            return CALCULA_TROCO;
        case A09:  // Libera o troco
            notification_troco(troco);
            break;
        case A10:
            user = IDLE;
            notification("IDLE");
            break;
        case A11:
            notification("Cadastro Concluido!");
            break;
        case A12:
            if(checa_codigo(codigo)) {
                return CODIGO_VALIDO;
            } else {
                return CODIGO_INVALIDO;
            }
        case A13:
            return LIBERAR_PRODUTO;
        case A14:
            calcula_troco();
            return LIBERAR_TROCO;
        case A15:
            retira_produto();
            break;
    }

    return retval;
}


/*
 * iniciaMaquinaEstados
 * Inicia a maquina de estados
 * entradas
 *     nenhuma
 * saidas
 *     nenhuma
 */
void iniciaMaquinaEstados()
{
    int i;
    int j;

    for(i=0; i < NUM_ESTADOS; i++) {
        for (j=0; j < NUM_EVENTOS; j++) {
            acao_matrizTransicaoEstados[i][j] = NENHUMA_ACAO;
            proximo_estado_matrizTransicaoEstados[i][j] = i;
        }
    }

    // IDLE
    proximo_estado_matrizTransicaoEstados[IDLE][SEL_CLIENTE] = CLIENTE_IDLE;
    acao_matrizTransicaoEstados[IDLE][SEL_CLIENTE] = A02;

    proximo_estado_matrizTransicaoEstados[IDLE][SEL_ADMIN] = ADMINISTRADOR_IDLE;
    acao_matrizTransicaoEstados[IDLE][SEL_ADMIN] = A01;

    // CLIENTE IDLE
    proximo_estado_matrizTransicaoEstados[CLIENTE_IDLE][CANCELAR] = CALCULANDO_TROCO;
    acao_matrizTransicaoEstados[CLIENTE_IDLE][CANCELAR] = A05;

    proximo_estado_matrizTransicaoEstados[CLIENTE_IDLE][MOEDA_INSERIDA] = CLIENTE_IDLE;
    acao_matrizTransicaoEstados[CLIENTE_IDLE][MOEDA_INSERIDA] = A03;

    proximo_estado_matrizTransicaoEstados[CLIENTE_IDLE][CARACTERE_INSERIDO] = CHECANDO_CODIGO;
    acao_matrizTransicaoEstados[CLIENTE_IDLE][CARACTERE_INSERIDO] = A04;

    proximo_estado_matrizTransicaoEstados[CLIENTE_IDLE][VOLTAR] = IDLE;
    acao_matrizTransicaoEstados[CLIENTE_IDLE][VOLTAR] = A10;

    // CHECANDO CODIGO
    proximo_estado_matrizTransicaoEstados[CHECANDO_CODIGO][CHECAR_CODIGO] = CHECANDO_CODIGO;
    acao_matrizTransicaoEstados[CHECANDO_CODIGO][CHECAR_CODIGO] = A12;

    proximo_estado_matrizTransicaoEstados[CHECANDO_CODIGO][CODIGO_INVALIDO] = CLIENTE_IDLE;
    acao_matrizTransicaoEstados[CHECANDO_CODIGO][CODIGO_INVALIDO] = NENHUMA_ACAO;

    proximo_estado_matrizTransicaoEstados[CHECANDO_CODIGO][CODIGO_VALIDO] = LIBERANDO_PRODUTO;
    acao_matrizTransicaoEstados[CHECANDO_CODIGO][CODIGO_VALIDO] = A13;

    // LIBERANDO PRODUTO
    proximo_estado_matrizTransicaoEstados[LIBERANDO_PRODUTO][LIBERAR_PRODUTO] = CALCULANDO_TROCO;
    acao_matrizTransicaoEstados[LIBERANDO_PRODUTO][LIBERAR_PRODUTO] = A08;

    // CALCULANDO TROCO
    proximo_estado_matrizTransicaoEstados[CALCULANDO_TROCO][CALCULA_TROCO] = CALCULANDO_TROCO;
    acao_matrizTransicaoEstados[CALCULANDO_TROCO][CALCULA_TROCO] = A14;

    proximo_estado_matrizTransicaoEstados[CALCULANDO_TROCO][LIBERAR_TROCO] = CLIENTE_IDLE;
    acao_matrizTransicaoEstados[CALCULANDO_TROCO][LIBERAR_TROCO] = A09;

    // ADMINISTRADOR IDLE
    proximo_estado_matrizTransicaoEstados[ADMINISTRADOR_IDLE][PRODUTO] = CADASTRANDO_PRODUTO;
    acao_matrizTransicaoEstados[ADMINISTRADOR_IDLE][PRODUTO] = A06;

    proximo_estado_matrizTransicaoEstados[ADMINISTRADOR_IDLE][RETIRA_PRODUTO] = ADMINISTRADOR_IDLE;
    acao_matrizTransicaoEstados[ADMINISTRADOR_IDLE][RETIRA_PRODUTO] = A15;

    proximo_estado_matrizTransicaoEstados[ADMINISTRADOR_IDLE][TROCO] = CADASTRANDO_TROCO;
    acao_matrizTransicaoEstados[ADMINISTRADOR_IDLE][TROCO] = A07;

    proximo_estado_matrizTransicaoEstados[ADMINISTRADOR_IDLE][VOLTAR] = IDLE;
    acao_matrizTransicaoEstados[ADMINISTRADOR_IDLE][VOLTAR] = A10;

    // CADASTRANDO PRODUTO
    proximo_estado_matrizTransicaoEstados[CADASTRANDO_PRODUTO][CADASTRO_CONCLUIDO] = ADMINISTRADOR_IDLE;
    acao_matrizTransicaoEstados[CADASTRANDO_PRODUTO][CADASTRO_CONCLUIDO] = A11;

    // CADASTRANDO TROCO
    proximo_estado_matrizTransicaoEstados[CADASTRANDO_TROCO][CADASTRO_CONCLUIDO] = ADMINISTRADOR_IDLE;
    acao_matrizTransicaoEstados[CADASTRANDO_TROCO][CADASTRO_CONCLUIDO] = A11;
}


/*
 * iniciaSistema
 * Inicia o sistema
 * entradas
 *     nenhuma
 * saidas
 *     nenhuma
 */
void iniciaSistema()
{
    iniciaMaquinaEstados();
}


/*
 * Funções para ler o input do usuário
 * e verificar qual a ação que ele quer
 * executar.
 * entradas
 *     nenhuma
 * saidas
 *     TRUE: Esse é o evento que o usuário quer que ocorra
 *     FALSE: Não é o evento desejado
*/

char* teclas;

int selecionar_admin()
{
    if(strcmp(teclas, "admin") == 0) {
        return true;
    }
    return false;
}

int selecionar_cliente()
{
    if(strcmp(teclas,"cliente") == 0) {
        return true;
    }
    return false;
}

int voltar()
{
    if(strcmp(teclas, "voltar") == 0) {
        return true;
    }
    return false;
}

int cancelar_compra() {
    if(strcmp(teclas, "cancelar") == 0) {
        return true;
    }
    return false;
}

int moeda_inserida() {
    if(strcmp(teclas, "0") == 0) {
        moeda = 0;
        return true;
    } else if(strcmp(teclas, "1") == 0) {
        moeda = 1;
        return true;
    } else if(strcmp(teclas, "2") == 0) {
        moeda = 2;
        return true;
    } else if(strcmp(teclas, "3") == 0) {
        moeda = 3;
        return true;
    } else if(strcmp(teclas, "4") == 0) {
        moeda = 4;
        return true;
    }
    return false;
}

int ins_codigo() {
    if(strcmp(teclas, "codigo") == 0) {
        return true;
    }
    return false;
}

int cad_produto() {
    if(strcmp(teclas, "produto") == 0) {
        return true;
    }
    return false;
}

int cad_troco() {
    if(strcmp(teclas, "troco") == 0) {
        return true;
    }
    return false;
}

int ret_produto() {
    if(strcmp(teclas, "retirar") == 0) {
        return true;
    }
    return false;
}



/*
 * Funcoes para obter os eventos, acoes e estados
*/

int obterEvento() {
    int retval = NENHUM_EVENTO;

    teclas = obterTeclas();
    if(selecionar_admin()) return SEL_ADMIN;
    else if(selecionar_cliente()) return SEL_CLIENTE;
    else if(cancelar_compra()) return CANCELAR;
    else if(voltar()) return VOLTAR;
    else if(moeda_inserida()) return MOEDA_INSERIDA;
    else if(ins_codigo()) return CARACTERE_INSERIDO;
    else if(cad_produto()) return PRODUTO;
    else if(cad_troco()) return TROCO;
    else if(ret_produto()) return RETIRA_PRODUTO;
    return retval;
}

int obterAcao(int estado, int codigoEvento) {
    return acao_matrizTransicaoEstados[estado][codigoEvento];
}

int obterProximoEstado(int estado, int codigoEvento) {
    return proximo_estado_matrizTransicaoEstados[estado][codigoEvento];
}


/*
 * main
 * Função com o loop principal da vending machine
*/
int main() 
{
    int codigoEvento;
    int codigoAcao;
    int estado;
    int eventoInterno;
    int log=0;

    estado = IDLE;
    eventoInterno = NENHUM_EVENTO;
    iniciaSistema();
    printf("VENDING MACHINE LIGADA\n\n");
    while(true) {
        printf("\n\nLOG_COUNT: %d\n\n", log);

        if(eventoInterno == NENHUM_EVENTO) {
            display();
            codigoEvento = obterEvento();
        } else {
            codigoEvento = eventoInterno;
        }
        if(codigoEvento != NENHUM_EVENTO) {
            codigoAcao = obterAcao(estado, codigoEvento);
            eventoInterno = executarAcao(codigoAcao);
            printf("Anterior -> Estado: %d Evento: %d Acao: %d\n", estado, codigoEvento, codigoAcao);
            estado = obterProximoEstado(estado, codigoEvento);
            printf("Atual    -> Estado: %d\n\n", estado);
        }
        log++;
    }
}


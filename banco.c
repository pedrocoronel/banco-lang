#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

struct Conta {
    char nome[20];
    int saldo;
    int agencia;
};

struct Conta contas[10];
int totalContas = 0;

void f5(void){
    sleep(2);
    system("clear");
}

void criarConta(void){
    char nome[20];
    int saldo;
    int agencia;
    struct Conta novaConta;
    putchar('\n');

    printf("qual o seu nome?\n>:");
    scanf("%s", nome);
    putchar('\n');

    for (int i = 0; nome[i]; i++){
            nome[i] = toupper((unsigned char)nome[i]);
    }

    printf("valor para transferir a sua conta nova\n>:");
    scanf("%d", &saldo);
    putchar('\n');

    printf("sua agencia:\n>:");
    scanf("%d", &agencia);
    putchar('\n');

    printf("Nome:\t\t%s\n", nome);
    printf("Saldo:\t\t%d\n", saldo);
    printf("Agencia:\t%d\n", agencia);
    putchar('\n');

    strcpy(novaConta.nome, nome);
    novaConta.saldo = saldo;
    novaConta.agencia = agencia;

    contas[totalContas] = novaConta;
    totalContas++;
}

void efetuarSaque(void){
    int agencia;
    int valorSaque;

    printf("Qual é a sua agência?\n>:");
    scanf("%d", &agencia);
    putchar('\n');

    int indiceConta = -1;
    for (int i = 0; i < totalContas; i++) {
        if (contas[i].agencia == agencia) {
            indiceConta = i;
            break;
        }
    }

    if (indiceConta == -1) {
        printf("Agência não encontrada.\n");
    } else {
        printf("Informe o valor que deseja sacar:\n>:");
        scanf("%d", &valorSaque);
        putchar('\n');

        if (valorSaque <= contas[indiceConta].saldo) {
            contas[indiceConta].saldo -= valorSaque;
            printf("Saque de %d realizado com sucesso. Novo saldo: %d\n", valorSaque, contas[indiceConta].saldo);
        } else {
            printf("Saldo insuficiente para o saque.\n");
        }
    }
}

void efetuarDeposito(void){
    int agencia;
    int valorDeposito;

    printf("Qual é a sua agência?\n>:");
    scanf("%d", &agencia);
    putchar('\n');

    int indiceConta = -1;
    for (int i = 0; i < totalContas; i++) {
        if (contas[i].agencia == agencia) {
            indiceConta = i;
            break;
        }
    }

    if (indiceConta == -1) {
        printf("Agência não encontrada.\n");
    } else {
        printf("Informe o valor que deseja depositar:\n>:");
        scanf("%d", &valorDeposito);
        putchar('\n');

        contas[indiceConta].saldo += valorDeposito;
        printf("Depósito de %d realizado com sucesso. Novo saldo: %d\n", valorDeposito, contas[indiceConta].saldo);
    }
}

void efetuarTransferencia(void){
    int agenciaOrigem, agenciaDestino, valorTransferencia;

    printf("Qual é a sua agência de origem?\n>:");
    scanf("%d", &agenciaOrigem);
    putchar('\n');

    int indiceContaOrigem = -1;
    for (int i = 0; i < totalContas; i++) {
        if (contas[i].agencia == agenciaOrigem) {
            indiceContaOrigem = i;
            break;
        }
    }

    if (indiceContaOrigem == -1) {
        printf("Agência de origem não encontrada.\n");
        return;
    }

    printf("Qual é a agência de destino?\n>:");
    scanf("%d", &agenciaDestino);
    putchar('\n');

    int indiceContaDestino = -1;
    for (int i = 0; i < totalContas; i++) {
        if (contas[i].agencia == agenciaDestino) {
            indiceContaDestino = i;
            break;
        }
    }

    if (indiceContaDestino == -1) {
        printf("Agência de destino não encontrada.\n");
        return;
    }

    printf("Informe o valor que deseja transferir:\n>:");
    scanf("%d", &valorTransferencia);
    putchar('\n');

    if (valorTransferencia <= contas[indiceContaOrigem].saldo) {
        contas[indiceContaOrigem].saldo -= valorTransferencia;
        contas[indiceContaDestino].saldo += valorTransferencia;
        printf("Transferência de %d realizada com sucesso.\n", valorTransferencia);
    } else {
        printf("Saldo insuficiente para a transferência.\n");
    }
}

void listarContas(void){
    printf("Lista de Contas:\n");
    for (int i = 0; i < totalContas; i++) {
        printf("Nome: %s, Agência: %d, Saldo: %d\n", contas[i].nome, contas[i].agencia, contas[i].saldo);
    }
}

void menu(void){
    int escolha;
    printf(" /8888888  /8888888  /88   /88  /8888888  /8888888\n");
    printf("| 88  /88 | 88__/88 | 8888| 88 | 888___/ | 88__/88\n");
    printf("| 88888 / | 88  |88 | 88888888 | 888     | 88 | 88\n");
    printf("| 88  /88 | 8888888 | 88  8888 | 888     | 88 | 88\n");
    printf("| 8888888 | 88   88 | 88 \\  88 | 8888888 | 8888888\n");
    printf("|/_____/  |/_/  /_/ |/_/  \\/_/ |/_____/  |/_____/\n");
    puts("{1} - CRIAR CONTA.");
    puts("{2} - EFETUAR SAQUE.");
    puts("{3} - EFETUAR DEPÓSITO.");
    puts("{4} - EFETUAR TRANSFERÊNCIA.");
    puts("{5} - LISTA DE CONTAS.");
    puts("{6} - SAIR DO PROGRAMA.");
    printf(">: ");
    scanf("%d", &escolha);

    switch(escolha){
        case 1:
            criarConta();
            f5();
            break;
        case 2:
            efetuarSaque();
            f5();
            break;
        case 3:
            efetuarDeposito();
            f5();
            break;
        case 4:
            efetuarTransferencia();
            f5();
            break;
        case 5:
            listarContas();
            f5();
            break;
        case 6:
            exit(0); // Encerra o programa
        default:
            printf("Opção inválida. Tente novamente.\n");
            f5();
            break;
        };
    }

int main(void){
    system("clear");
    while(1){
        menu();
        usleep(100000);
    }
    return 0;
}


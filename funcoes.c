// funcoes.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

void NovoCliente(totalclientes *Clientes) {
    if (Clientes->qtd >= 1000) {
        printf("Você ultrapassou o limite de clientes.\n");
        return;
    }

    clientedesc NovoCliente;

    printf("Digite o seu nome: ");
    scanf("%s", NovoCliente.nome);

    printf("Digite seu CPF: ");
    scanf("%ld", &NovoCliente.cpf);

    printf("Qual seria seu tipo de conta?\n1 - Conta comum\n2 - Conta Plus com benefícios\n");
    scanf("%d", &NovoCliente.tipodeconta);

    printf("Qual será o seu valor inicial? ");
    scanf("%lf", &NovoCliente.valorinicial);

    printf("Qual será sua senha de segurança com até 10 dígitos: ");
    scanf("%s", NovoCliente.senha);

    NovoCliente.saldoatual = NovoCliente.valorinicial;
    Clientes->Clientes[Clientes->qtd] = NovoCliente;
    Clientes->qtd++;
    printf("Cliente cadastrado com sucesso.\n");
}

void Listarclientes(totalclientes *TodosClientes) {
    if (TodosClientes->qtd == 0) {
        printf("Nenhum cliente encontrado.\n");
        return;
    }

    printf("Aqui está a lista de todos os seus clientes:\n");

    for (int i = 0; i < TodosClientes->qtd; i++) {
        printf("Nome: %s\n", TodosClientes->Clientes[i].nome);
        printf("CPF: %ld\n", TodosClientes->Clientes[i].cpf);
        printf("Tipo de conta: %d\n", TodosClientes->Clientes[i].tipodeconta);
        printf("Valor inicial: %.2lf\n", TodosClientes->Clientes[i].valorinicial);
        printf("Saldo atual: %.2f\n\n", TodosClientes->Clientes[i].saldoatual);
    }
}

void ApagarCliente(totalclientes *TodosClientes, long cpf) {
    int index = -1;
    for (int i = 0; i < TodosClientes->qtd; i++) {
        if (TodosClientes->Clientes[i].cpf == cpf) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < TodosClientes->qtd - 1; i++) {
            TodosClientes->Clientes[i] = TodosClientes->Clientes[i + 1];
        }
        TodosClientes->qtd--;
        printf("Cliente removido com sucesso.\n");
    } else {
        printf("Cliente não encontrado.\n");
    }
}

void debito(clientedesc *Clientes) {
    long cpf;
    char senha[11];
    double valor;

    printf("Digite o seu CPF: ");
    scanf("%ld", &cpf);

    int index = -1;
    for (int i = 0; i < 1000; i++) {
        if (Clientes[i].cpf == cpf) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("Digite a senha: ");
        scanf("%s", senha);

        if (strcmp(Clientes[index].senha, senha) == 0) {
            printf("Digite o valor a ser debitado: ");
            scanf("%lf", &valor);

            if (valor > 0 && valor <= Clientes[index].saldoatual) {
                Clientes[index].saldoatual -= valor;
                printf("Débito realizado com sucesso. Novo saldo: %.2f\n", Clientes[index].saldoatual);
            } else {
                printf("Valor inválido ou insuficiente na conta.\n");
            }
        } else {
            printf("Senha incorreta. Operação cancelada.\n");
        }
    } else {
        printf("Cliente não encontrado.\n");
    }
}
void deposito(clientedesc *Clientes) {
    long cpf;
    double valor;

    printf("Digite o seu CPF: ");
    scanf("%ld", &cpf);

    int index = -1;
    for (int i = 0; i < 1000; i++) {
        if (Clientes[i].cpf == cpf) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("Digite o valor a ser depositado: ");
        scanf("%lf", &valor);

        if (valor > 0) {
            Clientes[index].saldoatual += valor;
            printf("Depósito realizado com sucesso. Novo saldo: %.2f\n", Clientes[index].saldoatual);
        } else {
            printf("Valor inválido.\n");
        }
    } else {
        printf("Cliente não encontrado.\n");
    }
}

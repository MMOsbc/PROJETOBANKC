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

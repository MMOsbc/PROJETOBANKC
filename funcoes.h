// funcoes.h
#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct {
    char nome[50];
    long cpf;
    int tipodeconta;
    double valorinicial;
    char senha[11];
    float saldoatual;
} clientedesc;

typedef struct {
    clientedesc Clientes[1000];
    int qtd;
} totalclientes;

void NovoCliente(totalclientes *Clientes);
void ApagarCliente(totalclientes *TodosClientes, long cpf);
void Listarclientes(totalclientes *TodosClientes);
void debito(clientedesc *Clientes);
void deposito(clientedesc *Clientes);
void extrato(clientedesc *Clientes);
void transferencia(clientedesc *Clientes);
void salvarClientes(totalclientes *Clientes);
void carregarClientes(totalclientes *Clientes);

#endif
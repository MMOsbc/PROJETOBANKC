// funcoes.h
#ifndef FUNCOES_H
#define FUNCOES_H
// define 
#define MAX_CLIENTES 1000
#define MAX_SALDO_COMUM 1000
#define MAX_SALDO_PLUS 5000

typedef struct {
    char nome[50];
    long cpf;
    int tipodeconta;
    double valorinicial;
    char senha[11];
    float saldoatual;
} clientedesc;

typedef struct {
    clientedesc Clientes[MAX_CLIENTES];
    int qtd;
} totalclientes;

void NovoCliente(totalclientes *Clientes);
void Listarclientes(totalclientes *TodosClientes);
void ApagarCliente(totalclientes *TodosClientes, long cpf);
void debito(totalclientes *Clientes);
void deposito(totalclientes *Clientes);
void extrato(totalclientes *Clientes);
void transferencia(totalclientes *Clientes);
void salvarClientes(totalclientes *Clientes);
void carregarClientes(totalclientes *Clientes);

#endif

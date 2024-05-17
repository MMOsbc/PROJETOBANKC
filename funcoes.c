// funcoes.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
// Função para cadastrar um novo cliente
void NovoCliente(totalclientes *Clientes) 
 // Verifica se o limite de clientes foi atingido{
    if (Clientes->qtd >= 1000) {
        printf("Você ultrapassou o limite de clientes.\n");
        return;
    }
 // Declaração de uma variável para armazenar os dados do novo cliente
    clientedesc NovoCliente;
 // Solicita e lê o nome do cliente
    printf("Digite o seu nome: ");
    scanf("%s", NovoCliente.nome);
// Solicita e lê o CPF do cliente
    printf("Digite seu CPF: ");
    scanf("%ld", &NovoCliente.cpf);
// Solicita e lê o tipo de conta do cliente
    printf("Qual seria seu tipo de conta?\n1 - Conta comum\n2 - Conta Plus com benefícios\n");
    scanf("%d", &NovoCliente.tipodeconta);
 // Solicita e lê o valor inicial da conta do cliente
    printf("Qual será o seu valor inicial? ");
    scanf("%lf", &NovoCliente.valorinicial);
   // Solicita e lê a senha do cliente
    printf("Qual será sua senha de segurança com até 10 dígitos: ");
    scanf("%s", NovoCliente.senha);
 // Define o saldo atual do cliente como o valor inicial
    NovoCliente.saldoatual = NovoCliente.valorinicial;
     // Adiciona o novo cliente à lista de clientes e incrementa o contador de clientes
    Clientes->Clientes[Clientes->qtd] = NovoCliente;
    Clientes->qtd++;
        // Mensagem de sucesso

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
    // Solicita e lê o CPF do cliente

    printf("Digite o seu CPF: ");
    scanf("%ld", &cpf);
 // Procura o cliente pelo CPF
    int index = -1;
    for (int i = 0; i < 1000; i++) {
        if (Clientes[i].cpf == cpf) {
            index = i;
            break;
        }
    }
 // Verifica se o cliente foi encontrado
    if (index != -1) {
         // Solicita e lê o valor a ser depositado
        printf("Digite o valor a ser depositado: ");
        scanf("%lf", &valor);
 // Verifica se o valor é válido e realiza o depósito
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
// Função para mostrar o extrato de um cliente

void extrato(clientedesc *Clientes) {
    long cpf;
    char senha[11];
    // Solicita e lê o CPF do cliente

    printf("Digite o seu CPF: ");
    scanf("%ld", &cpf);
    // Procura o cliente pelo CPF

    int index = -1;
    for (int i = 0; i < 1000; i++) {
        if (Clientes[i].cpf == cpf) {
            index = i;
            break;
        }
    }
    // Verifica se o cliente foi encontrado

    if (index != -1) {
        printf("Digite a senha: ");
        scanf("%s", senha);
        // Verifica se a senha está correta
       

        if (strcmp(Clientes[index].senha, senha) == 0) {
            printf("Extrato do cliente %s (CPF: %ld)\n", Clientes[index].nome, cpf);
            printf("Saldo Inicial: %.2f\n", Clientes[index].valorinicial);
            printf("Saldo Final: %.2f\n", Clientes[index].saldoatual);
                 // Mostra o extrato do cliente
        } else {
            printf("Senha incorreta. Operação cancelada.\n");
        }
    } else {
        printf("Cliente não encontrado.\n");
    }
}
// Função para realizar uma transferência entre contas
void transferencia(clientedesc *Clientes) {
    long cpfOrigem, cpfDestino;
    char senhaOrigem[11];
    double valor;
// Solicita e lê o CPF da conta de origem
    printf("Digite o seu CPF (Origem): ");
    scanf("%ld", &cpfOrigem);

    int indexOrigem = -1;
    for (int i = 0; i < 1000; i++) {
        if (Clientes[i].cpf == cpfOrigem) {
            indexOrigem = i;
            break;
        }
    }
 // Verifica se a conta de origem foi encontrada
    if (indexOrigem != -1) {
        printf("Digite a senha (Origem): ");
        scanf("%s", senhaOrigem);
          // Verifica se a senha da conta de origem está correta

        if (strcmp(Clientes[indexOrigem].senha, senhaOrigem) == 0) {
            // Solicita e lê o CPF da conta de destino
            printf("Digite o CPF (Destino): ");
            scanf("%ld", &cpfDestino);
 // Procura o cliente pelo CPF da conta de destino
            int indexDestino = -1;
            for (int i = 0; i < 1000; i++) {
                if (Clientes[i].cpf == cpfDestino) {
                    indexDestino = i;
                    break;
                }
            }
// Verifica se a conta de destino foi encontrada
            if (indexDestino != -1) {
                // Solicita e lê o valor a ser transferido
                printf("Digite o valor a ser transferido: ");
                scanf("%lf", &valor);
// Verifica se o valor é válido e realiza a transferência
                if (valor > 0 && valor <= Clientes[indexOrigem].saldoatual) {
                    Clientes[indexOrigem].saldoatual -= valor;
                    Clientes[indexDestino].saldoatual += valor;
                    printf("Transferência realizada com sucesso.\n");
                } else {
                    printf("Valor inválido ou insuficiente na conta de origem.\n");
                }
            } else {
                printf("Conta de destino não encontrada.\n");
            }
        } else {
            printf("Senha incorreta da conta de origem. Operação cancelada.\n");
        }
    } else {
        printf("Conta de origem não encontrada.\n");
    }
}
// Função para salvar os dados dos clientes em um arquivo binário
void salvarClientes(totalclientes *Clientes) {
    FILE *arquivo = fopen("clientes.bin", "wb");
   // Abre o arquivo para escrita binária
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar os clientes.\n");
        return;
    }
 // Verifica se o arquivo foi aberto corretamente
    if (fwrite(Clientes, sizeof(totalclientes), 1, arquivo) == 1) {
        fclose(arquivo);
        printf("Os Dados foram salvos com sucesso.\n");
    } else {
        fclose(arquivo);
        printf("Erro ao salvar os dados.\n");
    }
}
// Função para carregar os dados dos clientes de um arquivo binário
void carregarClientes(totalclientes *Clientes) 
  // Abre o arquivo para leitura binária{
    FILE *arquivo = fopen("clientes.bin", "rb");
 // Verifica se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        printf("Arquivo não encontrado. Criando novo arquivo...\n");
        salvarClientes(Clientes);
        return;
    }
// Lê os dados dos clientes do arquivo
    if (fread(Clientes, sizeof(totalclientes), 1, arquivo) == 1) {
        fclose(arquivo);
        printf("Dados carregados com sucesso!\n");
    } else {
        fclose(arquivo);
        printf("Erro ao carregar os dados.\n");
    }
}

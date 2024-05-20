// funcoes.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
// funcao que cadastra novo cliente
void NovoCliente(totalclientes *Clientes) {
    if (Clientes->qtd >= MAX_CLIENTES) {
        printf("Limite máximo de clientes atingido.\n");
        return;
    }
// verifica se está na quantidade máxima
    clientedesc NovoCliente;
// exige informacoes para cadastro
    printf("Digite o primeiro nome do cliente: ");
    scanf("%s", NovoCliente.nome);

    printf("Digite o CPF do cliente: ");
    scanf("%ld", &NovoCliente.cpf);

    printf("Qual o tipo de conta?\n1 - Comum\n2 - Plus\n");
    scanf("%d", &NovoCliente.tipodeconta);

    printf("Qual o valor inicial da conta? ");
    scanf("%lf", &NovoCliente.valorinicial);

    printf("Digite a senha (até 10 dígitos): ");
    scanf("%s", NovoCliente.senha);
// cria o cliente 
    NovoCliente.saldoatual = NovoCliente.valorinicial;
    Clientes->Clientes[Clientes->qtd] = NovoCliente;
    Clientes->qtd++;
    printf("Cliente cadastrado com sucesso.\n");
}
// funcao para listar todos clientes
void Listarclientes(totalclientes *TodosClientes) {
    if (TodosClientes->qtd == 0) {
        printf("Nenhum cliente encontrado.\n");
        return;
    }

    printf("Lista de clientes:\n");
    //intera no array para printar todos clientes e info de conta

    for (int i = 0; i < TodosClientes->qtd; i++) {
        printf("Nome: %s\n", TodosClientes->Clientes[i].nome);
        printf("CPF: %ld\n", TodosClientes->Clientes[i].cpf);
        printf("Tipo de conta: %s\n", TodosClientes->Clientes[i].tipodeconta == 1 ? "Comum" : "Plus");
        printf("Valor inicial: %.2lf\n", TodosClientes->Clientes[i].valorinicial);
        printf("Saldo atual: %.2f\n\n", TodosClientes->Clientes[i].saldoatual);
    }
}
// apaga cliente com base no cpf
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
// funcao debito
void debito(totalclientes *Clientes) {
    long cpf;
    char senha[11];
    double valor;
// cria variaveis sem ser global para usar na função
    printf("Digite o seu CPF: ");
    scanf("%ld", &cpf);

    int index = -1;
    for (int i = 0; i < Clientes->qtd; i++) {
        if (Clientes->Clientes[i].cpf == cpf) {
            index = i;
            break;
        }
    }
// confere a senha do cpf digitado
    if (index != -1) {
        printf("Digite a senha: ");
        scanf("%s", senha);
// solicita o valor desejado e adiciona a taxa
        if (strcmp(Clientes->Clientes[index].senha, senha) == 0) {
            printf("Digite o valor a ser debitado: ");
            scanf("%lf", &valor);

            double taxa = (Clientes->Clientes[index].tipodeconta == 1) ? 0.05 : 0.03;
            double saldo_atual = Clientes->Clientes[index].saldoatual - valor - (valor * taxa);
//confere se o valor esta dentro dos limites
            if (saldo_atual >= -MAX_SALDO_COMUM && saldo_atual >= -MAX_SALDO_PLUS) {
                Clientes->Clientes[index].saldoatual = saldo_atual;
                printf("Débito realizado com sucesso. Novo saldo: %.2f\n", saldo_atual);
            } else {
                printf("Limite de saldo excedido.\n");
            }
        } else {
            printf("Senha incorreta. Operação cancelada.\n");
        }
    } else {
        printf("Cliente não encontrado.\n");
    }
}
// deposita no cpf desejado
void deposito(totalclientes *Clientes) {
    long cpf;
    double valor;

    printf("Digite o seu CPF: ");
    scanf("%ld", &cpf);

    int index = -1;
    for (int i = 0; i < Clientes->qtd; i++) {
        if (Clientes->Clientes[i].cpf == cpf) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("Digite o valor a ser depositado: ");
        scanf("%lf", &valor);

        if (valor > 0) {
            Clientes->Clientes[index].saldoatual += valor;
            printf("Depósito realizado com sucesso. Novo saldo: %.2f\n", Clientes->Clientes[index].saldoatual);
        } else {
            printf("Valor inválido.\n");
        }
    } else {
        printf("Cliente não encontrado.\n");
    }
}

void extrato(totalclientes *Clientes) {
    long cpf;
    char senha[11];
// extrato do cliente com a primeiro valor e o atual
    printf("Digite o seu CPF: ");
    scanf("%ld", &cpf);
// com base no cpf indicado solicita senha e intera sobre a primeira e ultima transação após confirmação de dados
    int index = -1;
    for (int i = 0; i < Clientes->qtd; i++) {
        if (Clientes->Clientes[i].cpf == cpf) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("Digite a senha: ");
        scanf("%s", senha);

        if (strcmp(Clientes->Clientes[index].senha, senha) == 0) {
            printf("Extrato do cliente %s (CPF: %ld)\n", Clientes->Clientes[index].nome, cpf);
            printf("Saldo Inicial: %.2f\n", Clientes->Clientes[index].valorinicial);
            printf("Saldo Final: %.2f\n", Clientes->Clientes[index].saldoatual);
        } else {
            printf("Senha incorreta. Operação cancelada.\n");
        }
    } else {
        printf("Cliente não encontrado.\n");
    }
}
// funcao de transferência
void transferencia(totalclientes *Clientes) {
    long cpfOrigem, cpfDestino;
    char senhaOrigem[11];
    double valor;
// solicita cpf
    printf("Digite o seu CPF (Origem): ");
    scanf("%ld", &cpfOrigem);
// intera sobre clientes para identificar o cpf
    int indexOrigem = -1;
    for (int i = 0; i < Clientes->qtd; i++) {
        if (Clientes->Clientes[i].cpf == cpfOrigem) {
            indexOrigem = i;
            break;
        }
    }
// após indicado o cpf solicita senha para confirmação
    if (indexOrigem != -1) {
        printf("Digite a senha (Origem): ");
        scanf("%s", senhaOrigem);
// solicita cpf de destino
        if (strcmp(Clientes->Clientes[indexOrigem].senha, senhaOrigem) == 0) {
            printf("Digite o CPF (Destino): ");
            scanf("%ld", &cpfDestino);

            int indexDestino = -1;
            for (int i = 0; i < Clientes->qtd; i++) {
                if (Clientes->Clientes[i].cpf == cpfDestino) {
                    indexDestino = i;
                    break;
                }
            }
// solicita valor a ser transferido
            if (indexDestino != -1) {
                printf("Digite o valor a ser transferido: ");
                scanf("%lf", &valor);

                double saldo_atual_origem = Clientes->Clientes[indexOrigem].saldoatual - valor;
                double saldo_atual_destino = Clientes->Clientes[indexDestino].saldoatual + valor;
// confere se está certo o valor e da para ser debitado de acordo com os limites e saldo
                if (saldo_atual_origem >= -MAX_SALDO_COMUM && saldo_atual_origem >= -MAX_SALDO_PLUS) {
                    Clientes->Clientes[indexOrigem].saldoatual = saldo_atual_origem;
                    Clientes->Clientes[indexDestino].saldoatual = saldo_atual_destino;
                    printf("Transferência realizada com sucesso.\n");
                } else {
                    printf("Limite de saldo excedido.\n");
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
// funcao de salvar as infos
void salvarClientes(totalclientes *Clientes) {
    FILE *arquivo = fopen("clientes.bin", "wb");
// abre arquivo 
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar os clientes.\n");
        return;
    }

    if (fwrite(Clientes, sizeof(totalclientes), 1, arquivo) == 1) {
        fclose(arquivo);
        printf("Dados salvos com sucesso.\n");
    } else {
        fclose(arquivo);
        printf("Erro ao salvar os dados.\n");
    }
}
// carrega os clientes a partir de um arquivo usado anteriormente
void carregarClientes(totalclientes *Clientes) {
    FILE *arquivo = fopen("clientes.bin", "rb");
// abrindo
    if (arquivo == NULL) {
        printf("Arquivo não encontrado. Criando novo arquivo...\n");
        salvarClientes(Clientes);
        return;
    }
// criando arquivo caso não tenha
    if (fread(Clientes, sizeof(totalclientes), 1, arquivo) == 1) {
        fclose(arquivo);
        printf("Dados carregados com sucesso!\n");
        // carregou e fechou
    } else {
        fclose(arquivo);
        printf("Erro ao carregar os dados.\n");
    }
}

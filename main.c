#include <stdio.h>       // Inclui a biblioteca padrão de entrada e saída
#include <stdlib.h>      // Inclui a biblioteca padrão de funções úteis
#include "funcoes.h"    // Inclui o arquivo de cabeçalho que contém as definições das funções e estruturas utilizadas

// Function to save client data to a file
void salvarClientes(totalclientes *Clientes);
// Function to load client data from a file
void carregarClientes(totalclientes *Clientes);

int main() {
    totalclientes TodosClientes;    // Declara uma estrutura para armazenar todos os clientes
    TodosClientes.qtd = 0;    // Inicializa o contador de clientes como zero

    carregarClientes(&TodosClientes);    // Carrega os clientes do arquivo

    int escolha;    // Declara uma variável para armazenar a escolha do usuário

    // Loop infinito para exibir o menu de opções
    while (1) {
        printf("\nEscolha uma opção:\n");
        printf("1. Novo Cliente\n");
        printf("2. Apagar Cliente\n");
        printf("3. Listar Cliente\n");
        printf("4. Debito\n");
        printf("5. Deposito\n");
        printf("6. Extrato\n");
        printf("7. Transferencia entre contas\n");
        printf("8. Sair\n");
        printf("Digite o número da opção desejada: ");

        scanf("%d", &escolha);    // Lê a escolha do usuário

        // Estrutura de controle switch para executar a função correspondente à opção escolhida
        switch (escolha) {
            case 1:
                NovoCliente(&TodosClientes);    // Chama a função para cadastrar um novo cliente
                salvarClientes(&TodosClientes);    // Salva os clientes atualizados no arquivo
                break;
            case 2: {
                long cpf = 0; // define o cpf valor zerado
                printf("Digite o CPF do cliente a ser apagado: "); // printa 
                scanf("%ld", &cpf); // le o cpf indicado
                ApagarCliente(&TodosClientes, cpf); // ativa funcao de apagar cliente
                salvarClientes(&TodosClientes); // salva após apagar
                break;
                }
            case 3:
                Listarclientes(&TodosClientes);    // Chama a função para listar todos os clientes
                salvarClientes(&TodosClientes);    // Salva os clientes atualizados no arquivo
                break;
            case 4:
                debito(TodosClientes.Clientes);    // Chama a função para realizar um débito na conta de um cliente
                salvarClientes(&TodosClientes);    // Salva os clientes atualizados no arquivo
                break;
            case 5:
                deposito(TodosClientes.Clientes);    // Chama a função para realizar um depósito na conta de um cliente
                salvarClientes(&TodosClientes);    // Salva os clientes atualizados no arquivo
                break;
            case 6:
                extrato(TodosClientes.Clientes);    // Chama a função para exibir o extrato de um cliente
                salvarClientes(&TodosClientes);    // Salva os clientes atualizados no arquivo
                break;
            case 7:
                transferencia(TodosClientes.Clientes);    // Chama a função para realizar uma transferência entre contas
                salvarClientes(&TodosClientes);    // Salva os clientes atualizados no arquivo
                break;
            case 8:
                salvarClientes(&TodosClientes);    // Salva os clientes antes de sair
                printf("Que pena que escolheu sair. Até breve!\n");    // Exibe mensagem de despedida
                return 0;    // Encerra o programa
            default:
                printf("Opção inválida! Tente novamente.\n");    // Exibe mensagem de erro se a opção escolhida for inválida
        }
    }
}

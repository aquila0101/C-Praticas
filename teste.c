#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100
#define MAX_NOME 50

char produtos[MAX_PRODUTOS][MAX_NOME];
int numProdutos = 0;

void registrarProdutos() {
    int quantidade, i;

    printf("Quantos produtos deseja registrar? ");
    scanf("%d", &quantidade);

    if (quantidade + numProdutos > MAX_PRODUTOS) {
        printf("Limite de produtos atingido. Não é possível registrar mais.\n");
        return;
    }

    for (i = 0; i < quantidade; i++) {
        printf("Digite o nome do produto %d: ", i + 1);
        scanf("%s", produtos[numProdutos + i]);
    }

    numProdutos += quantidade;
    printf("%d produtos registrados com sucesso!\n", quantidade);
}

void listarProdutos() {
    if (numProdutos == 0) {
        printf("Nenhum produto registrado.\n");
        return;
    }

    printf("\nProdutos registrados:\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("- %s\n", produtos[i]);
    }
}

int main() {
    int opcao;

    do {
        printf("\n#### Menu ####\n");
        printf("1 - Registrar Produtos\n");
        printf("2 - Listar Produtos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                registrarProdutos();
                break;
            case 2:
                listarProdutos();
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}

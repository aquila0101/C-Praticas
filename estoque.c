#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    float preco; //preço
    int quantidade; //quantidade em estoque
} Produto;

Produto produtos[MAX_PRODUTOS];
int numProdutos = 0;

void registrarProduto() {
    if (numProdutos == MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    printf("Nome do produto: ");
    scanf("%s", produtos[numProdutos].nome);

    printf("Preço: ");
    scanf("%f", &produtos[numProdutos].preco);

    printf("Quantidade em estoque: ");
    scanf("%d", &produtos[numProdutos].quantidade);

    numProdutos++;
    printf("Produto registrado com sucesso!\n");
}

void listarProdutos() {
    if (numProdutos == 0) {
        printf("Nenhum produto registrado.\n");
        return;
    }

    printf("\nProdutos registrados:\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("- %s (R$ %.2f) - %d unidades\n",
               produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
    }
}

int main() {
    int opcao;

    do {
        printf("\n#### Menu ####\n");
        printf("1 - Registrar Produto\n");
        printf("2 - Listar Produtos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");

        // entrada inválida
        if (scanf("%d", &opcao) != 1) {
            printf("Opção inválida! Digite um número.\n");
            while(getchar() != '\n');
            continue;
        }

        switch (opcao) {
            case 1:
                registrarProduto();
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

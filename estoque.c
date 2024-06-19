#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_PRODUTOS 100
#define MAX_NOME 50
#define MAX_DESC 100

typedef struct {
    int codigo;
    char nome[MAX_NOME];
    char descricao[MAX_DESC];
    float preco;
} Produto;

Produto produtos[MAX_PRODUTOS];
int numProdutos = 0;

// Funções auxiliares para formatação (linha e título)
void linha() {
    printf("========================================\n");
}

void titulo(const char *texto) {
    linha();
    printf("|| %30s ||\n", texto);
    linha();
}

// Função para cadastrar um novo produto
void cadastrarProduto() {
    system("cls || clear"); // Limpa a tela (Windows/Linux/macOS)
    titulo("CADASTRAR PRODUTO");

    if (numProdutos < MAX_PRODUTOS) {
        Produto novoProduto;

        printf("Código: ");
        scanf("%d", &novoProduto.codigo);
        getchar(); // Consumir o caractere de nova linha deixado pelo scanf

        printf("Nome: ");
        fgets(novoProduto.nome, MAX_NOME, stdin);
        novoProduto.nome[strcspn(novoProduto.nome, "\n")] = 0; // Remover a nova linha do fgets

        printf("Descrição: ");
        fgets(novoProduto.descricao, MAX_DESC, stdin);
        novoProduto.descricao[strcspn(novoProduto.descricao, "\n")] = 0;

        printf("Preço: ");
        scanf("%f", &novoProduto.preco);

        produtos[numProdutos++] = novoProduto;
        printf("\nProduto cadastrado com sucesso!\n\n");
    } else {
        printf("\nLimite de produtos atingido!\n\n");
    }
    system("pause");
}

// Função para listar os produtos cadastrados
void listarProdutos() {
    system("cls || clear");
    titulo("LISTAR PRODUTOS");

    if (numProdutos > 0) {
        for (int i = 0; i < numProdutos; i++) {
            printf("Código: %d\n", produtos[i].codigo);
            printf("Nome: %s\n", produtos[i].nome);
            printf("Descrição: %s\n", produtos[i].descricao);
            printf("Preço: %.2f\n", produtos[i].preco);
            printf("--------------------\n");
        }
    } else {
        printf("\nNenhum produto cadastrado!\n\n");
    }
    system("pause");
}

int main() {
    int opcao;

    do {
        setlocale(LC_ALL, "Portuguese");
        system("cls || clear");
        titulo("MENU PRINCIPAL");
        printf("|| 1 - Cadastrar Produto        ||\n");
        printf("|| 2 - Listar Produtos          ||\n");
        printf("|| 0 - Sair                    ||\n");
        linha();
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                listarProdutos();
                break;
            case 0:
                printf("\nSaindo do programa...\n");
                exit(0);
            default:
                printf("\nOpção inválida!\n\n");
                system("pause");
        }
    } while (opcao != 0);

    return 0;
}

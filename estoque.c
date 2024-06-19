
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_PRODUTOS 100
#define MAX_NOME 50
#define MAX_DESC 100

// Estrutura

typedef struct {
    int codigo;
    char nome[MAX_NOME];
    char descricao[MAX_DESC];
    float preco;
} Produto;

Produto produtos[MAX_PRODUTOS];
int numProdutos = 0;

// Linha do Menu
void linha() {
    printf("========================================\n");
}
void titulo(const char *texto) {
    linha();
    printf("|| %30s ||\n", texto);
    linha();
}

// Funções do menu
void cadastrarProduto() {
    system("cls");
    titulo("CADASTRAR PRODUTO");

    if (numProdutos < MAX_PRODUTOS) {
        Produto novoProduto;
        printf("Código: ");
        scanf("%d", &novoProduto.codigo);
        getchar();

        printf("Nome: ");
        fgets(novoProduto.nome, MAX_NOME, stdin);
        novoProduto.nome[strcspn(novoProduto.nome, "\n")] = 0;

        printf("Descricao: ");
        fgets(novoProduto.descricao, MAX_DESC, stdin);
        novoProduto.descricao[strcspn(novoProduto.descricao, "\n")] = 0;

        printf("Preço: ");
        scanf("%f", &novoProduto.preco);

        produtos[numProdutos++] = novoProduto;
        system("cls");
        printf("Produto cadastrado com sucesso!\n");

    } else {
        printf("Limite de produtos atingido!\n");
    }
}

void listarProdutos() {
    titulo("LISTAR PRODUTOS");

    if (numProdutos > 0) {
        for (int i = 0; i < numProdutos; i++) {
            printf("Código: %d\n", produtos[i].codigo);
            printf("Nome: %s\n", produtos[i].nome);
            printf("Descricao: %s\n", produtos[i].descricao);
            printf("Preço: %.2f\n", produtos[i].preco);
            printf("--------------------\n");
           // getchar();

        }
    } else {
        printf("Nenhum Produto Cadastrado!\n");
    }
}
int menuu() {
    int opcao;
    do {
        titulo("MENU PRINCIPAL");
        printf("|| 1 - Cadastrar Produto          ||\n");
        printf("|| 2 - Listar Produtos            ||\n");
        printf("|| 0 - Voltar                     ||\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                system("cls"); // Limpa a tela (Windows)
                listarProdutos();
                break;
            case 0:
                system("cls"); // Limpa a tela (Windows)
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção invalida!\n");
        }
        printf("\n");
    } while (opcao != 0 && opcao != 1 && opcao != 2);

    return 0;
}

int main() {
    int opcao;

    do {
        setlocale(LC_ALL, "Portuguese");
        titulo("MENU PRINCIPAL");
        printf("|| 1 - Cadastrar Produto          ||\n");
        printf("|| 2 - Listar Produtos            ||\n");
        printf("|| 0 - Sair                       ||\n");
        linha();
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                system("cls");
                listarProdutos();
                menuu();
                break;
            case 0:
                system("cls");
                printf("Saindo do programa...\n");
                break;
            default:
                system("cls");
                printf("Opção invalida!\n");
        }
       system("\n");
    } while (opcao != 0 || opcao !=1 || opcao !=2);

    return 0;
}

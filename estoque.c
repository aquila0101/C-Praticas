#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <windows.h>

#define MAX_PRODUTOS 100
#define MAX_NOME 50
#define MAX_DESC 100
#define NOME_ARQUIVO "produtos.txt"

typedef struct {
    int codigo;
    char nome[MAX_NOME];
    char descricao[MAX_DESC];
    float preco;
} Produto;

Produto produtos[MAX_PRODUTOS];
int numProdutos = 0;

void linha() {
    printf("========================================\n");
}

void titulo(const char *texto) {
    linha();
    printf(texto);
    linha();
}

void cadastrarProduto() {
    system("cls || clear");
    titulo("CADASTRAR PRODUTO\n");

    if (numProdutos < MAX_PRODUTOS) {
        Produto novoProduto;
        int codigoDuplicado;

        do {
            codigoDuplicado = 0;
            printf("Código: ");
            scanf("%d", &novoProduto.codigo);
            getchar();

            for (int i = 0; i < numProdutos; i++) {
                if (produtos[i].codigo == novoProduto.codigo) {
                    codigoDuplicado = 1;
                    printf("Código já cadastrado! Digite outro código.");
                    break;
                }
            }
        } while (codigoDuplicado);

        printf("Nome: ");
        fgets(novoProduto.nome, MAX_NOME, stdin);
        novoProduto.nome[strcspn(novoProduto.nome, "\n")] = 0;

        printf("Descrição: ");
        fgets(novoProduto.descricao, MAX_DESC, stdin);
        novoProduto.descricao[strcspn(novoProduto.descricao, "\n")] = 0;

        printf("Preço: ");
        scanf("%f", &novoProduto.preco);

        produtos[numProdutos++] = novoProduto;
        printf("\nProduto cadastrado com sucesso!\n");

        // Salvar produto no arquivo
        FILE *arquivo = fopen(NOME_ARQUIVO, "a");
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo para escrita!");
            return;
        }

        fprintf(arquivo, "%d;%s;%s;%.2f\n", novoProduto.codigo, novoProduto.nome, novoProduto.descricao, novoProduto.preco);
        fclose(arquivo);
    } else {
        printf("\nLimite de produtos atingido!\n");
    }
    system("pause");
}

void listarProdutos() {
    system("cls || clear");
    titulo("LISTAR PRODUTOS\n");

    FILE *arquivo = fopen(NOME_ARQUIVO, "r");
    if (arquivo == NULL) {
        printf("\nNenhum produto cadastrado!\n");
        system("pause");
        return;
    }

    Produto produto;
    while (fscanf(arquivo, "%d;%49[^;];%99[^;];%f\n", &produto.codigo, produto.nome, produto.descricao, &produto.preco) == 4) {
        printf("Código:");
        printf("%d\n", produto.codigo);
        printf("Nome:");
        printf("%s\n", produto.nome);
        printf("Descrição:");
        printf("%s\n", produto.descricao);
        printf("Preço:");
        printf("%.2f\n", produto.preco);
        printf("--------------------\n");
    }

    fclose(arquivo);
    system("pause");
}

int main() {
    int opcao;

    do {
        setlocale(LC_ALL, "Portuguese");
        system("cls || clear");
        titulo("      MENU PRINCIPAL                   \n");
        printf("||   1 - Cadastrar Produto           ||\n");
        printf("||   2 - Listar Produtos             ||\n");
        printf("||   3 - Sair                        ||\n");

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
            case 3:
                system("cls");
                linha();
                printf("|| Saindo do Programa!              ||\n");
                linha();
                exit(0);
            default:
                printf("\nOpção inválida!\n\n");
                system("pause");
        }
    } while (opcao != 1 || opcao !=2 || opcao !=3);

    printf("\nOpção inválida!\n\n");
}

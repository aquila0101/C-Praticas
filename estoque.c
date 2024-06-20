#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>

#define MAX_PRODUTOS 100
#define MAX_NOME_PRODUTO 50

// Estrutura para representar um produto
typedef struct {
    int id;
    wchar_t nome[MAX_NOME_PRODUTO];
    float preco;
} Produto;

Produto produtos[MAX_PRODUTOS];
int numProdutos = 0;

// Função para gerar um ID aleatório
int gerar_id() {
    srand(time(NULL));
    return rand() % 1000;
}

// Função para registrar um produto
void registrar_produto() {
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    if (numProdutos >= MAX_PRODUTOS) {
        printf("Limite máximo de produtos atingido!\n");
        return;
    }

    Produto novoProduto;
    novoProduto.id = gerar_id();

    printf("\n========== Registrar Produto ==========\n");
    printf("Nome do produto: ");

    int ch;
    while ((ch = getchar()) != EOF && ch != '\n'); // Limpa o buffer
    fgetws(novoProduto.nome, MAX_NOME_PRODUTO, stdin);
    novoProduto.nome[wcslen(novoProduto.nome) - 1] = L'\0'; // Remove a nova linha

    do {
        printf("Preço (maior que zero): ");
        if (scanf("%f", &novoProduto.preco) != 1) {
            printf("Entrada inválida. Digite um número válido.\n");
            while ((ch = getchar()) != EOF && ch != '\n');
        } else if (novoProduto.preco <= 0) {
            printf("O preço deve ser maior que zero. Tente novamente.\n");
        }
    } while (novoProduto.preco <= 0);

    produtos[numProdutos] = novoProduto;
    numProdutos++;

    printf("Produto registrado com sucesso! (ID: %d)\n", novoProduto.id);
}

void imprimir_cabecalho(int tabSize) {
    wprintf(L"┌────────────┬────────────────");
    for (int i = 0; i < tabSize; i++) {
        wprintf(L"─");
    }
    wprintf(L"────┬────────────┐\n");
    wprintf(L"| ID\t| Nome");
    for (int i = 0; i < tabSize; i++) {
        wprintf(L" ");
    }
    wprintf(L" | Preço\t|\n");
    wprintf(L"├────────────┼────────────────");
    for (int i = 0; i < tabSize; i++) {
        wprintf(L"─");
    }
    wprintf(L"────┼────────────┤\n");
}
// Função para imprimir o corpo da tabela
void imprimir_produto(Produto p, int tabSize) {
    wprintf(L"| %d\t| %-15ls | R$ %.2f |\n", p.id, p.nome, p.preco);
}
// Função para imprimir o rodapé da tabela
void imprimir_rodape(int tabSize) {
    wprintf(L"└────────────┴────────────────");
    for (int i = 0; i < tabSize; i++) {
        wprintf(L"─");
    }
    wprintf(L"────┴────────────┘\n");
}
// Função para listar os produtos
void listar_produtos() {
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    wprintf(L"\n\t========== Lista de Produtos ==========\n\n");

    if (numProdutos == 0) {
        wprintf(L"\t   Nenhum produto cadastrado ainda.\n\n");
    } else {
        // Encontrar o nome mais longo para ajustar a tabulação
        int maxNomeLength = 0;
        for (int i = 0; i < numProdutos; i++) {
            int nomeLength = wcslen(produtos[i].nome);
            if (nomeLength > maxNomeLength) {
                maxNomeLength = nomeLength;
            }
        }

        // Calcular o número de espaços para a tabulação
        int tabSize = (maxNomeLength > 15) ? 1 : (15 - maxNomeLength);

        // Imprimir o cabeçalho
        imprimir_cabecalho(tabSize);

        // Imprimir cada produto
        for (int i = 0; i < numProdutos; i++) {
            imprimir_produto(produtos[i], tabSize);
        }

        // Imprimir o rodapé
        imprimir_rodape(tabSize);
    }
}


int main() {
    int opcao;
    int ch;
    setlocale(LC_ALL, "Portuguese");

    do {
        printf("\n\t========== Menu ==========\n\n");
        printf("\t1 - Registrar produto\n");
        printf("\t2 - Listar produtos\n");
        printf("\t3 - Sair\n\n");
        printf("\tOpção: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida. Digite um número válido.\n");
            while ((ch = getchar()) != EOF && ch != '\n');
            continue;
        }

        switch (opcao) {
            case 1:
                system("cls");
                registrar_produto();
                break;
            case 2:
                system("cls");
                listar_produtos();
                break;
            case 3:
                system("cls");
                printf("Encerrando o programa...\n");
                exit(0);
            default:
                printf("Opção inválida!\n");
                system("pause");
        }
    } while (opcao != 3);

    return 0;
}

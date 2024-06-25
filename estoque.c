#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define MAX_PRODUTOS 100

struct Produto {
    int id;
    char nome[50];
    float valor;
};

struct Produto produtos[MAX_PRODUTOS];
int numProdutos = 0;

void registrarProduto() {

    if (numProdutos < MAX_PRODUTOS) {
        srand(time(NULL)); // Inicializa o gerador de números aleatórios

        produtos[numProdutos].id = rand() % 1000 + 1; // ID aleatório entre 1 e 1000

        printf("Nome do Produto: ");
        scanf(" %[^\n]", produtos[numProdutos].nome);
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }


        printf("Valor do Produto: ");
        scanf("%f", &produtos[numProdutos].valor);

        numProdutos++;
        system("cls");
        printf("Produto registrado com sucesso!\n");
    } else {
        printf("Limite máximo de produtos atingido.\n");
    }
}

void listarProdutos() {
    system("cls");
    if (numProdutos == 0) {
        printf("Nenhum produto registrado.\n");
        return;
    }

    // Ordenar produtos por ID (Bubble Sort)
    for (int i = 0; i < numProdutos - 1; i++) {
    for (int j = 0; j < numProdutos - i - 1; j++) {
        if (produtos[j].id > produtos[j + 1].id) {
            struct Produto temp = produtos[j];
            produtos[j] = produtos[j + 1];
            produtos[j + 1] = temp;
        }
    }
}

    printf("\n");
    printf(" ____________________________________________________________________\n");
    printf("|                                    LISTA DE PRODUTOS                                   |\n");
    printf("|____________________________________________________________________|\n");
    printf("|  ID  |               Nome                |         Valor         |\n");
    printf("|______|___________________________________|_______________________|\n");

    for (int i = 0; i < numProdutos; i++) {
    printf("| %4d  | %-31s  | R$ %11.2f        |\n", produtos[i].id, produtos[i].nome, produtos[i].valor);
    printf("|______|___________________________________|_______________________|\n");
    }

}

void mostrarMenu() {
    printf("\n");
    printf(" _____________________________\n");
    printf("|                             |\n");
    printf("|          MENU              |\n");
    printf("|_____________________________|\n");
    printf("|                             |\n");
    printf("| 1. Registrar produto        |\n");
    printf("| 2. Listar produtos          |\n");
    printf("| 3. Sair                    |\n");
    printf("|_____________________________|\n");
}

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int opcao;

    do {
        mostrarMenu();
        printf("Opção: ");
        scanf("%d", &opcao);
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }

        switch (opcao) {
            case 1:
                registrarProduto();
                break;
            case 2:
                listarProdutos();
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 3);

    return 0;
}

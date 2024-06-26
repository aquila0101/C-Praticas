#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <localcharset.h>

#define MAX_PRODUTOS 100
#define LINHA "----------------------------------------\n"

struct Produto {
    char nome[50];
    float valor;
    int quantidade;
    int id;
};

struct Produto produtos[MAX_PRODUTOS];
int numProdutos = 0;

int gerarID() {
    return rand() % 1000 + 1;
}

int produtoExiste(const char *nome) {
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].nome, nome) == 0) {
            return 1;
        }
    }
    return 0;
}

void registrarProduto() {
    system("cls");
    fflush(stdin);

    if (numProdutos >= MAX_PRODUTOS) {
        printf("\nLimite de produtos atingido!\n");
        return;
    }

    struct Produto novoProduto;
    printf("\n" LINHA "--- Registrar Produto ---\n" LINHA);

    // Leitura do nome com espaços
    do {
        printf("Nome: ");
        if (fgets(novoProduto.nome, sizeof(novoProduto.nome), stdin) == NULL) {
            printf("Erro ao ler o nome do produto.\n");
            return;
        }

        // Remover o \n (nova linha) do final da string
        novoProduto.nome[strcspn(novoProduto.nome, "\n")] = 0; ;
    } while (produtoExiste(novoProduto.nome));

    printf("Valor: R$ ");
    scanf("%f", &novoProduto.valor);

    // Limpeza do buffer de entrada após scanf
   int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    printf("Quantidade: ");
    scanf("%d", &novoProduto.quantidade);

    novoProduto.id = gerarID();
    produtos[numProdutos++] = novoProduto;

    printf(LINHA "Produto registrado com sucesso! (ID: %d)\n" LINHA, novoProduto.id);
}


void listarProdutos() {
    system("cls");
    printf("\n" LINHA "--- Lista de Produtos ---\n" LINHA);
    if (numProdutos == 0) {
        printf("Nenhum produto registrado.\n");
        return;
    }

    for (int i = 0; i < numProdutos - 1; i++) {
        for (int j = 0; j < numProdutos - i - 1; j++) {
            if (produtos[j].id > produtos[j + 1].id) {
                struct Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < numProdutos; i++) {

        printf("ID: %d \n\t| Nome: %s \n\t| Valor: R$ %.2f \n\t| Quantidade: %d\n",
               produtos[i].id, produtos[i].nome, produtos[i].valor, produtos[i].quantidade);
        printf(LINHA);
    }

}

void buscarProdutoPorID() {
    system("cls");
    int idBusca;
    printf("\n" LINHA "--- Buscar Produto por ID ---\n" LINHA);
    printf("Digite o ID do produto: ");
    scanf("%d", &idBusca);

    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].id == idBusca) {
            printf(LINHA "Produto encontrado:\n");
            printf("ID: %d | Nome: %s | Valor: R$ %.2f | Quantidade: %d\n" LINHA,
                   produtos[i].id, produtos[i].nome, produtos[i].valor, produtos[i].quantidade);
            return;
        }
    }

    printf(LINHA "Produto não encontrado.\n" LINHA);
}

void mostrarMenu() {
    printf("\n");
    printf(" _____________________________\n");
    printf("|                             |\n");
    printf("|          MENU               |\n");
    printf("|_____________________________|\n");
    printf("|                             |\n");
    printf("| 1. Registrar Produto        |\n");
    printf("| 2. Listar Produtos          |\n");
    printf("| 3. Buscar Produto por ID    |\n");
    printf("| 4. Sair                     |\n");
    printf("|_____________________________|\n");
}


int main() {
    srand(time(NULL)); //Gerador de números aleatórios
    setlocale(LC_ALL, "");

    int escolha;
    do {
        mostrarMenu();
        printf("Opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                registrarProduto();
                break;
            case 2:
                listarProdutos();
                break;
            case 3:
                system("cls");
                buscarProdutoPorID();
                break;
            case 4:
                printf("\nSaindo do programa...\n");
                break;
            default:
                system("cls");
                printf("\nOpção inválida!\n");
        }
    } while (escolha != 4);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p1, i;
    char p2[50];

    printf("\n#### Menu ####\n");
    printf("1 - Registrar Produto\n");
    printf("2 - Listar Produtos Registrados\n");
    printf("0 - Sair\n");

    do {
        printf("Digite uma opção:\n");

        scanf("%d", &p1);

        switch (p1) {
            case 0:
                printf("Escolheu sair do menu\n");
                break;
            case 1:
                printf("Quantos produtos serão registrados? ");
                int quantidade;
                scanf("%d", &quantidade);
                for(i = 0; i < quantidade; i++) {
                printf("Qual produto irá ser registrado: ");
                scanf("%s", p2[i]);
                break;
            case 2:

                break;
            default:
                printf("Escolheu uma opção inválida\n");
                break;
        }
    } while (p1 != 0);
}

}


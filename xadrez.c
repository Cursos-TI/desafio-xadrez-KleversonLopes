/**
 * author: Kleverson
 * description: Implementação do sistema de movimentação das peças de xadrez.
 * data: 26-08-2025
 * intituição: Faculdade Estácio de Sá - Vitória - ES
 */

#include <stdio.h>
#include <stdlib.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

void LimpaTela() {
    // Limpar a tela
    #ifdef __linux__ // se o SO for linux
        system("clear");
    #elif _WIN32 // se o SO for Windows
        system("cls");
    #endif
}

void Espera() {
    printf("\n*** Pressione ENTER para continuar...");
    int c;
    // Limpa qualquer entrada residual
    while ((c = getchar()) != '\n' && c != EOF);
    // Espera o ENTER
    getchar();
}

void moveTorre() {
    const int MAX_MOVIMENTO_TORRE = 5;
    printf("\n*** Movimento da Torre ***\n");
    for (int i = 1; i <= MAX_MOVIMENTO_TORRE; i++) {
        printf("Direita (%d)\n", i);
    }
}

void moveBispo() {
    const int MAX_MOVIMENTO_BISPO = 5;
    printf("\n*** Movimento do Bispo ***\n");
    for (int i = 1; i <= MAX_MOVIMENTO_BISPO; i++) {
        printf("Direita | ");
        printf("Cima (%d)\n", i);
    }
}

void moveRainha() {
    const int MAX_MOVIMENTO_RAINHA = 8;
    printf("\n*** Movimento da Rainha ***\n");
    for (int i = 1; i <= MAX_MOVIMENTO_RAINHA; i++) {
        printf("Esquerda (%d)\n", i);
    }
}

void moveCavalo() {
    const int MAX_MOVIMENTO_CAVALO = 2;
    printf("\n*** Movimento do Cavalo ***\n");

    int j = 1;

    for (int i = 1; i <= MAX_MOVIMENTO_CAVALO; i++) {
        printf("Baixo (%d)\n", i);

        while (i == MAX_MOVIMENTO_CAVALO) {
            printf("Esquerda (%d)\n", (i - 1));
            i++;
        }
    }
}

int main() {
    do {
        LimpaTela();
        
        printf("Desafio de Xadrez - MateCheck\n\n");
        printf("Escolha uma peça para mover:\n\n");
        printf("1. Torre\n");
        printf("2. Bispo\n");
        printf("3. Rainha\n");
        printf("4. Cavalo\n");
        printf("9. Todas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");

        int opcao;
        
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("Saindo...\n");
                return 0;
            case 1:
                moveTorre();
                break;
            case 2:
                moveBispo();
                break;
            case 3:
                moveRainha();
                break;
            case 4:
                moveCavalo();
                break;
            case 9:
                moveTorre();
                moveBispo();
                moveRainha();
                moveCavalo();
                break;
            default:
                printf("Opção inválida!\n");
        }
        
        Espera();

    } while (1);

    return 0;
}

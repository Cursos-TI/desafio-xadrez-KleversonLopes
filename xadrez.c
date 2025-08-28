/**
 * author: Kleverson
 * description: Implementação do sistema de movimentação das peças de xadrez.
 * data: 26-08-2025
 * intituição: Faculdade Estácio de Sá - Vitória - ES
 * Nível Mestre - 28-08-2025
 */

#include <stdio.h>
#include <stdlib.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

const int MAX_MOVIMENTO_TORRE = 5;
const int MAX_MOVIMENTO_BISPO = 5;
const int MAX_MOVIMENTO_RAINHA = 8;
const int MAX_MOVIMENTO_CAVALO = 2;

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

void moveTorre(int i) {
    if (i == MAX_MOVIMENTO_TORRE) printf("\n*** Movimento da Torre ***\n");

    if (i > 0) {
        moveTorre(--i);
        printf("Direita (%d)\n", i+1);
    }

}

void moveBispo(int i) {
    if (i == MAX_MOVIMENTO_BISPO) printf("\n*** Movimento do Bispo ***\n");

    if (i > 0) {
        moveBispo(--i);
        printf("Cima (%d)\n", i+1);
        int C = i;
        while (C == i) {
            C++;
            printf("Direita (%d)\n", C);
        }
    }

}

void moveRainha(int i) {
    if (i == MAX_MOVIMENTO_RAINHA) printf("\n*** Movimento da Rainha ***\n");

    if (i > 0) {
        moveRainha(--i);
        printf("Esquerda (%d)\n", i+1);
    }

}

void moveCavalo() {
    printf("\n*** Movimento do Cavalo ***\n");

    for (int C = 1, D = 1; C <= MAX_MOVIMENTO_CAVALO; C++, D++) {
        printf("Cima (%d)\n", C);
        
        if (D < 2)
            continue;
        
        printf("Direita (%d)\n", D-1);
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
                moveTorre(MAX_MOVIMENTO_TORRE);
                break;
            case 2:
                moveBispo(MAX_MOVIMENTO_BISPO);
                break;
            case 3:
                moveRainha(MAX_MOVIMENTO_RAINHA);
                break;
            case 4:
                moveCavalo();
                break;
            case 9:
                moveTorre(MAX_MOVIMENTO_TORRE);
                moveBispo(MAX_MOVIMENTO_BISPO);
                moveRainha(MAX_MOVIMENTO_RAINHA);
                moveCavalo();
                break;
            default:
                printf("Opção inválida!\n");
        }
        
        Espera();

    } while (1);

    return 0;
}

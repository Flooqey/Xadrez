#include <stdio.h>

// Quantidade de casas para cada peça
const int casasTorre = 5;
const int casasRainha = 8;
const int casasBispo = 4;
const int casasCavaloVertical = 3;
const int casasCavaloHorizontal = 3;

//TORRE
void moverTorre(int casas) {
    if (casas <= 0) return;
    printf("Direita\n");
    moverTorre(casas - 1);
}

// RAINHA
void moverRainha(int casas) {
    if (casas <= 0) return;
    printf("Esquerda\n");
    moverRainha(casas - 1);
}

// BISPO
void moverBispoRecursivo(int casas) {
    if (casas <= 0) return;
    printf("Cima\n");
    printf("Direita\n");
    moverBispoRecursivo(casas - 1);
}

// Loop aninhado adicional para o bispo
void moverBispoComLoops() {
    for (int i = 0; i < casasBispo; i++) {
        for (int j = 0; j < casasBispo; j++) {
            if (i == j) {
                printf("Diagonal (Cima e Direita)\n");
            }
        }
    }
}

//CAVALO
void moverCavalo() {
    for (int i = 0; i < casasCavaloVertical; i++) {
        for (int j = 0; j < casasCavaloHorizontal; j++) {
            if (i == 2 && j == 1) {
                printf("Cavalo: Duas para cima e uma para a direita\n");
                continue;
            }
            if (i + j > 3) break;
        }
    }
}

//MAIN
int main() {
    int opcao = 0;

    printf("Pecas:\n");
    printf("1. Bispo\n");
    printf("2. Torre\n");
    printf("3. Rainha\n");
    printf("4. Cavalo\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    printf("\n");

    switch (opcao) {
        case 1:
            printf("Movimento do Bispo (Recursivo):\n");
            moverBispoRecursivo(casasBispo);
            printf("\nMovimento do Bispo (Loops Aninhados):\n");
            moverBispoComLoops();
            break;
        case 2:
            printf("Movimento da Torre:\n");
            moverTorre(casasTorre);
            break;
        case 3:
            printf("Movimento da Rainha:\n");
            moverRainha(casasRainha);
            break;
        case 4:
            printf("Movimento do Cavalo:\n");
            moverCavalo();
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }

    return 0;
}

#include <stdio.h>

// Função recursiva para movimentar a Torre (Direita)
void moverTorre(int passos) {
    if (passos <= 0) return;
    printf("Direita\n");
    moverTorre(passos - 1);
}

// Função recursiva para movimentar o Bispo (Cima + Direita)
void moverBispoRecursivo(int passos) {
    if (passos <= 0) return;
    printf("Cima Direita\n");
    moverBispoRecursivo(passos - 1);
}

// Função recursiva para movimentar a Rainha (Esquerda)
void moverRainha(int passos) {
    if (passos <= 0) return;
    printf("Esquerda\n");
    moverRainha(passos - 1);
}

int main() {
    // Quantidade de movimentos
    int passosTorre = 5;
    int passosBispo = 5;
    int passosRainha = 8;

    // --- TORRE ---
    printf("Movimento da Torre (Recursivo):\n");
    moverTorre(passosTorre);
    printf("\n");

    // --- BISPO COM RECURSIVIDADE ---
    printf("Movimento do Bispo (Recursivo):\n");
    moverBispoRecursivo(passosBispo);
    printf("\n");

    // --- BISPO COM LOOPS ANINHADOS ---
    printf("Movimento do Bispo (Loops Aninhados):\n");
    for (int linha = 0; linha < passosBispo; linha++) {
        for (int coluna = 0; coluna < 1; coluna++) { // 1 passo horizontal por linha
            printf("Cima Direita\n");
        }
    }
    printf("\n");

    // --- RAINHA ---
    printf("Movimento da Rainha (Recursivo):\n");
    moverRainha(passosRainha);
    printf("\n");

    // --- CAVALO COM LOOPS COMPLEXOS ---
    printf("Movimento do Cavalo (Loops Complexos):\n");
    int movimentosVerticais = 2;
    int movimentosHorizontais = 1;

    for (int i = 0, passosFeitos = 0; i < 3; i++) {  // Controla tentativas (poderia ser simulação de múltiplos Ls)
        for (int j = 0; j < movimentosVerticais + movimentosHorizontais; j++) {
            if (j < movimentosVerticais) {
                printf("Cima\n");
            } else if (j == movimentosVerticais) {
                if (i % 2 == 0) {
                    printf("Direita\n");
                } else {
                    printf("Direita\n"); // poderia ser uma variação como Esquerda para variar movimentos
                }
                break; // encerra após o "L" completo
            } else {
                continue; // ignora qualquer repetição extra
            }
        }
    }

    return 0;
}

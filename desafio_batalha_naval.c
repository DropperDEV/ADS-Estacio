#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define TAM 10
#define TAM_HABIL 5

int tabuleiro[TAM][TAM];

// Função para inicializar o tabuleiro com 0
void inicializarTabuleiro() {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;
}

// Função para posicionar navios no tabuleiro
bool posicionarNavio(int linha, int coluna, char direcao, int tamanho) {
    int dx = 0, dy = 0;

    switch (direcao) {
        case 'H': dy = 1; break;
        case 'V': dx = 1; break;
        case 'D': dx = dy = 1; break;
        case 'A': dx = 1; dy = -1; break;
        default: return false;
    }

    // Verifica limites
    for (int i = 0; i < tamanho; i++) {
        int x = linha + i * dx;
        int y = coluna + i * dy;

        if (x < 0 || x >= TAM || y < 0 || y >= TAM || tabuleiro[x][y] != 0)
            return false;
    }

    // Posiciona navio
    for (int i = 0; i < tamanho; i++) {
        int x = linha + i * dx;
        int y = coluna + i * dy;
        tabuleiro[x][y] = 3;
    }

    return true;
}

// Função para imprimir o tabuleiro
void exibirTabuleiro() {
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para criar matriz de habilidade
void criarMatrizHabilidade(char tipo, int matriz[TAM_HABIL][TAM_HABIL]) {
    for (int i = 0; i < TAM_HABIL; i++) {
        for (int j = 0; j < TAM_HABIL; j++) {
            matriz[i][j] = 0;

            if (tipo == 'C') { // Cruz
                if (i == TAM_HABIL / 2 || j == TAM_HABIL / 2)
                    matriz[i][j] = 1;

            } else if (tipo == 'O') { // Octaedro (losango)
                if (abs(i - TAM_HABIL / 2) + abs(j - TAM_HABIL / 2) <= TAM_HABIL / 2)
                    matriz[i][j] = 1;

            } else if (tipo == 'N') { // Cone (abaixo do topo)
                if (i >= 1 && j >= TAM_HABIL / 2 - i && j <= TAM_HABIL / 2 + i)
                    matriz[i][j] = 1;
                if (i == 0 && j == TAM_HABIL / 2)
                    matriz[i][j] = 1;
            }
        }
    }
}

// Sobrepõe matriz de habilidade no tabuleiro
void aplicarHabilidade(int origemX, int origemY, int matriz[TAM_HABIL][TAM_HABIL]) {
    int offset = TAM_HABIL / 2;
    for (int i = 0; i < TAM_HABIL; i++) {
        for (int j = 0; j < TAM_HABIL; j++) {
            int x = origemX + i - offset;
            int y = origemY + j - offset;

            if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
                if (matriz[i][j] == 1 && tabuleiro[x][y] == 0)
                    tabuleiro[x][y] = 5;
            }
        }
    }
}

int main() {
    inicializarTabuleiro();

    // Posicionar 4 navios
    bool n1 = posicionarNavio(1, 2, 'H', 3);
    bool n2 = posicionarNavio(5, 7, 'V', 3);
    bool n3 = posicionarNavio(0, 0, 'D', 3);
    bool n4 = posicionarNavio(0, 9, 'A', 3);

    if (!n1 || !n2 || !n3 || !n4)
        printf("Erro ao posicionar algum navio!\n");

    // Matrizes de habilidades
    int cone[TAM_HABIL][TAM_HABIL];
    int cruz[TAM_HABIL][TAM_HABIL];
    int octaedro[TAM_HABIL][TAM_HABIL];

    criarMatrizHabilidade('N', cone);
    criarMatrizHabilidade('C', cruz);
    criarMatrizHabilidade('O', octaedro);

    // Aplicar habilidades no tabuleiro
    aplicarHabilidade(2, 5, cone);       // cone centrado em (2,5)
    aplicarHabilidade(7, 2, cruz);       // cruz centrada em (7,2)
    aplicarHabilidade(5, 5, octaedro);   // octaedro centrado em (5,5)

    // Mostrar resultado
    exibirTabuleiro();

    return 0;
}

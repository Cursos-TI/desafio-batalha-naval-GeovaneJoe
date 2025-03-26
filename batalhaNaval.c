#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    // Imprimir a parte superior do tabuleiro com índices das colunas
    printf("   ");
    for (int j = 0; j < TAM_TABULEIRO; j++) {
        printf("%d ", j);  // Índices das colunas
    }
    printf("\n");

    // Imprimir o tabuleiro com os índices das linhas
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%d  ", i);  // Índices das linhas
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);  // Mostrar 0 (água) ou 3 (navio)
        }
        printf("\n");
    }
}

int main() {
    // Inicializa o tabuleiro com 0 (água)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Definir coordenadas e posições dos navios
    // Navio horizontal: começa na linha 3, coluna 2
    int linhaHorizontal = 3;
    int colunaHorizontal = 2;

    // Navio vertical: começa na linha 6, coluna 5
    int linhaVertical = 6;
    int colunaVertical = 5;

    // Posicionar o navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;
    }

    // Posicionar o navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = 3;
    }

    // Exibir o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
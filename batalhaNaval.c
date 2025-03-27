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

// Função para verificar se a posição é válida (não fora do tabuleiro ou sobreposição)
int verificarPosicaoValida(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int direcao, int tamanho) {
   
    // Direção 0 = Horizontal, 1 = Vertical, 2 = Diagonal principal, 3 = Diagonal inversa
    for (int i = 0; i < tamanho; i++) {
        int x = linha;
        int y = coluna;

        if (direcao == 0) {
            y += i;  // Horizontal
        } else if (direcao == 1) {
            x += i;  // Vertical
        } else if (direcao == 2) {
            x += i;
            y += i;  // Diagonal principal
        } else if (direcao == 3) {
            x += i;
            y -= i;  // Diagonal inversa
        }

        // Verificar se está fora do tabuleiro ou se já tem um navio na posição
        if (x < 0 || x >= TAM_TABULEIRO || y < 0 || y >= TAM_TABULEIRO || tabuleiro[x][y] == 3) {
            return 0;  // Posição inválida
        }
    }
    return 1;  // Posição válida
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int direcao, int tamanho) {
    if (verificarPosicaoValida(tabuleiro, linha, coluna, direcao, tamanho)) {
        for (int i = 0; i < tamanho; i++) {
            int x = linha;
            int y = coluna;

            if (direcao == 0) {
                y += i;  // Horizontal
            } else if (direcao == 1) {
                x += i;  // Vertical
            } else if (direcao == 2) {
                x += i;
                y += i;  // Diagonal principal
            } else if (direcao == 3) {
                x += i;
                y -= i;  // Diagonal inversa
            }

            tabuleiro[x][y] = 3;  // Marca a posição do navio
        }
    } else {
        printf("Posição inválida para o navio!\n");
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

    // Navio diagonal principal: começa na linha 0, coluna 0
    int linhaDiagonalPrincipal = 0;
    int colunaDiagonalPrincipal = 0;

    // Navio diagonal inversa: começa na linha 0, coluna 9
    int linhaDiagonalInversa = 0;
    int colunaDiagonalInversa = 9;

    // Posicionar os navios
    posicionarNavio(tabuleiro, linhaHorizontal, colunaHorizontal, 0, TAM_NAVIO); // Horizontal
    posicionarNavio(tabuleiro, linhaVertical, colunaVertical, 1, TAM_NAVIO);     // Vertical
    posicionarNavio(tabuleiro, linhaDiagonalPrincipal, colunaDiagonalPrincipal, 2, TAM_NAVIO); // Diagonal Principal
    posicionarNavio(tabuleiro, linhaDiagonalInversa, colunaDiagonalInversa, 3, TAM_NAVIO);   // Diagonal Inversa

    // Exibir o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}

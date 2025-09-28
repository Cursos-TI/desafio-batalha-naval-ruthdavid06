#include <stdio.h>

// constantes que definem o tamanho da matriz (tabuleiro) e o tamanho de cada navio
#define MATRIZ 10
#define TAM_NAVIO 3

// Função genérica para verificar e posicionar navio:
// Parâmetros: matriz, linha inicial, coluna inicial, vetor do navio, direção linha, direção coluna
int verificaEPosiciona(int tabuleiro[MATRIZ][MATRIZ], int linha, int coluna, int navio[], int direcaoLinha, int direcaoColuna) {

// Verifica limites do tabuleiro e evita sobreposição de navios
for (int i = 0; i < TAM_NAVIO; i++) {
int l = linha + i * direcaoLinha; // linha final = linha inicial + índice(0, 1 ou 2) x direcaoLinha(0, 1 ou -1)
int c = coluna + i * direcaoColuna; // coluna final = coluna inicial + (i)índice(0, 1 ou 2) x direcaoColuna(0, 1 ou -1)

    // linha final < 0 ou >= MATRIZ(10) ou coluna final < 0 ou >= MATRIZ(10) ou valor da posição[l][c] do tabuleito for diferente de zero
    if (l < 0 || l >= MATRIZ || c < 0 || c >= MATRIZ || tabuleiro[l][c] != 0) {
        return 0; // inválido
    }
}

// Posiciona o navio se válido
for (int i = 0; i < TAM_NAVIO; i++) {
    int l = linha + i * direcaoLinha;
    int c = coluna + i * direcaoColuna;
    tabuleiro[l][c] = navio[i]; // Atribui ao tabuleiro o valor correspondente do navio, de acordo com a posição calculada pelas variáveis de linha e coluna
}

return 1; // válido
}

int main(){

    // 1. Inicializa o tabuleiro com água representada pelo valor 0
    int tabuleiro[10][10] = {0};

    // 2. Define navios com tamanho fixo de 3 elementos que são representados pelo valor 3 em cada posição
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};
    int navioDiagonal1[3] = {3, 3, 3};
    int navioDiagonal2[3] = {3, 3, 3};

    // 3. Define coordenadas de início (dentro dos limites do tabuleiro)

    int linhaH = 7; // linha onde o navio horizontal será posicionado
    int colunaH = 6; // coluna inicial do navio horizontal

    if (!verificaEPosiciona(tabuleiro, linhaH, colunaH, navioHorizontal, 0, 1)) { // Verifica e Posiciona o navio horizontal no tabuleiro
    printf("Erro ao posicionar navio horizontal\n");
}

    int linhaV = 4; // linha inicial do navio vertical
    int colunaV = 3; // coluna onde o navio vertical será posicionado

    if (!verificaEPosiciona(tabuleiro, linhaV, colunaV, navioVertical, 1, 0)) { // Verifica e Posiciona o navio vertical no tabuleiro
    printf("Erro ao posicionar navio vertical\n");
}

    int linhaDiagonal1 = 9; // linha inicial onde o navio Diagonal 1 será posicionado
    int colunaDiagonal1 = 0; // coluna inicial do navio Diagonal 1

    if (!verificaEPosiciona(tabuleiro, linhaDiagonal1, colunaDiagonal1, navioDiagonal1, -1, 1)) { // Verifica e Posiciona o navio Diagonal 1 no tabuleiro
    printf("Erro ao posicionar navio diagonal ↘\n");
}
    
    int linhaDiagonal2 = 2; // linha inicial onde o navio Diagonal 2 será posicionado
    int colunaDiagonal2 = 7; // coluna inicial do navio Diagonal 2

    if (!verificaEPosiciona(tabuleiro, linhaDiagonal2, colunaDiagonal2, navioDiagonal2, 1, 1)) { // Verifica e Posiciona o navio Diagonal 2 no tabuleiro
    printf("Erro ao posicionar navio diagonal ↙\n");
}

    // 8. Exibe o tabuleiro com loops aninhados
    printf("Tabuleiro de Batalha Naval:\n\n");

    for (int linha = 0; linha < 10; linha++){
        for (int coluna = 0; coluna < 10; coluna++){
            printf("%d ", tabuleiro[linha][coluna]); // imprime cada valor da matriz
        }
        printf("\n"); // nova linha após cada linha da matriz
    } 
    
    return 0;
}

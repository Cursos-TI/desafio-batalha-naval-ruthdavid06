#include <stdio.h>

// Desafio Jogo de Batalha Naval: nível mestre
// Habilidades especiais e áreas de efeito

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

    // 8. Define o tamanho das matrizes de habilidades especiais que são representadas no tabuleiro pelo valor 5 
    int cone[5][5] = {0};
    int cruz[4][4] = {0};
    int octaedro[3][3] = {0};

    int inicioCone = 2; // índice 2 na matriz 5x5

    for (int i = 0; i < 3; i++) { // Apenas 3 linhas serão preenchidas para formar o cone
    int inicio = inicioCone - i; // Define o ínicio da área que será ocupada pela figura cone na matriz da habilidade especial
    int fim = inicioCone + i; // Define o fim da área de ocupação da figura
    for (int j = inicio; j <= fim; j++) {
        cone[i][j] = 1; // A figura será representada pelo valor 1 na matriz de habilidade
    }
}
    // Origem das coordenadas da matriz cone dentro do tabuleiro
    int linhaTabuleiroCone = 0;
    int colunaTabuleiroCone = 4;

    for (int i = 0; i < 5; i++) { // loops aninhados para sobrepor a matriz cone ao tabuleiro
    for (int j = 0; j < 5; j++) {
        int linhaTab = linhaTabuleiroCone + i;
        int colunaTab = colunaTabuleiroCone -2 + j; // desloca -2 para alinhar o cone

        // Verifica se está dentro dos limites do tabuleiro
        if (linhaTab >= 0 && linhaTab < 10 && colunaTab >= 0 && colunaTab < 10) {
            if (cone[i][j] == 1) {
                tabuleiro[linhaTab][colunaTab] = 5; // A figura será representada no tabuleiro pelo valor 5
            }
        }
    }
}

    int centroCruz = 1; // índice 1 na matriz 4x4

    for (int i = 0; i < 4; i++) { // Define as linhas que serão ocupadas pela figura na matriz da habilidade especial
        cruz[i][centroCruz] = 1; 
    for (int j = 0; j < 3; j++) { // Define as colunas que serão ocupadas pela figura na matriz da habilidade especial
        cruz[centroCruz][j] = 1; // A figura será representada pelo valor 1 na matriz de habilidade 
    }
}

    // Origem das coordenadas da matriz cruz dentro do tabuleiro
    int linhaTabuleiroCruz = 5;
    int colunaTabuleiroCruz = 5;

    for (int i = 0; i < 4; i++){ // loops aninhados para sobrepor a matriz cruz ao tabuleiro
    for (int j = 0; j < 4; j++){
        int linhaTab = linhaTabuleiroCruz -1 + i;
        int colunaTab = colunaTabuleiroCruz -1 + j;

        // Verifica se está dentro dos limites do tabuleiro
        if (linhaTab >= 0 && linhaTab < 10 && colunaTab >= 0 && colunaTab < 10){
            if (cruz[i][j] == 1) {
                tabuleiro[linhaTab][colunaTab] = 5; // A figura será representada no tabuleiro pelo valor 5
            }
        }
    }
}

    int centroOctaedro = 1; // índice 1 na matriz 3x3

    for (int i = 0; i < 3; i++) { // Define as linhas que serão ocupadas pela figura na matriz da habilidade especial
        octaedro[i][centroOctaedro] = 1;
    for (int j = 0; j < 3; j++) { // Define as colunas que serão ocupadas pela figura na matriz da habilidade especial
        octaedro[centroOctaedro][j] = 1; // A figura será representada pelo valor 1 na matriz de habilidade 
    }
}

    // Origem das coordenadas da matriz octaedro dentro do tabuleiro
    int linhaTabuleiroOctaedro = 4;
    int colunaTabuleiroOctaedro = 1;

    for (int i = 0; i < 3; i++){ // loops aninhados para sobrepor a octaedro ao tabuleiro
    for (int j = 0; j < 3; j++){
        int linhaTab = linhaTabuleiroOctaedro -1 + i; 
        int colunaTab = colunaTabuleiroOctaedro -1 + j;

        // Verifica se está dentro dos limites do tabuleiro
        if (linhaTab >= 0 && linhaTab < 10 && colunaTab >= 0 && colunaTab < 10){
            if (octaedro[i][j] == 1){
            tabuleiro[linhaTab][colunaTab] = 5; // A figura será representada no tabuleiro pelo valor 5
            }
        }
    }
}

    // 9. Exibe o tabuleiro com loops aninhados
    printf("Tabuleiro de Batalha Naval:\n\n");

    for (int linha = 0; linha < 10; linha++){
        for (int coluna = 0; coluna < 10; coluna++){
            printf("%d ", tabuleiro[linha][coluna]); // imprime cada valor da matriz
        }
        printf("\n"); // nova linha após cada linha da matriz
    } 
    
    return 0;
}
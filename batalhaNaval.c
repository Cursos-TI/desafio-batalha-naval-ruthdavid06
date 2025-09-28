#include <stdio.h>

int main(){

    // 1. Inicializa o tabuleiro com água (0)
    int tabuleiro[10][10] = {0};

    // 2. Define navios com valor 3 em cada parte
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

    // 3. Define coordenadas de início (dentro dos limites do tabuleiro)
    int linhaH = 7; // linha onde o navio horizontal será posicionado
    int colunaH = 6; // coluna inicial do navio horizontal

    int linhaV = 4; // linha inicial do navio vertical
    int colunaV = 3; // coluna onde o navio vertical será posicionado

    // 4. Posiciona o navio horizontal no tabuleiro
    for (int i = 0; i < 3; i++) {
    tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    // 5. Posiciona o navio vertical no tabuleiro
    for (int i = 0; i < 3; i++) {
    tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    // 6. Exibe o tabuleiro com loops aninhados
    printf("Tabuleiro de Batalha Naval:\n\n");

    for (int linha = 0; linha < 10; linha++){
        for (int coluna = 0; coluna < 10; coluna++){
            printf("%d ", tabuleiro[linha][coluna]); // imprime cada valor da matriz
        }
        printf("\n"); // nova linha após cada linha da matriz
    } 
    
    
    
    return 0;
}


#include <stdio.h>
#include <stdlib.h> // para abs()

#define TAM 10
#define HAB 5

int main() {

    int tabuleiro[TAM][TAM];
    int i, j;

    // ==========================
    // Inicializa tabuleiro
    // ==========================
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ==========================
    // Navios (3)
    // ==========================
    tabuleiro[2][2] = 3;
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;

    tabuleiro[6][6] = 3;
    tabuleiro[7][6] = 3;
    tabuleiro[8][6] = 3;

    // ==========================
    // Matrizes de habilidade
    // ==========================
    int cone[HAB][HAB];
    int cruz[HAB][HAB];
    int octaedro[HAB][HAB];

    // -------- CONE --------
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            if (j >= (HAB / 2) - i && j <= (HAB / 2) + i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // -------- CRUZ --------
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            if (i == HAB / 2 || j == HAB / 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // -------- OCTAEDRO --------
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            if (abs(i - HAB / 2) + abs(j - HAB / 2) <= HAB / 2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // ==========================
    // Origens das habilidades
    // ==========================
    int coneL = 1, coneC = 5;
    int cruzL = 5, cruzC = 2;
    int octL  = 6, octC  = 7;

    // -------- Sobreposição Cone --------
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            int l = coneL + i;
            int c = coneC + j - HAB / 2;
            if (l >= 0 && l < TAM && c >= 0 && c < TAM && cone[i][j]) {
                if (tabuleiro[l][c] == 0) tabuleiro[l][c] = 5;
            }
        }
    }

    // -------- Sobreposição Cruz --------
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            int l = cruzL + i - HAB / 2;
            int c = cruzC + j - HAB / 2;
            if (l >= 0 && l < TAM && c >= 0 && c < TAM && cruz[i][j]) {
                if (tabuleiro[l][c] == 0) tabuleiro[l][c] = 5;
            }
        }
    }

    // -------- Sobreposição Octaedro --------
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            int l = octL + i - HAB / 2;
            int c = octC + j - HAB / 2;
            if (l >= 0 && l < TAM && c >= 0 && c < TAM && octaedro[i][j]) {
                if (tabuleiro[l][c] == 0) tabuleiro[l][c] = 5;
            }
        }
    }

    // ==========================
    // Exibição com A–J e 1–10
    // ==========================
    printf("\n    A B C D E F G H I J\n");
    printf("   -------------------\n");

    for (i = 0; i < TAM; i++) {
        printf("%2d | ", i + 1); // linhas 1–10
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
#include <stdio.h>

void floodFill(int M, int N, int picture[M][N], int r, int c, int color) {
    int originalColor = picture[r][c];

    if (originalColor == color) {
        return;
    }

    void fill(int x, int y) {
        if (x < 0 || x >= M || y < 0 || y >= N || picture[x][y] != originalColor) {
            return;
        }

        picture[x][y] = color;
        fill(x + 1, y);
        fill(x - 1, y);
        fill(x, y + 1);
        fill(x, y - 1);
    }

    fill(r, c);
}

void printPicture(int M, int N, int picture[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d  ", picture[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    int picture[M][N];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &picture[i][j]);
        }
    }

    int r, c, color;
    scanf("%d %d %d", &r, &c, &color);

    floodFill(M, N, picture, r, c, color);

    printPicture(M, N, picture);

    return 0;
}

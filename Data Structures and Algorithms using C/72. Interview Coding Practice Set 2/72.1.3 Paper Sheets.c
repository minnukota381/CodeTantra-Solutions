#include <stdio.h>

int minFolds(int h1, int h2, int w1, int w2) {
    int folds = 0;

    while (h1 > h2) {
        h1 = (h1 + 1) / 2;
        folds++;
    }

    while (w1 > w2) {
        w1 = (w1 + 1) / 2;
        folds++;
    }

    return folds;
}

int main() {
    int h1, h2, w1, w2;
    scanf("%d %d %d %d", &h1, &w1, &h2, &w2);
    printf("%d\n", minFolds(h1, h2, w1, w2));
    return 0;
}

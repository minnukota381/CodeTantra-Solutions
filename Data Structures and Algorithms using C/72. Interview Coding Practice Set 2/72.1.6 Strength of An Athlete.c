#include <stdio.h>

int main() {
    int N, K, count = 0;
    scanf("%d %d", &N, &K);

    int ath[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &ath[i]);
    }

    for (int i = 1; i <= K; i++) {
        int k = 0;
        for (int j = 0; j < N; j++) {
            if (i%ath[j] == 0) {
                k = 1;
                break;
            }
        }

        if (k == 0) {
            count++;

        }
    }
    printf("%d\n", count);
    return 0;
}

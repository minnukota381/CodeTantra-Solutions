#include <stdio.h>

#define MOD 1000000007

int countWays(int A) {
    int dp[A + 1];
    dp[0] = 1;
    for (int i = 1; i <= A; i++) {
        dp[i] = 0;
        for (int j = 1; j <= 6 && j <= i; j++) {
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }
    return dp[A];
}

int main() {
    int A;
    scanf("%d", &A);
    printf("%d\n", countWays(A));
    return 0;
}

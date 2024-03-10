#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int getTotalX(int a[], int n, int b[], int m) {
    int lcm_val = a[0];
    for (int i = 1; i < n; i++) {
        lcm_val = lcm(lcm_val, a[i]);
    }

    int gcd_val = b[0];
    for (int i = 1; i < m; i++) {
        gcd_val = gcd(gcd_val, b[i]);
    }

    int count = 0;
    for (int i = lcm_val; i <= gcd_val; i += lcm_val) {
        if (gcd_val % i == 0) {
            count++;
        }
    }

    return count;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n], b[m];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    printf("%d\n", getTotalX(a, n, b, m));
    return 0;
}

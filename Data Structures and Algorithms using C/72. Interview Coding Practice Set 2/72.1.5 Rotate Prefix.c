#include <stdio.h>
#include <string.h>

int minRotationsReq(int n, int f, int k, char c, char* s) {
    int count_c = 0;
    for (int i = 0; i < k; i++) {
        if (s[i] == c)
            count_c++;
    }
    if (count_c >= f)
        return 0;

    for (int i = 1; i <= n; i++) {
        char temp = s[n - 1];
        for (int j = n - 1; j > 0; j--) {
            s[j] = s[j - 1];
        }
        s[0] = temp;

        if (s[0] == c)
            count_c++;
        if (s[k] == c)
            count_c--;
        if (count_c >= f)
            return i;
    }

    return -1;
}

int main() {
    int n, f, k;
    char c;
    scanf("%d %d %d %c", &n, &f, &k, &c);
    char s[n];
    scanf("%s", s);

    printf("%d\n", minRotationsReq(n, f, k, c, s));
    return 0;
}

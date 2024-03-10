#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isBinary(const char *str) {
    while (*str) {
        if (*str != '0' && *str != '1') {
            return 0;
        }
        str++;
    }
    return 1;
}

char *addBinary(const char *a, const char *b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int max_len = len_a > len_b ? len_a : len_b;

    char *result = (char *)malloc((max_len + 2) * sizeof(char));
    result[max_len + 1] = '\0';

    int carry = 0, i = len_a - 1, j = len_b - 1, k = max_len;

    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result[k--] = sum % 2 + '0';
        carry = sum / 2;
    }

    return result + (result[0] == '0' ? 1 : 0);
}

int main() {
    char binary1[201], binary2[201];
    scanf("%s", binary1);
    scanf("%s", binary2);

    if (strlen(binary2) >= 200 || binary1[0] == '\0' || binary2[0] == '\0' || binary1[0] == '0' || binary2[0] == '0' || !isBinary(binary1) || !isBinary(binary2)) {
        return 1;
    }

    char *result = addBinary(binary1, binary2);

    if (result[0] == '\0') {
        printf("0\n");
    } else {
        printf("%s\n", result);
    }

    free(result);

    return 0;
}

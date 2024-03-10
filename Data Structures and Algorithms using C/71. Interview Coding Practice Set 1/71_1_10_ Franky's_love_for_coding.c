#include <stdio.h>
#include <string.h>

int checkOccurrences(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (str[j] - '0' == i) {
                count++;
            }
        }
        if (count != str[i] - '0') {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[100];
    scanf("%s", str);
    if (checkOccurrences(str)) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int minUnhappiness(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);

    int unhappiness = 0;
    for (int i = 0; i < n; i++) {
        unhappiness += abs(arr[i] - (i + 1));
    }

    return unhappiness;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", minUnhappiness(arr, n));

    return 0;
}

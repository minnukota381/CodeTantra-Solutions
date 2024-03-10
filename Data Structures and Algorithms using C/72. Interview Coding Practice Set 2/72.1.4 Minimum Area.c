#include <stdio.h>
#include <limits.h>

int main() {
    int n = 3; 
    int x[n], y[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &y[i]);
    }

    int k;
    scanf("%d", &k);

    int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;

    for (int i = 0; i < n; i++) {
        minX = (x[i] < minX) ? x[i] : minX;
        minY = (y[i] < minY) ? y[i] : minY;
        maxX = (x[i] > maxX) ? x[i] : maxX;
        maxY = (y[i] > maxY) ? y[i] : maxY;
    }

    int side = (maxX - minX > maxY - minY) ? maxX - minX : maxY - minY;

    side += 2;

    printf("%d\n", side * side);

    return 0;
}

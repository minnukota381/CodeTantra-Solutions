#include <stdio.h>

int calculateArea(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1) * abs(y2 - y1);
}

int findOverlapLength(int a, int b, int c, int d) {
    return (b > c && d > a) ? (b < d ? b - c : d - a) : 0;
}

int totalAreaCovered(int x1_rect1, int y1_rect1, int x2_rect1, int y2_rect1, int x1_rect2, int y1_rect2, int x2_rect2, int y2_rect2) {
    int area_rect1 = calculateArea(x1_rect1, y1_rect1, x2_rect1, y2_rect1);
    int area_rect2 = calculateArea(x1_rect2, y1_rect2, x2_rect2, y2_rect2);

    int overlap_width = findOverlapLength(x1_rect1, x2_rect1, x1_rect2, x2_rect2);
    int overlap_height = findOverlapLength(y1_rect1, y2_rect1, y1_rect2, y2_rect2);

    int overlap_area = overlap_width * overlap_height;

    return area_rect1 + area_rect2 - overlap_area;
}

int main() {
    int x1_rect1, y1_rect1, x2_rect1, y2_rect1;
    int x1_rect2, y1_rect2, x2_rect2, y2_rect2;

    scanf("%d %d", &x1_rect1, &y1_rect1);
    scanf("%d %d", &x2_rect1, &y2_rect1);
    scanf("%d %d", &x1_rect2, &y1_rect2);
    scanf("%d %d", &x2_rect2, &y2_rect2);

    printf("%d\n", totalAreaCovered(x1_rect1, y1_rect1, x2_rect1, y2_rect1, x1_rect2, y1_rect2, x2_rect2, y2_rect2));

    return 0;
}

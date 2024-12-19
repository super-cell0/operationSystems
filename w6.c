#include <stdio.h>

void swap(int x, int y);
void swap_point(int * x, int * y);

int main() {
    int x = 5;
    int y = 6;

    swap(x, y);
    printf("old x = %d, old y = %d\n", x, y);

    swap_point(&x, &y);
    printf("old x = %d, old y = %d\n", x, y);

    return 0;
}

void swap(int x, int y) {
    int t = x;
    x = y;
    y = t;
    printf("x = %d, y = %d\n", x, y);
}

void swap_point(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
    printf("x = %d, y = %d\n", *x, *y);
}
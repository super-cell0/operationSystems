#include <stdio.h>

#define R 3
#define C 4


int main() {

    int num[R][C] = {
        {6, 1, 2, 3},
        {3, 5, 6, 7},
        {9, 8, 7, 6},
    };

    for (int i = 0; i<R; i++) {
        for (int j = 0; j<C; j++) {
            printf("&a[%d][%d] = %p, a[%d][%d] = %d\n", i, j, &num[i][j], i, j, num[i][j]);
        }
    }

    int num2[2][R][C] = {
        {
            {6, 1, 2, 3},
            {3, 5, 6, 7},
            {9, 8, 7, 6},
        },
        {
            {6, 1, 2, 3},
            {3, 5, 6, 7},
            {9, 8, 7, 6},
        }
    };

    return 0;
}
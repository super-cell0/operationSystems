#include <stdio.h>
#include <stdbool.h>

#define M 5
#define N 5

int main() {

    int a[M][N] = {
        {3,7,3,9,3},
        {3,6,3,6,3},
        {4,5,4,5,4},
        {3,6,3,6,3},
        {3,8,3,8,3},
    };

    bool max_in_row[M][N] = {false};
    bool min_in_col[M][N] = {false};

    // 每一行的最大值
    for (int i = 0; i<M; i++) {
        int max = a[i][0];
        for (int j = 1; j<N; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
        for (int j=0; j<N; j++) {
            if (a[i][j] == max) {
                max_in_row[i][j] = true;
            }
        }
    }
    
    //每一列的最小值
    for (int j=0; j<N; j++) {
        int min = a[0][j];
        for (int i=1; i<M; i++) {
            if (a[i][j] < min) {
                min = a[i][j];
            }
        }
        for (int i= 0; i<M; i++) {
            if (a[i][j] == min) {
                min_in_col[i][j] = true;
            }
        }
    
    }

    for (int i = 0; i<M; i++) {
        for (int j = 0; j<N; j++) {
            if (max_in_row[i][j] == true && min_in_col[i][j] == true) {
                printf("[%d]", a[i][j]);
            } else {
                printf(" %d ", a[i][j]);
            }
        }
        printf("\n");
    
    }

    return 0;
}
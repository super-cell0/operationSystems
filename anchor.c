#include <stdio.h>
#include <stdbool.h>

#define M 5
#define N 5

int main() {

    int a[M][N] = {
        {3,7,7,9,3},
        {3,6,3,6,3},
        {4,5,4,5,4},
        {3,6,3,6,3},
        {3,8,3,8,3},
    };

    bool max_row[M][N] = {false};
    bool min_col[M][N] = {false};

    for (int i = 0; i<M; i++) {
        int max = a[i][0];
        for (int j = 1; j<N; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
        for (int j=0; j<N; j++) {
            if (a[i][j] == max) {
                max_row[i][j] = true;
            }
        }
    }



    return 0;
}
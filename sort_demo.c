#include <complex.h>
#include <stdio.h>


// 选择排序
int selectionSort(int sums[], int count) {
    for (int i = 0; i < count - 1; i++) {
        int k = i;
        for (int j = i + 1; j < count; j++) {
            if (sums[j] < sums[k]) {
                k = j;
            }
        }
        if (k != i) {
            int t = sums[i];
            sums[i] = sums[k];
            sums[k] = t;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {   
    int nums[] = {4,4,1,3,2, 5}; 
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("初始数组: \n");
    for (int i = 0; i < n; i++) {
        printf("%d, ", nums[i]);
    }
    printf("\n");

    selectionSort(nums, n);

    printf("排序后的数组: \n");
    for (int i = 0; i < n; i++) {
        printf("%d, ", nums[i]);
    }
    printf("\n");

    return 0;
}

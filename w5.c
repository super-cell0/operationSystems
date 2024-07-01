#include <stdio.h>

void my_insert(int *num, int count);
int merge_sort_w5();

int main() {
    int nums[] = {3, 2, 4,2 ,17,4,8};
    int count = sizeof(nums) / sizeof(nums[0]);

    merge_sort_w5();

    return 0;
}

void my_insert(int *nums, int count) {
    for (int i = 1; i<count; i++) {
        int base = nums[i];
        int j = i-1;
        while (j>=0 && nums[j] > base) {
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = base;
    }
}

// 归并的实现
int merge_sort_w5() {
    int num_a[] ={1,2,3,4,5,7,8,10,11};
    int num_b[] = {2,3,7,8,10};
    int count_a = sizeof(num_a) / sizeof(num_a[0]);
    int count_b = sizeof(num_b) / sizeof(num_b[0]);
    int i = 0;
    int j = 0;
    if (count_b > count_a) {
        return -1;
    }
    while (i < count_a && j < count_b) {
        if (num_a[i] <= num_b[j]) {
            printf("%d ", num_a[i]);
            i++;
        } else {
            printf("%d ", num_b[j]);
            j++;
        }
    }
    if (i != count_a) {
        while (i < count_a) {
            printf("%d ", num_a[i]);
            i++;
        }
    } else if (j != count_b) {
        while (j < count_b) {
            printf("%d ", num_b[j]);
        }
    }
    return 0;
}
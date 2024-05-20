#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mainHeader.h"
#include "leetcode.h"
#include "sortDemo.h"

int main() {

    int nums[] = { 6, 3, 7, 5, 1, 2, 4, 4, 6, 12, 9};
    int count = sizeof(nums) / sizeof(nums[0]);
    int singleNums[] = {3, 3, 4, 5, 4};
    int singleCount = sizeof(singleNums) / sizeof(singleNums[0]);

    bubble_sort(nums, count);

    for (int i = 0; i < count; i++) {
        printf("%d, ", nums[i]);
    }
    printf("\n");

    return 0;
}

// 根据所给的index插入一个值
void insert(int nums[], int *count, int number, int index) {
    if (index < 0 || index > *count) {
        printf("index无效\n");
        return;
    }
    for (int i = *count - 1; i > index; i--) {
        nums[i] = nums[i-1];
    }
    nums[index] = number;
    (*count)++;
}

// 随机访问数组的一个值
int random_element(int *nums, int count) {
    srand(time(NULL));
    int rand_index = rand() % count;
    int rand_num = nums[rand_index];
    return rand_num;
}

// 删除给定的index的值
void remove_element(int *nums, int *count, int index) {
    if (index < 0 || index >= *count) {
        printf("index无效\n");
        return;
    }
    for (int i = index; i < *count; i++) {
        nums[i] = nums[i+1];
    }
    (*count)--;
}

// 查找值
int find(int *num, int count, int target) {
    for (int i=0; i<count; i++) {
        if (num[i] == target) {
            return i;
        }
    }
    return -1;
}



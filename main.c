#include <stdio.h>
#include "header.h"
#include <stdlib.h>
#include <time.h>

void insert(int nums[], int *count, int number, int index) {
    if (index < 0 || index > *count) {
        printf("index无效");
        return;
    }
    for (int i = *count; i > index; i--) {
        nums[i] = nums[i-1];
    }
    nums[index] = number;
    (*count)++;
}

int random_element(int *nums, int count) {
    srand(time(NULL));
    int rand_index = rand() % count;
    int rand_num = nums[rand_index];
    return rand_num;
}

int main() {
    
    int nums[] = {3,4,2,1,6};
    int count = sizeof(nums) / sizeof(nums[0]);

    return 0;
}
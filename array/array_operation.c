#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// insert the element at the index of the array
void insert_on(int nums[], int *count, int number, int index) {
    //检查插入位置
    if (index < 0 || index > *count) {
        printf("插入索引无效!");
        return;
    }
    for (int i = *count; i > index; i--) {
        nums[i] = nums[i - 1];
    }
    nums[index] = number;
    //更新数组大小
    (*count)++;
}

// access an array of random elements
int randomAccess(int *nums, int count) {
    srand(time(NULL));
    int random_index = rand() % count;
    int num = nums[random_index];
    return num;
}

int main() {
    int nums[5] = { 100, 200, 300, 400, 500};
    int count = sizeof(nums) / sizeof(nums[0]);

    printf("初始数组:\n");
    for (int i = 0; i < count; i++) {
        printf("%d, ", nums[i]);
    }
    printf("\n");
    
    insert_on(nums, &count, 888, 5);

    printf("插入后的数组:\n");
    for (int i = 0; i < count; i++) {
        printf("%d, ", nums[i]);
    }
    printf("\n");

    int num = randomAccess(nums, count);
    printf("%d\n", num);

    return 0;
}
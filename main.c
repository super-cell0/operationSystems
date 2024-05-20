#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mainHeader.h"
#include "leetcode.h"

int main() {

//    int nums[] = { 6, 3, 7, 5, 1, 2, 4, 4, 6};
//    int count = sizeof(nums) / sizeof(nums[0]);
    int singleNums[] = {3, 3, 4, 5, 4};
    int singleCount = sizeof(singleNums) / sizeof(singleNums[0]);

    singleNumber(singleNums, singleCount);

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

void printfArray(int array[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");
}

int selectSort(int array[], int count) {
    for (int i = 0; i < count - 1; i++) {
        int k = i;
        for (int j = i + 1; j < count; j++) {
            if (array[j] < array[k]) {
                k = j;
            }
        }
        if (k != i) {
            int temp = array[i];
            array[i] = array[k];
            array[k] = temp;
        }
    }
    return 0;
}

int bubbleSort(int array[], int count) {
    for (int i = count - 1; i > 0; i--) {
        bool flag = false;
        for (int j = 0; j < i; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
        printfArray(array, count);
    }
    return 0;
}

// 插入排序
void insertSort(int arr[], int count) {
    for (int i = 1; i < count; i++) {
        int base = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > base) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = base;
    }
}

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void insertDemo(int arr[], int count) {
    for (int i = 1; i < count; i++) {
        int base = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > base) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = base;
    }
}

// 快速排序
// 哨兵划分
int quickSortFinal(int arr[], int start, int end) {
    int base = arr[start];
    int left = start;
    int right = end;
    while (left < right) {
        while (left < right && arr[right] >= base) {
            right--;
        }
        while (left < right && arr[left] <= base) {
            left++;
        }
        if (left < right) {
            swap(arr, left, right);
        }
    }
    swap(arr, left, start);
    return left;
}

void quickSortDemo(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = quickSortFinal(arr, left, right);
    quickSortDemo(arr, left, pivot - 1);
    quickSortDemo(arr, pivot + 1, right);
}



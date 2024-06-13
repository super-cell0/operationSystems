//
// Created by mac on 2024/5/20.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "sortDemo.h"

void sift_down1(int nums[], int count, int i) {
    while (1) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int m = i;
        if (l < count && nums[l] > nums[m]) {
            m = l;
        }
        if (r < count && nums[r] > nums[m]) {
            m = r;
        }
        if (m == i) {
            break;
        }
        int t = nums[i];
        nums[i] = nums[m];
        nums[m] = t;
        i = m;
    }
}

void heap_sort1(int nums[], int count) {
    for (int i = count / 2 - 1; i>=0; i--) {
        sift_down1(nums, count, i);
    }
    for (int i = count - 1; i>0; i--) {
        int t = nums[0];
        nums[0] = nums[i];
        nums[i] = t;
        sift_down1(nums, i, 0);
    }
}

void counting_sort(int nums[], int count) {
    //找出最大的数m
    int m = 0;
    for (int i = 0; i<count; i++) {
        if (nums[i]>m) {
            m = nums[i];
        }
    }
    // counter[num] 代表num的出现次数
    int *counter = calloc(m+1, sizeof(int));
    for (int i = 0; i<count; i++) {
        counter[nums[i]]++;
    }
    for (int i = 0; i<m; i++) {
        counter[i+1] = counter[i+1] + counter[i];
    }
    int *result = malloc(sizeof(int) * count);
    // 将 num 填入数组 result 的索引 prefix[num] - 1 处。
    // 令前缀和 prefix[num] 减小  ，从而得到下次放置 v 的索引
    for (int i = count-1; i>=0; i--) {
        int num = nums[i];
        result[counter[num]-1] = num;
        counter[num]--;
    }
    memcpy(nums, result, count * sizeof(int));
    free(counter);
    free(result);
}

void select_sort(int nums[], int count) {
    for (int i = 0; i < count - 1; i++) {
        int min_k = i;
        for (int j = i + 1; j < count; j++) {
            if (nums[j] < nums[min_k]) {
                min_k = j;
            }
        }
        if (min_k != i) {
            swap(nums, i, min_k);
        }
    }
}

void bubble_sort(int nums[], int count) {
    for (int i = count - 1; i > 0; i--) {
        bool flag = false;
        for (int j = 0; j < i; j++) {
            if (nums[j] > nums[j+1]) {
                swap(nums, j, j + 1);
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }
}

void insert_sort(int nums[], int count) {
    for (int i = 1; i < count; i++) {
        int base = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > base) {
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = base;
    }
}

int partition(int nums[], int start, int end) {
    int base = nums[start];
    int left = start;
    int right = end;
    while (left < right) {
        // 从右向左找首个小于基准数的元素
        while (left < right && nums[right] >= base) {
            right--;
        }
        // 从左向右找首个大于基准数的元素
        while (left < right && nums[left] <= base) {
            left++;
        }
        if (left < right) {
            swap(nums, left, right);
        }
    }
    // 将基准数交换至两子数组的分界线
    swap(nums, left, start);
    //printf_array(nums, end + 1);
    // 返回基准数的索引
    return left;
}

void quick_sort(int nums[], int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = partition(nums, left, right);
    quick_sort(nums, left, pivot - 1);
    quick_sort(nums, pivot + 1, right);
}

void merge(int num[], int left, int mid, int right) {
    int temp_size = right - left + 1;
    // malloc 用于在堆上分配内存，并返回一个指向所分配内存块的指针
    int *temp = (int *)malloc(temp_size * sizeof(int));
    int i = left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right) {
        if (num[i] <= num[j]) {
            temp[k++] = num[i++];
        } else {
            temp[k++] = num[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = num[i++];
    }
    while (j <= right) {
        temp[k++] = num[j++];
    }
    for (k = 0; k < temp_size; k++) {
        num[left+k] = temp[k];
    }
    free(temp);
}

void merge_sort(int num[], int left, int right) {
    if (left >= right) {
        return;
    }
    // 防止整数溢出
    int mid = left + (right - left) / 2;
    merge_sort(num, left, mid);
    merge_sort(num, mid + 1, right);
    merge(num, left, mid, right);
}

void printf_array(int array[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d,", array[i]);
    }
    printf("\n");
}

void swap(int nums[], int a, int b) {
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}
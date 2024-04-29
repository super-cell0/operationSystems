#include <stdio.h>
#include <stdbool.h>


// 冒泡排序是稳定排序 时间复杂度 O(n^2)
void bobble_sort(int arr[], int count) {
    for (int i = count - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

// 优化 如果某轮“冒泡”中没有执行任何交换操作，说明数组已经完成排序，可直接返回结果
void bubble_sort_optimize(int arr[], int count) {
    //外部循环控制每次冒泡的轮数，从数组的最后一个元素开始逐渐减少
    for (int i = count - 1; i > 0; i--) {
        bool flag = false;
        //内部循环遍历未排序的元素，并将当前元素与下一个元素进行比较，如果逆序则进行交换
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }
}

void bubble_sort_flip(int arr[], int count) {
    for (int i = 0; i < count - 1; i++) {
        bool flag = false;
        for (int j = 0; j < count - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j+1] = t;
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }
}


int main() {
    int arr[] = {4, 13, 3, 1, 5, 2};
    int count = sizeof(arr) / sizeof(arr[0]);

    bubble_sort_flip(arr, count);

    printf("排序后的数组:\n");
    for (int i = 0; i < count; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");

    return 0;
}
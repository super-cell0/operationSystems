#include <complex.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "header.h"
#include <stdlib.h>
#include <time.h>
#include <bootstrap.h>

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


ListNode *newListNode(int value) {
    ListNode *node;

    node = (ListNode *)malloc(sizeof(ListNode));
    node->value = value;
    node->next = NULL;

    return node;
}

void print_list(ListNode* head) {  
    ListNode* current = head; // 从头节点开始  
    while (current != NULL) { // 当 current 不是 NULL 时，继续循环  
        printf("%d->", current->value); // 打印当前节点的值  
        current = current->next; // 移动到下一个节点  
    }  
    printf("\n");
}

void printfArray(int array[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");
}

int selecte(int array[], int count) {
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

int bubble(int array[], int count) {
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

int main() {
    
    int nums[] = {5,14,9,8,6};
    int count = sizeof(nums) / sizeof(nums[0]);

    ListNode *n1 = newListNode(1);
    ListNode *n2 = newListNode(2);
    ListNode *n3 = newListNode(3);
    ListNode *n4 = newListNode(5);
    ListNode *n5 = newListNode(4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    bubble(nums, count);

    return 0;
}
#include <stdio.h>
#include "header.h"
#include <stdlib.h>
#include <time.h>

void insert(int nums[], int *count, int number, int index) {
    if (index < 0 || index > *count) {
        printf("index无效\n");
        return;
    }
    //在C语言中数组索引是从0开始的因此数组的最后一个元素的索引是 ‘数组长度减1’ 而不是数组长度
    for (int i = *count - 1; i > index; i--) {
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

void printList(ListNode* head) {  
    ListNode* current = head; // 从头节点开始  
    while (current != NULL) { // 当 current 不是 NULL 时，继续循环  
        printf("%d->", current->value); // 打印当前节点的值  
        current = current->next; // 移动到下一个节点  
    }  
    printf("\n");
}

int main() {
    
    int nums[] = {3,4,2,1,6};
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

    printList(n1);

    return 0;
}
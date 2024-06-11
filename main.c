#include <complex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mainHeader.h"
#include "leetcode.h"
#include "sortDemo.h"
#include "linkList.h"
#include "course.h"

void swapDemo(int nums[], int a, int b) {
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}

int partitionDemo(int nums[], int start, int end) {
    int base = nums[start];
    int left = start;
    int right = end;
    while (left < right) {
        while (left<right && nums[right] >= base) {
            right--;
        }
        while (left<right && nums[left] <= base) {
            left++;
        }
        if (left < right) {
            swapDemo(nums, left, right);
        }
    }
    swapDemo(nums, left, start);
    return left;
}
 
void demoN(int nums[], int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = partitionDemo(nums, left, right);
    demoN(nums, left, pivot-1);
    demoN(nums, pivot+1, right);
}

int main() {

    int nums[] = { 6, 3, 7, 5, 1, 2, 4, 4, 6, 12,9};
    int count = sizeof(nums) / sizeof(nums[0]);
    int singleNums[] = {3, 3, 4, 5, 4};
    int singleCount = sizeof(singleNums) / sizeof(singleNums[0]);

    // ListNode *head = initListNode();
    // ListNode *newNode = newListNode(89);
    // ListNode *n3 = head;
    // while (n3 != NULL && n3->next != NULL && n3->next->value != 4) {  
    //     n3 = n3->next; // 找到值为3的节点的前一个节点  
    // }
    
    for (int i = 0; i<count; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    demoN(nums, 0, count-1);

    for (int i = 0; i<count; i++) {
         printf("%d ", nums[i]);
    }

    return 0;
}


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

void demo23(int nums[], int count, int i) {
    while (1) {
        int l = 2*i+1;
        int r = 2*i+2;
        int m = i;
        if (l<count && nums[l]>nums[m]) {
            m = l;
        }
        if (r<count && nums[r]>nums[m]) {
            m = r;
        }
        if (m==i) {
            break;
        }
        int t = nums[i];
        nums[i] = nums[m];
        nums[m] = t;
        i = m;
    }
}

void demo24(int nums[], int count) {
    for (int i = count/2-1; i>=0; i--) {
        demo23(nums, count, i);
    }
    for (int i = count-1; i>0; i--) {
        int t = nums[0];
        nums[0] = nums[i];
        nums[i] = t;
        demo23(nums, i, 0);
    }
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

    demo24(nums, count);

    for (int i = 0; i<count; i++) {
         printf("%d ", nums[i]);
    }

    return 0;
}


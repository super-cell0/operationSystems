#include <stdio.h>

#include "mainHeader.h"
#include "leetcode.h"
#include "sortDemo.h"
#include "linkList.h"
#include "course.h"

int main() {

    int nums[] = { 6, 3, 7, 5, 1, 2, 4, 4, 6, 12, 9};
    int count = sizeof(nums) / sizeof(nums[0]);
    int singleNums[] = {3, 3, 4, 5, 4};
    int singleCount = sizeof(singleNums) / sizeof(singleNums[0]);

    // ListNode *head = initListNode();
    // ListNode *newNode = newListNode(89);
    // ListNode *n3 = head;
    // while (n3 != NULL && n3->next != NULL && n3->next->value != 4) {  
    //     n3 = n3->next; // 找到值为3的节点的前一个节点  
    // }
    
    // insert_list(n3, newNode);
    // print_list(head);

    digit();

    return 0;
}


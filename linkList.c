#include <stdio.h>
#include <stdlib.h>

// 链表节点
typedef struct ListNode {
    int value; // 节点值
    struct ListNode *next; //指向下一个节点的指针
} ListNode;

// 构造函数
ListNode *newListNode(int value) {
    ListNode *node;
    node = (ListNode *)malloc(sizeof(ListNode));
    node->value = value;
    node->next = NULL;

    return node;
}

ListNode *initListNode() {
    ListNode *n0 = newListNode(1);
    ListNode *n1 = newListNode(2);
    ListNode *n2 = newListNode(3);
    ListNode *n3 = newListNode(5);
    ListNode *n4 = newListNode(4);

    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    return n0;
}

// 访问节点
void printList(ListNode *node) {
    ListNode *current = node;
    while (current != NULL) {
        printf("%d->", current->value);
        current = current->next;
    }
    printf("\n");
}

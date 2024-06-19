#include <stdio.h>
#include <stdlib.h>

// 链表节点
typedef struct ListNode {
    int value; // 节点值
    struct ListNode *next; //指向下一个节点的指针
} ListNode;

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
    ListNode *n3 = newListNode(4);
    ListNode *n4 = newListNode(5);

    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    return n0;
}

void access_list(ListNode *node) {
    ListNode *crruent = node;
    while ( crruent != NULL) {
        printf("%d->", crruent->value);
        crruent = crruent->next;
    }
}

void insert_list(ListNode *n0, ListNode *P) {
    if (n0 != NULL) {
        ListNode *n1 = n0->next;
        P->next = n1;
        n0->next = P;
    }
}

void remove_list(ListNode *n0) {
    if (!n0->next) {
        return;
    }
    ListNode *P = n0->next;
    ListNode *n1 = P->next;
    n0->next = n1;
    free(P);
}

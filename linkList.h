#ifndef LINK_LIST_H
#define LINK_LIST_H

// 链表节点
typedef struct ListNode {
    int value; // 节点值
    struct ListNode *next; //指向下一个节点的指针
} ListNode;

// 构造函数
ListNode *newListNode(int value);

ListNode *initListNode();

// 访问节点
void print_list(ListNode *node);
// 插入节点
void insert_list(ListNode *n0, ListNode *P);
// 删除一个节点
void remove_list(ListNode *n0);

#endif
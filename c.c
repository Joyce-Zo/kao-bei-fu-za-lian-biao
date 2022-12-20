#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


struct Node
{
	int val;
	struct Node* next;
	struct Node* random;
};


struct Node* copyRandomList(struct Node* head)
{
    struct Node* cur = head;
    while (cur)
    {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        // 1.复制新节点到原节点后
        copy->next = cur->next;
        cur->next = copy;
        cur = copy->next;
    }

    // 2.根据原节点的random复制新节点的random
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;
        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            copy->random = cur->random->next;
        }
        cur = copy->next;
    }
    // 3.复制所有的新节点到一个新链表，并恢复原链表
    struct Node* copyhead, * copytail;
    cur = head;
    copyhead = copytail = cur->next;
    while (cur)
    {
        cur = copytail->next;
        copytail->next = cur->next;
        copytail = copytail->next;
    }
    return copyhead;
}

struct Node* copyRandomList(struct Node* head)
{
    struct Node* cur = head;
    while (cur)
    {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val; // 传值
        // 1.复制新节点到原节点后
        copy->next = cur->next;
        cur->next = copy;
        cur = copy->next;
    }

    // 2.根据原节点的random复制新节点的random
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;
        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            copy->random = cur->random->next;
        }
        cur = copy->next;
    }
    // 3.复制所有的新节点到一个新链表，并恢复原链表
    struct Node* copyhead = NULL, * copytail = NULL;
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next; // 保存每个新节点
        struct Node* next = copy->next;// 保存每个原节点的next

        if (copytail == NULL)
        {
            copyhead = copytail = copy;
        }
        else
        {
            copytail->next = copy;
            copytail = copy;
        }
        cur->next = next; // 原链表的连接
        cur = next;     // 原链表的cur指向下一个cur
    }
    return copyhead;
}
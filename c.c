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
        // 1.�����½ڵ㵽ԭ�ڵ��
        copy->next = cur->next;
        cur->next = copy;
        cur = copy->next;
    }

    // 2.����ԭ�ڵ��random�����½ڵ��random
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
    // 3.�������е��½ڵ㵽һ�����������ָ�ԭ����
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
        copy->val = cur->val; // ��ֵ
        // 1.�����½ڵ㵽ԭ�ڵ��
        copy->next = cur->next;
        cur->next = copy;
        cur = copy->next;
    }

    // 2.����ԭ�ڵ��random�����½ڵ��random
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
    // 3.�������е��½ڵ㵽һ�����������ָ�ԭ����
    struct Node* copyhead = NULL, * copytail = NULL;
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next; // ����ÿ���½ڵ�
        struct Node* next = copy->next;// ����ÿ��ԭ�ڵ��next

        if (copytail == NULL)
        {
            copyhead = copytail = copy;
        }
        else
        {
            copytail->next = copy;
            copytail = copy;
        }
        cur->next = next; // ԭ���������
        cur = next;     // ԭ�����curָ����һ��cur
    }
    return copyhead;
}
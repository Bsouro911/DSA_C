#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

bool check(struct ListNode *a, struct ListNode **m_tmp)
{
    if (a == NULL)
    {
        return true;
    }

    if (!check(a->next, m_tmp))
    {
        return false;
    }

    if ((*m_tmp)->val != a->val)
    {
        return false;
    }

    *m_tmp = (*m_tmp)->next;
    return true;
}

bool isPalindrome(struct ListNode *head)
{
    struct ListNode *m_tmp = head;
    return check(head, &m_tmp);
}

void insert(struct ListNode **head, int val)
{
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

void freeList(struct ListNode *head)
{
    while (head != NULL)
    {
        struct ListNode *temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    struct ListNode *head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);

    if (isPalindrome(head))
    {
        printf("It's a palindrome.\n");
    }
    else
    {
        printf("It's not a palindrome.\n");
    }

    freeList(head);

    return 0;
}

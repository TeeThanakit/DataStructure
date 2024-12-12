#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *createLinkedList(struct Node *head, int n)
{
    struct Node *p, *q;

    p = (struct Node *)malloc(sizeof(struct Node));
    p->prev = NULL;
    p->data = n;
    p->next = NULL;

    if (head == NULL)
    {
        head = p;
    }
    else
    {
        q = head;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
        p->prev = q;
    }

    return head;
}

struct Node *DeleteElement(struct Node *head, int n)
{
    struct Node *head;
    struct Node *current = head;
    struct Node *p;

    if (head->data == n)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
    else
    {
        while (current != NULL && current->data != n)
        {
            current = current->next;
        }

        if (current == NULL)
        {
            printf("Number not found\n");
            return head;
        }

        if (current->prev != NULL)
        {
            current->prev->next = current->next;
        }

        if (current->next != NULL)
        {
            current->next->prev = current->prev;
        }
    }

    return head;
}

void printLinkedList(struct Node *head)
{
    struct Node *p;
    p = head;

    struct Node *q;
    while (p != NULL)
    {
        q = p;
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    while (q != NULL)
    {
        printf("%d ", q->data);
        q = q->prev;
    }
}

int main()
{
    struct Node *head = NULL;
    int n;

    while (1)
    {
        printf("Enter number:");
        scanf("%d", &n);

        if (n == 0)
            break;

        head = createLinkedList(head, n);
    }
    printLinkedList(head);

    return 0;
}
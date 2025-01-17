#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createLinkedList(struct Node *head, int n)
{
    struct Node *p = NULL, *q = NULL;

    p = (struct Node *)malloc(sizeof(struct Node));
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
    }

    return head;
}

void printLinkedList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node *deleteElement(struct Node *head, int n)
{
    struct Node *current = head;
    struct Node *previous;

    if (head->data == n)
    {
        head = head->next;
        free(current);
        return head;
    }
    while (current != NULL && current->data != n)
    {
        previous = current;
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Integet not found\n");
        return head;
    }

    previous->next = current->next;
    free(current);
    return head;
}

struct Node *InsertElement(struct Node *head, int n, int position)
{
    struct Node *current = head;
    struct Node *previous;

    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = n;
    p->next = NULL;

    if (position == 1)
    {
        p->next = head;
        head = p;
        return head;
    }

    for (int i = 0; i < position - 1; i++)
    {
        previous = current;
        current = current->next;
        if (current == NULL)
        {
            printf("This position does not exist!.");
            return head;
        }
    }

    previous->next = p;
    p->next = current;

    return head;
}

struct Node *Edit(struct Node *head, int n, int position)
{
    struct Node *current = head;

    for (int i = 0; i < position - 1; i++)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Position exceeds\n");
        return head;
    }

    current->data = n;
    return head;
}

int main()
{
    int n;
    struct Node *head = NULL;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;

        head = createLinkedList(head, n);
    }
    printLinkedList(head);
    scanf("%d", &n);
    // deleteElement(head, n);
    *InsertElement(head, 180, 3);
    printf("After deleted\n");
    printLinkedList(head);
}
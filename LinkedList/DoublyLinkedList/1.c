#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head = NULL, *p = NULL, *current = NULL;
    int n;

    while (1)
    {
        printf("Enter number: ");
        scanf("%d", &n);

        if (n == 0)
            break;

        p = (struct Node *)malloc(sizeof(struct Node));
        p->prev = NULL;
        p->data = n;
        p->next = NULL;

        if (head == NULL)
        {
            head = p;
            current = p;
        }
        else
        {
            p->prev = current;
            current->next = p;
            current = current->next;
        }
    }

    printf("Printing forward\n");
    p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\nPrinting Backward\n");
    p = current;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->prev;
    }
}

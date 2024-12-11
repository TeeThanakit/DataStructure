#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *p = NULL, *q = NULL, *head = NULL;
    int n;
    while (1)
    {
        printf("Enter number: ");
        scanf("%d", &n);

        if (n == 0)
            break;
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = n;
        p->next = NULL;

        if (head == NULL)
        {
            head = p;
        }
        else
        {
            q->next = p;
        }
        q = p;
    }
    printf("Test");
    p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
        free(head);
        head = p;
    }
}

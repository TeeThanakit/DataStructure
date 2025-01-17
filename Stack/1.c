#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack
{
    int arr[100];
    int top;
};

void startStack(struct Stack *stack)
{
    stack->top = -1;
}

bool isFull(struct Stack *stack)
{
    if (stack->top == 99)
        return true;
    else
        return false;
}

int main()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    startStack(stack);

    return 0;
}
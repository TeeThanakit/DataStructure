#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define size 10
struct Stack
{
    int arr[size];
    int top;
};

void startStack(struct Stack *stack)
{
    stack->top = -1;
}

bool isFull(struct Stack *stack)
{
    if (stack->top == size - 1)
        return true;
    else
        return false;
}

bool isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void Push(struct Stack *stack, int data)
{
    if (isFull(stack))
    {
        printf("The stack is full");
        // return stack;
    }
    stack->top += 1;
    stack->arr[stack->top] = data;
}

int Pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        int value = stack->arr[stack->top];
        stack->top -= 1;
        return value;
    }

    printf("Stack is empty\n");
    return stack;
}

int Peep(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        return stack->arr[stack->top];
    }

    printf("Stack is empty\n");
    return stack;
}

int main()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    startStack(stack);
    Push(stack, 1);
    Push(stack, 2);
    Push(stack, 3);
    Push(stack, 4);
    Push(stack, 5);
    printf("Value is %d\n", Pop(stack));
    printf("Top is %d", stack->top);
    return 0;
}
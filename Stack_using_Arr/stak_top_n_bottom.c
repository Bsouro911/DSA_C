#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
}

int
stackTop(struct stack *s)
{
    return s->arr[s->top];
};

int stackBottom(struct stack *s)
{
    return s->arr[0];
};

int main()

{
    // stack implementation

    return 0;
}
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *data;
    size_t capacity;
    size_t size;
} stack;

void stack_init(stack *s)
{
    s->data = NULL;
    s->capacity = 0;
    s->size = 0;
}

void stack_push(stack *s, char c)
{
    if (s->size == s->capacity)
    {
        s->capacity = (s->capacity == 0) ? 1 : s->capacity * 2;
        s->data = (char *)realloc(s->data, s->capacity * sizeof(char));
    }
    s->data[s->size++] = c;
}

char stack_top(stack *s)
{
    return s->data[s->size - 1];
}

void stack_pop(stack *s)
{
    if (s->size > 0)
    {
        s->size--;
    }
}

void stack_free(stack *s)
{
    free(s->data);
    s->data = NULL;
    s->capacity = 0;
    s->size = 0;
}

bool isValid(char *s)
{
    stack str;
    stack_init(&str);

    size_t len = strlen(s);
    for (size_t i = 0; i < len; i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            stack_push(&str, ch);
        }
        else
        {
            if (str.size > 0)
            {
                char top = stack_top(&str);
                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '['))
                {
                    stack_pop(&str);
                }
                else
                {
                    stack_free(&str);
                    return false;
                }
            }
            else
            {
                stack_free(&str);
                return false;
            }
        }
    }

    bool result = (str.size == 0);
    stack_free(&str);
    return result;
}

int main()
{
    char input[] = "{[()]}}";

    if (isValid(input))
    {
        printf("The input string is valid.\n");
    }
    else
    {
        printf("The input string is not valid.\n");
    }

    return 0;
}

#include <stdio.h>

struct NestedInteger
{
    int isInteger;                    // 1 if it's an integer, 0 if it's a nested list
    int value;                        // Value if it's an integer
    struct NestedInteger *nestedList; // Pointer to the nested list if it's not an integer
};

int nestedListSum(struct NestedInteger *nestedList)
{
    if (nestedList->isInteger)
    {
        return nestedList->value;
    }
    else
    {
        int sum = 0;
        struct NestedInteger *current = nestedList->nestedList;
        while (current != NULL)
        {
            sum += nestedListSum(current);
            current = current->nestedList;
        }
        return sum;
    }
}

int main()
{
    struct NestedInteger nestedList[] = {
        {1, 1, NULL},
        {0, 0, (struct NestedInteger[]){{1, 2, NULL}, {0, 0, (struct NestedInteger[]){{1, 3, NULL}, {1, 4, NULL}}}}},
        {0, 0, (struct NestedInteger[]){{1, 5, NULL}, {1, 6, NULL}}}};

    int sum = nestedListSum(nestedList);
    printf("Sum of all elements in the nested list: %d\n", sum);

    return 0;
}

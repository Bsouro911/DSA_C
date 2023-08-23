#include <stdio.h>
#include <stdbool.h>

bool isSubsetSum(int set[], int n, int target)
{
    // Base cases
    if (target == 0)
    {
        return true;
    }
    if (n == 0 && target != 0)
    {
        return false;
    }

    // If the last element is greater than the target, it can't be included
    if (set[n - 1] > target)
    {
        return isSubsetSum(set, n - 1, target);
    }

    // Check if the target can be achieved by either including or excluding the last element
    return isSubsetSum(set, n - 1, target) || isSubsetSum(set, n - 1, target - set[n - 1]);
}

int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(set) / sizeof(set[0]);
    int target = 9;

    if (isSubsetSum(set, n, target))
    {
        printf("Subset with sum %d exists.\n", target);
    }
    else
    {
        printf("No subset with sum %d exists.\n", target);
    }

    return 0;
}

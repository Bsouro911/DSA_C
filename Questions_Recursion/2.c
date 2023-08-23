#include <stdio.h>
#include <stdlib.h>

void findCombinations(int *candidates, int candidatesSize, int target, int *currentCombination, int currentSize, int currentIndex)
{
    if (target == 0)
    {
        // Print the combination
        printf("[");
        for (int i = 0; i < currentSize; i++)
        {
            printf("%d", currentCombination[i]);
            if (i < currentSize - 1)
            {
                printf(", ");
            }
        }
        printf("]\n");
        return;
    }

    if (currentIndex >= candidatesSize || target < 0)
    {
        return;
    }

    // Include the current candidate
    currentCombination[currentSize] = candidates[currentIndex];
    findCombinations(candidates, candidatesSize, target - candidates[currentIndex], currentCombination, currentSize + 1, currentIndex);

    // Exclude the current candidate and move to the next one
    findCombinations(candidates, candidatesSize, target, currentCombination, currentSize, currentIndex + 1);
}

void combinationSum(int *candidates, int candidatesSize, int target)
{
    int *currentCombination = (int *)malloc(target * sizeof(int));
    findCombinations(candidates, candidatesSize, target, currentCombination, 0, 0);
    free(currentCombination);
}

int main()
{
    int candidates[] = {2, 3, 6, 7};
    int candidatesSize = sizeof(candidates) / sizeof(candidates[0]);
    int target = 7;

    printf("Combinations that sum up to %d:\n", target);
    combinationSum(candidates, candidatesSize, target);

    return 0;
}

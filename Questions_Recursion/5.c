#include <stdio.h>

int countPaths(int m, int n)
{
    // Base case: reached bottom-right corner
    if (m == 1 && n == 1)
    {
        return 1;
    }

    // Recursive cases: move right and move down
    int pathsRight = (n > 1) ? countPaths(m, n - 1) : 0;
    int pathsDown = (m > 1) ? countPaths(m - 1, n) : 0;

    return pathsRight + pathsDown;
}

int main()
{
    int m = 3; // Number of rows
    int n = 3; // Number of columns

    int totalPaths = countPaths(m, n);
    printf("Total unique paths: %d\n", totalPaths);

    return 0;
}

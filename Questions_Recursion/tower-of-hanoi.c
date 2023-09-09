#include <stdio.h>

void hanoi(int n, char source, char target, char auxiliary)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from %c to %c", source, target);
        return;
    }
    hanoi(n - 1, source, auxiliary, target);
    printf("\n Move disk %d from %c to %c", n, source, target);
    hanoi(n - 1, auxiliary, target, source);
}

int main()
{
    int n = 4;
    hanoi(n, 'A', 'C', 'B');
    return 0;
}

#include <stdio.h>

void dfs(int arr[8][8], int size, int viz[8], int node)
{
    if (viz[node] == 0)
    {
        viz[node] = 1;
        printf("%d ", node + 1);
        for (int i = 0; i < size; i++)
        {
            if (viz[i] == 0 && arr[node][i] == 1)
            {
                dfs(arr, size, viz, i);
            }
        }
    }
}

int main()
{
    int arr[8][8] = {0};
    int visited[8] = {0};
    arr[0][1] = arr[1][0] = 1;
    arr[0][2] = arr[2][0] = 1;
    arr[1][3] = arr[3][1] = 1;
    arr[1][4] = arr[4][1] = 1;
    arr[2][5] = arr[5][2] = 1;
    arr[2][6] = arr[6][2] = 1;
    arr[3][7] = arr[7][3] = 1;
    arr[4][7] = arr[7][4] = 1;
    arr[5][7] = arr[7][5] = 1;
    arr[6][7] = arr[7][6] = 1;
    printf("DFS Traversal: ");
    for (int i = 0; i < 8; i++)
    {
        if (visited[i] == 0)
        {
            dfs(arr, 8, visited, i);
        }
    }

    return 0;
}

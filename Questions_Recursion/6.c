#include <stdio.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5

bool isSafe(int maze[ROWS][COLS], int x, int y)
{
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS && maze[x][y] == 0);
}

bool solveMazeUtil(int maze[ROWS][COLS], int x, int y, int solution[ROWS][COLS])
{
    // Base case: destination cell is reached
    if (x == ROWS - 1 && y == COLS - 1)
    {
        solution[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y))
    {
        solution[x][y] = 1;

        // Move right
        if (solveMazeUtil(maze, x, y + 1, solution))
        {
            return true;
        }
        // Move down
        if (solveMazeUtil(maze, x + 1, y, solution))
        {
            return true;
        }

        // If no path found, backtrack
        solution[x][y] = 0;
        return false;
    }

    return false;
}

void solveMaze(int maze[ROWS][COLS])
{
    int solution[ROWS][COLS] = {0};

    if (solveMazeUtil(maze, 0, 0, solution))
    {
        printf("Solution path:\n");
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                printf("%d ", solution[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("No solution path found.\n");
    }
}

int main()
{
    int maze[ROWS][COLS] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0}};

    printf("Maze:\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    solveMaze(maze);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define n 8
#define true 1
#define false 0

int stack[n], graph[n][n], visited[n];

int in_visited(int x) 
{
    int i;
    for (i = 0; i < n; i++) 
    {
        if (x == visited[i]) 
        {
            return true;
        }
    }
    return false;
}

void topological(int s, int *a) 
{
    int i;
    if (!in_visited(s)) 
    {
        visited[*a] = s;
        (*a)++;
        for (i = 0; i < n; i++) 
        {
            if (graph[s][i] == 1 && !in_visited(i)) 
            {
                topological(i, a);
            }
        }
        stack[s] = 1;
    }
}

int main() 
{
    int i, j;
    int a = 0;

    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            graph[i][j] = 0;
        }
    }

    graph[0][3] = 1;
    graph[1][0] = 1;
    graph[1][3] = 1;
    graph[3][2] = 1;
    graph[3][4] = 1;
    graph[5][4] = 1;
    graph[6][3] = 1;
    graph[6][5] = 1;
    graph[7][5] = 1;

    for (i = 0; i < n; i++) 
    {
        visited[i] = -1;
        stack[i] = 0;
    }

    for (i = 0; i < n; i++) 
    {
        if (!in_visited(i)) 
        {
            topological(i, &a);
        }
    }

    printf("Topological Sorting Order: ");
    for (i = a - 1; i >= 0; i--) 
    {
        printf("%d ", visited[i]);
    }
    printf("\n");

    return 0;
}


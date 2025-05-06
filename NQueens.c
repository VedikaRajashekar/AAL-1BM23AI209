#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int isSafe(int mat[MAX][MAX], int n, int row, int col) 
{
    int i, j;
    for (i = 0; i < row; i++) 
	{
        if (mat[i][col])
            return 0;
    }
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) 
	{
        if (mat[i][j])
            return 0;
    }
    for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) 
	{
        if (mat[i][j])
            return 0;
    }
    return 1;
}

int placeQueens(int row, int mat[MAX][MAX], int n) 
{
    int i;
    if (row == n)
        return 1;
    for (i = 0; i < n; i++) 
	{
        if (isSafe(mat, n, row, i)) 
		{
            mat[row][i] = 1;
            if (placeQueens(row + 1, mat, n))
                return 1;
            mat[row][i] = 0;
        }
    }
    return 0;
}

int nQueen(int n, int result[MAX]) 
{
    int mat[MAX][MAX];
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            mat[i][j] = 0;
    if (placeQueens(0, mat, n)) 
	{
        int idx = 0;
        for (i = 0; i < n; i++) 
		{
            for (j = 0; j < n; j++) 
			{
                if (mat[i][j]) 
				{
                    result[idx++] = j + 1;
                    break;
                }
            }
        }
        return idx;
    }
    result[0] = -1;
    return 1;
}

int main() 
{
    int n = 4;
    int result[MAX];
    int count, i;
    count = nQueen(n, result);
    for (i = 0; i < count; i++) 
	{
        printf("%d ", result[i]);
    }
    return 0;
}


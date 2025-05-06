#include <stdio.h>
#include <limits.h>

#define N 4
#define MAX_MASK (1 << N)

int cost[N][N] = 
{
    {0, 10, 15, 20},
    {5, 0, 9, 10},
    {6, 13, 0, 12},
    {8, 8, 9, 0}
};

int dp[MAX_MASK][N];

void init_dp() 
{
	int i,j;
    for ( i = 0; i < MAX_MASK; i++) 
	{
        for (j = 0; j < N; j++) 
		{
            dp[i][j] = -1;
        }
    }
}

int totalCost(int mask, int pos) 
{
    if (mask == (1 << N) - 1) 
	{
        return cost[pos][0];
    }

    if (dp[mask][pos] != -1) 
	{
        return dp[mask][pos];
    }

    int ans = INT_MAX;
	int i;
    for (i = 0; i < N; i++) 
	{
        if ((mask & (1 << i)) == 0) 
		{
            int newAns = cost[pos][i] + totalCost(mask | (1 << i), i);
            if (newAns < ans) 
			{
                ans = newAns;
            }
        }
    }

    dp[mask][pos] = ans;
    return ans;
}

int tsp() 
{
    init_dp();
    return totalCost(1, 0);
}

int main() 
{
    int result = tsp();
    printf("Cost of path is %d\n", result);
    return 0;
}


#include <stdio.h>

int main()
{
	int n= 4, graph[n][n], d, i, j;
	
	graph[0][0]= 0;
	graph[0][1]= 8;
	graph[0][2]= -999;
	graph[0][3]= 1;
	graph[1][0]= -999;
	graph[1][1]= 0;
	graph[1][2]= 1;
	graph[1][3]= -999;
	graph[2][0]= 4;
	graph[2][1]= -999;
	graph[2][2]= 0;
	graph[2][3]= -999;
	graph[3][0]= -999;
	graph[3][1]= 2;
	graph[3][2]= 9;
	graph[3][3]= 0;
	
	printf("\nGraph Network:\n");
	for(i= 0; i<n; i++)
	{
		for(j= 0; j<n; j++)
			printf("\t%d", graph[i][j]);
		printf("\n");
	}
	
	printf("\n");
	for(i= 0; i<n; i++)
		for(j= 0; j<n; j++)
			printf("Path cost from '%d' to '%d': %d\n", i, j, graph[i][j]);
	
	for(d= 0; d<n; d++)
	{
		for(i= 0; i<n; i++)
		{
			if(i==d)
				continue;
			for(j= 0; j<n; j++)
			{
				if(j==d)
					continue;
				int current= graph[i][j];
				int via_d;
				if(graph[i][d]==-999 || graph[d][j]==-999)
					via_d= -999;
				else
					via_d= graph[i][d]+graph[d][j];
				if(via_d!=-999 && (current==-999 || current>=via_d))
					graph[i][j]= via_d;
			}
		}
	}
	
	printf("\nAll Pairs Shortest Paths:\n");
	for(i= 0; i<n; i++)
	{
		for(j= 0; j<n; j++)
				printf("\t%d", graph[i][j]);
		printf("\n");
	}
	
	printf("\n");
	for(i= 0; i<n; i++)
		for(j= 0; j<n; j++)
				printf("Shortest Path from '%d' to '%d': %d\n", i, j, graph[i][j]);
				
	return 0;
}

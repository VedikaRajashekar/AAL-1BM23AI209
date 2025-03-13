#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	time_t start, stop;
	int n, key, beg, end, mid, i, j, temp;
	n= 100000;
	int a[n];
	for(i=0; i<n; i++)
		a[i]= rand() % 2000;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n-1-i; j++)
		{
			if (a[j]>a[j+1])
			{
				temp= a[j];
				a[j]= a[j+1];
				a[j+1]= temp;
			}
		}
	}
	printf("\nSorted Array:\n");
	for(i=0; i<n; i++)
		printf("%d\t", a[i]);
	key= rand() % 2000;
	beg= 0;
	end= n-1;
	i= 0;
	start= time(NULL);
	while (beg<=end)
	{
		mid= (beg+end)/2;
		if (a[mid]==key)
		{
			i= 1;
			break;
		}
		else if (a[mid]>key)
			end= mid;
		else
			beg= mid;
	}
	stop= time(NULL);
	if (i==0)
		printf("\n%d not found.\n", key);
	else
		printf("\n%d found at position %d.\n", key, mid);
	printf("\nSearch started at: %d\n", start);
	printf("\nSearch ended at: %d\n", stop);
	printf("\nTotal time taken to search: %d\n", (stop-start));
}

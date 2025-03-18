#include <stdio.h>
#include <time.h>

int main()
{
	time_t start, end;
	int n, i, j;
	n= 100000;
	int a[n];
	for(i=0; i<n; i++)
		a[i]= rand() % 10000;
	printf("\nArray before sorting:\n");
	for(i=0; i<n; i++)
		printf("%d\t", a[i]);
	start= time(NULL);
	for(i=0; i<n; i++)
	{
		int min= i;
		for(j=i+1; j<n; j++)
		{
			if (a[min]>a[j])
				min= j;
		}
		int temp= a[i];
		a[i]= a[min];
		a[min]= temp;
	}
	end= time(NULL);
	printf("\n\nArray after sorting:\n");
	for(i=0; i<n; i++)
		printf("%d\t", a[i]);
	printf("\n\nTime before starting the sort:%d\n", start);
	printf("\nTime after starting the sort%d:\n", end);
	printf("\nTime taken to sort:%d\n", end-start);
	return 0;
}

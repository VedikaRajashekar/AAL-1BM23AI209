#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	time_t start, end;
	int n= 500000;
	int a[n];
	int i, key, c= 0;
	for(i=0; i<n; i++)
		a[i]= rand() % 20000;
	printf("\nArray Elements:\n");
	for(i=0; i<n; i++)
		printf("%d\t", a[i]);
	key= rand() % 20000;
	printf("\nKey element: %d", key);
	start= time(NULL);
	printf("\nStart time of the Search: %d\n", start);
	for(i=0; i<n; i++)
	{
		if(a[i]==key)
		{
			c++;
			break;
		}
	}
	end= time(NULL);
	printf("\nEnd time of the Search: %d\n", end);
	printf("\nTotal time taken for the Search: %d\n", (end-start));
	if(c==1)
		printf("\n%d is present at position %d.\n", key, (i+1));
	else
		printf("\n%d is not present.\n");
	return 0;
}

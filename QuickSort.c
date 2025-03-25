#include<stdio.h>

int partition(int a[], int p, int q)
{
	int i= q;
	int j= p;
	while(i<j)
	{
		while(a[i]<=a[q] && j>=q+1)
			j--;
		if(i<j)
		{
			int temp= a[i];
			a[i]= a[j];
			a[j]= temp;
		}
	}
	int temp= a[q];
	a[q]= a[j];
	a[j]= temp;
	return j;
}

void quicksort(int a[], int p, int q)
{
	if(p<q)
	{
		int pi= partition(a, p, q);
		quicksort(a, p, pi-1);
		quicksort(a, pi+1, q);
	}
}

int main()
{
	int n;
	printf("Enter the number of array elements: ");
	scanf("%d", &n);
	int i, a[n];
	for(i= 0; i<n; i++)
		scanf("%d", &a[i]);
	int p= 0, q= n-1; 
	quicksort(a, 0, n-1);
	printf("\nArray after sorting:\n");
	for(i= 0; i<n; i++)
		printf("%d	", a[i]);
}

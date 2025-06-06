#include <stdio.h>

void swap(int *a, int *b)
{
	int temp= *a;
	*a= *b;
	*b= temp;
}

void heapify(int a[], int n, int i)
{
	int largest= i;
	int l= 2*i+1;
	int r= 2*i+2;
	if(l<n && a[l]>a[largest])
		largest= l;
	if(r<n && a[r]>a[largest])
		largest= r;
	if(largest!=i)
	{
		swap(&a[i], &a[largest]);
		heapify(a, n, largest);
	}
}

void heapsort(int a[], int n)
{
	int i;
	for(i= n/2-1; i>=0; i--)
		heapify(a, n, i);
	for(i= n-1; i>=0; i--)
	{
		swap(&a[0], &a[i]);
		heapify(a, i, 0);
	}
}

int main()
{
	int i, n= 15, a[n];
	for(i= 0; i<n; i++)
		a[i]= rand()%100;
	printf("\nUnsorted array is:\t");
	for(i= 0; i<n; i++)
		printf("%d\t", a[i]);
	heapsort(a, n);
	printf("\n\nSorted array is:\t");
	for(i= 0; i<n; i++)
		printf("%d\t", a[i]);
}

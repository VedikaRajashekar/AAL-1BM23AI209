#include <stdio.h>

void merge(int l[], int ls, int r[], int rs, int res[]) 
{
    int i = 0, j = 0, k = 0;

    while (i<ls && j<rs) 
	{
        if (l[i] < r[j])
            res[k++]= l[i++];
        else
            res[k++]= r[j++];
    }

    while (i<ls) 
        res[k++]= l[i++];
    while (j<rs) 
        res[k++]= r[j++];
}

void mergesort(int a[], int l, int r[]) 
{
	int i;
    if (l<=1) 
	{
        for (i= 0; i<l; i++) 
            r[i] = a[i];
        return;
    }    
    int mid= l/2;
    int lH[mid], rH[l-mid], sL[mid], sR[l - mid];    
    for (i= 0; i < mid; i++) 
        lH[i] = a[i];
    for (i= mid; i<l; i++)
        rH[i - mid] = a[i];
    mergesort(lH, mid, sL);
    mergesort(rH, l-mid, sR);
    merge(sL, mid, sR, l-mid, r);
}

int main() 
{
	int l= 100;
    int a[l];
    int i;
    for(i= 0; i<l; i++)
    	a[i]= rand() % 100;
    printf("\nUsorted array:\n");
    for (i= 0; i<l; i++) 
        printf("%d\t", a[i]);
    printf("\n");	
    int r[l];
    mergesort(a, l, r);
    printf("\nSorted array:\n");
    for (i= 0; i<l; i++)
        printf("%d\t", r[i]);
    printf("\n");
    return 0;
}


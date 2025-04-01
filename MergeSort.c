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

void mergesort(int a[], int len, int res[]) 
{
	int i;
    if (len<=1) 
	{
        for (i= 0; i<len; i++) 
            res[i] = a[i];
        return;
    }    
    int mid= len/2;
    int lH[mid], rH[len-mid], sL[mid], sR[len-mid];    
    for (i= 0; i<mid; i++) 
        lH[i] = a[i];
    for (i= mid; i<len; i++)
        rH[i - mid] = a[i];
    mergesort(lH, mid, sL);
    mergesort(rH, len-mid, sR);
    merge(sL, mid, sR, len-mid, res);
}

int main() 
{
	int len= 100;
    int a[len];
    int i;
    for(i= 0; i<len; i++)
    	a[i]= rand() % 100;
    printf("\nUsorted array:\n");
    for (i= 0; i<len; i++) 
        printf("%d\t", a[i]);
    printf("\n");	
    int res[len];
    mergesort(a, len, res);
    printf("\nSorted array:\n");
    for (i= 0; i<len; i++)
        printf("%d\t", res[i]);
    printf("\n");
    return 0;
}


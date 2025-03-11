#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	time_t start, end;
	int l= 500000;
	int a[l];
	int i, j, temp;
	for(i=0; i<l; i++)
		a[i]= rand() % 20000;
	printf("\nArray before Sorting:\n");
	for(i=0; i<l; i++)
		printf("%d\t", a[i]);
	start= time(NULL);
	printf("\nStart time of the Search: %d\n", start);
	for(i=0; i<l; i++)
    {
        for(j=0; j<l-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                temp= a[j];
                a[j]= a[j+1];
                a[j+1]= temp;
            }
        }
    }
	end= time(NULL);
	printf("\nEnd time of the Search: %d\n", end);
    printf("\nArray after Sorting:\n");
    for(i=0; i<l; i++)
        printf("%d\t", a[i]);
    return 0;
}

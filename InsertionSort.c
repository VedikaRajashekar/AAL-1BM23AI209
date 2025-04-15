#include<stdio.h>

int main()
{
	int i, j, n= 100, us[n], s[n];
	for(i= 0; i<n; i++)
		us[i]= rand() %200;
	printf("\nUnsorted List:\n");
	for(i= 0; i<n; i++)
		printf("%d\t", us[i]);
	s[0]= us[0];
	for(i= 1; i<n; i++)
	{
		s[i]= us[i];
		for(j= i; j>0; j--)
		{
			if (s[j]<s[j-1])
			{
				int temp= s[j];
				s[j]= s[j-1];
				s[j-1]= temp;
			}
			else
				break;
		}
	}
	printf("\nSorted List:\n");
	for(i= 0; i<n; i++)
		printf("%d\t", s[i]);
	return 0;
}

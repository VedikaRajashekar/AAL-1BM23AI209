#include<stdio.h>

int len(char ch[])
{
	int i= 0;
	while (ch[i] != '\0')
		i++;
	return i;
}

int main()
{
	char s[]= "Nobody_noticed him but we found him";
	char p[]= "him";
	int i, j, c, pos= 0, ls= len(s), lp= len(p);
	printf("\nString: %s\n", s);
	printf("\nPattern: %s\n", p);
	for(i=0; i<ls-lp+1; i++)
	{
		c= 0;
		for(j=0; j<lp; j++)
		{
			if(s[i+j]!=p[j])
			{	
				c= 1;		
				break;	
			}
		}
		if (c==0)
		{
			pos= i+1;
			printf("\nPattern found at position %d.\n", pos);
		}
	}
	if (pos==0)
		printf("\nPattern not found.\n");
	return 0;
}

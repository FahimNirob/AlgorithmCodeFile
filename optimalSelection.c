//note done yet
#include<stdio.h>
int min(int a,int b);
int main()
{
	int n=8,k=3;
	int total[1<<k][20];
	int price[1<<k][8];

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<8;j++)
		{
			scanf("%d",&price[i][j]);
		}
	}
	for (int x = 0; x < k; x++) 
	{
		total[1<<x][0] = price[x][0];
	}

	for (int d = 1; d < n; d++) 
	{
		for (int s = 0; s < (1<<k); s++) 
		{
			total[s][d] = total[s][d-1];
			for (int x = 0; x < k; x++) 
			{
				if (s&(1<<x)) 
				{
					total[s][d] = min(total[s][d],(total[s^(1<<x)][d-1]+price[x][d]));
					printf("%d\n",total[s][d]);
				}
			}
		}
	}
	printf("%d\n",total[2][7] );
}

int min(int a,int b)
{
	if(a>b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

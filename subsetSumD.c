//subset sum using dynamic programming

#include<stdio.h>

int main()
{
	int set[20],i,j,x,value,n,sum,t,z,subset[20];

	scanf("%d",&t);
	for(z=0;z<t;z++)
	{	
		printf("Enter number of elements in set: ");
		scanf("%d",&n);//number of element in set
		printf("Enter the elements of the set:\n");
		for(i=0;i<n;i++)
		{
			scanf("%d",&set[i]);
		}
		printf("Enter the sum to search: ");
		scanf("%d",&sum);//total sum

		int table[n+5][sum+5];

		//creating the table.
		
		//making the first column true
		for(int s = 0;s < n;s++)
		{
			table[s][0]=1;
		}
		for(i=0;i < n;i++)
		{
			 
			value = set[i];
			for(j=1;j<=sum;j++)
			{
				if(i==0)
				{
					if(j == value)
					{
						table[i][j] = 1;
					}
					else
					{
						table[i][j] = 0;
					}
				}
				else
				{
					if(value > j)
					{
						table[i][j] = table[i-1][j];
					}
					else
					{
						if(table[i-1][j]==1)
						{
							table[i][j] = 1;
						}
						else
						{
							table[i][j] = table[i-1][j-value];
						}
					}
				}
			}
		}

		j=sum;
		i=n-1;
		x = 0;
		while( i!=0 || j!=0)
		{
			if(table[i][j] & table[i-1][j])
			{
				i=i-1;
			}
			else
			{
				j=j-set[i];
				subset[x]=set[i];
				x++;
			}
		}
		if(sum == 0)
		{
			printf("Yes(0)\n");
		}
		else
		{	printf("Yes (");
			for(i=0;i<x;i++)
			{
			printf("%d ",subset[i]);
			}
			printf(")\n");
		}

	}


}
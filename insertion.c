#include<stdio.h>
void insertion(int ar[],int n);
int main()
{
	int ar[20],i,j,n;
	printf("Enter the number of element for sorting: ");
	scanf("%d",&n);
	printf("\n Enter the Numbers: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&ar[i]);
	}
	//sorting:
	insertion(ar,n);
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",ar[i]);
	}
}
void insertion(int ar[],int n)
{
	int i,j,k,temp,temp2;
	for(i=1;i<n;i++)
	{
		temp=ar[i];
		j=i;
		while(temp<=ar[j-1])
		{
			ar[j]=ar[j-1];
			j--;
		}
		ar[j]=temp;
	}
}

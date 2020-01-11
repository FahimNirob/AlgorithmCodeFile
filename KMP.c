#include<stdio.h>
#include<string.h>

int main()
{

	int index,flag = 0,textln,s=0,t=0;
	char pat[200];
	int sufP[200];
	char text[500];
	
	printf("Please Enter the pattern:" );
	scanf("%s",&pat);

	index= strlen(pat);
	//creating the array of substring
	int i=1,j=0;
	sufP[0]=0;
	for(int i=0;i<index;i++)
	{
		printf("%c ",pat[i] );
	}
	while(i!=index)
	{
		if(pat[j]==pat[i])
		{
			sufP[i]=j+1;
			j++;
			i++;

		}
		else
		{
			if(j!=0)
			{
				j=sufP[j-1];
			}
			else
			{
				sufP[i]=0;
				i++;

			}

		}
	}
	printf("\n");
	// for(int i=0;i<index;i++)
	// {
	// 	printf("%d\n",sufP[i]);
	// }

	printf("Please Enter your text:\n");
	scanf("%s",&text);
	textln=strlen(text);

	while(t<textln)
	{
		if(s==0 & pat[s]!=text[t])
		{
			t++;
		}
		else if(s==index-1)
		{
			printf("The pattern is found.\n");
			break;
		}
		else if(pat[s]==text[t])
		{
			s++;
			t++;
		}
		else if(pat[s]!=text[t])
		{
			if(s!=0)
			{
				s=sufP[s-1];
			}
			else
			{
				s=0;
			}
		}
	}

}
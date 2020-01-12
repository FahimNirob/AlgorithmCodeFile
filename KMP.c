#include<stdio.h>
#include<string.h>
void sufpTable(char pat[]);

int ind,flag=0,textln,s=0,t=0;
char pat[200];
int sufP[200];
char text[500];

int main()
{
	int count =0;
	
	printf("Please Enter the pattern:" );
	scanf("%s",&pat);
	int patlen = strlen(pat);
	
	//creating the array of substring
	sufpTable(pat);

	printf("Please Enter your text:\n");
	scanf("%s",&text);
	textln=strlen(text);

	while(t<textln)
	{
		if(s<patlen-1)
		{
			if(text[t]==pat[s])
			{
				t++;
				s++;
			}
			else if(s == 0 && text[t]!=pat[s])
			{
				t++;
			}
			else if(s != 0 && text[t]!=pat[s])
			{
				s = sufP[s-1];
			}
		}
		else if( s == patlen-1)
		{
			if(pat[s]==text[t])
			{
				count++;
				s = sufP[s];
				t++;
			}
			else
			{
				s = sufP[s-1];
			}
		}
	}

	printf("Pattern found %d time(s)\n",count);
}

void sufpTable(char pat[])
{	
	ind = strlen(pat);
	int i=1,j=0;
	sufP[0]=0;
	for(int i=0;i<ind;i++)
	{
		printf("%c ",pat[i] );
	}
	while(i!=ind)
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
	return;
}
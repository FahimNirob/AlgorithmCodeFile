#include <bits/stdc++.h>
using namespace std;

typedef long long int LongNum;//Defined a custum type
LongNum FirstHalf[1000000],SecondHalf[1000000];

void subSetGenerate(LongNum set[],LongNum subSet[], int end,int start)
{
	for(int i=0;i<(1<<end);i++)
	{
		LongNum temp = 0;
		for(int j=0;j<end;j++)
		{
			if(i & (1<<j))
			{
				temp+= set[j+start];
			}
			subSet[i] = temp;
		}
	}
}

LongNum mergeAndSolve(LongNum set[],int size,LongNum value)
{
	subSetGenerate(set,FirstHalf,size/2,0);
	subSetGenerate(set,SecondHalf,size-size/3,size/2);

	int FirstHalf_size = 1<<(size/2);
	int SecondHalf_size = 1<<(size-size/2);

	sort(SecondHalf,SecondHalf+SecondHalf_size);

	LongNum max = 0;

	for(int i = 0;i<FirstHalf_size;i++)
	{
		if(FirstHalf[i]<=value)
		{
			int pointer = lower_bound(SecondHalf,SecondHalf+SecondHalf_size,(value-FirstHalf[i]))-SecondHalf;
			if( pointer == SecondHalf_size || SecondHalf[pointer]!=(value-FirstHalf[i]))
			{
				pointer--;
			}
			if((SecondHalf[pointer]+FirstHalf[i])>max)
			{
				max = SecondHalf[pointer]+FirstHalf[i];
			}
		}
	}
	return max;
}

int main()
{
	LongNum set[]={2,4,3,6,7,8};
	int n = sizeof(set)/sizeof(set[0]);
	LongNum value = 29;

	LongNum sum = mergeAndSolve(set,n,value);
	printf("Largest value smaller than (or equal) %lld is %lld.\n",value,sum);
}

//without update operation
#include <iostream>
#include<math.h>
using namespace std;
int min(int a, int b);
void printTree(int n);
void constructTree(int input[],int segmentT[],int low,int high, int pos);
int querry(int segmentT[],int qLow,int qHigh, int low, int high, int pos);
int input[]= {-1,0,3,6},segmentT[10000],infinity = 999999;

int main()
{
	int n,lenSeg,a;
	float b;
	a = sqrt(sizeof(input)/sizeof(input[0]));
	b = sqrt(sizeof(input)/sizeof(input[0]));

	if(b-a == 0)
	{
		lenSeg = pow(2,a)*2 -1;
	}
	else
	{
		lenSeg = pow(2,a+1)*2 -1;
	}

	for(int i = 0; i < lenSeg;i++)
	{
		segmentT[i]= infinity;
	}

	constructTree(input,segmentT,0,3,0);
	printTree(lenSeg);
	cout << endl;
	cout << "minimum of 1-3: " << querry(segmentT,1,3,0,3,0)<< endl;
}
void constructTree(int input[],int segmentT[],int low,int high, int pos)
{
	if(low == high)
	{
		segmentT[pos] = input[low];
		return;
	}
	int mid = (low + high) / 2 ;
	constructTree(input,segmentT,low,mid, 2*pos+1);
	constructTree(input, segmentT, mid+1, high, 2*pos+2);
	segmentT[pos] = min(segmentT[2*pos+1], segmentT[2*pos+2]);
}
int querry(int segmentT[],int qLow,int qHigh, int low, int high, int pos)
{
	if(qLow <= low && qHigh >= high)
	{
		return segmentT[pos];
	}
	if(qLow > high || qHigh < low)
	{
		return infinity;
	}
	int mid = (low+high)/2;

	int temp = min(querry(segmentT,qLow,qHigh,low,mid,2*pos+1),querry(segmentT,qLow,qHigh,mid+1,high,2*pos+2));
	return temp;
}
void printTree(int n)
{
	for(int i = 0;i<n;i++)
	{
		cout << segmentT[i] << " ";
	}
	cout<<endl;
}
int min(int a, int b)
{
	if(a>b)
		return b;
	else
		return a;
}


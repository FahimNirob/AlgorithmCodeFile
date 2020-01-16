#include <iostream>
using namespace std;
void createTree(int Tree[],int n);
void printTree(int Tree[],int n);
void updateTree(int Tree[], int n, int value, int index);
int Sum(int Tree[], int index);

int array[1000];
int Tree[1000];

int main()
{
	int n;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	

	printf("Enter the element of the array:\n");
	Tree[0]=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
		Tree[i+1]=0;//initializing the tree assigning 0 to every index;
	}

	createTree(array,n);
	cout << "Sum of 0-5: "
		<< Sum(Tree, 5);

}
void createTree(int array[],int n)
{
	for(int i = 0;i<n;i++)
	{
		updateTree(Tree,n,array[i],i);
	}
	printTree(Tree,n);
}
void printTree(int Tree[],int n)
{
	for(int i=1;i<=n;i++)
	{
		cout << Tree[i]<<" ";
	}
	cout << "\n" << endl;
}
void updateTree(int Tree[], int n, int value, int index)
{
	index = index + 1;
	while (index <= n)
	{
	Tree[index] += value;
	index += index & (-index);
	}
}
int Sum(int Tree[], int index)
{
	int sum = 0;
	index = index + 1;

	while (index>0)
	{
		sum += Tree[index];
		index -= index & (-index);
	}
	return sum;
}
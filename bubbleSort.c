#include <stdio.h>
void bubbleSort(int array[], int size);
void printArray(int array[], int size);

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
	bubbleSort(ar,n);
    printArray(ar, n);
}
void bubbleSort(int array[], int size)
{
  for (int step = 0; step < size - 1; ++step)
  {
    for (int i = 0; i < size - step - 1; ++i)
    {
      if (array[i] > array[i + 1])
      {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}
void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

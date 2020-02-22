#include <iostream>
using namespace std;

int input[100],segmentT[1000];
int main()
{
	int n;
	cout << "Enter the number of elements in array:";
	cin >> n;
	cout << "Enter the array"<< endl; 
	for(int i = 0; i<n;i++)
	{
		cin >> input[i];
	}
	for(int i = 0;i<n;i++)
	{
		cout << input[i] << " ";
	}
}
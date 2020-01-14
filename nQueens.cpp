#include <iostream>
using namespace std;
void printTheGrid(int x);
bool validaionCheck(int column, int row, int n) ;
bool solve (int n, int row);

int matrix[10][10];

int main()
{
        int queen;
        cout<<"Enter the number of queen"<<endl;
        cin >> queen;

        for (int i = 0;i < queen;i++) 
        {
            for (int j = 0;j < queen;j++) 
            {
                matrix[i][j] = 0;
            }
        }
        
        bool solution = solve(queen, 0);
        if(solution == false) 
        {
            cout << "no solutions" << endl;
        } 
        else 
        {
            cout << endl;
        }
  return 0;
}

bool solve (int n, int row) 
{
    if (n == row) 
    {
        printTheGrid(n);
        return true;
    }

    bool res = false;
    for (int i = 0;i <=n-1;i++) 
    {
        if (validaionCheck(i, row, n)) 
        {
            matrix[row][i] = 1;
            res = solve(n, row+1) || res;
            matrix[row][i] = 0;
        }
    }
    return res;
}

bool validaionCheck(int column, int row, int n) 
{
	//checking the column.
    for (int i = 0; i < row; i++) 
    {
        if (matrix[i][column]) 
        {
            return false;
        }
    }
    //checking the diagonas.(have to check the upper diagonals for validation).
    for (int i = row,j = column;i >= 0 && j >= 0; i--,j--) 
    {
        if (matrix[i][j]) 
        {
            return false;
        }
    }
    for (int i = row, j = column; i >= 0 && j < n; j++, i--) 
    {
        if (matrix[i][j]) 
        {
            return false;
        }
    }

    return true;
}
void printTheGrid(int x) 
{
    for (int i = 0;i <= x-1; i++) 
    {
        for (int j = 0;j <= x-1; j++) 
        {
                cout <<matrix[i][j]<< " ";
            
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}
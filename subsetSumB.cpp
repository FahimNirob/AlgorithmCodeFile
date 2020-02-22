//generating all subset using backtracking.
#include<bits/stdc++.h>
#include <vector>
using namespace std;
std::vector<int> subset;

int generateSubset(int k);
int n=4,Set[4]={2,4,6,8}, value = 8;
int main()
{
    generateSubset(0);
}
int generateSubset(int k)
{
    if(k == n)
    {
        int temp = 0;
        for(int i=0; i < subset.size(); i++)
            temp = temp + subset.at(i);
        if(temp == value)
        {
            for(int i=0; i < subset.size(); i++)
            std::cout << subset.at(i)<< ' ';
        }
        cout << endl;
    }
    else
    {
        generateSubset(k+1);
        subset.push_back(Set[k]);
        generateSubset(k+1);
        subset.pop_back();
    }
}

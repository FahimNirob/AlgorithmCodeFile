//unfinished

#include<bits/stdc++.h>
#include <vector>
using namespace std;


int main()
{
    int n = 4,Set[4]={2,4,6,8}, value = 8,temp;
    int b = 0;
    sub:
    while(b<(1<<n))
    {

        vector<int> subset;
        temp = value;
        for(int i = 0; i<n ; i++)
        {
            if(b & (1 << i))
            {
                if((temp - Set[i])>=0 )
                {
                    cout<< Set[i]<<' ';
                    temp = temp - Set[i];
                }
                else
                {
                    b++;
                    goto sub;
                }
            }
        }
        //cout<< temp;
        cout << endl;
        b++;
    }
}

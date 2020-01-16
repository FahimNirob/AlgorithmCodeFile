//Light oj 1203 using convex hull jarvis march algorithm
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

struct Point
{
    long long int x, y;
};

long double angle(long long int a1,long long int b1,long long int a2,long long int b2,long long int a3,long long int b3)
{
	long double A_dot_B,modA,modB,temp1,temp2,ang;
	A_dot_B = ((a1-a2)*(a3-a2))+((b1-b2)*(b3-b2));
	modA = sqrt((pow((a1-a2),2)+pow((b1-b2),2)));
	modB = sqrt((pow((a3-a2),2)+pow((b3-b2),2)));

	temp1 = (A_dot_B*1.0) / (modA * modB);
	if(modA == 0 || modB == 0)
    {
        ang = 0;
    }
    else
    {
        temp2 = acos(temp1);

        ang = ((180/3.141592653589793 )*temp2);
    }

	return ang;
}

int orientation(Point a, Point b, Point c)
{
    long long int slope = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);

    if (slope == 0)
    {
    	return 0;  // colinear
    }
    else if(slope > 0)
    {


    	return 1;//clockwise
    }
    else
    {
    	return 2;//Counterclockwise
    }
}

long double convexHull(Point points[], long long int n)
{
	long double ag;
	long long int flag = -1;
	if(n<3)
	{
		return 0;
	}
	else{
		vector<Point> cv;

		//find left most;
		long long int left = 0;
		for(int i = 0;i< n;i++)
		{
			if (points[i].x < points[left].x)
			{
				left = i;
			}
		}

		long long int p = left,q;//starting from left.
		do
		{
			cv.push_back(points[p]);

			q = (p+1)%n; //taking a random point at first

            //Finding orientation
			for (int i = 0; i < n; i++)
        	{
                if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
            }
            p = q;
        }while (p != left);

        for (int i = 0; i < cv.size(); i++)
        cout << "(" << cv[i].x << ", "
              << cv[i].y << ")\n";


        long double temp = 360.00;
        for (int i = 0; i < cv.size(); i++)
        {
        	if(i == (cv.size()-2) )
        	{
        		ag = angle(cv[i].x,cv[i].y,cv[i+1].x,cv[i+1].y,cv[0].x,cv[0].y);
        	}
        	else if(i == (cv.size()-1))
        	{
        		ag = angle(cv[i].x,cv[i].y,cv[0].x,cv[0].y,cv[1].x,cv[1].y);
        	}
        	else
        	{
        		ag = angle(cv[i].x,cv[i].y,cv[i+1].x,cv[i+1].y,cv[i+2].x,cv[i+2].y);
        	}
        	if(ag <= temp)
        	{
        		temp = ag;
        		flag = i;
        	}
        }
        return temp;
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for(int s = 0;s<T;s++)
    {
        int np;
        cin >> np;

        if(np<3)
        {
            cout<<"Case "<< s+1<<": "<< "0"<<endl;
        }
        else
        {
            Point points[np];

             for(int i = 0;i<np;i++)
            {
                 cin>>points[i].x >>points[i].y;
             }

            long long int n = sizeof(points)/sizeof(points[0]);

            cout <<"Case "<<s+1<<": "<< fixed << setprecision(6) << convexHull(points, n) <<endl;
        }

    }
    return 0;
}

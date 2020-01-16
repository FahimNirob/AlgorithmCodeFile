#include<bits/stdc++.h>
#include <vector>
using namespace std;
void DFS(int start);
void process(int node);

std::vector<int> graph[1000];
bool visit[1000];
int node;
int main()
{
	int ver,x,y,starting;//x and y are adjecent nodes connected by a vertecis.
		cin>>node;//entering number of node;
		if(node == 0)
		{
			cout<<"There is no graph";
			return 0;
		}
		cin >> ver;//entering number of vertecis
		for(int i =0 ;i <ver;i++)
		{
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		cin >> starting;//entering the starting node for dfs;
		DFS(starting);

}
void DFS(int s)
{
	
	//cout << visit[s];
	if(visit[s])
	{
		return;
	}
	visit[s] = true;
	process(s);
	for(auto x: graph[s])
	{
		DFS(x);
	}
}
void process(int node)
{
	cout<< node << endl;
}

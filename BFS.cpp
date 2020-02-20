#include<bits/stdc++.h>
#include <vector>
using namespace std;
void BFS(int start);
void process(int node);

std::vector<int> graph[1000];
bool visit[1000];
queue<int> q;
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
		BFS(starting);

}
void BFS(int s)
{
	visit[s]=true;
	q.push(s);
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		process(node);
		for(auto u:graph[node])
		{
			if(visit[u])
			{
				continue;
			}
			visit[u]=true;
			q.push(u);
		}
	}
}
void process(int node)
{
	cout<< node << endl;
}

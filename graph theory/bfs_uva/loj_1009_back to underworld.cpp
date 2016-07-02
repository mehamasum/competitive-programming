#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define N 20005
vector <int> edge[N];
int visited[N]={0};
int level[N]={0};
int color[N]={0};
int n=0;
int a,b;
int u,v,size;
int one=0,two=0;
int T;
int i,j,k;
queue <int> q;
int maxi=0;

int bfs( int source)
{
	one=0; two=0;
	q.push(source);
	visited[source]=1;
	color[source]=1;
	one++;

	while(!q.empty())
	{
		u=q.front();
		size=edge[u].size();
		q.pop();
		for(int i=0;i<size;i++)
		{
			v=edge[u][i];
			if(!visited[v])
			{
				q.push(v);
				visited[v]=1;
				if(color[u]==1) { color[v]=2; two++;}
				else {color[v]=1; one++;}
			}
		}
	}
	//printf("Case %d: ",k+1);
	if(one>two) return one;
	else return two;
}

int main()
{
	freopen("input.txt","r",stdin);
	scanf("%d",&T);


	for(int k=1;k<=T;k++)
	{
		memset(visited,0,sizeof visited);
		memset(level,0,sizeof level);
		memset(color,0,sizeof color);
		one=0; two=0,maxi=0;
		for(j=0;j<N;j++)
			edge[j].clear();
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%d %d",&a,&b);
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		for(j=0;j<N;j++)
		{
			if(!edge[j].empty() && !visited[j])
				maxi+=bfs(j);
		}
		printf("Case %d: ",k);
		printf("%d\n",maxi);

	}
	return 0;
}



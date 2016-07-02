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

#define NODES 1005

int T,K,N,M;
int i,j,k,temp;
int a,b;
queue <int> q;
vector <int> sources;
vector <int> edge[NODES];
int visited[NODES]={0};
int visit_count[NODES]={0};
int u,v,size;
int sum;
		
void bfs( int source)
{
	q.push(source);
	visited[source]=1;
	visit_count[source]++;

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
				visit_count[v]++;
			}
		}
	}
	return;
}


int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%d",&T);

	for(i=1;i<=T;i++)
	{
		sum=0;
		memset(visited,0,sizeof visited);
		memset(visit_count,0,sizeof visit_count);
		sources.clear();
		

		scanf("%d %d %d",&K,&N,&M);
		for(j=0;j<K;j++)
		{
			scanf("%d",&temp);
			sources.push_back(temp);
		}
		for(j=0;j<M;j++)
		{
			scanf("%d %d",&a,&b);
			edge[a].push_back(b);
		}
		for(j=0;j<sources.size();j++)
		{
			k=sources[j];
			if(!edge[k].empty())
			{
				memset(visited,0,sizeof visited);
				bfs(k);
			}
		}
		for(j=1;j<=N;j++)
			if(visit_count[j]==K) sum++;
		for(j=1;j<=N;j++)
			edge[j].clear();
		printf("Case %d: ",i);
		printf("%d\n",sum);
	}
	return 0;
}

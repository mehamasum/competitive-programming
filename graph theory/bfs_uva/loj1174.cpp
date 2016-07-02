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

#define pii pair<int,int>
#define uu first
#define vv second

#define inf 1<<29
#define EPS 1e-7
const double PI = acos(-1.0);
const double EulerConstant = std::exp(1.0);

#define FRE freopen("C:\\Users\\User\\Desktop\\input.txt","r",stdin)
#define MEM(a,b) memset(a, b, sizeof(a))
#define MAX 105
using namespace std;

int level[MAX];
int level2[MAX];

vector<int>G[MAX];

void bfs(int src)
{
	queue<int>Q;
	Q.push(src);
	int visited[100]={0};
	int parent[100];
	visited[src]=1; 
    level[src]=0;
	while(!Q.empty())
	{
		int u=Q.front();
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			if(!visited[v])
			{
				level[v]=level[u]+1; 
				parent[v]=u;
				visited[v]=1;
				Q.push(v);
			}
		}
		Q.pop();
	}
}

void bfs2(int src)
{
	queue<int>Q;
	Q.push(src);
	int visited[100]={0};
	int parent[100];
	visited[src]=1; 
    level2[src]=0;
	while(!Q.empty())
	{
		int u=Q.front();
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			if(!visited[v])
			{
				level2[v]=level2[u]+1; 
				parent[v]=u;
				visited[v]=1;
				Q.push(v);
			}
		}
		Q.pop();
	}
}

int main()
{
	FRE;
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++)
	{
		for(int i=0;i<MAX;i++)
			G[i].clear();
		MEM(level,0);
		MEM(level2,0);

		int n, e;
		cin>>n>>e;
		for(int i=0;i<e;i++)
		{
			int a,b;
			cin>>a>>b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		
		int src, dst;
		cin>>src>>dst;
		bfs(src);
		bfs2(dst);

		int maxi=0;
		for(int i=0; i<MAX; i++)
			maxi=max(maxi,level[i]+level2[i]);
		printf("Case %d: %d\n",t,maxi);
	}
	return 0;
}
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

const double PI = acos(-1.0);
#define left(i) ((i+1)%3)
#define right(i) ((i+2)%3)
#define inf 1<<29
vector <int> edge[105];
int id[105],vis[105];
int go[105];
int exsource;
int n,i,j,a;
/*void topsort(int source)
{
	int v;
	for(int i=0;i<edge[source].size();i++)
	{
		v=edge[source][i];
		id[v]--;
	}
	exsource=source;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i] && id[i]==0)
		{
			source=i;
			vis[i]=1;
			break;
		}
	}
	if(exsource==source) return;
	printf(" %d",source);
	topsort(source);
}*/

int main()
{
	//freopen("input.txt","r",stdin);
	while(scanf("%d",&n)==1)
	{
		exsource=0;
		for(i=1;i<=n;i++)
			edge[i].clear();
		memset(id,0,sizeof id);
		memset(vis,0,sizeof vis);
		memset(go,0,sizeof go);
		for(i=1;i<=n;i++)
		{
			for(;;)
			{
				scanf("%d",&a);
				if(a==0) break;
				edge[i].push_back(a);
				id[a]++;
			}
		}
		int source,x=0;
		queue <int> q;
		for(j=1;j<=n;j++)
		{
			for(i=1;i<=n;i++)
			{
				if(!vis[i] && id[i]==0)
				{
					q.push(i);
				}
			}
			while(!q.empty())
			{
				source=q.front();
				q.pop();
				vis[source]=1;
				go[x]=source; x++;

				int v;
				for (i=0;i<edge[source].size();i++)
				{
					v=edge[source][i];
					id[v]--;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			if(i==0) printf("%d",go[i]);
			else printf(" %d",go[i]);
		}
		printf("\n");

	}
	return 0;
}
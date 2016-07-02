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

int main()
{
	//freopen("input.txt","r",stdin);
	int nodes;
	while(scanf("%d",&nodes)==1)
	{
		int friends,temp,source;
		int i,j,t;
		vector <int> edge[10000];
		int T;
		queue <int> q;
		int visited[10000]={0};
		int level[10000]={0};
		int leveldata[10000]={0};

		int u,size,v;
		int l=0,max=0;
		for(i=0;i<nodes;i++)
		{
			scanf("%d",&friends);
			for(j=0;j<friends;j++)
			{
				scanf("%d",&temp);
				edge[i].push_back(temp);
			}
		}
		scanf("%d",&T);
		for(t=0;t<T;t++)
		{
			l=0,max=0;
			memset(visited,0,sizeof visited);
			memset(level,0,sizeof level);
			memset(leveldata,0,sizeof leveldata);
			scanf("%d",&source);
			q.push(source);
			visited[source]=1;
			level[source]=0;

			while(!q.empty())
			{
				u=q.front();
				size=edge[u].size();
				q.pop();
				for(i=0;i<size;i++)
				{
					v=edge[u][i];
					if(!visited[v])
					{
						q.push(v);
						visited[v]=1;
						level[v]=level[u]+1;
						leveldata[level[v]]++;
						if(max<leveldata[level[v]]) { l=level[v]; max=leveldata[level[v]];}
					}
				}
			}
			if(max==0) printf("0\n");
			else printf("%d %d\n",max,l);
		}
	}
	return 0;
}



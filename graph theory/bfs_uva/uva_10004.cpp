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
	int n, e;
	int i,j;
	int a,b;
	
	int visited[1000]={0};
	int color[1000]={0};
	int col=1;
	int red=0;
	while(scanf("%d",&n)==1)
	{
		col=1;
		red=0;
		memset(visited,0,sizeof visited);
		memset(color,0,sizeof color);
		
		vector <int> v[1000];
		queue <int> q;

		if(n==0) break;
		scanf("%d",&e);
		for(i=0;i<e;i++)
		{
			scanf("%d %d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int source=0;
		q.push(source);
		visited[source]=1;
		color[source]=col;
		while(!q.empty())
		{
			int u=q.front();
			int size=v[u].size();
			q.pop();
			col=-color[u];
			for(i=0;i<size;i++)
			{
				int vv=v[u][i];
				if(visited[vv] && color[vv]==color[u]) { red=1; break;}
				if(!visited[vv])
				{
					visited[vv]=1;
					color[vv]=col;
					q.push(vv);
				}
			}
		}
		if(red==1) printf("NOT BICOLORABLE.\n");
		else printf("BICOLORABLE.\n");
	}
	return 0;
}

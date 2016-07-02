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

#define N 100005

vector <int> edge[N];

int main()
{
	int n,i,j,k,links,temp;
	while(scanf("%d",&n)==1)
	{
		for(i=1;i<=n;i++)
		{
			cin>>k>>links;
			for(j=1;j<=links;j++)
			{
				cin>>temp;
				edge[i].push_back(temp);
			}
		}
		int source=1,u,size,v;
		queue <int> q;
		vector <int> parent[N];
		int visited[N]={0};

		q.push(source);
		parent[source].push_back(0);
		visited[source]=1;
		while(!q.empty())
		{
			u=q.front();
			size=edge[u].size();
			q.pop();
			for(i=0;i<size;i++)
			{
				v=edge[u][i];
				if(!visited[v]) q.push(v);
				parent[v].push_back(u);
			}
		}

		for(i=1;i<=n;i++)
		{
			if(i==1) printf("sober ");
			else 
			{
				parent[i][j];
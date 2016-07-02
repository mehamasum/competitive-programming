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
#define MEMSET(a,b) memset(a,b,sizeof(a));

#define CINd(a) scanf("%d",&a);
#define CINdd(a,b) scanf("%d %d", &a, &b);
#define CINddd(a,b,c) scanf("%d %d %d", &a, &b, &c);

#define CINf(a) scanf("%lf",&a);
#define CINff(a,b) scanf("%lf %lf", &a, &b);
#define CINfff(a,b,c) scanf("%lf %lf %lf", &a, &b, &c);
#define COUT(a) cout<<a<<endl;
using namespace std;

#define MAX 10005



int v,e;
int color[MAX],parent[MAX];
int discovery[MAX],final[MAX];
int timer=0;

map<string,int> myMap;
vector<int>G[MAX];

#define WHITE 0
#define GRAY 1
#define BLACK 2

int cycleFound=0;

void DFS_visit(int i)
{
	color[i]=GRAY;
	timer++;
	discovery[i]=timer;
	for(int j=0;j<G[i].size();j++)
	{
		int u=G[i][j];
		if(color[u]==GRAY)
		{
			cycleFound=1;
			break;
		}
		if(color[u]==WHITE)
		{
			parent[u]=i;
			DFS_visit(u);
		}
	}
	color[i]=BLACK;
	timer++;
	final[i]=timer;
}
void DFS()
{
	cycleFound=0;
	for(int i=1;i<=v;i++)
	{
		if(G[i].size()==0) continue;

		if(color[i]==WHITE)
		{
			DFS_visit(i);
			if(cycleFound==1) break;
		}
	}
}

int main()
{
	FRE;
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++)
	{
		v=e=0;
		MEMSET(color,0);
		MEMSET(parent,0);
		MEMSET(discovery,0);
		MEMSET(final,0);
		for(int i=0; i<MAX; i++ )
			G[i].clear();
		myMap.clear();



		string a,b;

		cin>>e;
		for(int i=0;i<e;i++)
		{
			cin>>a>>b;
			if( !myMap[a]) myMap[a] = ++v;
            if( !myMap[b]) myMap[b] = ++v;
			G[myMap[a]].push_back(myMap[b]);
		}

		DFS();
		if(cycleFound==1) printf("Case %d: No\n",t);
		else printf("Case %d: Yes\n",t);
	}
	return 0;
}

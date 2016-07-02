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

#define LL long long
#define ULL unsigned long long

#define INF (1<<29)
#define EPS 1e-7
const double PI = acos(-1.0);
const double EulerConstant = std::exp(1.0);

#define READ freopen("C:\\Users\\User\\Desktop\\input.txt","r",stdin)
#define MEM(a,b) memset(a,b,sizeof(a))

#define sf(a) scanf("%d",&a)
#define sff(a,b) scanf("%d%d", &a, &b)
#define sfff(a,b,c) scanf("%d%d%d", &a, &b, &c)

#define sd(a) scanf("%lf",&a)
#define sdd(a,b) scanf("%lf%lf", &a, &b)
#define sddd(a,b,c) scanf("%lf%lf%lf", &a, &b, &c)

#define print(a) printf("%d\n",a)
#define pf printf

using namespace std;

#define space <<" "<<
#define endl <<endl
#define put cout<<
#define NL "\n"

#define MAX 10005
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define NIL -1
#define inf 1e17

int v,e;
int color[MAX],parent[MAX];
int discovery[MAX],final[MAX];
int low[MAX], ap[MAX];
int timer=0;
int child_of_root=0;
vector<int>G[MAX];
vector< pair<int ,int> > bridge;
int cnt=0;

bool compare(pair<int ,int> a, pair<int ,int> b)
{
	if(a.first==b.first)
		return a.second<b.second;
	else
		return a.first<b.first;
}
void DFS_visit(int i)
{
	color[i]=GRAY;
	timer++;
	discovery[i]=timer;
	low[i]= discovery[i];

	for(int j=0;j<G[i].size();j++)
	{
		int w=G[i][j];

		if(color[w] == WHITE)
		{
			parent[w]=i;
			DFS_visit(w);
			low[i] = min(low[i], low[w]);

			if (low[w] == discovery[w])
			{
				if(i<w)
					bridge.push_back(make_pair(i,w));
				else
					bridge.push_back(make_pair(w,i));

				cnt++;
			}

		}

		else if(parent[i] != w)
			low[i] = min(low[i], discovery[w]);
	}

	color[i]=BLACK;
	timer++;
	final[i]=timer;
}


void DFS()
{
	cnt=0;
	//MEM(bridge,0);
	bridge.clear();
	for(int i=0;i<v;i++)
	{
		color[i] = WHITE;
		parent[i]=NIL;
		low[i]=inf;
		final[i]=inf; 
		discovery[i]=inf;
	}

	for(int i=0;i<v;i++)
		if(color[i]==WHITE)
			DFS_visit(i);
}


int main()
{
	freopen("C:\\Users\\User\\Desktop\\input.txt","r",stdin);
	int T;
	sf(T);

	for(int t=1; t<=T; t++)
	{
		sf(v);
		if(v==0)
		{
			pf("Case %d:\n0 critical links\n",t);
			//pf(NL);
			continue;
		}
		for(int i=0; i<v; i++)
		{
			int a, e;
			sf(a);

			char A[10],b[10];
			scanf("%s",A);
			sscanf(A,"(%d)",&e);
			
			for(int j=0;j<e;j++)
			{
				int b;
				sf(b);
				G[a].push_back(b);
				//G[b].push_back(a);
			}
		}

		DFS();

		pf("Case %d:\n%d critical links\n",t,cnt);

		sort(bridge.begin(),bridge.end(),compare);
		for(int i=0; i<cnt; i++)
			pf("%d - %d\n",bridge[i].first,bridge[i].second);

		for(int i=0; i<v; i++)
			G[i].clear();
	}
	return 0;
}



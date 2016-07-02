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

#define MAX 1005
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define NIL -1
#define inf 1e17

int v,e;
int color[MAX],parent[MAX];
int discovery[MAX],final[MAX];
int low[MAX], ap[MAX], bridge[MAX][MAX];
int timer=0;
int child_of_root=0;
vector<int>G[MAX];
int cnt=0;

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
					bridge[i][w]=1;
				else
					bridge[w][i]=1;

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
	MEM(bridge,0);
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
	
	while(sf(v)==1)
	{
		for(int i=0; i<MAX; i++)
			G[i].clear();

		if(v==0)
		{
			pf("0 critical links\n");
			pf(NL);
			continue;
		}

		for(int i=0; i<v; i++)
		{
			int a, e;
			char dum1, dum2;
			cin>>a>>dum1>>e>>dum2;

			for(int j=0;j<e;j++)
			{
				int b;
				cin>>b;

				//put a <<" "<< b endl;
				//put b <<" "<< a endl;

				G[a].push_back(b);
				//G[b].push_back(a);
			}
		}

		DFS();

		pf("%d critical links\n",cnt);


		for(int i=0; i<v; i++)
			for(int j=0;j<v;j++)
				if(bridge[i][j])
					pf("%d - %d\n",i,j);
		pf(NL);
	}
	return 0;
}



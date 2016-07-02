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
#define MEM(a,b) memset(a,b,sizeof(a));

#define sf(a) scanf("%d",&a)
#define sff(a,b) scanf("%d%d", &a, &b)
#define sfff(a,b,c) scanf("%d%d%d", &a, &b, &c)

#define sd(a) scanf("%lf",&a)
#define sdd(a,b) scanf("%lf%lf", &a, &b)
#define sddd(a,b,c) scanf("%lf%lf%lf", &a, &b, &c)

#define print(a) printf("%d\n",a)

using namespace std;

#define space <<" "<<
#define endl <<endl
#define NL "\n"
#define pf printf
#define put cout<<

#define MAXN 105
#define MAXE 1005

map <string,int> myMap;

int v,e;
int d[MAXN], par[MAXN];
int cost[MAXN][MAXN];
		

void bellman(int s, int y)
{
	for(int i=1;i<=v;i++) 
	{
		d[i]=INF;
		par[i]=0;
	}
	d[s]=0; 
	par[s]=-1;

	for(int m=1;m<=y;m++)
	{
		for(int i=v;i>=1;i--)
		{
			for(int j=v;j>=1;j--)
			{
				if(cost[i][j]>=0)
				{
					if(d[i]+cost[i][j]<=d[j])
					{
						d[j]=d[i]+cost[i][j];
						par[j]=i;

					}
				}
			}
		}
	}
}

void path(int i)
{
	if(i==-1) return;
	path(par[i]);
	put i endl;

}
int main()
{
	READ;
	int T;
	while(sf(T)==1)
	{
		for(int t=1;t<=T;t++)
		{
			MEM(cost,-1);
			myMap.clear();

			sf(v);
			for(int i=1;i<=v;i++)
			{
				string a;
				cin>>a;
				myMap[a]=i;
			}

			sf(e);
			for(int i=e;i>=1;i--)
			{
				string a,b;
				int c;
				cin>>a>>b>>c;

				int p=myMap[a];
				int q=myMap[b];

				if(cost[p][q]>=0)
				{
					if(c<cost[p][q])
						cost[p][q]=c;
				}

				else
					cost[p][q]=c;
			}

			int q;
			sf(q);
			if(t!=1) 
				pf (NL);
			put "Scenario #" << t endl;
			for(int i=1;i<=q;i++)
			{
				int x;
				sf(x);
				
				if(x==0) 
				{
					if(cost[1][v]>=0)
						put "Total cost of flight(s) is $" <<cost[1][v] endl;
					else
						put "No satisfactory flights" endl;
				}
				else
				{
					bellman(1,x+1);
					//path(v);
					if(d[v]==INF)
						put "No satisfactory flights" endl;
					else
						put "Total cost of flight(s) is $" << d[v] endl;
				}

			}
		}

	}
}
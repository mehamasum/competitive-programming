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
#define MAXN 1005
#define MAXE 2005
#define space <<" "<<
#define show <<endl

int v,e;
int d[MAXN];
int edge_u[MAXE],edge_v[MAXE],edge_cost[MAXE];

bool neg_cycle;

void bellman()
{
	neg_cycle=false;
	for(int i=0;i<v;i++)
	{
		bool updated=false;
		for(int j=0;j<e;j++)
		{
			int a=edge_u[j],b=edge_v[j];
			if(d[a]+edge_cost[j]<d[b])
			{
				updated=true;
				if(i==v-1) 
					neg_cycle=true;
				d[b]=d[a]+edge_cost[j];
			}
		}
		if(updated==false)
			break;
	}
}

int main()
{
	FRE;
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++)
	{
		MEMSET(d,0);
		MEMSET(edge_u,0);
		MEMSET(edge_v,0);
		MEMSET(edge_cost,0);
		cin>>v>>e;

		for(int i=0;i<v;i++) 
			d[i]=inf;
		d[0]=0; //distance to source is 0
		
		for(int i=0;i<e;i++)
			cin>>edge_u[i]>>edge_v[i]>>edge_cost[i];
		string ans;
		bellman();

		if(neg_cycle) ans="possible";
		else ans="not possible";

		cout<<ans<<endl;
	}
	return 0;
}
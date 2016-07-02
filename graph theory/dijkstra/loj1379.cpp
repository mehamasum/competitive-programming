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
#define MEM(a,b) memset(a,b,sizeof(a));

#define CINd(a) scanf("%d",&a);
#define CINdd(a,b) scanf("%d %d", &a, &b);
#define CINddd(a,b,c) scanf("%d %d %d", &a, &b, &c);

#define CINf(a) scanf("%lf",&a);
#define CINff(a,b) scanf("%lf %lf", &a, &b);
#define CINfff(a,b,c) scanf("%lf %lf %lf", &a, &b, &c);
#define COUT(a) cout<<a<<endl;
using namespace std;

#define MAX 10005

vector <int> g[MAX], g1[MAX],cost[MAX], cost1[MAX];

int d[MAX],par[MAX];
int d1[MAX],par1[MAX];

struct node
{
    int u,d,child;
    node(int a,int b,int c){u=a; d=b; child=c;}
    bool operator < ( const node& p ) const { return d > p.d; }
};
void dijkstra(int src)
{
    memset(d,63,sizeof(d)); 
    memset(par,-1,sizeof(par));
    priority_queue <node> q;

	par[src]=0;
    q.push(node(src,0,0));
    d[src]=0;

    while(!q.empty())
    {
        node top=q.top(); q.pop();
        int u=top.u;
		//cout<<">"; COUT(u); cout<<" "; COUT(d[u]);
		int ch=top.child;

        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            if(d[u]+cost[u][i]<d[v])
            {
				
                d[v]=d[u]+cost[u][i];
                par[v]=u;
                q.push(node(v,d[v],i));
            }
        }
    }
}
void dijkstra1(int src)
{
    memset(d1,63,sizeof(d)); 
    memset(par1,-1,sizeof(par));
    priority_queue <node> q;

	par1[src]=0;
    q.push(node(src,0,0));
    d1[src]=0;

    while(!q.empty())
    {
        node top=q.top(); q.pop();
        int u=top.u;
		//cout<<">>"; COUT(u); cout<<" "; COUT(d1[u]);
		int ch=top.child;

        for(int i=0;i<g1[u].size();i++)
        {
            int v=g1[u][i];
            if(d1[u]+cost1[u][i]<d1[v])
            {
				
                d1[v]=d1[u]+cost1[u][i];
                par1[v]=u;
                q.push(node(v,d1[v],i));
            }
        }
    }
}
int main()
{
	FRE;
	int T;
	CINd(T);
	for(int t=1; t<=T; t++)
	{
		for(int j=0;j<MAX;j++)
		{
			g[j].clear(); 
			g1[j].clear();
			cost[j].clear();
			cost1[j].clear();
		}

		int n, e, start, end, money;
		CINdd(n,e);
		CINddd(start,end,money);

		for(int i=0;i<e;i++)
		{
			int u,v,w;
			
			cin>>u>>v>>w;
			g[u].push_back(v);
			g1[v].push_back(u);
			cost[u].push_back(w);
			cost1[v].push_back(w);

		}

		dijkstra(start);
		dijkstra1(end);

		int ans=-1;
		for(int i=1;i<MAX;i++)
			for(int j=0;j<g[i].size();j++)
			{
				//edge between i->j   g[i][j]
				//cost                cost[i][j]
				
				int total=d[i]+d1[g[i][j]]+cost[i][j];
				//cout<<"u->v "; cout<<i<<" "<<g[i][j]<<" "; COUT(cost[i][j]);
				//COUT(d[i]);
				//COUT(d1[g[i][j]]);
				//COUT(total);
				if(total<=money)
					ans=max(ans,cost[i][j]);
			}
		printf("Case %d: %d\n",t,ans);
	}


}
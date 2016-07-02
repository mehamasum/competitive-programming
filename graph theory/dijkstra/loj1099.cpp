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
using namespace std;

#define MAX 5005

struct node
{
	int u,d,op;
	node(int a,int b,int c)
	{
		u=a;
		d=b;
		op=c;
	}
	bool operator < ( const node& o ) const 
	{ 
		if (op == o.op)
			if(d == o.d ) 
				return u > o.u;
			return d > o.d;
		return op > o.op;
	}
};

vector <int> g[MAX],cost[MAX];
int d[2][MAX], op[MAX], par[MAX], second[MAX];

int dijkstra(int n)
{
	//cout<<n<<endl;
	MEM(d,63);
	MEM(par,-2);
	MEM(second,63);

	priority_queue <struct node> q;

	d[0][1]=0;
	q.push(node(1,d[0][1],0));

	while(!q.empty())
	{

		node top=q.top(); 
		
		q.pop();
		
		int u=top.u;
		int dis=top.d;
		int op=top.op;
		
		//cout<<"pop>> "<<u<<" "<<dis<<" "<<op<<endl;
		
		if( u==n && op==1)
		{
			return dis;
		}

		for(int i=0;i<(int)g[u].size();i++)
		{
			int v=g[u][i];
			int alt=d[op][u]+cost[u][i];
			if(alt<d[0][v])
			{
				d[1][v]=d[0][v];
				d[0][v]=alt;
				par[v]=u;
				q.push(node(v,d[0][v],0));
				q.push(node(v,d[1][v],1));

				//cout<<"pushed: "<<v<<" "<<d[0][v]<<" 0"<<endl;
				//cout<<"pushed: "<<v<<" "<<d[1][v]<<" 1"<<endl;
			}
			else if(alt>d[0][v] && alt<d[1][v])
			{
				d[1][v]=alt;
				q.push(node(v,d[1][v],1));
				//cout<<"pushed:: "<<v<<" "<<d[1][v]<<" 1"<<endl;
			}
		}

	}

	return -1;
}

int main()
{
	FRE;
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++)
	{
		for(int j=0;j<MAX;j++)
		{
			g[j].clear();
			cost[j].clear();
		}

		int n,e;
		cin>>n>>e;
		for(int i=0;i<e;i++)
		{
			int u,v,w;
			
			cin>>u>>v>>w;
			g[u].push_back(v);
			g[v].push_back(u);
			cost[u].push_back(w);
			cost[v].push_back(w);

		}

		printf("Case %d: %d\n",t,dijkstra(n));
	}


}
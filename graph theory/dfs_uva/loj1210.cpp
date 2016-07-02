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

#define MAX 20005




#define WHITE 0
#define GRAY 1
#define BLACK 2

int v,e;
int color[MAX];
int timer=0;

vector<int> G[MAX], GG[MAX]; //GG reverse graph

struct node 
{
	int no;
	int fin_time;

	node()
	{
		no=0;
		fin_time=0;
	}
};

struct node n[MAX];
bool compare(struct node a, struct node b)
{
	return a.fin_time < b.fin_time;
}

void DFS_visit(int i)
{
	color[i]=GRAY;
	timer++;
	for(int j=0;j<G[i].size();j++)
	{
		int u=G[i][j];
		if(color[u]==WHITE)
			DFS_visit(u);
	}
	color[i]=BLACK;
	timer++;
	n[i].fin_time=timer;
}

int comp_no=1;
int comp[MAX];

void DFS_visit2(int i)
{
	//cout<<i<<" ";
	comp[i]=comp_no;
	color[i]=GRAY;
	timer++;
	for(int j=0;j<GG[i].size();j++)
	{
		int u=GG[i][j];
		if(color[u]==WHITE)
		{
			
			DFS_visit2(u);
		}
	}
	color[i]=BLACK;
}

void DFS()
{
	timer=0;
	for(int i=1;i<=v;i++)
	{
		if(color[i]==WHITE)
			DFS_visit(i);
	}
}

void DFS2()
{
	int cnt=0;
	timer=0;
	for(int i=v;i>=1;i--)
	{
		int j=n[i].no;
		if(color[j]==WHITE)
		{
			/*cout<<j<<": ";*/
			DFS_visit2(j);
			comp_no++;
			//cout<<endl;
		}
	}
}

int in[MAX], out[MAX];
void counter()
{
	MEMSET(in,0);
	MEMSET(out,0);
	for(int i=1;i<=v;i++)
	{
		for(int j=0;j<G[i].size();j++)
		{
			int u=G[i][j];
			if(comp[i]!=comp[u])
			{
				//cout<< i <<" "<<u<<endl;
				out[comp[i]]++;
				in[comp[u]]++;
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
		getchar();
		CINdd(v,e);

		MEMSET(color,0);
		comp_no=1;
		MEMSET(comp,0);
		
		for(int i=0; i<MAX; i++ )
		{
			G[i].clear();
			GG[i].clear();
			n[i].fin_time=n[i].no=0;
		}

		for(int i=1;i<=v;i++)
		{
			n[i].no=i;
		}

		int a,b;
		for(int i=0;i<e;i++)
		{
			CINdd(a,b);

			G[a].push_back(b);
			GG[b].push_back(a);
			
		}

		DFS();
		MEMSET(color,0);

		/*for(int i=1;i<=v;i++)
			cout<<"be:"<<n[i].no<<" "<< n[i].fin_time<<endl;*/
		sort(n,n+v+1,compare);
		
		/*for(int i=1;i<=v;i++)
			cout<<"af:"<< n[i].no<<endl;*/

		DFS2();
		counter();

		int ans=0, sum_in=0, sum_out=0;


		for(int i=1;i<comp_no;i++)
		{
			//cout<<"in: "<<in[i]<<" out: "<<out[i]<<endl;
			if(in[i]==0) sum_in++;
			if(out[i]==0) sum_out++;
		}

		ans=max(sum_in, sum_out);
		if (comp_no==2)
			ans=0;

		if(e==0) printf("Case %d: %d\n",t,v);
		else printf("Case %d: %d\n",t,ans);

	}
	return 0;
}

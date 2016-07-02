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

#define MAX 1005




#define WHITE 0
#define GRAY 1
#define BLACK 2

int v,e;
int color[MAX];
int timer=0;

map<string,int> myMap;
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

void DFS_visit2(int i)
{
	color[i]=GRAY;
	timer++;
	for(int j=0;j<GG[i].size();j++)
	{
		int u=GG[i][j];
		if(color[u]==WHITE)
			DFS_visit2(u);
	}
	color[i]=BLACK;
	timer++;
	n[i].fin_time=timer;
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

int DFS2()
{
	int cnt=0;
	timer=0;
	for(int i=v;i>=1;i--)
	{
		int j=n[i].no;
		if(color[j]==WHITE)
		{
			//cout<<j<<endl;
			DFS_visit2(j);
			cnt++;
		}
	}
	return cnt;
}


int main()
{
	FRE;
	while(scanf("%d %d",&v, &e)==2)
	{
		getchar();
		if(v==0 && e==0) break;

		MEMSET(color,0);
		
		for(int i=0; i<MAX; i++ )
		{
			G[i].clear();
			GG[i].clear();
			n[i].fin_time=n[i].no=0;
		}
		myMap.clear();



		char a[40],b[40];

		for(int i=1;i<=v;i++)
		{
			gets(a);
			myMap[a] = i;
			n[i].no=i;
		}

		
		for(int i=0;i<e;i++)
		{
			gets(a);
			gets(b);
			
			G[myMap[a]].push_back(myMap[b]);
			GG[myMap[b]].push_back(myMap[a]);
			
		}

		DFS();
		MEMSET(color,0);

		/*for(int i=1;i<=v;i++)
			cout<<"be:"<<n[i].no<<" "<< n[i].fin_time<<endl;*/
		sort(n,n+v+1,compare);
		
		/*for(int i=1;i<=v;i++)
			cout<<"af:"<< n[i].no<<endl;*/

		int ans=DFS2();
		printf("%d\n",ans);


	}
	return 0;
}

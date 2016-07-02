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

#define WHITE 0
#define GRAY 1
#define BLACK 2

int v,e;
int color[MAX];
int timer=0;

vector<int>G[MAX];
int q[MAX],counter=0;

void DFS_visit(int i)
{
	color[i]=GRAY;
	for(int j=0;j<G[i].size();j++)
	{
		int u=G[i][j];
		if(color[u]==WHITE)
		{
			//cout<<"u: "<<u<<endl;
			DFS_visit(u);
		}
	}
}
int DFS()
{
	int cnt=0;
	for(int i=1;i<=v;i++)
	{
		if(color[i]==WHITE)
		{
			//cout<<"i1: "<<i<<endl;
			q[counter++]=i;
			DFS_visit(i);
			cnt++;
			//cout<<"cnt: "<<cnt<<endl;
		}
	}
	return cnt;
}

int DFS2()
{
	int cnt=0,mini=1000000000;
	for(int p=counter-1;p>=0;p--)
	{
		//MEMSET(color,0);

		int j=q[p];
		//cout<<"j: "<<j<<endl;
		//p++;
		//DFS_visit(j);

		if(color[j]==WHITE)
		{
			//cout<<"i2: "<<i<<endl;
			DFS_visit(j);
			cnt++;
			//cout<<"cnt: "<<cnt<<endl;
		}

	}
	mini=min(mini,cnt);
	return mini;
}


int main()
{
	FRE;
	int T;
	scanf("%d", &T);

	for(int t=1; t<=T; t++)
	{
		getchar();
		CINdd(v,e);

		MEMSET(color,0);
		for(int i=0; i<MAX; i++ )
			G[i].clear();
		counter=0;


		for(int i=0;i<e;i++)
		{
			int x,y;
			CINdd(x,y);
			G[x].push_back(y);
			//G[y].push_back(x);
		}
		DFS();
		MEMSET(color,0);
		int ans=DFS2();

		printf("Case %d: %d\n",t,ans);
	}
	return 0;
}


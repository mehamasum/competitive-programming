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

#define MAX 205


struct edge
{
	int u,v,w;
	bool operator < (const edge& obj) const
	{
		return w > obj.w; 
	}
};

int par[MAX];

vector <edge> e;

int parent(int r)
{
	return (par[r]==r) ? r: parent(par[r]);
}

int mst(int n)
{
	//sort
	sort(e.begin(), e.end());

	//initialize disjoint set
	for(int i=1; i<=n; i++)
		par[i]=i;

	int count=0, sum=0;
	for(int i=0;i<e.size();i++)
	{
		int u= parent(e[i].u);
		int v= parent(e[i].v);

		if(u!=v)
		{
			//union
			par[u]=v;

			count++;
			sum+=e[i].w;
			if(count==n-1) break;

		}
	}

	return sum;

}

map <string, int> mymap;

int main()
{
	int n,m;
	while (scanf("%d %d",&n, &m)==2)
	{
		if(n==0 && m==0) break;

		for(int i=1; i<=m; i++)
		{
			edge input;

			char a[50], b[50];


			cin>> a >> b >> input.w;
			e.push_back(input);
		}

		cout<< mst(n) <<endl;

	}
	return 0;

}
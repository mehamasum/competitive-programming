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

#define MAX 105

#define WHITE 0
#define GRAY 1
#define BLACK 2

int v,e;
int color[MAX];
int timer=0;

vector<int>G[MAX];
vector<int> arr;


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
	arr.push_back(i);
}
void DFS()
{
	for(int i=1;i<=v;i++)
		if(color[i]==WHITE)
			DFS_visit(i);
}
int main()
{
	//READ;
	while(sff(v,e)==2)
	{
		if(v==0 && e==0) break;

		arr.clear();
		for(int i=0;i<v;i++)
			G[i].clear();
		MEM(color,0);

		for(int i=0; i<e;i++)
		{
			int a,b;
			sff(a,b);
			G[a].push_back(b);
		}

		DFS();
		reverse(arr.begin(),arr.end());
		for(int i=0;i<v;i++)
			pf ("%d ",arr[i]);
		pf("\n");
	}
	return 0;
}
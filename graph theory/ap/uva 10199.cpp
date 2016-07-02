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

#define sf(a) scanf("%d",&a);
#define sff(a,b) scanf("%d%d", &a, &b);
#define sfff(a,b,c) scanf("%d%d%d", &a, &b, &c);

#define sd(a) scanf("%lf",&a);
#define sdd(a,b) scanf("%lf%lf", &a, &b);
#define sddd(a,b,c) scanf("%lf%lf%lf", &a, &b, &c);

#define print(a) printf("%d\n",a);
#define NL "\n"
#define pf printf
#define put cout<<

using namespace std;

#define space <<" "<<
#define endl <<endl

using namespace std;

#define MAX 1000
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define NIL -1
#define inf 1e17

int v,e;
int color[MAX],parent[MAX];
int discovery[MAX];
int low[MAX], ap[MAX];
int timer=0, cnt=0;
vector<int>G[MAX];

void DFS_visit(int i)
{
	int child=0;
	color[i]=GRAY;
	timer++;
	discovery[i]=timer;
	low[i]= discovery[i];

	for(int j=0;j<G[i].size();j++)
	{
		int w=G[i][j];

		if(color[w] == WHITE)
		{
			child++;
			parent[w]=i;
			DFS_visit(w);

			low[i] = min(low[i], low[w]);

            if (parent[i]!=NIL && discovery[i]<=low[w])
			{
				if(!ap[i]) cnt++;
				ap[i]=1;
				put i endl;
			}	
            
            else if(parent[i]==NIL && child>1)
			{
				if(!ap[i]) cnt++;
				ap[i]=1;
				put i endl;
			}		
		}

		else if(parent[i] != w)
			low[i] = min(low[i], discovery[w]);
	}

	color[i]=BLACK;
	timer++;
}


void DFS()
{    
	cnt=0;
	for(int i=1;i<=v;i++)
	{
		color[i] = WHITE;
		parent[i]=NIL;
		low[i]=inf;
		discovery[i]=inf;
		ap[i]=0;
	}

	for(int i=1;i<=v;i++)
		if(color[i]==WHITE)
			DFS_visit(i);
}

int main()
{
	freopen("C:\\Users\\User\\Desktop\\input.txt","r",stdin);
	int t=0;
	while(cin >> v)
	{
		if(v==0) break;

		string nodeName[MAX];
		map <string,int> myMap;

		for(int i=1;i<=v;i++)
		{
			string x;
			cin >> x;
			cout << x endl;
			nodeName[i]=x;
			myMap[x]=i;
		}

		cin>>e;
		
		for(int i=0; i<e; i++)
		{
			string a, b;
			cin>>a>>b;
			cout << a <<" "<< b endl;
			G[myMap[a]].push_back(myMap[b]);
			G[myMap[b]].push_back(myMap[a]);
		}

		DFS();
		printf("City map #%d: %d camera(s) found\n",++t,cnt);
		for(int i=1;i<=v;i++)
		{
			if(ap[i])
			{
				printf("%s\n",nodeName[i]);
			}
		}
		put NL;
		
	}
	return 0;
}



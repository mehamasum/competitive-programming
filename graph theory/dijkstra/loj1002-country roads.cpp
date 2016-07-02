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
#include <ctime>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef map<int,string> MAP;
typedef pair<int,int> PII;
typedef stack<int> SI;

#define INF (1<<29)
#define EPS 1e-7
#define PI acos(-1.0)
#define EulerConstant exp(1.0)
#define char2Int(c) (c-'0')

#define READ freopen("C:\\Users\\User\\Desktop\\input.txt","r",stdin)
#define WRITE freopen("C:\\Users\\User\\Desktop\\output.txt","w",stdout)

#define FRA(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FRAE(i,L,R) for (int i = L; i <= R; i++)
#define FRD(i,L,R) for (int i = L; i > R; i--)
#define FRDE(i,L,R) for (int i = L; i >= R; i--)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) // traverse an STL data structure

#define MEM(a,b) memset(a,b,sizeof(a))
#define SET(a,n,val) FRA(i,0,n) a[i]=val
#define SET2D(a,r,c,val) FRA(i,0,r) FRA(j,0,c) a[i][j]=val

#define SIZE(x) ((int)((x).size()))
#define arrSize(arr) ( sizeof(arr) / sizeof((arr)[0]) )

#define sf(a) scanf("%d",&a)
#define sff(a,b) scanf("%d%d", &a, &b)
#define sfff(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define sd(a) scanf("%lf",&a)
#define sdd(a,b) scanf("%lf%lf", &a, &b)
#define sddd(a,b,c) scanf("%lf%lf%lf", &a, &b, &c)
#define print(a) printf("%d\n",a)
#define sp <<" "<<
#define el <<endl
#define NL "\n"
#define pf printf
#define put cout<<

#define df(a) cerr<<#a<<" = "<<(a)<<endl
#define dff(a,b) cerr<<#a<<" = "<<(a)<<" "<<#b<<" = "<<(b)<<endl
#define dfff(a,b,c) cerr<<#a<<" = "<<(a)<<" "<<#b<<" = "<<(b)<<" "<<#c<<" = "<<(c)<<endl

#define printArr(a,L,R) FRA(i,L,R) cout << a[i] << (i==(R-1)?'\n':' ')
#define printArrE(a,L,R) FRAE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printArr2D(a,R,C) FRA(i,0,R) FRA(j,0,C) cout << a[i][j] << (j==(R-1)?'\n':' ')
#define printV(a) printArr(a,0,a.size()-1)

#define ALL(c) (c).begin(), (c).end()
#define PB push_back
#define MP make_pair
#define uu first
#define vv second
#define left  (2*i)
#define right (2*i+1)

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))
//void printSet(int x){pf("S=%2d=",x); SI st; while(x) st.push(x%2),x/=2; while(!st.empty()) pf("%d",st.top()),st.pop();pf(NL);}

#define MAX 505

int n,e;
vector <int> g[MAX],cost[MAX];

struct node
{
    int u,d;
    node(int a,int b){u=a; d=b;}
    bool operator < ( const node& p ) const { return d > p.d; } //smallest first
};

int d[MAX],par[MAX];

void dijkstra(int src)
{
    FRA(i,0,n) d[i]=INF;
    FRA(i,0,n) par[i]=-1;
    priority_queue <node> q;
    
	q.push(node(src,0));
    d[src]=0;

    while(!q.empty())
    {
        node top=q.top(); q.pop();
        int u=top.u;
        //df(u);
        for(int i=0;i<(int)g[u].size();i++)
        {
            int v=g[u][i];
            if(max(d[u],cost[u][i])<d[v])
            {
                d[v]=max(d[u],cost[u][i]);
				//dff(v,d[v]);
                par[v]=u;
                q.push(node(v,d[v]));
            }
        }
    }
}

int main()
{
	READ;
	int T;
	sf(T);
	FRAE(t,1,T)
	{
		cin>>n>>e;
		for(int i=0;i<e;i++)
		{
			int u,v;
			int w;
			cin>>u>>v>>w;
			g[u].push_back(v);
			g[v].push_back(u);
			cost[u].push_back(w);
			cost[v].push_back(w);
        
		}
		int src;
		sf(src);
		dijkstra(src);

		pf("Case %d:\n",t);
		FRA(i,0,n) 
		{	
			if(d[i]==INF) pf("Impossible\n");
			else pf("%d\n",d[i]);
		}

		FRAE(i,0,n) g[i].clear(), cost[i].clear();
	}
	return 0;
}
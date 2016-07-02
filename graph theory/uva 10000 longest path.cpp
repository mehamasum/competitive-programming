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
using namespace std;

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef map<int,string> MAP;
typedef pair<int,int> PII;

#define INF (1<<29)
#define EPS 1e-7
#define PI acos(-1.0)
#define EulerConstant exp(1.0)
#define char2Int(c) (c-'0')

#define READ freopen("C:\\Users\\User\\Desktop\\input.txt","r",stdin)
#define WRITE freopen("C:\\Users\\User\\Desktop\\output.txt","w",stdout)

#define FOR(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FORE(i,L,R) for (int i = L; i <= R; i++)
#define DEC(i,L,R) for (int i = L; i > R; i--)
#define DECE(i,L,R) for (int i = L; i >= R; i--)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) // traverse an STL data structure

#define MEM(a,b) memset(a,b,sizeof(a))
#define SET(a,n,val) FOR(i,0,n) a[i]=val
#define SET2D(a,r,c,val) FOR(i,0,r) FOR(j,0,c) a[i][j]=val

#define SIZE(x) ((int)((x).size()))
#define arrSize(arr) ( sizeof(arr) / sizeof((arr)[0]) )

#define sf(a) scanf("%d",&a)
#define sff(a,b) scanf("%d%d", &a, &b)
#define sfff(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define sd(a) scanf("%lf",&a)
#define sdd(a,b) scanf("%lf%lf", &a, &b)
#define sddd(a,b,c) scanf("%lf%lf%lf", &a, &b, &c)
#define print(a) printf("%d\n",a)
#define space <<" "<<
#define el <<endl
#define NL "\n"
#define pf printf
#define put cout<<

#define df(a) cerr<<#a<<" = "<<(a)<<endl
#define dff(a,b) cerr<<#a<<" = "<<(a)<<" "<<#b<<" = "<<(b)<<endl
#define dfff(a,b,c) cerr<<#a<<" = "<<(a)<<" "<<#b<<" = "<<(b)<<" "<<#c<<" = "<<(c)<<endl

#define printArr(a,L,R) FOR(i,L,R) cout << a[i] << (i==(R-1)?'\n':' ')
#define printArrE(a,L,R) FORE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printArr2D(a,R,C) FOR(i,0,R) FOR(j,0,C) cout << a[i][j] << (j==(R-1)?'\n':' ')
#define printV(a) printArr(a,0,a.size()-1)

#define ALL(c) (c).begin(), (c).end()
#define PB push_back
#define MP left_pair
#define uu first
#define vv second
#define left  (2*i)
#define right (2*i+1)

#define mx 105

int n, m, src;
int dp[mx],son[mx];
vector <int> G[mx];

int findLast(int u)
{
	//cout<<u space son[u] el;
	if(son[u]==-1) return u;
	findLast(son[u]);
}

int longest(int u)
{
    if(dp[u]!=-1) return dp[u];
	if(G[u].size()==0) return 0;
    int maxi=-INF, maxSon=-INF;
    for(int i=0; i<G[u].size(); i++)
    {
        int v=G[u][i];
        
		//dff(v,longest(v));
		
        if(longest(v)>maxi || (longest(v)==maxi && findLast(maxSon)>findLast(v) )  )
        {
			
			//cout<<v space longest(v) el;
            maxi=longest(v);
			maxSon=v;
            son[u]=v;
			//cout<<u space son[u] el;
        }
    }
    return dp[u]=maxi+1;
}



int main()
{
    READ;
    int t=0;
    while(1)
    {
        sf(n);
        if(n==0) break;
        sf(src);
        while(1)
        {
            int x,y;
            sff(x,y);
            if(x==0 && y==0)
                break;
            G[x].push_back(y);

        }

        memset(dp,-1,sizeof dp);
        memset(son,-1,sizeof son);
        int ans=longest(src);
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",++t,src,ans,findLast(src));

		FOR(i,0,n)
			G[i].clear();
    }
    return 0;
}


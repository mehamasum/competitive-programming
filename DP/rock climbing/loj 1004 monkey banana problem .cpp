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
#define printArr2D(a,R,C) FOR(i,0,R) {FOR(j,0,C) cout << a[i][j] << (j==(R-1)?'\n':' '); pf(NL);}
#define printV(a) printArr(a,0,a.size()-1)

#define ALL(c) (c).begin(), (c).end()
#define PB push_back
#define MP left_pair
#define uu first
#define vv second
#define left  (2*i)
#define right (2*i+1)

#define MAX 1005

int mat[205][105],dp[205][105];
int n,r,c;
int climb(int i,int j)
{
	if(i>=0 && i<r && j>=0 && j<c)
	{
		if(dp[i][j]!=-1) return dp[i][j];
		int ret1=0, ret2=0;
		ret1=climb(i+1,j)+mat[i][j];
		if(i<n-1) ret2=climb(i+1,j+1)+mat[i][j];
		else ret2=climb(i+1,j-1)+mat[i][j];
		
		//if(ret1!=0 || ret2!=0) cout << i space j space mat[i][j] space max(ret1,ret2) el;//ret1 space ret2 el;
		return dp[i][j]=max(ret1,ret2);
	}
	else
		return 0;
}

int main()
{
	READ;
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++)
	{
		scanf("%d",&n);
		r=2*n-1;
		c=n;

		MEM(mat,0);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				scanf("%d",&mat[i][j]);
			}
		}
		for(int i=n;i<2*n-1;i++)
		{
			for(int j=0;j<2*n-1-i;j++)
			{
				scanf("%d",&mat[i][j]);
			}
		}

		MEM(dp,-1);
		printf("Case %d: %d\n",t,climb(0,0));
	}
	return 0;
}
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

#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define printArr(a,L,R) FOR(i,L,R) cout << a[i] << (i==(R-1)?'\n':' ')
#define printArrE(a,L,R) FORE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printArr2D(a,R,C) FOR(i,0,R) FOR(j,0,C) cout << a[i][j] << (j==(R-1)?'\n':' ')
#define printV(a) printArr(a,0,a.size()-1)

#define ALL(c) (c).begin(), (c).end()
#define PB push_back
#define MP left_pair
#define uu first
#define vv second
// #define left  (2*i)
#define right (2*i+1)

#define MAX 10005

int coin[]={1,5,10,25,50};
double dp[5][50000];
int tol;

double coinChange(int i, int left)
{
	//cout<< i space left el;
	if(i>4)
	{
		if(left==0) return 1.0;
		else return 0;
	}

	if(dp[i][left]!=-1)
		return dp[i][left];

	double way1=0, way2=0;

	if(left-coin[i]>=0)
		way1=coinChange(i,left-coin[i]);
	way2=coinChange(i+1, left);

	return dp[i][left]=way1+way2;

}

int main()
{
    READ;
	SET2D(dp,5,50000,-1.0);
	while(sf(tol)==1)
	{
		double ans=coinChange(0,tol);
		if(ans!=1) pf("There are %.0lf ways to produce %d cents change.\n",ans, tol );
		else pf("There is only 1 way to produce %d cents change.\n",tol );
	}
    return 0;
}

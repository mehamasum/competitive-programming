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
#define printArr2D(a,R,C) FOR(i,0,R) FOR(j,0,C) cout << a[i][j] << (j==(R-1)?'\n':' ')
#define printV(a) printArr(a,0,a.size()-1)

#define ALL(c) (c).begin(), (c).end()
#define PB push_back
#define MP left_pair
#define uu first
#define vv second
#define left  (2*i)
#define right (2*i+1)

#define MAX 1000
char A[MAX],B[MAX];
int dp[MAX][MAX];
int calcLCS(int i,int j)
{
	if(A[i]=='\0' || B[j]=='\0') return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	if(A[i]==B[j])
	{
		return dp[i][j]=calcLCS(i+1,j+1)+1;
	}
	else
	{
		int val1=calcLCS(i+1,j);
		int val2=calcLCS(i,j+1);
		return dp[i][j]=max(val1, val2);
	}
}
string ans;
void printLCS(int i,int j)
{
	if(A[i]=='\0' || B[j]=='\0')
	{
		cout<<ans<<endl;
		return;
	}
	if(A[i]==B[j])
	{
		ans+=A[i];
		printLCS(i+1,j+1);
	}
	else
	{
		if(dp[i+1][j]>dp[i][j+1]) printLCS(i+1,j);
		else printLCS(i,j+1);
	}
}

int cnt=0;
void printAllLCS(int i,int j) // there is bug in it
{
	if(A[i]=='\0' || B[j]=='\0')
	{
		cout<<++cnt space ans<<endl;
		return;
	}
	if(A[i]==B[j])
	{
		ans+=A[i];
		printAllLCS(i+1,j+1);
		ans.erase(ans.end()-1); //Delete last character
	}
	else
	{
		if(dp[i+1][j]>dp[i][j+1]) printAllLCS(i+1,j);
		else if(dp[i+1][j]<dp[i][j+1]) printAllLCS(i,j+1);
		else
		{
			printAllLCS(i+1,j);
			printAllLCS(i,j+1);
		}
	}
}
int main() 
{
	READ;
	SET2D(dp,MAX,MAX,-1);
	scanf("%s%s",A,B);
	printf("%d\n",calcLCS(0,0));
	ans="";
	printLCS(0,0);
	ans="";
	printAllLCS(0,0);
}
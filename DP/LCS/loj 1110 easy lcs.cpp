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

#define MAX 102
char A[MAX],B[MAX], C[MAX];
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


void printAllLCS(int n)
{
	MEM(C,0);
	int r=0, c=0, cnt=0;
	int a,b;
	DECE(k,n,1)
	{
		FOR(i,r,strlen(A))
		{
			FOR(j,c,strlen(B))
			{
				if(dp[i][j]==k && A[i]==B[j])
				{
					if(C[cnt]==0 || (C[cnt]!=0 && C[cnt]>A[i]) )
					{
						C[cnt]=A[i];
						a=i+1;
						b=j+1;
						//cout<<C[cnt]<<endl;
					}
				}
			}
		}
		cnt++;
		r=a;
		c=b;
	}

	C[cnt]=NULL;
	printf("%s\n",C);

}

int main()
{
	READ;
	//WRITE;
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++)
	{
		MEM(dp,-1);
		scanf("%s %s",A,B);
		printf("Case %d: ",t);

		int ans=calcLCS(0,0);
		//cout<<ans el;
		if(ans) 
			printAllLCS(ans);
		else
			printf(":(\n");
	}
	return 0;
}
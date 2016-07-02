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

using namespace std;

#define space <<" "<<
#define endl <<endl
#define NL "\n"
#define pf printf
#define put cout<<

#define MAX 1005
int maxn,maxw=0;

int p[MAX], w[MAX], dp[MAX][MAX];

int knapsack(int i, int tol)
{
	if(i==maxn+1) return 0;
	if(dp[i][tol]!=-1) return dp[i][tol];

	int profit1=0, profit2=0;
	if(tol+w[i]<=maxw)
		profit1=p[i]+knapsack(i+1,tol+w[i]);
	profit2=knapsack(i+1,tol);

	dp[i][tol]=max(profit1, profit2);
	return dp[i][tol];
}



int main()
{
	READ;
	int T;
	while(scanf("%d", &T)==1)
	{
		for(int t=1; t<=T; t++)
		{
			MEM(p,0);
			MEM(w,0);
			MEM(dp,-1);

			int g,ans=0;
			sf(maxn);
			for(int i=1;i<=maxn;i++)
				scanf("%d %d",p+i,w+i);
			sf(g);
			for(int i=1;i<=g;i++)
			{
				sf(maxw);
				MEM(dp,-1);
				int earnt=knapsack(1,0);
				ans+=earnt;
			}

			printf("%d\n",ans);
		}
	}
	return 0;
}

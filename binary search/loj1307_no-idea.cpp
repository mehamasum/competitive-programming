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

using namespace std;
int q;
int dp[300];
int factorial(int n)
{
	if(dp[n]!=-1) return dp[n];
	else return dp[n]=n*factorial(n-1);
}
int zeroFinder(int value)
{

}
int numbermaker(int a)
{
	int count=10;
	for(int i=1;i<q;i++)
		count*=10;
	return count;
}
int BS(int lo, int hi)
{
	int mid, fac;
	while(lo<mid)
	{
		mid=lo+(hi-lo)/2;
		fac=factorial(mid);
		if(zeroFinder(fac)==q)
			return mid;
		if(fac>numbermaker(q))

	}
}
int main()
{
	memset(dp,-1, sizeof dp);
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++)
	{

		scanf("%d",&q);
		BS(0,200);



		printf("Case %d: %d",t,mid);
	}
	return 0;
}

// new StringBuffer(string).reverse().toString();
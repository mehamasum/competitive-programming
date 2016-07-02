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

long long int a, b, c, d, e, f;
long long int dp[10005];
long long int fn( long long int n ) 
{
	if( n == 0 ) return a% 10000007;
	if( n == 1 ) return b% 10000007;
	if( n == 2 ) return c% 10000007;
	if( n == 3 ) return d% 10000007;
	if( n == 4 ) return e% 10000007;
	if( n == 5 ) return f% 10000007;

	if(dp[n]!=-1) return dp[n];
	else
	{
		dp[n]=(fn(n-1)+ fn(n-2)+ fn(n-3)+ fn(n-4) + fn(n-5) + fn(n-6))% 10000007;
		return dp[n];
	}
}

int main() 
{
	//freopen("input.txt","r",stdin);
	long long int n, caseno = 0, cases;
	scanf("%lld", &cases);
	while( cases-- ) 
	{
		memset(dp, -1, sizeof(dp));
		scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
		printf("Case %lld: %lld\n", ++caseno, fn(n) % 10000007);
	}
	return 0;
}
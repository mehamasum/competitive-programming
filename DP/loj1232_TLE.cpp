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
#define MOD 100000007
int dp[105][10005];
int coin[105], n, k;

int fn(int i, int count)
{
	if(i>n)
	{
		if(count==k) return 1;
		else return 0;
	}

	if(count==k) return 1;
	if(count>k) return 0;

	if (dp[i][count]!=-1) return dp[i][count];

	else
	{
		int ways=0;
		for(int p=1;p<=k;p++)
		{
			if(count+p*coin[i]<=k) 
				ways=(ways+ fn(i+1, count+p*coin[i])  % MOD) % MOD;
			else 
				break;
		}
		ways=(ways+fn(i+1, count) % MOD) % MOD;

		return dp[i][count]=ways % MOD;

	}
}

int main() 
{
	freopen("input.txt","r",stdin);
	int caseno = 0, cases;
	scanf("%d", &cases);
	

	while( cases-- ) 
	{
		memset(dp, -1, sizeof(dp));
		scanf("%d %d",&n, &k);
		for(int i=1;i<=n;i++)
			scanf("%d",coin+i);
		printf("Case %d: %d\n", ++caseno, fn(1,0) % MOD);
	}
	return 0;
}
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

int coin[105], dp[10005];

int main()
{
	FRE;
	int caseno = 0, cases;
	scanf("%d", &cases);
	

	while( cases-- ) 
	{
		int n, k;
		scanf("%d %d",&n, &k);
		for(int i=1;i<=n;i++)
			scanf("%d",coin+i);
		memset(dp, 0, sizeof(dp));
		for(int i=1; i<=n ;i++)
			for(int j=k ; j>=0 ;j--)
			{
				dp[j]+=
			}
		printf("Case %d: %d\n", ++caseno, fn(1,0) % MOD);
	}
	return 0;
}
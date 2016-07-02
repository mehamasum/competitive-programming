#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <iterator>
#include <sstream>
#include <numeric>
#include <fstream>
#include <vector>
#include <cctype>
#include <math.h>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
//#include <windows.h>
using namespace std;

#define read() freopen("c:\\Users\\User\\Desktop\\Input.txt", "r", stdin)
#define write() freopen("c:\\Users\\User\\Desktop\\Output.txt", "w", stdout)
#define FRE(i,a,b) for(i = a; i <= b; i++)
#define FRL(i,a,b) for(i = a; i < b; i++)
#define mem(t, v) memset ((t) , v, sizeof(t))
#define all(x) x.begin(),x.end()
#define sf(n) scanf("%d", &n)
#define sff(a,b) scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define pf printf
#define VI vector <int>
#define QI queue <int>
#define pb push_back
#define sz size()
#define mp make_pair
#define ins insert
#define fi first
#define se second
#define inf (1<<29)
#define MAX 110
#define MOD 100000007

typedef long long int LL;
typedef double db;

int v[1000];
LL dp[100000];

int main()
{
	int i, j, K, t, cs, n, mx, st, ed;
	freopen("C:\\Users\\User\\Desktop\\input.txt","r",stdin);
	sf(t);
	FRE(cs,1,t)
	{
		sff(n, K);
		FRE(i,1,n) sf(v[i]);
		FRE(i,1,n) pf("%d ",v[i]);
		cout<<endl;
		mem(dp, 0);
		dp[0] = 1;

		for( int i = 1; i <= n; i++ )
		{
			for(int k = 1; k <= K; k++)
			{
				if( v[i] <= k)
					dp[k] = (dp[k] + dp[k - v[i]]) % MOD;
			}
		}

		printf("Case %d: %lld\n", cs, dp[K]%MOD);
	}
	return 0;
}
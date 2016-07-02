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
#define left(i) ((i+1)%3)
#define right(i) ((i+2)%3)

#define N 25
#define INF 1<<28
int T,n;
int RGB[N][3];
int COST[N][3];

int main()
{
	freopen("input.txt","r",stdin);
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			memset(RGB[i],0,sizeof RGB[i]);
		for(int i=0;i<n;i++)
			memset(COST[i],0,sizeof COST[i]);

		for(int i=0;i<n;i++)
			for(int j=0;j<3;j++)
				cin>>RGB[i][j];
		for(int j=0;j<3;j++)
				COST[0][j]=RGB[0][j];
		for(int i=1;i<n;i++)
			for(int j=0;j<3;j++)
				COST[i][j]=RGB[i][j]+min(COST[i-1][left(j)],COST[i-1][right(j)]);
		printf("Case %d: %d\n",t, min( COST[n-1][0], min (COST[n-1][1],COST[n-1][2]) ) );
	}
}
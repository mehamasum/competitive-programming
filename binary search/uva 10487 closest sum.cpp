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
#define left(i) ((i+1)%3)
#define right(i) ((i+2)%3)
#define INF 1<<29
const double PI = acos(-1.0);
const double EulerConstant = std::exp(1.0);
#define FREOPEN freopen("input.txt","r",stdin)
#define EPS 1e-7
using namespace std;
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int a[1006],sum[1000099];
int main()
{
	//FREOPEN;
	int n,cnt=0;
	while(1)
	{
		scanf("%d",&n);
		if(n==0) break;
		cnt++;
		memset(a,0,sizeof (a));
		memset(sum,0,sizeof (sum));
		int i,j,m,k=0,minimum=INF;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
			{
				sum[k]=a[i]+a[j];
				k++;
			}
		//qsort(sum, k, sizeof (int), compare);
		scanf("%d",&m);
		int mm, ans;
		printf("Case %d:\n",cnt);
		for(j=0;j<m;j++)
		{
			minimum=INF;
			scanf("%d",&mm);
			for(i=0;i<k;i++)
			{
				int d=(int) fabs(1.0*sum[i]-mm);
				if(d<minimum) { minimum=d; ans=sum[i];}
			}
			printf("Closest sum to %d is %d.\n",mm,ans);
		}
	}
	return 0;
}

		

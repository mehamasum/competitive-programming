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
#define inf 1<<29
const double PI = acos(-1.0);
const double EulerConstant = std::exp(1.0);
#define FREOPEN freopen("input.txt","r",stdin)
#define EPS 1e-7
#define FREE(x) memset(x,0,sizeof(x))
using namespace std;

int boys_list[105][105], girls_list[105][105];
int boys_prio[105][105], girls_prio[105][105];
int engage[205], proposed[105][105];
int n;
queue <int> patro;
void STABLE_MARR(int boy)
{
	int girl;
	for(int i=1;i<=n;i++)
	{
		girl=boys_list[boy][i];
		if(!proposed[boy][girl])
			break;
	}
	proposed[boy][girl]=1;
	if(engage[girl]==0)
	{
		engage[girl]=boy;
		patro.pop();
	}
	else
	{
		int fianc=engage[girl];
		if(girls_prio[girl][boy]<girls_prio[girl][fianc])
		{
			engage[girl]=boy;
			patro.pop();
			patro.push(fianc);
		}
		else STABLE_MARR(boy);
	}

}

int main()
{
	FREOPEN;
	int t=0,T;

	scanf("%d",&T);
	for(t=0;t<T;t++)
	{
		FREE(boys_list);
		FREE(girls_list);
		FREE(girls_prio);
		FREE(boys_prio);
		FREE(engage);
		FREE(proposed);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			patro.push(i);
			for(int j=1;j<=n;j++)
			{
				int temp;
				scanf("%d",&temp);
				boys_list[i][j]=temp;
				boys_prio[i][temp]=j;	
			}
		}
		for(int i=n+1;i<=2*n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int temp;
				scanf("%d",&temp);
				girls_list[i][j]=temp;
				girls_prio[i][temp]=j;
			}
		}
		while(!patro.empty())
		{
			int i=patro.front();
			STABLE_MARR(i);
		}
		
		printf("Case %d:",t+1);
		for(int i=n+1;i<=2*n;i++)
			printf(" (%d %d)",engage[i],i);
		printf("\n");
	}
	return 0;
}
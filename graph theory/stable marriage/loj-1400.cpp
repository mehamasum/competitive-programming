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

int polar_list[105][105], maiyar_list[105][105];
int polar_prio[105][105], maiyar_prio[105][105];
int fre[205], engage[205]={0}, proposed[105][105]={0};
int n;

void STABLE_MARR(int pola)
{
	int maiya;
	for(int i=1;i<=n;i++)
	{
		maiya=polar_list[pola][i];
		if(!proposed[pola][maiya])
			break;
	}
	proposed[pola][maiya]=1;
	if(fre[maiya]==1)
	{
		fre[maiya]=0;
		engage[maiya]=pola;
	}
	else
	{
		int fianc=engage[maiya];
		if(maiyar_prio[maiya][pola]<maiyar_prio[maiya][fianc])
		{
			fre[fianc]=1;
			engage[maiya]=pola;
		}
		else STABLE_MARR(pola);
	}

}

int main()
{
	FREOPEN;
	int t=0,T;
	
	scanf("%d",&T);
	for(t=0;t<T;t++)
	{
		FREE(polar_list);
		FREE(maiyar_list);
		FREE(maiyar_prio);
		FREE(polar_prio);
		FREE(engage);
		FREE(proposed);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int temp;
				scanf("%d",&temp);
				polar_list[i][j]=temp;
				polar_prio[i][temp]=j;	
			}
		}
		for(int i=n+1;i<=2*n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int temp;
				scanf("%d",&temp);
				maiyar_list[i][j]=temp;
				maiyar_prio[i][temp]=j;
			}
		}
		for(int i=0;i<205;i++)
			fre[i]=1;
		for(int i=1;i<=n;i++)
		{
			if(fre[i]==1)
				STABLE_MARR(i);
		}
		printf("Case %d:",t+1);
		for(int i=n+1;i<=2*n;i++)
			printf(" (%d %d)",engage[i],i);
	}
	return 0;
}
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
using namespace std;


int w,h,tim;
char a[1000][1000];
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int visited[1000][1000]={0};

void DFS(int x, int y)
{
	for(int k=0;k<4;k++)
	{
		int tx=x+fx[k];
		int ty=y+fy[k];
		if((tx>=0 && tx<h) && (ty>=0 && ty<w) && visited[tx][ty]==0 && a[tx][ty]=='.')
		{
			tim++;
			visited[tx][ty]=1;
			DFS(tx,ty);
		}
	}
}


int main()
{
	//FREOPEN;
	int t=0,T;
	scanf("%d",&T);
	getchar();
	for(t=0;t<T;t++)
	{
		tim=0;
		int x=0,y=0;
		scanf("%d %d",&w,&h);
		int i,j;
		getchar();

		memset(visited,0,sizeof(visited));
		memset(a,0,sizeof(a));
		//getchar();
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				scanf("%c",&a[i][j]);
				if(a[i][j]=='@') { x=i; y=j; }
			}
			getchar();
			a[i][j]='\0';
		}
		tim=1;
		visited[x][y]=1;
		DFS(x,y);
		printf("Case %d: %d\n",t+1,tim);
	}
	return 0;
}
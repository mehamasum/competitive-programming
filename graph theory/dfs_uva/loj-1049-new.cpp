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
vector <int> in[105], out[105], in_cash[105], out_cash[105];
//int gray[105]={0};
int tol=0, dir=0;
void DFS(int n, int p)
{
	int m;
	if(out[n].size()==2)
	{
		m=out[n][0];
	
		if(m==p) { m=out[n][1]; tol+=out_cash[n][1];}
		else { tol+=out_cash[n][0]; }
		
	}
	else if(out[n].size()==0)
	{
		m=in[n][0];
		
		if(m==p) { m=in[n][1]; tol+=in_cash[n][1]; dir+=in_cash[n][1];}
		else { tol+=in_cash[n][0];dir+=in_cash[n][0]; }

	}
	else if(out[n].size()==1 && in[n].size()==1)
	{
		m=out[n][0];
		if(m==p) 
		{ 
			m=in[n][0]; 
			tol+=in_cash[n][0]; 
			dir+=in_cash[n][0];
		}
		else { tol+=out_cash[n][0]; }
	}
	if(m==1) return;
	DFS(m,n);
}
int main()
{
	FREOPEN;
	int t=0,T;
	scanf("%d",&T);
	getchar();
	for(t=0;t<T;t++)
	{
		getchar();
		int n,i,j;
		tol=dir=0;
		
		for(i=0;i<105;i++)
		{
			out[i].clear();
			in[i].clear();
			out_cash[i].clear();
			in_cash[i].clear();

		}
		//memset(gray,0,sizeof(gray));

		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a, &b, &c);
			in[b].push_back(a);
			in_cash[b].push_back(c);
			out[a].push_back(b);
			out_cash[a].push_back(c);
		}
		//gray[1]=1;
		
		DFS(1,0);
		int min_cash;
		//if(dir==tol-dir) min_cash=0;
		min_cash=min(dir,tol-dir);
		printf("Case %d: %d\n",t+1,min_cash);

	}
	return 0;
}

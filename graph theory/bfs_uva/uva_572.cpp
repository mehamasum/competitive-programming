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

#define LL long long
#define ULL unsigned long long

#define INF (1<<29)
#define EPS 1e-7
const double PI = acos(-1.0);
const double EulerConstant = std::exp(1.0);

#define READ freopen("C:\\Users\\User\\Desktop\\input.txt","r",stdin)
#define MEM(a,b) memset(a,b,sizeof(a))

#define sf(a) scanf("%d",&a)
#define sff(a,b) scanf("%d%d", &a, &b)
#define sfff(a,b,c) scanf("%d%d%d", &a, &b, &c)

#define sd(a) scanf("%lf",&a)
#define sdd(a,b) scanf("%lf%lf", &a, &b)
#define sddd(a,b,c) scanf("%lf%lf%lf", &a, &b, &c)

#define print(a) printf("%d\n",a)
#define pf printf

using namespace std;

#define space <<" "<<
#define endl <<endl
#define put cout<<

#define MAX 105

char v[105][105];
int visited[105][105]={0};
queue <int> qr;
queue <int> qc;

int cnt=0;
int r,c;
	

int dr[]={-1,-1,-1,0,0,1,1,1};
int dc[]={-1,0,1,-1,1,-1,0,1};

void bfs_visit(int i, int j)
{
	qr.push(i);
	qc.push(j);

	while(!qr.empty() || !qc.empty())
	{
		int ur,uc;
		ur=qr.front();
		uc=qc.front();
		qr.pop();
		qc.pop();
		for(int k=0;k<8;k++)
		{
			int vr,vc;
			vr=ur+dr[k];
			vc=uc+dc[k];
			if(vr>=0 && vr<r && vc>=0 && vc<c && !visited[vr][vc] && v[vr][vc]=='@')
			{
				qr.push(vr);
				qc.push(vc);
				visited[vr][vc]=1;
			}
		}
	}
}

int bfs()
{
	for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(v[i][j]=='@' && !visited[i][j])
				{
					visited[i][j]=1;
					bfs_visit(i,j);
					cnt++;
				}
			}
		}
	return cnt;
}



int main()
{	
	READ;
	int i,j;
	while(scanf("%d %d",&r,&c)==2)
	{
		getchar();
		if(r==0) break;
		cnt=0;
		
		MEM(v,0);
		MEM(visited,0);
		
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				scanf("%c",&v[i][j]);
			}
			getchar();
		}
		
		
		printf("%d\n",bfs());
	}
	return 0;
}

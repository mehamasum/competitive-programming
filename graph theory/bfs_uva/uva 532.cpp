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
#define NL "\n"

#define MAX 32

char v[MAX][MAX][MAX];
int visited[MAX][MAX][MAX];
int d[MAX][MAX][MAX];

queue <int> ql;
queue <int> qr;
queue <int> qc;

int l,r,c;
	
int dl[]={0,0,0,0,1,-1};
int dr[]={-1,0,0,1,0,0};
int dc[]={0,-1,1,0,0,0};

int bfs(int q, int w, int e)
{
	
	ql.push(q);
	qr.push(w);
	qc.push(e);
	
	visited[q][w][e]=1;
	d[q][w][e]=0;
	

	while(!ql.empty() || !qr.empty() || !qc.empty())
	{
		int ul, ur, uc;

		ul=ql.front();
		ur=qr.front();
		uc=qc.front();

		ql.pop();
		qr.pop();
		qc.pop();

		for(int k=0;k<6;k++)
		{
			int vl,vr,vc;

			vl=ul+dl[k];
			vr=ur+dr[k];
			vc=uc+dc[k];

			if(vl>=0 && vl<l && vr>=0 && vr<r && vc>=0 && vc<c && !visited[vl][vr][vc] && v[vl][vr][vc]=='E')
			{
				d[vl][vr][vc]=d[ul][ur][uc]+1;
				return d[vl][vr][vc];
			}


			if( (vl>=0 && vl<l) && (vr>=0 && vr<r) && (vc>=0 && vc<c) && visited[vl][vr][vc]==0 && v[vl][vr][vc]=='.')
			{
				ql.push(vl);
				qr.push(vr);
				qc.push(vc);

				d[vl][vr][vc]=d[ul][ur][uc]+1;
				visited[vl][vr][vc]=1;
			}
		}
	}

	return -1;
}




int main()
{	
	READ;

	while(1)
	{
		cin >>l >>r >>c ;
		
		if(l==0 && r==0 && c==0) break;
		int sl, sr, sc;
		
		MEM(v,0);
		MEM(visited,0);
		MEM(d,0);

		while(!ql.empty()) ql.pop();
		while(!qr.empty()) qr.pop();
		while(!qc.empty()) qc.pop();
		
		char arr[100], vua[100];


		for(int i=0;i<l;i++)
		{
			for(int j=0;j<r;j++)
			{
				cin >> arr;
				for(int k=0;k<c;k++)
				{
					v[i][j][k]=arr[k];
					if(v[i][j][k]=='S')
					{
						sl=i; sr=j; sc=k;
					}
				}

			}
		}
				

		//getchar();

		//put "s:" space sl space sr space sc endl;

		/*for(int i=0;i<l;i++)
		{
			for(int j=0;j<r;j++)
			{
				for(int k=0;k<c;k++)
				{
					pf ("%c",v[i][j][k]);
				}
				put NL;
			}

			put NL;
		}*/
		
		int ans=bfs(sl,sr,sc);
		if(ans==-1)
			pf ("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n",ans);

		//fflush(stdin);
	}
	return 0;
}

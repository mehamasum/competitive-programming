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

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef map<int,string> MAP;
typedef pair<int,int> PII;

#define INF (1<<29)
#define EPS 1e-7
#define PI acos(-1.0)
#define EulerConstant exp(1.0)
#define char2Int(c) (c-'0')

#define READ freopen("C:\\Users\\User\\Desktop\\input.txt","r",stdin)
#define WRITE freopen("C:\\Users\\User\\Desktop\\output.txt","w",stdout)

#define FOR(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FORE(i,L,R) for (int i = L; i <= R; i++)
#define DEC(i,L,R) for (int i = L; i > R; i--)
#define DECE(i,L,R) for (int i = L; i >= R; i--)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) // traverse an STL data structure

#define MEM(a,b) memset(a,b,sizeof(a))
#define SET(a,n,val) FOR(i,0,n) a[i]=val
#define SET2D(a,r,c,val) FOR(i,0,r) FOR(j,0,c) a[i][j]=val

#define SIZE(x) ((int)((x).size()))
#define arrSize(arr) ( sizeof(arr) / sizeof((arr)[0]) )

#define sf(a) scanf("%d",&a)
#define sff(a,b) scanf("%d%d", &a, &b)
#define sfff(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define sd(a) scanf("%lf",&a)
#define sdd(a,b) scanf("%lf%lf", &a, &b)
#define sddd(a,b,c) scanf("%lf%lf%lf", &a, &b, &c)
#define print(a) printf("%d\n",a)
#define sp <<" "<<
#define el <<endl
#define NL "\n"
#define pf printf
#define put cout<<

#define df(a) cerr<<#a<<" = "<<(a)<<endl
#define dff(a,b) cerr<<#a<<" = "<<(a)<<" "<<#b<<" = "<<(b)<<endl
#define dfff(a,b,c) cerr<<#a<<" = "<<(a)<<" "<<#b<<" = "<<(b)<<" "<<#c<<" = "<<(c)<<endl

#define printArr(a,L,R) FOR(i,L,R) cout << a[i] << (i==(R-1)?'\n':' ')
#define printArrE(a,L,R) FORE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printArr2D(a,R,C) FOR(i,0,R) FOR(j,0,C) cout << a[i][j] << (j==(R-1)?'\n':' ')
#define printV(a) printArr(a,0,a.size()-1)

#define ALL(c) (c).begin(), (c).end()
#define PB push_back
#define MP make_pair
#define uu first
#define vv second
#define left  (2*i)
#define right (2*i+1)

#define MAX 55

struct eve
{

	int d;
	int ty;
	int p;

	eve()
	{

	}

	eve(int _d,int _ty,int _p)
	{
		ty=_ty;
		d=_d;
		p=_p;
	}
};

typedef struct eve data;
data ara[MAX];
double rate, leak; 
int cnt=0, flag=0;

double simu(double x)
{

	double rem=x;
	rate=ara[0].p;
	leak=0;

	FOR(i,1,cnt)
	{
		rem-=(1.0*ara[i].d-ara[i-1].d)*(rate/100.0+leak*1.0);
		if(rem<0) return -INF;
		//cout<<(1.0*ara[i].d-ara[i-1].d)*(rate/100.0+leak*1.0) sp rem el;


		//pf("%0.20lf\n",rem);
		if(ara[i].ty==1)
			rate=ara[i].p;
		if(ara[i].ty==2)
			leak++;
		if(ara[i].ty==3)
			rem+=x-rem;
		if(ara[i].ty==4)
			leak=0;
	}

	//if(rem==0) pf("fuck\n");
	return rem;
}

double BS()
{
	double lo=0, hi=10000, mid;

	FOR(i,0,50)
	{
		mid=lo+(hi-lo)/2;
		if(fabs(simu(mid)-0)<EPS)
			return mid;
		if(simu(mid)>0) hi=mid;
		else lo=mid;
	}
	return mid;
}

int main()
{
	READ;
	while(1)
	{
		cnt=0, flag=0;
		while(1)
		{
			int a, c=0;
			char b[20];


			sf(a);
			scanf("%s",b);
			if(strcmp(b,"Fuel")==0)
			{
				scanf("%s",b);
				sf(c);
			}

			else if(strcmp(b,"Gas")==0)
			{
				scanf("%s",b);
			}

			if(a==0 && strcmp(b,"consumption")==0 && c==0)
			{
				flag=1;
				break;
			}

			if(strcmp(b,"consumption")==0)
				ara[cnt++]=eve(a,1,c);
			else if(strcmp(b,"Leak")==0)
				ara[cnt++]=eve(a,2,c);
			else if(strcmp(b,"station")==0)
				ara[cnt++]=eve(a,3,c);
			else if(strcmp(b,"Mechanic")==0)
				ara[cnt++]=eve(a,4,c);
			else if(strcmp(b,"Goal")==0)
			{
				ara[cnt++]=eve(a,5,c);
				break;
			}


			//dfff(ara[cnt-1].ty,ara[cnt-1].d,ara[cnt-1].p);

		}

		if(flag==1) break;
		//simu(10);
		pf("%0.3lf\n",BS());
		FOR(i,0,cnt)
			ara[i].d=0, ara[i].p=0, ara[i].ty=0;
		//df(flag);

	}
	return 0;
}	
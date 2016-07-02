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
typedef stack<int> SI;

#define INF (1<<29)
#define EPS 1e-7
#define PI acos(-1.0)
#define EulerConstant exp(1.0)
#define char2Int(c) (c-'0')

#define READ freopen("C:\\Users\\User\\Desktop\\input.txt","r",stdin)
#define WRITE freopen("C:\\Users\\User\\Desktop\\output.txt","w",stdout)

#define FRA(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FRAE(i,L,R) for (int i = L; i <= R; i++)
#define FRD(i,L,R) for (int i = L; i > R; i--)
#define FRDE(i,L,R) for (int i = L; i >= R; i--)
#define FRAEACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) // traverse an STL data structure

#define MEM(a,b) memset(a,b,sizeof(a))
#define SET(a,n,val) FRA(i,0,n) a[i]=val
#define SET2D(a,r,c,val) FRA(i,0,r) FRA(j,0,c) a[i][j]=val

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

#define printArr(a,L,R) FRA(i,L,R) cout << a[i] << (i==(R-1)?'\n':' ')
#define printArrE(a,L,R) FRAE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printArr2D(a,R,C) FRA(i,0,R) FRA(j,0,C) cout << a[i][j] << (j==(R-1)?'\n':' ')
#define printV(a) printArr(a,0,a.size()-1)

#define ALL(c) (c).begin(), (c).end()
#define PB push_back
#define MP make_pair
#define uu first
#define vv second
#define left  (2*i)
#define right (2*i+1)

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))
//void printSet(int x){pf("S=%2d=",x); SI st; while(x) st.push(x%2),x/=2; while(!st.empty()) pf("%d",st.top()),st.pop();pf(NL);}

#define MAX 105
int n,m;
struct edge
{
	int u,v;
	double w;
	bool operator < (const edge& obj) const
	{
		return w < obj.w; 
	}
};

int par[MAX];

vector <edge> e;

struct cor
{
	double a,b;
};

double dist(cor p, cor q)
{
	return sqrt((p.a-q.a)*(p.a-q.a)+(p.b-q.b)*(p.b-q.b));
}

cor cor_arr[MAX];

void calc()
{
	//cout<<"here";
	FRA(i,0,n)
		FRA(j,i+1,n)
		{
			edge x;
			x.u=i;
			x.v=j;
			x.w=dist(cor_arr[i],cor_arr[j]);
			e.push_back(x);
		}
}

int parent(int r)
{
	return (par[r]==r) ? r: parent(par[r]);
}

double mst(int n)
{
	//sort
	sort(e.begin(), e.end());

	for(int i=0; i<n; i++)
		par[i]=i;

	int count=0;
	double sum=0;
	for(int i=0;i<e.size();i++)
	{
		int u= parent(e[i].u);
		int v= parent(e[i].v);

		if(u!=v)
		{
			//union
			par[u]=v;

			count++;
			sum+=e[i].w;

			if(count==n-1) break;		
		}
	}
	return sum;
}

int main()
{
	READ;
	int T;
	sf(T);
	FRAE(t,1,T)
	{
		sf(n);
		double a, b;
		FRA(i,0,n)
		{
			sdd(a,b);
			cor_arr[i].a=a;
			cor_arr[i].b=b;
		}

		calc();
		if(t!=1) pf(NL);
		printf("%0.2lf\n",mst(n));
		e.clear();
	}
}
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
#define space <<" "<<
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
#define MP left_pair
#define uu first
#define vv second
#define left  (2*i)
#define right (2*i+1)

#define MAX 4005

int A[MAX], B[MAX], C[MAX], D[MAX], AB[MAX*MAX];//, flag[MAX*MAX];
int n, cnt;


void BS(int lo, int hi, int key)
{
	if(lo>hi) return;
	int mid=lo+(hi-lo)/2;
	if(AB[mid]==key) //&& flag[mid]==0)
	{
		//flag[mid]=1;
		//dff(mid,AB[mid]);
		cnt++;
		BS(lo,mid-1,key);
		BS(mid+1,hi,key);
	}

	else if(AB[mid]>key)
		BS(lo,mid-1,key);
	else if(AB[mid]<key)
		BS(mid+1,hi,key);
}

int LowerBound(int lo, int hi, int key) 
{
	int i=-1;
	while(lo<=hi) 
	{
		int mid = (hi+lo)/2;
		if(AB[mid]>=key) 
		{
			if(AB[mid]==key)
				i=mid;
			hi = mid-1;
		} 
		else lo = mid+1;
	}
	return i;
}

int UpperBound(int lo, int hi, int key) 
{
	int i=-1;
	while(lo<=hi) 
	{
		int mid = (hi+lo)/2;
		if (AB[mid]<=key) 
		{
			if(AB[mid]==key)
				i=mid;
			lo=mid+1;
		} 
		else hi=mid-1;
	}
	return i;
}


int main()
{
	READ;
	//WRITE;
	int T;
	sf(T);
	FORE(p,1,T)
	{
		sf(n);
		FOR(i,0,n)
		{
			sff(A[i],B[i]);
			sff(C[i],D[i]);
		}

		int t=0;
		FOR(i,0,n)
		{
			FOR(j,0,n)
			{
				AB[t++]=-(A[i]+B[j]);
			}
		}

		//printArr(AB,0,t);
		sort(AB,AB+t);
		//printArr(AB,0,t);

		int sum=0;
		cnt=0;

		FOR(i,0,n)
		{
			FOR(j,0,n)
			{
				sum=C[i]+D[j];
				//put sum el;
				//put UpperBound(0,t-1,sum) space LowerBound(0,t-1,sum) el;

				int u=UpperBound(0,t-1,sum);
				int l=LowerBound(0,t-1,sum);
				if(u!=-1 || l!=-1)
					cnt+=u-l+1;
				//df(cnt);
			}
		}

		if(p!=1) pf(NL);
		pf("%d\n",cnt);

	}
	return 0;
}
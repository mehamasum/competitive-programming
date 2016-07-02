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
#define MP make_pair
#define uu first
#define vv second
#define left  (2*i)
#define right (2*i+1)
#define abs(x) (x<0?(-x):x)

#define MAX 100005

int n,k, arr[MAX];

int sliding()
{
	deque <PII> minDQ, maxDQ;
	int maxDif=0;
	FOR(i,0,n)
	{
		int mini=0, maxi=0, dif;

		while(minDQ.size() && minDQ.front().first>=arr[i])
			minDQ.pop_front();
		minDQ.push_front(MP(arr[i],i));
		while(minDQ.size() && minDQ.back().second<=i-k)
			minDQ.pop_back();
		if(i>=k-1) 
		{	
			mini=minDQ.back().first;
			//cout<<minDQ.back().first<<" ";
			//cout<<mini<<" ";
		}

		while(maxDQ.size() && maxDQ.front().first<=arr[i])
			maxDQ.pop_front();
		maxDQ.push_front(MP(arr[i],i));
		while(maxDQ.size() && maxDQ.back().second<=i-k)
			maxDQ.pop_back();
		if(i>=k-1) 
		{	
			maxi=maxDQ.back().first;
			//cout<<"** "<<maxDQ.back().first<<" ";
			//cout<<"** "<<maxi<<" ";
		}

		dif=fabs((double)mini-maxi);
		maxDif=max(maxDif,dif);
	}
	//cout<<endl;
	return maxDif;
}

int main() 
{
	READ;
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++)
	{
		sff(n,k);

		FOR(i,0,n) sf(arr[i]);
		//FOR(i,0,n) print(arr[i]);
		int ans=sliding();
		printf("Case %d: %d\n",t,ans);
	}
	return 0;
}
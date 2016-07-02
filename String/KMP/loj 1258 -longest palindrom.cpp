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

#define printArr(a,L,R) FOR(x,L,R) cout << a[x] << (x==(R-1)?'\n':' ')
#define printArrE(a,L,R) FORE(x,L,R) cout << a[x] << (x==R?'\n':' ')
#define printArr2D(a,R,C) FOR(i,0,R) FOR(j,0,C) cout << a[i][j] << (j==(R-1)?'\n':' ')
#define printV(a) printArr(a,0,a.size()-1)

#define ALL(c) (c).begin(), (c).end()
#define PB push_back
#define MP make_pair
#define uu first
#define vv second
#define left  (2*i)
#define right (2*i+1)

#define MAX 1000005

char T[MAX], P[MAX]; // T = text, P = pattern
int b[MAX], n, m; // b = back table, n = length of T, m = length of P


void kmpPreprocess() 
{
	int i = 0, j = -1; b[0] = -1; 
	while (i < m) 
	{
		while (j >= 0 && P[i] != P[j]) j = b[j]; // if different, reset j using b
		i++; j++; // if same, advance both pointers
		b[i] = j; 
	} 
}           
int kmpSearch() 
{ 
	int cnt=0;
	kmpPreprocess();
	int i = 0, j = 0; 
	while (i < n) 
	{
		while (j >= 0 && T[i] != P[j]) j = b[j]; // if different, reset j using b
		i++; j++; // if same, advance both pointers
	} 
	return n+ (i-j);
}


int main() 
{
	READ;
	int TT;
	sf(TT);
	getchar();
	for(int t=1; t<=TT; t++)
	{
		scanf("%s",T);
		n = (int)strlen(T);

		FOR(i,0,n)
			P[n-1-i]=T[i];
		P[n]=NULL;
				
		m = (int)strlen(P);

		if(strcmp(P,T)!=0)
			printf("Case %d: %d\n",t,kmpSearch());
		else
			printf("Case %d: %d\n",t,n);
	}

	return 0;
}
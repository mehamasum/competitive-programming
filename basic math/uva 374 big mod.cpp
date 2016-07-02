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

using namespace std;

#define space <<" "<<
#define el <<endl
#define NL "\n"
#define pf printf
#define put cout<<

#define MAX 10005

int mod(int b, int p, int m)
{
	//put b space p space m el;
	if(p==0) return 1;
	if(p%2==0)
	{
		int first= mod(b,p/2,m)%m;
		return (first*first)%m;
	}
	else
	{
		int first= b%m;
		int second= mod(b,p-1,m)%m;
		return (first*second)%m;
	}
}

int main()
{
	READ;
	int b, p, m;
	while(cin>>b>>p>>m)
		cout<<mod(b,p,m) el;
	return 0;
}

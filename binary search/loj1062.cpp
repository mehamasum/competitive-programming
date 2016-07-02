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

#define inf 1<<29
#define EPS 1e-7
const double PI = acos(-1.0);
const double EulerConstant = std::exp(1.0);

#define FREOPEN freopen("input.txt","r",stdin)

using namespace std;

double x, y, c;

double BS(double lo, double hi)
{
	double d;
	for(int i=0;i<100;i++)
	{
		d=(lo+hi)/2;
		double a=sqrt(x*x-d*d);
		double b=sqrt(y*y-d*d);
		double c1=a*b/(a+b);
		if(c1>c)
			lo=d;
		else
			hi=d;
	}
	return d;
}

int main()
{
	//FREOPEN;

	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++)
	{
		scanf("%lf %lf %lf", &x, &y, &c);
		double maxm=max(x,y);
		printf("Case %d: %0.8lf\n",t,BS(0,maxm));
	}
	return 0;
}
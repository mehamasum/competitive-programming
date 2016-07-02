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

double BS(double p,double q,double r,double s,double t,double u)
{
	double hi ,lo, T, x;
	lo=0;
	hi=1;
	while(lo<=hi)
	{
		x=lo+(hi-lo)/2;
		T=p*pow(EulerConstant,-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
		if(fabs(T-0.0)<=EPS) return x;
		else if(T>0.0) lo=x;
		else hi=x;
	}
}
int main()
{
	double p,q,r,s,t,u,x;
	while(scanf("%lf %lf %lf %lf %lf %lf",&p,&q,&r,&s,&t,&u)!=EOF)
	{
		double t1,t2;
		x=0;
		t1=p*pow(EulerConstant,-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;

		x=1;
		t2=p*pow(EulerConstant,-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x+ u;

		if(t1>0 && t2>0 || t1<0 && t2<0) printf("No solution\n");
		else if(p==0 && q==0 &&r==0 &&s==0 &&t==0 &&u==0) printf("0.0000\n");
		else if(p==0 && q==0 &&r==0 &&s==0) printf("%0.4lf\n",sqrt(-1*u/t));
		else
		{
			double ans=BS(p,q,r,s,t,u);
			printf("%0.4lf\n",ans);
		}
	}
	return 0;
}
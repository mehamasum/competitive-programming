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

const double PI = acos(-1.0);
#define EPS 1e-11

long double area(double d,double x1,double y1,double r1,double x2,double y2,double r2)
{
	if (d>=r1+r2+EPS) return 0;
	//if (d< r1+r2+EPS) return 0;
	if(d< fabs(r1-r2)+EPS)
	{
		double r=min(r1,r2);
		return PI*r*r;
	}
	long double CAD= 2* acos( (r1*r1 + d*d -r2*r2)/(2*r1*d));
	long double  CBD= 2* acos( (r2*r2 + d*d -r1*r1)/(2*r2*d));
	long double A,B,C,D;
	A=0.5*CBD*r2*r2;
	B=0.5*r2*r2*sin(CBD);
	C=0.5*CAD*r1*r1;
	D=0.5*r1*r1*sin(CAD);
	return (A - B) + (C - D);
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output_my.txt","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		double x1, y1, r1, x2, y2, r2;
		cin >>x1 >>y1 >>r1 >>x2 >>y2 >>r2;
		long double d= sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
		printf("Case %d: %.10Lf\n",i,area(d,x1, y1, r1, x2, y2, r2));
	}
	return 0;
}



#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define EPS 1e-4
double bsearch(double x, double y, double c)
{
	double hi=x<y?x:y,lo=0;
	double d,t1,t2,C;
	while(lo<=hi)
	{
		d=lo+(hi-lo)/2;
		t1=1/sqrt(x*x-d*d);
		t2=1/sqrt(y*y-d*d);
		C=1/(t1+t2);
		if(C>=c) {if(fabs(C-c)<=EPS) return d; lo=d;}
		else hi=d;
	}
}
int main()
{
	double x,y,c;
	while(scanf("%lf %lf %lf",&x,&y,&c)==3)
	{
		printf("%0.3lf\n",bsearch(x,y,c));
	}
	return 0;
}
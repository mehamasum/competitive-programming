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

#define EPS 1e-7

double area(double a, double b, double c)
{
	double s= (a+b+c)/2.0;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main()
{
	int T;
	scanf("%d",&T);

	for(int t=1;t<=T;t++)
	{
		double AB, AC, BC, r;
		double s, tol, h, a1, a2, AD, AE, DE;
		double aADE, aBDEC, r1;

		scanf("%lf %lf %lf %lf", &AB, &AC, &BC, &r);

		tol= area(AB, AC, BC);
		
		double lo=0, hi=AB;

		for(int i=0; i<1000; i++)
		{
			AD=(lo+hi)/2;

			AE=AC*AD/AB;
			DE=BC*AD/AB;

			aADE= area(AD,DE,AE);
			aBDEC= tol- aADE;

			r1=aADE/aBDEC;
			if(r1<r)
				lo=AD;
			else
				hi=AD;
		}
		printf("Case %d: %0.10lf\n",t,AD);
	}
}
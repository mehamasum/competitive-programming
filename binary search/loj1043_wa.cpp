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

int main()
{
	int T;
	scanf("%d",&T);

	for(int t=1;t<=T;t++)
	{
		double AB, AC, BC, r;
		double s, area, h, a1, a2, AD, AE;
		double aADE, aBDEC, r1;

		scanf("%lf %lf %lf %lf", &AB, &AC, &BC, &r);

		s=(AB+BC+AC)/2.0;
		area=sqrt(s*(s-AB)*(s-BC)*(s-AC));
		h=2.0*sqrt(s*(s-AB)*(s-BC)*(s-AC))/BC;

		a1=acos(h/AB);
		a2= acos(h/AC);

		double lo=0, hi=AB;

		for(int i=0; i<1000; i++)
		{
			AD=(lo+hi)/2;

			AE=AC*AD/AB;
			aADE= 0.5*AD*AE*sin(a1+a2);
			aBDEC= area- aADE;
			r1=aADE/aBDEC;
			if(r1<r)
				lo=AD;
			else
				hi=AD;
		}

		printf("Case %d: %0.8lf\n",t,AD);
	}
}
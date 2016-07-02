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

#define inf 1<<29
#define EPS 1e-7
const double PI = acos(-1.0);
const double EulerConstant = std::exp(1.0);

#define FREOPEN freopen("input.txt","r",stdin)


using namespace std;


int main()
{
	//FREOPEN;
	int T;
	scanf("%d",&T);

	for(int t=1;t<=T;t++)
	{
		double R, r, n, tol;
		scanf("%lf %lf", &R, &n);
		double lo=0, hi=R/2;
		for(int i=0;i<1000;i++)
		{
			r=(lo+hi)/2.0;
			
			tol=2*n*asin(r/(R-r));
			if(tol<2.0*PI)
				lo=r;
			else 
				hi=r;
		}
		printf("Case %d: %0.10lf\n",t,r);
	}
}
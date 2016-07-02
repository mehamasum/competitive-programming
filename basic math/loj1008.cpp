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
	scanf("%d", &T);
	for(int t=1; t<=T; t++)
	{
		long long s;
		scanf("%lld", &s);

		long long n, temp, sqrtS=sqrt(s*1.0);
		long long row, col;

		if(s==sqrtS*sqrtS)
			n=ceil(sqrtS*1.0);
		else
			n=ceil(sqrtS*1.0)+1;

		temp=s-sqrtS*sqrtS;
		if(temp==0)
		{
			if(s%2==1)
			{
				col=1;
				row=sqrtS;
			}
			else
			{
				col=sqrtS;
				row=1;
			}
		}
		else
		{
			long long first=s-(temp-1);
			long long partn= (2*n-1)/2;

			if(n%2==0)
			{
				if(temp<=partn)
				{
					row=n;
					col=temp;
				}
				else
				{
					col=n;
					row=2*n-temp;
				}
			}
			else
			{
				if(temp<=partn)
				{
					col=n;
					row=temp;
				}
				else
				{
					row=n;
					col=2*n-temp;
				}

			}

		}

		printf("Case %d: %lld %lld\n",t,col, row);
	}
	return 0;
}
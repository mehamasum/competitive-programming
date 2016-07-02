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

#define FRE freopen("C:\\Users\\User\\Desktop\\input.txt","r",stdin)

using namespace std;

int con( int dec)
{
	int rem, sum=0, i=1;
	do
    {
        rem=dec%2;
        sum=sum + (i*rem);
        dec=dec/2;
        i=i*10;
    }while(dec>0);

	return sum;
}

int main()
{
	FRE;
	int T;
	scanf("%d", &T);
	getchar();
	for(int t=1; t<=T; t++)
	{
		char dec[100];
		gets(dec);
		int a, b, c ,d;
		sscanf(dec,"%d.%d.%d.%d",&a,&b,&c,&d);

		char bi[100];
		gets(bi);
		int p,q,r,s;
		sscanf(bi,"%d.%d.%d.%d",&p,&q,&r,&s);
	
		int flag=0;
		if(con(a)==p)
			if(con(b)==q)
				if(con(c)==r)
					if(con(d)==s)
						flag=1;
		
		if(flag==1) printf("Case %d: Yes\n",t);
		else printf("Case %d: No\n",t);
		
	}
	return 0;
}


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


int points[100005];

int BS(int lo, int hi, int key)
{
	int mid;
	while(lo<=hi)
	{
		if(lo+1==hi)
		{
			//cout<<"lo:"<<lo<<" hi:"<<hi<<endl;
			if(points[lo]==key) return lo;
			if(points[hi]==key) return hi;
			return hi;
		}

		mid=lo+(hi-lo)/2;
		if(points[mid]==key) return mid;


		if(points[mid]>key)
			hi=mid;
		else
			lo=mid;
	}
}

int BS1(int lo, int hi, int key)
{
	int mid;
	while(lo<=hi)
	{
		if(lo+1==hi)
		{
			//cout<<"lo:"<<lo<<" hi:"<<hi<<endl;
			if(points[lo]==key) return lo;
			if(points[hi]==key) return hi;
			return lo;
		}

		mid=lo+(hi-lo)/2;
		if(points[mid]==key) return mid;


		if(points[mid]>key)
			hi=mid;
		else
			lo=mid;
	}
}

int main()
{
	//FRE;
	int T;
	scanf("%d", &T);
	points[0]=-1;
	for(int t=1; t<=T; t++)
	{
		printf("Case %d:\n",t);
		int n, q;
		scanf("%d %d",&n, &q);
		for(int i=1;i<=n;i++)
		{
			scanf("%d", points+i);
		}
		points[n+1]=-1;
		for(int i=0;i<q;i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);

			if(a==b) 
			{
				int found=0;
				for(int i=1;i<=n;i++)
				{
					if(points[i]==a) 
					{
						found=1;
						break;
					}
				}
				printf("%d\n",found);
			}
			else
			{
				int loc1=BS(0,n+1,a); //cout<<">loc1 "<<loc1<<" "<<points[loc1]<<endl;
				int loc2=BS1(0,n+1,b); //cout<<">loc2 "<<loc2<<" "<<points[loc2]<<endl;
				int diff=loc2-loc1;
				//if(diff<0) diff=-diff;


				if(loc1==loc2) printf("1\n");
				else if(loc1==0) printf("%d\n",diff);
				else if(diff<0) printf("0\n");
				else printf("%d\n",diff+1);
			}
		}
	}
	return 0;
}


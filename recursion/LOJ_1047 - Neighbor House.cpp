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

#define N 25
#define INF 1<<28
int T,n;
int RGB[N][3];
int COST[N][3];

#define left(i) ((i+1)%3)
#define right(i) ((i+2)%3)

int sum(int level, int color)
{
	if(level==n) return 0;
	int basecost=RGB[level][color];
	if(!COST[level][color])
	{
		int t1=sum(level+1,left(color));
		int t2=sum(level+1,right(color));
		int t=min(t1,t2);
		COST[level][color]=basecost+t;
		return COST[level][color];
	}
	return COST[level][color];
}

int main()
{
	//freopen("input.txt","r",stdin);
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			memset(RGB[i],0,sizeof RGB[i]);
		for(int i=0;i<n;i++)
			memset(COST[i],0,sizeof COST[i]);

		for(int i=0;i<n;i++)
			for(int j=0;j<3;j++)
				cin>>RGB[i][j];
		int base,temp,min=INF,baselevel=1;
		for(int i=0;i<n;i++)
		{
			base=RGB[0][i];
			temp=sum(baselevel,left(i));
			if(base+temp<min) min=base+temp;

			temp=sum(baselevel,right(i));
			if(base+temp<min) min=base+temp;
		}
		cout<<"Case "<<t<<": "<<min<<endl;
	}
	return 0;
}


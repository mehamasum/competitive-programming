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
#define inf 1<<29

char age[1000005];
int main()
{	
	while(1)
	{
		if(gets(age)<=0) break;
		int digit,sum=0,flag=0,m=0;
		int size=strlen(age);
		reverse(age,age+size);
		for(int j=0;j<size;j++)
		{
			if(age[j]>=0 && age[j]<=57) digit=age[j]-48;
			else digit=age[j]-55;
			m=max(digit,m);
			sum+=digit;
		}
		int k=m;
		if(k<=1) k=1;
		for(;k<=36;k++)
		{
			if (sum%k==0) {flag=1; printf("%d\n",k+1); break;}
		}
		if(flag==0) printf("No solution.\n");
	}
	return 0;
}
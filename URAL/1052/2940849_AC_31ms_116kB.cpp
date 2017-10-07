#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	struct point
	{
		int x,y;
	};
	struct point a[205];
	int n,cnt,ans;
	while(scanf("%d",&n)==1)
	{
		memset(a,0,sizeof a);
		cnt=0;
		ans=0;
		int i,j,k;
		for(i=0;i<n;i++)
			scanf("%d %d",&a[i].x,&a[i].y);
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				cnt=0;
				for(k=j+1;k<n;k++)
				{
					if( (a[k].y-a[i].y)*(a[i].x-a[j].x)==(a[i].y-a[j].y)*(a[k].x-a[i].x) ) cnt++;
					ans=max(cnt,ans);
				}
			}
		}
		printf("%d\n",ans+2);
	}
	return 0;
}
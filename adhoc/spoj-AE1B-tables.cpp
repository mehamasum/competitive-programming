#include <stdio.h>
#include <stdlib.h>
#define N 1005
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int main()
{
	//freopen("input.txt","r",stdin);
	int n,s,t,i;
	while(scanf("%d %d %d",&n,&s,&t)==3)
	{
		int total= s*t;
		int a[N]={0};
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		qsort(a, n, sizeof(int), compare);
		int sum=0,step=0;
		for(i=n-1;i>=0;i--)
		{
			sum+=a[i];
			step++;
			if(sum>=total) break;
		}
		printf("%d\n",step);
	}
	return 0;
}

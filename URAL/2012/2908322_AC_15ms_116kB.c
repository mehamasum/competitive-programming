#include <stdio.h>
#define N 12
#define T 4*60
int main()
{
	int f;
	while(scanf("%d",&f)==1)
	{
		int left=N-f;
		int time=left*45;
		if(time>T) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}

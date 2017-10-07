#include <stdio.h>

int main()
{
	int n,k;
	while(scanf("%d %d",&n,&k)==2)
	{
		int pure,de,temp;
		pure=(k-1)*(k-1);
		de=(k-1);
		for(int i=3;i<=n;i++)
		{
			temp=pure;
			pure=pure*(k-1)+de*(k-1);
			de=temp;
		}
		printf("%d\n",pure+de);
	}
	return 0;
}
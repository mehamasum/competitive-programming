#include <stdio.h>
#include <time.h>
double a,b,c=0;
void O_N(int n)
{
	a=clock();
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) for(int k=0;k<n;k++) c++;
	//c++;
	b= clock();
	printf("%.10lf\n",(b-a)/CLOCKS_PER_SEC);
}

void ex(int n)
{
	a=clock();
	int r=1,t=10;
	while(n)
	{
		if(n%2==1) r*=t;
		n/=2;
		t*=t;
	}
	b= clock();
	printf("%.10lf\n",(b-a)/CLOCKS_PER_SEC);
}
int main()
{
	freopen("output.txt","w",stdout);
	for(int j=10;j<=1000000 ;j*=10)
		ex(j);
	return 0;
}

#include <stdio.h>
int main()
{
   int count, number;
   scanf("%d",&count);
   for(int i = 0; i < count; ++i) 
   {
      scanf("%d",&number);
	  if(number==0) printf("0\n");
	  else if(number==1) printf("0\n");
	  else
	  {
		  int sum = 1;
		  for (int j = 2; j*j<=number; j++) 
		  {
			  if (number%j==0)
			  {
				  sum+=j;
				  sum+= number/j;
			  }
			  if (j*j==number) sum-=j;
		  }
		  printf("%d\n",sum);
	  }

	}
   return 0;
}
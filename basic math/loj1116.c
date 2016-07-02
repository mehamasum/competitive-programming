#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    int t;
    for(t=1;t<=T;t++)
    {
        long long w, m, n;
        scanf("%lld", &w);
        if(w%2==1)
        {
            printf("Case %d: Impossible\n",t);
        }
        else
        {
            for(n=2; ;n+=2)
            {
                m=w/n;
                if(m%2==1 && m*n==w)
                {
                    printf("Case %d: %lld %lld\n",t,m,n);
                    break;
                }
            }

        }


    }
    return 0;
}

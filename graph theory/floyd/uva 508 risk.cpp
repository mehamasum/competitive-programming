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
#define MEMSET(a,b) memset(a,b,sizeof(a));

#define CINd(a) scanf("%d",&a);
#define CINdd(a,b) scanf("%d %d", &a, &b);
#define CINddd(a,b,c) scanf("%d %d %d", &a, &b, &c);

#define CINf(a) scanf("%lf",&a);
#define CINff(a,b) scanf("%lf %lf", &a, &b);
#define CINfff(a,b,c) scanf("%lf %lf %lf", &a, &b, &c);
#define COUT(a) cout<<a<<endl;
using namespace std;

#define space <<" "<<
#define done <<endl

#define MAX 20

int dist[MAX+5][MAX+5];
void floyd()
{
    int i, j, k;
    for( k=1 ; k<=MAX; k++)
        for( i=1 ; i<=MAX; i++)
            for( j=1 ; j<=MAX; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j]= dist[i][k] + dist[k][j];
}


int main()
{
	FRE;
    int n=0, a=0, test=1;
    int i=0,j;
	

    while(scanf("%d", &n)==1)
    {
		if(a==0)
		{
			for(i=1; i<=MAX; i++)
			{
				for(j=1;j<=MAX;j++)
				{
					if(i==j) dist[i][j]=0;
					else dist[i][j]=inf;
				}
			}
		}
        


        a++;
        if(a<20)
        {
			if(n!=0)
			{
				for(i=1;i<=n;i++)
				{
					int b;
					scanf("%d", &b);
					
					dist[a][b]=1;
					dist[b][a]=1;
					//cout<<a<<" "<<b<<" "<<dist[a][b]<<endl;


				}
			}
        }

		
        if(a==20)
        {
			/*for(i=1; i<=MAX; i++)
			{
				cout <<">";
				for(j=1;j<=MAX;j++)
				{
					cout<< dist[i][j] <<" ";
				}
				cout<<endl;
			}*/

            floyd(); /////////////////////////////
			
			/*for(i=0; i<MAX; i++)
			{
				for(j=0;j<5;j++)
				{
					cout << dist[i][j] <<" ";
				}
				cout<<endl;
			}*/
            cout<<"Test Set #"<<test<<endl;
            for(i=1;i<=n;i++)
            {
                int u,v;
                cin>>u>>v;
				printf("%2d to %2d: %d\n",u,v,dist[u][v]);
                //cout<<u<<" to "<<v<<": "<<dist[u][v]<<endl;
            }
            cout <<endl;
            test++;
			a=0;

        }

    }
	return 0;
}
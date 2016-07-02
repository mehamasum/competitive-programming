/* 
 * File:   main.cpp
 * Author: Meha Masum
 * Created on September 23, 2015, 12:06 AM
 */

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

#define LL long long
#define ULL unsigned long long

#define INF (1<<29)
#define EPS 1e-7
const double PI = acos(-1.0);
const double EulerConstant = std::exp(1.0);

#define READ freopen("C:\\Users\\User\\Desktop\\input.txt","r",stdin)
#define MEM(a,b) memset(a,b,sizeof(a));

#define sf(a) scanf("%d",&a);
#define sff(a,b) scanf("%d%d", &a, &b);
#define sfff(a,b,c) scanf("%d%d%d", &a, &b, &c);

#define sd(a) scanf("%lf",&a);
#define sdd(a,b) scanf("%lf%lf", &a, &b);
#define sddd(a,b,c) scanf("%lf%lf%lf", &a, &b, &c);

#define pf printf
#define print(a) printf("%d\n",a);

using namespace std;

#define space <<" "<<
#define endl <<endl
#define put cout<<

#define MAX 10005
#define MOD 10000007

vector<int>G[100];
map <int,int> mymap;

int n,m;

int bfs(int src, int lev) 
{
    int cnt=0;


    queue<int>Q;
    Q.push(src);
    int visited[100] = {0}, level[100];
    int parent[100];
    visited[src] = 1;
    level[src] = 0;
    while (!Q.empty()) 
    {
        int u = Q.front();
		//put u space level[u] space lev-1 endl; 
		if(level[u]<=lev-1)
		{
			for (int i = 0; i < G[u].size(); i++) 
			{
				int v = G[u][i];
				if (!visited[v]) 
				{
					cnt++;
					level[v] = level[u] + 1;
					parent[v] = u;
					visited[v] = 1;
					Q.push(v);
				}
			}
			Q.pop();
		}

		else
			break;
    }
    //put cnt endl;    
    return n-cnt-2;
}

int main(int argc, char** argv)
{
	//READ;
    int caseNo=1;
    while(scanf("%d",&m)==1)
    {
		if(m==0) break;

        n = 1;
		mymap.clear();
		for(int i=0;i<100;i++)
			G[i].clear();


        for (int i = 0; i < m; i++) 
        {
            int a, b;
            sff(a, b);

            if (!mymap[a])
                mymap[a] = n++;
            if (!mymap[b])
                mymap[b] = n++;
            
            G[mymap[a]].push_back(mymap[b]);
			G[mymap[b]].push_back(mymap[a]);

        }
        
		/*for(int i=0; i<110; i++)
		{
			cout << i space mymap[i] endl;
		}

		for(int i=1; i<n; i++)
		{
			for(int j=0; j<G[i].size(); j++)
				cout <<">>" space i space G[i][j] endl;
		}*/

        int s, d;
        while(1)
        {
            sff(s,d);
			if(s==0 && d==0) break;
            pf ("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",caseNo++,bfs(mymap[s],d),s,d);
            
        }

    }
    return 0;
}
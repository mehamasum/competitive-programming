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

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef map<int,string> MAP;
typedef pair<int,int> PII;

#define INF (1<<29)
#define EPS 1e-7
#define PI acos(-1.0)
#define EulerConstant exp(1.0)
#define char2Int(c) (c-'0')

#define READ freopen("C:\\Users\\User\\Desktop\\input.txt","r",stdin)
#define WRITE freopen("C:\\Users\\User\\Desktop\\output.txt","w",stdout)

#define FOR(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FORE(i,L,R) for (int i = L; i <= R; i++)
#define DEC(i,L,R) for (int i = L; i > R; i--)
#define DECE(i,L,R) for (int i = L; i >= R; i--)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) // traverse an STL data structure

#define MEM(a,b) memset(a,b,sizeof(a))
#define SET(a,n,val) FOR(i,0,n) a[i]=val
#define SET2D(a,r,c,val) FOR(i,0,r) FOR(j,0,c) a[i][j]=val

#define SIZE(x) ((int)((x).size()))
#define arrSize(arr) ( sizeof(arr) / sizeof((arr)[0]) )

#define sf(a) scanf("%d",&a)
#define sff(a,b) scanf("%d%d", &a, &b)
#define sfff(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define sd(a) scanf("%lf",&a)
#define sdd(a,b) scanf("%lf%lf", &a, &b)
#define sddd(a,b,c) scanf("%lf%lf%lf", &a, &b, &c)
#define print(a) printf("%d\n",a)
#define sp <<" "<<
#define el <<endl
#define NL "\n"
#define pf printf
#define put cout<<

#define df(a) cerr<<#a<<" = "<<(a)<<endl
#define dff(a,b) cerr<<#a<<" = "<<(a)<<" "<<#b<<" = "<<(b)<<endl
#define dfff(a,b,c) cerr<<#a<<" = "<<(a)<<" "<<#b<<" = "<<(b)<<" "<<#c<<" = "<<(c)<<endl

#define printArr(a,L,R) FOR(i,L,R) cout << a[i] << (i==(R-1)?'\n':' ')
#define printArrE(a,L,R) FORE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printArr2D(a,R,C) FOR(i,0,R) FOR(j,0,C) cout << a[i][j] << (j==(R-1)?'\n':' ')
#define printV(a) printArr(a,0,a.size()-1)

#define ALL(c) (c).begin(), (c).end()
#define PB push_back
#define MP left_pair
#define uu first
#define vv second
#define left  (2*i)
#define right (2*i+1)

#define MAX 100005

int v[105], cnt[105], numberOfCoins[MAX], dp[MAX];
int main()
{
	READ;
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++)
	{
		int n, k, ans=0;
		sff(n, k);
		FOR(i,0,n) sf(v[i]);
		FOR(i,0,n) sf(cnt[i]);
		MEM(dp, 0);
		dp[0] = 1;

		FOR(i,0,n)
		{
			FORE(j,0,k)
			{
				numberOfCoins[j]=0;
			}

			FORE(j,v[i],k)
			{
				if(dp[j]==0 && dp[j-v[i]]==1 && numberOfCoins[j-v[i]]+1<=cnt[i])
				{
					ans++;
					dp[j]=1;
					numberOfCoins[j]=numberOfCoins[j-v[i]]+1;
				}
			}
		}
		printf("Case %d: %d\n",t,ans);
	}
	return 0;
}

//Suppose, I want to check the money between 1 to 6. 
//I have coins 2,3. 
//2 can be used for 2 times.
//The moneys are 1,2,3,4,5,6,7,8,9. 
//Suppose I want to start with coin 2. 
//then I'll iterate through 2 to 9 to check which money I can make with this coin. 
//Initially, You set dp[0]=1.//base case.
//So, for coin 2 , starting from i=2, I can make 2 since dp[2-[present_coin]]==1, i.e, dp[0]=1. 
//then set dp[2]=present coin. dp[2]=2//since number of coins are limited, u will need this to check. 
//now store 1 in an _cnt array since this is the 1st use of coin 2. 
//_cnt array will store how many times a particular coin has been used to make a amount.
//so, dp[2]=2. _cnt[2]=1.
//now, for i=3, I can't make 3 since dp[3-[present_coin]]==0,
//i.e, dp[1]=0 and I couldn't make 1. then leave it. dp[3]=0. _cnt[2]=0.
//for i=4, I can make 4 since dp[4-present_coin]==2, 
//i.e dp[2]=2. Here is a matter, since dp[4-present_coin]==2 that means 2 has been made with a use of present coin. Since number of coins is limited so you have to //check _cnt array to determine whether you can use present coin or you have already used max time.
//since _cnt[2]=1 that means you have used present coin 1 time to make previous amount,2. and if you want to make 4 using present coin then you will used present coin //for _cnt[2]+1=2 times.Since I can use coin 2 for max 2 times so, I can use present coin to make 4. 
//dp[4]=2. _cnt[4]=_cnt[2]+1.//1 for using present coin another time.
//Now, for i=5, I can't make 5 since dp[5-[present_coin]]==0,i.e, dp[3]=0 and I couldn't make 5 using present coin since coin 3 has not been made yet; 
//then leave it. dp[5]=0. _cnt[5]=0.
//For i=6, I can make 6 since dp[6-present_coin]==2, i.e dp[4]=2. Here is a matter, since dp[6-present_coin]==2 
//that means coin 4 has been made with a use of present coin. 
//Since number of coins is limited so you have to check cnt array to determine whether you can use present coin or you have already used max time. 
//Since cnt[4]=4 that means you have used present coin 2 times to make previous amount,4. and if you want to make 6 using present coin then you will used 
//present coin for _cnt[4]+1=3 times,which is not allowed.Since I can use coin 2 for max 2 times so, I can't use present coin to make 6. dp[6]=0. _cnt6]=0.
//The last case, i=6, is very important to understand.
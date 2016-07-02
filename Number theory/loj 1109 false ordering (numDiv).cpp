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
typedef stack<int> SI;

#define INF (1<<29)
#define EPS 1e-7
#define PI acos(-1.0)
#define EulerConstant exp(1.0)
#define char2Int(c) (c-'0')

#define READ freopen("C:\\Users\\User\\Desktop\\input.txt","r",stdin)
#define WRITE freopen("C:\\Users\\User\\Desktop\\output.txt","w",stdout)

#define FRA(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FRAE(i,L,R) for (int i = L; i <= R; i++)
#define FRD(i,L,R) for (int i = L; i > R; i--)
#define FRDE(i,L,R) for (int i = L; i >= R; i--)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) // traverse an STL data structure

#define MEM(a,b) memset(a,b,sizeof(a))
#define SET(a,n,val) FRA(i,0,n) a[i]=val
#define SET2D(a,r,c,val) FRA(i,0,r) FRA(j,0,c) a[i][j]=val

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

#define printArr(a,L,R) FRA(i,L,R) cout << a[i] << (i==(R-1)?'\n':' ')
#define printArrE(a,L,R) FRAE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printArr2D(a,R,C) FRA(i,0,R) FRA(j,0,C) cout << a[i][j] << (j==(R-1)?'\n':' ')
#define printV(a) printArr(a,0,a.size()-1)

#define ALL(c) (c).begin(), (c).end()
#define PB push_back
#define MP make_pair
#define uu first
#define vv second
#define left  (2*i)
#define right (2*i+1)

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))
//void printSet(int x){pf("S=%2d=",x); SI st; while(x) st.push(x%2),x/=2; while(!st.empty()) pf("%d",st.top()),st.pop();pf(NL);}

#define MAX 1005

struct num
{
	int n;
	LL numDiv;
};

num p[MAX];

bool comp(num A, num B)
{
	if(A.numDiv==B.numDiv) return A.n>B.n;
	else return A.numDiv<B.numDiv;
}

LL _sieve_size;
bitset<10000010> bs;   // 10^7 should be enough for most cases
VI primes;   // compact list of primes in form of vector<int>

void sieve(LL upperbound) {          // create list of primes in [0..upperbound]
  _sieve_size = upperbound + 1;                   // add 1 to include upperbound
  bs.set();                                                 // set all bits to 1
  bs[0] = bs[1] = 0;                                     // except index 0 and 1
  for (LL i = 2; i <= _sieve_size; i++) if (bs[i]) {
    // cross out multiples of i starting from i * i!
    for (LL j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
    primes.push_back((int)i);  // also add this vector containing list of primes
} }                                           // call this method in main method

LL numDiv(LL N) {
  LL PF_idx = 0, PF = primes[PF_idx], ans = 1;             // start from ans = 1
  while (N != 1 && (PF * PF <= N)) {
    LL power = 0;                                             // count the power
    while (N % PF == 0) { N /= PF; power++; }
    ans *= (power + 1);                              // according to the formula
    PF = primes[++PF_idx];
  }
  if (N != 1) ans *= 2;             // (last factor has pow = 1, we add 1 to it)
  return ans;
}

int main()
{
	READ;
	int T;
	sf(T);

	sieve(105);
	FRAE(i,1,1000) p[i].n=i, p[i].numDiv=numDiv(i);
	sort(p,p+1001,comp);

	FRAE(t,1,T)
	{
		int n;
		sf(n);
		pf("Case %d: %d\n",t,p[n]);
	}
	return 0;
}
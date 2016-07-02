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
#define space <<" "<<
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
#define MP make_pair
#define uu first
#define vv second
#define left  (2*i)
#define right (2*i+1)
#define abs(x) (x<0?(-x):x)

#define MAX 100005


class DequeEmptyException
{
public:
    DequeEmptyException()
    {
        cout << "Deque empty" << endl;
    }
};

class Node
{
public:
    int data, idx;
    Node* next;
    Node* prev;
};

class Deque
{  
private:
    Node* front;
    Node* rear;
    int count;

public:
    Deque()
    {
        front = NULL;
        rear = NULL;
        count = 0;
    }      
  
    void InsertFront(int element, int i)
    {
        // Create a new node
        Node* tmp = new Node();
        tmp->data = element;
		tmp->idx=i;
        tmp->next = NULL;
        tmp->prev = NULL;

        if ( isEmpty() ) {
            // Add the first element
            front = rear = tmp;
        }
        else {
            // Prepend to the list and fix links
            tmp->next = front;
            front->prev = tmp;
            front = tmp;
        }

        count++;
    }

    int RemoveFront()
    {
        if ( isEmpty() ) {
            throw new DequeEmptyException();
        }

        //  Data in the front node
        int ret = front->data;

        // Delete the front node and fix the links
        Node* tmp = front;
        if ( front->next != NULL )
        {
            front = front->next;
            front->prev = NULL;
        }
        else
        {
            front = NULL;
        }
        count--;
        delete tmp;

        return ret;
    }

    void InsertBack(int element, int i)
    {          
        // Create a new node
        Node* tmp = new Node();
        tmp->data = element;
		tmp->idx= i;
        tmp->next = NULL;
        tmp->prev = NULL;

        if ( isEmpty() ) {
            // Add the first element
            front = rear = tmp;
        }
        else {
            // Append to the list and fix links
            rear->next = tmp;
            tmp->prev = rear;
            rear = tmp;
        }

        count++;
    }

    int RemoveBack()
    {
        if ( isEmpty() ) {
            throw new DequeEmptyException();
        }

        //  Data in the rear node
        int ret = rear->data;

        // Delete the front node and fix the links
        Node* tmp = rear;
        if ( rear->prev != NULL )
        {
            rear = rear->prev;
            rear->next = NULL;
        }
        else
        {
            rear = NULL;
        }
        count--;
        delete tmp;

        return ret;
    }
  
    int Front()
    {          
        if ( isEmpty() )
            throw new DequeEmptyException();

        return front->data;
    }

    int Back()
    {
        if ( isEmpty() )
            throw new DequeEmptyException();

        return rear->data;
    }

	int BackIdx()
    {
        if ( isEmpty() )
            throw new DequeEmptyException();

		return rear->idx;
    }
  
    int Size()
    {
        return count;
    }

    bool isEmpty()
    {
        return count == 0 ? true : false;
    }
};

int n, x, arr[MAX];

bool sliding(int k)
{
	Deque minDQ;
	int cnt=0;
	FOR(i,0,n)
	{
		
		minDQ.InsertFront(arr[i],i);
		//for(deque <PII>::iterator i=minDQ.begin(); i!=minDQ.end(); i++)
			//cout<<(*i).first<<" ";
		//cout<<endl;
		cnt+=arr[i];

		//df(cnt);
		if(cnt>=x) return true;

		if(minDQ.BackIdx()<=i-k+1)
		{
			cnt-=minDQ.Back();
			minDQ.RemoveBack();
		}
	}
	return false;
}

int main() 
{
	READ;
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++)
	{
		sff(n,x);

		FOR(i,0,n) sf(arr[i]);
		int ans=-1;
		FORE(i,1,n)
		{
			bool got=sliding(i);
			//cout<<got<<endl;
			if(got)
			{
				ans=i;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
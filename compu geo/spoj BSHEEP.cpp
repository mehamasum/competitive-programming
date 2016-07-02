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
#define MEM(a,b) memset(a,b,sizeof(a))

#define sf(a) scanf("%d",&a)
#define sff(a,b) scanf("%d%d", &a, &b)
#define sfff(a,b,c) scanf("%d%d%d", &a, &b, &c)

#define sd(a) scanf("%lf",&a)
#define sdd(a,b) scanf("%lf%lf", &a, &b)
#define sddd(a,b,c) scanf("%lf%lf%lf", &a, &b, &c)

#define print(a) printf("%d\n",a)

using namespace std;

#define space <<" "<<
#define endl <<endl
#define NL "\n"
#define pf printf
#define put cout<<

#define MAX 100005


struct Point
{
    int x, y, sheep;
};

Point p0;
vector<int> ans;


Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

void swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

int sqDist(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

double dis(int p1, int q1, int p2, int q2)
{
    double a,b,c,d, dist;
    a=p1, b=q1, c=p2, d=q2;
    dist= sqrt((a - c)*(a - c) + (b - d)*(b - d));
    //cout<< "dis: " space dist endl;
    return dist;
}
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

int compare(const void *vp1, const void *vp2)
{
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;

   int o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (sqDist(p0, *p2) >= sqDist(p0, *p1))? -1 : 1;

   return (o == 2)? -1: 1;
}

double convexHull(Point points[], int n)
{
   // Find the bottommost point
   int ymin = points[0].y, mini = 0;
   for (int i = 1; i < n; i++)
   {
     int y = points[i].y;

     // Pick the bottom-most or chose the left most point in case of tie
     if ((y < ymin) || (ymin == y && points[i].x < points[mini].x))
        ymin = points[i].y, mini = i;
   }

   // Place the bottom-most point at first position
   swap(points[0], points[mini]);


   p0 = points[0];

   //pf("p0= %d\n",p0);

   qsort(&points[1], n-1, sizeof(Point), compare);

   stack<Point> S;
   S.push(points[0]);
   S.push(points[1]);

   for (int i = 2; i < n; i++)
   {
      while (S.size()>1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
         S.pop();
      S.push(points[i]);
   }

    double tol=0;
    int prev_x=INF, prev_y=INF, fx,fy;
   while (!S.empty())
   {
       Point p = S.top();
       if(prev_x!=INF && prev_y!=INF)
       {
           tol += dis(prev_x,prev_y,p.x,p.y);
           //cout <<"tol:" space tol endl;
       }
       else
       {
            fx=p.x, fy=p.y;
       }
        prev_x=p.x;
        prev_y=p.y;
       //cout << p.sheep endl;
       ans.push_back(p.sheep);
       S.pop();
   }
   tol += dis(prev_x,prev_y,fx,fy);
   return tol;
}

int main()
{
	READ;
	int T;
	sf(T);
	Point points[MAX];


	for(int t=1; t<=T; t++)
	{
		getchar();

		int n;
		sf(n);

		//cout << n endl;

		for(int i=0; i<n; i++)
		{
			int a, b;
			sff(a,b);
			points[i].x=a;
			points[i].y=b;
			points[i].sheep=i+1;
		}

        if(n==1)
        {
            if(t!=1)
            {
                pf(NL); pf(NL);
            }
            printf("0.00\n");
            printf("%d",n);
            continue;
        }

	    double tolDist=convexHull(points, n);
        //cout<< "got:" space tolDist endl;

	    if(t!=1)
        {
          pf(NL); pf(NL);
	    }
	    printf("%0.2lf\n",tolDist);
		for(int i=ans.size()-1; i>=0; i--)
		{
			printf("%d ",ans[i]);
		}
		//pf(NL);

	    ans.clear();
	}
    return 0;
}

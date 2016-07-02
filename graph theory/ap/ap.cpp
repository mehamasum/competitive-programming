#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define NIL -1
#define inf 1e17

int v,e;
int color[MAX],parent[MAX];
int discovery[MAX],final[MAX];
int low[MAX], ap[MAX], bridge[MAX][MAX];
int timer=0;
vector<int>G[MAX];

void DFS_visit(int i)
{
	int child=0;
	color[i]=GRAY;
	timer++;
	discovery[i]=timer;
	low[i]= discovery[i];

	for(int j=0;j<G[i].size();j++)
	{
		int w=G[i][j];

		if(color[w] == WHITE)
		{
			child++;
			parent[w]=i;
			DFS_visit(w);

			low[i] = min(low[i], low[w]);

			if (low[w] == discovery[w])
                bridge[i][w]=1;

            if (parent[i]!=NIL && discovery[i]<=low[w])
				ap[i]=1;
            
            else if(parent[i]==NIL && child>1)
				ap[i]=1;
		}

		else if(parent[i] != w)
			low[i] = min(low[i], discovery[w]);
	}

	color[i]=BLACK;
	timer++;
	final[i]=timer;
}


void DFS()
{
	for(int i=1;i<=v;i++)
        for(int j=1;j<=v;j++)
            bridge[i][j]=0;
        
	for(int i=1;i<=v;i++)
	{
		color[i] = WHITE;
		parent[i]=NIL;
		low[i]=inf;
		final[i]=inf; 
		discovery[i]=inf;
		ap[i]=0;
	}

	for(int i=1;i<=v;i++)
		if(color[i]==WHITE)
			DFS_visit(i);
}


int main()
{
	freopen("C:\\Users\\User\\Desktop\\input.txt","r",stdin);
	cin >> v >>e;
	for(int i=0; i<e; i++)
	{
		int a, b;
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	DFS();

	cout<< "Articulation points: ";
	for(int i=1; i<=v; i++)
		if(ap[i])
			cout<< i << " ";
	cout<<endl;


	cout<< "Bridges: " <<endl;
	for(int i=1; i<=v; i++)
		for(int j=1;j<=v;j++)
			if(bridge[i][j])
				cout<< i << "-"<< j <<" ";
	cout<<endl;

	return 0;
}



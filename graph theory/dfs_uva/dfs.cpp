#define WHITE 0
#define GRAY 1
#define BLACK 2

int v,e;
int color[MAX],parent[MAX];
int discovery[MAX],final[MAX];
int timer=0;

vector<int>G[MAX];


void DFS_visit(int i)
{
	color[i]=GRAY;
	timer++;
	discovery[i]=timer;
	for(int j=0;j<G[i].size();j++)
	{
		int u=G[i][j];
		if(color[u]==WHITE)
		{
			parent[u]=i;
			DFS_visit(u);
		}
	}
	color[i]=BLACK;
	timer++;
	final[i]=timer;
}
void DFS()
{
	for(int i=1;i<=v;i++)
		if(color[i]==WHITE)
			DFS_visit(i);
}
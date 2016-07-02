#define WHITE 0
#define GRAY 1
#define BLACK 2

int v,e;
int color[MAX];
int timer=0;

vector<int> G[MAX], GG[MAX]; //GG reverse graph

struct node 
{
	int no;
	int fin_time;

	node()
	{
		no=0;
		fin_time=0;
	}
};

struct node n[MAX];

bool compare(struct node a, struct node b)
{
	return a.fin_time < b.fin_time;
}

void DFS_visit(int i)
{
	color[i]=GRAY;
	timer++;
	for(int j=0;j<G[i].size();j++)
	{
		int u=G[i][j];
		if(color[u]==WHITE)
			DFS_visit(u);
	}
	color[i]=BLACK;
	timer++;
	n[i].fin_time=timer;
}

int comp_no=1;
int comp[MAX];

void DFS_visit2(int i)
{
	//cout<<i<<" ";
	comp[i]=comp_no;
	color[i]=GRAY;
	timer++;
	for(int j=0;j<GG[i].size();j++)
	{
		int u=GG[i][j];
		if(color[u]==WHITE)
		{
			
			DFS_visit2(u);
		}
	}
	color[i]=BLACK;
}

void DFS()
{
	timer=0;
	for(int i=1;i<=v;i++)
	{
		if(color[i]==WHITE)
			DFS_visit(i);
	}
}

void DFS2()
{
	int cnt=0;
	timer=0;
	for(int i=v;i>=1;i--)
	{
		int j=n[i].no;
		if(color[j]==WHITE)
		{
			/*cout<<j<<": ";*/
			DFS_visit2(j);
			comp_no++;
			//cout<<endl;
		}
	}
}


int main()
{
	for(int i=1;i<=v;i++)
	{
		n[i].no=i;
	}

	int a,b;
	
	for(int i=0;i<e;i++)
	{
		CINdd(a,b);

		G[a].push_back(b);
		GG[b].push_back(a);	
	}

	DFS();

	MEMSET(color,0);

	sort(n,n+v+1,compare);
	
	DFS2();
}
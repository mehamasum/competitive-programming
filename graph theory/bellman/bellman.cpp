#define MAXN 1005
#define MAXE 2005

int v,e;
int d[MAXN];
int edge_u[MAXE],edge_v[MAXE],edge_cost[MAXE];
bool neg_cycle;

for(int i=1;i<=v;i++) 
	d[i]=inf;
d[1]=0; //distance to source is 0
		
for(int i=1;i<=e;i++)
	cin>>edge_u[i]>>edge_v[i]>>edge_cost[i];


void bellman()
{
	neg_cycle=false;
	for(int i=1;i<=v;i++)
	{
		bool updated=false;
		for(int j=1;j<=e;j++)
		{
			int a=edge_u[j],b=edge_v[j];
			if(d[a]+edge_cost[j]<d[b])
			{
				updated=true;
				if(i==v) 
					neg_cycle=true;
				d[b]=d[a]+edge_cost[j];
			}
		}
		if(updated==false)
			break;
	}
}
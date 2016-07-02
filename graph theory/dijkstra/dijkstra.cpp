#define MAX 5005

vector <int> g[MAX],cost[MAX];
struct node
{
    int u,d;
    node(int a,int b){u=a; d=b;}
    bool operator < ( const node& p ) const { return d > p.d; } //smallest first
};
int d[MAX],par[MAX];
int dijkstra(int n)
{
    memset(d,63,sizeof(d)); 
    memset(par,-1,sizeof(par));
    priority_queue <node> q;
    q.push(node(1,0));
    d[1]=0;
    while(!q.empty())
    {
        node top=q.top(); q.pop();
        int u=top.u;
        
        if(u==n) return d[n];
        for(int i=0;i<(int)g[u].size();i++)
        {
            int v=g[u][i];
            if(d[u]+cost[u][i]<d[v])
            {
                d[v]=d[u]+cost[u][i];
                par[v]=u;
                q.push(node(v,d[v]));
            }
        }
    }
    return -1;
}

int main(){
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int u,v;
        int w;
        cin>>u>>v>>w;
        g[u].push_back(v);
        g[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
        
    }
    int ret=dijkstra(n);
    if(ret==-1) puts("No path!");
    else
    {
        int u=n;
        vectorout;
        while(u!=-1)
        {
            out.push_back(u);
            
            u=par[u];
            
        }
        reverse(out.begin(),out.end());
        for(int i=0;i&lt;(int)out.size();i++)
           cout<<out[i]<<endl;
        puts("");
        
    }
}

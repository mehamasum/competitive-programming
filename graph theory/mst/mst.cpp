struct edge
{
	int u,v,w;
	bool operator < (const edge& obj) const
	{
		return w > obj.w; 
	}
};

int par[MAX];

vector <edge> e;

int parent(int r)
{
	return (par[r]==r) ? r: parent(par[r]);
}

int mst(int n)
{
	//sort
	sort(e.begin(), e.end());

	//initialize disjoint set
	for(int i=1; i<=n; i++)
		par[i]=i;

	int count=0, sum=0;
	for(int i=0;i<e.size();i++)
	{
		int u= parent(e[i].u);
		int v= parent(e[i].v);

		if(u!=v)
		{
			//union
			par[u]=v;

			count++;
			sum+=e[i].w;
			if(count==n-1) break;

		}
	}

	return sum;

}

int main()
{
	int n,m;
	cin>>n>>m;

	for(int i=1; i<=m; i++)
	{
		edge input;
		cin>> input.u >>input.v >> input.w;
		e.push_back(input);
	}

	cout<< mst(n) <<endl;
}
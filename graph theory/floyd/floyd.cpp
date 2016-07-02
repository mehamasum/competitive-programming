void floyd()
{
    int i, j, k;
    for( k=1 ; k<=v; k++)
        for( i=1 ; i<=v; i++)
            for( j=1 ; j<=v; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j]= dist[i][k] + dist[k][j];
                	next[i][j]= next[i][k]; //for saving the path
                }
}

for(i=1; i<=MAX; i++)
{
	for(j=1;j<=MAX;j++)
	{
		if(i==j) dist[i][j]=0;
		else dist[i][j]=inf;
	}
}


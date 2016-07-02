#define MAX 15
#define MAXBIT  1 <<MAX

int dist[MAX][MAX], dp[MAX][MAXBIT]; 

int tsp(int pos, int bitmask) 
{ 
	if (bitmask == (1 << (n)) - 1)
		return dist[pos][0]; 
	if (dp[pos][bitmask] != -1)
		return dp[pos][bitmask];

	int ans = INF;
	for (int nxt = 0; nxt < n; nxt++)
		if (nxt != pos && !(bitmask & (1 << nxt))) 
			ans = min(ans, dist[pos][nxt] + tsp(nxt, bitmask | (1 << nxt)));
	return dp[pos][bitmask] = ans;
}
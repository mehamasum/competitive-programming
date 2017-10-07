#include <cstdio>
#include <iostream>
#include <map>

#define READ freopen("C:\\Users\\mehamasum\\Desktop\\input.txt","r",stdin)
#define WRITE freopen("C:\\Users\\mehamasum\\Desktop\\output.txt","w",stdout)

using namespace std;

int main()
{
    READ;

	int T, K, M;
	map <char, double> cost;

	string line="";

	char c;
	double v, total=0;

	cin >> T;
	while(T--)
	{
		cin >> K;
		for(int i = 0; i < K; i++){
			cin >> c >> v;
			cost[c] = v;
		}

		cin >> M;
		cin.ignore();

		for(int i = 0; i < M; i++){

			getline(cin, line);
			int l = line.size();

			for(int j = 0; j < l; j++){
				total += cost[line[j]];
			}
		}

		total /= 100;
		printf("%0.2lf$\n", total);

		cost.clear();
        total = 0;
	}

	return 0;
}

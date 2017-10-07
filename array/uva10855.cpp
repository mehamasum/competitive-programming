#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define MAX 1000

char big[MAX][MAX], small[MAX][MAX];

int submat(int n, int m)
{
    int cnt = 0;
    for(int i = 0; i < n-m+1; i++)
    {
        for(int j = 0; j < n-m+1; j++)
        {
            int flag = 1;
            for(int k = 0; k < m; k++)
            {
                for(int l = 0; l < m; l++)
                {
                    if(big[i+k][j+l] != small[k][l]) {
                        flag = 0;
                        break;
                    }
                }

                if(flag==0) break;
            }
            if(flag==1)
                cnt++;
        }
    }
    return cnt;
}

void rotate(int n)
{
    char tmp[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            tmp[i][j] = small[n-j-1][i];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            small[i][j] = tmp[i][j];
    }
}
int main()
{
    freopen("../input.txt", "r", stdin);

    int n, m;

    while(1)
    {
        cin >> n >> m;
        if(n == 0 && m == 0)
            break;

        for(int i = 0; i < n; i++)
            cin >> big[i];
        for(int i = 0; i < m; i++)
            cin >> small[i];

        printf("%d ", submat(n, m));

        rotate(m);
        printf("%d ", submat(n, m));

        rotate(m);
        printf("%d ", submat(n, m));

        rotate(m);
        printf("%d\n", submat(n, m));


    }
    return 0;
}

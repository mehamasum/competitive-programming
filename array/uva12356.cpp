#include<cstdio>
#include<iostream>

using namespace std;

#define MAX 100010

int main()
{
    freopen("../input.txt", "r", stdin);
    int S, B, L, R;

    int left[MAX];
    int right[MAX];

    while(1)
    {
        cin >> S >> B;

        if(S == 0 & B == 0) break;

        for(int i = 0; i <= S; i++)
        {
            left[i] = i - 1;
            right[i] = i + 1;
        }

        for(int i = 0; i < B; i++)
        {
            cin >> L >> R;

            if(left[L] < 1) printf("* ");
            else printf("%d ", left[L]);

            if(right[R] > S) printf("*\n");
            else printf("%d\n", right[R]);

            //linking

            left[right[R]] = left[L];
            right[left[L]] = right[R];
        }
        printf("-\n");
    }
}

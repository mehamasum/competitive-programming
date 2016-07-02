int n = 9, A[] = { 4, -5, 4, -3, 4, 4, -4, 4, -5 };   // a sample array A
int kadane1D()
{
    int running_sum = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (running_sum + A[i] >= 0)
        {
            running_sum += A[i];
            ans = max(ans, running_sum);
        }
        else
            running_sum = 0;
    }

    return ans;
}

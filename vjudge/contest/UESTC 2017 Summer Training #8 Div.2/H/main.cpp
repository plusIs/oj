#include <bits/stdc++.h>
using namespace std;
int dp[1000005];
struct surf
{
    int m, f, w;
} data[300005];
bool cmp(const surf &a, const surf &b)
{
    return a.m > b.m;
}
int main()
{
    int n, maxF = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d%d", &data[i].m, &data[i].f, &data[i].w);
    }
    sort(data, data + n, cmp);

    for (int i = 0; i < n; ++i)
    {
        //printf("%d %d %d\n", data[i].m, data[i].f, data[i].w);
        dp[data[i].m] = data[i].f;
        if (data[i].m + data[i].w <= data[0].m)
            dp[data[i].m] += dp[data[i].m + data[i].w];
        maxF = max(maxF, dp[data[i].m]);
        dp[data[i].m] = maxF;
        if (i != n - 1)
        {
            for (int j = data[i].m - 1; j > data[i + 1].m; --j)
            {
                dp[j] = dp[data[i].m];
            }
        }

    }
    printf("%d\n", maxF);
    return 0;
}

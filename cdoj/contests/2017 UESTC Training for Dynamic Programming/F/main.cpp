#include <bits/stdc++.h>
using namespace std;
#define MAXN 505
#define MAXB 505

int dp[1005][1005], data[1005][1005];

int main()
{
    //freopen("data.in", "r", stdin);
    int n, m, ret = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            scanf("%d", &data[i][j]);
    }
    dp[1][1] = data[1][1];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            ret = max(ret, dp[i][j]);
            //printf("%d ", dp[i][j]);
            if (dp[i][j] > 0)
            {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + data[i + 1][j]);
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + data[i][j + 1]);
                dp[i + 1][j + 2] = max(dp[i + 1][j + 2], dp[i][j] + data[i + 1][j + 2]);
                dp[i + 2][j + 1] = max(dp[i + 2][j + 1], dp[i][j] + data[i + 2][j + 1]);
            }
        }
        //putchar('\n');
    }
    printf("%d\n", ret);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define MAXN 505
#define MAXM 100005
int c[MAXN], w[MAXN];
int dp[MAXM], bucket[MAXN];

int main()
{
    //freopen("data.in", "r", stdin);
    int n, m, maxTmp = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &c[i], &w[i]);
        if (c[i] <= m)
            bucket[c[i]] = max(bucket[c[i]], w[i]);
    }

    n = 0;
    for (int i = 1; i < m; ++i)
    {
        if (bucket[i] > maxTmp)
        {
            maxTmp = bucket[i];
            c[n] = i;
            w[n] = bucket[i];
            ++n;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = c[i]; j <= m; ++j)
            dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
    }
    printf("%d", dp[m]);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define MAXN 20005
#define MAXM 10005
int t[MAXN], c[MAXN], w[MAXN];
int dp[MAXM];
int main()
{
    //freopen("data.in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d%d%d", &t[i], &w[i], &c[i]);
    for (int i = 0; i < n; ++i)
    {
        if (t[i] == 1)
        {
            for (int j = c[i]; j <= m; ++j)
                dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
        }
        else
        {
            for (int j = m; j >= c[i]; --j)
                dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
        }
    }
    printf("%d\n", dp[m]);
    return 0;
}
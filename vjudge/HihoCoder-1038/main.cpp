#include <bits/stdc++.h>
using namespace std;
#define MAXN 505
#define MAXM 100005
int c[MAXN], w[MAXN], key[MAXN];
int dp[MAXM];

int main()
{
    freopen("data.in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &c[i], &w[i]);

    for (int i = n - 1; i >= 0; --i)
        key[i] = c[i] + key[i + 1];
    for (int i = 0; i < n; ++i)
    {
        for (int j = m; j >= max(c[i], m - key[i]); --j)
            dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
    }
    printf("%d", dp[m]);
    return 0;
}

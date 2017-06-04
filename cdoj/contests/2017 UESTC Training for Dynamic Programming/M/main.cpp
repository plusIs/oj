#include <bits/stdc++.h>
using namespace std;
#define MAXN 105
#define MAXM 50005
int t[MAXN], c[MAXN], w[MAXN];
int dp[MAXM];
int n, m;

void zeroOnePack(int c, int w)
{
    for (int i = m; i >= c; --i)
        dp[i] = max(dp[i], dp[i - c] + w);
}

void completePack(int c, int w)
{
    for (int i = c; i <= m; ++i)
        dp[i] = max(dp[i], dp[i - c] + w);
}

int main()
{
    //freopen("data.in", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d%d%d", &c[i], &w[i], &t[i]);
    for (int i = 0; i < n; ++i)
    {
        int k = 1, tmp = t[i];
        if (t[i] * c[i] >= m)
            completePack(c[i], w[i]);
        else
        {
            while (k < tmp)
            {
                zeroOnePack(c[i] * k, w[i] * k);
                tmp -= k;
                k *= 2;
            }
            zeroOnePack(c[i] * tmp, w[i] * tmp);
        }
    }
    printf("%d\n", dp[m]);
    return 0;
}
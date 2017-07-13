#include <bits/stdc++.h>
using namespace std;
#define MAXN 505
#define MAXB 505

int n, m, b, mod;
int a[MAXN];//1行代码的bug数
long long dp[MAXN][MAXB];//打出i行代码 j个bug的方法

//f[i][j][k] = f[i-1][j][k] + f[i][j - 1][k - a[i]]

void completePack(int c)
{
    for (int i = 1; i <= m; ++i)
    {
        for (int j = c; j <= b; ++j)
        {
            dp[i][j] += dp[i - 1][j - c];
            dp[i][j] %= mod;
        }
    }
}

int main()
{
    //freopen("data.in", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &b, &mod);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i <=b; ++i)
        dp[0][i] = 1;
    for (int i = 1; i <= n; ++i)
    {
        completePack(a[i]);
    }
    printf("%lld\n", dp[m][b]);
    return 0;
}
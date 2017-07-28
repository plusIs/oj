#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull dp[25] = {0, 2, 2, 4};
ull C(ull a, ull b)
{
    b = max(a - b, b);
    ull ret = 1;
    for (ull i = b + 1; i <= a; ++i)
        ret *= i;
    for (ull i = 2; i <= a - b; ++i)
        ret /= i;
    return ret;
}

int main()
{
    for (int i = 4; i <= 20; ++i)
    {
        dp[i] = dp[i - 1];
        for (int j = 1; j < i - 1; ++j)
        {
            dp[i] += (dp[j] >> 1ll) * (dp[i - 1 - j] >> 1ll) * C(i - 1, j);
        }
        //printf("%lld\n", dp[i]);
    }
    dp[1] = 1;
    int P, d, n;
    scanf("%d", &P);
    while(P--)
    {
        scanf("%d%d", &d, &n);
        printf("%d %lld\n", d, dp[n]);
    }
    return 0;
}

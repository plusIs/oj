#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef unsigned long long ull;
ull f[100] = {0, 0};

ull fun(ull n)
{
    ull ret = 1;
    for (ull i = 1; i <= n; ++i)
    {
        ret = (ret * (i % MOD)) % MOD;
    }
}

int main()
{
    for (int i = 2; i <= 51; ++i)
    {
        f[i] = i * f[i - 1];
        if ((i -2) % 2 == 1)
            ++f[i];
        else
            --f[i];
    }
    int n, m;
    scanf("%d%d", &n, &m);
    ull result;
    result = fun(n);
    result = result - fun(n - m * (fun(m) - f[m]);
    result = result % MOD;
    printf("%d\n", (int)result);
    return 0;
}

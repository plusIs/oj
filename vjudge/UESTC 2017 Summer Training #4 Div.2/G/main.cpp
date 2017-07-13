#include <bits/stdc++.h>
using namespace std;
long long c(long long a, long long b)
{
    long long ret = 1;
    b = min(b, a - b);
    for (int i = a - b + 1; i <= a; ++i)
    {
        ret *= (long long)i;
    }
    for (int i = 2; i <= b; ++i)
        ret /= (long long)i;
    return ret;
}

int main()
{
    int n, oushu, jishu;
    long long result = 0;
    scanf("%d", &n);
    oushu = n / 2;
    if (n <= 2)
    {
        puts("0");
        return 0;
    }
    if (n % 2 == 0)
        jishu = oushu;
    else
        jishu = oushu + 1;
    result = c(jishu, 2) * c(oushu, 1);
    if (oushu >= 3)
        result += c(oushu, 3);
    printf("%lld\n", result);
    return 0;
}

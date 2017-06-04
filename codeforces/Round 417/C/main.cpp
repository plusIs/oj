#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
long long c[MAXN], now[MAXN];

long long getResult(long long k, long long n)
{
    long long ret = 0;
    for (long long i = 1; i <= n; ++i)
        now[i] = c[i] + i * k;
    sort(now + 1, now + n + 1);
    for (long long i = 1; i <= k; ++i)
        ret += now[i];
    //printf("%lld %lld\n", k, ret);
    return ret;
}

int main()
{
    long long n, s, mid, k, ret;
    scanf("%lld%lld", &n, &s);
    long long l = 0, r = n;
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &c[i]);
    while (l <= r)
    {
        mid = (l + r) / 2;
        ret = getResult(mid, n);
        if (ret <= s)
        {
            l = mid;
            if ((l + r) / 2 == mid)
            {
                if (getResult(mid + 1, n) <= s)
                {
                    ret = getResult(mid + 1, n);
                    ++mid;
                }
                break;
            }
        }
        else if (ret > s)
            r = mid - 1;
        //printf("%lld %lld %lld %lld\n", l, r, mid, ret);
    }
    printf("%lld %lld\n", mid, ret);
    return 0;
}
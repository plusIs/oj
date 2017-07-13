#include <bits/stdc++.h>

using namespace std;
long long a[60];
int last[70], now[70], result[70];

int tento2(long long n)
{
    for (int i = 1;; ++i)
    {
        now[i] = n % 2;
        n /= 2;
        if (n == 0)
        {
            return i;
        }
    }
}

long long getResult()
{
    long long ret = 1;
    for (int i = 1; i <= 60; ++i)
    {
        if (result[i])
            ret *= 2;
    }
    return ret;
}

int main()
{
    int n, l;
    scanf("%d", &n);
    for (int i = 60; i >= 1; --i)
        result[i] = 1;
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &a[i]);
        for (int j = 0; j < 70; ++j)
            last[j] = now[j];
        memset(now, 0, sizeof(now));
        l = tento2(a[i]);
        if (i != 0)
        {
            for (int j = 64; j >= 1; --j)
            {
                if (j > 60 && last[j] != now[j])
                    break;
                if (last[j] != now[j])
                {
                    if (last[j] > now[j])[[[[p[[[[[[[[]]]]]]]]]]]]
                    //result[j] = 0;
                    break;
                }
            }
        }
    }
    printf("%lld\n", getResult());
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long data[2005][3];
long long myPow(long long a, long long b, long long mod) //其实是有问题的
{
    long long data[70], ret = 1;
    data[1] = a % mod;
    for (int i = 2; i <= 64; ++i)
    {
        data[i] = (data[i - 1] * data[i - 1]) % mod;
    }
    for (int i = 1; b != 0; ++i)
    {
        if (b % (long long)2 == 1)
            ret *= data[i];
        ret %= mod;
        b /= (long long)2;
    }
    return ret;
}

int main()
{
    int n, T;
    scanf("%d", &T);
    data[1][1] = 26;
    for (int i = 2; i <= 2000; ++i)
    {
        data[i][1] += (data[i - 1][1] * (long long)25) % (long long)1000000007;
        data[i][1] %= (long long)1000000007;
        data[i][1] += (data[i - 1][2] * (long long)25) % (long long)1000000007;
        data[i][1] %= (long long)1000000007;
        data[i][1] += (data[i - 1][3] * (long long)25) % (long long)1000000007;
        data[i][1] %= (long long)1000000007;

        data[i][2] = (data[i - 1][1]) % (long long)1000000007;
        if (i >= 3)
            data[i][3] = (data[i - 1][2]) % (long long)1000000007;
        //printf("%lld %lld %lld\n", data[i][1], data[i][2], data[i][3]);
    }
    while (T--)
    {
        scanf("%d", &n);
        printf("%lld\n", (data[n][1] + data[n][2] + data[n][3]) % (long long)1000000007);
        //myPow(26, n, 1000000007);
        //printf("%lld\n", myPow(26, n, 1000000007));
    }
    return 0;
}

//#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int data[100005], data1[100005], data2[100005];

long long myPow(long long x, long long y, long long mod)
{
    long long result = 1, tmp = x;
    while (y != 0)
    {
        if (y % 2 != 0)
            result = (result * tmp) % mod;
        tmp = (tmp * tmp) % mod;
        y = y / 2;
    }
    return result;
}
int main()
{
    int T, n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        printf("%lld\n", (myPow(4, n - 1, 10007) + myPow(2, n - 1, 10007)) % 10007);
    }
    return 0;
}

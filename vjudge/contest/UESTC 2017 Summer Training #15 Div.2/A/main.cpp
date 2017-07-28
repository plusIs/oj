#include <bits/stdc++.h>
using namespace std;
char str[10000005];


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
    int P, d, b, l, result;
    scanf("%d", &P);
    while (P--)
    {
        result = 0;
        scanf("%d%d", &d, &b);
        getchar();
        gets(str);
        l = strlen(str);
        for (int i = l - 1; i >=0; --i)
        {
            result = (result + ((str[i] - '0') * myPow(b, l - i - 1, b - 1)) % (b - 1)) % (b - 1);
        }
        printf("%d %d\n", d, result);
    }
    return 0;
}
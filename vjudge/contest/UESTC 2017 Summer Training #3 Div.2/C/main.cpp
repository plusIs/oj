#include <bits/stdc++.h>
using namespace std;
long long getLen(long long num)
{
    long long ret = 0;
    while (num != 0)
    {
        num = num / 2;
        ++ret;
    }
    return ret;
}


int main()
{
    long long T, lData[70], rData[70];
    scanf("%lld", &T);
    while (T--)
    {
        memset(lData, 0, sizeof(lData));
        memset(rData, 0, sizeof(rData));
        
        long long l, r, maxLen, ret = 0;
        scanf("%lld%lld", &l, &r);
        if (l == r)
        {
            printf("%lld\n", l);
            continue;
        }
        maxLen = max(getLen(l), getLen(r));
        for (long long i = 0; i < maxLen; ++i)
        {
            lData[i + 1] = l % 2;
            l = l / 2;
            rData[i + 1] = r % 2;
            r = r / 2;
        }
        for (long long i = maxLen; i >= 1; --i)
        {
            //printf("i = %lld %lld %lld %lld\n", i, (l >> i) % 2, l - r, ret);
            if (lData[i] == rData[i])
            {
                if (lData[i] == 1)
                    ret += (long long)pow(2, i - 1);
            }
            else
            {
                ret += (long long)pow(2, i) - 1;
                break;
            }
        }
        printf("%lld\n", ret);
    }
    return 0;
}

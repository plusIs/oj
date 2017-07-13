#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, lData[70], rData[70];
    scanf("%d", &T);
    while (T--)
    {
        memset(lData, 0, sizeof(lData));
        memset(rData, 0, sizeof(rData));
        
        long long l = 0, r = 0, ret = 0;
        scanf("%lld%lld", &l, &r);
        if (l == r)
        {
            printf("%lld\n", l);
            continue;
        }
        int i = 0;
        int j = 0;
        while(l != 0)
        {
            int t = l % 2;
            lData[i++] = t;
            l /= 2;
        }
        while(r != 0)
        {
            int t = r % 2;
            rData[j++] = t;
            r /= 2;
        }
        int maxLen = max(i, j);
        for (int i = maxLen - 1; i >= 0; --i)
        {
            if (lData[i] == rData[i])
            {
                if (lData[i] == 1)
                    ret += (long long)pow(2, i);
            }
            else
            {
                ret += (long long)pow(2, i + 1) - 1;
                break;
            }
        }
        printf("%lld\n", ret);
    }
    return 0;
}

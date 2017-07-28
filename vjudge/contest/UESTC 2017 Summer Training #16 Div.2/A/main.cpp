#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll data[105], pData[65], SG[105];

ll sg(ll x)
{
    if (x % 2 == 0)
        return x / 2ll;
    return sg(x / 2);
}

int main()
{
    for (int i = 0; i <= 63; ++i)
        pData[i] = (1ll << (long long)i) - 1;
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        ll result = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%lld", &data[i]);
            result ^= sg(data[i]);
        }
        if (result == 0)
            puts("NO");
        else
            puts("YES");
        //printf("%lld\n", result); //0为NO
    }
    //for (int i = 1; i <= 7; ++i)
        //printf("sg=%lld\n", sg(i));
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, n, m, gcd, tmp;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        tmp = (n + m) / 2;
        if ((n + m) % 2 == 1)
            ++tmp;
        gcd = __gcd(tmp, n + m);
        printf("%d/%d\n", tmp / gcd, (n + m) / gcd);
    }
    return 0;
}

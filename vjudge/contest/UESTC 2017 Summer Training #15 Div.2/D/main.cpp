#include <bits/stdc++.h>
using namespace std;

int main()
{
    int P,d, n, maxN;
    scanf("%d", &P);
    while (P--)
    {
        maxN = 0;
        scanf("%d%d", &d, &n);
        maxN = max(maxN, n);
        while (n != 1)
        {
            if (n % 2 == 0)
                n /= 2;
            else
                n = n * 3 + 1;
            maxN = max(maxN, n);
        }
        printf("%d %d\n", d, maxN);
    }
    return 0;
}

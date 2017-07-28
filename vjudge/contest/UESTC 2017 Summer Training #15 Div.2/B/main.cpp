#include <bits/stdc++.h>
using namespace std;

int main()
{
    int P, d, n;
    scanf("%d", &P);
    while (P--)
    {
        int result = 0, tmp1, tmp2, tmp3;
        scanf("%d%d", &d, &n);
        tmp1 = n / 3;
        for (int i = 0; i < tmp1; ++i)
        {
            tmp2 = (n - i) / 2;
            if ((n - i) % 2 != 0)
                ++tmp2;
            tmp3 = (n - 2 * i) / 2 + 1;
            tmp3 = max(tmp3, i + 1);
            if ((tmp2 - tmp3) > 0)
                result += 2 * (tmp2 - tmp3);
        }
        tmp2 = n / 2;
        if (n % 2 == 1)
        {
            ++tmp2;
            if ((tmp2 - 1) % 2 == 0)
                result += (tmp2 - 1) / 2;
            else
                result += (tmp2 - 1) / 2 + 1;
        }
        else
            result += (tmp2 - 1) / 2;
        printf("%d %d\n", d, result);
    }
    return 0;
}
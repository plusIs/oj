#include <bits/stdc++.h>
using namespace std;

char str1[80005], str2[80005];

int main()
{
    int n, x, y, diff;
    for (int i = 1; i <= 500; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            for (int k = 0; k <= i; ++k)
            {
                for (int l = 0; l <= i; ++l)
                {
                    n = i;
                    x = j;
                    y = k;
                    diff = l;
                    int tmp = x - (n - diff);
                    if (x >= y && x - y <= diff && x - y < (tmp - (diff - tmp)))
                        printf("n=%d x=%d y=%d diff=%d tmp=%d\n", n, x, y, diff, tmp);
                }
            }
        }
    }

    return 0;
}

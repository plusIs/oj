#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, n, s;
    char str1[200], str2[200];
    scanf("%d", &T);
    while (T--)
    {
        int tmp;
        memset(str1, 0, sizeof(str1));
        memset(str2, 0, sizeof(str2));
        scanf("%d%d", &n, &s);
        if (s > 9 * n || (s == 0 && n > 1))
        {
            puts("-1 -1");
            continue;
        }
        tmp = s;
        for (int i = 0; i < n; ++i)
        {
            if (tmp >= 9)
            {
                tmp -= 9;
                str1[i] = '9';
            }
            else
            {
                str1[i] = tmp + '0';
                tmp = 0;
            }
        }
        tmp = s;
        for (int i = n - 1; i >= 0; --i)
        {
            if (s - 9 * (n - 1) > 0)
            {
                if (tmp >= 9)
                {
                    tmp -= 9;
                    str2[i] = '9';
                }
                else
                {
                    str2[i] = '0' + tmp;
                    tmp = 0;
                }
            }
            else if (tmp > 1)
            {
                if (tmp - 1 >= 9)
                {
                    tmp -= 9;
                    str2[i] = '9';
                }
                else
                {
                    str2[i] = '0' + tmp - 1;
                    tmp -= tmp - 1;
                }
            }
            else if (i > 0)
            {
                str2[i] = '0';
            }
            else
                str2[i] = '0' + tmp;
        }
        printf("%s %s\n", str2, str1);
    }
    return 0;
}
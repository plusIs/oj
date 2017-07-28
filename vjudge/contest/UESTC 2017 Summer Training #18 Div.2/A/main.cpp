#include <bits/stdc++.h>
using namespace std;

char str[20];
int data[20], biger[20];

int factorial(int n)
{
    int ret = 1;
    for (int i = 2; i <= n; ++i)
        ret = ret * i;
    return ret;
}

long double myPow(long double x, int y)
{
    long double result = 1, tmp = x;
    while (y != 0)
    {
        if (y % 2 != 0)
            result = result * tmp;
        tmp = tmp * tmp;
        y = y / 2;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int l, big = 0, f;
        long double result = 0;
        memset(biger, 0, sizeof(biger));

        scanf("%s", str);
        l = strlen(str);
        f = factorial(l);
        for (int i = 0; i < l; ++i)
            data[i] = str[i] - '0';
        for (int i = 0; i < l; ++i)
        {
            for (int j = 0; j < l; ++j)
            {
                if (data[j] > str[i] - '0')
                    ++biger[i];
                else if (data[j] == str[i] - '0')
                    data[j] = 0;
            }
            big += biger[i] * factorial(l - i - 1);
        }
        if (big != 0)
        {
            result = 1.0 / f;
            for (int i = 0; i < big - 1; ++i)
            {
                result = result + result * (1.0 / f);
            }
        }
        cout << fixed << setprecision(9) << result << endl;
    }
    return 0;
}
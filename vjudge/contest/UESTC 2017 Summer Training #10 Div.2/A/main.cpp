#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long m, n, t, result, f[14] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800};
    string str;
    scanf("%lld%lld%lld", &m, &n, &t);
    switch (t)
    {
    case 1:
        n = min(n, 13ll);
        result = f[n];
        if (result > m)
            str = "TLE";
        else
            str = "AC";
        break;
    case 2:
        n = min(n, 40ll);
        result = (long long)1 << n;
        if (result > m)
            str = "TLE";
        else
            str = "AC";
        break;
    case 3:
        n = min(n, 1000ll);
        result = n * n * n * n;
        if (result > m)
            str = "TLE";
        else
            str = "AC";
        break;
    case 4:
        n = min(n, 10000ll);
        result = n * n * n;
        if (result > m)
            str = "TLE";
        else
            str = "AC";

        break;
    case 5:
        result = n * n;
        if (result > m)
            str = "TLE";
        else
            str = "AC";
        break;
    case 6:
        if (n * log(n) / log(2) > m)
            str = "TLE";
        else
            str = "AC";
        break;
    case 7:
        if (n > m)
            str = "TLE";
        else
            str = "AC";
        break;
    }
    puts(str.c_str());
    return 0;
}
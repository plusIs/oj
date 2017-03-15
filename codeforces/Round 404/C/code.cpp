#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{    
    long long n, m, out = 0;
    double tmp;
    scanf ("%lld%lld", &n, &m);
    m %= n;
    out += m;
    //(-1 + (1 + 8*n - 8m))/2
    tmp = (-1.0 + sqrt(1.0 + 8 * n - 8 * m)) / 2.0;
    out += tmp;    
    if (tmp - (long long)tmp > 1e-8)
        ++out;
    printf("%lld\n", out);
    return 0;
}
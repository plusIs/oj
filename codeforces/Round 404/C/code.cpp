#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{    
    long long n, m, out = 0;
    double tmp;
    scanf ("%lld%lld", &n, &m);
    if (m > n)
        m = n;
    out += m;
    tmp = (-1.0 + sqrt(1.0 + 8 * n - 8 * m)) / 2.0;
    for (long long i = max((long long)(tmp - 1), (long long)0); i < tmp + 1; ++i)//我知道这样写很傻逼 懒得改了
    {
        if(n -(i + 1)*i/2 - m <= 0)
        {
            out += i;
            break;
        }
    }
    printf("%lld\n", out);
    return 0;
}
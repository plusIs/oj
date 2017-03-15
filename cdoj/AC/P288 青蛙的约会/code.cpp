#include <cstdio>
#include <algorithm>

using namespace std;

long long gcd(long long, long long);
void egcd(long long, long long, long long&, long long&);

int main()
{
    long long x, y, m, n, L, gc, k, t;
    //freopen("data.in", "r", stdin);
    while(scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &L) != EOF)
    {
        if (n == m)
        {
            printf("Impossible\n");
            continue;
        }
        gc = gcd(L, n - m);
        if ((x - y) % gc)
        {
            printf("Impossible\n");
            continue;
        }
        egcd(L, n - m, t, k);
        k = k * (x - y) / gc;
        k = (k % (L / gc) + L / gc) % (L / gc);
        printf("%lld\n", k);
    }
    return 0;
}

long long gcd(long long a, long long b)
{
    long long r;
    do
    {
        r = a % b;
        a = b;
        b = r;
    }while (r);
    return a;
}

void egcd(long long a, long long b, long long &x, long long &y)
{
    long long x1, y1;
    if (a % b == 0)
    {
        x = 0;
        y = 1;
        return;
    }
    egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
}
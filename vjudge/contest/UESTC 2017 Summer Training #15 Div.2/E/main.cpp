#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct fenshu // b / a
{
    ll a, b;
    fenshu(ll n)
    {
        b = n;
        a = 1;
    }
    fenshu()
    {
        b = 0;
        a = 1;
    }
    fenshu(ll a, ll b)
    {
        this->a = a;
        this->b = b;
    }
    void huajian()
    {
        ll tmp = __gcd(abs(a), abs(b));
        a /= tmp;
        b /= tmp;
    }
    fenshu operator+(const fenshu &p) const
    {
        fenshu ret;
        ll b1, b2, tmp, tmp1, tmp2;
        tmp = __gcd(a, p.a);
        tmp2 = a / tmp;
        tmp1 = p.a / tmp;
        ret.b = b * tmp1 + p.b * tmp2;
        ret.a = a * tmp1;
        ret.huajian();
        return ret;
    }

    fenshu operator*(const fenshu &p) const
    {
        fenshu ret;
        ll tmp;
        ret.a = a * p.a;
        ret.b = b * p.b;
        ret.huajian();
        return ret;
    }

    fenshu operator-(const fenshu &p) const
    {
        fenshu ret, tmp1;
        ll tmp;
        tmp1 = p;
        tmp1.b = -tmp1.b;
        ret = *this + tmp1;
        ret.huajian();
        return ret;
    }
} data[405][405];

int main()
{
    data[0][1] = fenshu(1);
    for (int i = 1; i <= 403; ++i)
    {
        data[i][1] = fenshu(1);
        for (int j = 2; j <= i + 1; ++j)
        {
            data[i][j] = fenshu(j, i) * data[i - 1][j - 1];
            data[i][1] = data[i][1] - data[i][j];
        }
        /*
        printf("%d/%d ", data[i][1].b, data[i][1].a);
        for (int j = 2; j <= i + 1; ++j)
            printf("%d/%d ", data[i][j].b, data[i][j].a);
        putchar('\n');
        */
    }
    int P, d, x, y;
    scanf("%d", &P);
    while (P--)
    {
        scanf("%d%d%d", &d, &x, &y);
        printf("%d %lld",d, data[x][y].b);
        if (data[x][y].a != 1)
            printf("/%lld", data[x][y].a);
        putchar('\n');
    }
    return 0;
}

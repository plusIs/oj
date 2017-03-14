#include <cstdio>
#include <algorithm>

using namespace std;

int gcd(int, int);
void egcd(int, int, int&, int&);

int main()
{
    int x, y, m, n, L, gc, k, t;
    //freopen("data.in", "r", stdin);
    while(scanf("%d%d%d%d%d", &x, &y, &m, &n, &L) != EOF)
    {
        if (n == m)
        {
            printf("Impossible\n");
            continue;
        }
        else if (n < m)
        {
            swap(n, m);
            swap(x, y);
        }
        gc = gcd(L, n - m);
        if ((x - y) % gc)
        {
            printf("Impossible\n");
            continue;
        }
        egcd(L, n - m, t, k);
        while (k < 0 && (x - y) > 0)
        {
            k += (n - m) / gc * L; 
        }
        while (k > 0 && (x - y) < 0)
        {
            k -= (n - m) / gc * L; 
        }
        printf("%d\n", k * (x - y) / gc);
    }
    return 0;
}

int gcd(int a, int b)
{
    int r;
    do
    {
        r = a % b;
        a = b;
        b = r;
    }while (r);
    return a;
}

void egcd(int a, int b, int &x, int &y)
{
    int x1, y1;
    if (a % b == 0)
    {
        x = 0;
        y = 1;
        return;
    }
    egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    //printf("a=%d b=%d x=%d y=%d\n",a,b,x,y);
}
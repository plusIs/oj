#include <cstdio>
#include <algorithm>
using namespace std;
int gcd(int, int);
int egcd(int, int);
int main()
{
    int x, y, m, n, L, gc, nm, xy;
    freopen("data.in", "r", stdin);
    scanf("%d%d%d%d%d", &x, &y, &m, &n, &L);
    nm = n - m;
    xy = x - y;
    gc = gcd(L, nm);
    if (xy % gc)
        printf("Impossible\n");
        return 0;
    
    return 0;
}
int gcd(int a, int b)
{
    int r;
    if (a > b)
        swap(a, b);
    do
    {
        r = a % b;
        a = b;
        b = r;
    }while (r);
    return a;
}
int egcd(int, int)
{
    
}
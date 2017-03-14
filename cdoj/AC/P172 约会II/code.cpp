#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, out = 0;
    //freopen("data.in", "r", stdin);
    while(scanf("%d%d", &a, &b) && (a != 0 || a != b))
    {
        out = 0;
        while(a % 3)
            ++a;
        while(b % 3)
            --b;
        out += (b - a) / 3 + 1;
        printf("%d\n", out);
    }
    return 0;
}
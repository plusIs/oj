#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x0, y0, z0, x1, y1, z1, x2, y2, z2, x3, y3, z3, result = 0;
    scanf("%d%d%d", &x0, &y0, &z0);
    scanf("%d%d%d", &x1, &y1, &z1);
    scanf("%d%d%d", &x2, &y2, &z2);
    if (x0 >= x1 && x0 <= x2)
        x3 = 0;
    else
        x3 = min((x2 - x0) * (x2 - x0), (x1 - x0) * (x1 - x0));

    if (y0 >= y1 && y0 <= y2)
        y3 = 0;
    else
        y3 = min((y2 - y0) * (y2 - y0), (y1 - y0) * (y1 - y0));

    if (z0 >= z1 && z0 <= z2)
        z3 = 0;
    else
        z3 = min((z2 - z0) * (z2 - z0), (z1 - z0) * (z1 - z0));

    result = x3 + y3 + z3;
    printf("%d\n", result);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int m1[10005][10005], m2[10005][10005];

int main()
{
    int g, x, y, n, r;
    scanf("%d", &g);
    for (int i = 0; i < g; ++i)
    {
        scanf("%d%d", &x, &y);
        ++m1[x][y];
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d%d", &x, &y, &r);
        int xLow, xMax, yLow, yMax, dx, dy;
        xLow = max(0, x - r);
        xMax = min(10001, x + r);
        yLow = max(0, y - r);
        yMax = min(10001, y + r);
        for (int j = xLow; j <= xMax; ++j)
        {
            dx = j - x;
            for (int k = yLow; k <= yMax; ++k)
            {
                dy = k - y;
                if (dx * dx + dy * dy <= r * r)
                {
                    g -= m1[j][k];
                    m1[j][k] = 0;
                }
            }
        }
    }
    printf("%d\n", g);
    return 0;
}
